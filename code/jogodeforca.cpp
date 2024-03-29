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

void exibeStatus(string palavraComMascara, int tamanhoDaPalavra, int tentativasRestantes, string letrasJaArriscadas, string mensagem)
{

    // cout << "A palavra secreta: " << palavra << "(Tamanho:" << tamanhoDaPalavra << ")";
    cout << mensagem;
    cout << "\nPalavra: " << palavraComMascara << "(Tamanho:" << tamanhoDaPalavra << ")";
    cout << "\nTentativas restantes:" << tentativasRestantes;

    int cont;
    cout << "\nLetras arriscadas:";
    for (cont = 0; cont < letrasJaArriscadas.size(); cont++)
    {
        cout << letrasJaArriscadas[cont] << ", ";
    }
}

void jogarSozinho()
{
    string palavra = retornaPalavraAleatoria();

    int tamanhoDaPalavra = palavra.size();
    string palavraComMascara = retornaPalavraComMascara(palavra, tamanhoDaPalavra);

    int tentativas = INITIAL, maximoDeTentativas = END;
    int cont = INITIAL;
    char letra;
    string letrasJaArriscadas;
    string mensagem = "Bem vindo ao jogo";
    bool jáDigitouLetra = false, acertouLetra = false;

    while (palavra != palavraComMascara && maximoDeTentativas - tentativas > INITIAL)
    {
        limpaTela();

        exibeStatus(palavraComMascara, tamanhoDaPalavra, maximoDeTentativas - tentativas, letrasJaArriscadas, mensagem);

        cout << "Digite uma letra:";
        cin >> letra;

        for (cont = 0; cont < tentativas; cont++)
        {
            if (letrasJaArriscadas[cont] == letra)
            {
                mensagem = "Essa letra já foi digitada";
                jáDigitouLetra = true;
            }
        }

        if (jáDigitouLetra == false)
        {
            letrasJaArriscadas += letra;

            for (cont = 0; cont < tamanhoDaPalavra; cont++)
            {
                if (palavra[cont] == letra)
                {
                    palavraComMascara[cont] = palavra[cont];

                    acertouLetra = true;
                }
            }
            if (acertouLetra == false)
            {
                mensagem = "Você errou uma letra";
            }
            else
            {
                mensagem = "Você acertou uma letra";
            }
            tentativas++;
        }
        jáDigitouLetra = false;
        acertouLetra = false;
    }

    if (palavra == palavraComMascara)
    {
        limpaTela();
        cout << "Parabéns";
    }
    else
    {
        limpaTela();
        cout << "Tu é burro falante  é?";
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