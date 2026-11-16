#ifndef LIMITE_H
#define LIMITE_H


#include <stdexcept>

/**
 * @file Limite.h
 * @brief Definição da classe Dominio Limite para o sistema.
 */

/**
 * @class Limite
 * @brief Representa e valida um limite.
 *
 * Esta classe armazena um Limite valido e garante
 * que o valor informado atenda às regras de validação
 * estabelecidas pelo domínio.
 */

class Limite{
private:
    int valor;                               ///< armazena um Limite valido.

    void validar(int valor);                 ///< Verifica se o Limite esta dentro do intervalo permitido de 1 à 25.


public:
    Limite() = default;                      ///< Construtor padrão.

    explicit Limite(int valor);              ///< Constrói um objeto Limite a partir de um valor informado.


    void setValor(int valor);                ///< Define um novo Limite após validação.

    int getValor() const;                    ///< Retorna o Limite armazenado.
};
#endif //LIMITE_H
