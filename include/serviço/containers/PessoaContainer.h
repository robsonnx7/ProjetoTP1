#ifndef PESSOACONTAINER_H
#define PESSOACONTAINER_H

#include <map>
#include <string>
#include <vector>
#include "Pessoa.h"
#include "Email.h"

class PessoaContainer {
private:
    std::map<std::string, Pessoa> pessoas;

public:
    bool incluir(const Pessoa& pessoa);
    bool pesquisar(Pessoa* pessoa);
    bool atualizar(const Pessoa& pessoa);
    bool remover(const Email& email);
    bool listar(std::vector<Pessoa>* lista);
};

#endif // PESSOACONTAINER_H
