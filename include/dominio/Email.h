#ifndef EMAIL_H
#define EMAIL_H

#include <string>
#include <stdexcept>

/**
 * @file Email.h
 * @brief Definição da classe Dominio Email para o sistema.
 */

/**
 * @class Email
 * @brief Define e valida um endereço de e-mail.
 *
 * Esta classe armazena um endereço de e-mail e garante
 * que o valor informado atenda às regras de validação
 * estabelecidas pelo domínio.
 */

class Email {
private:
    std::string valor;                          ///< armazena o endereço de email valido.
    void validar(const std::string& valor);     ///< Verifica se o endereço de e-mail atende às regras do domínio.

public:
    Email() = default;                          ///< Construtor padrão.
    explicit Email(const std::string& valor);   ///< Constrói um objeto Email a partir de um valor informado.

    void setValor(const std::string& valor);    ///< Define um novo endereço de e-mail após validação.
    std::string getValor() const;               ///< Retorna o endereço de e-mail armazenado.
};

#endif // EMAIL_H
