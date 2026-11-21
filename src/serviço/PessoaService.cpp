#include "PessoaService.h"

PessoaService::PessoaService(PessoaContainer* pessoaContainer,
                             ProjetoContainer* projetoContainer,
                             CartaoAtividadeContainer* cartaoContainer)
    : pessoaContainer(pessoaContainer),
      projetoContainer(projetoContainer),
      cartaoContainer(cartaoContainer) {}

bool PessoaService::temPermissao(Papel papelSolicitante) const {
    return papelSolicitante.getValor() == "GESTOR" ||
           papelSolicitante.getValor() == "DESENVOLVEDOR";
}

bool PessoaService::possuiVinculosAtivos(const Email& email) const {
    // Na ordem de exclusao (Cartao -> Quadro -> Projeto -> Pessoa),
    // Pessoa so pode ser removida quando nao ha projetos (como gestor)
    // nem cartoes de atividade (como desenvolvedor) vinculados a ela[cite: 6].
    if (projetoContainer != nullptr && projetoContainer->existePorGestor(email)) {
        return true;
    }
    if (cartaoContainer != nullptr && cartaoContainer->existePorDesenvolvedor(email)) {
        return true;
    }
    return false;
}

bool PessoaService::criar(const Pessoa& pessoa, Papel papelSolicitante) {
    if (pessoaContainer == nullptr || !temPermissao(papelSolicitante)) {
        return false;
    }
    return pessoaContainer->inserir(pessoa);
}

bool PessoaService::ler(Pessoa* pessoa, Papel papelSolicitante) {
    if (pessoaContainer == nullptr || pessoa == nullptr || !temPermissao(papelSolicitante)) {
        return false;
    }
    return pessoaContainer->buscar(pessoa);
}

bool PessoaService::atualizar(const Pessoa& pessoa, Papel papelSolicitante) {
    if (pessoaContainer == nullptr || !temPermissao(papelSolicitante)) {
        return false;
    }
    return pessoaContainer->atualizar(pessoa);
}

bool PessoaService::excluir(const Email& email, Papel papelSolicitante) {
    if (pessoaContainer == nullptr || !temPermissao(papelSolicitante)) {
        return false;
    }
    if (possuiVinculosAtivos(email)) {
        return false;
    }
    return pessoaContainer->remover(email);
}

bool PessoaService::listar(std::vector<Pessoa>* pessoasSaida, Papel papelSolicitante) {
    if (pessoaContainer == nullptr || pessoasSaida == nullptr || !temPermissao(papelSolicitante)) {
        return false;
    }
    return pessoaContainer->listar(pessoasSaida);
}
