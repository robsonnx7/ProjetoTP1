#include <iostream>
#include <vector>
#include <string>

#include "Email.h"
#include "Estado.h"
#include "Identificador.h"
#include "Limite.h"
#include "Nome.h"
#include "Timestamp.h"
#include "Texto.h"
#include "Tamanho.h"
#include "Senha.h"
#include "Papel.h"
#include "Prioridade.h"

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

//========================================================
//FUNÇÕES TESTE TIMESTAMP
//========================================================

void testarTimestampValido(const std::string& ts) {
    try {
        Timestamp t(ts);
        std::cout << "[OK] Sucesso: " << t.getValor() << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "[ERRO] Deveria aceitar '" << ts << "', mas lancou: " << e.what() << std::endl;
    }
}

void testarTimestampInvalido(const std::string& ts) {
    try {
        Timestamp t(ts);
        std::cout << "[ERRO] Deveria rejeitar '" << ts << "', mas aceitou." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "[OK] Rejeitou corretamente '" << ts << "': " << e.what() << std::endl;
    }
}

//========================================================
//FUNÇÕES TESTE TEXTO
//========================================================

/// Funcao para testar entradas que devem ser ACEITAS
void testarTextoValido(const std::string& txt) {
    try {
        Texto t(txt);
        std::cout << "[OK] Sucesso: \"" << t.getValor() << "\"" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "[ERRO FALHO] Deveria aceitar \"" << txt << "\", mas lancou: " << e.what() << std::endl;
    }
}

/// Funcao para testar entradas que devem ser REJEITADAS
void testarTextoInvalido(const std::string& txt) {
    try {
        Texto t(txt);
        std::cout << "[ERRO FALHO] Deveria rejeitar \"" << txt << "\", mas aceitou." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "[OK] Rejeitou corretamente \"" << txt << "\": " << e.what() << std::endl;
    }
}

//=========================================================
//FUNÇÕES TESTE TAMANHO
//=========================================================

/// Funcoes de teste para a classe Tamanho
void testarTamanhoValido(const std::string& tamanhoTeste) {
    try {
        Tamanho t(tamanhoTeste);
        std::cout << "[OK] Sucesso: " << t.getValor() << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "[ERRO FALHO] Deveria aceitar '" << tamanhoTeste << "', mas lancou: " << e.what() << std::endl;
    }
}

void testarTamanhoInvalido(const std::string& tamanhoTeste) {
    try {
        Tamanho t(tamanhoTeste);
        std::cout << "[ERRO FALHO] Deveria rejeitar '" << tamanhoTeste << "', mas aceitou." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "[OK] Rejeitou corretamente '" << tamanhoTeste << "': " << e.what() << std::endl;
    }
}

//=========================================================
//FUNÇÕES TESTE SENHA
//=========================================================

/// Funcoes de teste para a classe Senha
void testarSenhaValida(const std::string& senhaTeste) {
    try {
        Senha s(senhaTeste);
        std::cout << "[OK] Sucesso: " << s.getValor() << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "[ERRO FALHO] Deveria aceitar '" << senhaTeste << "', mas lancou: " << e.what() << std::endl;
    }
}

void testarSenhaInvalida(const std::string& senhaTeste) {
    try {
        Senha s(senhaTeste);
        std::cout << "[ERRO FALHO] Deveria rejeitar '" << senhaTeste << "', mas aceitou." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "[OK] Rejeitou corretamente '" << senhaTeste << "': " << e.what() << std::endl;
    }
}

//==================================================
// FUNÇÕES TESTE PAPEL
//==================================================

// Funcoes de teste para a classe Papel
void testarPapelValido(const std::string& papelTeste) {
    try {
        Papel p(papelTeste);
        std::cout << "[OK] Sucesso: " << p.getValor() << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "[ERRO FALHO] Deveria aceitar '" << papelTeste << "', mas lancou: " << e.what() << std::endl;
    }
}

void testarPapelInvalido(const std::string& papelTeste) {
    try {
        Papel p(papelTeste);
        std::cout << "[ERRO FALHO] Deveria rejeitar '" << papelTeste << "', mas aceitou." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "[OK] Rejeitou corretamente '" << papelTeste << "': " << e.what() << std::endl;
    }
}

//==================================================
// FUNÇÕES TESTE PRIORIDADE
//==================================================

// Funcoes de teste para a classe Prioridade
void testarPrioridadeValida(const std::string& prioridadeTeste) {
    try {
        Prioridade p(prioridadeTeste);
        std::cout << "[OK] Sucesso: " << p.getValor() << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "[ERRO FALHO] Deveria aceitar '" << prioridadeTeste << "', mas lancou: " << e.what() << std::endl;
    }
}

void testarPrioridadeInvalida(const std::string& prioridadeTeste) {
    try {
        Prioridade p(prioridadeTeste);
        std::cout << "[ERRO FALHO] Deveria rejeitar '" << prioridadeTeste << "', mas aceitou." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "[OK] Rejeitou corretamente '" << prioridadeTeste << "': " << e.what() << std::endl;
    }
}
//==================================================
// FUNÇÕES TESTE LIMITE
//==================================================

void testarLimiteValido(int limiteTeste) {
    try {
        Limite l(limiteTeste);

        std::cout << "[OK] Sucesso: "
                  << l.getValor()
                  << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cout << "[ERRO FALHO] Deveria aceitar "
                  << limiteTeste
                  << ", mas lancou: "
                  << e.what()
                  << std::endl;
    }
}

void testarLimiteInvalido(int limiteTeste) {
    try {
        Limite l(limiteTeste);

        std::cout << "[ERRO FALHO] Deveria rejeitar "
                  << limiteTeste
                  << ", mas aceitou."
                  << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cout << "[OK] Rejeitou corretamente "
                  << limiteTeste
                  << ": "
                  << e.what()
                  << std::endl;
    }
}

//==================================================
// FUNÇÕES TESTE NOME
//==================================================

void testarNomeValido(const std::string& nomeTeste) {
    try {
        Nome n(nomeTeste);

        std::cout << "[OK] Sucesso: "
                  << n.getValor()
                  << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cout << "[ERRO FALHO] Deveria aceitar '"
                  << nomeTeste
                  << "', mas lancou: "
                  << e.what()
                  << std::endl;
    }
}

void testarNomeInvalido(const std::string& nomeTeste) {
    try {
        Nome n(nomeTeste);

        std::cout << "[ERRO FALHO] Deveria rejeitar '"
                  << nomeTeste
                  << "', mas aceitou."
                  << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cout << "[OK] Rejeitou corretamente '"
                  << nomeTeste
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

    //=====================================
    // TIMESTAMP
    //=====================================
    std::cout << "\n=== TESTES DE TIMESTAMP VALIDOS ===" << std::endl;
    std::vector<std::string> validos = {
        "01-JAN-2020-00:00",
        "29-FEV-2024-23:59",
        "31-OUT-2026-15:30",
        "15-AGO-2099-12:00"
    };

    for (const auto& ts : validos) {
        testarTimestampValido(ts);
    }

    std::cout << "\n=== TESTES DE TIMESTAMP INVALIDOS ===" << std::endl;
    std::vector<std::string> invalidos = {
        "29-FEV-2023-12:00",
        "31-ABR-2025-10:00",
        "15-XXX-2022-10:00",
        "10-OUT-1999-10:00",
        "10-OUT-2100-10:00",
        "10-OUT-2025-24:00",
        "10-OUT-2025-10:60"
    };

    for (const auto& ts : invalidos) {
        testarTimestampInvalido(ts);
    }

    //=====================================
    // TEXTO
    //=====================================

    std::cout << "\n=== TESTES DE TEXTO VALIDOS ===" << std::endl;
    validos = {
        "Tarefa importante",
        "A1, teste final!",
        "Texto curto?",
        "Exemplo: com pontuacao"
    };

    for (const auto& txt : validos) {
        testarTextoValido(txt);
    }

    std::cout << "\n=== TESTES DE TEXTO INVALIDOS ===" << std::endl;
    invalidos = {
        "texto comecando minúsculo",
        "Texto com mais de trinta caracteres aqui...",
        "Texto terminando com ponto.",
        "Texto com pontuacao.. dupla",
        "Texto com pontuacao!?",
        "Texto com @ invalido"
    };

    for (const auto& txt : invalidos) {
        testarTextoInvalido(txt);
    }

    //=======================================
    //TAMANHO
    //=======================================

    std::cout << "\n=== TESTES DE TAMANHO VALIDOS ===" << std::endl;
    validos = {
        "GRANDE",
        "MEDIO",
        "PEQUENO"
    };

    for (const auto& t : validos) {
        testarTamanhoValido(t);
    }

    std::cout << "\n=== TESTES DE TAMANHO INVALIDOS ===" << std::endl;
    invalidos = {
        "grande",   /// Minusculo nao e permitido
        "Médio",    /// Com acento/minusculo
        "GIGANTE",  /// Valor inexistente
        "PEQUENO "  /// Espaco no final
    };

    for (const auto& t : invalidos) {
        testarTamanhoInvalido(t);
    }

    //=====================================
    // SENHA
    //=====================================
    std::cout << "\n=== TESTES DE SENHA VALIDOS ===" << std::endl;
    validos = {
        "a1B2c",  /// 5 caracteres, mistura letras e digitos
        "1234a",  /// 4 digitos e 1 letra
        "Z9x8Y"   /// 5 caracteres validos
    };

    for (const auto& s : validos) {
        testarSenhaValida(s);
    }

    std::cout << "\n=== TESTES DE SENHA INVALIDOS ===" << std::endl;
    invalidos = {
        "1234",    /// Menos de 5 caracteres
        "123456",  /// Mais de 5 caracteres
        "abcde",   /// Apenas letras (falta digito)
        "12345",   /// Apenas digitos (falta letra)
        "a1B2#",   /// Contem caractere especial '#'
        "a 1B2"    /// Contem espaco em branco
    };

    for (const auto& s : invalidos) {
        testarSenhaInvalida(s);
    }

    //=====================================
    // PAPEL
    //=====================================
    std::cout << "\n=== TESTES DE PAPEL VALIDOS ===" << std::endl;
    validos = {
        "GESTOR",
        "DESENVOLVEDOR"
    };

    for (const auto& p : validos) {
        testarPapelValido(p);
    }

    std::cout << "\n=== TESTES DE PAPEL INVALIDOS ===" << std::endl;
    invalidos = {
        "gestor",        /// Minusculo nao e permitido
        "desenvolvedor", /// Minusculo nao e permitido
        "ADMINISTRADOR", /// Valor inexistente no dominio
        "GESTOR "        /// Espaco no final
    };

    for (const auto& p : invalidos) {
        testarPapelInvalido(p);
    }

    //=====================================
    // PRIORIDADE
    //=====================================
    std::cout << "\n=== TESTES DE PRIORIDADE VALIDOS ===" << std::endl;
    validos = {
        "ALTA",
        "MEDIA",
        "BAIXA"
    };

    for (const auto& p : validos) {
        testarPrioridadeValida(p);
    }

    std::cout << "\n=== TESTES DE PRIORIDADE INVALIDOS ===" << std::endl;
    invalidos = {
        "alta",     /// Minusculo nao e permitido
        "Média",    /// Com acento/minusculo
        "URGENTE",  /// Valor inexistente no dominio
        "BAIXA "    /// Espaco no final
    };

    for (const auto& p : invalidos) {
        testarPrioridadeInvalida(p);
    }
        //=====================================
    // LIMITE
    //=====================================

    std::cout << "\n=== TESTES DE LIMITE VALIDOS ===" << std::endl;

    std::vector<int> limitesValidos = {
        1,
        5,
        10,
        20,
        25
    };

    for (const auto& l : limitesValidos) {
        testarLimiteValido(l);
    }

    std::cout << "\n=== TESTES DE LIMITE INVALIDOS ===" << std::endl;

    std::vector<int> limitesInvalidos = {
        0,
        -1,
        26,
        50,
        100
    };

    for (const auto& l : limitesInvalidos) {
        testarLimiteInvalido(l);
    }

        //=====================================
    // NOME
    //=====================================

    std::cout << "\n=== TESTES DE NOME VALIDOS ===" << std::endl;

    validos = {
        "Joao",
        "Maria",
        "Pedro Silva",
        "Ana Clara",
        "Jose Carlos"
    };

    for (const auto& nome : validos) {
        testarNomeValido(nome);
    }

    std::cout << "\n=== TESTES DE NOME INVALIDOS ===" << std::endl;

    invalidos = {
        "",
        " Pedro",            // inicia com espaço
        "Pedro ",            // termina com espaço
        "Pedro  Silva",      // espaço seguido de espaço
        "Pedro123",          // contém números
        "Pedro@",            // caractere especial
        "NomeMuitoGrandeDemais" // mais de 15 caracteres
    };

    for (const auto& nome : invalidos) {
        testarNomeInvalido(nome);
    }
    return 0;
}
