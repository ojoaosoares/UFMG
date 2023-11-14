// NÃO ALTERE ESSA LINHA
#include "avaliacao_basica_pokemon.hpp"

const char CADASTRAR_TREINADOR = 't';
const char IMPRIMIR_TREINADOR = 'i';
const char ADICIONAR_POKEMON_ELETRICO = 'e';
const char ADICIONAR_POKEMON_AQUATICO = 'q';
const char ADICIONAR_POKEMON_EXPLOSIVO = 'x';
const char REALIZAR_BATALHA = 'h';
const char AVALIACAO_BASICA = 'b';

int main() {

    char comando;
    Campeonato camp;
    int idt1, idt2, idpk1, idpk2;
    std::string nome, nome_pokemon, tipo_ataque;    
    double forca_ataque, potencia_raio, litros_jato, temeperatura_explosao;
    
    while(std::cin >> comando) {
        
        if(comando == CADASTRAR_TREINADOR) {
            std::cin >> nome;
            camp.cadastrar_treinador(nome);
        }

        else if(comando == IMPRIMIR_TREINADOR) {
            std::cin >> idt1;
            camp.imprimir_informacoes_treinador(idt1);
        }

        else if(comando == ADICIONAR_POKEMON_ELETRICO) {
            std::cin >> idt1 >> nome_pokemon >> tipo_ataque >> forca_ataque >> potencia_raio;
            camp.cadastrar_pokemon_eletrico(idt1,nome_pokemon,tipo_ataque,forca_ataque,potencia_raio);

        }

        else if(comando == ADICIONAR_POKEMON_AQUATICO) {
            std::cin >> idt1 >> nome_pokemon >> tipo_ataque >> forca_ataque >> litros_jato;
            camp.cadastrar_pokemon_aquatico(idt1,nome_pokemon,tipo_ataque,forca_ataque,litros_jato);

        }

        else if(comando == ADICIONAR_POKEMON_EXPLOSIVO) {
            std::cin >> idt1 >> nome_pokemon >> tipo_ataque >> forca_ataque >> temeperatura_explosao;
            camp.cadastrar_pokemon_explosivo(idt1,nome_pokemon,tipo_ataque,forca_ataque,temeperatura_explosao);

        }

        else if(comando == REALIZAR_BATALHA) {
            std::cin >> idt1 >> idpk1 >> idt2 >> idpk2;
            camp.executar_batalha(idt1,idpk1,idt2,idpk2);
        }

        else if(comando == AVALIACAO_BASICA) avaliacao_basica();

    }
    
    return 0;
}