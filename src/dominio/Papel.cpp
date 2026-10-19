#include "Papel.h"

/// repassa a string de entrada para o setValor aplicar a validacao
Papel::Papel(const std::string& valor) {
    setValor(valor);
}

/// Altera o valor interno caso a string seja valida
void Papel::setValor(const std::string& valor) {
    validar(valor);
    this->valor = valor;
}

/// Retorna o valor atual da classe
std::string Papel::getValor() const {
    return valor;
}

/// Metodo privado de validacao
void Papel::validar(const std::string& valor) {
    /// Verifica se o valor informado corresponde exatamente a uma das opcoes validas
    if (valor != "GESTOR" && valor != "DESENVOLVEDOR") {
        throw std::invalid_argument("Papel invalido: deve ser 'GESTOR' ou 'DESENVOLVEDOR'.");
    }
}
