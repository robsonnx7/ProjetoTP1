#ifndef PESSOACONTAINER_H
#define PESSOACONTAINER_H

#include <vector>
#include "Pessoa.h"
#include "Email.h"

/**
 * @file PessoaContainer.h
 * @brief Declaração do container em memória para a entidade Pessoa.
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

    ~PessoaContainer() = default;
};

#endif // PESSOACONTAINER_H
