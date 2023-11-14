#include "Treinador.hpp"

class Campeonato {
    private:
        std::vector<Treinador*> _treinadores;
    public:
        ~Campeonato();
        void cadastrar_treinador(const std::string);
        void cadastrar_pokemon_eletrico(const int, const std::string, const std::string, const double, const double);
        void cadastrar_pokemon_aquatico(const int, const std::string, const std::string, const double, const double);
        void cadastrar_pokemon_explosivo(const int, const std::string, const std::string, const double, const double);
        void imprimir_informacoes_treinador(const int) const;
        void executar_batalha(const int, const int, const int, const int);
};


