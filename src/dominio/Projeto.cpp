#include "Projeto.h"

/**
 * @file Projeto.cpp
 * @brief Implementação dos métodos da classe entidade Projeto.
 */

void Projeto::setIdentificador(const Identificador& id) {
    this->identificador = id;
}

Identificador Projeto::getIdentificador() const {
    return identificador;
}

void Projeto::setNome(const Nome& nome) {
    this->nome = nome;
}

Nome Projeto::getNome() const {
    return nome;
}

void Projeto::setDescricao(const Texto& descricao) {
    this->descricao = descricao;
}

Texto Projeto::getDescricao() const {
    return descricao;
}

void Projeto::setInicio(const Timestamp& inicio) {
    this->inicio = inicio;
}

Timestamp Projeto::getInicio() const {
    return inicio;
}

void Projeto::setTermino(const Timestamp& termino) {
    this->termino = termino;
}

Timestamp Projeto::getTermino() const {
    return termino;
}
