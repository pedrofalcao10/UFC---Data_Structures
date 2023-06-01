#include <stdio.h>
#include <stdlib.h>

void merge3(int n, int *l, int *a, int *b){
    //1 2 18 20   4 17 96 97   18 77 84 85
    int i = 0, j = n/3, t = 0;
    while(t < 2*n/3){
        if(i < n/3 && l[i] < l[j]){
            a[t] = l[i];
            i++;
            t++;
        }
        else if(j < (2*n)/3 && l[j] <= l[2*n/3 - 1]){
            a[t] = l[j];
            j++;
            t++;
        }
    }//1 2 4 17 18 20 96 97   18 77 84 85

    i = 0, j = (2*n)/3, t = 0;

    while(t < n){
        if(i < (2*n)/3 && a[i] < l[j]){
            b[t] = a[i];
            i++;
            t++;
        }
        else if(j < n){
            b[t] = l[j];
            j++;
            t++;
        }
    }//1 2 4 17 18 18 20 77 84 85 96 97
}

void imprime(int n, int *b){
    for(int i = 0; i < n; i++){
        printf("%d ", b[i]);
    }
}

void main (){
    int n;

    printf("Tamanho da sequencia: ");
    scanf("%d", &n); //12

    int *l = (int*)malloc(n*sizeof(int));
    int *a = (int*)malloc(n*sizeof(int));
    int *b = (int*)malloc(n*sizeof(int));

    printf("3 tercos ordenados: "); //1 2 18 20 4 17 96 97 18 77 84 85
    for(int i = 0; i < n; i++){
        scanf("%d", &l[i]);
    }

    merge3(n, l, a, b);

    printf("Lista ordenada: "); //1 2 4 17 18 20 18 77 84 85 96 97
    imprime(n, b);

    free(l);
    free(a);
    free(b);
}