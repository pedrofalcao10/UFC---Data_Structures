# include <iostream>
#include <cmath>

class registro{
    public:
        int chave;
        registro* prox;
};

class TabelaDispersao_EE_Multiplicacao{
    public:
        registro ** tabela;
        int m; // tamanho da tabela
        int cont; //nú mero de elementos na tabela
        // mé todo construtor , inicializa a tabela
        TabelaDispersao_EE_Multiplicacao (int tamanho ){
            m = tamanho;
            tabela = new registro *[m];
            cont = 0;
        }

        int metodo_multiplicacao (int chave, int m){
            float a = 0.6180339;
            float y;
            double p_i;

            y = modf(chave*a, &p_i);

            modf(y*m, &p_i);

            return p_i;
        }
        
        int inserir ( registro * reg ){ //método inserir
            int pos = metodo_multiplicacao(reg->chave, m);

            if(tabela[pos] == NULL){
                tabela[pos] = reg;
            }
            else{
                reg->prox = tabela[pos];
                tabela[pos] = reg;
            }
        }
        
        // mé todo buscar
        registro * buscar ( int chave ){
            int pos = metodo_multiplicacao(chave, m);

            registro* aux = tabela[pos];

            while(aux != NULL){
                if(aux->chave == chave){
                    return aux;
                }

                aux = aux->prox;

            }
        }
        
        // mé todo remover , devolve um ponteiro para o nó removido
        // não libera o espa ço do nó
        registro * remover ( int chave ){
            int pos = metodo_multiplicacao(chave, m);

            if(tabela[pos] == NULL){
                return NULL;
            }
            else{
                if(tabela[pos]->chave == chave){
                    registro* h = tabela[pos];
                    tabela[pos] = tabela[pos]->prox;
                    
                    return h;
                }
                else{
                    registro* aux = tabela[pos];
                    
                    while(aux->prox != NULL){
                        if(aux->prox->chave == chave){
                            registro* h = aux->prox;
                            aux->prox = aux->prox->prox;
                            
                            return h;
                            
                            break;
                        }

                        aux = aux->prox;
                    }
                }
            }
        }
        
        // mé todo eliminar , remove o nó liberando o espa ço
        void eliminar ( int chave ){
            delete(remover(chave));
        }
};