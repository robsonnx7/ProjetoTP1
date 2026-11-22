#ifndef ICARTAOATIVIDADESERVICE_H
#define ICARTAOATIVIDADESERVICE_H

#include <vector>
#include "CartaoAtividade.h"
#include "Identificador.h"
#include "Papel.h"

/**
 * @file ICartaoAtividadeService.h
 * @brief Declaração da interface de serviço para gerenciamento de cartões de atividade.
 */

/**
 * @class ICartaoAtividadeService
 * @brief Define o contrato das operações disponíveis para cartões de atividade.
 *
 * Esta interface estabelece os serviços responsáveis pelo
 * gerenciamento de cartões de atividade do sistema,
 * incluindo operações de criação, consulta,
 * atualização, exclusão e listagem.
 */
class ICartaoAtividadeService {
public:

    /**
     * @brief Cadastra um novo cartão de atividade.
     *
     * A operação insere um novo cartão no sistema,
     * desde que o usuário possua permissão para
     * realizar a ação.
     *
     * @param cartao Cartão de atividade a ser cadastrado.
     * @param papelSolicitante Papel do usuário solicitante.
     *
     * @return true caso a operação seja concluída com sucesso.
     * @return false caso a operação não possa ser realizada.
     */
    virtual bool criar(
        const CartaoAtividade& cartao,
        Papel papelSolicitante) = 0;

    /**
     * @brief Consulta um cartão de atividade.
     *
     * Recupera as informações do cartão solicitado,
     * desde que o usuário possua autorização para
     * executar a operação.
     *
     * @param cartao Ponteiro para o cartão a ser consultado.
     * @param papelSolicitante Papel do usuário solicitante.
     *
     * @return true caso o cartão seja localizado.
     * @return false caso a consulta não possa ser realizada.
     */
    virtual bool ler(
        CartaoAtividade* cartao,
        Papel papelSolicitante) = 0;

    /**
     * @brief Atualiza os dados de um cartão de atividade.
     *
     * Permite alterar as informações armazenadas
     * para um cartão existente.
     *
     * @param cartao Cartão contendo os novos dados.
     * @param papelSolicitante Papel do usuário solicitante.
     *
     * @return true caso a atualização seja realizada.
     * @return false caso a atualização não seja permitida.
     */
    virtual bool atualizar(
        const CartaoAtividade& cartao,
        Papel papelSolicitante) = 0;

    /**
     * @brief Remove um cartão de atividade do sistema.
     *
     * A exclusão é realizada a partir do identificador
     * do cartão informado.
     *
     * @param id Identificador do cartão.
     * @param papelSolicitante Papel do usuário solicitante.
     *
     * @return true caso o cartão seja removido.
     * @return false caso a operação não possa ser realizada.
     */
    virtual bool excluir(
        const Identificador& id,
        Papel papelSolicitante) = 0;

    /**
     * @brief Lista os cartões de atividade disponíveis.
     *
     * Armazena os cartões encontrados na estrutura
     * indicada pelo parâmetro de saída.
     *
     * @param saida Estrutura utilizada para receber os cartões.
     * @param papelSolicitante Papel do usuário solicitante.
     *
     * @return true caso a listagem seja realizada.
     * @return false caso a operação não possa ser executada.
     */
    virtual bool listar(
        std::vector<CartaoAtividade>* saida,
        Papel papelSolicitante) = 0;

    /**
     * @brief Destrutor virtual da interface.
     */
    virtual ~ICartaoAtividadeService() = default;
};

#endif // ICARTAOATIVIDADESERVICE_H
