#ifndef QUADRO_H
#define QUADRO_H

#include <string>
#include "Identificador.h"
#include "Nome.h"
#include "Limite.h"

/**
 * @file Quadro.h
 * @brief Definição da classe entidade Quadro para o sistema.
 */

/**
 * @class Quadro
 * @brief Representa um quadro dentro de um projeto.
 *
 * Um quadro possui um identificador único, um nome
 * descritivo, um limite de WIP ("Work in Progress"/ trabalho em progresso)
 * e o identificador do projeto ao qual pertence.
 */
class Quadro {
private:
    Identificador identificador; ///< Identificador único do quadro.

    Nome nome;                   ///< Nome descritivo do quadro.

    Limite limite;               ///< Limite de cartões em andamento (WIP) permitido no quadro.

    Identificador idProjeto;     ///< Identificador do projeto ao qual o quadro pertence.

public:
    /**
     * @brief Construtor padrão da classe Quadro.
     * Inicializa os atributos com seus valores padrão.
     */
    Quadro() = default;

    /**
     * @brief Define o identificador do quadro.
     * @param id Objeto do tipo Identificador validado.
     */
    void setIdentificador(const Identificador& id);

    /**
     * @brief Retorna o identificador do quadro.
     * @return Objeto Identificador contido no quadro.
     */
    Identificador getIdentificador() const;

    /**
     * @brief Define o nome do quadro.
     * @param nome Objeto do tipo Nome validado.
     */
    void setNome(const Nome& nome);

    /**
     * @brief Retorna o nome do quadro.
     * @return Objeto Nome contido no quadro.
     */
    Nome getNome() const;

    /**
     * @brief Define o limite do quadro.
     * @param limite Objeto do tipo Limite validado.
     */
    void setLimite(const Limite& limite);

    /**
     * @brief Retorna o limite do quadro.
     * @return Objeto Limite contido no quadro.
     */
    Limite getLimite() const;

    /**
     * @brief Define o identificador do projeto vinculado ao quadro.
     * @param idProjeto Objeto do tipo Identificador validado.
     */
    void setIdProjeto(const Identificador& idProjeto);

    /**
     * @brief Retorna o identificador do projeto vinculado ao quadro.
     * @return Objeto Identificador do projeto.
     */
    Identificador getIdProjeto() const;
};

#endif // QUADRO_H
