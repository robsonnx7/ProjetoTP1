#ifndef QUADROCONTAINER_H
#define QUADROCONTAINER_H

#include <vector>
#include "Quadro.h"
#include "Identificador.h"

/**
 * @file QuadroContainer.h
 * @brief Declaração do container em memória para armazenamento de objetos Quadro.
 */

/**
 * @class QuadroContainer
 * @brief Gerencia o armazenamento e as operações básicas em memória de entidades Quadro.
 *
 * Mantém uma coleção em memória indexada pelo Identificador do quadro e oferece
 * consultas auxiliares, como a verificação de quadros vinculados a um projeto.
 */
class QuadroContainer {
private:
    std::vector<Quadro> quadros; ///< Coleção em memória dos quadros cadastrados.

    /**
     * @brief Localiza o índice de um quadro no vetor interno a partir do identificador.
     * @param id Identificador utilizado como chave de busca.
     * @return Índice do quadro se encontrado, ou -1 caso contrário.
     */
    int buscarIndicePorId(const Identificador& id) const;

public:
    /**
     * @brief Construtor padrão de QuadroContainer.
     */
    QuadroContainer() = default;

    /**
     * @brief Insere um novo quadro caso não exista outro com o mesmo identificador.
     * @param quadro Objeto Quadro a ser inserido.
     * @return true se a inserção foi realizada; false se o identificador já estiver cadastrado.
     */
    bool inserir(const Quadro& quadro);

    /**
     * @brief Busca um quadro pelo identificador informado e preenche os dados encontrados.
     * @param[in,out] quadro Ponteiro para Quadro contendo o identificador de busca; recebe os dados completos se encontrado.
     * @return true se o quadro foi encontrado; false se o ponteiro for nulo ou o identificador não existir.
     */
    bool buscar(Quadro* quadro) const;

    /**
     * @brief Atualiza os dados de um quadro já existente identificado pelo identificador.
     * @param quadro Objeto Quadro com os dados atualizados.
     * @return true se a atualização foi concluída; false se o identificador não for encontrado.
     */
    bool atualizar(const Quadro& quadro);

    /**
     * @brief Remove um quadro do container a partir do identificador.
     * @param id Identificador do quadro a ser removido.
     * @return true se a remoção foi realizada; false se o identificador não for encontrado.
     */
    bool remover(const Identificador& id);

    /**
     * @brief Copia todos os quadros armazenados para o vetor de saída.
     * @param[out] saida Ponteiro para vetor que receberá os quadros cadastrados.
     * @return true se a listagem foi copiada com sucesso; false se o ponteiro for nulo.
     */
    bool listar(std::vector<Quadro>* saida) const;

    /**
     * @brief Verifica se existe ao menos um quadro associado ao identificador de projeto informado.
     * @param idProjeto Identificador do projeto a ser verificado.
     * @return true se houver quadro vinculado ao projeto; false caso contrário.
     */
    bool existePorProjeto(const Identificador& idProjeto) const;
};

#endif // QUADROCONTAINER_H
