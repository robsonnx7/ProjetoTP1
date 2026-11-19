#include "Email.h"
#include <cctype>

/**
 * @brief Constrói um objeto Email.
 *
 * Inicializa o objeto utilizando o valor informado
 * e executa o processo de validação do endereço.
 *
 * @param valor Endereço de e-mail a ser armazenado.
 */
Email::Email(const std::string& valor) {
    setValor(valor);
}

/**
 * @brief Define um novo endereço de e-mail.
 *
 * O valor informado é validado antes de ser
 * armazenado no objeto.
 *
 * @param valor Endereço de e-mail informado.
 */
void Email::setValor(const std::string& valor) {
    validar(valor);
    this->valor = valor;
}

/**
 * @brief Retorna o endereço de e-mail armazenado.
 *
 * @return Endereço de e-mail válido.
 */
std::string Email::getValor() const {
    return valor;
}

/**
 * @brief Verifica se o endereço de e-mail atende às regras do domínio.
 *
 * O endereço deve conter exatamente um caractere '@',
 * possuir uma parte local válida e um domínio válido.
 *
 * @param valor Endereço de e-mail a ser validado.
 *
 * @throws std::invalid_argument Caso alguma regra de validação seja violada.
 */
void Email::validar(const std::string& valor) {

    /// Verifica se existe exatamente um caractere '@'.
    size_t posArroba = valor.find('@');

    if (posArroba == std::string::npos ||
        valor.find('@', posArroba + 1) != std::string::npos) {

        throw std::invalid_argument(
            "E-mail invalido: deve conter exatamente um caractere '@'."
        );
    }

    /// Separa o endereço em parte local e domínio.
    std::string parteLocal = valor.substr(0, posArroba);
    std::string dominio    = valor.substr(posArroba + 1);

    /// Verifica o tamanho permitido para a parte local.
    if (parteLocal.empty() || parteLocal.length() > 64) {

        throw std::invalid_argument(
            "E-mail invalido: tamanho da parte local deve ter entre 1 e 64 caracteres."
        );
    }

    /// Obtém o primeiro e o último caractere da parte local.
    char primeiroCharLocal = parteLocal.front();
    char ultimoCharLocal   = parteLocal.back();

    /// A parte local não pode iniciar nem terminar
    /// com '.' ou '-'.
    if (primeiroCharLocal == '.' ||
        primeiroCharLocal == '-' ||
        ultimoCharLocal == '.' ||
        ultimoCharLocal == '-') {

        throw std::invalid_argument(
            "E-mail invalido: parte local nao pode iniciar ou terminar com '.' ou '-'."
        );
    }

    /// Verifica os caracteres permitidos da parte local.
    for (size_t i = 0; i < parteLocal.length(); ++i) {

        char c = parteLocal[i];

        /// Aceita apenas letras, dígitos,
        /// ponto e hífen.
        if (!std::isalnum(static_cast<unsigned char>(c))
            && c != '.'
            && c != '-') {

            throw std::invalid_argument(
                "E-mail invalido: caractere nao permitido na parte local."
            );
        }

        /// Garante que '.' ou '-' sejam seguidos
        /// por letra ou dígito.
        if ((c == '.' || c == '-') &&
            i + 1 < parteLocal.length()) {

            char proximo = parteLocal[i + 1];

            if (!std::isalnum(
                    static_cast<unsigned char>(proximo))) {

                throw std::invalid_argument(
                    "E-mail invalido: '.' ou '-' na parte local deve ser seguido por letra ou digito."
                );
            }
        }
    }

    /// Verifica o tamanho permitido para o domínio.
    if (dominio.empty() || dominio.length() > 255) {

        throw std::invalid_argument(
            "Email invalido: tamanho do dominio deve ter entre 1 e 255 caracteres."
        );
    }

    /// Percorre e valida cada subdomínio.
    size_t inicio = 0;

    while (inicio < dominio.length()) {

        size_t fim = dominio.find('.', inicio);

        if (fim == std::string::npos) {
            fim = dominio.length();
        }

        /// Extrai um subdomínio.
        std::string subDominio =
            dominio.substr(inicio, fim - inicio);

        /// Não permite subdomínios vazios.
        if (subDominio.empty()) {

            throw std::invalid_argument(
                "Email invalido: parte do dominio nao pode ser vazia."
            );
        }

        /// O subdomínio não pode iniciar
        /// nem terminar com '-'.
        if (subDominio.front() == '-' ||
            subDominio.back() == '-') {

            throw std::invalid_argument(
                "Email invalido: parte do dominio nao pode iniciar ou terminar com '-'."
            );
        }

        /// Verifica os caracteres permitidos
        /// em cada subdomínio.
        for (char c : subDominio) {

            if (!std::isalnum(
                    static_cast<unsigned char>(c))
                && c != '-') {

                throw std::invalid_argument(
                    "E-mail invalido: caractere nao permitido no dominio."
                );
            }
        }

        /// Avança para o próximo subdomínio.
        inicio = fim + 1;
    }
}
