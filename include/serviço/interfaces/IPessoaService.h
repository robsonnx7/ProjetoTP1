#ifndef IPESSOASERVICE_H
#define IPESSOASERVICE_H

#include <vector>
#include "Pessoa.h"
#include "Email.h"
#include "Papel.h"

/**
 * @file IPessoaService.h
 * @brief Interface para o serviço de gerenciamento de Pessoa.
 */
class IPessoaService {
public:
    virtual bool criar(const Pessoa& pessoa, Papel papelSolicitante) = 0;
    virtual bool ler(Pessoa* pessoa, Papel papelSolicitante) = 0;
    virtual bool atualizar(const Pessoa& pessoa, Papel papelSolicitante) = 0;
    virtual bool excluir(const Email& email, Papel papelSolicitante) = 0;
    virtual bool listar(std::vector<Pessoa>* pessoasSaida, Papel papelSolicitante) = 0;

    virtual ~IPessoaService() = default;
};

#endif // IPESSOASERVICE_H
