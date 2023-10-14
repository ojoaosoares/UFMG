#include "ContaBancaria.hpp"
#include <iomanip>

using namespace std;

Conta_Bancaria::Conta_Bancaria(int id, string cliente) {
    this->set_id(id);
    this->set_cliente(cliente);
    this->set_saldo(0);
}

int Conta_Bancaria::get_id() {
    return this->id;
}

string Conta_Bancaria::get_cliente() {
    return this->cliente;
}

float Conta_Bancaria::get_saldo() {
    return this->saldo;
}

void Conta_Bancaria::set_id(int id) {
    this->id = id;
}

void Conta_Bancaria::set_cliente(string cliente) {
    this->cliente = cliente;
}

void Conta_Bancaria::set_saldo(float valor) {
    this->saldo = valor;
}

void Conta_Bancaria::deposito(float valor) {
    this->set_saldo(this->get_saldo() + valor);
}

void Conta_Bancaria::saque(float valor) {
    this->set_saldo(this->get_saldo() - valor);
}

void Conta_Bancaria::pix(Conta_Bancaria *alvo, float valor) {
    this->set_saldo(this->get_saldo() - valor);
    alvo->set_saldo(alvo->get_saldo() + valor);
}

void Conta_Bancaria::imprime() {
    cout << this->get_id() << " " << this->get_cliente() << " " <<  fixed << setprecision(2) << this->get_saldo() << endl;
    
}