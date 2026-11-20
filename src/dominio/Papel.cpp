#include "Papel.h"

/**
 * @brief Constrói um objeto Papel.
 *
 * Inicializa o objeto utilizando o valor informado
 * e executa o processo de validação do papel.
 *
 * @param valor Papel a ser armazenado.
 */

Papel::Papel(const std::string& valor) {
    setValor(valor);
}

/**
 * @brief Define um novo Papel.
 *
 * O valor informado é validado antes de ser
 * armazenado no objeto.
 *
 * @param valor Papel informado.
 */

void Papel::setValor(const std::string& valor) {
    validar(valor);
    this->valor = valor;
}

/**
 * @brief Retorna o papel armazenado.
 *
 * @return Papel válido.
 */

std::string Papel::getValor() const {
    return valor;
}

/**
 * @brief Verifica se o papel informado atende às regras do domínio.
 *
 * Os únicos papeis permitidos são:
 * - GESTOR
 * - DESENVOLVEDOR
 *
 * @param valor Papel a ser validado.
 *
 * @throws std::invalid_argument Caso o papel informado não
 * pertença ao conjunto de valores permitidos.
 */

void Papel::validar(const std::string& valor) {
    /// Verifica se o valor corresponde a um dos papéis permitidos pelo domínio.
    if (valor != "GESTOR" && valor != "DESENVOLVEDOR") {
        throw std::invalid_argument("Papel invalido: deve ser 'GESTOR' ou 'DESENVOLVEDOR'.");
    }
}
