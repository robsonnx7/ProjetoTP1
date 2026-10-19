#ifndef PRIORIDADE_H
#define PRIORIDADE_H

#include <string>
#include <stdexcept>

/// Classe que representa o dominio Prioridade do sistema Kanban.
/// Garante que apenas os valores 'ALTA', 'MEDIA' ou 'BAIXA' sejam aceitos.
class Prioridade {
private:
    // Atributo privado para armazenar a string da prioridade validada
    std::string valor;

    /// Metodo privado auxiliar que valida a entrada.
    // Lanca std::invalid_argument caso o valor nao corresponda às opções permitidas.
    void validar(const std::string& valor);

public:
    // Construtor padrao
    Prioridade() = default;

    // Construtor com parametro que ja valida a string recebida
    explicit Prioridade(const std::string& valor);

    // Altera o valor armazenado apos validacao
    void setValor(const std::string& valor);

    // Retorna a prioridade armazenada
    std::string getValor() const;
};

#endif // PRIORIDADE_H
