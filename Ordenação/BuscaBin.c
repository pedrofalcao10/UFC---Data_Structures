#include <stdio.h>

int BuscaBin(int n, int *l, int x){
    int i = 0, j = n-1;

    while(i <= j){
        int meio = (i + j)/2;

        if(l[meio] == x){
            return meio;
        }
        else{
            if(l[meio] < x){
                i = meio+1;
            }
            else{
                j = meio-1;
            }
        }
    }
    return -1;
}

void main (){
    int n, x, iteracoes = 0;

    printf("Tamanho da sequencia (par): ");
    scanf("%d", &n);

    float *l = (float*)malloc(n*sizeof(float));

    printf("Sequencia: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &l[i]);
    }

    printf("Numero procurado: ");
    scanf("%d", &x);

    printf("Numero %d na posicao %d", x, BuscaBin(n, l, x));
}