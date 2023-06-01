# include <cstdio>

class FilaInt{
    public:
        int* v;
        int tam_max, inicio, fim, count;

        FilaInt(int tamanho){//método construtor, inicializa a fila
            v = new int[tamanho];// cria vetor de inteiros com o tamanho desejado
            tam_max = tamanho;
            inicio = 0;
            fim = -1;
            count = 0;
        }

        void enfileirar(int x){//método enfileirar
            if(count < tam_max){
                fim = (fim+1)%tam_max;
                count++;
                v[fim] = x;
            }
        }

        int desenfileirar(){//método desenfileirar
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
    FilaInt fila(10);//cria fila de tamanho 10
    
    for (int i = 0; i < 10; i ++){
        fila.enfileirar (i);// 0 1 2 3 4 5 6 7 8 9
    }

    for (int i = 0; i < 5; i ++){// 0 1 2 3 4
        printf ("%d. ", fila.desenfileirar ());
    }
    
    printf ("\n");
    
    for (int i = 0; i < 5; i ++){// 5 6 7 8 9 0 1 2 3 4
        fila.enfileirar (i);
    }

    while (!fila.vazia ()){
        printf ("%d, ", fila.desenfileirar ());
    }
}