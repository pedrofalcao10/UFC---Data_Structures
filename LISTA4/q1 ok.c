#include <stdio.h>

int BuscaTri(int n, int *l, int x){
    int i = 0, j = 2*(n-1);

    while(i <= j){
        int terco = (i + j)/3;

        if(l[terco] == x){
            return terco;
        }
        else{
            if(l[terco] < x){
                i = terco + 3;
            }
            else{
                j = terco - 3;
            }
        }
    }
    return -1;
}

void main (){
    int n, x;

    printf("Tamanho da sequencia (M3): ");
    scanf("%d", &n); // 12

    float *l = (float*)malloc(n*sizeof(float)); // 1 2 18 20 29 30 39 44 55 56 84 96

    printf("Sequencia: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &l[i]);
    }

    printf("Numero procurado: ");
    scanf("%d", &x); // 56

    printf("Numero %d na posicao %d", x, BuscaTri(n, l, x));
}