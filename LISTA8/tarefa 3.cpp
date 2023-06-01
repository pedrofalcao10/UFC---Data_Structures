#include <iostream>

using namespace std;

class No{
    public:
        int chave;
        No *prox = NULL;
        No *ante = NULL;
};

No* lista(int n){
    if(n <= 0){
        return NULL;
    }

    No* cabeca = new No;
    No* aux = cabeca;

    for(int i = 0; i < n; i++){
        aux->chave = i;
        aux->prox = new No;
        aux->prox->ante = aux;

        aux = aux->prox;
    }
    return cabeca;
};

void imprime_reverso_recursivo(No* cabeca){
    if(cabeca->prox != NULL){
        imprime_reverso_recursivo(cabeca->prox);

        cout << cabeca->chave << " ";
    }
}

void imprime_reverso_naorecursivo(No* cabeca){
    No* aux = cabeca;

    while(aux->prox != NULL){
        aux = aux->prox;
    }

    while(aux != cabeca){
        aux = aux->ante;
        cout << aux->chave << " ";
    }
}

int main (){
    int n;

    cout << "n = ";
    cin >> n;

    No* cabeca = lista(n);

    cout << "... recursivo: ";
    imprime_reverso_recursivo(cabeca);
    cout << endl;

    cout << "Nao recursivo: ";
    imprime_reverso_naorecursivo(cabeca);
}