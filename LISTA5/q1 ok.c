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

void insercao(int n, int *l){ //O(n²)

    for(int k = 0; k < n-1; k++){
        int aux = l[k+1], i = k;

        while(l[i] > aux && i >= 0){
            l[i+1] = l[i];

            i--;
        }

        l[i+1] = aux;
    }

    imprime(n, l);
}

void selecao(int n, int *l){ //O(n²)

    for(int k = n-1; k > 0; k--){
        int pmax = 0;

        for(int i = 1; i <= k; i++){

            if(l[i] > l[pmax]){
                pmax = i;
            }

        }

        troca(&l[pmax], &l[k]);
    }

    imprime(n, l);
}

void main(){

    int n, a = 1, b = 0;
    char op;

    printf("Tamanho: ");
    scanf("%d", &n); // 10

    int *l = (int*)malloc(n*sizeof(int));

    printf("Sequencia: ");
    for(int i = 0; i < n; i++){ // 17 32 41 42 8 39 33 1 53 6
        scanf("%d", &l[i]);
    }

    printf("Ordenar usando bolha, insercao ou selecao (b/i/s)? ");
    scanf(" %c", &op);

    if(op == 'b'){
        printf("Bolha: ");
        bolha(n, l);
    }
    else if(op == 'i'){
        printf("Insercao: ");
        insercao(n, l);
    }
    else{
        printf("Selecao: ");
        selecao(n, l);
    }

    free(l);
}