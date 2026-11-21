#include "CartaoAtividadeService.h"

CartaoAtividadeService::CartaoAtividadeService(CartaoAtividadeContainer* cartaoContainer,
                                               QuadroContainer* quadroContainer,
                                               PessoaContainer* pessoaContainer)
    : cartaoContainer(cartaoContainer),
      quadroContainer(quadroContainer),
      pessoaContainer(pessoaContainer) {}

bool CartaoAtividadeService::quadroExiste(const Identificador& idQuadro) const {
    if (quadroContainer == nullptr) {
        return false;
    }
    Quadro consulta;
    consulta.setIdentificador(idQuadro);
    return quadroContainer->buscar(&consulta);
}

bool CartaoAtividadeService::desenvolvedorExiste(const Email& emailDesenvolvedor) const {
    if (pessoaContainer == nullptr) {
        return false;
    }
    Pessoa consulta;
    consulta.setEmail(emailDesenvolvedor);
    return pessoaContainer->buscar(&consulta);
}

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

bool CartaoAtividadeService::ler(CartaoAtividade* cartao, Papel papelSolicitante) {
    (void)papelSolicitante;
    if (cartaoContainer == nullptr || cartao == nullptr) {
        return false;
    }
    return cartaoContainer->buscar(cartao);
}

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

bool CartaoAtividadeService::excluir(const Identificador& id, Papel papelSolicitante) {
    if (papelSolicitante.getValor() != "GESTOR") return false;
    if (cartaoContainer == nullptr) {
        return false;
    }
    // Cartao de atividade esta na base da hierarquia de exclusao
    // (Cartao -> Quadro -> Projeto -> Pessoa)[cite: 2].
    return cartaoContainer->remover(id);
}

bool CartaoAtividadeService::listar(std::vector<CartaoAtividade>* saida, Papel papelSolicitante) {
    (void)papelSolicitante;
    if (cartaoContainer == nullptr || saida == nullptr) {
        return false;
    }
    return cartaoContainer->listar(saida);
}
