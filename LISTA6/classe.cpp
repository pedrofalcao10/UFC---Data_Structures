# include <cstdio >
class Posicao{
    public:
        int l, c; // linha // coluna
        // mehtodo construtor, inicializa a posição
        Posicao(int linha, int coluna){
            l = linha ;
            c = coluna ;
        }
};

int main (){
    
    Posicao p(10, 15); // criando um objeto do tipo Posicao na variável p
    
    printf ("A linha eh %d e a coluna eh %d\n\n", p.l, p.c);
    printf (" Digite a linha da posicao: ");
    scanf ("%d", &p.l);

    printf (" Digite a coluna da posicao: ");
    scanf ("%d", &p.c);

    printf (" Agora a linha eh %d e a coluna eh %d\n\n", p.l, p.c);

    p.l = 17;
    p.c = 18;

    printf ("Ja agora a linha eh %d e a coluna eh %d\n\n", p.l, p.c);
}