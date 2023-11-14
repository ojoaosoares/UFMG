#include "PokemonAquatico.hpp"

PokemonAquatico::PokemonAquatico(const std::string nome, const std::string tipo_ataque, const double forca_ataque, const double litros_jato) : 
Pokemon::Pokemon(nome,tipo_ataque,forca_ataque), _litros_jato(litros_jato) {}

void PokemonAquatico::falar_tipo_ataque() const {
    Pokemon::falar_tipo_ataque();
    std::cout << "Splash!" << std::endl;
}

const double PokemonAquatico::calcular_dano() const {
    return this->ataque_aquatico();
}

const double PokemonAquatico::ataque_aquatico() const {
    return this->_forca_ataque + this->_litros_jato;
}