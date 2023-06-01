#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void split(int n, int *l, int p){
    int i = 1, j = n-1;

    troca(&l[0], &l[p]);

    while(i <= j){
        while(l[i] < l[0]){
            i++;
        }
        while(l[j] > l[0]){
            j--;
        }
        if(i <= j){
            troca(&l[i], &l[j]);
        }
    }

    troca(&l[i-1], &l[0]);
}

void imprime(int n, int *l){
    for(int i = 0; i < n; i++){
        printf("%d ", l[i]);
    }
}

void main (){
    int n;

    printf("Tamanho da sequencia: ");
    scanf("%d", &n); // 9

    int *l = (int*)malloc(n*sizeof(int));

    printf("Sequencia: "); // 48 29 22 33 39 42 8 41 19 16
    for(int i = 0; i < n; i++){
        scanf("%d", &l[i]);
    }

    split(n, l, n/2);

    printf("Lista com split: "); // 8 29 22 33 19 16 39 42 48 41
    imprime(n, l);

    free(l);
}