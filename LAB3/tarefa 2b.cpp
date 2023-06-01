#include <iostream>

using namespace std;

class ConjuntoDouble{
    public:
        struct noh{
            double elem;
            noh *prox = nullptr;
        };

        noh *h;

        ConjuntoDouble () {        // Cria um conjunto vazio representado atrav´es de lista encadeada.
            h = nullptr;
        }

        bool pertence (double e) {        // Retorna "true" se e somente se "e" pertence ao conjunto.
            noh *aux = h;

            while(aux->elem != e){
                aux = aux->prox;
            }

            if(aux->elem == e){
                return true;
            }
            else{
                return false;
            }
        }

        void inserir_sem_testar (double e) {        // Insere "e" no conjunto sem testar se "e" está no conjunto.
            noh *aux = new noh;
            aux->elem = e;

            aux->prox = h;

            h = aux;

            cout << e << " inserido sem testar." << endl;
        }

        void inserir (double e) {        // Insere "e" no conjunto apenas se "e" ainda não pertence ao conjunto.
            if(pertence(e)){
                cout << e << " ja pertence ao conjunto." << endl;
            }
            else{
                inserir_sem_testar(e);
            }
        }

        void remover (double e) {        // Remove "e" do conjunto, caso "e" perten¸ca a ele; se "e" n~ao pertence ao conjunto, mant´em-no inalterado.            
            noh *aux = h;
            noh **p = &aux;

            //cout << "123 ";
            while(aux->elem != e){
                //cout << "456 ";
                aux = aux->prox;
                *p = aux;
                //cout << "789";
            }

            //cout << "101112";

            if(aux->elem == e){
                aux = aux->prox;
                delete *p;
                cout << e << " foi removido." << endl;
            }
        }

        ~ConjuntoDouble () {        // Desaloca a lista encadeada.
            noh* aux = h;
            noh* removido;

            while(aux){
                removido = aux;
                aux = aux->prox;
                delete removido;
            }
        }
};

int main () {
    ConjuntoDouble conj;

    //conj.remover(4.2);

    for(int i = 0; i < 14; i++){
        conj.inserir_sem_testar(i);
    }

    cout << endl;

    for(int i = 7; i < 11; i++){
        conj.inserir(i);
    }

    cout << endl;

    for(int i = 4; i < 10; i++){
        conj.remover(i);
    }
    
    cout << endl;

    for(int i = 4; i < 10; i++){
        conj.pertence(i);
    }

    cout << endl;
}