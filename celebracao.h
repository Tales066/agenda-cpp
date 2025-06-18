#pragma once

#include <vector>
#include <string>

struct Celebracao {
    std::string titulo;
    std::string data;
    std::string comentario;
};

std::vector<Celebracao> carregamentoCelebracao ();

void salvarCelebracao (const std::vector<Celebracao>& celebracao);
void adicionarCelebracao ();
void ordenarCelebracao();
void deletarCelebracao();
