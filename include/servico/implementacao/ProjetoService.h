#ifndef PROJETOSERVICE_H
#define PROJETOSERVICE_H

#include <vector>
#include "IProjetoService.h"
#include "ProjetoContainer.h"
#include "QuadroContainer.h"
#include "IPessoaService.h"

/**
 * @file ProjetoService.h
 * @brief Implementacao concreta de IProjetoService[cite: 1, 6].
 */
class ProjetoService : public IProjetoService {
private:
    ProjetoContainer* projetoContainer;
    QuadroContainer* quadroContainer;
    IPessoaService* pessoaService;

    bool gestorExiste(const Email& emailGestor, Papel papelSolicitante) const;
    bool possuiQuadrosVinculados(const Identificador& idProjeto) const;

public:
    ProjetoService(ProjetoContainer* projetoContainer = nullptr,
                   IPessoaService* pessoaService = nullptr,
                   QuadroContainer* quadroContainer = nullptr);

    bool criar(const Projeto& projeto, Papel papelSolicitante) override;
    bool ler(Projeto* projeto, Papel papelSolicitante) override;
    bool atualizar(const Projeto& projeto, Papel papelSolicitante) override;
    bool excluir(const Identificador& id, Papel papelSolicitante) override;
    bool listar(std::vector<Projeto>* saida, Papel papelSolicitante) override;

    ~ProjetoService() override = default;
};

#endif // PROJETOSERVICE_H
