#include <stdio.h>
#include <stdlib.h>

void imprime_matriz (int n, float **M){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%.0f ", M[i][j]);
        }
        printf("\n");
    }
}

int main (){
    float det = 0;

    float **M = (float **)malloc(3*sizeof(float*));
    float **M_1 = (float **)malloc(3*sizeof(float*));

    for(int i = 0; i < 3; i++){
        M[i] = (float *)malloc(3*sizeof(float));
        M_1[i] = (float *)malloc(3*sizeof(float));
    }

    printf("Insira a matriz 3x3: ");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%f", &M[i][j]);
        }
    }
    printf("\n");

    det += M[0][0]*(M[1][1]*M[2][2] - M[1][2]*M[2][1]);
    det += M[0][1]*(M[1][2]*M[2][0] - M[1][0]*M[2][2]);
    det += M[0][2]*(M[1][0]*M[2][1] - M[1][1]*M[2][0]);

    if(det == 0){
        printf("A matriz 'M' nao possui inversa.");
    }
    else{
        M_1[0][0] = (M[1][1]*M[2][2] - M[1][2]*M[2][1]);
        M_1[0][1] = (M[0][2]*M[2][1] - M[0][1]*M[2][2]);
        M_1[0][2] = (M[0][1]*M[1][2] - M[0][2]*M[1][1]);

        M_1[1][0] = (M[1][2]*M[2][0] - M[1][0]*M[2][2]);
        M_1[1][1] = (M[0][0]*M[2][2] - M[0][2]*M[2][0]);
        M_1[1][2] = (M[0][2]*M[1][0] - M[0][0]*M[1][2]);
        
        M_1[2][0] = (M[1][0]*M[2][1] - M[1][1]*M[2][0]);
        M_1[2][1] = (M[0][1]*M[2][0] - M[0][0]*M[2][1]);
        M_1[2][2] = (M[0][0]*M[1][1] - M[0][1]*M[1][0]);
        
        printf("Inversa de M (M_1): \n");
        imprime_matriz (3, M_1);
    }

    free(M);

    return 0;
}
