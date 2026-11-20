#include "Senha.h"
#include <cctype>

/**
 * @brief Constrói um objeto Senha.
 *
 * Inicializa o objeto utilizando o valor informado
 * e executa o processo de validação da senha.
 *
 * @param valor Senha a ser armazenada.
 */

Senha::Senha(const std::string& valor) {
    setValor(valor);
}

/**
 * @brief Define uma nova senha.
 *
 * O valor informado é validado antes de ser
 * armazenado no objeto.
 *
 * @param valor Senha informada.
 */

void Senha::setValor(const std::string& valor) {
    validar(valor);
    this->valor = valor;
}
/**
 * @brief Retorna a senha armazenada.
 *
 * @return Senha válida.
 */

std::string Senha::getValor() const {
    return valor;
}
/**
 * @brief Verifica se a senha informada atende às regras do domínio.
 *
 * A senha deve conter exatamente 5 caracteres.
 * São permitidos apenas letras (A-Z, a-z) e
 * dígitos (0-9).
 * A senha deve possuir pelo menos uma letra
 * e pelo menos um dígito.
 *
 * @param valor Senha a ser validada.
 *
 * @throws std::invalid_argument Caso a senha não
 * atenda às regras estabelecidas pelo domínio.
 */

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
