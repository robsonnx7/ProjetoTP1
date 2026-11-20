#ifndef PESSOASERVICEINT_H
#define PESSOASERVICEINT_H

#include <vector>
#include "Pessoa.h"
#include "Email.h"
#include "Papel.h"

class PessoaServiceInt {
public:
    virtual bool criar(const Pessoa& pessoa, Papel papelSolicitante) = 0;
    virtual bool ler(Pessoa* pessoa, Papel papelSolicitante) = 0;
    virtual bool atualizar(const Pessoa& pessoa, Papel papelSolicitante) = 0;
    virtual bool excluir(const Email& email, Papel papelSolicitante) = 0;
    virtual bool listar(std::vector<Pessoa>* pessoas, Papel papelSolicitante) = 0;

    virtual ~PessoaServiceInt() = default;
};

#endif // PESSOASERVICEINT_H
