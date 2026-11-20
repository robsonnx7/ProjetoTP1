#include "Estado.h"

/**
 * @brief Constrói um objeto Estado.
 *
 * Inicializa o objeto utilizando o valor informado
 * e executa o processo de validação do estado.
 *
 * @param valor Estado a ser armazenado.
 */

Estado::Estado(const std::string& valor){
    setValor(valor);
}

/**
 * @brief Define um novo estado.
 *
 * O valor informado é validado antes de ser
 * armazenado no objeto.
 *
 * @param valor Estado informado.
 */

void Estado::setValor(const std::string& valor){
    validar(valor);
    this -> valor = valor;
}

/**
 * @brief Retorna o estado armazenado.
 *
 * @return Estado válido.
 */

std::string Estado::getValor() const{
    return valor;
}

/**
 * @brief Verifica se o estado informado atende às regras do domínio.
 *
 * Os únicos estados permitidos são:
 * - A FAZER
 * - FAZENDO
 * - FEITO
 *
 * @param valor Estado a ser validado.
 *
 * @throws std::invalid_argument Caso o estado informado não
 * pertença ao conjunto de valores permitidos.
 */

void Estado::validar(const std::string& valor){
    /// Verifica se a entrada corresponde a um dos
    /// estados permitidos pelo domínio.
    if(valor != "A FAZER" &&
       valor != "FAZENDO" &&
       valor != "FEITO"){
        throw std::invalid_argument("Estado invalido. Deve ser: A FAZER, FAZENDO ou FEITO.");
       }
}
