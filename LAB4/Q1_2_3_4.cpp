#include <iostream>
#include <stdexcept>

using namespace std;

class Monte{
    public:  // Pre-condicao: tam_max >= 1.
    double *v;
    int tam_max, quant_elem, i;

    Monte (int tam)
    {
        v = new double[tam];
        tam_max = tam;
        quant_elem = 0;
        i = 0;
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
            v[0] = v[i];
            i--;

            priorizar_remocao();

            quant_elem--;
        }
        else throw runtime_error ("Tentativa de remocao com monte vazio!");
    }

    ~Monte () {delete v;}
};

int main (){
    Monte M(10);
    
    if (M.capacidade() != 10 or M.num_elementos() != 0) return 1;

    for (double j = 0; j < 10; j++) {
        M.inserir (j);
        cout << M.consultar() << " ";
    }

    cout << "\n" << "Maximo: " << M.consultar() << '\n';

    while (M.num_elementos() != 0){
        cout << "Remocao de " << M.consultar() << '\n';
        M.remover ();
    }
}