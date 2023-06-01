#include <stdio.h>

void main (){
    int l[10] = {16, 19, 41, 8, 42, 36, 33, 22, 29, 48};
    int v[10] = {2, 5, 17, 9, 35, 19, 23, 72, 91, 44};
    
    int menorL = l[0], maiorV = v[0];
    int pos_menorL = 0, pos_maiorV = 0;

    for(int i = 0; i < 10; i++){
        if(l[i] < menorL){
            menorL = l[i];
        }
        if(v[i] > maiorV){
            maiorV = v[i];
        }
    }

    printf("menor: %d\nmaior: %d\n", menorL, maiorV);

    while(menorL < maiorV){

        for(int i = 0; i < 10; i++){
            if(l[i] < menorL){
                menorL = l[i];
                pos_menorL = i;
            }
            if(v[i] > maiorV){
                maiorV = v[i];
                pos_maiorV = i;
            }
        }

        l[pos_menorL] = maiorV;
        v[pos_maiorV] = menorL;
    }

    printf("L: ");
    for(int i = 0; i < 10; i++){
        printf("%d ", l[i]);
    }
    printf("\nV: ");
    for(int i = 0; i < 10; i++){
        printf("%d ", v[i]);
    }
}