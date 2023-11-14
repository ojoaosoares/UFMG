#include "PokemonEletrico.hpp"
#include "PokemonAquatico.hpp"
#include "PokemonExplosivo.hpp"
#include <vector>

class Treinador {
    private:
        std::string _nome;
        std::vector<Pokemon*> _pokemons;
    public:
        Treinador(const std::string);
        ~Treinador();
        const std::string getNome() const;
        Pokemon* getPokemon(const int idpk) const;
        void cadastrar_pokemon_eletrico(const std::string, const std::string, const double, const double);
        void cadastrar_pokemon_aquatico(const std::string, const std::string, const double, const double);
        void cadastrar_pokemon_explosivo(const std::string, const std::string, const double, const double);
        const Pokemon* usar_pokemon(const int) const;
        void imprimir_informacoes() const;
        


};

