#include "PessoaContainer.h"

int PessoaContainer::buscarIndicePorEmail(const Email& email) const {
    for (size_t i = 0; i < pessoas.size(); ++i) {
        if (pessoas[i].getEmail().getValor() == email.getValor()) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

bool PessoaContainer::inserir(const Pessoa& pessoa) {
    if (buscarIndicePorEmail(pessoa.getEmail()) != -1) {
        return false;
    }
    pessoas.push_back(pessoa);
    return true;
}

bool PessoaContainer::buscar(Pessoa* pessoa) const {
    if (pessoa == nullptr) {
        return false;
    }
    int idx = buscarIndicePorEmail(pessoa->getEmail());
    if (idx == -1) {
        return false;
    }
    *pessoa = pessoas[idx];
    return true;
}

bool PessoaContainer::atualizar(const Pessoa& pessoa) {
    int idx = buscarIndicePorEmail(pessoa.getEmail());
    if (idx == -1) {
        return false;
    }
    pessoas[idx] = pessoa;
    return true;
}

bool PessoaContainer::remover(const Email& email) {
    int idx = buscarIndicePorEmail(email);
    if (idx == -1) {
        return false;
    }
    pessoas.erase(pessoas.begin() + idx);
    return true;
}

bool PessoaContainer::listar(std::vector<Pessoa>* pessoasSaida) const {
    if (pessoasSaida == nullptr) {
        return false;
    }
    *pessoasSaida = pessoas;
    return true;
}
