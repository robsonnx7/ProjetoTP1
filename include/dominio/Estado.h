#ifndef ESTADO_H
#define ESTADO_H

#include <string>
#include <stdexcept>

class Estado{
private:
    std::string valor;
    void validar(const std::string& valor);

public:
    Estado() = default;
    explicit Estado(const std::string& valor);

    void setValor(const std::string& valor);
    std::string getValor() const;
};

#endif //ESTADO_H
