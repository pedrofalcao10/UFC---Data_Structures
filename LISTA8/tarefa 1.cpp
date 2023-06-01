#include <iostream>

using namespace std;

class No{
    public:
        int chave;
        No *prox = NULL;
};

No* nova_lista_encadeada(int n){
    if(n <= 0){
        return NULL;
    }

    No* cabeca = new No;
    No* aux = cabeca;

    for(int i = 0; i < n; i++){
        aux->chave = i;
        aux->prox = new No;
        aux = aux->prox;
    }

    return cabeca;
}

int main (){
    int n;
    cout << "n = ";
    cin >> n;

    No* v = nova_lista_encadeada(n);

    for(int i = 0; i < n; i++){
        cout << v->chave << " ";
        v = v->prox;
    }
}