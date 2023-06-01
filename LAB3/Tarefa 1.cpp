#include <iostream>

using namespace std;

class DequeInt{
    public:
    struct Noh{
        int elem;
        Noh *ant, *prox;
    };

    Noh *esq, *dir;
    
        DequeInt(){ //método construtor, inicializa o deque
        esq = dir = nullptr;
        }

        ~DequeInt () { //método destrutor, finaliza o deque
            Noh *aux;
            while(aux != nullptr){
                aux = esq;
                esq = esq->prox;
                delete aux;
            }
        }

        void inserir_esq (int e) { //método para inserir a esquerda no deque
            Noh *n = new Noh;

            n->elem = e;

            if(esq == NULL && dir == NULL){
                esq = dir = n;
                n->ant = n->prox = nullptr;
            }
            else{
                esq->ant = n;
                n->prox = esq;
                esq = n;
                n->ant = nullptr;
            }
        }

        void inserir_dir (int e) { //método para inserir a direita no deque
            Noh *n = new Noh;

            n->elem = e;

            if(esq == NULL && dir == NULL){
                dir = n;
                n->ant = n->prox = nullptr;
            }
            else{
                dir->prox = n;
                n->ant = dir;
                dir = n;
                n->prox = nullptr;
            }
        }

        int consultar_esq () { //pré-condição: deque não vazio
            return esq->elem; // retorna o elemento mais a esquerda do deque
        }

        int consultar_dir () { //pré-condição: deque não vazio
            return dir->elem; // retorna o elemento mais a direita do deque
        }

        void remover_esq () { //pré-condição: deque não vazio
            Noh *aux = esq;  // remove o elemento mais a esquerda do deque
            esq = esq->prox;
            delete aux;

            if(esq == NULL)
                dir = esq;
            else
                esq->ant = nullptr;
        }

        void remover_dir () { //pré-condição: deque não vazio
            Noh *aux = dir;  // remove o elemento mais a direita do deque
            dir = dir->ant;
            delete aux;

            if(dir == NULL)
                esq = dir;
            else
                dir->prox = nullptr;
        }
        
        bool vazio (){
            return esq == nullptr && dir == nullptr;
        }
};

int main () {
    DequeInt deque;
    // cout << "1111";
    for(int i = 1; i <= 5; i++){
        deque.inserir_esq(i);
        cout << "inseri na esquerda: "<< deque.consultar_esq() << endl;
    }
    for(int i = 5; i <= 10; i++){
        deque.inserir_dir(i);
        cout << "inseri na direita: "<< deque.consultar_dir() << endl;
    }

    while(!deque.vazio()){
        deque.remover_dir();
    }

    if(deque.vazio()){
        cout << "vazio";
    }
}
