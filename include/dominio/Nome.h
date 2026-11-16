#ifndef NOME_H
#define NOME_H

#include <string>
#include <stdexcept>

 /**
 * @file Nome.h
 * @brief Definição da classe Dominio Nome para o sistema.
 */

/**
 * @class Nome
 * @brief Representa e valida um nome.
 *
 * Esta classe armazena um Nome valido e garante
 * que o valor informado possua no máximo 15 caracteres,
 * seja composto apenas por letras e espaços e atenda
 * às regras de validação estabelecidas pelo domínio.
 */

class Nome{
private:
    std::string valor;                                ///< armazena um Nome valido.

    void validar(const std::string& valor);           ///< Verifica se o nome atende às regras do domínio.

public:
    Nome() = default;                                 ///< Construtor padrão.

    explicit Nome(const std::string& valor);          ///< Constrói um objeto Nome a partir de um valor informado.


    void setValor(const std::string& valor);          ///< Define um novo Limite após validação.

    std::string getValor() const;                     ///< Retorna o Nome armazenado.
};

#endif //NOME_H
