#include <stdio.h>
#include <stdlib.h>

void inverte(int *a, int *b){
    int aux = *b;
    *b = *a;
    *a = aux;
}

void imprime(int n, int *l){
    for(int i = 0; i < n; i++){
        printf("%d ", l[i]);
    }
}

void main (){
    int n, quant = 0;
    
    printf("Tamanho: ");
    scanf("%d", &n); // 9

    int *l = (int*)malloc(n*sizeof(int)); // 1 3 2 6 4 5 9 7 8

    printf("Sequencia: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &l[i]);
    }

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(l[i] > l[j]){
                inverte(&l[i], &l[j]);
                quant++;
            }
        }
    }

    imprime(n, l);
    
    printf("\nQuantidade de trocas efetuadas: %d", quant);

    free(l);
}