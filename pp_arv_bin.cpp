#include <iostream>
#include <ctime>

using namespace std;

struct no_arv{
    int elem;
    no_arv *esq, *dir;
};

void inserir(no_arv** raiz, no_arv* no){
    if(*raiz == nullptr) *raiz = no;
    else if(no->elem <= (*raiz)->elem) inserir(&(*raiz)->esq, no); 
    else inserir(&(*raiz)->dir, no);
}

void inserir_ref(no_arv* &raiz, no_arv* no){
    if(raiz == nullptr) raiz = no;
    else if(no->elem <= raiz->elem) inserir_ref(raiz->esq, no); 
    else inserir_ref(raiz->dir, no);
}

void print(no_arv* no, int space){
    if(no == nullptr) return;
    static int w = 5;
    print(no->dir, space + w);
    for(int i = 0; i < space; i++){
        cout << " ";
    }
    cout << no->elem << endl;
    print(no->esq, space + w);
}

int main(){
    no_arv* raiz = nullptr;
    no_arv* no;
    srand(time(NULL));

    for(int i = 0; i < 15; i++){
        no = new no_arv{rand()%100, nullptr, nullptr};
        inserir_ref(raiz, no);
    }
    
    print(raiz, 0);
}