#include <stdio.h>

void main (){
    int n, primeiro, segundo, trocou = 0; //10
    
    printf("Insira o tamanho 'n' da sequencia: ");
    scanf("%d", &n);

    int l[n];

    printf("Insira a sequencia: "); //16 19 41 8 42 39 33 22 29 48
    for(int i = 0; i < n; i++){
        scanf("%d", &l[i]);
    }

    for(int i = 1; i < n-1; i++){
        if(l[i] > l[i-1] && l[i] > l[i+1]){
            printf("%d ", l[i]);
        }
    }
}