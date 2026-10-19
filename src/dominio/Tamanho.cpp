#include "Tamanho.h"

/// Repassa a string de entrada para o setValor fazer a aplicação e validação
Tamanho::Tamanho(const std::string& valor) {
    setValor(valor);
}

/// Altera o valor interno caso a string seja valida
void Tamanho::setValor(const std::string& valor) {
    validar(valor);
    this->valor = valor;
}

/// Retorna o valor atual da classe
std::string Tamanho::getValor() const {
    return valor;
}

/// Metodo privado de validacao
void Tamanho::validar(const std::string& valor) {
    /// Lista de constantes validas definidas na especificacao do projeto (sem acento)
    if (valor != "GRANDE" && valor != "MEDIO" && valor != "PEQUENO") {
        throw std::invalid_argument("Tamanho invalido: deve ser 'GRANDE', 'MEDIO' ou 'PEQUENO'.");
    }
}
