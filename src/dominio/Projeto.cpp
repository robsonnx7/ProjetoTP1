#include "Projeto.h"

/**
 * @file Projeto.cpp
 * @brief Implementação dos métodos da entidade Projeto.
 */

/**
 * @brief Associa um identificador ao projeto.
 *
 * O identificador é utilizado para distinguir
 * unicamente o projeto dentro do sistema.
 *
 * @param id Identificador validado.
 */
void Projeto::setIdentificador(const Identificador& id) {
    this->identificador = id;
}

/**
 * @brief Obtém o identificador do projeto.
 *
 * @return Identificador associado ao projeto.
 */
Identificador Projeto::getIdentificador() const {
    return identificador;
}

/**
 * @brief Define o nome do projeto.
 *
 * O nome permite identificar de forma resumida
 * o projeto dentro do sistema.
 *
 * @param nome Nome validado.
 */
void Projeto::setNome(const Nome& nome) {
    this->nome = nome;
}

/**
 * @brief Obtém o nome do projeto.
 *
 * @return Nome associado ao projeto.
 */
Nome Projeto::getNome() const {
    return nome;
}

/**
 * @brief Define a descrição do projeto.
 *
 * A descrição contém informações detalhadas
 * sobre os objetivos e características do projeto.
 *
 * @param descricao Texto validado.
 */
void Projeto::setDescricao(const Texto& descricao) {
    this->descricao = descricao;
}

/**
 * @brief Obtém a descrição do projeto.
 *
 * @return Descrição associada ao projeto.
 */
Texto Projeto::getDescricao() const {
    return descricao;
}

/**
 * @brief Registra a data de início do projeto.
 *
 * Este atributo representa o momento em que
 * o projeto passou a ser executado.
 *
 * @param inicio Timestamp validado.
 */
void Projeto::setInicio(const Timestamp& inicio) {
    this->inicio = inicio;
}

/**
 * @brief Obtém a data de início do projeto.
 *
 * @return Timestamp correspondente ao início do projeto.
 */
Timestamp Projeto::getInicio() const {
    return inicio;
}

/**
 * @brief Registra a data de término do projeto.
 *
 * Este atributo representa o momento em que
 * o projeto foi concluído.
 *
 * @param termino Timestamp validado.
 */
void Projeto::setTermino(const Timestamp& termino) {
    this->termino = termino;
}

/**
 * @brief Obtém a data de término do projeto.
 *
 * @return Timestamp correspondente ao término do projeto.
 */
Timestamp Projeto::getTermino() const {
    return termino;
}

/**
 * @brief Define o e-mail do gestor responsável pelo projeto.
 *
 * @param emailGestor E-mail validado da pessoa gestora.
 */
void Projeto::setEmailGestor(const Email& emailGestor) {
    this->emailGestor = emailGestor;
}

/**
 * @brief Obtém o e-mail do gestor responsável pelo projeto.
 *
 * @return E-mail do gestor associado ao projeto.
 */
Email Projeto::getEmailGestor() const {
    return emailGestor;
}
