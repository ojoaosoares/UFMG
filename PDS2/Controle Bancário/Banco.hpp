#ifndef BANCO_HPP
#define BANCO_HPP
#include "ContaBancaria.hpp"

struct Banco {
    int total_de_contas;
    Conta_Bancaria **contas_bancarias;
    
    Banco();
    int get_total_de_contas();
    void set_total_de_contas(int total);
    Conta_Bancaria* get_conta_bancaria(int index);
    void set_conta_bancaria(int index, Conta_Bancaria* conta);
    Conta_Bancaria* criar_conta(int id, string cliente);
    Conta_Bancaria* pesquisa(int id);
    void lista_contas();

};


#endif