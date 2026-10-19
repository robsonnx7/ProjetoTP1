#include "Timestamp.h"
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>

Timestamp::Timestamp(const std::string& valor) {
    setValor(valor);
}

void Timestamp::setValor(const std::string& valor) {
    validar(valor);
    this->valor = valor;
}

std::string Timestamp::getValor() const {
    return valor;
}

bool Timestamp::ehBissexto(int ano) const {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

int Timestamp::obterDiasNoMes(int mes, int ano) const {
    static const int diasPorMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (mes == 2 && ehBissexto(ano)) {
        return 29;
    }
    return diasPorMes[mes - 1];
}

void Timestamp::validar(const std::string& valor) {
    /// 1. Separar a string por hífen ('-')
    std::vector<std::string> partes;
    std::stringstream ss(valor);
    std::string item;

    while (std::getline(ss, item, '-')) {
        partes.push_back(item);
    }

    if (partes.size() != 4) {
        throw std::invalid_argument("Timestamp invalido: formato correto e DIA-MES-ANO-HORARIO.");
    }

    std::string strDia = partes[0];
    std::string strMes = partes[1];
    std::string strAno = partes[2];
    std::string strHorario = partes[3];

    /// 2. Validar Mês
    static const std::vector<std::string> mesesValidos = {
        "JAN", "FEV", "MAR", "ABR", "MAI", "JUN",
        "JUL", "AGO", "SET", "OUT", "NOV", "DEZ"
    };

    auto it = std::find(mesesValidos.begin(), mesesValidos.end(), strMes);
    if (it == mesesValidos.end()) {
        throw std::invalid_argument("Timestamp invalido: mes incorreto.");
    }
    int mesNum = std::distance(mesesValidos.begin(), it) + 1;

    /// 3. Validar Ano (2000 a 2099)
    int ano;
    try {
        ano = std::stoi(strAno);
    } catch (...) {
        throw std::invalid_argument("Timestamp invalido: ano invalido.");
    }

    if (strAno.length() != 4 || ano < 2000 || ano > 2099) {
        throw std::invalid_argument("Timestamp invalido: ano deve estar entre 2000 e 2099.");
    }

    /// 4. Validar Dia conforme o mês e ano bissexto
    int dia;
    try {
        dia = std::stoi(strDia);
    } catch (...) {
        throw std::invalid_argument("Timestamp invalido: dia invalido.");
    }

    int maxDias = obterDiasNoMes(mesNum, ano);
    if (dia < 1 || dia > maxDias) {
        throw std::invalid_argument("Timestamp invalido: dia fora do alcance para o mes/ano informado.");
    }

    /// 5. Validar Horário (HH:MM)
    size_t posDoisPontos = strHorario.find(':');
    if (posDoisPontos == std::string::npos || strHorario.length() != 5) {
        throw std::invalid_argument("Timestamp invalido: horario deve estar no formato HH:MM.");
    }

    int horas, minutos;
    try {
        horas = std::stoi(strHorario.substr(0, 2));
        minutos = std::stoi(strHorario.substr(3, 2));
    } catch (...) {
        throw std::invalid_argument("Timestamp invalido: hora ou minuto invalido.");
    }

    if (horas < 0 || horas > 23 || minutos < 0 || minutos > 59) {
        throw std::invalid_argument("Timestamp invalido: hora deve ser 00-23 e minutos 00-59.");
    }
}
