#include "List.hpp"

void List::inserir_node(int valor) {

    Node *novo = new Node;
    novo->data = valor;
    novo->next = nullptr;


    if(head == nullptr) {
        head = novo;
        tail = novo;
    }
    else {
        tail->next = novo;
        tail = novo;
    }


}

void List::remover_nodes(int valor) {

    Node *current = head, *previous = nullptr;

    while(current != nullptr) {

        if(current->data == valor) {

            if (current->next == nullptr && previous == nullptr) {
                head = nullptr;
                tail = nullptr;
            }
            else if(previous == nullptr) head = current->next;

            else if(current->next == nullptr) {
                previous->next = nullptr;
                tail = previous;
            }

            else previous->next = current->next;

            delete current;

            return;
            

        }

        previous = current;
        current = current->next;
    }
    
}


void List::display() {

    for (Node *current = head; current != nullptr; current = current->next)
        cout << current->data << " ";
    
    cout << endl;
    

}


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