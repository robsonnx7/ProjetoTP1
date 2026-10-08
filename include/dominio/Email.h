#ifndef EMAIL_H
#define EMAIL_H

#include <string>
#include <stdexcept>

class Email {
private:
    std::string valor;
    void validar(const std::string& valor);

public:
    Email() = default;
    explicit Email(const std::string& valor);

    void setValor(const std::string& valor);
    std::string getValor() const;
};

#endif // EMAIL_H
