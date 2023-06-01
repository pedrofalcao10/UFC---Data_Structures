#include <iostream>

using namespace std;

struct noh{int elem; noh *esq, *dir;};

struct ArvBin{
    noh *raiz;

    ArvBin(): raiz(nullptr){} // arvbin(){raiz = nullptr;}

    void inserir (int e){
        noh *n = new noh{e, nullptr, nullptr};

        if(raiz == nullptr){raiz = n;}
        else{
            noh *atual = raiz;

            for(;;){ //while(true)
                if(n->elem < atual->elem){
                    if(atual->esq == nullptr){
                        atual->esq = n;
                        break;
                    }
                    else{
                        atual = atual->esq;
                    }
                }
                else{
                    if(atual->dir == nullptr){
                        atual->dir = n;
                        break;
                    }
                    else{
                        atual = atual->dir;
                    }
                }
            }
        }
    }

    bool pertence (int e){ // retorna ponteiro p remoção
        noh *n = raiz;

        while (n != nullptr){
            if(e == n->elem) return true;
            if(e < n->elem) n = n->esq;
            else            n = n->dir;
        }
        return false;
    }

    void remover (int e){
        noh *n = raiz, *cima = nullptr;

        while (n != nullptr){
            if(e == n->elem) break;
            else if(e < n->elem){cima = n; n = n->esq;}
            else                {cima = n; n = n->dir;}
        }

        if (n == nullptr) return;

        if(n->esq == nullptr){
            if(cima == nullptr) raiz = n->dir;
            else if(n == cima->esq) cima->esq = n->dir;
            else                    cima->dir = n->dir;
        }
        else if(n->dir == nullptr){
            if(cima == nullptr) raiz = n->esq;
            else if(n == cima->dir) cima->dir = n->esq;
            else                    cima->esq = n->esq;
        }
        else{
            noh *p = n->esq, *cp = n;

            while(p->dir != nullptr){//encontrar predecessor
                cp = p;
                p = p->dir;
            }

            if(p == cp->esq) cp->esq = p->esq;//remover predecessor
            else             cp->dir = p->esq;

            p->esq = n->esq;//substituir n
            p->dir = n->dir;//pelo predecessor
            
            if(cima == nullptr)   raiz = p;
            else if(n==cima->esq) cima->esq = p;
            else                  cima->dir = p;
        }
        delete n;
    }

    /*void remover_melhor (int e){
        noh* *cima = &raiz;
        noh *n;

        for(;;){ //while(true)
            n = *cima; //o ponteiro apontado por "cima"
            if(n == nullptr) return;
            if(e == n->elem) break;
            if(e < n->elem) cima = &(n->esq);
            else            cima = &(n->dir);
        }

        if(n->esq == nullptr) *cima = n->dir;
        else if()
    }*/

    void imprimir_crescente (noh *n){
        if(n != nullptr){
            imprimir_crescente(n->esq);
            cout << n->elem << " \t";
            imprimir_crescente(n->dir);
        }
    }

    void imprimir_arv (){
        imprimir_crescente(raiz);
    }

    void imprimir_prof_subarv (noh *n, int pn){
        if(n != nullptr){
            cout << "prof(" << n->elem << ") = " << pn << endl;
            imprimir_prof_subarv(n->esq, pn+1);
            imprimir_prof_subarv(n->dir, pn+1);
        }
    }

    void imprimir_profundidades (){
        imprimir_prof_subarv(raiz, 0);
    }

    void apagar (noh *n){
        if(n != nullptr){
            apagar(n->esq);
            apagar(n->dir);
            delete(n);
        }
    }

    ~ArvBin (){
        apagar(raiz);
    }
};

int main (){
    ArvBin arv;
    arv.inserir(5);
    arv.inserir(4);
    arv.inserir(8);
    arv.inserir(6);
    arv.inserir(0);
    arv.inserir(7);
    arv.inserir(41);
    arv.inserir(35);
    
    if(arv.pertence(4) == true){
        cout << "4 pertence" << endl;
    }
    arv.imprimir_arv();
    cout << endl;

    arv.remover(5);
    arv.imprimir_arv();
    cout << endl;

    arv.remover(8);
    arv.imprimir_arv();
}
