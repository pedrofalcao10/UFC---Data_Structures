#include <cstdio>

class Posicao{
    public:
        int l, c;
};

class FilaPosicao{
    public:
        Posicao* v;
        int tam_max;
        int inicio;
        int fim;
        int count;

        FilaPosicao(int tamanho){//método construtor, inicializa a fila
            v = new Posicao[tamanho];// cria vetor de inteiros com o tamanho desejado
            tam_max = tamanho;
            inicio = 0;
            fim = -1;
            count = 0;
        }

        void enfileirar(Posicao p){//método enfileirar
            if(count < tam_max){
                fim = (fim+1)%tam_max;
                count++;
                v[fim] = p;
            }
        }

        Posicao desenfileirar(){//método desenfileirar
            if(count >= 0){
                int p = inicio;
                inicio = (inicio+1)%tam_max;
                count--;
                return v[p];
            }
            throw "Impossivel retirar da fila vazia";
        }

        int vazia(){//método fila vazia
            return count == 0;
        }
};

int main (){
    
    Posicao p;
    FilaPosicao fila(10); // cria fila de tamanho 10

    for(int i = 0; i < 10; i++){
        p.l = i;
        p.c = i;
        fila.enfileirar(p);
        printf ("enfileirei linha %d. coluna %d\n", p.l, p.c);

    }

    printf("\n\nahs\n\n");

    for(int i = 0; i < 5; i++){
        p = fila.desenfileirar();
        printf ("desenfileirei linha %d. coluna %d\n", p.l, p.c);
    }
    
    printf ("\nmmmmm\n\n");
    
    for(int i = 0; i < 5; i++){
        p.l = i;
        p.c = i;
        fila.enfileirar(p);
        printf ("enfileirei linha %d. coluna %d\n", p.l, p.c);
    }

        printf ("\nmmmmm\n\n");


    while (!fila.vazia()){
        p = fila.desenfileirar();
        printf ("desenfileirei linha %d, coluna %d\n", p.l, p.c);
    }
}