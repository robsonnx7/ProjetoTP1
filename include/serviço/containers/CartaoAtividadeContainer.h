#ifndef CARTAOATIVIDADECONTAINER_H
#define CARTAOATIVIDADECONTAINER_H

#include <vector>
#include "CartaoAtividade.h"
#include "Identificador.h"
#include "Email.h"

/**
 * @file CartaoAtividadeContainer.h
 * @brief Container em memoria para armazenamento de objetos CartaoAtividade.
 */
class CartaoAtividadeContainer {
private:
    std::vector<CartaoAtividade> cartoes;

    int buscarIndicePorId(const Identificador& id) const;

public:
    CartaoAtividadeContainer() = default;

    bool inserir(const CartaoAtividade& cartao);
    bool buscar(CartaoAtividade* cartao) const;
    bool atualizar(const CartaoAtividade& cartao);
    bool remover(const Identificador& id);
    bool listar(std::vector<CartaoAtividade>* saida) const;

    bool existePorQuadro(const Identificador& idQuadro) const;
    bool existePorDesenvolvedor(const Email& emailDesenvolvedor) const;
};

#endif // CARTAOATIVIDADECONTAINER_H
