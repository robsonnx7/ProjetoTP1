#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>

#include "CartaoAtividadeController.h"
#include "Identificador.h"
#include "Nome.h"
#include "Texto.h"
#include "Prioridade.h"
#include "Estado.h"
#include "Tamanho.h"
#include "Timestamp.h"
#include "Email.h"
#include "Papel.h"

namespace {

void limparBufferCart() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string lerLinhaCart(const std::string& rotulo) {
    std::string entrada;
    std::cout << rotulo;
    std::getline(std::cin >> std::ws, entrada);
    return entrada;
}

bool lerPapelCart(Papel& saida) {
    while (true) {
        try {
            saida.setValor(lerLinhaCart("Papel do solicitante (GESTOR ou DESENVOLVEDOR): "));
            return true;
        } catch (const std::invalid_argument& e) {
            std::cout << "Erro: " << e.what() << "\n";
        }
    }
}

bool lerIdCart(Identificador& saida, const std::string& rotulo) {
    while (true) {
        try {
            saida.setValor(lerLinhaCart(rotulo));
            return true;
        } catch (const std::invalid_argument& e) {
            std::cout << "Erro: " << e.what() << "\n";
        }
    }
}

bool lerDadosCartao(CartaoAtividade& cartao, bool exigirId = true) {
    if (exigirId) {
        Identificador id;
        if (!lerIdCart(id, "Identificador do cartao: ")) return false;
        cartao.setIdentificador(id);
    }

    while (true) {
        try {
            Nome nome;
            nome.setValor(lerLinhaCart("Nome do cartao: "));
            cartao.setNome(nome);
            break;
        } catch (const std::invalid_argument& e) {
            std::cout << "Erro: " << e.what() << "\n";
        }
    }

    while (true) {
        try {
            Texto desc;
            desc.setValor(lerLinhaCart("Descricao do cartao: "));
            cartao.setDescricao(desc);
            break;
        } catch (const std::invalid_argument& e) {
            std::cout << "Erro: " << e.what() << "\n";
        }
    }

    while (true) {
        try {
            Prioridade prio;
            prio.setValor(lerLinhaCart("Prioridade (ALTA, MEDIA ou BAIXA): "));
            cartao.setPrioridade(prio);
            break;
        } catch (const std::invalid_argument& e) {
            std::cout << "Erro: " << e.what() << "\n";
        }
    }

    while (true) {
        try {
            Estado est;
            est.setValor(lerLinhaCart("Estado (A FAZER, FAZENDO ou FEITO): "));
            cartao.setEstado(est);
            break;
        } catch (const std::invalid_argument& e) {
            std::cout << "Erro: " << e.what() << "\n";
        }
    }

    while (true) {
        try {
            Tamanho tam;
            tam.setValor(lerLinhaCart("Tamanho (GRANDE, MEDIO ou PEQUENO): "));
            cartao.setTamanho(tam);
            break;
        } catch (const std::invalid_argument& e) {
            std::cout << "Erro: " << e.what() << "\n";
        }
    }

    while (true) {
        try {
            Timestamp entrada;
            entrada.setValor(lerLinhaCart("Data/hora de entrada (DD-MMM-AAAA-HH:MM): "));
            cartao.setEntrada(entrada);
            break;
        } catch (const std::invalid_argument& e) {
            std::cout << "Erro: " << e.what() << "\n";
        }
    }

    while (true) {
        try {
            Timestamp inicio;
            inicio.setValor(lerLinhaCart("Data/hora de inicio (DD-MMM-AAAA-HH:MM): "));
            cartao.setInicio(inicio);
            break;
        } catch (const std::invalid_argument& e) {
            std::cout << "Erro: " << e.what() << "\n";
        }
    }

    while (true) {
        try {
            Timestamp termino;
            termino.setValor(lerLinhaCart("Data/hora de termino (DD-MMM-AAAA-HH:MM): "));
            cartao.setTermino(termino);
            break;
        } catch (const std::invalid_argument& e) {
            std::cout << "Erro: " << e.what() << "\n";
        }
    }

    Identificador idQuadro;
    if (!lerIdCart(idQuadro, "Identificador do quadro vinculado: ")) return false;
    cartao.setIdQuadro(idQuadro);

    while (true) {
        try {
            Email emailDev;
            emailDev.setValor(lerLinhaCart("E-mail do desenvolvedor responsavel: "));
            cartao.setEmailDesenvolvedor(emailDev);
            break;
        } catch (const std::invalid_argument& e) {
            std::cout << "Erro: " << e.what() << "\n";
        }
    }

    return true;
}

void exibirCartao(const CartaoAtividade& c) {
    std::cout << "-----------------------------------------\n"
              << "ID Cartao    : " << c.getIdentificador().getValor() << "\n"
              << "Nome         : " << c.getNome().getValor() << "\n"
              << "Descricao    : " << c.getDescricao().getValor() << "\n"
              << "Prioridade   : " << c.getPrioridade().getValor() << "\n"
              << "Estado       : " << c.getEstado().getValor() << "\n"
              << "Tamanho      : " << c.getTamanho().getValor() << "\n"
              << "Entrada      : " << c.getEntrada().getValor() << "\n"
              << "Inicio       : " << c.getInicio().getValor() << "\n"
              << "Termino      : " << c.getTermino().getValor() << "\n"
              << "ID Quadro    : " << c.getIdQuadro().getValor() << "\n"
              << "Desenvolvedor: " << c.getEmailDesenvolvedor().getValor() << "\n"
              << "-----------------------------------------\n";
}

} // namespace

CartaoAtividadeController::CartaoAtividadeController(ICartaoAtividadeService* servico)
    : servico(servico) {}

void CartaoAtividadeController::executar() {
    if (servico == nullptr) {
        std::cout << "Erro: servico de cartao de atividade nao configurado.\n";
        return;
    }

    int opcao = -1;
    do {
        std::cout << "\n=== MENU CARTAO DE ATIVIDADE ===\n"
                  << "1. Criar cartao de atividade\n"
                  << "2. Buscar cartao por ID\n"
                  << "3. Atualizar cartao de atividade\n"
                  << "4. Excluir cartao de atividade\n"
                  << "5. Listar cartoes de atividade\n"
                  << "0. Voltar\n"
                  << "Escolha: ";

        if (!(std::cin >> opcao)) {
            limparBufferCart();
            std::cout << "Entrada invalida.\n";
            continue;
        }
        limparBufferCart();

        switch (opcao) {
            case 1: {
                Papel papelSol;
                if (!lerPapelCart(papelSol)) break;

                CartaoAtividade novoCartao;
                if (!lerDadosCartao(novoCartao, true)) break;

                if (servico->criar(novoCartao, papelSol)) {
                    std::cout << "Cartao de atividade criado com sucesso.\n";
                } else {
                    std::cout << "Nao foi possivel criar (verifique se o quadro e o desenvolvedor existem ou se o ID ja existe).\n";
                }
                break;
            }
            case 2: {
                Papel papelSol;
                if (!lerPapelCart(papelSol)) break;

                Identificador id;
                if (!lerIdCart(id, "Identificador do cartao: ")) break;

                CartaoAtividade consulta;
                consulta.setIdentificador(id);

                if (servico->ler(&consulta, papelSol)) {
                    exibirCartao(consulta);
                } else {
                    std::cout << "Cartao de atividade nao encontrado.\n";
                }
                break;
            }
            case 3: {
                Papel papelSol;
                if (!lerPapelCart(papelSol)) break;

                CartaoAtividade cartaoAtualizado;
                if (!lerDadosCartao(cartaoAtualizado, true)) break;

                if (servico->atualizar(cartaoAtualizado, papelSol)) {
                    std::cout << "Cartao de atividade atualizado com sucesso.\n";
                } else {
                    std::cout << "Nao foi possivel atualizar.\n";
                }
                break;
            }
            case 4: {
                Papel papelSol;
                if (!lerPapelCart(papelSol)) break;

                Identificador id;
                if (!lerIdCart(id, "Identificador do cartao: ")) break;

                if (servico->excluir(id, papelSol)) {
                    std::cout << "Cartao de atividade excluido com sucesso.\n";
                } else {
                    std::cout << "Cartao de atividade nao encontrado para exclusao.\n";
                }
                break;
            }
            case 5: {
                Papel papelSol;
                if (!lerPapelCart(papelSol)) break;

                std::vector<CartaoAtividade> lista;
                if (servico->listar(&lista, papelSol)) {
                    if (lista.empty()) {
                        std::cout << "Nenhum cartao de atividade cadastrado.\n";
                    } else {
                        for (const auto& c : lista) {
                            exibirCartao(c);
                        }
                    }
                } else {
                    std::cout << "Nao foi possivel listar cartoes de atividade.\n";
                }
                break;
            }
            case 0:
                std::cout << "Saindo do menu de cartao de atividade...\n";
                break;
            default:
                std::cout << "Opcao invalida.\n";
                break;
        }
    } while (opcao != 0);
}
