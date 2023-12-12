#include "Quarto.hpp"

Quarto::Quarto(int n_quarto) : _n_quarto(n_quarto) {}

Quarto::~Quarto() {

    for (Reserva* r : *(get_reservas()))
        delete r;
    
    _reservas.clear();
    
}

int Quarto::get_n_quarto() { return _n_quarto; }

std::vector<Reserva*>* Quarto::get_reservas() { return &_reservas; }

void Quarto::adiciona_reserva(struct std::tm data_inicio, struct std::tm data_saida) {
    
    int resultado;
    std::vector<Reserva*>* vetor_copia  =  get_reservas();
    Reserva* novo = new Reserva(data_inicio,data_saida);

    for(std::vector<Reserva*>::iterator it = vetor_copia->begin(); it != vetor_copia->end(); it++) {
        resultado = (*it)->comparar(*novo);
        if(resultado == 0) {
            delete novo;
            throw quarto_excp::reserva_indisponivel(data_inicio,data_saida);
        }

        else if(resultado == 1) {
            vetor_copia->insert(it,novo);
            return;
        }
    }

    vetor_copia->push_back(novo);
    
}

void Quarto::remove_reserva(struct std::tm data_inicio) {

    time_t entrada = mktime(&data_inicio);
    std::vector<Reserva*> *vetor_copia =  (get_reservas());

    for(std::vector<Reserva*>::iterator it = vetor_copia->begin(); it != vetor_copia->end(); it++)
        if(mktime((*it)->get_data_entrada()) ==  entrada) {
            delete (*it);
            vetor_copia->erase(it);
            return;
        }
    
    throw quarto_excp::reserva_nao_encontrada(get_n_quarto(),data_inicio);

}

void Quarto::print_info() {
    
    std::vector<Reserva*> vetor_copia =  *(get_reservas());
    std::cout << "Quarto  " << get_n_quarto() << "  ---------" << std::endl;

    for(std::vector<Reserva*>::iterator it = vetor_copia.begin(); it != vetor_copia.end(); it++)
        (*it)->print_info();

    std::cout << "------------------" << std::endl;
    
}