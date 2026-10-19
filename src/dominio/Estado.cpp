#include "Estado.h"

Estado::Estado(const std::string& valor){
    setValor(valor);
}
void Estado::setValor(const std::string& valor){
    validar(valor);
    this -> valor = valor;
}
std::string Estado::getValor() const{
    return valor;
}
void Estado::validar(const std::string& valor){
    ///verifica se a entrada é correspondente a algum dos estados de atividade atribuidos.
    if(valor != "A FAZER" &&
       valor != "FAZENDO" &&
       valor != "FEITO"){
        throw std::invalid_argument("Estado invalido. Deve ser: A FAZER, FAZENDO ou FEITO.");
       }
}
