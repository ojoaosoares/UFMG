#include <iostream>
#include "TADs/ListaEncadeada/List.hpp"

int main() {

    List lista;
    int x;


    for (int i = 0; i < 10; i++) {
        cin >> x;
        lista.inserir_node(x);
    }

    lista.display();

    cin >> x;
    lista.remover_nodes(x);


    lista.display();
    




}


