#ifndef PROJETOCONTROLLER_H
#define PROJETOCONTROLLER_H

#include "IProjetoService.h"
#include "Papel.h"

/**
 * @file ProjetoController.h
 * @brief Declaração da controladora de apresentação para Projeto.
 */

/**
 * @class ProjetoController
 * @brief Gerencia a interação via terminal para operações CRUD e listagem de Projeto.
 */
class ProjetoController {
private:
    IProjetoService* servico; ///< Ponteiro para a interface do serviço de projeto.

public:
    /**
     * @brief Constrói a controladora associando-a ao serviço de projeto.
     * @param servico Ponteiro para implementação de IProjetoService.
     */
    explicit ProjetoController(IProjetoService* servico);

    /**
     * @brief Inicia o loop interativo do menu de projeto para o papel informado.
     * @param papelSolicitante Papel do usuário autenticado ou solicitante da operação.
     */
    void executar(const Papel& papelSolicitante);

    /**
     * @brief Destrutor padrão de ProjetoController.
     */
    ~ProjetoController() = default;
};

#endif // PROJETOCONTROLLER_H
