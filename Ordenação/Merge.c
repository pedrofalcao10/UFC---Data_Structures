#include <stdio.h>
#include <stdlib.h>

void Merge(int n, int *l, int *a){
    int i = 0, j = n/2, k = 0;

    while(k < n){
        if(i < n/2 && l[i] < l[j]){
            a[k] = l[i];
            i++;
            k++;
        }
        else{
            if(j < n){
                a[k] = l[j];
                j++;
                k++;
            }
        }
    }
}

void main (){
    int n, x;

    printf("Tamanho da sequencia: ");
    scanf("%d", &n);

    float *l = (float*)malloc(n*sizeof(float));
    float *a = (float*)malloc(n*sizeof(float));

    printf("Primeira e segunda metades ordenadas: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &l[i]);
    }

    Merge(n, l, a);

    printf("Lista ordenada: ");
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}