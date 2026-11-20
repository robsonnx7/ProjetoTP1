#ifndef TIMESTAMP_H
#define TIMESTAMP_H

#include <string>
#include <stdexcept>
#include <vector>

/**
 * @file Timestamp.h
 * @brief Definição da classe domínio Timestamp para o sistema.
 */

/**
 * @class Timestamp
 * @brief Representa e valida um timestamp.
 *
 * Esta classe armazena um timestamp válido e garante
 * que o valor informado atenda às regras de validação
 * estabelecidas pelo domínio.
 */
class Timestamp {
private:
    std::string valor;
    ///< Armazena um timestamp válido.

    void validar(const std::string& valor);
    ///< Verifica se o timestamp informado atende às regras do domínio.

    bool ehBissexto(int ano) const;
    ///< Verifica se o ano informado é bissexto.

    int obterDiasNoMes(int mes, int ano) const;
    ///< Retorna a quantidade de dias de um mês considerando anos bissextos.

public:
    Timestamp() = default;
    ///< Construtor padrão.

    explicit Timestamp(const std::string& valor);
    ///< Constrói um objeto Timestamp a partir de um valor informado.

    void setValor(const std::string& valor);
    ///< Define um novo timestamp após validação.

    std::string getValor() const;
    ///< Retorna o timestamp armazenado.
};

#endif // TIMESTAMP_H
