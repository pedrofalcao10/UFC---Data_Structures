#include <stdio.h>
#include <stdbool.h>
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

void bolha(int n, int *l){

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){

            if(l[i] > l[j]){
                troca(&l[i], &l[j]);
            }

        }
    }

    imprime(n, l);
}

void cocktail(int n, int *l){ // funfa
    bool trocado = true;
    int inicio = 0, fim = n - 1;
 
    while(trocado){
        trocado = false;

        for(int i = inicio; i < fim; i++){
            if (l[i] > l[i + 1]) {
                troca(&l[i], &l[i + 1]);
                trocado = true;
            }
        }

        if(!trocado){
            break;
        }

        trocado = false;

        --fim;

        for(int i = fim - 1; i >= inicio; i--){
            if(l[i] > l[i + 1]) {
                troca(&l[i], &l[i + 1]);
                trocado = true;
            }
        }
        ++inicio;
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

    cocktail(n, l); //1 6 8 17 32 33 39 41 42 53

    free(l);
}
