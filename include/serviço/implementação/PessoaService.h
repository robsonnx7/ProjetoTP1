#ifndef PESSOASERVICE_H
#define PESSOASERVICE_H

#include <string>
#include <vector>
#include "IPessoaService.h"
#include "Pessoa.h"
#include "Email.h"
#include "Papel.h"

/**
 * @file PessoaService.h
 * @brief Declaração da implementação concreta de IPessoaService.
 */
class PessoaService : public IPessoaService {
private:
    std::vector<Pessoa> pessoas;

    bool temPermissao(Papel papelSolicitante) const;
    int buscarIndicePorEmail(const Email& email) const;

public:
    PessoaService() = default;

    bool criar(const Pessoa& pessoa, Papel papelSolicitante) override;
    bool ler(Pessoa* pessoa, Papel papelSolicitante) override;
    bool atualizar(const Pessoa& pessoa, Papel papelSolicitante) override;
    bool excluir(const Email& email, Papel papelSolicitante) override;
    bool listar(std::vector<Pessoa>* pessoasSaida, Papel papelSolicitante) override;

    ~PessoaService() override = default;
};

#endif // PESSOASERVICE_H
