#ifndef IPROJETOSERVICE_H
#define IPROJETOSERVICE_H

#include <vector>
#include "Projeto.h"
#include "Identificador.h"
#include "Papel.h"

/**
 * @file IProjetoService.h
 * @brief Interface abstrata pura para o servico de Projeto[cite: 1, 6].
 */
class IProjetoService {
public:
    virtual bool criar(const Projeto& projeto, Papel papelSolicitante) = 0;
    virtual bool ler(Projeto* projeto, Papel papelSolicitante) = 0;
    virtual bool atualizar(const Projeto& projeto, Papel papelSolicitante) = 0;
    virtual bool excluir(const Identificador& id, Papel papelSolicitante) = 0;
    virtual bool listar(std::vector<Projeto>* saida, Papel papelSolicitante) = 0;

    virtual ~IProjetoService() = default;
};

#endif // IPROJETOSERVICE_H
