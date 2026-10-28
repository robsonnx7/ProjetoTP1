#include "../../include/entidade/Pessoa.h"

/**
 * @brief Define o email da pessoa.
 * @param email Novo email.
 */
void Pessoa::setEmail(const Email &email){
    this->email = email;
}

/**
 * @brief Retorna o email da pessoa.
 * @return Email armazenado.
 */
Email Pessoa::getEmail() const{
    return email;
}

/**
 * @brief Define o nome da pessoa.
 * @param nome Novo nome.
 */
void Pessoa::setNome(const Nome &nome){
    this->nome = nome;
}

/**
 * @brief Retorna o nome da pessoa.
 * @return Nome armazenado.
 */
Nome Pessoa::getNome() const{
    return nome;
}

/**
 * @brief Define a senha da pessoa.
 * @param senha Nova senha.
 */
void Pessoa::setSenha(const Senha &senha){
    this->senha = senha;
}

/**
 * @brief Retorna a senha da pessoa.
 * @return Senha armazenada.
 */
Senha Pessoa::getSenha() const{
    return senha;
}

/**
 * @brief Define o papel da pessoa.
 * @param papel Novo papel.
 */
void Pessoa::setPapel(const Papel &papel){
    this->papel = papel;
}

/**
 * @brief Retorna o papel da pessoa.
 * @return Papel armazenado.
 */
Papel Pessoa::getPapel() const{
    return papel;
}
