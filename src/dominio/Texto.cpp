#include "Texto.h"
#include <cctype>

/// Construtor que recebe a string e utiliza o setValor para aplicar a validacao
Texto::Texto(const std::string& valor) {
    setValor(valor);
}

/// Atualiza o valor contido na classe apos validar a nova entrada
void Texto::setValor(const std::string& valor) {
    validar(valor);
    this->valor = valor;
}

/// Metodo de acesso (getter) para obter a string validada
std::string Texto::getValor() const {
    return valor;
}

/// Metodo privado de validacao onde as regras de negocio sao verificadas
void Texto::validar(const std::string& valor) {
    /// 1. Verifica se a string esta vazia ou se excede o limite maximo de 30 caracteres
    if (valor.empty() || valor.length() > 30) {
        throw std::invalid_argument("Texto invalido: deve conter de 1 a 30 caracteres.");
    }

    /// 2. Verifica a regra do primeiro caractere: deve ser obrigatoriamente uma letra maiuscula (A-Z)
    char primeiroChar = valor.front();
    if (!std::isupper(static_cast<unsigned char>(primeiroChar))) {
        throw std::invalid_argument("Texto invalido: o primeiro caractere deve ser letra maiuscula.");
    }

    /// 3. Verifica a regra do ultimo caractere: nao pode ser o sinal de ponto ('.')
    char ultimoChar = valor.back();
    if (ultimoChar == '.') {
        throw std::invalid_argument("Texto invalido: o ultimo caractere nao pode ser um ponto ('.').");
    }

    /// Lambda auxiliar para verificar se um caractere e um sinal de pontuacao permitido: , ; . : ? !
    auto ehPontuacaoPermitida = [](char c) {
        return c == ',' || c == ';' || c == '.' || c == ':' || c == '?' || c == '!';
    };

    /// 4. Percorre cada caractere da string para verificar se e valido e se cumpre as regras de sequencia
    for (size_t i = 0; i < valor.length(); ++i) {
        char c = valor[i];

        /// A) Verifica se o caractere atual pertence ao conjunto permitido:
        ///    Letra (A-Z ou a-z), Digito (0-9), Espaco em branco (' ') ou Pontuacao permitida.
        bool ehAlfanumerico = std::isalnum(static_cast<unsigned char>(c));
        bool ehEspaco = (c == ' ');
        bool ehPontuacao = ehPontuacaoPermitida(c);

        if (!ehAlfanumerico && !ehEspaco && !ehPontuacao) {
            throw std::invalid_argument("Texto invalido: contem caractere nao permitido.");
        }

        /// B) Verifica a regra: sinal de pontuacao NAO pode ser seguido por outro sinal de pontuacao
        if (ehPontuacao && i + 1 < valor.length()) {
            char proximoChar = valor[i + 1];
            if (ehPontuacaoPermitida(proximoChar)) {
                throw std::invalid_argument("Texto invalido: sinal de pontuacao nao pode ser seguido por outro sinal de pontuacao.");
            }
        }
    }
}
