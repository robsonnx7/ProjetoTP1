#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>

#include "QuadroController.h"
#include "Identificador.h"
#include "Nome.h"
#include "Limite.h"
#include "Papel.h"

namespace {

class EntradaEncerrada {};

void limparBufferQuad() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string lerLinhaQuad(const std::string& rotulo) {
    std::string entrada;
    std::cout << rotulo;
    if (!std::getline(std::cin, entrada)) {
        throw EntradaEncerrada();
    }
    return entrada;
}

bool lerIdQuad(Identificador& saida, const std::string& rotulo = "Identificador do quadro: ") {
    while (true) {
        std::cout << "\nRegras do identificador:\n"
                  << " - Deve conter exatamente 6 caracteres.\n"
                  << " - Os 3 primeiros devem ser letras (A-Z).\n"
                  << " - Os 3 ultimos devem ser numeros (0-9).\n"
                  << " - Exemplo valido: QUA001.\n";
        try {
            saida.setValor(lerLinhaQuad(rotulo));
            return true;
        } catch (const std::invalid_argument& e) {
            std::cout << "Identificador invalido: " << e.what() << "\n"
                      << "Por favor, tente novamente seguindo as regras acima.\n";
        }
    }
}

bool lerDadosQuadro(Quadro& quadro, bool exigirId = true) {
    if (exigirId) {
        Identificador id;
        if (!lerIdQuad(id, "Identificador do quadro: ")) return false;
        quadro.setIdentificador(id);
    }

    while (true) {
        try {
            Nome nome;
            nome.setValor(lerLinhaQuad("Nome do quadro: "));
            quadro.setNome(nome);
            break;
        } catch (const std::invalid_argument& e) {
            std::cout << "Erro: " << e.what() << "\n";
        }
    }

    while (true) {
        std::cout << "Limite WIP (1 a 25): ";
        int valorLimite = 0;
        if (!(std::cin >> valorLimite)) {
            if (std::cin.eof()) throw EntradaEncerrada();
            limparBufferQuad();
            std::cout << "Erro: digite um numero inteiro valido.\n";
            continue;
        }
        limparBufferQuad();

        try {
            Limite limite;
            limite.setValor(valorLimite);
            quadro.setLimite(limite);
            break;
        } catch (const std::invalid_argument& e) {
            std::cout << "Erro: " << e.what() << "\n";
        }
    }

    Identificador idProj;
    if (!lerIdQuad(idProj, "Identificador do projeto vinculado: ")) return false;
    quadro.setIdProjeto(idProj);

    return true;
}

void exibirQuadro(const Quadro& q) {
    std::cout << "-------------------------------------\n"
              << "ID Quadro  : " << q.getIdentificador().getValor() << "\n"
              << "Nome       : " << q.getNome().getValor() << "\n"
              << "Limite WIP : " << q.getLimite().getValor() << "\n"
              << "ID Projeto : " << q.getIdProjeto().getValor() << "\n"
              << "-------------------------------------\n";
}

} // namespace

QuadroController::QuadroController(IQuadroService* servico)
    : servico(servico) {}

void QuadroController::executar(const Papel& papelSolicitante) {
    if (servico == nullptr) {
        std::cout << "Erro: servico de quadro nao configurado.\n";
        return;
    }

    int opcao = -1;
    do {
        std::cout << "\n=== MENU QUADRO ===\n"
                  << "1. Criar quadro\n"
                  << "2. Buscar quadro por ID\n"
                  << "3. Atualizar quadro\n"
                  << "4. Excluir quadro\n"
                  << "5. Listar quadros\n"
                  << "0. Voltar\n"
                  << "Escolha: ";

        std::string linhaOpcao;
        if (!std::getline(std::cin, linhaOpcao)) {
            std::cout << "\nEntrada encerrada. Voltando ao menu anterior.\n";
            return;
        }
        std::istringstream leitorOpcao(linhaOpcao);
        std::string sobra;
        int opcaoLida = -1;
        if (!(leitorOpcao >> opcaoLida) || (leitorOpcao >> sobra)) {
            std::cout << "Entrada invalida. Digite uma opcao numerica.\n";
            continue;
        }
        opcao = opcaoLida;

        try {
        switch (opcao) {
            case 1: {
                Papel papelSol = papelSolicitante;

                Quadro novoQuadro;
                if (!lerDadosQuadro(novoQuadro, true)) break;

                if (servico->criar(novoQuadro, papelSol)) {
                    std::cout << "Quadro criado com sucesso.\n";
                } else {
                    std::cout << "Nao foi possivel criar (verifique se o projeto existe ou se o ID ja existe).\n";
                }
                break;
            }
            case 2: {
                Papel papelSol = papelSolicitante;

                Identificador id;
                if (!lerIdQuad(id)) break;

                Quadro consulta;
                consulta.setIdentificador(id);

                if (servico->ler(&consulta, papelSol)) {
                    exibirQuadro(consulta);
                } else {
                    std::cout << "Quadro nao encontrado.\n";
                }
                break;
            }
            case 3: {
                Papel papelSol = papelSolicitante;

                Quadro quadroAtualizado;
                if (!lerDadosQuadro(quadroAtualizado, true)) break;

                if (servico->atualizar(quadroAtualizado, papelSol)) {
                    std::cout << "Quadro atualizado com sucesso.\n";
                } else {
                    std::cout << "Nao foi possivel atualizar.\n";
                }
                break;
            }
            case 4: {
                Papel papelSol = papelSolicitante;

                Identificador id;
                if (!lerIdQuad(id)) break;

                if (servico->excluir(id, papelSol)) {
                    std::cout << "Quadro excluido com sucesso.\n";
                } else {
                    std::cout << "Nao foi possivel excluir (verifique se ha cartoes vinculados ou se o ID existe).\n";
                }
                break;
            }
            case 5: {
                Papel papelSol = papelSolicitante;

                std::vector<Quadro> lista;
                if (servico->listar(&lista, papelSol)) {
                    if (lista.empty()) {
                        std::cout << "Nenhum quadro cadastrado.\n";
                    } else {
                        for (const auto& q : lista) {
                            exibirQuadro(q);
                        }
                    }
                } else {
                    std::cout << "Nao foi possivel listar quadros.\n";
                }
                break;
            }
            case 0:
                std::cout << "Saindo do menu de quadro...\n";
                break;
            default:
                std::cout << "Opcao invalida.\n";
                break;
        }
        } catch (const EntradaEncerrada&) {
            std::cout << "\nEntrada encerrada. Voltando ao menu anterior.\n";
            return;
        }
    } while (opcao != 0);
}
