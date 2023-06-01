#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void troca_linha(int n, int p, int q, float **M){
    for(int i = 0; i < 2*n; i++){
        troca(&M[p][i], &M[q][i]);
    }
}

void soma_na_linha_multiplicada(int n, int p, float a, int q, float b, float **M){
    for(int j = 0; j < 2*n; j++){
        M[p][j] = a*M[p][j] + b*M[q][j];
    }
}

void simplifica(int n, int l1, float a, float **M){
    for(int i = 0; i < 2*n; i++){
        M[l1][i] = M[l1][i]/a;
    }
}

void imprime_matriz(int n, float **M){
    printf("\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2*n; j++){
            if(j == n-1){
                printf("%.0f | ", M[i][j]);
            }
            else{
                printf("%.0f ", M[i][j]);
            }
        }
        printf("\n");
    }
}

void imprime_inversa(int n, float **M){
    printf("\n");
    for(int i = 0; i < n; i++){
        for(int j = n; j < 2*n; j++){
            printf("%.2f ", M[i][j]);
        }
        printf("\n");
    }
}

int main (){
    int n;
    char op = 's', troca ='s', simp = 's';

    printf("Tamanho: ");
    scanf("%d", &n);

    float **M = (float **)malloc(n*sizeof(float*));
    for(int i = 0; i < n; i++){
        M[i] = (float *)malloc((2*n)*sizeof(float));
    }

    printf("Insira a matriz:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%f", &M[i][j]);

            if(i == j){
                M[i][j+n] = 1;
            }
            else{
                M[i][j+n] = 0;
            }
        }
    }
    
    while(troca == 's'){

        printf("Deseja trocar linha de posicao (s/n)?");
        scanf(" %c", &troca);

        if(troca == 's'){
            int l1, l2;

            printf("Linhas a trocar: ");
            scanf("%d %d", &l1, &l2);

            troca_linha(n, l1, l2, M);
        }
    }

    imprime_matriz(n, M);

    while(op == 's'){
        int p, q;
        float a, b;

        printf("\nLinha 'p' multiplicada de 'a' recebe linha 'q' multiplicada de 'b' (p, a, q, b):  ");
        scanf("%d %f %d %f", &p, &a, &q, &b); //identado em C (começa do zero)

        soma_na_linha_multiplicada(n, p, a, q, b, M);
        imprime_matriz(n, M);

        printf("\nDeseja continuar? ");
        scanf(" %c", &op);
    }

    while(simp == 's'){

        printf("Deseja simplificar linha (s/n)?");
        scanf(" %c", &simp);

        if(simp == 's'){
            int l1, a;

            printf("Linhas a simplificar e valor a dividir: ");
            scanf("%d %d", &l1, &a);

            simplifica(n, l1, a, M);
        }
    }

    imprime_inversa(n, M);
}