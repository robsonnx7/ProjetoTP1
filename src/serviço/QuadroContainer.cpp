#include "QuadroContainer.h"

int QuadroContainer::buscarIndicePorId(const Identificador& id) const {
    for (size_t i = 0; i < quadros.size(); ++i) {
        if (quadros[i].getIdentificador().getValor() == id.getValor()) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

bool QuadroContainer::inserir(const Quadro& quadro) {
    if (buscarIndicePorId(quadro.getIdentificador()) != -1) {
        return false;
    }
    quadros.push_back(quadro);
    return true;
}

bool QuadroContainer::buscar(Quadro* quadro) const {
    if (quadro == nullptr) {
        return false;
    }
    int idx = buscarIndicePorId(quadro->getIdentificador());
    if (idx == -1) {
        return false;
    }
    *quadro = quadros[idx];
    return true;
}

bool QuadroContainer::atualizar(const Quadro& quadro) {
    int idx = buscarIndicePorId(quadro.getIdentificador());
    if (idx == -1) {
        return false;
    }
    quadros[idx] = quadro;
    return true;
}

bool QuadroContainer::remover(const Identificador& id) {
    int idx = buscarIndicePorId(id);
    if (idx == -1) {
        return false;
    }
    quadros.erase(quadros.begin() + idx);
    return true;
}

bool QuadroContainer::listar(std::vector<Quadro>* saida) const {
    if (saida == nullptr) {
        return false;
    }
    *saida = quadros;
    return true;
}

bool QuadroContainer::existePorProjeto(const Identificador& idProjeto) const {
    for (const auto& q : quadros) {
        if (q.getIdProjeto().getValor() == idProjeto.getValor()) {
            return true;
        }
    }
    return false;
}
