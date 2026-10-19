#ifndef PAPEL_H
#define PAPEL_H

#include <string>
#include <stdexcept>

/// Classe que representa o dominio Papel do sistema.
// Garante que apenas os papéis 'GESTOR' ou 'DESENVOLVEDOR' sejam aceitos.
class Papel {
private:
    /// Atributo privado que armazena a string do papel validado
    std::string valor;

    /// Metodo privado auxiliar que valida se a entrada corresponde a um dos valores permitidos.
    // Lanca std::invalid_argument se o valor for invalido.
    void validar(const std::string& valor);

public:
    /// Construtor padrao
    Papel() = default;

    /// Construtor com parametro que ja valida a string recebida
    explicit Papel(const std::string& valor);

    /// Atualiza o valor armazenado apos validacao
    void setValor(const std::string& valor);

    /// Retorna o papel armazenado
    std::string getValor() const;
};

#endif // PAPEL_H
