#include "ProjetoService.h"

ProjetoService::ProjetoService(ProjetoContainer* projetoContainer,
                               IPessoaService* pessoaService,
                               QuadroContainer* quadroContainer)
    : projetoContainer(projetoContainer),
      quadroContainer(quadroContainer),
      pessoaService(pessoaService) {}

bool ProjetoService::gestorExiste(const Email& emailGestor, Papel papelSolicitante) const {
    if (pessoaService == nullptr) {
        return false;
    }
    Pessoa consulta;
    consulta.setEmail(emailGestor);
    return pessoaService->ler(&consulta, papelSolicitante);
}

bool ProjetoService::possuiQuadrosVinculados(const Identificador& idProjeto) const {
    // Na ordem de exclusao (Cartao -> Quadro -> Projeto -> Pessoa),
    // Projeto so pode ser excluido se nao houver Quadro vinculado a ele[cite: 6].
    return quadroContainer != nullptr && quadroContainer->existePorProjeto(idProjeto);
}

bool ProjetoService::criar(const Projeto& projeto, Papel papelSolicitante) {
    if (projetoContainer == nullptr) {
        return false;
    }
    if (!gestorExiste(projeto.getEmailGestor(), papelSolicitante)) {
        return false;
    }
    return projetoContainer->inserir(projeto);
}

bool ProjetoService::ler(Projeto* projeto, Papel papelSolicitante) {
    (void)papelSolicitante;
    if (projetoContainer == nullptr || projeto == nullptr) {
        return false;
    }
    return projetoContainer->buscar(projeto);
}

bool ProjetoService::atualizar(const Projeto& projeto, Papel papelSolicitante) {
    if (projetoContainer == nullptr) {
        return false;
    }
    if (!gestorExiste(projeto.getEmailGestor(), papelSolicitante)) {
        return false;
    }
    return projetoContainer->atualizar(projeto);
}

bool ProjetoService::excluir(const Identificador& id, Papel papelSolicitante) {
    (void)papelSolicitante;
    if (projetoContainer == nullptr) {
        return false;
    }
    if (possuiQuadrosVinculados(id)) {
        return false;
    }
    return projetoContainer->remover(id);
}

bool ProjetoService::listar(std::vector<Projeto>* saida, Papel papelSolicitante) {
    (void)papelSolicitante;
    if (projetoContainer == nullptr || saida == nullptr) {
        return false;
    }
    return projetoContainer->listar(saida);
}
