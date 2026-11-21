#ifndef CARTAOATIVIDADESERVICE_H
#define CARTAOATIVIDADESERVICE_H

#include <vector>
#include "ICartaoAtividadeService.h"
#include "CartaoAtividadeContainer.h"
#include "QuadroContainer.h"
#include "PessoaContainer.h"

/**
 * @file CartaoAtividadeService.h
 * @brief Implementacao concreta de ICartaoAtividadeService[cite: 2].
 */
class CartaoAtividadeService : public ICartaoAtividadeService {
private:
    CartaoAtividadeContainer* cartaoContainer;
    QuadroContainer* quadroContainer;
    PessoaContainer* pessoaContainer;

    bool quadroExiste(const Identificador& idQuadro) const;
    bool desenvolvedorExiste(const Email& emailDesenvolvedor) const;

public:
    explicit CartaoAtividadeService(CartaoAtividadeContainer* cartaoContainer = nullptr,
                                    QuadroContainer* quadroContainer = nullptr,
                                    PessoaContainer* pessoaContainer = nullptr);

    bool criar(const CartaoAtividade& cartao, Papel papelSolicitante) override;
    bool ler(CartaoAtividade* cartao, Papel papelSolicitante) override;
    bool atualizar(const CartaoAtividade& cartao, Papel papelSolicitante) override;
    bool excluir(const Identificador& id, Papel papelSolicitante) override;
    bool listar(std::vector<CartaoAtividade>* saida, Papel papelSolicitante) override;

    ~CartaoAtividadeService() override = default;
};

#endif // CARTAOATIVIDADESERVICE_H
