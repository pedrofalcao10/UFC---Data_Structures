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

void soma_na_linha_multiplicada(int n, int p, float a, int q, float b, float **M){//Linha 'p' multiplicada de 'a' recebe linha 'q' multiplicada de 'b':
    for(int j = 0; j < 2*n; j++){
        M[p][j] = a*M[p][j] + b*M[q][j];
    }
}

void simplifica(int n, int l1, float a, float **M){
    for(int j = 0; j < 2*n; j++){
        M[l1][j] = M[l1][j]/a;
    }
}

void diagonalizar(int n, float **M){
    for(int i = 0; i < n; i++){
        if(M[i][i] == 0){
            for(int j = i+1; j < n; j++){
                if(M[j][i] != 0){
                    troca_linha(n, i, j, M);
                    break;
                }
            }
        }
    }

    printf("\nPos ordenacao:\n");
}

void inversa(int n, float **M){

    diagonalizar(n, M);

    imprime_matriz(n, M);

    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            soma_na_linha_multiplicada(n, j, -M[i][i], i, M[j][i], M);
        }
    }

    for(int i = n-1; i > 0; i--){
        for(int j = i-1; j >= 0; j--){
            soma_na_linha_multiplicada(n, j, -M[i][i], i, M[j][i], M);
        }
    }
    
    for(int i = 0; i < n; i++){
        simplifica(n, i, M[i][i], M);
    }

    for(int i = 0; i < n; i++){  /////////////////////////////////////////////////// devia transformar "-0" em "0"
       for(int j = 0; j < 2*n; j++){
            if(M[i][j] == -0){
                M[i][j] = 0;
            }
        }
    }
}

void imprime_matriz(int n, float **M){
    printf("\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2*n; j++){
            if(j == n-1){
                printf("%.3f | ", M[i][j]);
            }
            else{
                printf("%.3f ", M[i][j]);
            }
        }
        printf("\n");
    }
}

int main (){
    int n;

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

    inversa(n, M);

    imprime_matriz(n, M);
}