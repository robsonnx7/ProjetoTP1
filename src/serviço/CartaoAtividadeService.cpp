#include "CartaoAtividadeService.h"

/**
 * @file CartaoAtividadeService.cpp
 * @brief Implementação do serviço de regras de negócio para CartaoAtividade.
 */

/**
 * @brief Constrói o serviço injetando o container de cartões e containers de dependência.
 * @param cartaoContainer Container de cartões de atividade.
 * @param quadroContainer Container de quadros para validação de vínculo.
 * @param pessoaContainer Container de pessoas para validação do desenvolvedor.
 */
CartaoAtividadeService::CartaoAtividadeService(CartaoAtividadeContainer* cartaoContainer,
                                               QuadroContainer* quadroContainer,
                                               PessoaContainer* pessoaContainer)
    : cartaoContainer(cartaoContainer),
      quadroContainer(quadroContainer),
      pessoaContainer(pessoaContainer) {}

/**
 * @brief Verifica se o quadro referenciado pelo cartão existe.
 * @param idQuadro Identificador do quadro a ser consultado.
 * @return true se o quadro existir; false caso contrário ou se o container for nulo.
 */
bool CartaoAtividadeService::quadroExiste(const Identificador& idQuadro) const {
    if (quadroContainer == nullptr) {
        return false;
    }
    Quadro consulta;
    consulta.setIdentificador(idQuadro);
    return quadroContainer->buscar(&consulta);
}

/**
 * @brief Verifica se a pessoa desenvolvedora referenciada pelo cartão existe.
 * @param emailDesenvolvedor E-mail do desenvolvedor a ser consultado.
 * @return true se a pessoa existir; false caso contrário ou se o container for nulo.
 */
bool CartaoAtividadeService::desenvolvedorExiste(const Email& emailDesenvolvedor) const {
    if (pessoaContainer == nullptr) {
        return false;
    }
    Pessoa consulta;
    consulta.setEmail(emailDesenvolvedor);
    return pessoaContainer->buscar(&consulta);
}

/**
 * @brief Cria um novo cartão de atividade se o solicitante for GESTOR e as dependências existirem.
 * @param cartao Cartão de atividade a ser criado.
 * @param papelSolicitante Papel do usuário que solicita a operação.
 * @return true se criado com sucesso; false se sem permissão, dependências ausentes ou falha no container.
 */
bool CartaoAtividadeService::criar(const CartaoAtividade& cartao, Papel papelSolicitante) {
    if (papelSolicitante.getValor() != "GESTOR") return false;
    if (cartaoContainer == nullptr) {
        return false;
    }
    if (!quadroExiste(cartao.getIdQuadro()) || !desenvolvedorExiste(cartao.getEmailDesenvolvedor())) {
        return false;
    }
    return cartaoContainer->inserir(cartao);
}

/**
 * @brief Busca um cartão de atividade pelo identificador.
 * @param[in,out] cartao Ponteiro para cartão com identificador de busca; recebe os dados se encontrado.
 * @param papelSolicitante Papel do usuário que solicita a operação.
 * @return true se encontrado; false caso contrário.
 */
bool CartaoAtividadeService::ler(CartaoAtividade* cartao, Papel papelSolicitante) {
    (void)papelSolicitante;
    if (cartaoContainer == nullptr || cartao == nullptr) {
        return false;
    }
    return cartaoContainer->buscar(cartao);
}

/**
 * @brief Atualiza um cartão de atividade se o solicitante for GESTOR e as dependências existirem.
 * @param cartao Dados atualizados do cartão.
 * @param papelSolicitante Papel do usuário que solicita a operação.
 * @return true se atualizado com sucesso; false caso contrário.
 */
bool CartaoAtividadeService::atualizar(const CartaoAtividade& cartao, Papel papelSolicitante) {
    if (papelSolicitante.getValor() != "GESTOR") return false;
    if (cartaoContainer == nullptr) {
        return false;
    }
    if (!quadroExiste(cartao.getIdQuadro()) || !desenvolvedorExiste(cartao.getEmailDesenvolvedor())) {
        return false;
    }
    return cartaoContainer->atualizar(cartao);
}

/**
 * @brief Exclui um cartão de atividade se o solicitante for GESTOR.
 * @param id Identificador do cartão a ser excluído.
 * @param papelSolicitante Papel do usuário que solicita a operação.
 * @return true se excluído com sucesso; false caso contrário.
 */
bool CartaoAtividadeService::excluir(const Identificador& id, Papel papelSolicitante) {
    if (papelSolicitante.getValor() != "GESTOR") return false;
    if (cartaoContainer == nullptr) {
        return false;
    }
    // Cartao de atividade esta na base da hierarquia de exclusao
    // (Cartao -> Quadro -> Projeto -> Pessoa).
    return cartaoContainer->remover(id);
}

/**
 * @brief Lista todos os cartões de atividade cadastrados.
 * @param[out] saida Ponteiro para vetor que receberá os cartões.
 * @param papelSolicitante Papel do usuário que solicita a operação.
 * @return true se listado com sucesso; false caso contrário.
 */
bool CartaoAtividadeService::listar(std::vector<CartaoAtividade>* saida, Papel papelSolicitante) {
    (void)papelSolicitante;
    if (cartaoContainer == nullptr || saida == nullptr) {
        return false;
    }
    return cartaoContainer->listar(saida);
}
