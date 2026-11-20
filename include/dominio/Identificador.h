#ifndef IDENTIFICADOR_H
#define IDENTIFICADOR_H

#include <string>
#include <stdexcept>

/**
 * @file Identificador.h
 * @brief Definição da classe Dominio Identificador para o sistema.
 */

/**
 * @class Identificador
 * @brief Representa e valida um indentificador.
 *
 * Esta classe armazena um identificador valido e garante
 * que o valor informado atenda às regras de validação
 * estabelecidas pelo domínio.
 */

class Identificador{
private:
    std::string valor;                                       ///< armazena um Identificador valido.

    void validar(const std::string& valor);                  ///< Verifica se o Identificador possui tres letras seguidas de 3 digitos.

public:
    Identificador() = default;                               ///< Construtor padrão.

    explicit Identificador(const std::string& valor);        ///< Constrói um objeto Identificador a partir de um valor informado.


    void setValor(const std::string& valor);                 ///< Define um novo Identificador após validação.

    std::string getValor() const;                            ///< Retorna o Identificador armazenado.
};

#endif //IDENTIFICADOR_H
