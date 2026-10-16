#include <iostream>
#include <vector>
#include <string>

#include "Email.h"
#include "Estado.h"
#include "Identificador.h"

// ==================================================
// TESTES EMAIL
// ==================================================

void testarEmailValido(const std::string& emailTeste) {
    try {
        Email email(emailTeste);
        std::cout << "[OK] Sucesso ao criar Email valido: "
                  << email.getValor() << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cout << "[ERRO FALHO] Deveria aceitar '"
                  << emailTeste
                  << "', mas lançou: "
                  << e.what() << std::endl;
    }
}

void testarEmailInvalido(const std::string& emailTeste) {
    try {
        Email email(emailTeste);

        std::cout << "[ERRO FALHO] Deveria rejeitar '"
                  << emailTeste
                  << "', mas aceitou."
                  << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cout << "[OK] Rejeitou corretamente '"
                  << emailTeste
                  << "': "
                  << e.what()
                  << std::endl;
    }
}

// ==================================================
// TESTES ESTADO
// ==================================================

void testarEstadoValido(const std::string& estadoTeste) {
    try {
        Estado estado(estadoTeste);

        std::cout << "[OK] Sucesso ao criar Estado valido: "
                  << estado.getValor()
                  << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cout << "[ERRO FALHO] Deveria aceitar '"
                  << estadoTeste
                  << "', mas lançou: "
                  << e.what()
                  << std::endl;
    }
}

void testarEstadoInvalido(const std::string& estadoTeste) {
    try {
        Estado estado(estadoTeste);

        std::cout << "[ERRO FALHO] Deveria rejeitar '"
                  << estadoTeste
                  << "', mas aceitou."
                  << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cout << "[OK] Rejeitou corretamente '"
                  << estadoTeste
                  << "': "
                  << e.what()
                  << std::endl;
    }
}

// ==================================================
// TESTES IDENTIFICADOR
// ==================================================

void testarIdentificadorValido(const std::string& identificadorTeste) {
    try {
        Identificador identificador(identificadorTeste);

        std::cout << "[OK] Sucesso ao criar Identificador valido: "
                  << identificador.getValor()
                  << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cout << "[ERRO FALHO] Deveria aceitar '"
                  << identificadorTeste
                  << "', mas lançou: "
                  << e.what()
                  << std::endl;
    }
}

void testarIdentificadorInvalido(const std::string& identificadorTeste) {
    try {
        Identificador identificador(identificadorTeste);

        std::cout << "[ERRO FALHO] Deveria rejeitar '"
                  << identificadorTeste
                  << "', mas aceitou."
                  << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cout << "[OK] Rejeitou corretamente '"
                  << identificadorTeste
                  << "': "
                  << e.what()
                  << std::endl;
    }
}

// ==================================================
// MAIN
// ==================================================

int main() {

    // =============================================
    // EMAIL
    // =============================================

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
        "usuariosemarroba.com",
        "usuario@@dominio.com",
        ".usuario@dominio.com",
        "usuario-@dominio.com",
        "usu..ario@dominio.com",
        "usuario@-dominio.com",
        "usuario@dominio-.com",
        "usuario@.com"
    };

    for (const auto& email : emailsInvalidos) {
        testarEmailInvalido(email);
    }

    // =============================================
    // ESTADO
    // =============================================

    std::cout << "\n=== TESTES DE ESTADO VALIDOS ===" << std::endl;

    std::vector<std::string> estadosValidos = {
        "A FAZER",
        "FAZENDO",
        "FEITO"
    };

    for (const auto& estado : estadosValidos) {
        testarEstadoValido(estado);
    }

    std::cout << "\n=== TESTES DE ESTADO INVALIDOS ===" << std::endl;

    std::vector<std::string> estadosInvalidos = {
        "",
        "FAZER",
        "EM ANDAMENTO",
        "CONCLUIDO",
        "feito",
        "fazendo"
    };

    for (const auto& estado : estadosInvalidos) {
        testarEstadoInvalido(estado);
    }

    // =============================================
    // IDENTIFICADOR
    // =============================================

    std::cout << "\n=== TESTES DE IDENTIFICADOR VALIDOS ===" << std::endl;

    std::vector<std::string> identificadoresValidos = {
        "ABC123",
        "abc123",
        "AbC456",
        "xyz999"
    };

    for (const auto& identificador : identificadoresValidos) {
        testarIdentificadorValido(identificador);
    }

    std::cout << "\n=== TESTES DE IDENTIFICADOR INVALIDOS ===" << std::endl;

    std::vector<std::string> identificadoresInvalidos = {
        "AB1234",
        "ABCD12",
        "ABC12",
        "123ABC",
        "ABC12A",
        "AB@123",
        "ABC-12",
        ""
    };

    for (const auto& identificador : identificadoresInvalidos) {
        testarIdentificadorInvalido(identificador);
    }

    return 0;
}
