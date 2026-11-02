#ifndef PROJETO_H
#define PROJETO_H

#include <string>
#include "Identificador.h"
#include "Nome.h"
#include "Texto.h"
#include "Timestamp.h"

/**
 * @file Projeto.h
 * @brief Definição da classe entidade "Projeto" para o sistema.
 */

/**
 * @class Projeto
 * @brief Representa um projeto no sistema de gestão de projetos.
 *
 * Um projeto possui um identificador único (chave primária), um nome,
 * uma descrição detalhada e datas de início e término.
 */
class Projeto {
private:
    Identificador identificador; ///< Identificador único.
    Nome nome;                   ///< Nome descritivo do projeto.
    Texto descricao;             ///< Descrição detalhada dos objetivos do projeto.
    Timestamp inicio;            ///< Data e horário de início do projeto.
    Timestamp termino;           ///< Data e horário de término do projeto.

public:
    /**
     * @brief Construtor padrão da classe Projeto.
     * Inicializa os atributos com seus valores padrão.
     */
    Projeto() = default;

    /**
     * @brief Define o identificador do projeto.
     * @argument id Objeto do tipo Identificador validado.
     */
    void setIdentificador(const Identificador& id);

    /**
     * @brief Retorna o identificador do projeto.
     * @return Objeto Identificador contido no projeto.
     */
    Identificador getIdentificador() const;

    /**
     * @brief Define o nome do projeto.
     * @argument nome Objeto do tipo Nome validado.
     */
    void setNome(const Nome& nome);

    /**
     * @brief Retorna o nome do projeto.
     * @return Objeto Nome contido no projeto.
     */
    Nome getNome() const;

    /**
     * @brief Define a descrição do projeto.
     * @argument descricao Objeto do tipo Texto validado.
     */
    void setDescricao(const Texto& descricao);

    /**
     * @brief Retorna a descrição do projeto.
     * @return Objeto Texto contendo a descrição.
     */
    Texto getDescricao() const;

    /**
     * @brief Define a data de início do projeto.
     * @argument inicio Objeto do tipo Timestamp validado.
     */
    void setInicio(const Timestamp& inicio);

    /**
     * @brief Retorna a data de início do projeto.
     * @return Objeto Timestamp de início.
     */
    Timestamp getInicio() const;

    /**
     * @brief Define a data de término do projeto.
     * @argument termino Objeto do tipo Timestamp validado.
     */
    void setTermino(const Timestamp& termino);

    /**
     * @brief Retorna a data de término do projeto.
     * @return Objeto Timestamp de término.
     */
    Timestamp getTermino() const;
};

#endif // PROJETO_H
