#include <iostream>

using namespace std;

class DequeInt{
    public:
        struct noh{
            int elem;
            noh *ant, *prox;
        };

        noh *sentinela;
        
            DequeInt(){ //método construtor, inicializa o deque
                sentinela = new noh {-1, nullptr, nullptr};
            }

            void inserir_esq (int e) { //método para inserir a esquerda no deque
                noh* aux = new noh {e, nullptr, nullptr};

                if(sentinela->ant == nullptr){ //deque vazio
                    aux->ant = sentinela;
                    aux->prox = sentinela;
                    sentinela->ant = aux;
                    sentinela->prox = aux;
                }
                else{ //deque não vazio
                    aux->ant = sentinela;
                    aux->prox = sentinela->ant;
                    (sentinela->ant)->ant = aux;
                    sentinela->ant = aux;
                }
            }

            void inserir_dir (int e) { //método para inserir a direita no deque
                noh* aux = new noh {e, nullptr, nullptr};

                if(sentinela->prox == nullptr){ //deque vazio
                    aux->prox = sentinela;
                    aux->ant = sentinela;
                    sentinela->prox = aux;
                    sentinela->ant = aux;
                }
                else{ //deque não vazio
                    aux->prox = sentinela;
                    aux->ant = sentinela->prox;
                    (sentinela->prox)->prox = aux;
                    sentinela->prox = aux;
                }    
            }

            int consultar_esq () { //pré-condição: deque não vazio
                return sentinela->ant->elem;
            }

            int consultar_dir () { //pré-condição: deque não vazio
                return sentinela->prox->elem;

            }

            void remover_esq () { //pré-condição: deque não vazio
                noh* removido = sentinela->ant;

                if(sentinela->ant->prox != sentinela){ //+ de 1 elemento no deque
                    
                    sentinela->ant = sentinela->ant->prox;
                    (removido->prox)->ant = sentinela;
                    
                    cout << "removendo " << removido->elem << endl;

                    delete removido;
                }
                else{ //1 elemento no deque
                    sentinela->ant = sentinela->prox = nullptr;
                
                    cout << "removendo " << removido->elem << endl;

                    delete removido;
                }
            }

            void remover_dir () { //pré-condição: deque não vazio
                noh* removido = sentinela->prox;

                if(sentinela->prox->ant != sentinela){ //+ de 1 elemento no deque
                    
                    sentinela->prox = sentinela->prox->ant;
                    (removido->ant)->prox = sentinela;
                    
                    cout << "removendo " << removido->elem << endl;
                    
                    delete removido;
                }
                else{ //1 elemento no deque
                    sentinela->prox = sentinela->ant = nullptr;
                
                    cout << "removendo " << removido->elem << endl;
                    
                    delete removido;
                }
            }
            
            bool vazio (){
                return sentinela->ant == nullptr && sentinela->prox == nullptr;
            }

            ~DequeInt () { //método destrutor, finaliza o deque deixando só a sentinela
                noh* aux = sentinela->prox;
                noh* removido;

                while(aux != sentinela){
                    removido = aux;
                    aux = aux->prox;
                    delete removido;
                }
            }
};

int main () {
    DequeInt deque;

    for(int i = 1; i <= 5; i++){
        deque.inserir_esq(i);
        cout << "inseri na esquerda: "<< deque.consultar_esq() << endl;
    }

    for(int i = 6; i <= 10; i++){
        deque.inserir_dir(i);
        cout << "inseri na direita: "<< deque.consultar_dir() << endl;
    }

    while(!deque.vazio()){
        deque.remover_dir();
    }

    if(deque.vazio()){
        cout << "vazilzilzil";
    }
}
