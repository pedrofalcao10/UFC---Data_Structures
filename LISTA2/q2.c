#include <stdio.h>

void main (){
    int l[10] = {16, 19, 41, 8, 42, 36, 33, 22, 29, 48};
    int v[10] = {2, 5, 17, 9, 35, 19, 23, 72, 91, 44};
    int n, n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0, n6 = 0;

    int i = 0, aux = 0;
    n1++;

    while(i < 10){
        n2++;

        aux = l[i];
        n3++;
        l[i] = v[i];
        n4++;
        v[i] = aux;
        n5++;
        
        i++;
        n6++;
    }
    n2++; //entra no loop pra conferir se i < n mais uma vez, daí sai do loop

    printf("%d %d %d %d %d %d", n1, n2, n3, n4, n5, n6);
}