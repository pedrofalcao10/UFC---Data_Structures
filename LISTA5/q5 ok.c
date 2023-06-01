#include <stdio.h>

void troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void insercao(int n, int *l){
    for (int i = 1; i < n; i++){ 
        int key = l[i], j = i-1;; 

        for(; j >= 0 && l[j] > key; j--){
            l[j + 1] = l[j];
        }
        
        l[j + 1] = key; 
    } 
}

void ordem3invertida(int n, int *l){

    insercao(n, l);

    for(int i = 0; i < n; i +=3){
        troca(&l[i], &l[i+2]);
    }
}

void imprime3(int n, int *l){
    for(int i = 0; i <= n-3; i += 3){
        printf("%d %d %d   ", l[i], l[i+1], l[i+2]);
    }
}

void main (){
    int n;

    printf("Tamanho (M3): "); //12
    scanf("%d", &n);

    int *l = (int*)malloc(n*sizeof(int));

    printf("Sequencia: "); // 17 32 41 42 8 39 33 1 53 6 13 8
    for(int i = 0; i < n; i++){
        scanf("%d", &l[i]);
    }

    ordem3invertida(n, l);

    imprime3(n, l);
}