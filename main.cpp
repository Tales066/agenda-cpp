#include <iostream>
#include "celebracao.h"

using namespace std;

int main () {
    int opcao;

    do {
        cout << "======= Agenda de celebrações ======\n";
        cout << "1. Adicionar Celebração\n";
        cout << "2. Visualizar Celebrações\n";
        cout << "3. Excluir Celebrações\n";
        cout << "0. Sair\n";
        cout << "=============== ================\n";
        cout << "Escolha uma das opções: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao)
        {
        case 1:
            adicionarCelebracao();
            break;
        case 2:
            ordenarCelebracao();
            break;
        case 3:
            deletarCelebracao();
            break;
        case 0:
            cout << "Encerrando....\n";
            break;
        default:
            cout << "Opção inválida.\n";
            break;
        }
    } while (opcao !=0);

    return 0;
}