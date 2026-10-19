#ifndef TAMANHO_H
#define TAMANHO_H

#include <string>
#include <stdexcept>

/// Classe que representa o dominio Tamanho do sistema.
/// Garante que apenas os valores 'GRANDE', 'MEDIO' ou 'PEQUENO' sejam aceitos.
class Tamanho {
private:
    /// Atributo privado que armazena a string do tamanho validado
    std::string valor;

    /// Metodo privado que valida se a entrada corresponde a um dos valores permitidos.
    /// Lanca std::invalid_argument se o valor for diferente dos esperados.
    void validar(const std::string& valor);

public:
    /// Construtor padrao
    Tamanho() = default;

    /// Construtor com parametro que imediatamente valida a string recebida
    explicit Tamanho(const std::string& valor);

    /// Atualiza o valor armazenado apos validacao do construtor acima
    void setValor(const std::string& valor);

    /// Retorna o tamanho armazenado
    std::string getValor() const;
};

#endif // TAMANHO_H
