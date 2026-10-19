#include "Prioridade.h"

/// repassa a string de entrada para o setValor aplicar a validacao
Prioridade::Prioridade(const std::string& valor) {
    setValor(valor);
}

/// Altera o valor interno caso a string seja valida
void Prioridade::setValor(const std::string& valor) {
    validar(valor);
    this->valor = valor;
}

/// Retorna o valor atual da classe
std::string Prioridade::getValor() const {
    return valor;
}

/// Metodo privado de validacao
void Prioridade::validar(const std::string& valor) {
    /// Verifica se o valor informado corresponde exatamente a uma das opcoes validas
    if (valor != "ALTA" && valor != "MEDIA" && valor != "BAIXA") {
        throw std::invalid_argument("Prioridade invalida: deve ser 'ALTA', 'MEDIA' ou 'BAIXA'.");
    }
}
