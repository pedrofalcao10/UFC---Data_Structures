#include <stdio.h>

void main (){
    int n, aux, k = 1;

    printf("Insira 'n': ");
    scanf("%d", &n);

    int l[2*n];

    printf("Insira %d numeros: ", 2*n);
    for(int i = 0; i < 2*n; i++){
        scanf("%d", &l[i]);
    }
    //16 19 41 8 42 39 33 22 29 49

    for(int i = n; i < 2*n; i++){
        for(int j = i; j > k; j--){
            aux = l[j-1];
            l[j-1] = l[j];
            l[j] = aux;
        }
        k += 2;
    }

    for(int i = 0; i < 2*n; i++){
        printf("%d ", l[i]);
    }
    //16 39 19 33 41 22 8 29 42 49

}