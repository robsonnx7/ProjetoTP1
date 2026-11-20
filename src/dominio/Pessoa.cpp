#include "Pessoa.h"

/**
 * @file Pessoa.cpp
 * @brief Implementação dos métodos da entidade Pessoa.
 */

/**
 * @brief Associa um endereço de e-mail à pessoa.
 *
 * O e-mail é utilizado para identificação
 * e comunicação com a pessoa dentro do sistema.
 *
 * @param email Endereço de e-mail validado.
 */
void Pessoa::setEmail(const Email& email){
    this->email = email;
}

/**
 * @brief Obtém o endereço de e-mail da pessoa.
 *
 * @return E-mail associado à pessoa.
 */
Email Pessoa::getEmail() const{
    return email;
}

/**
 * @brief Define o nome da pessoa.
 *
 * O nome representa a identificação textual
 * utilizada para exibição da pessoa no sistema.
 *
 * @param nome Nome validado.
 */
void Pessoa::setNome(const Nome& nome){
    this->nome = nome;
}

/**
 * @brief Obtém o nome da pessoa.
 *
 * @return Nome associado à pessoa.
 */
Nome Pessoa::getNome() const{
    return nome;
}

/**
 * @brief Define a senha da pessoa.
 *
 * A senha é utilizada durante o processo
 * de autenticação e acesso ao sistema.
 *
 * @param senha Senha validada.
 */
void Pessoa::setSenha(const Senha& senha){
    this->senha = senha;
}

/**
 * @brief Obtém a senha da pessoa.
 *
 * @return Senha associada à pessoa.
 */
Senha Pessoa::getSenha() const{
    return senha;
}

/**
 * @brief Define o papel desempenhado pela pessoa.
 *
 * O papel determina o perfil de atuação
 * da pessoa dentro do sistema.
 *
 * @param papel Papel validado.
 */
void Pessoa::setPapel(const Papel& papel){
    this->papel = papel;
}

/**
 * @brief Obtém o papel da pessoa.
 *
 * @return Papel associado à pessoa.
 */
Papel Pessoa::getPapel() const{
    return papel;
}
