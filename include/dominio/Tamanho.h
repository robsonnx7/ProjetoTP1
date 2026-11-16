#ifndef TAMANHO_H
#define TAMANHO_H

#include <string>
#include <stdexcept>

 /**
 * @file Tamanho.h
 * @brief Definição da classe Dominio Tamanho para o sistema.
 */

/**
 * @class Tamanho
 * @brief Representa e valida um tamanho.
 *
 * Esta classe armazena um Tamanho valido e garante
 * que o valor informado atenda às regras de validação
 * estabelecidas pelo domínio.
 */

class Tamanho {
private:

    std::string valor;                                 ///< Armazena um tamanho

    void validar(const std::string& valor);            ///< Verifica se o valor corresponde a um dos tamanhos permitidos: "GRANDE", "MEDIO" ou "PEQUENO"..

public:

    Tamanho() = default;                               ///< Construtor padrao.


    explicit Tamanho(const std::string& valor);        ///< Constrói um objeto Tamanho a partir de um valor informado.


    void setValor(const std::string& valor);           ///< Define um novo tamanho após validação.


    std::string getValor() const;                      ///< Retorna o tamanho armazenado.
};

#endif // TAMANHO_H
