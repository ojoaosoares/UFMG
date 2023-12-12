#ifndef RESERVA_EXCEPTIONS_H
#define RESERVA_EXCEPTIONS_H

#include <stdexcept>
#include <iomanip>

namespace reserva_excp {


    class Reserva_Exceptions : public std::exception {
        
        public :
            Reserva_Exceptions(struct std::tm data_entrada) : data_entrada(data_entrada) {};
            virtual ~Reserva_Exceptions() {};
            virtual const char* what() const throw() = 0;
            const struct std::tm* get_data_entrada() const { return &data_entrada; }
            
        protected:
            struct std::tm data_entrada;
            
            
    };

    class data_entrada_no_passado : public Reserva_Exceptions {

        public :
            data_entrada_no_passado(struct std::tm data_entrada) : Reserva_Exceptions(data_entrada) {};
            const char* what() const throw() override { return "Data de entrada esta no passado"; };
            
    };


    class data_saida_antecede_entrada : public Reserva_Exceptions {

        public :
            data_saida_antecede_entrada(struct std::tm data_entrada, struct std::tm data_saida) : Reserva_Exceptions(data_entrada), data_saida(data_saida) {};
            const char* what() const throw() override { return "Data saida nao pode ser menor que a data entrada"; };
            const struct std::tm *get_data_saida() const { return &data_saida; };

        private:
            struct std::tm data_saida;
    };

    class periodo_muito_curto : public Reserva_Exceptions {

        public :
            periodo_muito_curto(struct std::tm data_entrada, struct std::tm data_saida) : Reserva_Exceptions(data_entrada), data_saida(data_saida) {};
            const char* what() const throw() override { return "Reserva deve ter duracao minima de 1 dia"; };
            const struct std::tm *get_data_saida() const { return &data_saida; };
        private:
            struct std::tm data_saida;
    };

    
};



#endif