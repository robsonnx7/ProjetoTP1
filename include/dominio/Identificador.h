#ifndef IDENTIFICADOR_H
#define IDENTIFICADOR_H

#include <string>
#include <stdexcept>

class Identificador{
private:
    std::string valor;
    void validar(const std::string& valor);

public:
    Identificador() = default;
    explicit Identificador(const std::string& valor);

    void setValor(const std::string& valor);
    std::string getValor() const;
};

#endif //IDENTIDADE_H
