#include <iostream>
#include "heap.hpp"

int main()
{
    int n; std::cin >> n;

    Heap heap(n);

    for (size_t i = 0; i < n; i++)
    {
        int number; std::cin >> number;
        heap.Inserir(number);
    }

    for (size_t i = 0; i < n; i++)
    {
        int number; number = heap.Remover();
        std::cout << number << " ";
    }

    std::cout << '\n';
    
    
}