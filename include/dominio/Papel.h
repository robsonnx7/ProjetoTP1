#ifndef PAPEL_H
#define PAPEL_H

#include <string>
#include <stdexcept>

 /**
 * @file Papel.h
 * @brief Definição da classe Dominio Papel para o sistema.
 */

/**
 * @class Papel
 * @brief Representa e valida um papel.
 *
 * Esta classe armazena um papel valido e garante
 * que o valor informado atenda às regras de validação
 * estabelecidas pelo domínio.
 */

class Papel {
private:
    std::string valor;                         ///< armazena um Papel valido.

    void validar(const std::string& valor);    ///< verifica se a entrada corresponde a um dos valores permitidos "GESTOR" ou "DESENVOLVEDOR".


public:
    Papel() = default;                         ///< construtor padrao.

    explicit Papel(const std::string& valor);  ///< constroi um objeto papel a partir do valor informado.

    void setValor(const std::string& valor);   ///< Define um novo papel após validação.

    std::string getValor() const;              ///< retorna o papel armazenado.
};

#endif // PAPEL_H
