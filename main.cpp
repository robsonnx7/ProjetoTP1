#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <stdexcept>

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

#include "Projeto.h"
#include "Quadro.h"
#include "CartaoAtividade.h"
#include "Pessoa.h"

#include "PessoaContainer.h"
#include "ProjetoContainer.h"
#include "QuadroContainer.h"
#include "CartaoAtividadeContainer.h"

#include "IPessoaService.h"
#include "IProjetoService.h"
#include "IQuadroService.h"
#include "ICartaoAtividadeService.h"

#include "PessoaService.h"
#include "ProjetoService.h"
#include "QuadroService.h"
#include "CartaoAtividadeService.h"

#include "PessoaController.h"
#include "ProjetoController.h"
#include "QuadroController.h"
#include "CartaoAtividadeController.h"

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
                  << e.what() << std::endl;
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
                  << e.what() << std::endl;
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
                  << e.what() << std::endl;
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
                  << e.what() << std::endl;
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
                  << e.what() << std::endl;
    }
}

// ==================================================
// FUNÇÕES TESTE TIMESTAMP
// ==================================================

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

// ==================================================
// FUNÇÕES TESTE TEXTO
// ==================================================

void testarTextoValido(const std::string& txt) {
    try {
        Texto t(txt);
        std::cout << "[OK] Sucesso: \"" << t.getValor() << "\"" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "[ERRO FALHO] Deveria aceitar \"" << txt << "\", mas lancou: " << e.what() << std::endl;
    }
}

void testarTextoInvalido(const std::string& txt) {
    try {
        Texto t(txt);
        std::cout << "[ERRO FALHO] Deveria rejeitar \"" << txt << "\", mas aceitou." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "[OK] Rejeitou corretamente \"" << txt << "\": " << e.what() << std::endl;
    }
}

// ==================================================
// FUNÇÕES TESTE TAMANHO
// ==================================================

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

// ==================================================
// FUNÇÕES TESTE SENHA
// ==================================================

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

// ==================================================
// FUNÇÕES TESTE PAPEL
// ==================================================

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

// ==================================================
// FUNÇÕES TESTE PRIORIDADE
// ==================================================

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

// ==================================================
// FUNÇÕES TESTE LIMITE
// ==================================================

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

// ==================================================
// FUNÇÕES TESTE NOME
// ==================================================

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
// TESTE ENTIDADES
// ==================================================

void testarEntidades() {
    std::cout << "\n=== INICIANDO TESTES DAS ENTIDADES ===" << std::endl;

    try {
        Projeto projeto;
        projeto.setIdentificador(Identificador("ABC123"));
        projeto.setNome(Nome("Sistema de TP"));
        projeto.setDescricao(Texto("Sistema de Gestao."));
        projeto.setInicio(Timestamp("01-OUT-2026-08:00"));
        projeto.setTermino(Timestamp("25-NOV-2026-18:00"));

        std::cout << "[OK] Projeto criado com sucesso:" << std::endl;
        std::cout << "   - ID: " << projeto.getIdentificador().getValor() << std::endl;
        std::cout << "   - Nome: " << projeto.getNome().getValor() << std::endl;
        std::cout << "   - Descricao: " << projeto.getDescricao().getValor() << std::endl;
        std::cout << "   - Inicio: " << projeto.getInicio().getValor() << std::endl;
        std::cout << "   - Termino: " << projeto.getTermino().getValor() << std::endl;

        Quadro quadro;
        quadro.setIdentificador(Identificador("XYZ789"));
        quadro.setNome(Nome("Quadro inicial"));
        quadro.setLimite(Limite(10));

        std::cout << "\n[OK] Quadro criado com sucesso:" << std::endl;
        std::cout << "   - ID: " << quadro.getIdentificador().getValor() << std::endl;
        std::cout << "   - Nome: " << quadro.getNome().getValor() << std::endl;
        std::cout << "   - Limite WIP: " << quadro.getLimite().getValor() << std::endl;

        CartaoAtividade cartao;
        cartao.setIdentificador(Identificador("CAR123"));
        cartao.setNome(Nome("Criar Telas"));
        cartao.setDescricao(Texto("Construir interface inicial."));
        cartao.setPrioridade(Prioridade("ALTA"));
        cartao.setEstado(Estado("FAZENDO"));
        cartao.setTamanho(Tamanho("GRANDE"));
        cartao.setEntrada(Timestamp("15-OUT-2026-10:00"));
        cartao.setInicio(Timestamp("16-OUT-2026-09:00"));
        cartao.setTermino(Timestamp("18-OUT-2026-17:00"));

        std::cout << "\n[OK] Cartao de Atividade criado com sucesso:" << std::endl;
        std::cout << "   - ID: " << cartao.getIdentificador().getValor() << std::endl;
        std::cout << "   - Nome: " << cartao.getNome().getValor() << std::endl;
        std::cout << "   - Prioridade: " << cartao.getPrioridade().getValor() << std::endl;
        std::cout << "   - Estado: " << cartao.getEstado().getValor() << std::endl;
        std::cout << "   - Tamanho: " << cartao.getTamanho().getValor() << std::endl;

    } catch (const std::exception& e) {
        std::cout << "[ERRO] Falha inesperada durante os testes: " << e.what() << std::endl;
    }
}

// ==================================================
// TESTE PESSOACONTAINER E PESSOASERVICE
// ==================================================

void testarPessoaContainerEServico() {
    std::cout << "\n=== INICIANDO TESTES DE PESSOACONTAINER E PESSOASERVICE ===" << std::endl;

    try {
        Pessoa p1;
        p1.setEmail(Email("ana.silva@unb.br"));
        p1.setNome(Nome("Ana Silva"));
        p1.setSenha(Senha("Abc12"));
        p1.setPapel(Papel("GESTOR"));

        Pessoa p2;
        p2.setEmail(Email("carlos@unb.br"));
        p2.setNome(Nome("Carlos"));
        p2.setSenha(Senha("1a2b3"));
        p2.setPapel(Papel("DESENVOLVEDOR"));

        // 1. Testes diretos no PessoaContainer
        PessoaContainer container;
        std::cout << (container.inserir(p1) ? "[OK]" : "[ERRO FALHO]")
                  << " Inserir p1 no container\n";
        std::cout << (!container.inserir(p1) ? "[OK]" : "[ERRO FALHO]")
                  << " Bloquear duplicata de p1 no container\n";

        Pessoa buscaContainer;
        buscaContainer.setEmail(Email("ana.silva@unb.br"));
        std::cout << (container.buscar(&buscaContainer) && buscaContainer.getNome().getValor() == "Ana Silva"
                          ? "[OK]" : "[ERRO FALHO]")
                  << " Buscar p1 no container\n";

        Pessoa p1Atualizada = p1;
        p1Atualizada.setNome(Nome("Ana Maria"));
        std::cout << (container.atualizar(p1Atualizada) ? "[OK]" : "[ERRO FALHO]")
                  << " Atualizar p1 no container\n";

        std::vector<Pessoa> listaContainer;
        std::cout << (container.listar(&listaContainer) && listaContainer.size() == 1 &&
                      listaContainer[0].getNome().getValor() == "Ana Maria"
                          ? "[OK]" : "[ERRO FALHO]")
                  << " Listar container apos atualizacao\n";

        std::cout << (container.remover(Email("ana.silva@unb.br")) ? "[OK]" : "[ERRO FALHO]")
                  << " Remover p1 do container\n";

        // 2. Testes no PessoaService
        PessoaService servico(&container);
        Papel gestor("GESTOR");
        Papel dev("DESENVOLVEDOR");

        std::cout << (servico.criar(p1, gestor) ? "[OK]" : "[ERRO FALHO]")
                  << " PessoaService::criar p1\n";
        std::cout << (!servico.criar(p1, gestor) ? "[OK]" : "[ERRO FALHO]")
                  << " PessoaService::criar bloqueia email duplicado\n";
        std::cout << (servico.criar(p2, dev) ? "[OK]" : "[ERRO FALHO]")
                  << " PessoaService::criar p2\n";

        Pessoa autenticada;
        std::cout << (servico.autenticar(Email("ana.silva@unb.br"), Senha("Abc12"), &autenticada) &&
                      autenticada.getPapel().getValor() == "GESTOR"
                          ? "[OK]" : "[ERRO FALHO]")
                  << " PessoaService::autenticar com credenciais corretas\n";
        std::cout << (!servico.autenticar(Email("ana.silva@unb.br"), Senha("Xyz98"), &autenticada)
                          ? "[OK]" : "[ERRO FALHO]")
                  << " PessoaService::autenticar rejeita senha incorreta\n";
        std::cout << (!servico.autenticar(Email("naoexiste@unb.br"), Senha("Abc12"), &autenticada)
                          ? "[OK]" : "[ERRO FALHO]")
                  << " PessoaService::autenticar rejeita e-mail inexistente\n";

        Pessoa consultaServico;
        consultaServico.setEmail(Email("carlos@unb.br"));
        std::cout << (servico.ler(&consultaServico, gestor) &&
                      consultaServico.getPapel().getValor() == "DESENVOLVEDOR"
                          ? "[OK]" : "[ERRO FALHO]")
                  << " PessoaService::ler p2\n";

        std::cout << (!servico.ler(nullptr, gestor) ? "[OK]" : "[ERRO FALHO]")
                  << " PessoaService::ler com nullptr retorna false\n";

        Pessoa p2Modificada = p2;
        p2Modificada.setNome(Nome("Carlos Souza"));
        std::cout << (servico.atualizar(p2Modificada, gestor) ? "[OK]" : "[ERRO FALHO]")
                  << " PessoaService::atualizar p2\n";

        std::vector<Pessoa> listaServico;
        std::cout << (servico.listar(&listaServico, gestor) && listaServico.size() == 2
                          ? "[OK]" : "[ERRO FALHO]")
                  << " PessoaService::listar retorna 2 pessoas\n";

        std::cout << (servico.excluir(Email("ana.silva@unb.br"), gestor) ? "[OK]" : "[ERRO FALHO]")
                  << " PessoaService::excluir p1\n";

        listaServico.clear();
        std::cout << (servico.listar(&listaServico, gestor) && listaServico.size() == 1
                          ? "[OK]" : "[ERRO FALHO]")
                  << " PessoaService::listar apos exclusao retorna 1 pessoa\n";

    } catch (const std::exception& e) {
        std::cout << "[ERRO] Falha inesperada em PessoaContainer/PessoaService: "
                  << e.what() << std::endl;
    }
}

// ==================================================
// MENUS INTERATIVOS POR PARTE (HIERARQUIA)
// ==================================================

void limparBufferMenuPrincipal() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void executarMenusModulos() {
    PessoaContainer containerPessoa;
    ProjetoContainer containerProjeto;
    QuadroContainer containerQuadro;
    CartaoAtividadeContainer containerCartao;

    PessoaService servicoPessoa(&containerPessoa, &containerProjeto, &containerCartao);
    ProjetoService servicoProjeto(&containerProjeto, &servicoPessoa, &containerQuadro);
    QuadroService servicoQuadro(&containerQuadro, &containerProjeto, &containerCartao);
    CartaoAtividadeService servicoCartao(&containerCartao, &containerQuadro, &containerPessoa);

    IPessoaService* ptrPessoaService = &servicoPessoa;
    IProjetoService* ptrProjetoService = &servicoProjeto;
    IQuadroService* ptrQuadroService = &servicoQuadro;
    ICartaoAtividadeService* ptrCartaoService = &servicoCartao;

    PessoaController controladorPessoa(ptrPessoaService);
    ProjetoController controladorProjeto(ptrProjetoService);
    QuadroController controladorQuadro(ptrQuadroService);
    CartaoAtividadeController controladorCartao(ptrCartaoService);

    std::vector<Pessoa> pessoas;
    servicoPessoa.listar(&pessoas, Papel("GESTOR"));

    // A primeira conta inicializa o sistema com o perfil de GESTOR.
    if (pessoas.empty()) {
        std::cout << "\n=== CONFIGURACAO INICIAL ===\n"
                  << "Nenhuma conta cadastrada. Crie a primeira conta de GESTOR.\n";
        Pessoa primeiroGestor;
        try {
            std::string email, nome, senha;
            std::cout << "E-mail: ";
            if (!std::getline(std::cin >> std::ws, email)) return;
            primeiroGestor.setEmail(Email(email));
            std::cout << "Nome: ";
            if (!std::getline(std::cin, nome)) return;
            primeiroGestor.setNome(Nome(nome));
            std::cout << "Senha (5 caracteres, ao menos uma letra e um digito): ";
            if (!std::getline(std::cin, senha)) return;
            primeiroGestor.setSenha(Senha(senha));
            primeiroGestor.setPapel(Papel("GESTOR"));
            if (!servicoPessoa.criar(primeiroGestor, Papel("GESTOR"))) {
                std::cout << "Nao foi possivel criar a conta inicial.\n";
                return;
            }
            std::cout << "Conta inicial de GESTOR criada.\n";
        } catch (const std::exception& e) {
            std::cout << "Erro no cadastro inicial: " << e.what() << "\n";
            return;
        }
    }

    Pessoa usuarioAutenticado;
    bool autenticado = false;
    while (!autenticado) {
        std::string emailTexto, senhaTexto;
        std::cout << "\n=== LOGIN DO SISTEMA KANBAN ===\n";
        std::cout << "E-mail (ou 0 para sair): ";
        if (!std::getline(std::cin >> std::ws, emailTexto)) return;
        if (emailTexto == "0") return;
        std::cout << "Senha: ";
        if (!std::getline(std::cin, senhaTexto)) return;
        try {
            Email email(emailTexto);
            Senha senha(senhaTexto);
            autenticado = servicoPessoa.autenticar(email, senha, &usuarioAutenticado);
            if (!autenticado) std::cout << "E-mail ou senha incorretos. Tente novamente.\n";
        } catch (const std::exception&) {
            std::cout << "Credenciais em formato invalido. Tente novamente.\n";
        }
    }

    std::cout << "\nBem-vindo(a), " << usuarioAutenticado.getNome().getValor()
              << "! Perfil: " << usuarioAutenticado.getPapel().getValor() << "\n";
    const Papel papelSessao = usuarioAutenticado.getPapel();

    int opcao = -1;
    do {
        std::cout << "\n============================================\n"
                  << "MENU PRINCIPAL - SISTEMA KANBAN\n"
                  << "Usuario: " << usuarioAutenticado.getNome().getValor()
                  << " (" << papelSessao.getValor() << ")\n"
                  << "============================================\n"
                  << "1. Gerenciar pessoas\n"
                  << "2. Gerenciar projetos\n"
                  << "3. Gerenciar quadros\n"
                  << "4. Gerenciar cartoes de atividade\n"
                  << "0. Encerrar sessao\n"
                  << "Escolha: ";

        if (!(std::cin >> opcao)) {
            if (std::cin.eof()) return;
            limparBufferMenuPrincipal();
            std::cout << "Entrada invalida.\n";
            continue;
        }
        limparBufferMenuPrincipal();

        switch (opcao) {
            case 1: controladorPessoa.executar(papelSessao); break;
            case 2: controladorProjeto.executar(papelSessao); break;
            case 3: controladorQuadro.executar(papelSessao); break;
            case 4: controladorCartao.executar(papelSessao); break;
            case 0: std::cout << "Sessao encerrada.\n"; break;
            default: std::cout << "Opcao invalida.\n"; break;
        }
    } while (opcao != 0);
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

    // =============================================
    // TIMESTAMP
    // =============================================
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

    // =============================================
    // TEXTO
    // =============================================
    std::cout << "\n=== TESTES DE TEXTO VALIDOS ===" << std::endl;
    validos = {
        "Tarefa importante.",
        "A1, teste final.",
        "Texto curto.",
        "Exemplo: com ponto."
    };
    for (const auto& txt : validos) {
        testarTextoValido(txt);
    }

    std::cout << "\n=== TESTES DE TEXTO INVALIDOS ===" << std::endl;
    invalidos = {
        "texto comecando minusculo.",
        "Texto com mais de trinta caracteres aqui...",
        "Texto sem ponto final",
        "Texto com pontuacao.. dupla",
        "Texto com pontuacao!?",
        "Texto com @ invalido"
    };
    for (const auto& txt : invalidos) {
        testarTextoInvalido(txt);
    }

    // =============================================
    // TAMANHO
    // =============================================
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
        "grande",
        "Médio",
        "GIGANTE",
        "PEQUENO "
    };
    for (const auto& t : invalidos) {
        testarTamanhoInvalido(t);
    }

    // =============================================
    // SENHA
    // =============================================
    std::cout << "\n=== TESTES DE SENHA VALIDOS ===" << std::endl;
    validos = {
        "a1B2c",
        "1234a",
        "Z9x8Y"
    };
    for (const auto& s : validos) {
        testarSenhaValida(s);
    }

    std::cout << "\n=== TESTES DE SENHA INVALIDOS ===" << std::endl;
    invalidos = {
        "1234",
        "123456",
        "abcde",
        "12345",
        "a1B2#",
        "a 1B2"
    };
    for (const auto& s : invalidos) {
        testarSenhaInvalida(s);
    }

    // =============================================
    // PAPEL
    // =============================================
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
        "gestor",
        "desenvolvedor",
        "ADMINISTRADOR",
        "GESTOR "
    };
    for (const auto& p : invalidos) {
        testarPapelInvalido(p);
    }

    // =============================================
    // PRIORIDADE
    // =============================================
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
        "alta",
        "Média",
        "URGENTE",
        "BAIXA "
    };
    for (const auto& p : invalidos) {
        testarPrioridadeInvalida(p);
    }

    // =============================================
    // LIMITE
    // =============================================
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

    // =============================================
    // NOME
    // =============================================
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
        " Pedro",
        "Pedro ",
        "Pedro  Silva",
        "Pedro123",
        "Pedro@",
        "NomeMuitoGrandeDemais"
    };
    for (const auto& nome : invalidos) {
        testarNomeInvalido(nome);
    }

    testarEntidades();
    testarPessoaContainerEServico();

    // =============================================
    // ACESSO AO SISTEMA COM AUTENTICACAO
    // =============================================
    char abrirMenu = 'n';
    std::cout << "\nDeseja iniciar o sistema que utiliza o metodo Kanban? (s/n): ";
    std::cin >> abrirMenu;
    limparBufferMenuPrincipal();

    if (abrirMenu == 's' || abrirMenu == 'S') {
        executarMenusModulos();
    }

    return 0;
}
