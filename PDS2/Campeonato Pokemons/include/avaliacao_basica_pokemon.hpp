#ifndef AVALIACAO_H
#define AVALIACAO_H

#include <iostream>
#include "Campeonato.hpp"

using namespace std;

void avaliacao_basica() {
    
    Campeonato campeonato;

    cout << "----------" << endl;

    campeonato.cadastrar_treinador("T0");
    campeonato.cadastrar_treinador("T1");

    campeonato.imprimir_informacoes_treinador(0);
    campeonato.imprimir_informacoes_treinador(1);

    cout << "----------" << endl;

    campeonato.cadastrar_pokemon_eletrico(0, "PE", "AE", 1, 1);
    campeonato.imprimir_informacoes_treinador(0);

    cout << "----------" << endl;

    campeonato.cadastrar_pokemon_aquatico(1, "PA", "AA", 1, 2);
    campeonato.cadastrar_pokemon_explosivo(1, "PX", "AX", 4, 2);
    campeonato.imprimir_informacoes_treinador(1);

    cout << "----------" << endl;

    campeonato.executar_batalha(0, 0, 1, 0);

    cout << "----------" << endl;

    campeonato.executar_batalha(1, 0, 0, 0);

    cout << "----------" << endl;

    campeonato.imprimir_informacoes_treinador(0);
    campeonato.imprimir_informacoes_treinador(1);

    cout << "----------" << endl;

}

#endif