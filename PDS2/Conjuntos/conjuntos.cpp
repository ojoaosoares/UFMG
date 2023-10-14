#include <iostream>
#include <set>

#define NUMERO_DE_CONJUNTOS 2
#define CONJUNTO_UM 0
#define CONJUNTO_DOIS 1
#define CONDICAO_DE_PARADA -1


using namespace std;

int main() {

    set<int> *conjuntos = new set<int>[NUMERO_DE_CONJUNTOS];
    set<int> uniao;
    set<int> intersecao;
    
    int item;

    for (int i = 0; i < 2; i++)
        while(true) {
            cin >> item;
            if (item == CONDICAO_DE_PARADA) break;
            conjuntos[i].insert(item);
        }
    

    set<int>::iterator it;
    for (it = conjuntos[CONJUNTO_UM].begin(); it != conjuntos[CONJUNTO_UM].end(); it++)
        if(conjuntos[CONJUNTO_DOIS].find(*it) != conjuntos[CONJUNTO_DOIS].end()) 
            intersecao.insert(*it);



    for (int i = 0; i < 2; i++) {
        for (it = conjuntos[i].begin(); it != conjuntos[i].end(); it++)
            uniao.insert(*it);
    }
    

    for (int i = 0; i < 2; i++) {
        for (it = conjuntos[i].begin(); it != conjuntos[i].end(); it++)
            cout << *it << " ";

        cout << endl;
    }


    for (int i : uniao)
        cout << i << " ";

    cout << endl;

    for (int i : intersecao)
        cout << i << " ";

    cout << endl;

    delete[] conjuntos;
       

    
    
}