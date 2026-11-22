#include "CartaoAtividadeContainer.h"

/**
 * @file CartaoAtividadeContainer.cpp
 * @brief Implementação do container em memória para objetos CartaoAtividade.
 */

/**
 * @brief Localiza o índice de um cartão no vetor interno pelo identificador.
 * @param id Identificador do cartão buscado.
 * @return Índice do cartão no vetor se encontrado, ou -1 caso contrário.
 */
int CartaoAtividadeContainer::buscarIndicePorId(const Identificador& id) const {
    for (size_t i = 0; i < cartoes.size(); ++i) {
        if (cartoes[i].getIdentificador().getValor() == id.getValor()) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

/**
 * @brief Insere um cartão de atividade se o identificador ainda não estiver em uso.
 * @param cartao Objeto CartaoAtividade a ser inserido.
 * @return true se inserido com sucesso; false se já existir cartão com o mesmo identificador.
 */
bool CartaoAtividadeContainer::inserir(const CartaoAtividade& cartao) {
    if (buscarIndicePorId(cartao.getIdentificador()) != -1) {
        return false;
    }
    cartoes.push_back(cartao);
    return true;
}

/**
 * @brief Busca um cartão pelo identificador e preenche o objeto apontado.
 * @param[in,out] cartao Ponteiro contendo o identificador de busca; recebe os dados se encontrado.
 * @return true se encontrado; false se o ponteiro for nulo ou o identificador não existir.
 */
bool CartaoAtividadeContainer::buscar(CartaoAtividade* cartao) const {
    if (cartao == nullptr) {
        return false;
    }
    int idx = buscarIndicePorId(cartao->getIdentificador());
    if (idx == -1) {
        return false;
    }
    *cartao = cartoes[idx];
    return true;
}

/**
 * @brief Atualiza os dados de um cartão existente identificado pelo identificador.
 * @param cartao Objeto CartaoAtividade com os novos dados.
 * @return true se atualizado com sucesso; false se o cartão não for encontrado.
 */
bool CartaoAtividadeContainer::atualizar(const CartaoAtividade& cartao) {
    int idx = buscarIndicePorId(cartao.getIdentificador());
    if (idx == -1) {
        return false;
    }
    cartoes[idx] = cartao;
    return true;
}

/**
 * @brief Remove um cartão de atividade a partir do identificador.
 * @param id Identificador do cartão a ser removido.
 * @return true se removido com sucesso; false se o cartão não for encontrado.
 */
bool CartaoAtividadeContainer::remover(const Identificador& id) {
    int idx = buscarIndicePorId(id);
    if (idx == -1) {
        return false;
    }
    cartoes.erase(cartoes.begin() + idx);
    return true;
}

/**
 * @brief Copia todos os cartões armazenados para o vetor de saída.
 * @param[out] saida Ponteiro para vetor que receberá os cartões cadastrados.
 * @return true se copiado com sucesso; false se o ponteiro for nulo.
 */
bool CartaoAtividadeContainer::listar(std::vector<CartaoAtividade>* saida) const {
    if (saida == nullptr) {
        return false;
    }
    *saida = cartoes;
    return true;
}

/**
 * @brief Verifica se existe algum cartão vinculado ao quadro informado.
 * @param idQuadro Identificador do quadro.
 * @return true se houver ao menos um cartão vinculado ao quadro; false caso contrário.
 */
bool CartaoAtividadeContainer::existePorQuadro(const Identificador& idQuadro) const {
    for (const auto& c : cartoes) {
        if (c.getIdQuadro().getValor() == idQuadro.getValor()) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Verifica se existe algum cartão associado ao desenvolvedor informado.
 * @param emailDesenvolvedor E-mail do desenvolvedor.
 * @return true se houver ao menos um cartão vinculado ao desenvolvedor; false caso contrário.
 */
bool CartaoAtividadeContainer::existePorDesenvolvedor(const Email& emailDesenvolvedor) const {
    for (const auto& c : cartoes) {
        if (c.getEmailDesenvolvedor().getValor() == emailDesenvolvedor.getValor()) {
            return true;
        }
    }
    return false;
}
