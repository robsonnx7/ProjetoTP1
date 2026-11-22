#ifndef IPESSOASERVICE_H
#define IPESSOASERVICE_H

#include <vector>
#include "Pessoa.h"
#include "Email.h"
#include "Papel.h"
#include "Senha.h"

/**
 * @file IPessoaService.h
 * @brief Declaração da interface de serviço para gerenciamento de pessoas.
 */

/**
 * @class IPessoaService
 * @brief Define o contrato das operações relacionadas à entidade Pessoa.
 *
 * Esta interface estabelece os serviços responsáveis pelo
 * gerenciamento de pessoas cadastradas no sistema,
 * incluindo autenticação, criação, consulta,
 * atualização, exclusão e listagem.
 */
class IPessoaService {
public:

    /**
     * @brief Autentica uma pessoa no sistema.
     *
     * Verifica se o e-mail e a senha informados
     * correspondem a uma pessoa cadastrada.
     *
     * @param email Endereço de e-mail utilizado na autenticação.
     * @param senha Senha utilizada na autenticação.
     * @param pessoaAutenticada Estrutura utilizada para receber os dados da pessoa autenticada.
     *
     * @return true caso a autenticação seja realizada com sucesso.
     * @return false caso as credenciais sejam inválidas.
     */
    virtual bool autenticar(
        const Email& email,
        const Senha& senha,
        Pessoa* pessoaAutenticada) = 0;

    /**
     * @brief Cadastra uma nova pessoa no sistema.
     *
     * A operação adiciona uma nova pessoa ao sistema,
     * respeitando as permissões do solicitante.
     *
     * @param pessoa Pessoa a ser cadastrada.
     * @param papelSolicitante Papel do usuário responsável pela solicitação.
     *
     * @return true caso o cadastro seja realizado.
     * @return false caso o cadastro não possa ser efetuado.
     */
    virtual bool criar(
        const Pessoa& pessoa,
        Papel papelSolicitante) = 0;

    /**
     * @brief Consulta os dados de uma pessoa.
     *
     * Recupera as informações da pessoa solicitada.
     *
     * @param pessoa Estrutura utilizada para receber os dados consultados.
     * @param papelSolicitante Papel do usuário responsável pela solicitação.
     *
     * @return true caso a consulta seja realizada.
     * @return false caso a consulta não possa ser efetuada.
     */
    virtual bool ler(
        Pessoa* pessoa,
        Papel papelSolicitante) = 0;

    /**
     * @brief Atualiza os dados de uma pessoa.
     *
     * Permite modificar as informações associadas
     * a uma pessoa previamente cadastrada.
     *
     * @param pessoa Pessoa contendo os novos dados.
     * @param papelSolicitante Papel do usuário responsável pela solicitação.
     *
     * @return true caso a atualização seja realizada.
     * @return false caso a atualização não possa ser efetuada.
     */
    virtual bool atualizar(
        const Pessoa& pessoa,
        Papel papelSolicitante) = 0;

    /**
     * @brief Remove uma pessoa do sistema.
     *
     * A exclusão é realizada a partir do endereço
     * de e-mail informado.
     *
     * @param email E-mail da pessoa a ser removida.
     * @param papelSolicitante Papel do usuário responsável pela solicitação.
     *
     * @return true caso a exclusão seja realizada.
     * @return false caso a exclusão não possa ser efetuada.
     */
    virtual bool excluir(
        const Email& email,
        Papel papelSolicitante) = 0;

    /**
     * @brief Lista as pessoas cadastradas no sistema.
     *
     * Armazena na estrutura de saída todas as pessoas
     * disponíveis para consulta.
     *
     * @param pessoasSaida Estrutura utilizada para receber a listagem.
     * @param papelSolicitante Papel do usuário responsável pela solicitação.
     *
     * @return true caso a listagem seja realizada.
     * @return false caso a operação não possa ser executada.
     */
    virtual bool listar(
        std::vector<Pessoa>* pessoasSaida,
        Papel papelSolicitante) = 0;

    /**
     * @brief Destrutor virtual da interface.
     */
    virtual ~IPessoaService() = default;
};

#endif // IPESSOASERVICE_H
