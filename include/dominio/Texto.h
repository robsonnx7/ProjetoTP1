#ifndef TEXTO_H
#define TEXTO_H

#include <string>
#include <stdexcept>

/// Classe que representa o dominio Texto do sistema Kanban.
/// Garante o encapsulamento e a validacao do valor conforme as regras do trabalho.
class Texto {
private:
    /// Atributo privado para armazenar o valor do texto apos validacao
    std::string valor;

    /// Metodo privado auxiliar que valida a string.
    /// Lanca std::invalid_argument se qualquer regra for violada.
    void validar(const std::string& valor);

public:
    /// Construtor padrao (sem argumentos)
    Texto() = default;

    /// Construtor com parametro: inicializa o objeto ja validando a string fornecida
    explicit Texto(const std::string& valor);

    /// Altera o valor armazenado, passando obrigatoriamente pela validacao
    void setValor(const std::string& valor);

    /// Retorna o texto armazenado (metodo const garante que nao altera o estado do objeto)
    std::string getValor() const;
};

#endif // TEXTO_H
