#include <stdio.h>

void main (){
    int m, n, aux, k = 0;

    printf("Insira o tamanho 'm' do vetor e a quant. de elem. 'n' nele: ");
    scanf("%d %d", &m, &n);

    int l[m];

    printf("Insira %d numeros: ", n);
    for(int i = 0; i < m && n > 0; i++, n--){
        scanf("%d", &l[i]);
    }
    //16 19 41 8 42 39 33 22 29 48

    for(int i = 0; i < m/2; i++){
        aux = l[m-1-i];
        l[m-1-i] = l[i];
        l[i] = aux;
    }

    for(int i = 0; i < m; i++){
        printf("%d ", l[i]);
    }
    //48 29 22 33 39 42 8 41 19 16
    
}