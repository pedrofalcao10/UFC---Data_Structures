#include <stdio.h>

int main (){
    int n, n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0, n6 = 0;
    int aux = 1;
    n1++;

    int i = 0;
    n2++;

    printf("Insira o 'n': ");
    scanf("%d", &n);

    while(i < n){
        n3++;
        aux += i;
        n4++;
        i++;
        n5++;
    }

    n3++; //entra no loop pra conferir se i < n mais uma vez, daí sai do loop

    n6++;

    printf("%d %d %d %d %d %d", n1, n2, n3, n4, n5, n6);

    return aux;
}