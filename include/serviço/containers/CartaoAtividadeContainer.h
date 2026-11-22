#ifndef CARTAOATIVIDADECONTAINER_H
#define CARTAOATIVIDADECONTAINER_H

#include <vector>
#include "CartaoAtividade.h"
#include "Identificador.h"
#include "Email.h"

/**
 * @file CartaoAtividadeContainer.h
 * @brief Definição do contêiner responsável pelo armazenamento de cartões de atividade.
 */

/**
 * @class CartaoAtividadeContainer
 * @brief Gerencia o armazenamento em memória dos cartões de atividade.
 *
 * Esta classe é responsável por manter e manipular
 * a coleção de cartões de atividade cadastrados
 * no sistema.
 *
 * As operações disponibilizadas permitem inserir,
 * consultar, atualizar, remover e listar cartões.
 */
class CartaoAtividadeContainer {
private:

    std::vector<CartaoAtividade> cartoes;
    ///< Coleção utilizada para armazenar os cartões de atividade.

    /**
     * @brief Localiza a posição de um cartão pelo identificador.
     *
     * @param id Identificador do cartão.
     *
     * @return Índice do cartão na coleção.
     * @return Valor negativo caso o cartão não seja encontrado.
     */
    int buscarIndicePorId(const Identificador& id) const;

public:

    /**
     * @brief Construtor padrão.
     */
    CartaoAtividadeContainer() = default;

    /**
     * @brief Insere um novo cartão no contêiner.
     *
     * @param cartao Cartão a ser armazenado.
     *
     * @return true caso a inserção seja realizada.
     * @return false caso o cartão já exista.
     */
    bool inserir(const CartaoAtividade& cartao);

    /**
     * @brief Consulta um cartão armazenado.
     *
     * @param cartao Estrutura utilizada para receber os dados encontrados.
     *
     * @return true caso o cartão seja localizado.
     * @return false caso o cartão não seja encontrado.
     */
    bool buscar(CartaoAtividade* cartao) const;

    /**
     * @brief Atualiza os dados de um cartão armazenado.
     *
     * @param cartao Cartão contendo os novos dados.
     *
     * @return true caso a atualização seja realizada.
     * @return false caso o cartão não seja encontrado.
     */
    bool atualizar(const CartaoAtividade& cartao);

    /**
     * @brief Remove um cartão do contêiner.
     *
     * @param id Identificador do cartão.
     *
     * @return true caso a remoção seja realizada.
     * @return false caso o cartão não seja encontrado.
     */
    bool remover(const Identificador& id);

    /**
     * @brief Recupera todos os cartões armazenados.
     *
     * @param saida Estrutura utilizada para receber a listagem.
     *
     * @return true caso a operação seja realizada.
     * @return false caso ocorra alguma falha.
     */
    bool listar(std::vector<CartaoAtividade>* saida) const;

    /**
     * @brief Verifica se existem cartões vinculados a um quadro.
     *
     * @param idQuadro Identificador do quadro.
     *
     * @return true caso exista ao menos um cartão vinculado.
     * @return false caso não existam cartões vinculados.
     */
    bool existePorQuadro(const Identificador& idQuadro) const;

    /**
     * @brief Verifica se existem cartões atribuídos a um desenvolvedor.
     *
     * @param emailDesenvolvedor E-mail do desenvolvedor.
     *
     * @return true caso exista ao menos um cartão associado.
     * @return false caso não existam cartões associados.
     */
    bool existePorDesenvolvedor(const Email& emailDesenvolvedor) const;
};

#endif // CARTAOATIVIDADECONTAINER_H
