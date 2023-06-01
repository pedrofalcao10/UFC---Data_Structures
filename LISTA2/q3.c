#include <stdio.h>
#include <stdlib.h>

int main (){
    int n, n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0, n6 = 0;
    printf("Insira o tamanho 'n' da sequencia: ");
    scanf("%d", &n);

    int l[n];

    printf("Insira a sequencia: ");
    for(int j = 0; j < n; j++){
        scanf("%d", &l[j]);
    }

    int i = 0;
    n1++;

    while(i < n){
        n2++;

        if(l[i]%3 == 0){
            n3++;

            l[i] = l[i]/3;
            n4++;

            l[i] = l[i]*l[i];
            n5++;
        }

        i++;
        n6++;
    }
    n2++; //entra no loop pra conferir se i < n mais uma vez, daí sai do loop

    printf("%d %d %d %d %d %d", n1, n2, n3, n4, n5, n6);
}