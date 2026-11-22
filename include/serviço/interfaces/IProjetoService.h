#ifndef IPROJETOSERVICE_H
#define IPROJETOSERVICE_H

#include <vector>
#include "Projeto.h"
#include "Identificador.h"
#include "Papel.h"

/**
 * @file IProjetoService.h
 * @brief Declaração da interface de serviço para gerenciamento de projetos.
 */

/**
 * @class IProjetoService
 * @brief Define o contrato das operações relacionadas à entidade Projeto.
 *
 * Esta interface estabelece os serviços responsáveis pelo
 * gerenciamento de projetos cadastrados no sistema,
 * incluindo operações de criação, consulta,
 * atualização, exclusão e listagem.
 */
class IProjetoService {
public:

    /**
     * @brief Cadastra um novo projeto no sistema.
     *
     * A operação adiciona um projeto ao sistema,
     * respeitando as permissões do usuário solicitante.
     *
     * @param projeto Projeto a ser cadastrado.
     * @param papelSolicitante Papel do usuário responsável pela solicitação.
     *
     * @return true caso o cadastro seja realizado com sucesso.
     * @return false caso o cadastro não possa ser efetuado.
     */
    virtual bool criar(
        const Projeto& projeto,
        Papel papelSolicitante) = 0;

    /**
     * @brief Consulta os dados de um projeto.
     *
     * Recupera as informações do projeto solicitado.
     *
     * @param projeto Estrutura utilizada para receber os dados do projeto.
     * @param papelSolicitante Papel do usuário responsável pela solicitação.
     *
     * @return true caso a consulta seja realizada com sucesso.
     * @return false caso a consulta não possa ser efetuada.
     */
    virtual bool ler(
        Projeto* projeto,
        Papel papelSolicitante) = 0;

    /**
     * @brief Atualiza os dados de um projeto.
     *
     * Permite alterar as informações associadas
     * a um projeto previamente cadastrado.
     *
     * @param projeto Projeto contendo os novos dados.
     * @param papelSolicitante Papel do usuário responsável pela solicitação.
     *
     * @return true caso a atualização seja realizada.
     * @return false caso a atualização não possa ser efetuada.
     */
    virtual bool atualizar(
        const Projeto& projeto,
        Papel papelSolicitante) = 0;

    /**
     * @brief Remove um projeto do sistema.
     *
     * A exclusão é realizada a partir do
     * identificador informado.
     *
     * @param id Identificador do projeto.
     * @param papelSolicitante Papel do usuário responsável pela solicitação.
     *
     * @return true caso a exclusão seja realizada.
     * @return false caso a exclusão não possa ser efetuada.
     */
    virtual bool excluir(
        const Identificador& id,
        Papel papelSolicitante) = 0;

    /**
     * @brief Lista os projetos cadastrados no sistema.
     *
     * Armazena na estrutura de saída todos os projetos
     * disponíveis para consulta.
     *
     * @param saida Estrutura utilizada para receber a listagem dos projetos.
     * @param papelSolicitante Papel do usuário responsável pela solicitação.
     *
     * @return true caso a listagem seja realizada.
     * @return false caso a operação não possa ser executada.
     */
    virtual bool listar(
        std::vector<Projeto>* saida,
        Papel papelSolicitante) = 0;

    /**
     * @brief Destrutor virtual da interface.
     */
    virtual ~IProjetoService() = default;
};

#endif // IPROJETOSERVICE_H
