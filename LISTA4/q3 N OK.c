#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void inserir(int n, int tam, int *l, int x){
    if(n <= tam){
        return;
    }
    int i = 0;
    
    for(; i < tam && l[i] < x; i++){}
    if(i == tam){
        l[tam] = x;
        tam++;
        return;
    };

    int hold = l[i];
    l[i] = x;
    i++;
    for(; i < tam+1; i++){
        troca(&hold, &l[i]);
    }
    tam++;
}

void remover(int tam, int *l, int x){
    if(tam == 0) return;

    int i = 0;

    for(; i < tam && l[i] != x; i++){}
    if(i >= tam) return;

    l[i] = 0;

    for(; i < tam-1; i++){
        troca(&l[i], &l[i+1]);
    }

    tam--;
}

void imprime(int tam, int *l){
    for(int i = 0; i < tam; i++){
        printf("%d ", l[i]);
    }
}

void main (){
    int tam, n;
    char resp = 's';

    printf("Tamanho total 'tam' e 'n' ja preenchidos: ");
    scanf("%d %d", &tam, &n); // 6 5

    int *l = (int*)malloc(tam*sizeof(int)); // 1 2 4 5 6 _

    printf("%d primeiros elementos ordenados: ", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &l[i]);
    }

    while(resp != 'n'){
        char op;
        int x;

        printf("Deseja adicionar ou remover um elemento? (a/r): "); //1 2 4 5 6 _
        scanf(" %c", &op);

        if(op == 'a'){
            printf("Que nero deseja adicionar? "); //3
            scanf("%d", &x);

            inserir(n, tam, l, x); // 1 2 3 4 5 6 
        }
        else{
            printf("Que numero deseja remover? "); //4
            scanf("%d", &x);

            remover(tam, l, x);
        }

        printf("Deseja continuar? (s/n): ");
        scanf(" %c", &resp);
    }

    imprime(tam, l);

    free(l);
}