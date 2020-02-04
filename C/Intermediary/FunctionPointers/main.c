#include <stdio.h>

// O typedef a seguir cria um tipo chamado 'TipoFuncao' que define um
// tipo de dado que é uma função.
// O que determina o tipo, neste caso é:
// - o tipo de retorno da função;
// - os parâmetros usados na função. Leva-se em conta a quantidade,
//     a ordem e o tipo destes parâmetros
typedef int (simpleFunction)();

typedef double (oneParameterFunction)(double);

// Cria um vetor de ponteiros para funções do tipo 'TipoFuncao'
static simpleFunction *VetorDeFuncoes[3];
static oneParameterFunction *opfVector[3];

// ***************************************************
// As três funções a seguir são do mesmo tipo de 'TipoFuncao'
int Load()
{
    // Veja o que significa a macro __FUNCTION__ em
    // https://gcc.gnu.org/onlinedocs/cpp/Standard-Predefined-Macros.html#Standard-Predefined-Macros
    printf("%s\n",     __FUNCTION__);
    return 10;
}

int Print()
{
    printf("%s\n",     __func__);
    return 20;
}
int Quit()
{
    printf("%s\n",     __func__);
    return 30;
}


double power(double value)
{
    return value * value;
}

double half(double value)
{
    return value / 2.0;
}

double triple(double value)
{
    return value  * 3.0;
}

// ***************************************************
//    Funcao que recebe um ponteiro (PonteiroParaUmaFuncao)
//    para uma função e o 'indice' do 'VetorDeFuncoes'
//  no qual será armazenado o ponteiro
// ***************************************************
void SetCallbackFunc(int indice, simpleFunction *PonteiroParaUmaFuncao)
{
    VetorDeFuncoes[indice] = PonteiroParaUmaFuncao;
}

void SetCallbackOPF(int indice, oneParameterFunction *PonteiroParaUmaFuncao)
{
    opfVector[indice] = PonteiroParaUmaFuncao;
}
// ***************************************************
int main()
{
    int opcao, retorno;

    // Faz cada um dos ponteiros do VetorDeFuncoes apontar para
    // uma função diferente
    SetCallbackFunc(0, Load);
    SetCallbackFunc(1, Print);
    SetCallbackFunc(2, Quit);

    do {
        printf("Digite sua opcao(1,2,3) :");
        scanf("%d", &opcao);
        // chama uma função a partir do vetor e obtem o retorno
        retorno = (*VetorDeFuncoes[opcao-1])();
        printf ("Retorno da função: %d\n\n", retorno);
    } while(opcao !=3);

    SetCallbackFunc()
}
