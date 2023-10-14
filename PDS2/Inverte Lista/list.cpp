#include <iostream>
#include "list.hpp"

void List::insertNode(int data) {
  Node* aux = new Node;
  aux->data = data;
  aux->next = nullptr;
  if (head == nullptr) {
    head = aux;
    tail = aux;
  } else {
    tail->next = aux;
    tail = aux;
  }
}

void List::display() {
  Node *aux = head;
  while (aux != nullptr) {
    cout << aux->data << " ";
    aux = aux->next;
  }
  cout << endl;
}

// Você deverá implementar apenas esse método
// void List::inverte(){

//   Node* anterior = nullptr;
//   Node *atual = head;
//   Node *proximo;
//   if(head) proximo = head->next;
  
//   tail = atual;

//   while (atual != nullptr)
//   {
//     atual->next = anterior;
//     anterior = atual;
//     atual = proximo;
//     if(proximo) proximo = proximo->next;
    
//   }

//   head = anterior;
  
// }


void List::inverte(){

  Node* anterior = nullptr;
  Node *proximo;
  if(head) proximo = head->next;
  
  tail = head;

  while (head != nullptr)
  {
    head->next = anterior;
    anterior = head;
    head = proximo;
    if(proximo) proximo = proximo->next;
    
  }

  head = anterior;
  
}