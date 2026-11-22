#include "ProjetoService.h"

/**
 * @file ProjetoService.cpp
 * @brief Implementação do serviço de regras de negócio para Projeto.
 */

/**
 * @brief Constrói o serviço injetando o container de projetos, serviço de pessoas e container de quadros.
 * @param projetoContainer Container de projetos.
 * @param pessoaService Interface de serviço de pessoas para validar o gestor.
 * @param quadroContainer Container de quadros para checar dependências na exclusão.
 */
ProjetoService::ProjetoService(ProjetoContainer* projetoContainer,
                               IPessoaService* pessoaService,
                               QuadroContainer* quadroContainer)
    : projetoContainer(projetoContainer),
      quadroContainer(quadroContainer),
      pessoaService(pessoaService) {}

/**
 * @brief Verifica se a pessoa gestora informada existe no serviço de pessoas.
 * @param emailGestor E-mail do gestor.
 * @param papelSolicitante Papel do usuário solicitante.
 * @return true se o gestor existir; false caso contrário.
 */
bool ProjetoService::gestorExiste(const Email& emailGestor, Papel papelSolicitante) const {
    if (pessoaService == nullptr) {
        return false;
    }
    Pessoa consulta;
    consulta.setEmail(emailGestor);
    return pessoaService->ler(&consulta, papelSolicitante);
}

/**
 * @brief Verifica se o projeto possui quadros vinculados antes de permitir a exclusão.
 * @param idProjeto Identificador do projeto.
 * @return true se houver quadro vinculado; false caso contrário.
 */
bool ProjetoService::possuiQuadrosVinculados(const Identificador& idProjeto) const {
    // Na ordem de exclusao (Cartao -> Quadro -> Projeto -> Pessoa),
    // Projeto so pode ser excluido se nao houver Quadro vinculado a ele.
    return quadroContainer != nullptr && quadroContainer->existePorProjeto(idProjeto);
}

/**
 * @brief Cria um novo projeto se o solicitante for GESTOR e o gestor existir.
 * @param projeto Objeto Projeto a ser criado.
 * @param papelSolicitante Papel do usuário solicitante.
 * @return true se criado com sucesso; false caso contrário.
 */
bool ProjetoService::criar(const Projeto& projeto, Papel papelSolicitante) {
    if (papelSolicitante.getValor() != "GESTOR") return false;
    if (projetoContainer == nullptr) {
        return false;
    }
    if (!gestorExiste(projeto.getEmailGestor(), papelSolicitante)) {
        return false;
    }
    return projetoContainer->inserir(projeto);
}

/**
 * @brief Busca um projeto pelo identificador.
 * @param[in,out] projeto Ponteiro contendo o identificador de busca; recebe os dados se encontrado.
 * @param papelSolicitante Papel do usuário solicitante.
 * @return true se encontrado; false caso contrário.
 */
bool ProjetoService::ler(Projeto* projeto, Papel papelSolicitante) {
    (void)papelSolicitante;
    if (projetoContainer == nullptr || projeto == nullptr) {
        return false;
    }
    return projetoContainer->buscar(projeto);
}

/**
 * @brief Atualiza um projeto existente se o solicitante for GESTOR e o gestor existir.
 * @param projeto Objeto Projeto com os dados atualizados.
 * @param papelSolicitante Papel do usuário solicitante.
 * @return true se atualizado com sucesso; false caso contrário.
 */
bool ProjetoService::atualizar(const Projeto& projeto, Papel papelSolicitante) {
    if (papelSolicitante.getValor() != "GESTOR") return false;
    if (projetoContainer == nullptr) {
        return false;
    }
    if (!gestorExiste(projeto.getEmailGestor(), papelSolicitante)) {
        return false;
    }
    return projetoContainer->atualizar(projeto);
}

/**
 * @brief Exclui um projeto se o solicitante for GESTOR e não houver quadros vinculados.
 * @param id Identificador do projeto a ser excluído.
 * @param papelSolicitante Papel do usuário solicitante.
 * @return true se excluído com sucesso; false caso contrário.
 */
bool ProjetoService::excluir(const Identificador& id, Papel papelSolicitante) {
    if (papelSolicitante.getValor() != "GESTOR") return false;
    if (projetoContainer == nullptr) {
        return false;
    }
    if (possuiQuadrosVinculados(id)) {
        return false;
    }
    return projetoContainer->remover(id);
}

/**
 * @brief Lista todos os projetos cadastrados.
 * @param[out] saida Ponteiro para vetor que receberá os projetos.
 * @param papelSolicitante Papel do usuário solicitante.
 * @return true se listado com sucesso; false caso contrário.
 */
bool ProjetoService::listar(std::vector<Projeto>* saida, Papel papelSolicitante) {
    (void)papelSolicitante;
    if (projetoContainer == nullptr || saida == nullptr) {
        return false;
    }
    return projetoContainer->listar(saida);
}
