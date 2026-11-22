#ifndef CARTAOATIVIDADECONTROLLER_H
#define CARTAOATIVIDADECONTROLLER_H

#include "ICartaoAtividadeService.h"
#include "Papel.h"

/**
 * @file CartaoAtividadeController.h
 * @brief Declaração da controladora de apresentação para CartaoAtividade.
 */

/**
 * @class CartaoAtividadeController
 * @brief Gerencia a interação via terminal para operações CRUD e listagem de CartaoAtividade.
 */
class CartaoAtividadeController {
private:
    ICartaoAtividadeService* servico; ///< Ponteiro para a interface do serviço de cartão de atividade.

public:
    /**
     * @brief Constrói a controladora associando-a ao serviço de cartão de atividade.
     * @param servico Ponteiro para implementação de ICartaoAtividadeService.
     */
    explicit CartaoAtividadeController(ICartaoAtividadeService* servico);

    /**
     * @brief Inicia o loop interativo do menu de cartão de atividade para o papel informado.
     * @param papelSolicitante Papel do usuário autenticado ou solicitante da operação.
     */
    void executar(const Papel& papelSolicitante);

    /**
     * @brief Destrutor padrão de CartaoAtividadeController.
     */
    ~CartaoAtividadeController() = default;
};

#endif // CARTAOATIVIDADECONTROLLER_H
