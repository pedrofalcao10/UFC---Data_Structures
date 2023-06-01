#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class NoRegistro{
    public:
        int chave;
        NoRegistro *prox = NULL;
};

class TabelaDispersao_EE_Divisao{
    public :
        NoRegistro **tabela;
        int m; //tamanho da tabela
        int cont; //número de elementos na tabela
        
        TabelaDispersao_EE_Divisao(int tamanho){ //método construtor, inicializa a tabela
            m = tamanho ;
            tabela = new NoRegistro *[m];
            cont = 0;
        }

        int metodo_divisao(int chave, int m){
            return chave%m;
        }
        
        int inserir(NoRegistro * reg){ //método inserir
            int pos = metodo_divisao(reg->chave, m);

            if(tabela[pos] == NULL){
                tabela[pos] = reg;
            }
            else{
                reg->prox = tabela[pos];
                tabela[pos] = reg;
            }
        }
};

int testeInsercao_TDEED(int m, int n, NoRegistro *Regs){ //realiza n inserções em uma tabela de tamanho m e retorna o tempo decorrrido
    // os registros que serão inseridos estão no vetor Regs
    
    TabelaDispersao_EE_Divisao TDEED (m); // cria tabela
    
    int inicio , fim; // registra inicio das inser ções
    
    inicio = clock(); // registra início do procedimento de inser ção
    
    for ( int i = 0; i < n; i ++){// insere os nós na tabela
        TDEED.inserir (& Regs [i]);
    }
    
    fim = clock();// registra o final das inser ções

    return fim-inicio;
}

void inicializa_Chaves_Aleatorias_TDEED(int n, NoRegistro * Regs){     // inicializa os registros com chaves aleatórias não repetidas
    srand (time (0));

    for (int i = 0; i < n; i ++){
        Regs [i].chave = rand ();
    }
}

int main (){
    int m; //tamanho da tabela de dispersão e divisão
    int n; //número de registros a serem inseridos
    cout << " Tamanho da tabela e numero de regs a inserir (m e n):";
    cin >> m >> n;

    NoRegistro *Regs1 = new NoRegistro [n];// cria registros a serem inseridos nas respectivas estruturas

    inicializa_Chaves_Aleatorias_TDEED (n, Regs1);//inicializa chaves aleatórias

    int duracaoTDEED = testeInsercao_TDEED (m, n, Regs1);//testa tabela de dispersão com encadeamento externo e mé todo da divis ão

    cout << " Duracao do teste de insercao\n";
    cout << " Tamanho da tabela: " << m << "\n";
    cout << " Numero de registros: " << n << "\n";
    cout << " Duracao da insercao: " << (float) 1000*duracaoTDEED/CLOCKS_PER_SEC << "ms\n";
}