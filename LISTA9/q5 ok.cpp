#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

class NoRegistro{
    public:
        int chave;
        NoRegistro *prox = NULL;
};

class TabelaDispersao_EE_Multiplicacao{
    public:
        NoRegistro **tabela;
        int m; //tamanho da tabela
        int cont; //número de elementos na tabela
        
        TabelaDispersao_EE_Multiplicacao (int tamanho){ // método construtor, inicializa a tabela
            m = tamanho;
            tabela = new NoRegistro *[m];
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
        
        int inserir (NoRegistro * reg){ //método inserir
            int pos = metodo_multiplicacao(reg->chave, m);

            if(tabela[pos] == NULL){
                tabela[pos] = reg;
            }
            else{
                reg->prox = tabela[pos];
                tabela[pos] = reg;
            }
        }
};

class Registro{
    public:
        int chave;
        int dado;
        Registro *prox = NULL;
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
};

int testeInsercao_TDEEM(int m, int n, NoRegistro *Regs){ //realiza 'n' inserções em uma tabela de tamanho 'm' e retorna o tempo decorrrido
    // os registros que serão inseridos estão no vetor Regs
    
    TabelaDispersao_EE_Multiplicacao TDEEM (m); // cria tabela
    
    int inicio, fim; // registra inicio das inser ções
    
    inicio = clock(); // registra início do procedimento de inser ção
    for (int i = 0; i < n; i++){// insere os nós na tabela
        TDEEM.inserir(& Regs [i]);
    }
    fim = clock ();// registra o final das inserções

    return fim-inicio;
}

int testeInsercao_LISTA(int p, Registro Reg){ //realiza 'n' inserções em uma tabela de tamanho 'm' e retorna o tempo decorrrido
    // os registros que serão inseridos estão no vetor Regs
    
    ListaOrdenada list (p); // cria tabela
    
    int inicio, fim; // registra inicio das inser ções
    
    inicio = clock(); // registra início do procedimento de inser ção
    for (int i = 0; i < p; i++){// insere os nós na tabela
        list.inserir(& Reg);
    }
    fim = clock ();// registra o final das inserções

    return fim-inicio;
}

void inicializa_Chaves_Aleatorias_TDEEM(int n, NoRegistro *Regs){ //inicializa os registros com chaves aleatórias não repetidas
    srand (time (0));

    for (int i = 0; i < n; i ++){
        Regs [i].chave = rand ();
    }
}

void inicializa_Chaves_Aleatorias_LISTA(int n, Registro *Reg){ //inicializa os registros com chaves aleatórias não repetidas
    srand (time (0));

    for (int i = 0; i < n; i ++){
        Reg [i].chave = rand ();
    }
}

int main (){
    int m; //tamanho da tabela de dispersão e multiplicação
    int n; //número de registros a serem inseridos
    cout << " Tamanho da tabela e numero de regs a inserir (m e n):";
    cin >> m >> n;

    NoRegistro *Regs = new NoRegistro [n];// cria registros a serem inseridos nas respectivas estruturas

    inicializa_Chaves_Aleatorias_TDEEM (n, Regs);//inicializa chaves aleatórias

    int duracaoTDEEM = testeInsercao_TDEEM (m, n, Regs);//testa tabela de dispersão com encadeamento externo e mé todo da divis ão

    cout << " Duracao do teste de insercao da tabela: \n";
    cout << " Tamanho da tabela: " << m << "\n";
    cout << " Numero de registros: " << n << "\n";
    cout << " Duracao da insercao: " << (float) 1000*duracaoTDEEM/CLOCKS_PER_SEC << "ms\n";

    
    cout << endl << endl;
    
    
    int p; // tamanho da lista ordenada
    cout << " Tamanho da lista ordenada: ";
    cin >> p;
    
    Registro *Reg = new Registro [p];// cria registros a serem inseridos nas respectivas estruturas

    inicializa_Chaves_Aleatorias_LISTA (p, Reg);//inicializa chaves aleatórias

    int duracaoLISTA = testeInsercao_LISTA (p, *Reg);//testa tabela de dispersão com encadeamento externo e mé todo da divis ão

    cout << " Duracao do teste de insercao da lista: \n";
    cout << " Tamanho da lista: " << p << "\n";
    cout << " Duracao da insercao: " << (float) 1000*duracaoLISTA/CLOCKS_PER_SEC << "ms\n";
}