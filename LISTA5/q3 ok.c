#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void imprime(int n, int *l){
    for(int i = 0; i < n; i++){
        printf("%d ", l[i]);
    }
}

void ordena_par(int n, int *l){ //insertion

    for(int k = 0; k < n-1; k += 2){
        int aux = l[k+2], i = k;

        while(l[i] > aux && i >= 0){
            l[i+2] = l[i];

            i -= 2;
        }

        l[i+2] = aux;
    }

    imprime(n, l);
}

void ordena_impar(int n, int *l){ //bubble
    
    for(int i = 1; i < n; i += 2){
        for(int j = i+2; j < n; j +=2){

            if(l[i] > l[j]){
                troca(&l[i], &l[j]);
            }

        }
    }

    imprime(n, l);
}

void main(){

    int n;

    printf("Tamanho: ");
    scanf("%d", &n); // 10

    int *l = (int*)malloc(n*sizeof(int));

    printf("Sequencia: ");
    for(int i = 0; i < n; i++){ // 17 32 41 42 8 39 33 1 53 6
        scanf("%d", &l[i]);
    }

    printf("Ordenacao das posicoes pares: ");
    ordena_par(n, l); //8 32 17 42 33 39 41 1 53 6
    puts("\n");

    printf("Ordenacao das posicoes impares (pos ordenacao das pares): ");
    ordena_impar(n, l); //8 1 17 6 33 32 41 39 53 42
    puts("\n");

    free(l);
}