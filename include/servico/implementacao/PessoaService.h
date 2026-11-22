#ifndef PESSOASERVICE_H
#define PESSOASERVICE_H

#include <vector>
#include "IPessoaService.h"
#include "PessoaContainer.h"
#include "ProjetoContainer.h"
#include "CartaoAtividadeContainer.h"
#include "Pessoa.h"
#include "Email.h"
#include "Papel.h"

/**
 * @file PessoaService.h
 * @brief Implementacao concreta de IPessoaService.
 */
class PessoaService : public IPessoaService {
private:
    PessoaContainer* pessoaContainer;
    ProjetoContainer* projetoContainer;
    CartaoAtividadeContainer* cartaoContainer;

    bool temPermissao(Papel papelSolicitante) const;
    bool possuiVinculosAtivos(const Email& email) const;

public:
    explicit PessoaService(PessoaContainer* pessoaContainer = nullptr,
                           ProjetoContainer* projetoContainer = nullptr,
                           CartaoAtividadeContainer* cartaoContainer = nullptr);

    bool autenticar(const Email& email, const Senha& senha, Pessoa* pessoaAutenticada) override;

    bool criar(const Pessoa& pessoa, Papel papelSolicitante) override;
    bool ler(Pessoa* pessoa, Papel papelSolicitante) override;
    bool atualizar(const Pessoa& pessoa, Papel papelSolicitante) override;
    bool excluir(const Email& email, Papel papelSolicitante) override;
    bool listar(std::vector<Pessoa>* pessoasSaida, Papel papelSolicitante) override;

    ~PessoaService() override = default;
};

#endif // PESSOASERVICE_H
