#ifndef PESSOACONTROLLER_H
#define PESSOACONTROLLER_H

#include "IPessoaService.h"
#include "Papel.h"

/**
 * @file PessoaController.h
 * @brief Declaração da controladora de apresentação para Pessoa.
 */

/**
 * @class PessoaController
 * @brief Gerencia a interação via terminal para operações CRUD e listagem de Pessoa.
 */
class PessoaController {
private:
    IPessoaService* servico; ///< Ponteiro para a interface do serviço de pessoa.

public:
    /**
     * @brief Constrói a controladora associando-a ao serviço de pessoa.
     * @param servico Ponteiro para implementação de IPessoaService.
     */
    explicit PessoaController(IPessoaService* servico);

    /**
     * @brief Inicia o loop interativo do menu de pessoa para o papel informado.
     * @param papelSolicitante Papel do usuário autenticado ou solicitante da operação.
     */
    void executar(const Papel& papelSolicitante);

    /**
     * @brief Destrutor padrão de PessoaController.
     */
    ~PessoaController() = default;
};

#endif // PESSOACONTROLLER_H
