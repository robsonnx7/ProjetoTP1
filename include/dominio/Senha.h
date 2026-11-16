#ifndef SENHA_H
#define SENHA_H

#include <string>
#include <stdexcept>

 /**
 * @file Senha.h
 * @brief Definição da classe Dominio Senha para o sistema.
 */

/**
 * @class Senha
 * @brief Representa e valida uma Senha.
 *
 * Esta classe armazena uma Senha valida e garante
 * que o valor informado atenda às regras de validação
 * estabelecidas pelo domínio.
 */

class Senha {
private:
    std::string valor;                           ///< Armazena uma senha valida.

    void validar(const std::string& valor);      ///< Verifica se a senha possui 5 caracteres alfanuméricos, contendo ao menos uma letra e um dígito.

public:
    Senha() = default;                           ///< Construtor padrao
    explicit Senha(const std::string& valor);    ///< Constroi um objeto Senha com o valor informado
    void setValor(const std::string& valor);     ///< Define uma nova senha apos a validaçao
    std::string getValor() const;                ///< Retorna a senha armazenada
};

#endif // SENHA_H
