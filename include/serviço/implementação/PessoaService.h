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
 * @brief Definição da classe de serviço para gerenciamento de pessoas.
 */

/**
 * @class PessoaService
 * @brief Implementa os serviços associados à entidade Pessoa.
 *
 * Esta classe é responsável pelas regras de negócio
 * relacionadas ao gerenciamento de pessoas no sistema,
 * incluindo autenticação, cadastro, consulta,
 * atualização, exclusão e listagem.
 *
 * A implementação utiliza contêineres para acesso
 * aos dados persistidos no sistema.
 */
class PessoaService : public IPessoaService {
private:

    PessoaContainer* pessoaContainer;
    ///< Contêiner responsável pelo armazenamento das pessoas.

    ProjetoContainer* projetoContainer;
    ///< Contêiner responsável pelo armazenamento dos projetos.

    CartaoAtividadeContainer* cartaoContainer;
    ///< Contêiner responsável pelo armazenamento dos cartões de atividade.

    /**
     * @brief Verifica se um usuário possui permissão para executar uma operação.
     *
     * @param papelSolicitante Papel do usuário solicitante.
     *
     * @return true caso o usuário possua permissão.
     * @return false caso o usuário não possua permissão.
     */
    bool temPermissao(Papel papelSolicitante) const;

    /**
     * @brief Verifica se uma pessoa possui vínculos ativos no sistema.
     *
     * O método é utilizado para impedir a exclusão
     * de pessoas associadas a projetos ou atividades.
     *
     * @param email E-mail da pessoa.
     *
     * @return true caso existam vínculos ativos.
     * @return false caso não existam vínculos ativos.
     */
    bool possuiVinculosAtivos(const Email& email) const;

public:

    /**
     * @brief Constrói o serviço de pessoas.
     *
     * Inicializa o serviço com os contêineres
     * necessários para acesso aos dados do sistema.
     *
     * @param pessoaContainer Contêiner de pessoas.
     * @param projetoContainer Contêiner de projetos.
     * @param cartaoContainer Contêiner de cartões de atividade.
     */
    explicit PessoaService(
        PessoaContainer* pessoaContainer = nullptr,
        ProjetoContainer* projetoContainer = nullptr,
        CartaoAtividadeContainer* cartaoContainer = nullptr
    );

    /**
     * @brief Realiza a autenticação de uma pessoa.
     *
     * Verifica se o e-mail e a senha informados
     * correspondem a uma pessoa cadastrada.
     *
     * @param email E-mail utilizado na autenticação.
     * @param senha Senha utilizada na autenticação.
     * @param pessoaAutenticada Estrutura utilizada para receber os dados da pessoa autenticada.
     *
     * @return true caso a autenticação seja realizada com sucesso.
     * @return false caso as credenciais sejam inválidas.
     */
    bool autenticar(
        const Email& email,
        const Senha& senha,
        Pessoa* pessoaAutenticada
    ) override;

    /**
     * @brief Cadastra uma nova pessoa no sistema.
     *
     * @param pessoa Pessoa a ser cadastrada.
     * @param papelSolicitante Papel do usuário solicitante.
     *
     * @return true caso o cadastro seja realizado.
     * @return false caso a operação falhe.
     */
    bool criar(
        const Pessoa& pessoa,
        Papel papelSolicitante
    ) override;

    /**
     * @brief Consulta os dados de uma pessoa.
     *
     * @param pessoa Estrutura utilizada para receber os dados consultados.
     * @param papelSolicitante Papel do usuário solicitante.
     *
     * @return true caso a consulta seja realizada.
     * @return false caso a operação falhe.
     */
    bool ler(
        Pessoa* pessoa,
        Papel papelSolicitante
    ) override;

    /**
     * @brief Atualiza os dados de uma pessoa.
     *
     * @param pessoa Pessoa contendo os novos dados.
     * @param papelSolicitante Papel do usuário solicitante.
     *
     * @return true caso a atualização seja realizada.
     * @return false caso a operação falhe.
     */
    bool atualizar(
        const Pessoa& pessoa,
        Papel papelSolicitante
    ) override;

    /**
     * @brief Remove uma pessoa do sistema.
     *
     * @param email E-mail da pessoa a ser removida.
     * @param papelSolicitante Papel do usuário solicitante.
     *
     * @return true caso a exclusão seja realizada.
     * @return false caso a operação falhe.
     */
    bool excluir(
        const Email& email,
        Papel papelSolicitante
    ) override;

    /**
     * @brief Lista as pessoas cadastradas no sistema.
     *
     * @param pessoasSaida Estrutura utilizada para receber a listagem.
     * @param papelSolicitante Papel do usuário solicitante.
     *
     * @return true caso a listagem seja realizada.
     * @return false caso a operação falhe.
     */
    bool listar(
        std::vector<Pessoa>* pessoasSaida,
        Papel papelSolicitante
    ) override;

    /**
     * @brief Destrutor da classe.
     */
    ~PessoaService() override = default;
};

#endif // PESSOASERVICE_H
