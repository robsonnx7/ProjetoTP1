#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>

#include "PessoaController.h"
#include "PessoaServiceInt.h"
#include "Pessoa.h"
#include "Email.h"
#include "Nome.h"
#include "Senha.h"
#include "Papel.h"

/**
 * @file PessoaController.cpp
 * @brief Implementação da controladora de apresentação para Pessoa.
 */

namespace {

void limparBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string lerLinha(const std::string& rotulo) {
    std::string entrada;
    std::cout << rotulo;
    std::getline(std::cin >> std::ws, entrada);
    return entrada;
}

bool lerPapelSolicitante(Papel& papelSaida) {
    while (true) {
        std::string textoPapel = lerLinha("Papel do solicitante (GESTOR ou DESENVOLVEDOR): ");
        try {
            papelSaida.setValor(textoPapel);
            return true;
        } catch (const std::invalid_argument& e) {
            std::cout << "Erro: " << e.what() << "\n";
        }
    }
}

bool lerEmail(Email& emailSaida) {
    while (true) {
        std::string textoEmail = lerLinha("E-mail: ");
        try {
            emailSaida.setValor(textoEmail);
            return true;
        } catch (const std::invalid_argument& e) {
            std::cout << "Erro: " << e.what() << "\n";
        }
    }
}

bool lerDadosPessoa(Pessoa& pessoaSaida, bool exigirEmail = true) {
    if (exigirEmail) {
        Email email;
        if (!lerEmail(email)) {
            return false;
        }
        pessoaSaida.setEmail(email);
    }

    while (true) {
        std::string textoNome = lerLinha("Nome (ate 15 caracteres, letras e espacos): ");
        try {
            Nome nome;
            nome.setValor(textoNome);
            pessoaSaida.setNome(nome);
            break;
        } catch (const std::invalid_argument& e) {
            std::cout << "Erro: " << e.what() << "\n";
        }
    }

    while (true) {
        std::string textoSenha = lerLinha("Senha (5 caracteres alfanumericos, 1 letra e 1 digito): ");
        try {
            Senha senha;
            senha.setValor(textoSenha);
            pessoaSaida.setSenha(senha);
            break;
        } catch (const std::invalid_argument& e) {
            std::cout << "Erro: " << e.what() << "\n";
        }
    }

    while (true) {
        std::string textoPapel = lerLinha("Papel (GESTOR ou DESENVOLVEDOR): ");
        try {
            Papel papel;
            papel.setValor(textoPapel);
            pessoaSaida.setPapel(papel);
            break;
        } catch (const std::invalid_argument& e) {
            std::cout << "Erro: " << e.what() << "\n";
        }
    }

    return true;
}

void exibirPessoa(const Pessoa& pessoa) {
    std::cout << "---------------------------\n"
              << "E-mail : " << pessoa.getEmail().getValor() << "\n"
              << "Nome   : " << pessoa.getNome().getValor() << "\n"
              << "Papel  : " << pessoa.getPapel().getValor() << "\n"
              << "---------------------------\n";
}

} // namespace

PessoaController::PessoaController(PessoaServiceInt* servico)
    : servico(servico) {}

void PessoaController::executar() {
    if (servico == nullptr) {
        std::cout << "Erro: servico de pessoa nao configurado.\n";
        return;
    }

    int opcao = -1;
    do {
        std::cout << "\n=== MENU PESSOA ===\n"
                  << "1. Cadastrar pessoa\n"
                  << "2. Buscar pessoa por e-mail\n"
                  << "3. Atualizar pessoa\n"
                  << "4. Excluir pessoa\n"
                  << "5. Listar pessoas\n"
                  << "0. Voltar\n"
                  << "Escolha: ";

        if (!(std::cin >> opcao)) {
            limparBuffer();
            std::cout << "Entrada invalida.\n";
            continue;
        }
        limparBuffer();

        switch (opcao) {
            case 1: {
                Papel papelSol;
                if (!lerPapelSolicitante(papelSol)) break;

                Pessoa novaPessoa;
                if (!lerDadosPessoa(novaPessoa, true)) break;

                if (servico->criar(novaPessoa, papelSol)) {
                    std::cout << "Pessoa cadastrada com sucesso.\n";
                } else {
                    std::cout << "Nao foi possivel cadastrar (verifique permissao ou e-mail duplicado).\n";
                }
                break;
            }
            case 2: {
                Papel papelSol;
                if (!lerPapelSolicitante(papelSol)) break;

                Email emailBusca;
                if (!lerEmail(emailBusca)) break;

                Pessoa pessoaConsulta;
                pessoaConsulta.setEmail(emailBusca);

                if (servico->ler(&pessoaConsulta, papelSol)) {
                    exibirPessoa(pessoaConsulta);
                } else {
                    std::cout << "Pessoa nao encontrada ou operacao nao permitida.\n";
                }
                break;
            }
            case 3: {
                Papel papelSol;
                if (!lerPapelSolicitante(papelSol)) break;

                Pessoa pessoaAtualizada;
                if (!lerDadosPessoa(pessoaAtualizada, true)) break;

                if (servico->atualizar(pessoaAtualizada, papelSol)) {
                    std::cout << "Pessoa atualizada com sucesso.\n";
                } else {
                    std::cout << "Nao foi possivel atualizar (verifique permissao ou existencia do e-mail).\n";
                }
                break;
            }
            case 4: {
                Papel papelSol;
                if (!lerPapelSolicitante(papelSol)) break;

                Email emailExcluir;
                if (!lerEmail(emailExcluir)) break;

                if (servico->excluir(emailExcluir, papelSol)) {
                    std::cout << "Pessoa excluida com sucesso.\n";
                } else {
                    std::cout << "Nao foi possivel excluir (verifique permissao ou existencia do e-mail).\n";
                }
                break;
            }
            case 5: {
                Papel papelSol;
                if (!lerPapelSolicitante(papelSol)) break;

                std::vector<Pessoa> lista;
                if (servico->listar(&lista, papelSol)) {
                    if (lista.empty()) {
                        std::cout << "Nenhuma pessoa cadastrada.\n";
                    } else {
                        for (const Pessoa& p : lista) {
                            exibirPessoa(p);
                        }
                    }
                } else {
                    std::cout << "Nao foi possivel listar pessoas.\n";
                }
                break;
            }
            case 0:
                std::cout << "Saindo do menu de pessoa...\n";
                break;
            default:
                std::cout << "Opcao invalida.\n";
                break;
        }
    } while (opcao != 0);
}
