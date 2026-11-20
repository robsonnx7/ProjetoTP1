#include "Nome.h"
#include <cctype>

/**
 * @brief Constrói um objeto Nome.
 *
 * Inicializa o objeto utilizando o valor informado
 * e executa o processo de validação do nome.
 *
 * @param valor Nome a ser armazenado.
 */

Nome::Nome(const std::string& valor){
 setValor(valor);
}

/**
 * @brief Define um novo Nome.
 *
 * O valor informado é validado antes de ser
 * armazenado no objeto.
 *
 * @param valor Nome informado.
 */

void Nome::setValor(const std::string& valor){
    validar(valor);
    this -> valor = valor;
}

/**
 * @brief Retorna o nome armazenado.
 *
 * @return Nome válido.
 */

std::string Nome::getValor() const{
    return valor;
}

/**
 * @brief Verifica se o nome informado atende às regras do domínio.
 *
 * O nome deve conter no máximo 15 caracteres.
 * São permitidas apenas letras maiúsculas (A-Z),
 * letras minúsculas (a-z) e espaços em branco.
 * O primeiro e o último caracteres não podem ser
 * espaços e todo espaço deve ser seguido por uma letra.
 *
 * @param valor Nome a ser validado.
 *
 * @throws std::invalid_argument Caso o nome não
 * atenda às regras estabelecidas pelo domínio.
 */

void Nome::validar(const std::string& valor){

    /// verifica se a entrada é vazia
    if(valor.empty()){
        throw std::invalid_argument(
            "Nome invalido. Nao pode ser vazio."
        );
    }

    /// verifica se o primeiro caractere é espaço
    if(valor.front() == ' '){
        throw std::invalid_argument(
            "Nome invalido. Nao pode comecar com espaco."
        );
    }

    /// verifica se o ultimo caractere é espaço
    if(valor.back() == ' '){
        throw std::invalid_argument(
            "Nome invalido. Nao pode terminar com espaco."
        );
    }

    /// verifica se possui mais de 15 caracteres
    if(valor.length() > 15){
        throw std::invalid_argument(
            "Nome invalido. Nao pode conter mais que 15 caracteres."
        );
    }
    /// Percorre todos os caracteres do nome para
    /// verificar se atendem às regras do domínio.
    for(size_t i = 0; i < valor.length(); i++){

        char c = valor[i];

        /// Permite apenas letras e espaços em branco.
        if(!std::isalpha(static_cast<unsigned char>(c))
           && c != ' '){

            throw std::invalid_argument(
                "Nome invalido. Contem caractere nao permitido."
            );
        }

        /// Espaços devem ser seguidos por uma letra.
        if(c == ' '){

            if(i + 1 >= valor.length()){
                throw std::invalid_argument(
                    "Nome invalido."
                );
            }

            if(!std::isalpha(
                    static_cast<unsigned char>(valor[i + 1]))){

                throw std::invalid_argument(
                    "Nome invalido. Espaco deve ser seguido por letra."
                );
            }
        }
    }
}
