# include <cstdio >
class Posicao{
    public:
        int l;
        int c;
};

int main (){
    Posicao* v;

    int n = 10;

    v = new Posicao [n];

    for(int i = 0; i < n; i++){
        v[i].l = i*i;
        v[i].c = (n-i)*i;
    }

    for(int i = 0; i < n; i ++){
        printf("A linha e %d e a coluna e %d\n", v[i].l, v[i].c);
    }

}