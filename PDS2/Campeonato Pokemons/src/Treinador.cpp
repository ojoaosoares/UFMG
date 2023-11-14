#include "Treinador.hpp"


Treinador::Treinador(const std::string nome): _nome(nome) {}

Treinador::~Treinador() {
    for (const Pokemon * pokemon : this->_pokemons) delete pokemon;
}

const std::string Treinador::getNome() const {
    return this->_nome;
}

Pokemon* Treinador::getPokemon(const int idpk) const {
    return this->_pokemons[idpk];
}

void Treinador::cadastrar_pokemon_eletrico(const std::string nome, const std::string tipo_ataque, const double forca_ataque, const double potencia_raio) {
    PokemonEletrico *novo_pokemon = new PokemonEletrico(nome, tipo_ataque, forca_ataque, potencia_raio);
    this->_pokemons.push_back(novo_pokemon);
}
void Treinador::cadastrar_pokemon_aquatico(const std::string nome, const std::string tipo_ataque, const double forca_ataque, const double litros_jato) {
    PokemonAquatico *novo_pokemon = new PokemonAquatico(nome, tipo_ataque, forca_ataque, litros_jato);
    this->_pokemons.push_back(novo_pokemon);
}
void Treinador::cadastrar_pokemon_explosivo(const std::string nome, const std::string tipo_ataque, const double forca_ataque, const double temperatura_explosao) {
    PokemonExplosivo *novo_pokemon = new PokemonExplosivo(nome, tipo_ataque, forca_ataque, temperatura_explosao);
    this->_pokemons.push_back(novo_pokemon);
}

const Pokemon*  Treinador::usar_pokemon(const int idpk) const {
    return this->_pokemons[idpk];
};
void Treinador::imprimir_informacoes() const {
    std::cout << "Nome: " << this->getNome() << std::endl;
    std::cout << "----------" << std::endl;

    if(this->_pokemons.size() == 0) {
        std::cout << "Nenhum Pokemon cadastrado!" << std::endl;
        std::cout << "----------" << std::endl;
    }

    else 
        for (const Pokemon * pokemon : this->_pokemons) {
            pokemon->imprimir_informacoes();
            std::cout << "----------" << std::endl;
        }
};