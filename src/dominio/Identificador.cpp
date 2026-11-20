#include "CartaoAtividade.h"
#include <cctype>

/**
 * @brief Constrói um objeto Identificador.
 *
 * Inicializa o objeto utilizando o valor informado
 * e executa o processo de validação do identificador.
 *
 * @param valor Identificador a ser armazenado.
 */

Identificador::Identificador(const std::string& valor){
 setValor(valor);
}

/**
 * @brief Define um novo identificador.
 *
 * O valor informado é validado antes de ser
 * armazenado no objeto.
 *
 * @param valor Identificador informado.
 */

void Identificador::setValor(const std::string& valor){
    validar(valor);
    this -> valor = valor;
}

/**
 * @brief Retorna o identificador armazenado.
 *
 * @return Identificador válido.
 */

std::string Identificador::getValor() const{
    return valor;
}

/**
 * @brief Verifica se o identificador informado atende às regras do domínio.
 *
 * O identificador deve conter exatamente 6 caracteres,
 * sendo letras de (a-z ou A-Z) os três primeiros caracteres.
 * Sendo digitos de (0-9) os três ultimos caracteres.
 *
 * @param valor Indentificador a ser validado.
 *
 * @throws std::invalid_argument Caso o identificador não
 * atenda às regras estabelecidas pelo domínio.
 */

void Identificador::validar(const std::string& valor){
    /// verifica se o identificador digitado possui 6 caracteres.
    if(valor.length()!=6){
        throw std::invalid_argument("Identificador invalido");
    }
    ///verifica se os tres primeiros caracteres do identificador sao letras.
    for(int i=0; i<3; i++){
        if(!std::isalpha(static_cast<unsigned char>(valor[i]))){
            throw std::invalid_argument("Os tres primeiros caracteres devem ser letras.");
        }
    }
    ///verifica se os ultimos tres caracteres do identificador sao numeros.
    for(int i=3; i<6; i++){
        if(!std::isdigit(valor[i])){
            throw std::invalid_argument("Os tres ultimos caracteres devem ser numeros.");
        }
    }
}
