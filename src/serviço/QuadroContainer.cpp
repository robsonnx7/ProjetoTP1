#include "QuadroContainer.h"

/**
 * @file QuadroContainer.cpp
 * @brief Implementação do container em memória para objetos Quadro.
 */

/**
 * @brief Localiza o índice de um quadro no vetor interno pelo identificador.
 * @param id Identificador do quadro buscado.
 * @return Índice do quadro no vetor se encontrado, ou -1 caso contrário.
 */
int QuadroContainer::buscarIndicePorId(const Identificador& id) const {
    for (size_t i = 0; i < quadros.size(); ++i) {
        if (quadros[i].getIdentificador().getValor() == id.getValor()) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

/**
 * @brief Insere um quadro se o identificador ainda não estiver cadastrado.
 * @param quadro Objeto Quadro a ser inserido.
 * @return true se inserido com sucesso; false se o identificador já existir.
 */
bool QuadroContainer::inserir(const Quadro& quadro) {
    if (buscarIndicePorId(quadro.getIdentificador()) != -1) {
        return false;
    }
    quadros.push_back(quadro);
    return true;
}

/**
 * @brief Busca um quadro pelo identificador e preenche o objeto apontado.
 * @param[in,out] quadro Ponteiro contendo o identificador de busca; recebe os dados se encontrado.
 * @return true se encontrado; false se o ponteiro for nulo ou o identificador não existir.
 */
bool QuadroContainer::buscar(Quadro* quadro) const {
    if (quadro == nullptr) {
        return false;
    }
    int idx = buscarIndicePorId(quadro->getIdentificador());
    if (idx == -1) {
        return false;
    }
    *quadro = quadros[idx];
    return true;
}

/**
 * @brief Atualiza os dados de um quadro existente identificado pelo identificador.
 * @param quadro Objeto Quadro com os novos dados.
 * @return true se atualizado com sucesso; false se o quadro não for encontrado.
 */
bool QuadroContainer::atualizar(const Quadro& quadro) {
    int idx = buscarIndicePorId(quadro.getIdentificador());
    if (idx == -1) {
        return false;
    }
    quadros[idx] = quadro;
    return true;
}

/**
 * @brief Remove um quadro do container a partir do identificador.
 * @param id Identificador do quadro a ser removido.
 * @return true se removido com sucesso; false se o quadro não for encontrado.
 */
bool QuadroContainer::remover(const Identificador& id) {
    int idx = buscarIndicePorId(id);
    if (idx == -1) {
        return false;
    }
    quadros.erase(quadros.begin() + idx);
    return true;
}

/**
 * @brief Copia todos os quadros armazenados para o vetor de saída.
 * @param[out] saida Ponteiro para vetor que receberá os quadros cadastrados.
 * @return true se copiado com sucesso; false se o ponteiro for nulo.
 */
bool QuadroContainer::listar(std::vector<Quadro>* saida) const {
    if (saida == nullptr) {
        return false;
    }
    *saida = quadros;
    return true;
}

/**
 * @brief Verifica se existe algum quadro associado ao projeto informado.
 * @param idProjeto Identificador do projeto.
 * @return true se houver ao menos um quadro vinculado ao projeto; false caso contrário.
 */
bool QuadroContainer::existePorProjeto(const Identificador& idProjeto) const {
    for (const auto& q : quadros) {
        if (q.getIdProjeto().getValor() == idProjeto.getValor()) {
            return true;
        }
    }
    return false;
}
