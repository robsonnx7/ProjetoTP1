#include "PessoaContainer.h"

/**
 * @file PessoaContainer.cpp
 * @brief Implementação do container em memória para a entidade Pessoa.
 */

int PessoaContainer::buscarIndicePorEmail(const Email& email) const {
    for (size_t i = 0; i < pessoas.size(); ++i) {
        if (pessoas[i].getEmail().getValor() == email.getValor()) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

bool PessoaContainer::inserir(const Pessoa& pessoa) {
    if (pessoa.getEmail().getValor().empty() ||
        buscarIndicePorEmail(pessoa.getEmail()) != -1) {
        return false;
    }

    pessoas.push_back(pessoa);
    return true;
}

bool PessoaContainer::buscar(Pessoa* pessoa) const {
    if (pessoa == nullptr) {
        return false;
    }

    int indice = buscarIndicePorEmail(pessoa->getEmail());
    if (indice == -1) {
        return false;
    }

    *pessoa = pessoas[indice];
    return true;
}

bool PessoaContainer::atualizar(const Pessoa& pessoa) {
    int indice = buscarIndicePorEmail(pessoa.getEmail());
    if (indice == -1) {
        return false;
    }

    pessoas[indice] = pessoa;
    return true;
}

bool PessoaContainer::remover(const Email& email) {
    int indice = buscarIndicePorEmail(email);
    if (indice == -1) {
        return false;
    }

    pessoas.erase(pessoas.begin() + indice);
    return true;
}

bool PessoaContainer::listar(std::vector<Pessoa>* pessoasSaida) const {
    if (pessoasSaida == nullptr) {
        return false;
    }

    *pessoasSaida = pessoas;
    return true;
}
