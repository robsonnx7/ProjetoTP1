#ifndef IQUADROSERVICE_H
#define IQUADROSERVICE_H

#include <vector>
#include "Quadro.h"
#include "Identificador.h"
#include "Papel.h"

/**
 * @file IQuadroService.h
 * @brief Declaração da interface de serviço para gerenciamento de quadros.
 */

/**
 * @class IQuadroService
 * @brief Define o contrato das operações relacionadas à entidade Quadro.
 *
 * Esta interface estabelece os serviços responsáveis pelo
 * gerenciamento dos quadros cadastrados no sistema,
 * incluindo operações de criação, consulta,
 * atualização, exclusão e listagem.
 */
class IQuadroService {
public:

    /**
     * @brief Cadastra um novo quadro no sistema.
     *
     * A operação adiciona um quadro ao sistema,
     * respeitando as permissões do usuário solicitante.
     *
     * @param quadro Quadro a ser cadastrado.
     * @param papelSolicitante Papel do usuário responsável pela solicitação.
     *
     * @return true caso o cadastro seja realizado com sucesso.
     * @return false caso o cadastro não possa ser efetuado.
     */
    virtual bool criar(
        const Quadro& quadro,
        Papel papelSolicitante) = 0;

    /**
     * @brief Consulta os dados de um quadro.
     *
     * Recupera as informações do quadro solicitado.
     *
     * @param quadro Estrutura utilizada para receber os dados do quadro.
     * @param papelSolicitante Papel do usuário responsável pela solicitação.
     *
     * @return true caso a consulta seja realizada com sucesso.
     * @return false caso a consulta não possa ser efetuada.
     */
    virtual bool ler(
        Quadro* quadro,
        Papel papelSolicitante) = 0;

    /**
     * @brief Atualiza os dados de um quadro.
     *
     * Permite alterar as informações associadas
     * a um quadro previamente cadastrado.
     *
     * @param quadro Quadro contendo os novos dados.
     * @param papelSolicitante Papel do usuário responsável pela solicitação.
     *
     * @return true caso a atualização seja realizada.
     * @return false caso a atualização não possa ser efetuada.
     */
    virtual bool atualizar(
        const Quadro& quadro,
        Papel papelSolicitante) = 0;

    /**
     * @brief Remove um quadro do sistema.
     *
     * A exclusão é realizada a partir do
     * identificador informado.
     *
     * @param id Identificador do quadro.
     * @param papelSolicitante Papel do usuário responsável pela solicitação.
     *
     * @return true caso a exclusão seja realizada.
     * @return false caso a exclusão não possa ser efetuada.
     */
    virtual bool excluir(
        const Identificador& id,
        Papel papelSolicitante) = 0;

    /**
     * @brief Lista os quadros cadastrados no sistema.
     *
     * Armazena na estrutura de saída todos os quadros
     * disponíveis para consulta.
     *
     * @param saida Estrutura utilizada para receber a listagem dos quadros.
     * @param papelSolicitante Papel do usuário responsável pela solicitação.
     *
     * @return true caso a listagem seja realizada.
     * @return false caso a operação não possa ser executada.
     */
    virtual bool listar(
        std::vector<Quadro>* saida,
        Papel papelSolicitante) = 0;

    /**
     * @brief Destrutor virtual da interface.
     */
    virtual ~IQuadroService() = default;
};

#endif // IQUADROSERVICE_H
