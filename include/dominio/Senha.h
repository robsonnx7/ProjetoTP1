#ifndef SENHA_H
#define SENHA_H

#include <string>
#include <stdexcept>

/// Classe que representa o dominio Senha do sistema.
/// Garante que a senha possua exatamente 5 caracteres com pelo menos uma letra e um digito.
class Senha {
private:
    /// Atributo privado que armazena a string da senha validada
    std::string valor;

    /// Metodo privado auxiliar que aplica as regras de validacao
    void validar(const std::string& valor);

public:
    /// Construtor padrao
    Senha() = default;

    /// Construtor com parametro: inicializa o objeto ja validando a string fornecida
    explicit Senha(const std::string& valor);

    /// Altera o valor armazenado apos validacao
    void setValor(const std::string& valor);

    /// Retorna a senha armazenada
    std::string getValor() const;
};

#endif // SENHA_H
