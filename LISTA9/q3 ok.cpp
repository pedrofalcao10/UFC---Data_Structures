#include <iostream>
#include <algorithm>

using namespace std;

class Registro{
    public:
        int chave;
        int dado;
};

class ListaOrdenada{
    public:
        Registro **L; // vetor de ponteiros de registros
        int tam_max; // tamanho máximo da lista
        int count; //número de elementos na lista
        
        ListaOrdenada (int tamanho){//método construtor, inicializa a lista
            tam_max = tamanho ;
            L = new Registro *[tam_max]();
            count = 0;
        }

        void swap(Registro *a, Registro *b){
            Registro aux = *a;
            *a = *b;
            *b = aux;
        }

        int busca_inserir(int valor){
            int ini = 0, fim = count-1, meio;

            while(ini <= fim){
                int meio = (ini + fim)/2;

                if(L[meio]->chave == valor){
                    return meio;
                }
                else{
                    if(L[meio]->chave < valor){
                        ini = meio + 1;
                    }
                    else{
                        fim = meio - 1;
                    }
                }
            }
            return fim + 1;
        }

        int inserir(Registro *reg){//método inserir, retorna a posição do registro inserido no vetor
            if(count == 0){
                L[count++] = reg;
                return 0;
            }

            int p = busca_inserir(reg->chave);
            
            L[count++] = reg;

            for(int i = count-1; i > p; i--){
                swap(L[i], L[i-1]);
            }

            return p;
        }
        
        Registro* buscar(int valor){ // método buscar, implementa busca binária
            int ini = 0, fim = count-1, meio;
            
            while(ini <= fim){
                meio = (ini + fim)/2;

                if(L[meio]->chave == valor){
                    return L[meio];
                }
                else{
                    if(L[meio]->chave < valor){
                        ini = meio + 1;
                    }
                    else{
                        fim = meio - 1;
                    }
                }
            }
            return nullptr;
        }

        Registro* remover(int valor){//método remover, retira da lista e devolve ponteiro para o registro removido
            int ini = 0, fim = count-1, meio;

            while(ini <= fim){
                meio = (ini + fim)/2;

                if(L[meio]->chave < valor){
                    ini = meio + 1;
                }
                else if(L[meio]->chave > valor){
                    fim = meio - 1;
                }
                else{
                    for(int i = meio; i < count-1; i++){
                        swap(L[i], L[i+1]);
                    }
                    return L[count--];
                }
            }
            return nullptr;
        }
};
