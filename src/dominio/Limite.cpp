#include "Limite.h"

/**
 * @brief Constrói um objeto Limite.
 *
 * Inicializa o objeto utilizando o valor informado
 * e executa o processo de validação do limite.
 *
 * @param valor Limite a ser armazenado.
 */

Limite::Limite(int valor){
    setValor(valor);
}

/**
 * @brief Define um novo limite.
 *
 * O valor informado é validado antes de ser
 * armazenado no objeto.
 *
 * @param valor Limite informado.
 */

void Limite::setValor(int valor){
    validar(valor);
    this -> valor = valor;
}

/**
 * @brief Retorna o limite armazenado.
 *
 * @return Limite válido.
 */

int Limite::getValor() const{
    return valor;
}

/**
 * @brief Verifica se o limite informado atende às regras do domínio.
 *
 * O limite deve estar no intervalo de 1 a 25,
 * incluindo os valores extremos.
 *
 * @param valor Limite a ser validado.
 *
 * @throws std::invalid_argument Caso o limite não
 * atenda às regras estabelecidas pelo domínio.
 */

void Limite::validar(int valor){
    /// Verifica se o valor pertence ao intervalo permitido.
    if(valor < 1 || valor > 25){
        throw std::invalid_argument("Limite invalido. Deve estar entre 1 e 25");
       }
}
