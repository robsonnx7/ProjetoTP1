#include "Quadro.h"

/**
 * @file Quadro.cpp
 * @brief Implementação dos métodos da entidade Quadro.
 */

/**
 * @brief Associa um identificador ao quadro.
 *
 * O identificador permite distinguir
 * unicamente o quadro dos demais
 * quadros cadastrados no sistema.
 *
 * @param id Identificador validado.
 */
void Quadro::setIdentificador(const Identificador& id) {
    this->identificador = id;
}

/**
 * @brief Obtém o identificador do quadro.
 *
 * @return Identificador associado ao quadro.
 */
Identificador Quadro::getIdentificador() const {
    return identificador;
}

/**
 * @brief Define o nome do quadro.
 *
 * O nome é utilizado para identificar
 * e apresentar o quadro aos usuários
 * do sistema.
 *
 * @param nome Nome validado.
 */
void Quadro::setNome(const Nome& nome) {
    this->nome = nome;
}

/**
 * @brief Obtém o nome do quadro.
 *
 * @return Nome associado ao quadro.
 */
Nome Quadro::getNome() const {
    return nome;
}

/**
 * @brief Define o limite de trabalho em progresso do quadro.
 *
 * O limite representa a quantidade máxima
 * de atividades que podem permanecer
 * simultaneamente em execução.
 *
 * @param limite Limite validado.
 */
void Quadro::setLimite(const Limite& limite) {
    this->limite = limite;
}

/**
 * @brief Obtém o limite de trabalho em progresso do quadro.
 *
 * @return Limite associado ao quadro.
 */
Limite Quadro::getLimite() const {
    return limite;
}
