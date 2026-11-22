#ifndef QUADROSERVICE_H
#define QUADROSERVICE_H

#include <vector>
#include "IQuadroService.h"
#include "QuadroContainer.h"
#include "ProjetoContainer.h"
#include "CartaoAtividadeContainer.h"

/**
 * @file QuadroService.h
 * @brief Implementacao concreta de IQuadroService.
 */
class QuadroService : public IQuadroService {
private:
    QuadroContainer* quadroContainer;
    ProjetoContainer* projetoContainer;
    CartaoAtividadeContainer* cartaoContainer;

    bool projetoExiste(const Identificador& idProjeto) const;
    bool possuiCartoesVinculados(const Identificador& idQuadro) const;

public:
    explicit QuadroService(QuadroContainer* quadroContainer = nullptr,
                           ProjetoContainer* projetoContainer = nullptr,
                           CartaoAtividadeContainer* cartaoContainer = nullptr);

    bool criar(const Quadro& quadro, Papel papelSolicitante) override;
    bool ler(Quadro* quadro, Papel papelSolicitante) override;
    bool atualizar(const Quadro& quadro, Papel papelSolicitante) override;
    bool excluir(const Identificador& id, Papel papelSolicitante) override;
    bool listar(std::vector<Quadro>* saida, Papel papelSolicitante) override;

    ~QuadroService() override = default;
};

#endif // QUADROSERVICE_H
