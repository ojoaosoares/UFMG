#include <iostream>
#include <cmath>
#include <iomanip>

float media(float *a, int qtd) {
    float soma = 0;
    for (int i = 0; i < qtd; i++)
        soma += a[i];
    

    return soma/qtd;
    
}

float desvioPadrao(float *a, int qtd, float media) {

    float soma = 0;
    for (int i = 0; i < qtd; i++)
        soma += pow(a[i] - media,2);

    return sqrt(soma/qtd);
    
}



int main() {

    int n;
    std::cin >> n;
    float *arranjo = new float[n];

    for (int i = 0; i < n; i++)
        std::cin >> arranjo[i];

    std::cout << std::fixed << std::setprecision(4);
    std::cout << media(arranjo, n) << std::endl;
    std::cout << std::fixed << std::setprecision(4);
    std::cout << desvioPadrao(arranjo,n,media(arranjo,n)) << std::endl;


    


}