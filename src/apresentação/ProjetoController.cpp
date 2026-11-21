#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>

#include "ProjetoController.h"
#include "Identificador.h"
#include "Nome.h"
#include "Texto.h"
#include "Timestamp.h"
#include "Email.h"
#include "Papel.h"

namespace {

void limparBufferProj() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string lerLinhaProj(const std::string& rotulo) {
    std::string entrada;
    std::cout << rotulo;
    std::getline(std::cin >> std::ws, entrada);
    return entrada;
}

bool lerPapelProj(Papel& saida) {
    while (true) {
        try {
            saida.setValor(lerLinhaProj("Papel do solicitante (GESTOR ou DESENVOLVEDOR): "));
            return true;
        } catch (const std::invalid_argument& e) {
            std::cout << "Erro: " << e.what() << "\n";
        }
    }
}

bool lerIdProj(Identificador& saida) {
    while (true) {
        try {
            saida.setValor(lerLinhaProj("Identificador do projeto: "));
            return true;
        } catch (const std::invalid_argument& e) {
            std::cout << "Erro: " << e.what() << "\n";
        }
    }
}

bool lerDadosProjeto(Projeto& proj, bool exigirId = true) {
    if (exigirId) {
        Identificador id;
        if (!lerIdProj(id)) return false;
        proj.setIdentificador(id);
    }

    while (true) {
        try {
            Nome nome;
            nome.setValor(lerLinhaProj("Nome do projeto: "));
            proj.setNome(nome);
            break;
        } catch (const std::invalid_argument& e) {
            std::cout << "Erro: " << e.what() << "\n";
        }
    }

    while (true) {
        try {
            Texto desc;
            desc.setValor(lerLinhaProj("Descricao do projeto: "));
            proj.setDescricao(desc);
            break;
        } catch (const std::invalid_argument& e) {
            std::cout << "Erro: " << e.what() << "\n";
        }
    }

    while (true) {
        try {
            Timestamp inicio;
            inicio.setValor(lerLinhaProj("Data/hora de inicio (DD-MMM-AAAA-HH:MM): "));
            proj.setInicio(inicio);
            break;
        } catch (const std::invalid_argument& e) {
            std::cout << "Erro: " << e.what() << "\n";
        }
    }

    while (true) {
        try {
            Timestamp termino;
            termino.setValor(lerLinhaProj("Data/hora de termino (DD-MMM-AAAA-HH:MM): "));
            proj.setTermino(termino);
            break;
        } catch (const std::invalid_argument& e) {
            std::cout << "Erro: " << e.what() << "\n";
        }
    }

    while (true) {
        try {
            Email emailGestor;
            emailGestor.setValor(lerLinhaProj("E-mail do gestor responsavel: "));
            proj.setEmailGestor(emailGestor);
            break;
        } catch (const std::invalid_argument& e) {
            std::cout << "Erro: " << e.what() << "\n";
        }
    }

    return true;
}

void exibirProjeto(const Projeto& p) {
    std::cout << "-------------------------------------\n"
              << "ID      : " << p.getIdentificador().getValor() << "\n"
              << "Nome    : " << p.getNome().getValor() << "\n"
              << "Desc    : " << p.getDescricao().getValor() << "\n"
              << "Inicio  : " << p.getInicio().getValor() << "\n"
              << "Termino : " << p.getTermino().getValor() << "\n"
              << "Gestor  : " << p.getEmailGestor().getValor() << "\n"
              << "-------------------------------------\n";
}

} // namespace

ProjetoController::ProjetoController(IProjetoService* servico)
    : servico(servico) {}

void ProjetoController::executar() {
    if (servico == nullptr) {
        std::cout << "Erro: servico de projeto nao configurado.\n";
        return;
    }

    int opcao = -1;
    do {
        std::cout << "\n=== MENU PROJETO ===\n"
                  << "1. Criar projeto\n"
                  << "2. Buscar projeto por ID\n"
                  << "3. Atualizar projeto\n"
                  << "4. Excluir projeto\n"
                  << "5. Listar projetos\n"
                  << "0. Voltar\n"
                  << "Escolha: ";

        if (!(std::cin >> opcao)) {
            limparBufferProj();
            std::cout << "Entrada invalida.\n";
            continue;
        }
        limparBufferProj();

        switch (opcao) {
            case 1: {
                Papel papelSol;
                if (!lerPapelProj(papelSol)) break;

                Projeto novoProj;
                if (!lerDadosProjeto(novoProj, true)) break;

                if (servico->criar(novoProj, papelSol)) {
                    std::cout << "Projeto criado com sucesso.\n";
                } else {
                    std::cout << "Nao foi possivel criar (verifique se o gestor existe ou se o ID ja existe).\n";
                }
                break;
            }
            case 2: {
                Papel papelSol;
                if (!lerPapelProj(papelSol)) break;

                Identificador id;
                if (!lerIdProj(id)) break;

                Projeto consulta;
                consulta.setIdentificador(id);

                if (servico->ler(&consulta, papelSol)) {
                    exibirProjeto(consulta);
                } else {
                    std::cout << "Projeto nao encontrado.\n";
                }
                break;
            }
            case 3: {
                Papel papelSol;
                if (!lerPapelProj(papelSol)) break;

                Projeto projAtualizado;
                if (!lerDadosProjeto(projAtualizado, true)) break;

                if (servico->atualizar(projAtualizado, papelSol)) {
                    std::cout << "Projeto atualizado com sucesso.\n";
                } else {
                    std::cout << "Nao foi possivel atualizar.\n";
                }
                break;
            }
            case 4: {
                Papel papelSol;
                if (!lerPapelProj(papelSol)) break;

                Identificador id;
                if (!lerIdProj(id)) break;

                if (servico->excluir(id, papelSol)) {
                    std::cout << "Projeto excluido com sucesso.\n";
                } else {
                    std::cout << "Nao foi possivel excluir (verifique se ha quadros vinculados ou se o ID existe).\n";
                }
                break;
            }
            case 5: {
                Papel papelSol;
                if (!lerPapelProj(papelSol)) break;

                std::vector<Projeto> lista;
                if (servico->listar(&lista, papelSol)) {
                    if (lista.empty()) {
                        std::cout << "Nenhum projeto cadastrado.\n";
                    } else {
                        for (const auto& p : lista) {
                            exibirProjeto(p);
                        }
                    }
                } else {
                    std::cout << "Nao foi possivel listar projetos.\n";
                }
                break;
            }
            case 0:
                std::cout << "Saindo do menu de projeto...\n";
                break;
            default:
                std::cout << "Opcao invalida.\n";
                break;
        }
    } while (opcao != 0);
}
