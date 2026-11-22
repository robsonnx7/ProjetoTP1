#include "ProjetoContainer.h"

/**
 * @file ProjetoContainer.cpp
 * @brief Implementação do container em memória para objetos Projeto.
 */

/**
 * @brief Localiza o índice de um projeto no vetor interno pelo identificador.
 * @param id Identificador do projeto buscado.
 * @return Índice do projeto no vetor se encontrado, ou -1 caso contrário.
 */
int ProjetoContainer::buscarIndicePorId(const Identificador& id) const {
    for (size_t i = 0; i < projetos.size(); ++i) {
        if (projetos[i].getIdentificador().getValor() == id.getValor()) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

/**
 * @brief Insere um projeto se o identificador ainda não estiver cadastrado.
 * @param projeto Objeto Projeto a ser inserido.
 * @return true se inserido com sucesso; false se o identificador já existir.
 */
bool ProjetoContainer::inserir(const Projeto& projeto) {
    if (buscarIndicePorId(projeto.getIdentificador()) != -1) {
        return false;
    }
    projetos.push_back(projeto);
    return true;
}

/**
 * @brief Busca um projeto pelo identificador e preenche o objeto apontado.
 * @param[in,out] projeto Ponteiro contendo o identificador de busca; recebe os dados se encontrado.
 * @return true se encontrado; false se o ponteiro for nulo ou o identificador não existir.
 */
bool ProjetoContainer::buscar(Projeto* projeto) const {
    if (projeto == nullptr) {
        return false;
    }
    int idx = buscarIndicePorId(projeto->getIdentificador());
    if (idx == -1) {
        return false;
    }
    *projeto = projetos[idx];
    return true;
}

/**
 * @brief Atualiza os dados de um projeto existente identificado pelo identificador.
 * @param projeto Objeto Projeto com os novos dados.
 * @return true se atualizado com sucesso; false se o projeto não for encontrado.
 */
bool ProjetoContainer::atualizar(const Projeto& projeto) {
    int idx = buscarIndicePorId(projeto.getIdentificador());
    if (idx == -1) {
        return false;
    }
    projetos[idx] = projeto;
    return true;
}

/**
 * @brief Remove um projeto do container a partir do identificador.
 * @param id Identificador do projeto a ser removido.
 * @return true se removido com sucesso; false se o projeto não for encontrado.
 */
bool ProjetoContainer::remover(const Identificador& id) {
    int idx = buscarIndicePorId(id);
    if (idx == -1) {
        return false;
    }
    projetos.erase(projetos.begin() + idx);
    return true;
}

/**
 * @brief Copia todos os projetos armazenados para o vetor de saída.
 * @param[out] saida Ponteiro para vetor que receberá os projetos cadastrados.
 * @return true se copiado com sucesso; false se o ponteiro for nulo.
 */
bool ProjetoContainer::listar(std::vector<Projeto>* saida) const {
    if (saida == nullptr) {
        return false;
    }
    *saida = projetos;
    return true;
}

/**
 * @brief Verifica se existe algum projeto associado ao e-mail do gestor informado.
 * @param emailGestor E-mail do gestor.
 * @return true se houver ao menos um projeto vinculado ao gestor; false caso contrário.
 */
bool ProjetoContainer::existePorGestor(const Email& emailGestor) const {
    for (const auto& p : projetos) {
        if (p.getEmailGestor().getValor() == emailGestor.getValor()) {
            return true;
        }
    }
    return false;
}
