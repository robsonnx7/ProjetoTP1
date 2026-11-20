#include "Tamanho.h"

/**
 * @brief Constrói um objeto Tamanho.
 *
 * Inicializa o objeto utilizando o valor informado
 * e executa o processo de validação do tamanho.
 *
 * @param valor Tamanho a ser armazenado.
 */

Tamanho::Tamanho(const std::string& valor) {
    setValor(valor);
}

/**
 * @brief Define um novo tamanho.
 *
 * O valor informado é validado antes de ser
 * armazenado no objeto.
 *
 * @param valor Tamanho informado.
 */

void Tamanho::setValor(const std::string& valor) {
    validar(valor);
    this->valor = valor;
}

/**
 * @brief Retorna o tamanho armazenado.
 *
 * @return Tamanho válido.
 */

std::string Tamanho::getValor() const {
    return valor;
}

/**
 * @brief Verifica se o tamanho informado atende às regras do domínio.
 *
 * Os únicos tamanhos permitidos são:
 * - GRANDE
 * - MEDIO
 * - PEQUENO
 *
 * @param valor Tamanho a ser validado.
 *
 * @throws std::invalid_argument Caso o tamanho informado não
 * pertença ao conjunto de valores permitidos.
 */

void Tamanho::validar(const std::string& valor) {
    /// Verifica se o valor corresponde a um dos tamanhos permitidos pelo domínio (sem acentuação).
    if (valor != "GRANDE" && valor != "MEDIO" && valor != "PEQUENO") {
        throw std::invalid_argument("Tamanho invalido: deve ser 'GRANDE', 'MEDIO' ou 'PEQUENO'.");
    }
}
