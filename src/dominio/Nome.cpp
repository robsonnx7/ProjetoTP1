#include "Nome.h"
#include <cctype>

Nome::Nome(const std::string& valor){
 setValor(valor);
}
void Nome::setValor(const std::string& valor){
    validar(valor);
    this -> valor = valor;
}
std::string Nome::getValor() const{
    return valor;
}

void Nome::validar(const std::string& valor){

    // verifica se a entrada é vazia
    if(valor.empty()){
        throw std::invalid_argument(
            "Nome invalido. Nao pode ser vazio."
        );
    }

    // verifica se o primeiro caractere é espaço
    if(valor.front() == ' '){
        throw std::invalid_argument(
            "Nome invalido. Nao pode comecar com espaco."
        );
    }

    // verifica se o ultimo caractere é espaço
    if(valor.back() == ' '){
        throw std::invalid_argument(
            "Nome invalido. Nao pode terminar com espaco."
        );
    }

    // verifica se possui mais de 15 caracteres
    if(valor.length() > 15){
        throw std::invalid_argument(
            "Nome invalido. Nao pode conter mais que 15 caracteres."
        );
    }

    for(size_t i = 0; i < valor.length(); i++){

        char c = valor[i];

        if(!std::isalpha(static_cast<unsigned char>(c))
           && c != ' '){

            throw std::invalid_argument(
                "Nome invalido. Contem caractere nao permitido."
            );
        }

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
