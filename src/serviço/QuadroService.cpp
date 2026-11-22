#include "QuadroService.h"

/**
 * @file QuadroService.cpp
 * @brief Implementação do serviço de regras de negócio para Quadro.
 */

/**
 * @brief Constrói o serviço injetando os containers de quadro, projeto e cartão de atividade.
 * @param quadroContainer Container de quadros.
 * @param projetoContainer Container de projetos para validar a existência do projeto.
 * @param cartaoContainer Container de cartões para checar dependências na exclusão.
 */
QuadroService::QuadroService(QuadroContainer* quadroContainer,
                             ProjetoContainer* projetoContainer,
                             CartaoAtividadeContainer* cartaoContainer)
    : quadroContainer(quadroContainer),
      projetoContainer(projetoContainer),
      cartaoContainer(cartaoContainer) {}

/**
 * @brief Verifica se o projeto vinculado ao quadro existe.
 * @param idProjeto Identificador do projeto.
 * @return true se o projeto existir; false caso contrário.
 */
bool QuadroService::projetoExiste(const Identificador& idProjeto) const {
    if (projetoContainer == nullptr) {
        return false;
    }
    Projeto consulta;
    consulta.setIdentificador(idProjeto);
    return projetoContainer->buscar(&consulta);
}

/**
 * @brief Verifica se o quadro possui cartões de atividade vinculados antes de permitir a exclusão.
 * @param idQuadro Identificador do quadro.
 * @return true se houver cartão vinculado; false caso contrário.
 */
bool QuadroService::possuiCartoesVinculados(const Identificador& idQuadro) const {
    // Na ordem de exclusao (Cartao -> Quadro -> Projeto -> Pessoa),
    // Quadro so pode ser excluido se nao houver Cartao de atividade vinculado a ele.
    return cartaoContainer != nullptr && cartaoContainer->existePorQuadro(idQuadro);
}

/**
 * @brief Cria um novo quadro se o solicitante for GESTOR e o projeto existir.
 * @param quadro Objeto Quadro a ser criado.
 * @param papelSolicitante Papel do usuário solicitante.
 * @return true se criado com sucesso; false caso contrário.
 */
bool QuadroService::criar(const Quadro& quadro, Papel papelSolicitante) {
    if (papelSolicitante.getValor() != "GESTOR") return false;
    if (quadroContainer == nullptr) {
        return false;
    }
    if (!projetoExiste(quadro.getIdProjeto())) {
        return false;
    }
    return quadroContainer->inserir(quadro);
}

/**
 * @brief Busca um quadro pelo identificador.
 * @param[in,out] quadro Ponteiro contendo o identificador de busca; recebe os dados se encontrado.
 * @param papelSolicitante Papel do usuário solicitante.
 * @return true se encontrado; false caso contrário.
 */
bool QuadroService::ler(Quadro* quadro, Papel papelSolicitante) {
    (void)papelSolicitante;
    if (quadroContainer == nullptr || quadro == nullptr) {
        return false;
    }
    return quadroContainer->buscar(quadro);
}

/**
 * @brief Atualiza um quadro existente se o solicitante for GESTOR e o projeto existir.
 * @param quadro Objeto Quadro com os dados atualizados.
 * @param papelSolicitante Papel do usuário solicitante.
 * @return true se atualizado com sucesso; false caso contrário.
 */
bool QuadroService::atualizar(const Quadro& quadro, Papel papelSolicitante) {
    if (papelSolicitante.getValor() != "GESTOR") return false;
    if (quadroContainer == nullptr) {
        return false;
    }
    if (!projetoExiste(quadro.getIdProjeto())) {
        return false;
    }
    return quadroContainer->atualizar(quadro);
}

/**
 * @brief Exclui um quadro se o solicitante for GESTOR e não houver cartões vinculados.
 * @param id Identificador do quadro a ser excluído.
 * @param papelSolicitante Papel do usuário solicitante.
 * @return true se excluído com sucesso; false caso contrário.
 */
bool QuadroService::excluir(const Identificador& id, Papel papelSolicitante) {
    if (papelSolicitante.getValor() != "GESTOR") return false;
    if (quadroContainer == nullptr) {
        return false;
    }
    if (possuiCartoesVinculados(id)) {
        return false;
    }
    return quadroContainer->remover(id);
}

/**
 * @brief Lista todos os quadros cadastrados.
 * @param[out] saida Ponteiro para vetor que receberá os quadros.
 * @param papelSolicitante Papel do usuário solicitante.
 * @return true se listado com sucesso; false caso contrário.
 */
bool QuadroService::listar(std::vector<Quadro>* saida, Papel papelSolicitante) {
    (void)papelSolicitante;
    if (quadroContainer == nullptr || saida == nullptr) {
        return false;
    }
    return quadroContainer->listar(saida);
}
