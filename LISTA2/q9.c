#include <stdio.h>
#include <math.h>

int main (){
    int n, achou = -1;
    
    printf("Insira o tamanho 'n' da sequencia: "); //10
    scanf("%d", &n);

    int l[n];

    printf("Insira a sequencia: "); //16 19 22 8 42 39 33 22 29 48
    for(int i = 0; i < n; i++){
        scanf("%d", &l[i]);
    }

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(l[j] == l[i]){
                achou = l[i];
            }
        }
    }

    if(achou == -1){
        printf("Nao ha repeticao.");
    }
    else{
        printf("%d", achou); //22
    }

    return 0;
}