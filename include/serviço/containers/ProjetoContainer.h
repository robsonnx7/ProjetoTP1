#ifndef PROJETOCONTAINER_H
#define PROJETOCONTAINER_H

#include <vector>
#include "Projeto.h"
#include "Identificador.h"
#include "Email.h"

/**
 * @file ProjetoContainer.h
 * @brief Declaração do container em memória para armazenamento de objetos Projeto.
 */

/**
 * @class ProjetoContainer
 * @brief Gerencia o armazenamento e as operações básicas em memória de entidades Projeto.
 *
 * Mantém uma coleção em memória indexada pelo Identificador do projeto e oferece
 * consultas auxiliares, como a verificação de vínculos por e-mail do gestor.
 */
class ProjetoContainer {
private:
    std::vector<Projeto> projetos; ///< Coleção em memória dos projetos cadastrados.

    /**
     * @brief Localiza o índice de um projeto no vetor interno a partir do identificador.
     * @param id Identificador utilizado como chave de busca.
     * @return Índice do projeto se encontrado, ou -1 caso contrário.
     */
    int buscarIndicePorId(const Identificador& id) const;

public:
    /**
     * @brief Construtor padrão de ProjetoContainer.
     */
    ProjetoContainer() = default;

    /**
     * @brief Insere um novo projeto caso não exista outro com o mesmo identificador.
     * @param projeto Objeto Projeto a ser inserido.
     * @return true se a inserção foi realizada; false se o identificador já estiver cadastrado.
     */
    bool inserir(const Projeto& projeto);

    /**
     * @brief Busca um projeto pelo identificador informado e preenche os dados encontrados.
     * @param[in,out] projeto Ponteiro para Projeto contendo o identificador de busca; recebe os dados completos se encontrado.
     * @return true se o projeto foi encontrado; false se o ponteiro for nulo ou o identificador não existir.
     */
    bool buscar(Projeto* projeto) const;

    /**
     * @brief Atualiza os dados de um projeto já existente identificado pelo identificador.
     * @param projeto Objeto Projeto com os dados atualizados.
     * @return true se a atualização foi concluída; false se o identificador não for encontrado.
     */
    bool atualizar(const Projeto& projeto);

    /**
     * @brief Remove um projeto do container a partir do identificador.
     * @param id Identificador do projeto a ser removido.
     * @return true se a remoção foi realizada; false se o identificador não for encontrado.
     */
    bool remover(const Identificador& id);

    /**
     * @brief Copia todos os projetos armazenados para o vetor de saída.
     * @param[out] saida Ponteiro para vetor que receberá os projetos cadastrados.
     * @return true se a listagem foi copiada com sucesso; false se o ponteiro for nulo.
     */
    bool listar(std::vector<Projeto>* saida) const;

    /**
     * @brief Verifica se existe ao menos um projeto associado ao e-mail do gestor informado.
     * @param emailGestor E-mail da pessoa gestora a ser verificado.
     * @return true se houver projeto vinculado ao gestor; false caso contrário.
     */
    bool existePorGestor(const Email& emailGestor) const;
};

#endif // PROJETOCONTAINER_H
