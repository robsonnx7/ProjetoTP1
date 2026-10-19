#ifndef NOME_H
#define NOME_H

#include <string>
#include <stdexcept>

class Nome{
private:
    std::string valor;
    void validar(const std::string& valor);

public:
    Nome() = default;
    explicit Nome(const std::string& valor);

    void setValor(const std::string& valor);
    std::string getValor() const;
};

#endif //NOME_H
