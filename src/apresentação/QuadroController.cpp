#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>

#include "QuadroController.h"
#include "Identificador.h"
#include "Nome.h"
#include "Limite.h"
#include "Papel.h"

/**
 * @file QuadroController.cpp
 * @brief Implementação da controladora de apresentação para Quadro.
 */

namespace {

/**
 * @brief Limpa o estado de erro e descarta caracteres restantes no buffer de entrada padrão.
 */
void limparBufferQuad() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
 * @brief Exibe um rótulo e lê uma linha de texto da entrada padrão.
 * @param rotulo Mensagem exibida ao usuário antes da leitura.
 * @return Linha digitada pelo usuário.
 */
std::string lerLinhaQuad(const std::string& rotulo) {
    std::string entrada;
    std::cout << rotulo;
    std::getline(std::cin >> std::ws, entrada);
    return entrada;
}

/**
 * @brief Lê e valida um Identificador a partir da entrada padrão.
 * @param[out] saida Objeto Identificador preenchido com o valor validado.
 * @param rotulo Mensagem exibida ao usuário.
 * @return true se a leitura e validação forem concluídas.
 */
bool lerIdQuad(Identificador& saida, const std::string& rotulo = "Identificador do quadro: ") {
    while (true) {
        try {
            saida.setValor(lerLinhaQuad(rotulo));
            return true;
        } catch (const std::invalid_argument& e) {
            std::cout << "Erro: " << e.what() << "\n";
        }
    }
}

/**
 * @brief Lê e valida todos os campos necessários para montar um Quadro.
 * @param[out] quadro Objeto Quadro preenchido com os dados informados.
 * @param exigirId Indica se o identificador do quadro deve ser solicitado na leitura.
 * @return true se todos os campos forem preenchidos com sucesso.
 */
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

/**
 * @brief Formata e exibe na saída padrão os dados de um Quadro.
 * @param q Quadro a ser exibido.
 */
void exibirQuadro(const Quadro& q) {
    std::cout << "-------------------------------------\n"
              << "ID Quadro  : " << q.getIdentificador().getValor() << "\n"
              << "Nome       : " << q.getNome().getValor() << "\n"
              << "Limite WIP : " << q.getLimite().getValor() << "\n"
              << "ID Projeto : " << q.getIdProjeto().getValor() << "\n"
              << "-------------------------------------\n";
}

} // namespace

/**
 * @brief Constrói a controladora associando-a ao serviço de quadro.
 * @param servico Ponteiro para a implementação de IQuadroService.
 */
QuadroController::QuadroController(IQuadroService* servico)
    : servico(servico) {}

/**
 * @brief Executa o menu interativo de operações sobre Quadro.
 * @param papelSolicitante Papel do usuário solicitante das operações.
 */
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

        if (!(std::cin >> opcao)) {
            limparBufferQuad();
            std::cout << "Entrada invalida.\n";
            continue;
        }
        limparBufferQuad();

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
    } while (opcao != 0);
}
