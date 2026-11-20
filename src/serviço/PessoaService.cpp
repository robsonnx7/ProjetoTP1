#include "PessoaService.h"

/**
 * @file PessoaService.cpp
 * @brief Implementação dos métodos da classe PessoaService.
 */

bool PessoaService::temPermissao(Papel papelSolicitante) const {
    const std::string valorPapel = papelSolicitante.getValor();
    return valorPapel == "GESTOR" || valorPapel == "DESENVOLVEDOR";
}

int PessoaService::buscarIndicePorEmail(const Email& email) const {
    for (size_t i = 0; i < pessoas.size(); ++i) {
        if (pessoas[i].getEmail().getValor() == email.getValor()) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

bool PessoaService::criar(const Pessoa& pessoa, Papel papelSolicitante) {
    if (!temPermissao(papelSolicitante)) {
        return false;
    }

    if (pessoa.getEmail().getValor().empty() ||
        buscarIndicePorEmail(pessoa.getEmail()) != -1) {
        return false;
    }

    pessoas.push_back(pessoa);
    return true;
}

bool PessoaService::ler(Pessoa* pessoa, Papel papelSolicitante) {
    if (!temPermissao(papelSolicitante) || pessoa == nullptr) {
        return false;
    }

    int indice = buscarIndicePorEmail(pessoa->getEmail());
    if (indice == -1) {
        return false;
    }

    *pessoa = pessoas[indice];
    return true;
}

bool PessoaService::atualizar(const Pessoa& pessoa, Papel papelSolicitante) {
    if (!temPermissao(papelSolicitante)) {
        return false;
    }

    int indice = buscarIndicePorEmail(pessoa.getEmail());
    if (indice == -1) {
        return false;
    }

    pessoas[indice] = pessoa;
    return true;
}

bool PessoaService::excluir(const Email& email, Papel papelSolicitante) {
    if (!temPermissao(papelSolicitante)) {
        return false;
    }

    int indice = buscarIndicePorEmail(email);
    if (indice == -1) {
        return false;
    }

    pessoas.erase(pessoas.begin() + indice);
    return true;
}

bool PessoaService::listar(std::vector<Pessoa>* pessoasSaida, Papel papelSolicitante) {
    if (!temPermissao(papelSolicitante) || pessoasSaida == nullptr) {
        return false;
    }

    *pessoasSaida = pessoas;
    return true;
}
