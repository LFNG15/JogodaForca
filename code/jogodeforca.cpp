#include <iostream>
#include <string>
#include <time.h>
#define INITIAL 0
#define END 5

using namespace std;

void limpaTela()
{
    system("CLS");
}

string retornaPalavraAleatoria()
{
    string palavras[3] = {"Abacaxi", "Morango", "Uva"};

    int indiceAleatorio = rand() % 3;
    // cout << palavras[indiceAleatorio];

    return palavras[indiceAleatorio];
}

string retornaPalavraComMascara(string palavra, int tamanhoDaPalavra)
{
    int cont = INITIAL;
    string palavraComMascara;

    while (cont < tamanhoDaPalavra)
    {
        palavraComMascara += "_";
        cont++;
    }

    return palavraComMascara;
}

void exibeStatus(string palavraComMascara, int tamanhoDaPalavra, int tentativasRestantes)
{

    // cout << "A palavra secreta: " << palavra << "(Tamanho:" << tamanhoDaPalavra << ")";
    cout << "Palavra: " << palavraComMascara << "(Tamanho:" << tamanhoDaPalavra << ")";
    cout << "\nTentativas restantes:" << tentativasRestantes;
}

void jogarSozinho()
{
    string palavra = retornaPalavraAleatoria();

    int tamanhoDaPalavra = palavra.size();
    string palavraComMascara = retornaPalavraComMascara(palavra, tamanhoDaPalavra);

    int tentativas = INITIAL, maximoDeTentativas = END;
    char letra;

    while (maximoDeTentativas - tentativas > INITIAL)
    {
        limpaTela();
        
        exibeStatus(palavraComMascara, tamanhoDaPalavra, maximoDeTentativas - tentativas);

        cout << "Digite uma letra:";
        cin >> letra;

        tentativas++;
    }
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
            jogarSozinho();
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

int main()
{
    srand((unsigned)time(NULL));
    menuInicial();
    return 0;
}