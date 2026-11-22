#ifndef QUADROSERVICE_H
#define QUADROSERVICE_H

#include <vector>
#include "IQuadroService.h"
#include "QuadroContainer.h"
#include "ProjetoContainer.h"
#include "CartaoAtividadeContainer.h"

/**
 * @file QuadroService.h
 * @brief Definição da classe de serviço para gerenciamento de quadros.
 */

/**
 * @class QuadroService
 * @brief Implementa os serviços associados à entidade Quadro.
 *
 * Esta classe é responsável pela execução das regras
 * de negócio relacionadas aos quadros do sistema,
 * incluindo cadastro, consulta, atualização,
 * exclusão e listagem.
 *
 * A implementação utiliza contêineres para acesso
 * aos dados armazenados e validação dos relacionamentos
 * existentes entre projetos, quadros e cartões.
 */
class QuadroService : public IQuadroService {
private:

    QuadroContainer* quadroContainer;
    ///< Contêiner responsável pelo armazenamento dos quadros.

    ProjetoContainer* projetoContainer;
    ///< Contêiner responsável pelo armazenamento dos projetos.

    CartaoAtividadeContainer* cartaoContainer;
    ///< Contêiner responsável pelo armazenamento dos cartões de atividade.

    /**
     * @brief Verifica se um projeto está cadastrado no sistema.
     *
     * O método é utilizado para garantir que o quadro
     * seja associado a um projeto existente.
     *
     * @param idProjeto Identificador do projeto.
     *
     * @return true caso o projeto exista.
     * @return false caso o projeto não seja encontrado.
     */
    bool projetoExiste(const Identificador& idProjeto) const;

    /**
     * @brief Verifica se existem cartões vinculados ao quadro.
     *
     * O método é utilizado para impedir a exclusão
     * de quadros que ainda possuam cartões associados.
     *
     * @param idQuadro Identificador do quadro.
     *
     * @return true caso existam cartões vinculados.
     * @return false caso não existam cartões vinculados.
     */
    bool possuiCartoesVinculados(const Identificador& idQuadro) const;

public:

    /**
     * @brief Constrói o serviço de quadros.
     *
     * Inicializa o serviço com os contêineres
     * responsáveis pelo acesso aos dados do sistema.
     *
     * @param quadroContainer Contêiner de quadros.
     * @param projetoContainer Contêiner de projetos.
     * @param cartaoContainer Contêiner de cartões de atividade.
     */
    explicit QuadroService(
        QuadroContainer* quadroContainer = nullptr,
        ProjetoContainer* projetoContainer = nullptr,
        CartaoAtividadeContainer* cartaoContainer = nullptr
    );

    /**
     * @brief Cadastra um novo quadro no sistema.
     *
     * @param quadro Quadro a ser cadastrado.
     * @param papelSolicitante Papel do usuário solicitante.
     *
     * @return true caso o cadastro seja realizado.
     * @return false caso a operação falhe.
     */
    bool criar(
        const Quadro& quadro,
        Papel papelSolicitante
    ) override;

    /**
     * @brief Consulta os dados de um quadro.
     *
     * @param quadro Estrutura utilizada para receber os dados consultados.
     * @param papelSolicitante Papel do usuário solicitante.
     *
     * @return true caso a consulta seja realizada.
     * @return false caso a operação falhe.
     */
    bool ler(
        Quadro* quadro,
        Papel papelSolicitante
    ) override;

    /**
     * @brief Atualiza os dados de um quadro.
     *
     * @param quadro Quadro contendo os novos dados.
     * @param papelSolicitante Papel do usuário solicitante.
     *
     * @return true caso a atualização seja realizada.
     * @return false caso a operação falhe.
     */
    bool atualizar(
        const Quadro& quadro,
        Papel papelSolicitante
    ) override;

    /**
     * @brief Remove um quadro do sistema.
     *
     * @param id Identificador do quadro.
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
     * @brief Lista os quadros cadastrados no sistema.
     *
     * @param saida Estrutura utilizada para receber a listagem.
     * @param papelSolicitante Papel do usuário solicitante.
     *
     * @return true caso a listagem seja realizada.
     * @return false caso a operação falhe.
     */
    bool listar(
        std::vector<Quadro>* saida,
        Papel papelSolicitante
    ) override;

    /**
     * @brief Destrutor da classe.
     */
    ~QuadroService() override = default;
};

#endif // QUADROSERVICE_H
