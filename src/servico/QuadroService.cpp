#include "QuadroService.h"

QuadroService::QuadroService(QuadroContainer* quadroContainer,
                             ProjetoContainer* projetoContainer,
                             CartaoAtividadeContainer* cartaoContainer)
    : quadroContainer(quadroContainer),
      projetoContainer(projetoContainer),
      cartaoContainer(cartaoContainer) {}

bool QuadroService::projetoExiste(const Identificador& idProjeto) const {
    if (projetoContainer == nullptr) {
        return false;
    }
    Projeto consulta;
    consulta.setIdentificador(idProjeto);
    return projetoContainer->buscar(&consulta);
}

bool QuadroService::possuiCartoesVinculados(const Identificador& idQuadro) const {
    // Na ordem de exclusao (Cartao -> Quadro -> Projeto -> Pessoa),
    // Quadro so pode ser excluido se nao houver Cartao de atividade vinculado a ele.
    return cartaoContainer != nullptr && cartaoContainer->existePorQuadro(idQuadro);
}

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

bool QuadroService::ler(Quadro* quadro, Papel papelSolicitante) {
    (void)papelSolicitante;
    if (quadroContainer == nullptr || quadro == nullptr) {
        return false;
    }
    return quadroContainer->buscar(quadro);
}

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

bool QuadroService::listar(std::vector<Quadro>* saida, Papel papelSolicitante) {
    (void)papelSolicitante;
    if (quadroContainer == nullptr || saida == nullptr) {
        return false;
    }
    return quadroContainer->listar(saida);
}
