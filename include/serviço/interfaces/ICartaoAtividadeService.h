#ifndef ICARTAOATIVIDADESERVICE_H
#define ICARTAOATIVIDADESERVICE_H

#include <vector>
#include "CartaoAtividade.h"
#include "Identificador.h"
#include "Papel.h"

/**
 * @file ICartaoAtividadeService.h
 * @brief Interface abstrata pura para o servico de CartaoAtividade[cite: 2].
 */
class ICartaoAtividadeService {
public:
    virtual bool criar(const CartaoAtividade& cartao, Papel papelSolicitante) = 0;
    virtual bool ler(CartaoAtividade* cartao, Papel papelSolicitante) = 0;
    virtual bool atualizar(const CartaoAtividade& cartao, Papel papelSolicitante) = 0;
    virtual bool excluir(const Identificador& id, Papel papelSolicitante) = 0;
    virtual bool listar(std::vector<CartaoAtividade>* saida, Papel papelSolicitante) = 0;

    virtual ~ICartaoAtividadeService() = default;
};

#endif // ICARTAOATIVIDADESERVICE_H
