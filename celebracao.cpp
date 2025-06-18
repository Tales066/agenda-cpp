#include "celebracao.h"
#include <iostream>
#include <fstream>

using namespace std;

vector<Celebracao> carregamentoCelebracao (){
    vector<Celebracao> celebracao;
    ifstream arquivo ("agenda.txt");
    Celebracao ev;

    while (getline(arquivo, ev.titulo)) {
        getline(arquivo, ev.data);
        getline(arquivo, ev.comentario);
        celebracao.push_back(ev);
    }
    arquivo.close();
    return celebracao;
}

void salvarCelebracao (const vector<Celebracao> & celebracao) {
    ofstream arquivo("agenda.txt");
    for(const Celebracao& ev: celebracao) {
        arquivo << ev.titulo << endl;
        arquivo << ev.data << endl;
        arquivo << ev.comentario << endl;
    }
    arquivo.close();
}

void adicionarCelebracao() {
    Celebracao ev;
    cout << "titulo da celebração: ";
    getline(cin, ev.titulo);
    cout << "Data (ex: 10.12.2025): ";
    getline (cin, ev.data);
    cout << "Comentario: ";
    getline(cin, ev.comentario);

    ofstream arquivo("agenda.txt",ios::app);
    arquivo << ev.titulo << endl;
    arquivo << ev.data << endl;
    arquivo << ev.comentario << endl;
    arquivo.close();

    cout << "Celebracao criada com sucesso!\n";
}

void ordenarCelebracao() {
    vector<Celebracao> celebracao = carregamentoCelebracao();

    if (celebracao.empty()) {
        cout << "Nenhuma celebração adicionada.\n";
        return;
    }

    for (size_t i = 0; i < celebracao.size(); ++i) {
        cout << "Celebração " << i + 1 << ":\n";
        cout << " Titulo: " << celebracao[i].titulo << endl;
        cout << " Data: " << celebracao[i].data << endl;
        cout << " Comentario: " << celebracao[i].comentario << endl;
        cout << "-------------------------\n";
    }
}

void deletarCelebracao () {
    vector<Celebracao> celebracao = carregamentoCelebracao();
    if (celebracao.empty()){
        cout << "Nenhuma celebração para deletar.\n";
        return;
    }

    ordenarCelebracao();
    cout << "Digite o número da celebração que deseja deletar: ";
    int num;
    cin >> num;
    cin.ignore();

    if (num < 1 || num > (int)celebracao.size()) {
        cout << "Numero invalido.\n";
        return;
    }

    celebracao.erase(celebracao.begin()+ (num-1));
    salvarCelebracao(celebracao);

    cout << "Evento deletado com sucesso.\n";
}