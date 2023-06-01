#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int meiabolha(int n, int *l){
    int exec1 = 0;

    for(int i = 0; i < n/2; i++){
        for(int j = i+1; j < n/2; j++){

            if(l[i] > l[j]){
                troca(&l[i], &l[j]);
                exec1++;
            }

        }
    }

    for(int i = n/2; i < n; i++){
        for(int j = i+1; j < n; j++){

            if(l[i] > l[j]){
                troca(&l[i], &l[j]);
                exec1++;
            }

        }
    }

    return exec1;
}

int merge(int n, int *l, int *a){
    int exec2 = 0;
    int i = 0, j = n/2, k = 0;

    while(k < n){
        if(i < n/2 && l[i] < l[j]){
            a[k] = l[i];
            i++;
            k++;

            exec2++;
        }
        else{
            if(j < n){
                a[k] = l[j];
                j++;
                k++;

                exec2++;
            }
        }
    }

    return exec2;
}

void imprime(int n, int *l){
    for(int i = 0; i < n; i++){
        printf("%d ", l[i]);
    }
}

void main(){

    int n;

    printf("Tamanho: ");
    scanf("%d", &n); // 10

    int *l = (int*)malloc(n*sizeof(int));
    int *a = (int*)malloc(n*sizeof(int));

    printf("Sequencia: ");
    for(int i = 0; i < n; i++){ // 17 32 41 42 8 39 33 1 53 6
        scanf("%d", &l[i]);
    }

    printf("Numero de execucoes da ordenacao das duas metades: %d\n", meiabolha(n, l));
    printf("Ordenacao das duas metades: ");
    imprime(n, l);
    puts("");

    printf("\nNumero de execucoes da Merge das duas metades: %d\n", merge(n, l, a));
    printf("Merge das duas metades: ");
    imprime(n, a);
    puts("\n");

    free(l);
    free(a);
}