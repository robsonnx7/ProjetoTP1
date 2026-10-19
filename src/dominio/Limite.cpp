#include "Limite.h"

Limite::Limite(int valor){
    setValor(valor);
}
void Limite::setValor(int valor){
    validar(valor);
    this -> valor = valor;
}
int Limite::getValor() const{
    return valor;
}

void Limite::validar(int valor){
    ///verifica se a entrada está entre o limite de 1 à 25.
    if(valor < 1 || valor > 25){
        throw std::invalid_argument("Limite invalido. Deve estar entre 1 e 25");
       }
}
