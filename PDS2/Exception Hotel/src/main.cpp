#include "Hotel.hpp"
#include <iostream>


int main() {

    char comando;
    Hotel hotel;
    while (std::cin >> comando)
    {
        try
        {

            if(comando == 'a') {
                int n_quarto;
                struct std::tm input_date = {};
                struct std::tm output_date = {};

                std::cin >> n_quarto;
                std::cin >> std::get_time(&input_date, FORMATO_DATA);
                std::cin >> std::get_time(&output_date, FORMATO_DATA);

                hotel.adiciona_reserva(n_quarto,input_date,output_date);
            }


            else if (comando == 'r') {
                int n_quarto;
                struct std::tm input_date = {};

                std::cin >> n_quarto;
                std::cin >> std::get_time(&input_date, FORMATO_DATA);

                hotel.remove_reserva(n_quarto,input_date);

            }  

            else if (comando == 'p') hotel.print_info();
            

        }
        catch(const reserva_excp::data_entrada_no_passado& e)
        {
            std::cerr << e.what() <<  ": " <<  std::put_time(e.get_data_entrada(), FORMATO_DATA) << '\n';
        }
        catch(const reserva_excp::data_saida_antecede_entrada& e)
        {
            std::cerr << e.what() <<  ": " <<  std::put_time(e.get_data_entrada(), FORMATO_DATA) <<", " << std::put_time(e.get_data_saida(), FORMATO_DATA) << '\n';
        }

        catch(const reserva_excp::periodo_muito_curto& e)
        {
            std::cerr << e.what() <<  ": " <<  std::put_time(e.get_data_entrada(), FORMATO_DATA) <<", " << std::put_time(e.get_data_saida(), FORMATO_DATA) << '\n';
        }

        catch(const quarto_excp::reserva_nao_encontrada& e)
        {
            std::cerr << e.what() <<  " no quarto " << e.get_n_quarto()<< ": " << std::put_time(e.get_data_entrada(), FORMATO_DATA) << '\n';
        }

        catch(const quarto_excp::reserva_indisponivel& e)
        {
            std::cerr << e.what() <<  " de " << std::put_time(e.get_data_entrada(), FORMATO_DATA) << " a " << std::put_time(e.get_data_saida(), FORMATO_DATA) << '\n';
        }

        catch(const hotel_excp::quarto_nao_existe& e)
        {
            std::cerr << e.what() <<  ": quarto " << e.get_n_quarto() << '\n';
        }

        catch(const hotel_excp::quarto_nao_criado& e)
        {
            std::cerr << e.what() <<  ": quarto " << e.get_n_quarto() << '\n';
        }
        
    }
    
}