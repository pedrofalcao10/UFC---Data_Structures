#include <stdio.h>

void main (){
    int n, aux;

    printf("Insira 'n': ");
    scanf("%d", &n);

    int L[2*n];

    printf("Insira %d numeros pares e %d numeros impares: ", n, n);
    for(int i = 0; i < 2*n; i++){
        scanf("%d", &L[i]);
    }
    //16 19 41 8 42 39 33 22 29 48

    for(int i = 0; i < 2*n; i++){
        if(L[i]%2 == 0 && i%2 != 0){
            aux = L[i];
            L[i] = L[i+1];
            L[i+1] = aux;
        }
        else if(L[i]%2 != 0 && i%2 == 0){
            aux = L[i];
            L[i] = L[i+1];
            L[i+1] = aux;
        }
    }

    for(int i = 0; i < 2*n; i++){
        printf("%d ", L[i]);
    }
    //16 19 8 41 42 39 22 33 48 29
    
}