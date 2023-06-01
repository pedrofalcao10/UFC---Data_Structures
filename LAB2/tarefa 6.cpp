#include <iostream>

using namespace std;

class No{
    public:
        int chave;
        No* direita = NULL;
        No* abaixo = NULL;
};

No* matriz(int n){
    if(n <= 0){
        return NULL;
    }

    No* cabeca = new No;
    No* auxLIN = cabeca;
    No* auxCOL = cabeca;

    for(int j = 0; j < n; j++){
        if(j != 0){
            auxLIN = auxLIN->abaixo;
            cabeca = auxLIN;
        }

        for(int i = 0; i < n; i++){
            cabeca->chave = i*i;
            cabeca->direita = new No;
            cabeca->abaixo = new No;
            cabeca = cabeca->direita;
        }
    }

    return auxCOL;
}

void imprime(No* auxCOL){
    No* aux = auxCOL;

    while(aux/*->abaixo*/ != NULL){
        while(auxCOL/*->direita*/ != NULL){
            cout << auxCOL->chave << " ";
            auxCOL = auxCOL->direita;
        }
        cout << endl;
        aux = aux->abaixo;
        auxCOL = aux;
    }
}

int main (){
    int n;
    cout << "n = ";
    cin >> n;

    imprime(matriz(n));
}