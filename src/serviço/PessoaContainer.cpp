#include "PessoaContainer.h"

/**
 * @file PessoaContainer.cpp
 * @brief Implementação do container em memória para objetos Pessoa.
 */

/**
 * @brief Localiza o índice de uma pessoa no vetor interno pelo e-mail.
 * @param email E-mail da pessoa buscada.
 * @return Índice da pessoa no vetor se encontrada, ou -1 caso contrário.
 */
int PessoaContainer::buscarIndicePorEmail(const Email& email) const {
    for (size_t i = 0; i < pessoas.size(); ++i) {
        if (pessoas[i].getEmail().getValor() == email.getValor()) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

/**
 * @brief Insere uma pessoa se não houver outro registro com o mesmo e-mail.
 * @param pessoa Objeto Pessoa a ser inserido.
 * @return true se inserido com sucesso; false se o e-mail já estiver cadastrado.
 */
bool PessoaContainer::inserir(const Pessoa& pessoa) {
    if (buscarIndicePorEmail(pessoa.getEmail()) != -1) {
        return false;
    }
    pessoas.push_back(pessoa);
    return true;
}

/**
 * @brief Busca uma pessoa pelo e-mail e preenche o objeto apontado.
 * @param[in,out] pessoa Ponteiro contendo o e-mail de busca; recebe os dados se encontrado.
 * @return true se encontrado; false se o ponteiro for nulo ou o e-mail não existir.
 */
bool PessoaContainer::buscar(Pessoa* pessoa) const {
    if (pessoa == nullptr) {
        return false;
    }
    int idx = buscarIndicePorEmail(pessoa->getEmail());
    if (idx == -1) {
        return false;
    }
    *pessoa = pessoas[idx];
    return true;
}

/**
 * @brief Atualiza os dados de uma pessoa existente identificada pelo e-mail.
 * @param pessoa Objeto Pessoa com os dados atualizados.
 * @return true se atualizado com sucesso; false se a pessoa não for encontrada.
 */
bool PessoaContainer::atualizar(const Pessoa& pessoa) {
    int idx = buscarIndicePorEmail(pessoa.getEmail());
    if (idx == -1) {
        return false;
    }
    pessoas[idx] = pessoa;
    return true;
}

/**
 * @brief Remove uma pessoa do container a partir do e-mail.
 * @param email E-mail da pessoa a ser removida.
 * @return true se removido com sucesso; false se a pessoa não for encontrada.
 */
bool PessoaContainer::remover(const Email& email) {
    int idx = buscarIndicePorEmail(email);
    if (idx == -1) {
        return false;
    }
    pessoas.erase(pessoas.begin() + idx);
    return true;
}

/**
 * @brief Copia todas as pessoas armazenadas para o vetor de saída.
 * @param[out] pessoasSaida Ponteiro para vetor que receberá as pessoas cadastradas.
 * @return true se copiado com sucesso; false se o ponteiro for nulo.
 */
bool PessoaContainer::listar(std::vector<Pessoa>* pessoasSaida) const {
    if (pessoasSaida == nullptr) {
        return false;
    }
    *pessoasSaida = pessoas;
    return true;
}
