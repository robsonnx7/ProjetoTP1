#include "CartaoAtividade.h"

/**
 * @file CartaoAtividade.cpp
 * @brief Implementação dos métodos da entidade CartaoAtividade.
 */

/**
 * @brief Associa um identificador ao cartão.
 *
 * O identificador é responsável por distinguir
 * unicamente a atividade dentro do sistema.
 *
 * @param id Identificador validado.
 */
void CartaoAtividade::setIdentificador(const Identificador& id) {
    this->identificador = id;
}

/**
 * @brief Obtém o identificador do cartão.
 *
 * @return Identificador associado à atividade.
 */
Identificador CartaoAtividade::getIdentificador() const {
    return identificador;
}

/**
 * @brief Define o nome da atividade.
 *
 * O nome permite identificar de forma resumida
 * a atividade representada pelo cartão.
 *
 * @param nome Nome validado.
 */
void CartaoAtividade::setNome(const Nome& nome) {
    this->nome = nome;
}

/**
 * @brief Obtém o nome da atividade.
 *
 * @return Nome associado ao cartão.
 */
Nome CartaoAtividade::getNome() const {
    return nome;
}

/**
 * @brief Define a descrição da atividade.
 *
 * A descrição apresenta informações detalhadas
 * sobre a atividade representada pelo cartão.
 *
 * @param descricao Texto validado.
 */
void CartaoAtividade::setDescricao(const Texto& descricao) {
    this->descricao = descricao;
}

/**
 * @brief Obtém a descrição da atividade.
 *
 * @return Descrição associada ao cartão.
 */
Texto CartaoAtividade::getDescricao() const {
    return descricao;
}

/**
 * @brief Define a prioridade da atividade.
 *
 * A prioridade indica o nível de importância
 * atribuído ao cartão.
 *
 * @param prioridade Prioridade validada.
 */
void CartaoAtividade::setPrioridade(const Prioridade& prioridade) {
    this->prioridade = prioridade;
}

/**
 * @brief Obtém a prioridade da atividade.
 *
 * @return Prioridade associada ao cartão.
 */
Prioridade CartaoAtividade::getPrioridade() const {
    return prioridade;
}

/**
 * @brief Atualiza o estado atual da atividade.
 *
 * O estado representa a posição da atividade
 * no fluxo de trabalho do quadro Kanban.
 *
 * @param estado Estado validado.
 */
void CartaoAtividade::setEstado(const Estado& estado) {
    this->estado = estado;
}

/**
 * @brief Obtém o estado atual da atividade.
 *
 * @return Estado associado ao cartão.
 */
Estado CartaoAtividade::getEstado() const {
    return estado;
}

/**
 * @brief Define o tamanho estimado da atividade.
 *
 * O tamanho representa o esforço necessário
 * para a realização da atividade.
 *
 * @param tamanho Tamanho validado.
 */
void CartaoAtividade::setTamanho(const Tamanho& tamanho) {
    this->tamanho = tamanho;
}

/**
 * @brief Obtém o tamanho estimado da atividade.
 *
 * @return Tamanho associado ao cartão.
 */
Tamanho CartaoAtividade::getTamanho() const {
    return tamanho;
}

/**
 * @brief Registra o instante de entrada do cartão.
 *
 * Este timestamp indica quando a atividade
 * passou a fazer parte do quadro.
 *
 * @param entrada Timestamp validado.
 */
void CartaoAtividade::setEntrada(const Timestamp& entrada) {
    this->entrada = entrada;
}

/**
 * @brief Obtém o instante de entrada do cartão.
 *
 * @return Timestamp de entrada.
 */
Timestamp CartaoAtividade::getEntrada() const {
    return entrada;
}

/**
 * @brief Registra o instante de início da atividade.
 *
 * Este timestamp é utilizado para acompanhar
 * o momento em que a atividade começou a ser executada.
 *
 * @param inicio Timestamp validado.
 */
void CartaoAtividade::setInicio(const Timestamp& inicio) {
    this->inicio = inicio;
}

/**
 * @brief Obtém o instante de início da atividade.
 *
 * @return Timestamp de início.
 */
Timestamp CartaoAtividade::getInicio() const {
    return inicio;
}

/**
 * @brief Registra o instante de conclusão da atividade.
 *
 * Este timestamp representa o momento em que
 * a atividade atingiu o estado de concluída.
 *
 * @param termino Timestamp validado.
 */
void CartaoAtividade::setTermino(const Timestamp& termino) {
    this->termino = termino;
}

/**
 * @brief Obtém o instante de conclusão da atividade.
 *
 * @return Timestamp de término.
 */
Timestamp CartaoAtividade::getTermino() const {
    return termino;
}

/**
 * @brief Define o identificador do quadro vinculado ao cartão.
 *
 * @param idQuadro Identificador validado do quadro.
 */
void CartaoAtividade::setIdQuadro(const Identificador& idQuadro) {
    this->idQuadro = idQuadro;
}

/**
 * @brief Obtém o identificador do quadro vinculado ao cartão.
 *
 * @return Identificador do quadro associado ao cartão.
 */
Identificador CartaoAtividade::getIdQuadro() const {
    return idQuadro;
}

/**
 * @brief Define o e-mail do desenvolvedor responsável pelo cartão.
 *
 * @param emailDesenvolvedor E-mail validado da pessoa desenvolvedora.
 */
void CartaoAtividade::setEmailDesenvolvedor(const Email& emailDesenvolvedor) {
    this->emailDesenvolvedor = emailDesenvolvedor;
}

/**
 * @brief Obtém o e-mail do desenvolvedor responsável pelo cartão.
 *
 * @return E-mail do desenvolvedor associado ao cartão.
 */
Email CartaoAtividade::getEmailDesenvolvedor() const {
    return emailDesenvolvedor;
}
