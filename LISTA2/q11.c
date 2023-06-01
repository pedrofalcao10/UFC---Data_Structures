#include <stdio.h>

void main (){
    int l[10] = {16, 19, 41, 8, 42, 36, 33, 22, 29, 48};
    int v[10] = {2, 5, 17, 9, 35, 19, 23, 72, 91, 44};
    int aux;

    for(int i = 0; i < 10; i++){
        for(int j = i+1; j < 10; j++){
            if(l[j] < l[i]){
                aux = l[j];
                l[j] = l[i];
                l[i] = aux;
            }
            if(v[j] > v[i]){
                aux = v[j];
                v[j] = v[i];
                v[i] = aux;
            }
        }
    }

    printf("L: ");
    for(int i = 0; i < 10; i++){
        printf("%d ", l[i]);
    }
    printf("\nV: ");
    for(int i = 0; i < 10; i++){
        printf("%d ", v[i]);
    }

    for(int i = 0; i < 10; i++){
        if(l[i] < v[i]){
            aux = v[i];
            v[i] = l[i];
            l[i] = aux;
        }
    }

    printf("\nL: ");
    for(int i = 0; i < 10; i++){
        printf("%d ", l[i]);
    }
    printf("\nV: ");
    for(int i = 0; i < 10; i++){
        printf("%d ", v[i]);
    }
}