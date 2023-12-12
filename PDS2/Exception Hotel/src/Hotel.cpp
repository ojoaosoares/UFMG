#include "Hotel.hpp"

Hotel::Hotel() {}

Hotel::~Hotel() {

    for (Quarto* q : *(get_quartos()))
        delete q;

    _quartos.clear();
}


Quarto* Hotel::get_quarto_pelo_n(int n_quarto) {

    for (Quarto* q : *(get_quartos()))
        if (q->get_n_quarto() == n_quarto)
            return q;
        
    throw hotel_excp::quarto_nao_criado(n_quarto);
    
}

std::vector<Quarto*>* Hotel::get_quartos() { return &_quartos; }

void Hotel::adiciona_reserva(int n_quarto, struct std::tm data_entrada, struct std::tm data_saida) {

    if(n_quarto < 0 || n_quarto > 5) throw hotel_excp::quarto_nao_existe(n_quarto);
    
    for (Quarto* q : *(get_quartos()))
        if (q->get_n_quarto() == n_quarto) {
            q->adiciona_reserva(data_entrada,data_saida);
            return;
        }
    
    Quarto* novo_quarto = new Quarto(n_quarto);
    novo_quarto->adiciona_reserva(data_entrada,data_saida);

    get_quartos()->push_back(novo_quarto);

}



void Hotel::remove_reserva(int n_quarto, struct std::tm data_entrada) {
    
    if(n_quarto < 0 || n_quarto > 5) throw hotel_excp::quarto_nao_existe(n_quarto);

    std::vector<Quarto*> *copia = get_quartos();

    for (std::vector<Quarto*>::iterator it = copia->begin(); it != copia->end(); it++)
        if ((*it)->get_n_quarto() == n_quarto) {
            (*it)->remove_reserva(data_entrada);

            if(((*it)->get_reservas())->size() < 1) {
                delete (*it);
                copia->erase(it);
            }

            return;
        }

    throw hotel_excp::quarto_nao_criado(n_quarto);
            
            
}


void Hotel::print_info() {

    for (Quarto* q : *(get_quartos()))
        q->print_info();
    
}

