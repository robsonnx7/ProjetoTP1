#ifndef PESSOACONTAINER_H
#define PESSOACONTAINER_H

#include <vector>
#include "Pessoa.h"
#include "Email.h"

/**
 * @file PessoaContainer.h
 * @brief Container em memoria para armazenamento de objetos Pessoa.
 */
class PessoaContainer {
private:
    std::vector<Pessoa> pessoas;

    int buscarIndicePorEmail(const Email& email) const;

public:
    PessoaContainer() = default;

    bool inserir(const Pessoa& pessoa);
    bool buscar(Pessoa* pessoa) const;
    bool atualizar(const Pessoa& pessoa);
    bool remover(const Email& email);
    bool listar(std::vector<Pessoa>* pessoasSaida) const;
};

#endif // PESSOACONTAINER_H
