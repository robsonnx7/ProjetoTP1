#ifndef PROJETOCONTAINER_H
#define PROJETOCONTAINER_H

#include <vector>
#include "Projeto.h"
#include "Identificador.h"
#include "Email.h"

/**
 * @file ProjetoContainer.h
 * @brief Container em memoria para armazenamento de objetos Projeto[cite: 1, 6].
 */
class ProjetoContainer {
private:
    std::vector<Projeto> projetos;

    int buscarIndicePorId(const Identificador& id) const;

public:
    ProjetoContainer() = default;

    bool inserir(const Projeto& projeto);
    bool buscar(Projeto* projeto) const;
    bool atualizar(const Projeto& projeto);
    bool remover(const Identificador& id);
    bool listar(std::vector<Projeto>* saida) const;
    bool existePorGestor(const Email& emailGestor) const;
};

#endif // PROJETOCONTAINER_H
