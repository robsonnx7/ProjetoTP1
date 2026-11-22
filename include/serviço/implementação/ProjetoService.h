#ifndef PROJETOSERVICE_H
#define PROJETOSERVICE_H

#include <vector>
#include "IProjetoService.h"
#include "ProjetoContainer.h"
#include "QuadroContainer.h"
#include "IPessoaService.h"

/**
 * @file ProjetoService.h
 * @brief Definição da classe de serviço para gerenciamento de projetos.
 */

/**
 * @class ProjetoService
 * @brief Implementa os serviços associados à entidade Projeto.
 *
 * Esta classe é responsável pela execução das regras
 * de negócio relacionadas aos projetos do sistema,
 * incluindo operações de cadastro, consulta,
 * atualização, exclusão e listagem.
 *
 * A implementação utiliza contêineres e outros
 * serviços para validar relacionamentos e
 * acessar os dados armazenados.
 */
class ProjetoService : public IProjetoService {
private:

    ProjetoContainer* projetoContainer;
    ///< Contêiner responsável pelo armazenamento dos projetos.

    QuadroContainer* quadroContainer;
    ///< Contêiner responsável pelo armazenamento dos quadros.

    IPessoaService* pessoaService;
    ///< Serviço utilizado para validações relacionadas às pessoas.

    /**
     * @brief Verifica se o gestor informado existe no sistema.
     *
     * O método é utilizado para garantir que o projeto
     * seja associado a um gestor previamente cadastrado.
     *
     * @param emailGestor E-mail do gestor responsável.
     * @param papelSolicitante Papel do usuário solicitante.
     *
     * @return true caso o gestor exista.
     * @return false caso o gestor não seja encontrado.
     */
    bool gestorExiste(
        const Email& emailGestor,
        Papel papelSolicitante
    ) const;

    /**
     * @brief Verifica se existem quadros vinculados ao projeto.
     *
     * O método é utilizado para impedir a exclusão
     * de projetos que ainda possuam quadros associados.
     *
     * @param idProjeto Identificador do projeto.
     *
     * @return true caso existam quadros vinculados.
     * @return false caso não existam quadros vinculados.
     */
    bool possuiQuadrosVinculados(
        const Identificador& idProjeto
    ) const;

public:

    /**
     * @brief Constrói o serviço de projetos.
     *
     * Inicializa o serviço com os componentes
     * responsáveis pelo acesso aos dados do sistema.
     *
     * @param projetoContainer Contêiner de projetos.
     * @param pessoaService Serviço de pessoas.
     * @param quadroContainer Contêiner de quadros.
     */
    ProjetoService(
        ProjetoContainer* projetoContainer = nullptr,
        IPessoaService* pessoaService = nullptr,
        QuadroContainer* quadroContainer = nullptr
    );

    /**
     * @brief Cadastra um novo projeto no sistema.
     *
     * @param projeto Projeto a ser cadastrado.
     * @param papelSolicitante Papel do usuário solicitante.
     *
     * @return true caso o cadastro seja realizado.
     * @return false caso a operação falhe.
     */
    bool criar(
        const Projeto& projeto,
        Papel papelSolicitante
    ) override;

    /**
     * @brief Consulta os dados de um projeto.
     *
     * @param projeto Estrutura utilizada para receber os dados consultados.
     * @param papelSolicitante Papel do usuário solicitante.
     *
     * @return true caso a consulta seja realizada.
     * @return false caso a operação falhe.
     */
    bool ler(
        Projeto* projeto,
        Papel papelSolicitante
    ) override;

    /**
     * @brief Atualiza os dados de um projeto.
     *
     * @param projeto Projeto contendo os novos dados.
     * @param papelSolicitante Papel do usuário solicitante.
     *
     * @return true caso a atualização seja realizada.
     * @return false caso a operação falhe.
     */
    bool atualizar(
        const Projeto& projeto,
        Papel papelSolicitante
    ) override;

    /**
     * @brief Remove um projeto do sistema.
     *
     * @param id Identificador do projeto.
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
     * @brief Lista os projetos cadastrados no sistema.
     *
     * @param saida Estrutura utilizada para receber a listagem.
     * @param papelSolicitante Papel do usuário solicitante.
     *
     * @return true caso a listagem seja realizada.
     * @return false caso a operação falhe.
     */
    bool listar(
        std::vector<Projeto>* saida,
        Papel papelSolicitante
    ) override;

    /**
     * @brief Destrutor da classe.
     */
    ~ProjetoService() override = default;
};

#endif // PROJETOSERVICE_H
