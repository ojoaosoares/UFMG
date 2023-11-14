#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>


const char RETANGULO = 'R';
const char CIRCULO = 'C';
const char TRIANGULO = 'T';
const char DESENHA = 'D';
const char AREA = 'A';
const char TERMINA = 'E';


class FiguraGeometrica {
    protected:
        int x, y;
    public:
        FiguraGeometrica(int , int);
        virtual ~FiguraGeometrica();
        virtual void Desenha();
        virtual float CalcularArea() = 0;

};

FiguraGeometrica::FiguraGeometrica(int x, int y) : x(x), y(y) {
}

FiguraGeometrica::~FiguraGeometrica() {}


void FiguraGeometrica::Desenha() {
    std::cout << x << " " << y << " ";
}


class Retangulo : public FiguraGeometrica {
    
    protected:
        float largura, comprimento;

    public:
        Retangulo(int , int, float , float);
        virtual void Desenha() override;
        virtual float CalcularArea() override;
    
};

Retangulo::Retangulo(int x, int y, float comprimento, float largura) : FiguraGeometrica(x,y), largura(largura),comprimento(comprimento) {}

void Retangulo::Desenha() {
    FiguraGeometrica::Desenha();
    std::cout << "RETANGULO" << std::endl;
}

float Retangulo::CalcularArea() {
    return largura * comprimento;
}


class Circulo : public FiguraGeometrica {
    protected:
        float raio;
    public:
        Circulo(int, int, float);
        virtual void Desenha() override;
        virtual float CalcularArea() override;
        
};

Circulo::Circulo(int x, int y, float raio) : FiguraGeometrica(x,y), raio(raio) {}

void Circulo::Desenha() {
    FiguraGeometrica::Desenha();
    std::cout << "CIRCULO" << std::endl;
}

float Circulo::CalcularArea() {
    return (float) (M_PI * raio * raio);
}


class Triangulo : public FiguraGeometrica {
    protected:
        float base, altura;
    public:
        Triangulo(int , int , float , float);
        virtual void Desenha() override;
        virtual float CalcularArea() override;

};

Triangulo::Triangulo(int x, int y, float base, float altura) : FiguraGeometrica(x,y), base(base), altura(altura) {}

void Triangulo::Desenha() {
    FiguraGeometrica::Desenha();
    std::cout << "TRIANGULO" << std::endl;
}

float Triangulo::CalcularArea() {
    return (float) (base*altura)/2;
}

int main() {

    std::vector<FiguraGeometrica*> figuras_geometricas;
    int x, y, comprimento, largura, raio, base, altura;
    char comando;

    while(true) {

        std::cin >> comando;

        if(comando == TERMINA)  {
            for(FiguraGeometrica * figura : figuras_geometricas) delete figura;
            figuras_geometricas.clear();
            break;
        } 

        else if(comando == RETANGULO) {
            std::cin >> x >> y >> comprimento >> largura;
            Retangulo *novo_rentangulo = new Retangulo(x,y,comprimento,largura);
            figuras_geometricas.push_back(novo_rentangulo);
        }

        else if(comando == CIRCULO) {
            std::cin >> x >> y >> raio;
            Circulo *novo_circulo = new Circulo(x,y,raio);
            figuras_geometricas.push_back(novo_circulo);
        }

        else if(comando == TRIANGULO) {
            std::cin >> x >> y >> base >> altura;
            Triangulo *novo_triangulo = new Triangulo(x,y,base,altura);
            figuras_geometricas.push_back(novo_triangulo);
        }

        else if(comando == DESENHA) for(FiguraGeometrica * figura : figuras_geometricas) figura->Desenha();
            
        else if(comando == AREA) {
            float area_total = 0;
            for(FiguraGeometrica * figura : figuras_geometricas) area_total += figura->CalcularArea();
            std::cout << std::fixed << std::setprecision(2) << area_total << std::endl;
        }
        
    }

}

