#include "Quadro.h"

/**
 * @file Quadro.cpp
 * @brief Implementação dos métodos da classe entidade Quadro.
 */

void Quadro::setIdentificador(const Identificador& id) {
    this->identificador = id;
}

Identificador Quadro::getIdentificador() const {
    return identificador;
}

void Quadro::setNome(const Nome& nome) {
    this->nome = nome;
}

Nome Quadro::getNome() const {
    return nome;
}

void Quadro::setLimite(const Limite& limite) {
    this->limite = limite;
}

Limite Quadro::getLimite() const {
    return limite;
}
