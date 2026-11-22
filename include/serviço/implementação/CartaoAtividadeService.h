#ifndef CARTAOATIVIDADESERVICE_H
#define CARTAOATIVIDADESERVICE_H

#include <vector>
#include "ICartaoAtividadeService.h"
#include "CartaoAtividadeContainer.h"
#include "QuadroContainer.h"
#include "PessoaContainer.h"

/**
 * @file CartaoAtividadeService.h
 * @brief Definição da classe de serviço para gerenciamento de cartões de atividade.
 */

/**
 * @class CartaoAtividadeService
 * @brief Implementa os serviços associados à entidade CartaoAtividade.
 *
 * Esta classe é responsável pela execução das operações
 * de negócio relacionadas aos cartões de atividade,
 * incluindo cadastro, consulta, atualização,
 * exclusão e listagem.
 *
 * A implementação utiliza contêineres para acesso e
 * armazenamento dos dados do sistema.
 */
class CartaoAtividadeService : public ICartaoAtividadeService {
private:

    CartaoAtividadeContainer* cartaoContainer;
    ///< Contêiner responsável pelo armazenamento dos cartões.

    QuadroContainer* quadroContainer;
    ///< Contêiner responsável pelo armazenamento dos quadros.

    PessoaContainer* pessoaContainer;
    ///< Contêiner responsável pelo armazenamento das pessoas.

    /**
     * @brief Verifica se um quadro está cadastrado.
     *
     * @param idQuadro Identificador do quadro.
     *
     * @return true caso o quadro exista.
     * @return false caso o quadro não seja encontrado.
     */
    bool quadroExiste(const Identificador& idQuadro) const;

    /**
     * @brief Verifica se um desenvolvedor está cadastrado.
     *
     * @param emailDesenvolvedor E-mail do desenvolvedor.
     *
     * @return true caso o desenvolvedor exista.
     * @return false caso o desenvolvedor não seja encontrado.
     */
    bool desenvolvedorExiste(const Email& emailDesenvolvedor) const;

public:

    /**
     * @brief Constrói o serviço de cartões de atividade.
     *
     * Inicializa o serviço com os contêineres responsáveis
     * pelo acesso aos dados do sistema.
     *
     * @param cartaoContainer Contêiner de cartões.
     * @param quadroContainer Contêiner de quadros.
     * @param pessoaContainer Contêiner de pessoas.
     */
    explicit CartaoAtividadeService(
        CartaoAtividadeContainer* cartaoContainer = nullptr,
        QuadroContainer* quadroContainer = nullptr,
        PessoaContainer* pessoaContainer = nullptr
    );

    /**
     * @brief Cria um novo cartão de atividade.
     *
     * @param cartao Cartão a ser cadastrado.
     * @param papelSolicitante Papel do usuário solicitante.
     *
     * @return true caso o cadastro seja realizado.
     * @return false caso a operação falhe.
     */
    bool criar(
        const CartaoAtividade& cartao,
        Papel papelSolicitante
    ) override;

    /**
     * @brief Consulta um cartão de atividade.
     *
     * @param cartao Estrutura utilizada para receber os dados.
     * @param papelSolicitante Papel do usuário solicitante.
     *
     * @return true caso a consulta seja realizada.
     * @return false caso a operação falhe.
     */
    bool ler(
        CartaoAtividade* cartao,
        Papel papelSolicitante
    ) override;

    /**
     * @brief Atualiza os dados de um cartão de atividade.
     *
     * @param cartao Cartão contendo os novos dados.
     * @param papelSolicitante Papel do usuário solicitante.
     *
     * @return true caso a atualização seja realizada.
     * @return false caso a operação falhe.
     */
    bool atualizar(
        const CartaoAtividade& cartao,
        Papel papelSolicitante
    ) override;

    /**
     * @brief Remove um cartão de atividade.
     *
     * @param id Identificador do cartão.
     * @param papelSolicitante Papel do usuário solicitante.
     *
     * @return true caso a exclusão seja realizada.
     * @return false caso a operação falhe.
     */
    bool excluir(
        const Identificador& id,
        Papel papelSolicitante
    ) override;

    /**
     * @brief Lista os cartões de atividade cadastrados.
     *
     * @param saida Estrutura utilizada para receber a listagem.
     * @param papelSolicitante Papel do usuário solicitante.
     *
     * @return true caso a listagem seja realizada.
     * @return false caso a operação falhe.
     */
    bool listar(
        std::vector<CartaoAtividade>* saida,
        Papel papelSolicitante
    ) override;

    /**
     * @brief Destrutor da classe.
     */
    ~CartaoAtividadeService() override = default;
};

#endif // CARTAOATIVIDADESERVICE_H
