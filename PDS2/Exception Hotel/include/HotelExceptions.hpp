#ifndef HOTEL_EXCEPTIONS_H
#define HOTEL_EXCEPTIONS_H

#include <stdexcept>
#include <iomanip>


namespace hotel_excp {

    class Hotel_Exceptions : public std::exception {
    
        public:
            Hotel_Exceptions(int n_quarto) : n_quarto(n_quarto) {};
            virtual ~Hotel_Exceptions() {};
            virtual const char* what() const throw() = 0;
            virtual const int get_n_quarto() const { return n_quarto; };    

        protected:
            int n_quarto;

    };

    class quarto_nao_existe : public Hotel_Exceptions {

        public:
            quarto_nao_existe(int n_quarto) : Hotel_Exceptions(n_quarto) {};
            const char* what() const throw() override { return "Numero do quarto informado nao pertence a colecao"; }; 

    };

    class quarto_nao_criado : public Hotel_Exceptions {

        public:
            quarto_nao_criado(int n_quarto) : Hotel_Exceptions(n_quarto) {};
            const char* what() const throw() override { return "Quarto ainda nao foi adicionado a lista"; };

    };
    
    
    
}




#endif