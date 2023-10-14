#ifndef CONTA_BANCARIA_HPP
#define CONTA_BANCARIA_HPP

#include <iostream>
#include <string>

using namespace std;

struct Conta_Bancaria {

    int id;
    string cliente;
    float saldo;

    Conta_Bancaria(int id, string cliente);
    int get_id();
    string get_cliente();
    float get_saldo();
    void set_id(int id);
    void set_cliente(string cliente);
    void set_saldo(float valor);
    void deposito(float valor);
    void saque(float valor);
    void pix(Conta_Bancaria *alvo, float valor);
    void imprime();

};

#endif