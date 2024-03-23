#include <iostream>
#include <string>
#define INITIAL 0
using namespace std;

void limpaTela(){
    system("CLS");
}

void menuInicial()
{
    int opcao = INITIAL;

    while (opcao < 1 || opcao > 3)
    {
        limpaTela();
        cout << "Bem vindo ao jogo";
        cout << "\n1 - Jogar";
        cout << "\n2 - Sobre";
        cout << "\n3 - Sair";

        cout << "\nEscolha a opcção e tecle ENTER";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "Jogo iniciado";
            break;
        case 2:
            cout << "Informação do Jogo";
            break;
        case 3:
            cout << "Saindo do Jogo";
            break;
        }
    }
}

int main(){
    menuInicial();
    return 0;
}