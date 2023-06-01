#include <stdio.h>
#include <stdlib.h>

int EncontrarSoma(int n, int *l, int x){
    int i = 0, j = n-1;

    while(i < j){
        if(l[i] + l[j] == x){
            printf("%d na posicao %d + %d na posicao %d = %d", l[i], i, l[j], j, x);
            return 1;
        }
        else{
            if((l[i] + l[j]) > x){
                j--;
            }
            else{
                i++;
            }
        }
    }
    return -1;
}

void main (){
    int n, x, iteracoes = 0;

    printf("Tamanho da sequencia: ");
    scanf("%d", &n);

    float *l = (float*)malloc(n*sizeof(float));

    printf("Sequencia: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &l[i]);
    }

    printf("Numero procurado: ");
    scanf("%d", &x);

    EncontrarSoma(n, l, x);
}