#include <stdio.h>
#include <stdlib.h>

void trocar_linhas (int i, int j, int n, int m, float M[n][m]){
    // Troca as linhas i e j da matriz M de dimensões n×m
    for(int k = 0; k < m; k++){
        int aux = M[i][k];
        M[i][k] = M[j][k];
        M[j][k] = aux;
    }
}

void multiplicar_escalar_linha (int i, int a, int n, int m, float M[n][m]){
    // Multiplica a linha i da matriz M de dimensões n×m
    for(int k = 0; k < m; k++){
        M[i][k] = a*M[i][k];
    }
}

void somar_linhas (int i, int j, int a, int n, int m, float M[n][m]){
    // Soma à linha i o produto da linha j por a
    // na matriz M de dimensões nxm
    for(int k = 0; k < m; k++){
        M[i][k] += a*M[j][k];
    }
}

void imprime_matriz (int n, int m, float M[n][m]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%.0f ", M[i][j]);
        }
        printf("\n");
    }
}

int main (){
    int n, m, op;

    printf("Dimensoes n*m: ");
    scanf("%d %d", &n, &m);

    float M[n][m];

    printf("Leitura da matriz %dx%d: ", n, m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%f", &M[i][j]);
        }
    }

    //float M[3][4] = {1, -2, 2, 1, 2, 1, -3, 5, 4, -7, 1, -1};

    printf("1 – trocar duas linhas da matriz\n2 - multiplicar uma linha por um numero (!= 0)\n3 - substituir uma linha pela soma dela mesma com outra multiplicada por um numero (!= 0)");

    scanf("%d", &op);

    if(op == 1){
        int i, j;
        printf("Linhas i e j a serem trocadas: ");
        scanf("%d %d", &i, &j);

        trocar_linhas(i, j, n, m, M);
    }
    else if(op == 2){
        int i, a;
        printf("Linhas i a ser multiplicada por a: ");
        scanf("%d %d", &i, &a);

        trocar_linhas(i, a, n, m, M);
    }
    else{
        int i, j, a;
        printf("Linhas i a ser somada pela j multiplicada de a: ");
        scanf("%d %d %d", &i, &j, &a);

        somar_linhas(i, j, a, n, m, M);
    }
        
    imprime_matriz(3, 4, M);

    return 0;
}