#include <iostream>
#include <stdexcept>

using namespace std;

class Monte{
    public:
        double *v;
        int tam_max, quant_elem, i;
        bool apaga;

    Monte (double *vetor, int tam_vetor)
    {
        v = *(&vetor);
        tam_max = tam_vetor;
        quant_elem = 0;
        i = 0;

        for(int j = 0; j < tam_vetor; j++) inserir(vetor[j]);
        
        apaga = false;
    }

    int capacidade () {return tam_max;}

    int num_elementos () {return quant_elem;}

    int pai (int i) {return (i-1)/2;}

    int filho_esq (int i) {return 2*i + 1;}

    int filho_dir (int i) {return 2*i + 2;}

    void troca (double &a, double &b)
    {
        double aux = a;
        a = b;
        b = aux;
    }

    void priorizar_insercao () //na inserção as únicas comparações são feitas com os pais
    {
        int aux = i;

        while(aux > 0 && v[aux] > v[pai(aux)]){

            troca (v[aux], v[pai(aux)]);

            aux = pai(aux);
        }
    }

    void inserir (double elem)
    {
        if(i < tam_max){
            v[i] = elem;
            quant_elem++;

            priorizar_insercao();

            i++;
        }
        else throw runtime_error ("Tentativa de insercao com monte cheio!");
    }

    double consultar ()
    {
        if(quant_elem != 0) return v[0];

        throw runtime_error ("Tentativa de consulta com monte vazio!");
    }

    void priorizar_remocao(){
        int aux = 0;

        while(aux < quant_elem){

            if(filho_dir(aux) < quant_elem){
                if(v[filho_dir(aux)] >= v[filho_esq(aux)]){
                    if(v[filho_dir(aux)] > v[aux]){
                        troca(v[filho_dir(aux)], v[aux]);

                        aux = filho_dir(aux);
                    }
                    else return;
                }
                else if(v[filho_esq(aux)] > v[filho_dir(aux)]){
                    if(v[filho_esq(aux)] > v[aux]){
                        troca(v[filho_esq(aux)], v[aux]);

                        aux = filho_esq(aux);
                    }
                }
                else return;
            }
            else if(filho_esq(aux) < quant_elem){
                if(v[filho_esq(aux)] > v[aux]){
                    troca(v[filho_esq(aux)], v[aux]);

                    aux = filho_esq(aux);
                }
                else return;
            }
            else return;
        }
    }
    
    void remover()
    {
        if(quant_elem != 0){
            
            i--;
            v[0] = v[i];
            
            priorizar_remocao();

            quant_elem--;
        }
        else throw runtime_error ("Tentativa de remocao com monte vazio!");
    }
    void esvaziar_ordenando ()
    {
        for(int j = 0; j < tam_max; j++){
            int aux = consultar();
            remover();
            v[i] = aux;
        }
    }

    ~Monte () {if(apaga) delete v;}
};

int main (){
    double v[10] = { 0, 4, 9, 6, 1, 2, 5, 8, 7, 3 }; Monte M(v,10);

    M.esvaziar_ordenando();

    if (M.capacidade() != 10 or M.num_elementos() != 0) return 1;

    for (int j = 0; j < 10; j++) cout << ' ' << v[j];

    cout << '\n';
}