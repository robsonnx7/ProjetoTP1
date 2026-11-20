#include "Prioridade.h"

/**
 * @brief Constrói um objeto prioridade.
 *
 * Inicializa o objeto utilizando o valor informado
 * e executa o processo de validação da prioridade.
 *
 * @param valor Prioridade a ser armazenada.
 */

Prioridade::Prioridade(const std::string& valor) {
    setValor(valor);
}

/**
 * @brief Define uma nova prioridade.
 *
 * O valor informado é validado antes de ser
 * armazenado no objeto.
 *
 * @param valor Prioridade informada.
 */

void Prioridade::setValor(const std::string& valor) {
    validar(valor);
    this->valor = valor;
}
/**
 * @brief Retorna a prioridade armazenada.
 *
 * @return Prioridade válida.
 */

std::string Prioridade::getValor() const {
    return valor;
}

/**
 * @brief Verifica se a prioridade informada atende às regras do domínio.
 *
 * As únicas prioridades permitidas são:
 * - ALTA
 * - MEDIA
 * - BAIXA
 *
 * @param valor Prioridade a ser validada.
 *
 * @throws std::invalid_argument Caso a prioridade informada não
 * pertença ao conjunto de valores permitidos.
 */

void Prioridade::validar(const std::string& valor) {
    /// Verifica se o valor corresponde a uma das prioridades permitidas pelo domínio.
    if (valor != "ALTA" && valor != "MEDIA" && valor != "BAIXA") {
        throw std::invalid_argument("Prioridade invalida: deve ser 'ALTA', 'MEDIA' ou 'BAIXA'.");
    }
}
