#ifndef IQUADROSERVICE_H
#define IQUADROSERVICE_H

#include <vector>
#include "Quadro.h"
#include "Identificador.h"
#include "Papel.h"

/**
 * @file IQuadroService.h
 * @brief Interface abstrata pura para o servico de Quadro.
 */
class IQuadroService {
public:
    virtual bool criar(const Quadro& quadro, Papel papelSolicitante) = 0;
    virtual bool ler(Quadro* quadro, Papel papelSolicitante) = 0;
    virtual bool atualizar(const Quadro& quadro, Papel papelSolicitante) = 0;
    virtual bool excluir(const Identificador& id, Papel papelSolicitante) = 0;
    virtual bool listar(std::vector<Quadro>* saida, Papel papelSolicitante) = 0;

    virtual ~IQuadroService() = default;
};

#endif // IQUADROSERVICE_H
