#ifndef PESSOACONTROLLER_H
#define PESSOACONTROLLER_H

#include "IPessoaService.h"
#include "Papel.h"

/**
 * @file PessoaController.h
 * @brief Declaração da controladora de apresentação para Pessoa.
 */
class PessoaController {
private:
    IPessoaService* servico;

public:
    explicit PessoaController(IPessoaService* servico);

    void executar(const Papel& papelSolicitante);

    ~PessoaController() = default;
};

#endif // PESSOACONTROLLER_H
