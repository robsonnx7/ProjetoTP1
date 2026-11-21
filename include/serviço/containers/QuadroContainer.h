#ifndef QUADROCONTAINER_H
#define QUADROCONTAINER_H

#include <vector>
#include "Quadro.h"
#include "Identificador.h"

/**
 * @file QuadroContainer.h
 * @brief Container em memoria para armazenamento de objetos Quadro.
 */
class QuadroContainer {
private:
    std::vector<Quadro> quadros;

    int buscarIndicePorId(const Identificador& id) const;

public:
    QuadroContainer() = default;

    bool inserir(const Quadro& quadro);
    bool buscar(Quadro* quadro) const;
    bool atualizar(const Quadro& quadro);
    bool remover(const Identificador& id);
    bool listar(std::vector<Quadro>* saida) const;
    bool existePorProjeto(const Identificador& idProjeto) const;
};

#endif // QUADROCONTAINER_H
