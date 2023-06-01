#include <stdio.h>

int main (){
    int n, k = 0;
    
    printf("Insira o tamanho 'n' da sequencia: ");
    scanf("%d", &n);

    int l[n];

    printf("Insira a sequencia: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &l[i]);
    }

    printf("Insira o inteiro cuja soma deve resultar: ");
    scanf("%d", &k);

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(l[i] + l[j] == k){
                printf("%d + %d = %d\n", l[i], l[j], k);
            }
        }
    }

    return 0;
}