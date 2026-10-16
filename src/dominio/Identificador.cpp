#include "Identificador.h"
#include <cctype>

Identificador::Identificador(const std::string& valor){
 setValor(valor);
}
void Identificador::setValor(const std::string& valor){
    validar(valor);
    this -> valor = valor;
}
std::string Identificador::getValor() const{
    return valor;
}
void Identificador::validar(const std::string& valor){
    // verifica se o identificador digitado possui 6 caracteres.
    if(valor.length()!=6){
        throw std::invalid_argument("Identificador invalido");
    }
    for(int i=0; i<3; i++){
        if(!std::isalpha(static_cast<unsigned char>(valor[i]))){
            throw std::invalid_argument("Os tres primeiros caracteres devem ser letras.");
        }
    }
    for(int i=3; i<6; i++){
        if(!std::isdigit(valor[i])){
            throw std::invalid_argument("Os tres ultimos caracteres devem ser numeros.");
        }
    }
}
