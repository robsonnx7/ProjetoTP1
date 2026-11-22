#include "PessoaService.h"

/**
 * @file PessoaService.cpp
 * @brief Implementação do serviço de regras de negócio para Pessoa.
 */

/**
 * @brief Constrói o serviço injetando o container de pessoas e containers de dependência.
 * @param pessoaContainer Container de pessoas.
 * @param projetoContainer Container de projetos para checar vínculo como gestor.
 * @param cartaoContainer Container de cartões para checar vínculo como desenvolvedor.
 */
PessoaService::PessoaService(PessoaContainer* pessoaContainer,
                             ProjetoContainer* projetoContainer,
                             CartaoAtividadeContainer* cartaoContainer)
    : pessoaContainer(pessoaContainer),
      projetoContainer(projetoContainer),
      cartaoContainer(cartaoContainer) {}

/**
 * @brief Verifica se o papel solicitante possui permissão de acesso no serviço.
 * @param papelSolicitante Papel do usuário solicitante.
 * @return true se for GESTOR ou DESENVOLVEDOR; false caso contrário.
 */
bool PessoaService::temPermissao(Papel papelSolicitante) const {
    return papelSolicitante.getValor() == "GESTOR" ||
           papelSolicitante.getValor() == "DESENVOLVEDOR";
}

/**
 * @brief Verifica se a pessoa possui projetos como gestor ou cartões como desenvolvedor.
 * @param email E-mail da pessoa a ser verificada.
 * @return true se houver algum vínculo ativo; false caso contrário.
 */
bool PessoaService::possuiVinculosAtivos(const Email& email) const {
    // Na ordem de exclusao (Cartao -> Quadro -> Projeto -> Pessoa),
    // Pessoa so pode ser removida quando nao ha projetos (como gestor)
    // nem cartoes de atividade (como desenvolvedor) vinculados a ela.
    if (projetoContainer != nullptr && projetoContainer->existePorGestor(email)) {
        return true;
    }
    if (cartaoContainer != nullptr && cartaoContainer->existePorDesenvolvedor(email)) {
        return true;
    }
    return false;
}

/**
 * @brief Autentica uma pessoa verificando e-mail e senha cadastrados.
 * @param email E-mail informado na autenticação.
 * @param senha Senha informada na autenticação.
 * @param[out] pessoaAutenticada Ponteiro preenchido com os dados da pessoa autenticada.
 * @return true se e-mail e senha conferirem; false caso contrário.
 */
bool PessoaService::autenticar(const Email& email, const Senha& senha, Pessoa* pessoaAutenticada) {
    if (pessoaContainer == nullptr || pessoaAutenticada == nullptr) {
        return false;
    }

    Pessoa consulta;
    consulta.setEmail(email);
    if (!pessoaContainer->buscar(&consulta)) {
        return false;
    }

    if (consulta.getSenha().getValor() != senha.getValor()) {
        return false;
    }

    *pessoaAutenticada = consulta;
    return true;
}

/**
 * @brief Cadastra uma nova pessoa se houver permissão e container configurado.
 * @param pessoa Objeto Pessoa a ser cadastrado.
 * @param papelSolicitante Papel do usuário solicitante.
 * @return true se cadastrado com sucesso; false caso contrário.
 */
bool PessoaService::criar(const Pessoa& pessoa, Papel papelSolicitante) {
    if (pessoaContainer == nullptr || !temPermissao(papelSolicitante)) {
        return false;
    }
    return pessoaContainer->inserir(pessoa);
}

/**
 * @brief Busca os dados de uma pessoa pelo e-mail.
 * @param[in,out] pessoa Ponteiro contendo o e-mail de busca; recebe os dados se encontrado.
 * @param papelSolicitante Papel do usuário solicitante.
 * @return true se encontrado e autorizado; false caso contrário.
 */
bool PessoaService::ler(Pessoa* pessoa, Papel papelSolicitante) {
    if (pessoaContainer == nullptr || pessoa == nullptr || !temPermissao(papelSolicitante)) {
        return false;
    }
    return pessoaContainer->buscar(pessoa);
}

/**
 * @brief Atualiza os dados de uma pessoa existente.
 * @param pessoa Objeto Pessoa com os dados atualizados.
 * @param papelSolicitante Papel do usuário solicitante.
 * @return true se atualizado com sucesso; false caso contrário.
 */
bool PessoaService::atualizar(const Pessoa& pessoa, Papel papelSolicitante) {
    if (pessoaContainer == nullptr || !temPermissao(papelSolicitante)) {
        return false;
    }
    return pessoaContainer->atualizar(pessoa);
}

/**
 * @brief Exclui uma pessoa caso não possua vínculos ativos em projetos ou cartões.
 * @param email E-mail da pessoa a ser excluída.
 * @param papelSolicitante Papel do usuário solicitante.
 * @return true se excluída com sucesso; false se houver vínculos ativos, sem permissão ou falha na remoção.
 */
bool PessoaService::excluir(const Email& email, Papel papelSolicitante) {
    if (pessoaContainer == nullptr || !temPermissao(papelSolicitante)) {
        return false;
    }
    if (possuiVinculosAtivos(email)) {
        return false;
    }
    return pessoaContainer->remover(email);
}

/**
 * @brief Lista todas as pessoas cadastradas caso haja permissão.
 * @param[out] pessoasSaida Ponteiro para vetor que receberá as pessoas.
 * @param papelSolicitante Papel do usuário solicitante.
 * @return true se listado com sucesso; false caso contrário.
 */
bool PessoaService::listar(std::vector<Pessoa>* pessoasSaida, Papel papelSolicitante) {
    if (pessoaContainer == nullptr || pessoasSaida == nullptr || !temPermissao(papelSolicitante)) {
        return false;
    }
    return pessoaContainer->listar(pessoasSaida);
}
