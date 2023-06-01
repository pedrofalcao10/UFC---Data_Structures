#include <stdio.h>
#include <stdlib.h>

void triangular_inferior (int n, float m[n][n]){
    // Zera as posições da matriz M abaixo da diagonal principal
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i < j){
                m[i][j] = 0;
            }
        }
    }
}

void imprime_matriz (int n, float m[n][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%.0f ", m[i][j]);
        }
        printf("\n");
    }
}

int main (){
    /*int n, m, op;

    printf("Dimensoes n*m: ");
    scanf("%d %d", &n, &m);

    float m[n][m];

    printf("Leitura da matriz %dx%d: ", n, m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%f", &m[i][j]);
        }
    }*/

    float m[3][3] = {1, 1, 1, 1, 1, 1, 1, 1, 1};

    triangular_inferior(3, m);
    imprime_matriz(3, m);

    return 0;
}