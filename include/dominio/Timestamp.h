#ifndef TIMESTAMP_H
#define TIMESTAMP_H

#include <string>
#include <stdexcept>
#include <vector>

class Timestamp {
private:
    std::string valor;

    void validar(const std::string& valor);
    bool ehBissexto(int ano) const;
    int obterDiasNoMes(int mes, int ano) const;

public:
    Timestamp() = default;
    explicit Timestamp(const std::string& valor);

    void setValor(const std::string& valor);
    std::string getValor() const;
};

#endif // TIMESTAMP_H
