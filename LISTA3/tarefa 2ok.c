#include <stdio.h>
#include <stdlib.h>

void zerar_posicao_abaixo (int i, int j, int n, int m, float **M){
    // Zera a posição M[i][j] da matriz M, onde i > j
    for(int k = 0; k < m; k++){
        M[i][k] -= (M[i][j]*M[j][k])/M[j][j];
    }
}

void imprime_matriz (int n, int m, float **M){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
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

    //float M[4][4] = {1, 2, 3, 4, 2, 1, 3, 4, 3, 1, 2, 3, 2 ,4, 3, 1};
    
    //printf("posição M[i][j] da matriz M, onde i > j: ", n, m);

    zerar_posicao_abaixo(0, 0, n, m, M);
    imprime_matriz(n, m, M);

    for(int i = 0; i < n; i++){
        free(M[i]);
    }
    
}