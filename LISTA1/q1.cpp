#include <iostream>

using namespace std;

int main (){
    int l[10];

    cout << "Insira 5 numeros pares e 5 numeros impares\n";
    for(int i = 0; i < 10; i++){
        cin >> l[i];
    }

    for(int i = 0; i < 10; i++){
        if(l[i]%2 == 0 && i%2 != 0){
            int aux = l[i];
            l[i] = l[i+1];
            l[i+1] = aux;
        }
        else if(l[i]%2 != 0 && i%2 == 0){
            int aux = l[i];
            l[i] = l[i+1];
            l[i+1] = aux;
        }
    }

    for(int i = 0; i < 10; i++){
        cout << l[i] << endl;
    }

    return 0;
}