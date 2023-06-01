// -----------------------------------------------------------------------------
// Universidade Federal do Ceará, Centro de Ciências, Departamento de Computação
// Disciplina: Estruturas de Dados - TI0140 2022.2 T02A
// Professor: Pablo Mayckon Silva Farias
// Trabalho 2
// Interface para Implementação de Dicionário baseado em árvore AVL.
// Autor: Pablo Mayckon Silva Farias, em 22/11/2022.
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// IDENTIFICAÇÃO DO(A) ESTUDANTE:
//
// NOME: PEDRO LEINOS FALCÃO CUNHA
// MATRÍCULA: 542114
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Tudo o que está presente na interface abaixo deve ser mantido como está,
// pois é essa interface que será utilizada no programa do professor para a
// realização dos testes.
//
// A realização do trabalho consiste portanto em *completar* a implementação
// abaixo, tornando-a funcional e atendendo aos requisitos deste trabalho.
// -----------------------------------------------------------------------------

#include <iostream>
#include <exception>

using namespace std;

struct DicioAVL{
    typedef double TC;  // Tipo das Chaves
    typedef float  TV;  // Tipo dos Valores

    struct Noh {TC chave; TV valor; int altura; Noh *esq, *dir;};

    Noh sent, *raiz;  // "sent": Sentinela.

    // Conforme a declaração acima, a implementação deve usar um nó sentinela,
    // que representará as subárvores vazias. Assim, por exemplo, os campos
    // "esq" e "dir" das folhas, ao invés de serem ponteiros nulos, apontarão
    // para "sent"; idem para o ponteiro "raiz", quando a árvore estiver vazia.
    // O campo "altura" da sentinela deve sempre valer zero.

    // --------------------------------------------------------------------------

    // Deve criar um dicionário vazio.

    DicioAVL ():raiz(&sent){
        sent.chave = 0;
        sent.valor = 0;
        sent.altura = 0;
        sent.dir = sent.esq = nullptr;
    }

    // --------------------------------------------------------------------------

    // Deve desalocar a árvore AVL.

    void apaga (Noh *no)
    {
        if(no != &sent){
            apaga(no->esq);
            apaga(no->dir);

            delete no;
        }
    }

    ~DicioAVL ()
    {
        apaga(raiz);
    }

    // --------------------------------------------------------------------------

    // Deve inserir a chave "c" e o valor "v" no dicionário, partindo da
    // PRÉ-CONDIÇÃO de que a chave "c" não existe no dicionário -- ou seja,
    // a função não precisa nem deve fazer esse teste.
    //
    // A função deve retornar um ponteiro apontando para o novo nó.
    // Em caso de falha de alocação de memória, a função deve retornar &sent.
    //
    // ATENÇÃO: a chave deve permanecer no mesmo nó enquanto não for removida
    // -------  do dicionário. Isso significa que, antes de tal remoção,
    //          deve ser possí­vel acessar a chave e seu valor a partir do
    //          ponteiro retornado pela função de inserção.

    int max (int x, int y)
    {
        if(x > y){return x;}
        else     {return y;}
    }
    
    void rot_esq (Noh* *noh1)
    {
        Noh* noh2 = *noh1;
        Noh* subarv = (*noh1)->dir;
    
        noh2->dir = subarv->esq;
        subarv->esq = noh2;

        *noh1 = subarv;
    
        noh2->altura = max(noh2->esq->altura, noh2->dir->altura) + 1;
        subarv->altura = max(subarv->esq->altura, subarv->dir->altura) + 1;
    }

    void rot_dir (Noh* *noh1)
    {
        Noh *noh2 = *noh1;
        Noh *subarv = (*noh1)->esq;
    
        noh2->esq = subarv->dir;
        subarv->dir = noh2;

        *noh1 = subarv;
    
        noh2->altura = max(noh2->esq->altura, noh2->dir->altura) + 1;
        subarv->altura = max(subarv->esq->altura, subarv->dir->altura) + 1;
    }

    int balanceamento (Noh *noh)
    {
        if(noh == &sent) return 0;

        return noh->dir->altura - noh->esq->altura;
    }

    void corrigir_AVL (Noh* *noh){
        
        (*noh)->altura = max((*noh)->esq->altura, (*noh)->dir->altura) + 1;

        int balanco = balanceamento(*noh);
    
        if (balanco < -1)
        {
            if(balanceamento((*noh)->esq) > 0) { rot_esq(&(*noh)->esq); } // esq dir

            rot_dir(noh); // dir
        }
        else if (balanco > 1)
        {
            if(balanceamento((*noh)->dir) < 0) { rot_dir(&(*noh)->dir); } // dir esq

            rot_esq(noh); // esq
        }
    }

    void inserir_rec(Noh** raiz, Noh* no)
    {
        if(*raiz == &sent)
        {
            *raiz = no;
            return;
        }
        else if(no->chave < (*raiz)->chave) inserir_rec(&(*raiz)->esq, no); 
        else inserir_rec(&(*raiz)->dir, no);

        corrigir_AVL(raiz);
    }

    Noh* inserir (TC c, TV v)
    {
        try
        {
            Noh* no = new Noh {c, v, 1, &sent, &sent};

            inserir_rec(&raiz, no);

            return no;
        }
        catch(const std::exception& e)
        {
            return nullptr;
        }
    }

    // --------------------------------------------------------------------------

    // Deve retornar um ponteiro para o nó de chave "c", caso essa chave exista
    // no dicionário; caso a chave não esteja presente, deve retornar &sent.

    Noh* buscar (TC c)
    {
        Noh *aux = raiz;

        while(aux != &sent){
            if(aux->chave == c){
                return aux;
            }
            else if(aux->chave <= c){
                aux = aux->dir;
            }
            else{
                aux = aux->esq;
            }
        }

        return nullptr;
    }

}; // DicioAVL  ------------------------------------------------------------

int main (){
    DicioAVL dic;

    dic.inserir(204, -21);
    dic.inserir(32, 46);
    dic.inserir(896, 72);
    dic.inserir(366, 25);
    dic.inserir(4, 3);

    if(dic.buscar(204)){
        cout << "achou" << endl;
    }
    else{
        cout << "nao achou" << endl;
    }
    
    if(dic.buscar(32)){
        cout << "achou" << endl;
    }
    else{
        cout << "nao achou" << endl;
    }
    
    if(dic.buscar(896)){
        cout << "achou" << endl;
    }
    else{
        cout << "nao achou" << endl;
    }
    
    if(dic.buscar(366)){
        cout << "achou" << endl;
    }
    else{
        cout << "nao achou" << endl;
    }

    if(dic.buscar(4)){
        cout << "achou" << endl;
    }
    else{
        cout << "nao achou" << endl;
    }

    if(dic.buscar(-9999)){
        cout << "achou" << endl;
    }
    else{
        cout << "nao achou" << endl;
    }
}