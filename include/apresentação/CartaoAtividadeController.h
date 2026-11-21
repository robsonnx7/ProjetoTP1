#ifndef CARTAOATIVIDADECONTROLLER_H
#define CARTAOATIVIDADECONTROLLER_H

#include "ICartaoAtividadeService.h"

/**
 * @file CartaoAtividadeController.h
 * @brief Controladora de apresentacao para CartaoAtividade[cite: 2].
 */
class CartaoAtividadeController {
private:
    ICartaoAtividadeService* servico;

public:
    explicit CartaoAtividadeController(ICartaoAtividadeService* servico);

    void executar();

    ~CartaoAtividadeController() = default;
};

#endif // CARTAOATIVIDADECONTROLLER_H
