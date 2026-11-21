#include "ProjetoContainer.h"

int ProjetoContainer::buscarIndicePorId(const Identificador& id) const {
    for (size_t i = 0; i < projetos.size(); ++i) {
        if (projetos[i].getIdentificador().getValor() == id.getValor()) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

bool ProjetoContainer::inserir(const Projeto& projeto) {
    if (buscarIndicePorId(projeto.getIdentificador()) != -1) {
        return false;
    }
    projetos.push_back(projeto);
    return true;
}

bool ProjetoContainer::buscar(Projeto* projeto) const {
    if (projeto == nullptr) {
        return false;
    }
    int idx = buscarIndicePorId(projeto->getIdentificador());
    if (idx == -1) {
        return false;
    }
    *projeto = projetos[idx];
    return true;
}

bool ProjetoContainer::atualizar(const Projeto& projeto) {
    int idx = buscarIndicePorId(projeto.getIdentificador());
    if (idx == -1) {
        return false;
    }
    projetos[idx] = projeto;
    return true;
}

bool ProjetoContainer::remover(const Identificador& id) {
    int idx = buscarIndicePorId(id);
    if (idx == -1) {
        return false;
    }
    projetos.erase(projetos.begin() + idx);
    return true;
}

bool ProjetoContainer::listar(std::vector<Projeto>* saida) const {
    if (saida == nullptr) {
        return false;
    }
    *saida = projetos;
    return true;
}

bool ProjetoContainer::existePorGestor(const Email& emailGestor) const {
    for (const auto& p : projetos) {
        if (p.getEmailGestor().getValor() == emailGestor.getValor()) {
            return true;
        }
    }
    return false;
}
