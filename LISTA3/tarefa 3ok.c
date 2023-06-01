#include <stdio.h>
#include <stdlib.h>

void zerar_coluna_abaixo (int k,  int n, float **M){
    // Zera as posições da coluna k da matriz M abaixo da diagonal principal
    for(int i = 0; i < n; i++){
        if(i > k){
            M[i][k] = 0;
        }
    }
}

void imprime_matriz (int n, float **M){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%.0f ", M[i][j]);
        }
        printf("\n");
    }
}

int main (){
    int n, m;

    printf("Dimensoes n*m: ");
    scanf("%d %d", &n, &m);

    float **M = (float **)malloc(n*sizeof(float*));
    for(int i = 0; i < n; i++){
        M[i] = (float *)malloc(m*sizeof(float));
    }

    printf("Leitura da matriz %dx%d: ", n, m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%f", &M[i][j]);
        }
    }

    //float m[3][3] = {1, 1, 1, 1, 1, 1, 1, 1, 1};

    zerar_coluna_abaixo(0, n, M);
    imprime_matriz(n, M);

    for(int i = 0; i < n; i++){
        free(M[i]);
    }

    return 0;
}