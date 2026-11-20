#ifndef PRIORIDADE_H
#define PRIORIDADE_H

#include <string>
#include <stdexcept>

 /**
 * @file Prioridade.h
 * @brief Definição da classe Dominio Prioridade para o sistema.
 */

/**
 * @class Prioridade
 * @brief Representa e valida uma prioridade.
 *
 * Esta classe armazena uma prioridade valida e garante
 * que o valor informado atenda às regras de validação
 * estabelecidas pelo domínio.
 */

class Prioridade {
private:
    std::string valor;                                ///< Armazena uma prioridade valida.

    void validar(const std::string& valor);           ///< verifica se a entrada corresponde a um dos valores permitidos: "BAIXA", "MEDIA" ou "ALTA".

public:
    Prioridade() = default;                           ///< Construtor padrao

    explicit Prioridade(const std::string& valor);    ///< Constroi um objeto Prioridade a partir de um valor informado.


    void setValor(const std::string& valor);          ///< Define a nova Prioridade apos a validaçao.


    std::string getValor() const;                     ///< Retorna a prioridade armazenada.
};

#endif // PRIORIDADE_H
