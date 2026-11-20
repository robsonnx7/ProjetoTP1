#include "Timestamp.h"
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>

/**
 * @brief Constrói um objeto Timestamp.
 *
 * Inicializa o objeto utilizando o valor informado
 * e executa o processo de validação do timestamp.
 *
 * @param valor Timestamp a ser armazenado.
 */
Timestamp::Timestamp(const std::string& valor) {
    setValor(valor);
}

/**
 * @brief Define um novo timestamp.
 *
 * O valor informado é validado antes de ser
 * armazenado no objeto.
 *
 * @param valor Timestamp informado.
 */
void Timestamp::setValor(const std::string& valor) {
    validar(valor);
    this->valor = valor;
}

/**
 * @brief Retorna o timestamp armazenado.
 *
 * @return Timestamp válido.
 */
std::string Timestamp::getValor() const {
    return valor;
}

/**
 * @brief Verifica se um determinado ano é bissexto.
 *
 * Um ano é considerado bissexto se for divisível por 4
 * e não divisível por 100, ou se for divisível por 400.
 *
 * @param ano Ano a ser verificado.
 *
 * @return true se o ano for bissexto.
 * @return false caso contrário.
 */
bool Timestamp::ehBissexto(int ano) const {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

/**
 * @brief Retorna a quantidade de dias de um mês.
 *
 * Considera automaticamente anos bissextos para o mês
 * de fevereiro.
 *
 * @param mes Número do mês.
 * @param ano Ano correspondente.
 *
 * @return Quantidade de dias do mês informado.
 */
int Timestamp::obterDiasNoMes(int mes, int ano) const {

    static const int diasPorMes[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if (mes == 2 && ehBissexto(ano)) {
        return 29;
    }

    return diasPorMes[mes - 1];
}

/**
 * @brief Verifica se o timestamp informado atende às regras do domínio.
 *
 * O timestamp deve seguir o formato:
 *
 * DIA-MES-ANO-HORARIO
 *
 * Exemplo:
 *
 * 01-JAN-2025-13:45
 *
 * Regras:
 * - Mês deve ser válido.
 * - Ano deve estar entre 2000 e 2099.
 * - Dia deve existir no mês informado.
 * - Horário deve estar no formato HH:MM.
 * - Hora deve estar entre 00 e 23.
 * - Minutos devem estar entre 00 e 59.
 *
 * @param valor Timestamp a ser validado.
 *
 * @throws std::invalid_argument Caso o timestamp não
 * atenda às regras estabelecidas pelo domínio.
 */
void Timestamp::validar(const std::string& valor) {

    /// Separa a string utilizando o caractere '-' como delimitador.
    std::vector<std::string> partes;
    std::stringstream ss(valor);
    std::string item;

    while (std::getline(ss, item, '-')) {
        partes.push_back(item);
    }

    /// Verifica se o formato possui exatamente quatro partes.
    if (partes.size() != 4) {
        throw std::invalid_argument(
            "Timestamp invalido: formato correto e DIA-MES-ANO-HORARIO."
        );
    }

    std::string strDia = partes[0];
    std::string strMes = partes[1];
    std::string strAno = partes[2];
    std::string strHorario = partes[3];

    /// Lista dos meses válidos definidos pelo domínio.
    static const std::vector<std::string> mesesValidos = {
        "JAN", "FEV", "MAR", "ABR", "MAI", "JUN",
        "JUL", "AGO", "SET", "OUT", "NOV", "DEZ"
    };

    /// Verifica se o mês informado é válido.
    auto it = std::find(
        mesesValidos.begin(),
        mesesValidos.end(),
        strMes
    );

    if (it == mesesValidos.end()) {
        throw std::invalid_argument(
            "Timestamp invalido: mes incorreto."
        );
    }

    int mesNum = std::distance(
        mesesValidos.begin(),
        it
    ) + 1;

    /// Valida o ano.
    int ano;

    try {
        ano = std::stoi(strAno);
    }
    catch (...) {
        throw std::invalid_argument(
            "Timestamp invalido: ano invalido."
        );
    }

    if (strAno.length() != 4 ||
        ano < 2000 ||
        ano > 2099) {

        throw std::invalid_argument(
            "Timestamp invalido: ano deve estar entre 2000 e 2099."
        );
    }

    /// Valida o dia.
    int dia;

    try {
        dia = std::stoi(strDia);
    }
    catch (...) {
        throw std::invalid_argument(
            "Timestamp invalido: dia invalido."
        );
    }

    int maxDias = obterDiasNoMes(mesNum, ano);

    if (dia < 1 || dia > maxDias) {
        throw std::invalid_argument(
            "Timestamp invalido: dia fora do alcance para o mes/ano informado."
        );
    }

    /// Verifica o formato HH:MM.
    size_t posDoisPontos = strHorario.find(':');

    if (posDoisPontos == std::string::npos ||
        strHorario.length() != 5) {

        throw std::invalid_argument(
            "Timestamp invalido: horario deve estar no formato HH:MM."
        );
    }

    /// Valida horas e minutos.
    int horas;
    int minutos;

    try {
        horas = std::stoi(strHorario.substr(0, 2));
        minutos = std::stoi(strHorario.substr(3, 2));
    }
    catch (...) {
        throw std::invalid_argument(
            "Timestamp invalido: hora ou minuto invalido."
        );
    }

    if (horas < 0 || horas > 23 ||
        minutos < 0 || minutos > 59) {

        throw std::invalid_argument(
            "Timestamp invalido: hora deve ser 00-23 e minutos 00-59."
        );
    }
}
