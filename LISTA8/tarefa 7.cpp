#include <iostream>

using namespace std;

class No{
    public:
        int chave;
        No* direita = NULL;
        No* abaixo = NULL;
};

No* matriz1(int n, int m){
    if(n <= 0){
        return NULL;
    }

    No* cabeca1 = new No;
    No* auxLIN1 = cabeca1;
    No* auxCOL1 = cabeca1;

    for(int j = 0; j < n; j++){
        if(j != 0){
            auxLIN1 = auxLIN1->abaixo;
            cabeca1 = auxLIN1;
        }

        for(int i = 0; i < m; i++){
            cabeca1->chave = i*i;
            cabeca1->direita = new No;
            cabeca1->abaixo = new No;
            cabeca1 = cabeca1->direita;
        }
    }

    return auxCOL1;
}

No* costurar(No* auxCOL1, No* auxCOL2){
    No* aux1 = auxCOL1;
    No* aux2 = auxCOL2;

    while(aux1->abaixo->abaixo){
        aux1 = aux1->abaixo;
    }

    while(aux1 && aux2){
       aux1->abaixo = aux2 ;
        aux1 = aux1->direita;
        aux2 = aux2->direita;
    }

    return auxCOL1;
}

void imprime(No* auxCOL){
    No* aux = auxCOL;

    while(aux->abaixo != NULL){
        while(auxCOL->direita != NULL){
            cout << auxCOL->chave << " ";
            auxCOL = auxCOL->direita;
        }
        aux = aux->abaixo;
        auxCOL = aux;
        cout << endl;
    }
}

int main (){
    int n, L, m;

    cout << "Quant de linhas de cada matriz: ";
    cin >> n >> L;
    cout << "Quant de colunas: ";
    cin >> m;

    No* a;
    No* b;

    a = matriz1(n, m);
    b = matriz1(L, m);

    costurar(a, b);

    imprime(a);
}