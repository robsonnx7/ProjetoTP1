#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED

///Inclusao dos arquivos utilizados pela entidade
#include "Email.h"
#include "Papel.h"
#include "Senha.h"
#include "Nome.h"

/**
 * @brief Entidade que representa uma pessoa no sistema.
 *
 * A entidade Pessoa é composta pelos domínios:
 * - Email
 * - Nome
 * - Senha
 * - Papel
 */
 class Pessoa{
 private:
     ///endereço de email
     Email email;

     ///nome da pessoa
     Nome nome;

     ///senha da pessoa
     Senha senha;

     ///papel da pessoa
     Papel papel;

 public:
     /**
      @brief Atribui um email à pessoa.
      @param email Domínio Email validado.
     */
     void setEmail(const Email&email);

     /**
     * @brief Retorna o email da pessoa.
     * @return Email armazenado.
     */
     Email getEmail()const;
     /**
     * @brief Atribui um nome à pessoa.
     * @param nome Domínio Nome validado.
     */
    void setNome(const Nome &nome);

    /**
     * @brief Retorna o nome da pessoa.
     * @return Nome armazenado.
     */
    Nome getNome() const;

    /**
     * @brief Atribui uma senha à pessoa.
     * @param senha Domínio Senha validado.
     */
    void setSenha(const Senha &senha);

    /**
     * @brief Retorna a senha da pessoa.
     * @return Senha armazenada.
     */
    Senha getSenha() const;

    /**
     * @brief Atribui um papel à pessoa.
     * @param papel Domínio Papel validado.
     */
    void setPapel(const Papel &papel);

    /**
     * @brief Retorna o papel da pessoa.
     * @return Papel armazenado.
     */
    Papel getPapel() const;
};

#endif // PESSOA_H_INCLUDED
