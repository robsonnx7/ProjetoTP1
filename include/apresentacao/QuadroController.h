#ifndef QUADROCONTROLLER_H
#define QUADROCONTROLLER_H

#include "IQuadroService.h"
#include "Papel.h"

/**
 * @file QuadroController.h
 * @brief Controladora de apresentacao para Quadro.
 */
class QuadroController {
private:
    IQuadroService* servico;

public:
    explicit QuadroController(IQuadroService* servico);

    void executar(const Papel& papelSolicitante);

    ~QuadroController() = default;
};

#endif // QUADROCONTROLLER_H
