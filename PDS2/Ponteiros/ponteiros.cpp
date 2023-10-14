#include <iostream>

using namespace std;

int main(){

    // 1) Declare uma variável do tipo inteiro e preencha com o valor informado na entrada
    int n;
    cin >> n;
    
    
    // 2) Declare um ponteiro para inteiros e inicialize com valor nulo
    int *inteiro_pointer = nullptr;

    // 3) Declare um vetor de inteiros com tamanho informado na entrada e preencha com dados lidos da entrada
    int tamanho;
    cin >> tamanho;
    int *inteiro_vetor = new int[tamanho];
    for (int i = 0; i < tamanho; i++)
        cin >> inteiro_vetor[i];
    

    // 4) Imprima o ENDEREÇO da variável declarada em (1)
    cout << &n << endl;

    // 5) Imprima o VALOR da variável declarada em (1)
    cout << n << endl;

    // 6) Imprima o ENDEREÇO da variável declarada em (2)
    cout << &inteiro_pointer << endl;
    
    // 7) Imprima o VALOR da variável declarada em (2)
    cout << inteiro_pointer << endl;

    // 8) Imprima o ENDEREÇO da variável declarada em (3)
    cout << inteiro_vetor << endl;

    // 9) Imprima o ENDEREÇO da primeira posição da variável declarada em (3)
    cout << inteiro_vetor << endl;

    // 10) Imprima o VALOR da primeira posição da variável declarada em (3)
    cout << inteiro_vetor[0] << endl;

    // 11) Atribua o ENDEREÇO da variável declarada em (1) à variável declarada em (2)
    inteiro_pointer = &n;

    // 12) Imprima o VALOR da variável declarada em (2)
    cout << inteiro_pointer << endl;

    // 13) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *inteiro_pointer << endl;

    // 14) Compare ENDEREÇO de (1) e o VALOR de (2), imprimindo 'S' se forem iguais e 'N' se forem diferentes
    if(&n == inteiro_pointer) cout << "S" << endl;
    else cout << "N" << endl;
    

    // 15) Coloque o VALOR '5' no ENDEREÇO apontado por (2)
    *inteiro_pointer = 5;

    // 16) Imprima o VALOR da variável declarada em (1)
    cout << n << endl;

    // 17) Atribua o VALOR da variável (3) à variável declarada em (2)
    inteiro_pointer = inteiro_vetor;
    

    // 18) Imprima o VALOR da variável declarada em (2)
    cout << inteiro_pointer << endl;

    

    // 19) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *inteiro_pointer << endl;


    // 20) Atribua o ENDEREÇO da primeira posição de (3) à variável declarada em (2)
    inteiro_pointer = inteiro_vetor;


    // 21) Imprima o VALOR da variável declarada em (2)
    cout << inteiro_pointer << endl;

    // 22) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *inteiro_pointer << endl;

    // 23) Multiplique todos os valores do vetor declarado em (3) por '10', porém manipulando apenas a variável (2)
    for (int i = 0; i < tamanho; i++)
        *(inteiro_pointer+i) *= 10;
    
    
    

    // 24) Imprima os elementos de (3) a partir variável do vetor utilizando a notação [] (colchetes)
    for (int i = 0; i < tamanho; i++) {
        cout << (inteiro_pointer[i]);
        if((i+1) != tamanho) cout << " ";
    }

    cout << endl;
    

    // 25) Imprima os elementos de (3) a partir variável do vetor utilizando a notação ponteiro/deslocamento
    // Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (3)
    for (int i = 0; i < tamanho; i++) {
        cout << *(inteiro_vetor+i);
        if((i+1) != tamanho) cout << " ";
    }
    cout << endl;


    // 26) Imprima os elementos de (3) utilizando a variável (2) e a notação ponteiro/deslocamento
    // Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (3)
    for (int i = 0; i < tamanho; i++) {
        cout << *(inteiro_pointer+i);
        if((i+1) != tamanho) cout << " ";
    }
    cout << endl;

    // 27) Atribua o ENDEREÇO da quinta posição de (3) à variável declarada em (2)
    inteiro_pointer = &inteiro_vetor[4];
    

    // 28) Imprima o VALOR da variável declarada em (2)
    cout << inteiro_pointer << endl;
    

    // 29) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *inteiro_pointer << endl;

    // 30) Declare um ponteiro para ponteiro e o inicialize com o ENDEREÇO da variável (2)
    int **pointer_pointer = &inteiro_pointer;
    

    // 31) Imprima o VALOR da variável declarada em (30)
    cout << pointer_pointer << endl;
    

    // 32) Imprima o ENDEREÇO da variável declarada em (30)
    cout << &pointer_pointer << endl;

    // 33) Imprima o VALOR guardado no ENDEREÇO apontado por (30)
    cout << *pointer_pointer << endl;
    

    // 34) Imprima o VALOR guardado no ENDEREÇO do ponteiro apontado por (30)
    cout << **pointer_pointer << endl;


    delete[] inteiro_vetor;


    return 0;
}