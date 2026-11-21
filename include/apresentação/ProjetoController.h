#ifndef PROJETOCONTROLLER_H
#define PROJETOCONTROLLER_H

#include "IProjetoService.h"

/**
 * @file ProjetoController.h
 * @brief Controladora de apresentacao para Projeto[cite: 1, 6].
 */
class ProjetoController {
private:
    IProjetoService* servico;

public:
    explicit ProjetoController(IProjetoService* servico);

    void executar();

    ~ProjetoController() = default;
};

#endif // PROJETOCONTROLLER_H
