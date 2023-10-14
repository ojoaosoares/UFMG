#include <iostream>
#include <string>

std::string codificar(std::string texto,std::string cifra) {

    int j = 0, c;
    std::string resultado = "";

    for (int i = 0; i < texto.length(); i++)
    {
        if(j >= cifra.length()) j = 0;

        resultado += texto[i];
        if(texto[i] >= 97 && texto[i] <= 122) {
            c = (texto[i] - 97) + (cifra[j] - 97);
            if(c > 26) c %= 26;

            resultado[i] = c + 'a';
            
        } 

        j++;

     
    }

    return resultado;

}


using namespace std;

int main() {
    
    std::string texto;
    std::string chave;

    std::getline(cin,texto);
    std::getline(cin,chave);

    cout << texto << endl;
    cout << codificar(texto,chave) << endl;



}