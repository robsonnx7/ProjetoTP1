#include "Senha.h"
#include <cctype>

/// repassa a entrada para o setValor aplicar a validacao
Senha::Senha(const std::string& valor) {
    setValor(valor);
}

/// Altera o valor interno caso a string cumpra os requisitos
void Senha::setValor(const std::string& valor) {
    validar(valor);
    this->valor = valor;
}

/// Retorna o valor contido na classe
std::string Senha::getValor() const {
    return valor;
}

/// Metodo privado de validacao
void Senha::validar(const std::string& valor) {
    /// 1. Verifica se o comprimento e exatamente igual a 5 caracteres
    if (valor.length() != 5) {
        throw std::invalid_argument("Senha invalida: deve conter exatamente 5 caracteres.");
    }

    bool temLetra = false;
    bool temDigito = false;

    /// 2. Percorre cada caractere para validar os tipos permitidos e checar a composicao
    for (char c : valor) {
        /// Verifica se e um caractere invalido (nem letra, nem digito)
        if (!std::isalnum(static_cast<unsigned char>(c))) {
            throw std::invalid_argument("Senha invalida: deve conter apenas letras (a-z, A-Z) e digitos (0-9).");
        }

        if (std::isalpha(static_cast<unsigned char>(c))) {
            temLetra = true;
        }

        if (std::isdigit(static_cast<unsigned char>(c))) {
            temDigito = true;
        }
    }

    /// 3. Verifica se cumpre o requisito de conter pelo menos uma letra E pelo menos um digito
    if (!temLetra || !temDigito) {
        throw std::invalid_argument("Senha invalida: deve conter pelo menos uma letra e pelo menos um digito.");
    }
}
