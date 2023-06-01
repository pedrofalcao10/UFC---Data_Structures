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
    No* it = cabeca;

    for(int i = 0; i < n; i++){
        it->chave = i;
        it->prox = new No;
        it = it->prox;
    }

    return cabeca;
}

void apaga_lista(No* cabeca){
    No* aux = cabeca;
    No* removido;

    while(aux){
        removido = aux;
        aux = aux->prox;
        delete removido;
    }
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

    apaga_lista(v);

    for(int i = 0; i < n; i++){
        cout << v->chave << " ";
        v = v->prox;
    }

}