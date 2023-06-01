#include <iostream>

using namespace std;

class No{
    public:
        int chave;
        No* direita = NULL;
        No* abaixo = NULL;
};

No* matriz_linha1(int n){
    if(n <= 0){
        return NULL;
    }

    No* cabeca1 = new No;
    No* aux = cabeca1;

    for(int i = 0; i < n; i++){
        aux->chave = i;
        aux->direita = new No;

        aux = aux->direita;
    }

    return cabeca1;
}

No* matriz_linha2(int n){
    if(n <= 0){
        return NULL;
    }

    No* cabeca2 = new No;
    No* aux = cabeca2;

    for(int i = 0; i < n; i++){
        aux->chave = n-1-i;
        aux->direita = new No;

        aux = aux->direita;
    }

    return cabeca2;
}

No* costurar(No* cabeca1, No* cabeca2){
    No* aux1 = cabeca1;
    No* aux2 = cabeca2;

    while(aux1->abaixo != NULL){
        aux1 = aux1->abaixo;
    }

    while(aux2->direita != NULL){
        aux1->abaixo = aux2;
        aux1 = aux1->direita;
        aux2 = aux2->direita;
    }

    return cabeca1;
}

void imprime(No* auxCOL){
    No* aux = auxCOL;

    while(aux->abaixo != NULL){
        while(auxCOL->direita != NULL){
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

    /*No* v = costurar(matriz_linha1(n), matriz_linha2(n));

    for(int i = 0; i < n; i++){
        cout << v->chave << " ";
        v = v->direita;
    }*/

    imprime(costurar(matriz_linha1(n), matriz_linha2(n)));

    return 0;
}