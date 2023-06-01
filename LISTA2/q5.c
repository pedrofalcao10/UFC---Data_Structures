#include <stdio.h>
#include <math.h>

int main (){
    int n, maior = 0, n1, n2; //10
    
    printf("Insira o tamanho 'n' da sequencia: ");
    scanf("%d", &n);

    int l[n];

    printf("Insira a sequencia: "); //16 19 41 8 42 39 33 22 29 48
    for(int i = 0; i < n; i++){
        scanf("%d", &l[i]);
    }

    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){

            if(abs(l[j]-l[i]) > maior){
                maior = abs(l[j]-l[i]);
                n1 = l[i];
                n2 = l[j];
            }

        }
    }

    printf("%d %d", n1, n2); //8 48

    return 0;
}