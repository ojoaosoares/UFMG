#include "Reserva.hpp"

Reserva::Reserva(struct std::tm data_entrada, struct std::tm data_saida) {

    time_t entrada = mktime(&data_entrada);
    time_t saida = mktime(&data_saida);
    time_t now = std::time(0); //gera um time_t com a data atual da máquina
    
    if(entrada < now) throw reserva_excp::data_entrada_no_passado(data_entrada);
    if(entrada > saida) throw reserva_excp::data_saida_antecede_entrada(data_entrada,data_saida);
    if(saida - entrada < DIA_EM_SEGUNDOS) throw reserva_excp::periodo_muito_curto(data_entrada,data_saida);

    _data_entrada = data_entrada;
    _data_saida = data_saida;
}

struct std::tm* Reserva::get_data_entrada() { return &_data_entrada; }

struct std::tm* Reserva::get_data_saida() { return &_data_saida; }

int Reserva::comparar(Reserva& other) {
    
    time_t saida = mktime(this->get_data_saida());
    time_t entrada = mktime(this->get_data_entrada());
    time_t entrada_other = mktime(other.get_data_entrada());
    time_t saida_other = mktime(other.get_data_saida());

    if(saida < entrada_other) return -1;
    else if(saida_other < entrada) return 1;
    return 0;

}

void Reserva::print_info() {
    std::cout << "\tEntrada: " << std::put_time(get_data_entrada(), FORMATO_DATA) << ", Saida: " << std::put_time(get_data_saida(), FORMATO_DATA) << std::endl;
}