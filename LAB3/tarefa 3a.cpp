#include <iostream>

using namespace std;

class ConjuntoDouble{
    public:
        struct noh{
            double elem;
            noh *prox = nullptr;
        };

        noh *sentinela;

        ConjuntoDouble () {        // Cria um conjunto vazio representado atrav´es de lista encadeada.
            sentinela = new noh;
        }

        bool pertence (double e) {        // Retorna "true" se e somente se "e" pertence ao conjunto.
            noh *aux = sentinela;
            sentinela->elem = e;

            while(aux->prox->elem != e){
                aux = aux->prox;
            }

            if(aux->prox == sentinela){
                return false;
            }
            else{
                return true;
            }
        }

        void inserir_sem_testar (double e) {        // Insere "e" no conjunto sem testar se "e" está no conjunto.
            noh* aux = new noh;
            aux->elem = e; //O(1), insere sempre no começo imediatamente dps da sentinela

            aux->prox = sentinela->prox;

            sentinela->prox = aux;

            cout << e << " inserido." << endl;
        }

        void inserir (double e) {        // Insere "e" no conjunto apenas se "e" ainda não pertence ao conjunto.
            if(pertence(e)){
                cout << e << " ja esta no conjunto." << endl;
            }
            else{
                inserir_sem_testar(e);
            }
        }

        void remover (double e) {        // Remove "e" do conjunto, caso "e" perten¸ca a ele; se "e" n~ao pertence ao conjunto, mant´em-no inalterado.
            if(pertence(e)){
                noh *aux = sentinela;
                //sentinela->elem = e;

                while(aux->prox->elem != e){
                    aux = aux->prox;
                }

                noh* remover = aux->prox;
                aux->prox = aux->prox->prox;

                delete remover;
            }
            else{
                cout << e << "nao pertence ao conj" << endl;
            }
        }

        bool vazio (){
            return sentinela->prox == nullptr;
        }

        ~ConjuntoDouble () {        // Desaloca a lista encadeada.
            noh* aux = sentinela->prox;
            noh* removido;

            while(aux != nullptr){
                removido = aux;
                aux = aux->prox;
                delete removido;
            }
        }
};

int main () {
    ConjuntoDouble conj;

    cout << endl;

    for(int i = 0; i < 14; i++){
        conj.inserir_sem_testar(i);
    }

    cout << endl;

    for(int i = 7; i < 11; i++){
        conj.inserir(i);
    }

    cout << endl;

    // for(int i = 4; i < 10; i++){
    //     conj.remover(i);
    // }
    
    cout << endl;

    for(int i = 0; i < 14; i++){
        if(conj.pertence(i)){
            cout << i << " pertence." << endl;
        }
        else{
            cout << i << " nao pertence." << endl;
        }
    }

    cout << endl;

    for(int i = 0; i < 14; i++){
        conj.remover(i);
        cout << "removi " << i << endl;
    }

    cout << endl;

    if(conj.vazio()){
        cout << "vazioh ";
    }

    cout << endl;
}