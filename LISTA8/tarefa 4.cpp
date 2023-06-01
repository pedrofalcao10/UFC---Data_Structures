#include <iostream>

using namespace std;

class Node{
    public:
        int chave;
        Node* prox = NULL;
        Node* ante = NULL;
};

class ListaDE{
    public:
        Node* cabeca = NULL;
        int count = 0;

        ListaDE(int n){ //método construtor, inicializa a lista
            cout << "lista de tamanho " << n << endl;
            cabeca = new Node;
            count = n;
            Node* aux = cabeca;

            for(int i = 0; i < n; i++){
                aux->chave = i;
                aux->prox = new Node;
                aux->prox->ante = aux;
                aux = aux->prox;
            }
        }

        void inserir_final(Node* no){
            cout << "inserir: " << no->chave << endl;

            Node* aux = cabeca;

            while(aux->prox != NULL){
                aux = aux->prox;
            }

            aux->prox = new Node;
            aux->chave = no->chave;
        }

        void reinserir(Node* no){
            cout << "reinserir: " << no->chave << endl;

            if(cabeca->chave > no->chave ){
                no->chave = cabeca->prox->chave;
                cabeca = no;
            }
            else{
                Node* aux = cabeca;

                while((aux->prox != NULL) && (aux->prox->chave < no->chave)){
                    aux = aux->prox ;
                }

                no->prox = aux->prox;
                aux->prox = no;
            }
        }

        Node* remover(int chave){
            cout << "remover: " << chave << endl;
            Node* aux = cabeca;

            while(aux->chave != chave){
                aux = aux->prox;
            }

            aux->ante->prox = aux->prox;
            aux->prox->ante = aux->ante;

            delete(aux);
        }

        void imprime(){
            Node* aux = cabeca;

            while(aux->prox != NULL){
                cout << aux->chave << " ";
                aux = aux->prox;
            }
            cout << endl;
        }
};

int main (){
    int n = 10;
    Node* no1;
    no1->chave = 4;
    int key = 4;

    ListaDE lista(n);
    lista.imprime();
    lista.remover(key);
    lista.imprime();
    lista.inserir_final(no1);
    lista.imprime();
    lista.reinserir(no1);
    lista.imprime();

    return 0;
}