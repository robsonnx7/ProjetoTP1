#ifndef PESSOACONTAINER_H
#define PESSOACONTAINER_H

#include <vector>
#include "Pessoa.h"
#include "Email.h"

/**
 * @file PessoaContainer.h
 * @brief Declaração do container em memória para armazenamento de objetos Pessoa.
 */

/**
 * @class PessoaContainer
 * @brief Gerencia o armazenamento e as operações básicas em memória de entidades Pessoa.
 *
 * Utiliza um vetor interno indexado pelo e-mail da pessoa (chave primária) para
 * inserção, consulta, atualização, remoção e listagem.
 */
class PessoaContainer {
private:
    std::vector<Pessoa> pessoas; ///< Coleção em memória das pessoas cadastradas.

    /**
     * @brief Localiza o índice de uma pessoa no vetor interno a partir do e-mail.
     * @param email E-mail utilizado como chave de busca.
     * @return Índice da pessoa se encontrada, ou -1 caso contrário.
     */
    int buscarIndicePorEmail(const Email& email) const;

public:
    /**
     * @brief Construtor padrão de PessoaContainer.
     */
    PessoaContainer() = default;

    /**
     * @brief Insere uma nova pessoa caso não exista outra com o mesmo e-mail.
     * @param pessoa Objeto Pessoa a ser inserido.
     * @return true se a inserção foi realizada; false se o e-mail já estiver cadastrado.
     */
    bool inserir(const Pessoa& pessoa);

    /**
     * @brief Busca uma pessoa pelo e-mail informado e preenche os dados encontrados.
     * @param[in,out] pessoa Ponteiro para Pessoa contendo o e-mail de busca; recebe os dados completos se encontrado.
     * @return true se a pessoa foi encontrada; false se o ponteiro for nulo ou o e-mail não existir.
     */
    bool buscar(Pessoa* pessoa) const;

    /**
     * @brief Atualiza os dados de uma pessoa já existente identificada pelo e-mail.
     * @param pessoa Objeto Pessoa com os dados atualizados.
     * @return true se a atualização foi concluída; false se o e-mail não for encontrado.
     */
    bool atualizar(const Pessoa& pessoa);

    /**
     * @brief Remove uma pessoa do container a partir do e-mail.
     * @param email E-mail da pessoa a ser removida.
     * @return true se a remoção foi realizada; false se o e-mail não for encontrado.
     */
    bool remover(const Email& email);

    /**
     * @brief Copia todas as pessoas armazenadas para o vetor de saída.
     * @param[out] pessoasSaida Ponteiro para vetor que receberá as pessoas cadastradas.
     * @return true se a listagem foi copiada com sucesso; false se o ponteiro for nulo.
     */
    bool listar(std::vector<Pessoa>* pessoasSaida) const;
};

#endif // PESSOACONTAINER_H
