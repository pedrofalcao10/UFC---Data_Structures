# include <stdio.h>
# include <stdlib.h>
/*
* Matriz como vetor de vetores alocados dinamicamente
**
uma matriz é definida assim
**
int n = ...
* int m = ...
* float ** M = ( float **) malloc (n* sizeof ( float *));
* for (int i = 0; i < n; i++)
* M[i] = ( float *) malloc (m* sizeof ( float ));
**
podemos acessar os elementos da matriz assim
**
M[i][j] = ...
**
para declarar um mé todo que recebe uma matriz , fazemos assim
**
void metodo (..., int n, int m, float ** M, ...)
**
ou seja , além da matriz , temos que passar tamb ém as dimens ões da matriz
*
*/
void imprimir_matriz ( int n, int m, float ** M){
    for ( int i = 0; i < n; i ++){
        for ( int j = 0; j < m; j ++){
            printf ("%.0f ", M[i][j]);
        }
        printf ("\n");
    }
}

void trocar_linhas ( int i, int j, int n, int m, float ** M){
// ...
}

void multiplicar_escalar_linha (int i, float j, int n, int m, float ** M){
// ...
}

void somar_linhas (int i, int j, float a, int n, int m, float ** M){
// ...
}


void zerar_posicao_abaixo (int i, int j, int n, int m, float ** M){
// ...
}

int main (){
// criando matriz e inicializando
    int n = 3;
    int m = 3;
    float ** Mat = ( float **)malloc(n* sizeof(float *));

    for(int i = 0; i < n; i++){
        Mat[i] = ( float *)malloc(m* sizeof(float));
    }

    Mat [0][0] = 1; Mat [0][1] = 2; Mat [0][2] = 3;
    Mat [1][0] = 1; Mat [1][1] = 3; Mat [1][2] = 2;
    Mat [2][0] = 2; Mat [2][1] = 1; Mat [2][2] = 3;

    // imprimindo a matriz
    imprimir_matriz (n, m, Mat);
    
    return 0;
}