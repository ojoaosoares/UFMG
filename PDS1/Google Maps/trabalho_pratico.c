#include <stdio.h>
#include <string.h>

struct Restaurante {
    int x,y,velocidade, distancia;
    char nome[20], preco[6];
    void atribuir(int x, int y, char* n, char* p, int v);
};

void Restaurante::atribuir(int x, int y, char* n, char* p, int v) {
    this->y = y;
    this->x = x;
    strcpy(this->nome, n);
    strcpy(this->preco, p);
    this->velocidade = v;
}

struct Rua {
    int x, y, pav;
    void atribuir(int x, int y, int p);
};

void Rua::atribuir(int x, int y, int p) {
    this->x = x;
    this->y = y;
    this->pav = p;
}

struct Cidade {
    Rua r[23][39];
};

struct Caminho {
    int x, y;
    char n,s,l,o;
    void atribuir(int x, int y);
};

void Caminho::atribuir(int x, int y) {
    this->x = x;
    this->y = y;
}

void apagarCaminho(Caminho *c) {
    (*c).atribuir(0,0);
    (*c).n = ' ';
    (*c).s = ' ';
    (*c).l = ' ';
    (*c).o = ' ';
}


void limparCaminhos(Caminho c[], int n) {
    for (int i = 0; i < n; i++)
        apagarCaminho(&c[i]);
}


void imprimirPlanoCartesiano(Cidade c) {
    printf("\n     ");
    for (int n = 1; n <= 39; n++)
        if(n < 10) printf("%d  ",n);
        else printf("%d ",n);
    
    printf("\n\n");

    for (int i = 0; i < 23; i++) {
        if(i < 9) printf("%d    ",i +1);
        else printf("%d   ",i +1);
        for (int j = 0; j < 39; j++) {
            if(c.r[i][j].pav) printf("\033[1;31m1\033[0m");
            else if(!c.r[i][j].pav) printf("\033[1;37m0\033[0m");

            printf("  ");
        }
        printf("\n");
    }
    printf("\n");
}


void imprimirRestaurantes(Restaurante r[], int n) {
    printf("---------------------------------------------\n");
        for (int i = 0; i < n; i++) {
            printf("Nome: %s Preco: %s\n",r[i].nome,r[i].preco);
            printf("Coordenadas: (%d|%d) Distância: %d\n",r[i].x+1,r[i].y+1,r[i].distancia);
            printf("Velocidade do motoboy: %d Tempo mínimo: %.2f minutos\n",r[i].velocidade,r[i].distancia/(float)r[i].velocidade);
            printf("---------------------------------------------\n");
        }
}

void capitalizar(char *s) {
    int tamanho = strlen(s);
    for (int i = 0; i < tamanho; i++) {
        if(!i && s[i] >= 97 && s[i] <= 122) s[i] -= 32;
        else if(i && s[i] >= 65 && s[i] <= 90) s[i] += 32;
    }
}

void copiarRestaurante(Restaurante *r, Restaurante *c) {
    (*c).x = (*r).x;
    (*c).y = (*r).y;
    (*c).velocidade = (*r).velocidade;
    (*c).distancia = (*r).distancia;
    strcpy((*c).nome, (*r).nome);
    strcpy((*c).preco, (*r).preco);    
}

void organizarPorRapidez(Restaurante r[], int n) {
    Restaurante menor;
    int id_menor;

    for (int i = 0; i < n; i++) {
        copiarRestaurante(&r[i],&menor);
        id_menor = i;
        for (int j = i+1; j < n; j++)
            if(r[j].distancia / (float) r[j].velocidade < menor.distancia / (float) menor.velocidade) {
                copiarRestaurante(&r[j],&menor);
                id_menor = j;
            }

        copiarRestaurante(&r[i],&r[id_menor]);
        copiarRestaurante(&menor,&r[i]);
    }
}

int preferenciaCusto (Restaurante r[],int n, char *p, Restaurante copia[]) {
    capitalizar(p);
    int cont = 0;
    for (int i = 0; i < n; i++)
        if(!strcmp(p,r[i].preco) && r[i].distancia >= 0) {
            copiarRestaurante(&r[i],&copia[cont]);
            cont++;
        }

    return cont;
}

int preferenciaTempo(Restaurante r[], int n, float limite, Restaurante copia[]) {
    int cont = 0;
    for (int i = 0; i < n; i++)
        if(r[i].distancia >= 0 && r[i].distancia/ (float) r[i].velocidade <= limite) {
            copiarRestaurante(&r[i],&copia[cont]);
            cont++;
        }

    return cont;
}

int main() {
    Cidade cidade;
    Restaurante restaurantes[23];
    FILE* ruas = fopen("ruas.txt","r+t");

    if(!ruas) {
        printf("Não foi possível abrir o arquivo ruas.txt\n");
        return 1;
    }

    int y,x,pavimento, qtd_ruas_pavimentadas = 0;

    while (!feof(ruas)) {
        pavimento = -1;
        fscanf(ruas,"%d %d %d",&x,&y,&pavimento);
        if(pavimento == -1) break;
        x--;
        y--;
        cidade.r[y][x].atribuir(x,y,pavimento);
        qtd_ruas_pavimentadas++;
    }    

    fclose(ruas);
    FILE* rest = fopen("restaurantes.txt","r+t");
    
    if(!rest) {
        printf("Não foi possível abrir o arquivo restaurantes.txt\n");
        return 1;
    }

    char nome[20],preco[7];
    int velocidade, qtd_restaurantes = 0;

    while (!feof(rest)) {
        velocidade = -1;
       fscanf(rest,"%d %d %s %s %d\n",&x,&y,nome,preco,&velocidade);
       if(velocidade == -1) break;
       x--;
       y--;
       restaurantes[qtd_restaurantes].atribuir(x,y,nome,preco,velocidade);
       qtd_restaurantes++;
    }

    fclose(rest);
    int pular_x, pular_y, cont_caminhos,continuar = 1,linha, coluna, qtd_preferencias;
    float tempo_limite;
    Caminho esquinas[qtd_ruas_pavimentadas];
    Restaurante preferencia[qtd_restaurantes];

    do {
        imprimirPlanoCartesiano(cidade);   
        printf("Digite as coordenadas da sua casa (X/Y) ");
        scanf("%d %d",&x,&y);
        x--;
        y--;

        if(!cidade.r[y][x].pav || (y <  0 || y > 22) || (x < 0 || x > 38) ) {
            printf("Este endereço não existe ou não tem pavimento, por favor forneca outro endereço\n");
            continue;
        }

        for (int c = 0; c < qtd_restaurantes; c++) {   

            limparCaminhos(esquinas,qtd_ruas_pavimentadas);
            linha= y, coluna = x;cont_caminhos = 0, pular_x =0; pular_y = 0;

            while (1) {
                if(restaurantes[c].x == coluna && restaurantes[c].y == linha) {
                    restaurantes[c].distancia = cont_caminhos;
                    break;
                }

                esquinas[cont_caminhos].atribuir(coluna,linha);
                    
                if(pular_y != 1 && cidade.r[linha-1][coluna].pav && linha-1 >= 0  && esquinas[cont_caminhos].n != 'S') esquinas[cont_caminhos].n = 'N';
                else esquinas[cont_caminhos].n = 'S';
                if(pular_y != -1 && cidade.r[linha+1][coluna].pav && linha+1 < 23 && esquinas[cont_caminhos].s != 'S') esquinas[cont_caminhos].s = 'N';
                else esquinas[cont_caminhos].s = 'S';
                if(pular_x != 1 && cidade.r[linha][coluna-1].pav && coluna-1 >= 0 && esquinas[cont_caminhos].l != 'S') esquinas[cont_caminhos].l = 'N';
                else esquinas[cont_caminhos].l = 'S';
                if(pular_x != -1 && cidade.r[linha][coluna+1].pav && coluna+1 < 39 && esquinas[cont_caminhos].o != 'S') esquinas[cont_caminhos].o = 'N';
                else esquinas[cont_caminhos].o = 'S';

                if(esquinas[cont_caminhos].n == 'N') {
                    esquinas[cont_caminhos].n = 'S';
                    pular_x = 0;
                    pular_y = -1;
                }

                else if(esquinas[cont_caminhos].s == 'N') {
                    esquinas[cont_caminhos].s = 'S';
                    pular_x = 0;
                    pular_y = 1;
                }

                else if(esquinas[cont_caminhos].l == 'N') {
                    esquinas[cont_caminhos].l = 'S';
                    pular_x = -1;
                    pular_y = 0;
                }

                else if(esquinas[cont_caminhos].o == 'N') {
                    esquinas[cont_caminhos].o = 'S';
                    pular_x = 1;
                    pular_y = 0;
                }

                else if(!cont_caminhos && esquinas[cont_caminhos].n == 'S' && esquinas[cont_caminhos].s == 'S' && esquinas[cont_caminhos].l == 'S' && esquinas[cont_caminhos].o == 'S') {
                    restaurantes[c].distancia = -1;
                    break;
                }

                else {
                    apagarCaminho(&esquinas[cont_caminhos]);
                    cont_caminhos--;
                    coluna = esquinas[cont_caminhos].x;
                    linha = esquinas[cont_caminhos].y;
                    pular_x = 0;
                    pular_y = 0;
                    continue;
                }

                coluna += pular_x;
                linha += pular_y;
                cont_caminhos++;   
            }    
        }

        printf("Preferência de custo (BARATO/CARO) ");
        scanf("%s",preco);
        qtd_preferencias = preferenciaCusto(restaurantes,qtd_restaurantes,preco,preferencia);
        organizarPorRapidez(preferencia,qtd_preferencias);
        imprimirRestaurantes(preferencia,qtd_preferencias);
        printf("Preferência de custo (BARATO/CARO) ");
        scanf("%s",preco);
        printf("Tempo máximo (minutos) ");
        scanf("%f",&tempo_limite);
        qtd_preferencias = preferenciaCusto(restaurantes,qtd_restaurantes,preco,preferencia);
        qtd_preferencias = preferenciaTempo(preferencia,qtd_preferencias,tempo_limite,preferencia);
        organizarPorRapidez(preferencia,qtd_preferencias);
        imprimirRestaurantes(preferencia,qtd_preferencias);
        printf("Se quiser continuar, digite 1 ... ");
        scanf("%d",&continuar);

    } while (continuar == 1);   
}