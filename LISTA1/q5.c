#include <stdio.h>

void main (){
    int m, n, aux, k = 0;

    printf("Insira o tamanho 'm' do vetor e a quant. de elem. 'n' nele: ");
    scanf("%d %d", &m, &n);
    //10 4

    k = n;
    int l[m];

    printf("Insira os %d numeros: ", n);
    for(int i = 0; k > 0; i++, k--){
        scanf("%d", &l[i]);
    }
    //16 39 10 50
    for(int i = n; i < m; i++){
        l[i] = 0;
    }

    for(int i = n; i > 0; i--){
        aux = l[i-1];
        l[i-1] = l[i-2];
        l[i-2] = aux;
    }

    l[0] = aux;
    for(int i = 0; i < m; i++){
        printf("%d ", l[i]);
    }
    //50 16 39 10 0 0 0 0 0 0
    
}