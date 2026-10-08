#include <iostream>
#include <vector>
#include <string>
#include "Email.h"

// Função auxiliar para testar casos válidos
void testarEmailValido(const std::string& emailTeste) {
    try {
        Email email(emailTeste);
        std::cout << "[OK] Sucesso ao criar Email valido: " << email.getValor() << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "[ERRO FALHO] Deveria aceitar '" << emailTeste << "', mas lançou: " << e.what() << std::endl;
    }
}

// Função auxiliar para testar casos inválidos
void testarEmailInvalido(const std::string& emailTeste) {
    try {
        Email email(emailTeste);
        std::cout << "[ERRO FALHO] Deveria rejeitar '" << emailTeste << "', mas aceitou." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "[OK] Rejeitou corretamente '" << emailTeste << "': " << e.what() << std::endl;
    }
}

int main() {
    std::cout << "=== TESTES DE EMAIL VALIDOS ===" << std::endl;
    std::vector<std::string> emailsValidos = {
        "usuario@dominio.com",
        "nome.sobrenome@sub.dominio.org",
        "a-b.c@d-e.com",
        "123user@empresa.com.br"
    };

    for (const auto& email : emailsValidos) {
        testarEmailValido(email);
    }

    std::cout << "\n=== TESTES DE EMAIL INVALIDOS ===" << std::endl;
    std::vector<std::string> emailsInvalidos = {
        "usuariosemarroba.com",          // Sem '@'
        "usuario@@dominio.com",          // Mais de um '@'
        ".usuario@dominio.com",          // Inicia com '.' na parte local
        "usuario-@dominio.com",          // Termina com '-' na parte local
        "usu..ario@dominio.com",         // Ponto seguido de ponto na parte local
        "usuario@-dominio.com",          // Subdomínio iniciando com '-'
        "usuario@dominio-.com",          // Subdomínio terminando com '-'
        "usuario@.com"                   // Parte do domínio vazia
    };

    for (const auto& email : emailsInvalidos) {
        testarEmailInvalido(email);
    }

    return 0;
}
