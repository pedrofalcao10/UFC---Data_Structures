#include <stdio.h>
#include <stdlib.h>

int main (){
    int n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0, n6 = 0, n7 = 0;
    int n8 = 0, n9 = 0, n10 = 0, n11 = 0, n12 = 0, n13 = 0, n14 = 0;
    int n;
    
    printf("Insira o tamanho 'n' da sequencia: ");
    scanf("%d", &n);

    int l[n];

    printf("Insira a sequencia: ");
    for(int j = 0; j < n; j++){
        scanf("%d", &l[j]);
    }

    int i = 0;
    n1++;

    while(i < n){
        n2++;

        if(l[i]%3 == 0){
            n3++;

            l[i] = l[i]/3;
            n4++;

            l[i] = l[i]*l[i];
            n5++;
        }
        else{
            n6++;

            if(l[i]%3 == 1){
                n7++;

                printf("Uhuuuuu! ");
                n8++;
            }
            else{
                n9++;

                if(l[i]%3 == 2){
                    n10++;

                    l[i] *= i;
                    n11++;

                    l[i] /= 3;
                    n12++;

                    l[i]--;
                    n13++;
                }
            }
        }

        i++;
        n14++;
    }
    n2++; //entra no loop pra conferir se i < n mais uma vez, daí sai do loop

    printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d", n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14);
}