#ifndef QUARTO_EXCEPTIONS_H
#define QUARTO_EXCEPTIONS_H

#include <stdexcept>
#include <iomanip>

namespace quarto_excp {
    
    class Quarto_Exceptions : public std::exception {
        
        public:
            Quarto_Exceptions(struct std::tm data_entrada) : data_entrada(data_entrada) {};
            virtual ~Quarto_Exceptions() {};
            virtual const char* what() const throw() = 0;
            virtual const struct std::tm *get_data_entrada() const { return &data_entrada; };

        protected:
            struct std::tm data_entrada;
        
    };

    class reserva_nao_encontrada : public Quarto_Exceptions {

        public:
            reserva_nao_encontrada(int n_quarto, struct std::tm data_inicio) : Quarto_Exceptions(data_inicio), n_quarto(n_quarto) {};
            const char* what() const throw() override { return "Reserva nao encontrada"; }; 
            const int get_n_quarto() const { return n_quarto; };

        private:
            int n_quarto;

    };

    class reserva_indisponivel : public Quarto_Exceptions {

        public:
            reserva_indisponivel(struct std::tm data_inicio, struct std::tm data_saida) : Quarto_Exceptions(data_inicio), data_saida(data_saida) {}
            const char* what() const throw() override { return "Existe uma reserva em alguns dos dias do periodo"; }; 
            const struct std::tm *get_data_saida() const { return &data_saida; };

        private:
            struct std::tm data_saida;

    };
    
    




}

#endif