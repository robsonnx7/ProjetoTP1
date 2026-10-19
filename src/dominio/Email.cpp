#include "Email.h"
#include <cctype>

Email::Email(const std::string& valor) {
    setValor(valor);
}

void Email::setValor(const std::string& valor) {
    validar(valor);
    this->valor = valor;
}

std::string Email::getValor() const {
    return valor;
}

void Email::validar(const std::string& valor) {
    /// 1. Verificar se o email digitado possui o caractere '@'
    size_t posArroba = valor.find('@');
    if (posArroba == std::string::npos || valor.find('@', posArroba + 1) != std::string::npos) {
        throw std::invalid_argument("E-mail invalido: deve conter exatamente um caractere '@'.");
    }

    std::string parteLocal = valor.substr(0, posArroba);
    std::string dominio = valor.substr(posArroba + 1);

    /// 2. Parte Local
    if (parteLocal.empty() || parteLocal.length() > 64) {
        throw std::invalid_argument("E-mail invalido: tamanho da parte local deve ter entre 1 e 64 caracteres.");
    }

    char primeiroCharLocal = parteLocal.front();
    char ultimoCharLocal = parteLocal.back();
    if (primeiroCharLocal == '.' || primeiroCharLocal == '-' || ultimoCharLocal == '.' || ultimoCharLocal == '-') {
        throw std::invalid_argument("E-mail invalido: parte local nao pode iniciar ou terminar com '.' ou '-'.");
    }

    for (size_t i = 0; i < parteLocal.length(); ++i) {
        char c = parteLocal[i];
        if (!std::isalnum(static_cast<unsigned char>(c)) && c != '.' && c != '-') {
            throw std::invalid_argument("E-mail invalido: caractere nao permitido na parte local.");
        }
        /// Ponto ou hífen deve ser seguido por letra ou dígito
        if ((c == '.' || c == '-') && i + 1 < parteLocal.length()) {
            char proximo = parteLocal[i + 1];
            if (!std::isalnum(static_cast<unsigned char>(proximo))) {
                throw std::invalid_argument("E-mail invalido: '.' ou '-' na parte local deve ser seguido por letra ou digito.");
            }
        }
    }

    /// 3. Domínio
    if (dominio.empty() || dominio.length() > 255) {
        throw std::invalid_argument("Email invalido: tamanho do dominio deve ter entre 1 e 255 caracteres.");
    }

    /// O domínio é totalmente composto por partes separadas por '.'
    size_t inicio = 0;
    while (inicio < dominio.length()) {
        size_t fim = dominio.find('.', inicio);
        if (fim == std::string::npos) {
            fim = dominio.length();
        }

        std::string subDominio = dominio.substr(inicio, fim - inicio);
        if (subDominio.empty()) {
            throw std::invalid_argument("Email invalido: parte do dominio não pode ser vazia.");
        }

        if (subDominio.front() == '-' || subDominio.back() == '-') {
            throw std::invalid_argument("Email invalido: parte do dominio não pode iniciar ou terminar com '-'.");
        }

        for (char c : subDominio) {
            if (!std::isalnum(static_cast<unsigned char>(c)) && c != '-') {
                throw std::invalid_argument("E-mail invalido: caractere não permitido no dominio.");
            }
        }

        inicio = fim + 1;
    }
}
