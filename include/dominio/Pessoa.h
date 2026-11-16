#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED

/// Inclusão dos domínios utilizados pela entidade.
#include "Email.h"
#include "Papel.h"
#include "Senha.h"
#include "Nome.h"

/**
 * @file Pessoa.h
 * @brief Definição da entidade Pessoa.
 */

/**
 * @class Pessoa
 * @brief Representa uma pessoa cadastrada no sistema.
 *
 * A entidade Pessoa é composta pelos domínios:
 * - Email
 * - Nome
 * - Senha
 * - Papel
 *
 * Cada atributo é armazenado por meio de um domínio,
 * responsável por garantir a validade dos dados
 * associados à pessoa.
 */
class Pessoa {
private:

    Email email;
    ///< Endereço de e-mail da pessoa.

    Nome nome;
    ///< Nome da pessoa.

    Senha senha;
    ///< Senha utilizada para autenticação da pessoa.

    Papel papel;
    ///< Papel desempenhado pela pessoa no sistema.

public:

    /**
     * @brief Define o e-mail da pessoa.
     * @param email Domínio Email validado.
     */
    void setEmail(const Email& email);

    /**
     * @brief Retorna o e-mail da pessoa.
     * @return E-mail armazenado.
     */
    Email getEmail() const;

    /**
     * @brief Define o nome da pessoa.
     * @param nome Domínio Nome validado.
     */
    void setNome(const Nome& nome);

    /**
     * @brief Retorna o nome da pessoa.
     * @return Nome armazenado.
     */
    Nome getNome() const;

    /**
     * @brief Define a senha da pessoa.
     * @param senha Domínio Senha validado.
     */
    void setSenha(const Senha& senha);

    /**
     * @brief Retorna a senha da pessoa.
     * @return Senha armazenada.
     */
    Senha getSenha() const;

    /**
     * @brief Define o papel da pessoa.
     * @param papel Domínio Papel validado.
     */
    void setPapel(const Papel& papel);

    /**
     * @brief Retorna o papel da pessoa.
     * @return Papel armazenado.
     */
    Papel getPapel() const;
};

#endif // PESSOA_H_INCLUDED
