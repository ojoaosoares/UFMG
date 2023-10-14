#ifndef LiSTA_H
#define LISTA_H

#include <iostream>

using namespace std;

struct Node {

    int data;
    Node *next;
};

struct List {
    Node *head = nullptr;
    Node *tail = nullptr;
    
    void inserir_node(int valor);
    void remover_nodes(int valor);
    void display();
    void inverte();

};

#endif