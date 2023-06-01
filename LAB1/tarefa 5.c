#include <stdio.h>
#include <stdlib.h>

void zerar_posicao_acima (int n, float m[n][n]){
    // Zera a posi ç ã o M [ i ][ j ] da matriz M , onde i < j
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                m[i-1][j] = 0;
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

    zerar_posicao_acima(3, m);
    imprime_matriz(3, m);

    return 0;
}