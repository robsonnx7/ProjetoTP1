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

/**
 * @file ProjetoController.cpp
 * @brief Implementação da controladora de apresentação para Projeto.
 */

namespace {

/**
 * @brief Limpa o estado de erro e descarta caracteres restantes no buffer de entrada padrão.
 */
void limparBufferProj() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
 * @brief Exibe um rótulo e lê uma linha de texto da entrada padrão.
 * @param rotulo Mensagem exibida ao usuário antes da leitura.
 * @return Linha digitada pelo usuário.
 */
std::string lerLinhaProj(const std::string& rotulo) {
    std::string entrada;
    std::cout << rotulo;
    std::getline(std::cin >> std::ws, entrada);
    return entrada;
}

/**
 * @brief Lê e valida o Identificador de um projeto a partir da entrada padrão.
 * @param[out] saida Objeto Identificador preenchido com o valor validado.
 * @return true se a leitura e validação forem concluídas.
 */
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

/**
 * @brief Lê e valida todos os campos necessários para montar um Projeto.
 * @param[out] proj Objeto Projeto preenchido com os dados informados.
 * @param exigirId Indica se o identificador do projeto deve ser solicitado na leitura.
 * @return true se todos os campos forem preenchidos com sucesso.
 */
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

/**
 * @brief Formata e exibe na saída padrão os dados de um Projeto.
 * @param p Projeto a ser exibido.
 */
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

/**
 * @brief Constrói a controladora associando-a ao serviço de projeto.
 * @param servico Ponteiro para a implementação de IProjetoService.
 */
ProjetoController::ProjetoController(IProjetoService* servico)
    : servico(servico) {}

/**
 * @brief Executa o menu interativo de operações sobre Projeto.
 * @param papelSolicitante Papel do usuário solicitante das operações.
 */
void ProjetoController::executar(const Papel& papelSolicitante) {
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
                Papel papelSol = papelSolicitante;

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
                Papel papelSol = papelSolicitante;

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
                Papel papelSol = papelSolicitante;

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
                Papel papelSol = papelSolicitante;

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
                Papel papelSol = papelSolicitante;

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
