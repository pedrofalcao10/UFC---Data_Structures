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

    primeiro = l[0];

    for(int i = 0; i < n; i++){
        if(l[i] > primeiro){
            segundo = primeiro;
            primeiro = l[i];
            trocou++;
        }
    }

    if(trocou == 0){
        printf("Nao existe segundo maior. ");
    }
    else{
        printf("%d", segundo); //42
    }
}