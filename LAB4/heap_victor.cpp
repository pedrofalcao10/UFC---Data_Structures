#include <iostream>
#include <stdexcept>
using namespace std;

class Monte{
    public:
        double *v;
        int tam_max, quant_elem, i;
        bool x;

    Monte(double *vetor, int tam_vetor)
    {
        v = *(&vetor);
        tam_max = tam_vetor;
        quant_elem = 0;
        i = -1;
        for(int j=0; j<tam_vetor;j++) inserir(vetor[j]);
        x=false;
    }

    ~Monte (){if(x){delete v;}}

    int capacidade(){return tam_max;}

    int num_elementos(){return quant_elem;}

    int pai(int indice){ indice = (indice-1)/2; return indice; }

    void troca_posicao(double &a, double &b){
        double aux = a;
        a = b;
        b = aux;
    }

    void priorizar_insercao(int posicao){
        int posicao_prox = posicao;

        while(posicao_prox != 0){
            posicao_prox = pai(posicao_prox);

            if(v[posicao_prox] < v[posicao]){
                troca_posicao(v[posicao], v[posicao_prox]);
            }
            else return;

            posicao = pai(posicao);
        }
    }

    void inserir(double elem){
        if(i > tam_max){ 
            throw runtime_error ("Tentativa de insercao com monte cheio!");
            return;
        }

        i++;
        v[i]=elem;
        quant_elem++;
        priorizar_insercao(i) ;
    }

    double consultar(){
        if(i==-1){throw runtime_error ("Tentativa de consulta com monte cheio!");}
        return v[0];
    }

    void priorizar_remocao(){
        int aux=0, filho_dir, filho_esq;

        while(aux < quant_elem){
            filho_dir = 2*aux+2;
            filho_esq = 2*aux+1;

            if(filho_dir < quant_elem){
                if(v[filho_dir]>=v[filho_esq]){
                    if(v[filho_dir] > v[aux]){
                        troca_posicao(v[filho_dir], v[aux]);

                        aux=filho_dir;
                    }
                    else return;
                }
                else if(v[filho_esq]>v[filho_dir]){
                    if(v[filho_esq] > v[aux]){
                        troca_posicao(v[filho_esq], v[aux]);

                        aux=filho_esq;
                    }
                    else return;
                }
            }
            else if(filho_esq < quant_elem){
                if(v[filho_esq] > v[aux]){
                    troca_posicao(v[filho_dir], v[aux]);

                    aux=filho_esq;
                }
                else return;
            }
            else return;
        }
    }

    void remover(){
        if(i==-1){throw runtime_error ("Tentativa de remo¸c~ao com monte vazio!");}

        v[0] = v[i];
        i--;

        priorizar_remocao();

        quant_elem--;
    }

    void esvaziar_ordenando(){
        for(int j = 0; j < tam_max; j++){
            int aux = consultar();
            remover();
            v[i+1] = aux;
        }
    }
};

int main (){
    double v[10] = { 0, 4, 9, 6, 1, 2, 5, 8, 7, 3 }; Monte M(v,10);

    M.esvaziar_ordenando();

    if (M.capacidade() != 10 or M.num_elementos() != 0) return 1;

    for (int j = 0; j < 10; j++) cout << ' ' << v[j];

    cout << '\n';
}