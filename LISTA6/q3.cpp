#include <cstdio>

int n;

class Posicao{
    public :
        int l;
        int c;
};

class FilaPosicao{
    public:
        Posicao* v;
        int tam_max, ini, fim, cont;

        FilaPosicao(int tamanho){// método construtor, inicializa a fila
            v = new Posicao [tamanho]; // cria vetor de posicoes com o tamanho desejad
            tam_max = tamanho;
            ini = 0;
            fim = -1;
            cont = 0;
        }

        void enfileirar(Posicao p){// método enfileirar
            if(cont < tam_max){
                fim = (fim + 1)%tam_max;
                v[fim] = p;
                cont++;
            }
        }

        Posicao desenfileirar(){// método desenfileirar
            Posicao p;
            if(cont >= 0){
                p = v[ini];
                ini = (ini + 1)%tam_max;
                cont--;
            }
            return p;
        }

        int vazia() const{// método fila vazia
            return cont == 0;
        }
};

Posicao p, q;

void dist(int** M, int** D, FilaPosicao f){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(M[i][j] == 1){
                D[i][j] = 0;
                p.l = i;
                p.c = j;
                f.enfileirar(p);
            }
        }
    }

    while(!f.vazia()){
        p = f.desenfileirar();

        if(p.l - 1 >= 0 && D[p.l-1][p.c] == -1){
            D[p.l-1][p.c] = D[p.l][p.c] + 1;
            q.l = p.l - 1;
            q.c = p.c;
            f.enfileirar(q);
        }

        if(p.l + 1 < n && D[p.l+1][p.c] == -1){
            D[p.l+1][p.c] = D[p.l][p.c] + 1;
            q.l = p.l + 1;
            q.c = p.c;
            f.enfileirar(q);
        }

        if(p.c - 1 >= 0 && D[p.l][p.c-1] == -1){
            D[p.l][p.c-1] = D[p.l][p.c] + 1;
            q.l = p.l;
            q.c = p.c - 1;
            f.enfileirar(q);
        }

        if(p.c + 1 < n && D[p.l][p.c+1] == -1){
            D[p.l][p.c+1] = D[p.l][p.c] + 1;
            q.l = p.l;
            q.c = p.c + 1;
            f.enfileirar(q);
        }
    }
}

int main(){

    printf("n = ");
    scanf("%d", &n);

    int** Mat = new int* [n];
    int** Dist = new int* [n];

    for(int i = 0; i < n; i++){
        Mat[i] = new int [n];
        Dist[i] = new int [n];
    }

    for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                scanf("%d", &Mat[i][j]);
            }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            Dist[i][j] = -1;
        }
    }

    FilaPosicao f(n*n);

    dist(Mat, Dist, f);

    printf("\n");

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", Dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}