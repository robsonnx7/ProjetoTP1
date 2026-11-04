#ifndef CARTAO_ATIVIDADE_H
#define CARTAO_ATIVIDADE_H

#include <string>
#include "Identificador.h"
#include "Nome.h"
#include "Texto.h"
#include "Prioridade.h"
#include "Estado.h"
#include "Tamanho.h"
#include "Timestamp.h"

/**
 * @file CartaoAtividade.h
 * @brief Definição da classe entidade CartaoAtividade para o sistema.
 */

/**
 * @class CartaoAtividade
 * @brief Representa um cartão de atividade dentro de um quadro.
 *
 * Um cartão armazena informações detalhadas de uma tarefa, incluindo identificador único,
 * nome, descrição, prioridade, estado atual, tamanho, além dos timestamps de entrada, início e término.
 */
class CartaoAtividade {
private:
    Identificador identificador; ///< Identificador único do cartão "citar 2".
    Nome nome;                   ///< Nome descritivo da atividade "citar 2".
    Texto descricao;             ///< Descrição detalhada da atividade[cite: 2, 3].
    Prioridade prioridade;       ///< Nível de prioridade da atividade (alta, media, baixa)[cite: 2, 3].
    Estado estado;               ///< Estado atual do cartão no Kanban (a fazer, fazendo, feito)[cite: 2, 3].
    Tamanho tamanho;             ///< Tamanho estimado da atividade (grande, medio, pequeno)[cite: 2, 3].
    Timestamp entrada;           ///< Momento em que o cartão entrou no quadro[cite: 2, 3].
    Timestamp inicio;            ///< Momento em que a atividade foi iniciada (movida para "fazendo")[cite: 2, 3].
    Timestamp termino;           ///< Momento em que a atividade foi concluída (movida para "feito")[cite: 2, 3].

public:
    /**
     * @brief Construtor padrão da classe CartaoAtividade.
     * Inicializa os atributos com seus valores padrão.
     */
    CartaoAtividade() = default;

    /**
     * @brief Define o identificador do cartão.
     * @param id Objeto do tipo Identificador validado.
     */
    void setIdentificador(const Identificador& id);

    /**
     * @brief Retorna o identificador do cartão.
     * @return Objeto Identificador contido no cartão.
     */
    Identificador getIdentificador() const;

    /**
     * @brief Define o nome do cartão.
     * @param nome Objeto do tipo Nome validado.
     */
    void setNome(const Nome& nome);

    /**
     * @brief Retorna o nome do cartão.
     * @return Objeto Nome contido no cartão.
     */
    Nome getNome() const;

    /**
     * @brief Define a descrição do cartão.
     * @param descricao Objeto do tipo Texto validado.
     */
    void setDescricao(const Texto& descricao);

    /**
     * @brief Retorna a descrição do cartão.
     * @return Objeto Texto contendo a descrição.
     */
    Texto getDescricao() const;

    /**
     * @brief Define a prioridade do cartão.
     * @param prioridade Objeto do tipo Prioridade validado.
     */
    void setPrioridade(const Prioridade& prioridade);

    /**
     * @brief Retorna a prioridade do cartão.
     * @return Objeto Prioridade contido no cartão.
     */
    Prioridade getPrioridade() const;

    /**
     * @brief Define o estado atual do cartão.
     * @param estado Objeto do tipo Estado validado.
     */
    void setEstado(const Estado& estado);

    /**
     * @brief Retorna o estado atual do cartão.
     * @return Objeto Estado contido no cartão.
     */
    Estado getEstado() const;

    /**
     * @brief Define o tamanho estimado do cartão.
     * @param tamanho Objeto do tipo Tamanho validado.
     */
    void setTamanho(const Tamanho& tamanho);

    /**
     * @brief Retorna o tamanho estimado do cartão.
     * @return Objeto Tamanho contido no cartão.
     */
    Tamanho getTamanho() const;

    /**
     * @brief Define o timestamp de entrada do cartão.
     * @param entrada Objeto do tipo Timestamp validado.
     */
    void setEntrada(const Timestamp& entrada);

    /**
     * @brief Retorna o timestamp de entrada do cartão.
     * @return Objeto Timestamp de entrada.
     */
    Timestamp getEntrada() const;

    /**
     * @brief Define o timestamp de início da atividade.
     * @param inicio Objeto do tipo Timestamp validado.
     */
    void setInicio(const Timestamp& inicio);

    /**
     * @brief Retorna o timestamp de início da atividade.
     * @return Objeto Timestamp de início.
     */
    Timestamp getInicio() const;

    /**
     * @brief Define o timestamp de término da atividade.
     * @param termino Objeto do tipo Timestamp validado.
     */
    void setTermino(const Timestamp& termino);

    /**
     * @brief Retorna o timestamp de término da atividade.
     * @return Objeto Timestamp de término.
     */
    Timestamp getTermino() const;
};

#endif // CARTAO_ATIVIDADE_H
