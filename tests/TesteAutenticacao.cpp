#include <cassert>
#include <iostream>
#include <vector>

#include "Pessoa.h"
#include "Email.h"
#include "Nome.h"
#include "Senha.h"
#include "Papel.h"
#include "PessoaContainer.h"
#include "PessoaService.h"
#include "ProjetoService.h"
#include "QuadroService.h"
#include "CartaoAtividadeService.h"

int main() {
    PessoaContainer pessoas;
    PessoaService pessoaService(&pessoas);

    Pessoa gestor;
    gestor.setEmail(Email("gestor@kanban.com"));
    gestor.setNome(Nome("Gestor"));
    gestor.setSenha(Senha("Abc12"));
    gestor.setPapel(Papel("GESTOR"));
    assert(pessoaService.criar(gestor, Papel("GESTOR")));

    Pessoa autenticado;
    assert(pessoaService.autenticar(Email("gestor@kanban.com"), Senha("Abc12"), &autenticado));
    assert(autenticado.getPapel().getValor() == "GESTOR");
    assert(!pessoaService.autenticar(Email("gestor@kanban.com"), Senha("Xyz98"), &autenticado));
    assert(!pessoaService.autenticar(Email("inexistente@kanban.com"), Senha("Abc12"), &autenticado));
    assert(!pessoaService.autenticar(Email("gestor@kanban.com"), Senha("Abc12"), nullptr));

    ProjetoService projetoService;
    QuadroService quadroService;
    CartaoAtividadeService cartaoService;
    const Papel desenvolvedor("DESENVOLVEDOR");
    const Papel papelGestor("GESTOR");
    const Identificador id("ABC123");

    // Desenvolvedores não podem executar operações de escrita administrativa.
    Projeto projeto;
    assert(!projetoService.criar(projeto, desenvolvedor));
    assert(!projetoService.atualizar(projeto, desenvolvedor));
    assert(!projetoService.excluir(id, desenvolvedor));

    Quadro quadro;
    assert(!quadroService.criar(quadro, desenvolvedor));
    assert(!quadroService.atualizar(quadro, desenvolvedor));
    assert(!quadroService.excluir(id, desenvolvedor));

    CartaoAtividade cartao;
    assert(!cartaoService.criar(cartao, desenvolvedor));
    assert(!cartaoService.atualizar(cartao, desenvolvedor));
    assert(!cartaoService.excluir(id, desenvolvedor));

    // Com containers não configurados, nem mesmo o gestor consegue gravar.
    assert(!projetoService.criar(projeto, papelGestor));
    assert(!quadroService.criar(quadro, papelGestor));
    assert(!cartaoService.criar(cartao, papelGestor));

    std::cout << "Todos os testes de autenticacao e permissao passaram.\n";
    return 0;
}
