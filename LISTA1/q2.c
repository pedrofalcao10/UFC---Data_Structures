#include <stdio.h>

void main (){
    int n, aux;

    printf("Insira 'n': ");
    scanf("%d", &n);

    int l[2*n];

    printf("Insira %d numeros: ", 2*n);
    for(int i = 0; i < 2*n; i++){
        scanf("%d", &l[i]);
    }
    //16 19 41 8 42 39 33 22 29 49

    aux = l[1];
    l[1] = l[5];
    l[5] = aux;

    aux = l[3];
    l[3] = l[6];
    l[6] = aux;

    aux = l[5];
    l[5] = l[8];
    l[8] = aux;

    aux = l[5];
    l[5] = l[7];
    l[7] = aux;

    for(int i = 0; i < 2*n; i++){
        printf("%d ", l[i]);
    }
    //16 39 41 33 42 22 8 29 19 49
    
}