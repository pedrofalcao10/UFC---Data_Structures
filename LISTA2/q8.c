#include <stdio.h>
#include <stdbool.h>

void main (){
    int n, primeiro, segundo, j = 0; //11
    
    printf("Insira o tamanho 'n' da sequencia: ");
    scanf("%d", &n);

    int l[n], t[n];

    printf("Insira a sequencia: "); //0 5 0 4 0 3 0 2 0 1 0
    for(int i = 0; i < n; i++){
        scanf("%d", &l[i]);
    }

    for(int i = 1; i < n-1; i++){ //se é topo, coloca o valor num novo vetor até completar todos os topos
        if(l[i] > l[i-1] && l[i+1] < l[i]){
            t[j] = l[i];
            j++;
        }
    }

    for(int i = 0; i < j; i++){
        for(int k = i + 1; k < j-1; k++){
            
            if(t[i] > t[k]){ //ordena os topos em ordem crescente
                int aux = t[k];
                t[k] = t[i];
                t[i] = aux;
            }

        }
    }

    for(int i = 0; i < j-1; i++){
        printf("%d ", t[i]);        
    }
}