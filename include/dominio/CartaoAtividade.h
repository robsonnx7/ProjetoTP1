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
#include "Email.h"

/**
 * @file CartaoAtividade.h
 * @brief Definição da classe entidade CartaoAtividade para o sistema.
 */

/**
 * @class CartaoAtividade
 * @brief Representa um cartão de atividade dentro de um quadro.
 *
 * Um cartão armazena informações detalhadas de uma tarefa, incluindo identificador único,
 * nome, descrição, prioridade, estado atual, tamanho, além dos timestamps de entrada, início e término,
 * do identificador do quadro ao qual pertence e do e-mail do desenvolvedor responsável.
 */
class CartaoAtividade {
private:
    Identificador identificador; ///< Identificador único do cartão.
    Nome nome;                   ///< Nome descritivo da atividade.
    Texto descricao;             ///< Descrição detalhada da atividade.
    Prioridade prioridade;       ///< Nível de prioridade da atividade (alta, media, baixa).
    Estado estado;               ///< Estado atual do cartão no Kanban (a fazer, fazendo, feito).
    Tamanho tamanho;             ///< Tamanho estimado da atividade (grande, medio, pequeno).
    Timestamp entrada;           ///< Momento em que o cartão entrou no quadro.
    Timestamp inicio;            ///< Momento em que a atividade foi iniciada (movida para "fazendo").
    Timestamp termino;           ///< Momento em que a atividade foi concluída (movida para "feito").
    Identificador idQuadro;      ///< Identificador do quadro ao qual o cartão pertence.
    Email emailDesenvolvedor;    ///< E-mail da pessoa que atua como desenvolvedor do cartão.

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
     * @brief Define o nome da atividade.
     * @param nome Objeto do tipo Nome validado.
     */
    void setNome(const Nome& nome);

    /**
     * @brief Retorna o nome da atividade.
     * @return Objeto Nome contido no cartão.
     */
    Nome getNome() const;

    /**
     * @brief Define a descrição da atividade.
     * @param descricao Objeto do tipo Texto validado.
     */
    void setDescricao(const Texto& descricao);

    /**
     * @brief Retorna a descrição da atividade.
     * @return Objeto Texto contendo a descrição.
     */
    Texto getDescricao() const;

    /**
     * @brief Define a prioridade da atividade.
     * @param prioridade Objeto do tipo Prioridade validado.
     */
    void setPrioridade(const Prioridade& prioridade);

    /**
     * @brief Retorna a prioridade da atividade.
     * @return Objeto Prioridade contido no cartão.
     */
    Prioridade getPrioridade() const;

    /**
     * @brief Define o estado atual da atividade.
     * @param estado Objeto do tipo Estado validado.
     */
    void setEstado(const Estado& estado);

    /**
     * @brief Retorna o estado atual da atividade.
     * @return Objeto Estado contido no cartão.
     */
    Estado getEstado() const;

    /**
     * @brief Define o tamanho estimado da atividade.
     * @param tamanho Objeto do tipo Tamanho validado.
     */
    void setTamanho(const Tamanho& tamanho);

    /**
     * @brief Retorna o tamanho estimado da atividade.
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

    /**
     * @brief Define o identificador do quadro vinculado ao cartão.
     * @param idQuadro Objeto do tipo Identificador validado.
     */
    void setIdQuadro(const Identificador& idQuadro);

    /**
     * @brief Retorna o identificador do quadro vinculado ao cartão.
     * @return Objeto Identificador do quadro.
     */
    Identificador getIdQuadro() const;

    /**
     * @brief Define o e-mail do desenvolvedor responsável pelo cartão.
     * @param emailDesenvolvedor Objeto do tipo Email validado.
     */
    void setEmailDesenvolvedor(const Email& emailDesenvolvedor);

    /**
     * @brief Retorna o e-mail do desenvolvedor responsável pelo cartão.
     * @return Objeto Email do desenvolvedor.
     */
    Email getEmailDesenvolvedor() const;
};

#endif // CARTAO_ATIVIDADE_H
