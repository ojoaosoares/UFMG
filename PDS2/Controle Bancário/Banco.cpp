#include "Banco.hpp"

Banco::Banco() {
    this->set_total_de_contas(0);
    this->contas_bancarias = new Conta_Bancaria*[20];

    for (int i = 0; i < 20; i++) 
        set_conta_bancaria(i, nullptr);

}

int Banco::get_total_de_contas() {
    return this->total_de_contas;
}

Conta_Bancaria* Banco::get_conta_bancaria(int index) {
    return this->contas_bancarias[index];
}

void Banco::set_total_de_contas(int total) {
    this->total_de_contas = total;
}

void Banco::set_conta_bancaria(int index, Conta_Bancaria* conta) {
    this->contas_bancarias[index] = conta;
}


Conta_Bancaria* Banco::criar_conta(int id, string cliente) {
    
    if(this->pesquisa(id)) return nullptr;
    Conta_Bancaria *nova_conta = new Conta_Bancaria(id,cliente);
    this->set_conta_bancaria(this->get_total_de_contas(),nova_conta);
    this->set_total_de_contas(this->get_total_de_contas() + 1);
    return nova_conta;
    
}

Conta_Bancaria* Banco::pesquisa(int id) {
    for (int i = 0; i < this->get_total_de_contas(); i++)
        if(get_conta_bancaria(i)->id == id) return get_conta_bancaria(i);
    
    return nullptr;
    
}

void Banco::lista_contas() {
    for (int i = 0; i < this->get_total_de_contas(); i++)
        get_conta_bancaria(i)->imprime();
    
}