#include "Campeonato.hpp"

Campeonato::~Campeonato() {
    for(const Treinador* treinador : _treinadores) delete treinador;
}

void Campeonato::cadastrar_treinador(const std::string nome) {
    Treinador* treinador = new Treinador(nome);
    this->_treinadores.push_back(treinador);
}

void Campeonato::cadastrar_pokemon_eletrico(const int idt, const std::string nome, const std::string tipo_ataque, const double forca_ataque, const double potencia_raio) {
    this->_treinadores[idt]->cadastrar_pokemon_eletrico(nome,tipo_ataque,forca_ataque,potencia_raio);
}
void Campeonato::cadastrar_pokemon_aquatico(const int idt, const std::string nome, const std::string tipo_ataque, const double forca_ataque, const double litros_jato) {
    this->_treinadores[idt]->cadastrar_pokemon_aquatico(nome,tipo_ataque,forca_ataque,litros_jato);
}
void Campeonato::cadastrar_pokemon_explosivo(const int idt, const std::string nome, const std::string tipo_ataque, const double forca_ataque, const double temperatura_explosao) {
    this->_treinadores[idt]->cadastrar_pokemon_explosivo(nome,tipo_ataque,forca_ataque,temperatura_explosao);
}

void Campeonato::imprimir_informacoes_treinador(const int idt) const {
    this->_treinadores[idt]->imprimir_informacoes();
}

void Campeonato::executar_batalha(const int idt1, const int idpk1, const int idt2, const int idpk2) {
    const Pokemon* pokemon1 = this->_treinadores[idt1]->getPokemon(idpk1);
    Pokemon* pokemon2 = this->_treinadores[idt2]->getPokemon(idpk2);
    
    std::cout << "### Batalha ###" << std::endl;
    std::cout << this->_treinadores[idt1]->getNome() << " (" << pokemon1->getNome() << ") vs. " <<
    this->_treinadores[idt2]->getNome() << " (" << pokemon2->getNome() << ")" << std::endl;
    pokemon1->atacar(pokemon2);
    pokemon2->imprimir_status();
    std::cout << "#########" << std::endl;
}