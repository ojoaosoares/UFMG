#include "PokemonExplosivo.hpp"

PokemonExplosivo::PokemonExplosivo(const std::string nome, const std::string tipo_ataque, const double forca_ataque, const double temperatura_explosao) : 
Pokemon::Pokemon(nome,tipo_ataque,forca_ataque), _temperatura_explosao(temperatura_explosao) {}

void PokemonExplosivo::falar_tipo_ataque() const {
    Pokemon::falar_tipo_ataque();
    std::cout << "Boom!" << std::endl;
}

const double PokemonExplosivo::calcular_dano() const {
    return this->ataque_explosivo();
}

const double PokemonExplosivo::ataque_explosivo() const {
    return this->_forca_ataque / this->_temperatura_explosao;
}