#ifndef ESTADO_H
#define ESTADO_H

#include <string>
#include <stdexcept>

/**
 * @file Estado.h
 * @brief Definição da classe Dominio Estado para o sistema.
 */

/**
 * @class Estado
 * @brief Representa e valida um estado de atividade.
 *
 * Esta classe armazena um estado valido e garante
 * que o valor informado atenda às regras de validação
 * estabelecidas pelo domínio.
 */

class Estado{
private:
    std::string valor;                               ///< armazena um Estado valido.

    void validar(const std::string& valor);          ///< Verifica se o estado informado é A FAZER, FAZENDO ou FEITO.


public:
    Estado() = default;                              ///< Construtor padrão.

    explicit Estado(const std::string& valor);       ///< Constrói um objeto Estado a partir de um valor informado.

    void setValor(const std::string& valor);         ///< Define um novo Estado após validação.

    std::string getValor() const;                    ///< Retorna o Estado armazenado.
};

#endif //ESTADO_H
