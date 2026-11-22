#ifndef QUADROCONTROLLER_H
#define QUADROCONTROLLER_H

#include "IQuadroService.h"
#include "Papel.h"

/**
 * @file QuadroController.h
 * @brief Declaração da controladora de apresentação para Quadro.
 */

/**
 * @class QuadroController
 * @brief Gerencia a interação via terminal para operações CRUD e listagem de Quadro.
 */
class QuadroController {
private:
    IQuadroService* servico; ///< Ponteiro para a interface do serviço de quadro.

public:
    /**
     * @brief Constrói a controladora associando-a ao serviço de quadro.
     * @param servico Ponteiro para implementação de IQuadroService.
     */
    explicit QuadroController(IQuadroService* servico);

    /**
     * @brief Inicia o loop interativo do menu de quadro para o papel informado.
     * @param papelSolicitante Papel do usuário autenticado ou solicitante da operação.
     */
    void executar(const Papel& papelSolicitante);

    /**
     * @brief Destrutor padrão de QuadroController.
     */
    ~QuadroController() = default;
};

#endif // QUADROCONTROLLER_H
