#include <iostream>

using namespace std;

class posicao{
    public:
        int l;
        int c;
};

class pilha_posicao{
    public:
        posicao *v;
        int tam_max;
        int topo;
        int count; //número de elementos na pilha
        
        pilha_posicao (int tamanho){ //método construtor, inicializa a pilha
            v = new posicao [tamanho];
            tam_max = tamanho;
            topo = -1;
            count = 0;
        }

        void empilhar(posicao p){ //empilha
            topo++;
            v[topo] = p;
            count++;
        }

        posicao desempilhar(){ //desempilha
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

    int n = 10;

    char m[n][n] = 
    {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'e', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', ' ', '#', ' ', '#', '#', ' ', '#'},
    {'#', '#', '#', ' ', '#', ' ', '#', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', '#', '#', '#', '#'}, 
    {'#', ' ', '#', ' ', '#', ' ', '#', '#', '#', '#'}, 
    {'#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#'}, 
    {'#', ' ', '#', '#', '#', '#', '#', '#', '#', '#'}, 
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 's'}, 
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    pilha_posicao pilha(n*n);
    posicao p;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(m[i][j] == 'e'){
                p.l = i;
                p.c = j;
                pilha.empilhar(p);
                break;
            }
        }
    }

    while(!pilha.vazia()){
        if(m[p.l][p.c] == 's'){
            break;
        }
        else{
            if(m[p.l][p.c + 1] != '#' && m[p.l][p.c + 1] != '.'){//direita

                m[p.l][p.c] = '.';

                //p.l = p.l;
                p.c = p.c + 1;

                pilha.empilhar(p);
                cout << "empilhei (" << p.l << ", " << p.c << ")" << endl;
            }

            else if(m[p.l + 1][p.c] != '#' && m[p.l + 1][p.c] != '.'){//baixo

                m[p.l][p.c] = '.';

                p.l = p.l + 1;
                //p.c = p.c;

                pilha.empilhar(p);
                cout << "empilhei (" << p.l << ", " << p.c << ")" << endl;
            }

            else if(m[p.l][p.c - 1] != '#' && m[p.l][p.c - 1] != '.'){//esquerda

                m[p.l][p.c] = '.';

                //p.l = p.l;
                p.c = p.c - 1;

                pilha.empilhar(p);
                cout << "empilhei (" << p.l << ", " << p.c << ")" << endl;
            }

            else if(m[p.l - 1][p.c] != '#' && m[p.l - 1][p.c] != '.'){//cima

                m[p.l][p.c] = '.';

                p.l = p.l - 1;
                //p.c = p.c;

                pilha.empilhar(p);
                cout << "empilhei (" << p.l << ", " << p.c << ")" << endl;
            }

            else{
                m[p.l][p.c] = '.';

                p = pilha.desempilhar(); // aqui eu só desempilhava, e oq ocorria era eu voltar todas as casas até as entradas sem fazer as comparações com os espaços vazios, mas com a mudança agr dá certo
                cout << "desempilhei (" << p.l << ", " << p.c << ")" << endl;
            }
        }
    }

    cout << endl << "apos percorrer: " << endl;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}