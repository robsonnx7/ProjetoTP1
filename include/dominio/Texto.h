#ifndef TEXTO_H
#define TEXTO_H

#include <string>
#include <stdexcept>

/**
 * @file Texto.h
 * @brief Definição da classe domínio Texto para o sistema.
 */

/**
 * @class Texto
 * @brief Representa e valida um texto.
 *
 * Esta classe armazena um texto válido e garante
 * que o valor informado atenda às regras de validação
 * estabelecidas pelo domínio.
 */
class Texto {
private:
    std::string valor;                             ///< Armazena um texto válido.

    void validar(const std::string& valor);        ///< Verifica se o texto possui até 30 caracteres e atende às regras de formatação do domínio.

public:
    Texto() = default;                             ///< Construtor padrão.

    explicit Texto(const std::string& valor);      ///< Constrói um objeto Texto a partir de um valor informado.

    void setValor(const std::string& valor);       ///< Define um novo texto após validação.

    std::string getValor() const;                  ///< Retorna o texto armazenado.
};

#endif // TEXTO_H
