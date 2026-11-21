#include "CartaoAtividadeContainer.h"

int CartaoAtividadeContainer::buscarIndicePorId(const Identificador& id) const {
    for (size_t i = 0; i < cartoes.size(); ++i) {
        if (cartoes[i].getIdentificador().getValor() == id.getValor()) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

bool CartaoAtividadeContainer::inserir(const CartaoAtividade& cartao) {
    if (buscarIndicePorId(cartao.getIdentificador()) != -1) {
        return false;
    }
    cartoes.push_back(cartao);
    return true;
}

bool CartaoAtividadeContainer::buscar(CartaoAtividade* cartao) const {
    if (cartao == nullptr) {
        return false;
    }
    int idx = buscarIndicePorId(cartao->getIdentificador());
    if (idx == -1) {
        return false;
    }
    *cartao = cartoes[idx];
    return true;
}

bool CartaoAtividadeContainer::atualizar(const CartaoAtividade& cartao) {
    int idx = buscarIndicePorId(cartao.getIdentificador());
    if (idx == -1) {
        return false;
    }
    cartoes[idx] = cartao;
    return true;
}

bool CartaoAtividadeContainer::remover(const Identificador& id) {
    int idx = buscarIndicePorId(id);
    if (idx == -1) {
        return false;
    }
    cartoes.erase(cartoes.begin() + idx);
    return true;
}

bool CartaoAtividadeContainer::listar(std::vector<CartaoAtividade>* saida) const {
    if (saida == nullptr) {
        return false;
    }
    *saida = cartoes;
    return true;
}

bool CartaoAtividadeContainer::existePorQuadro(const Identificador& idQuadro) const {
    for (const auto& c : cartoes) {
        if (c.getIdQuadro().getValor() == idQuadro.getValor()) {
            return true;
        }
    }
    return false;
}

bool CartaoAtividadeContainer::existePorDesenvolvedor(const Email& emailDesenvolvedor) const {
    for (const auto& c : cartoes) {
        if (c.getEmailDesenvolvedor().getValor() == emailDesenvolvedor.getValor()) {
            return true;
        }
    }
    return false;
}
