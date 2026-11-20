#ifndef PESSOASERVICE_H
#define PESSOASERVICE_H

#include <vector>
#include "PessoaServiceInt.h"
#include "PessoaContainer.h"
#include "Pessoa.h"
#include "Email.h"
#include "Papel.h"

class PessoaService : public PessoaServiceInt {
private:
    PessoaContainer container;
    bool temPermissao(Papel papel) const;

public:
    bool criar(const Pessoa& pessoa, Papel papelSolicitante) override;
    bool ler(Pessoa* pessoa, Papel papelSolicitante) override;
    bool atualizar(const Pessoa& pessoa, Papel papelSolicitante) override;
    bool excluir(const Email& email, Papel papelSolicitante) override;
    bool listar(std::vector<Pessoa>* pessoas, Papel papelSolicitante) override;
};

#endif // PESSOASERVICE_H
