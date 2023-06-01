#include <iostream>

using namespace std;

class posicao{
    public:
        int l;
        int c;
};

class pilhaposicao{
    public:
        posicao *v;
        int tam_max;
        int topo;
        int count; // número de elementos na pilha
        
        pilhaposicao (int tamanho){ //método construtor, inicializa a pilha
            v = new posicao [tamanho];
            tam_max = tamanho;
            topo = -1;
            count = 0;
        }

        void empilhar(posicao p){//empilha
            topo++;
            v[topo] = p;
            count++;
        }

        posicao desempilhar(){//desempilha
            if(count > 0){
                topo--;
                count--;
                return v[topo + 1];
            }
        }

        int vazia(){
            return count == 0;
        }
};

int main (){
    int n;

    cout << "n = ";
    cin >> n;

    pilhaposicao pilha(n*n);
    posicao p;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            p.l = i;
            p.c = j;
            pilha.empilhar(p);

            cout << "empilhei (" << p.l << ", " << p.c << ")" << endl;
        }
    }

    cout << endl;

    while(!pilha.vazia()){
        p = pilha.desempilhar();

        cout << "desempilhei (" << p.l << ", " << p.c << ")" << endl;
    }
}