// Este algoritmo é por comparação e do grupo dos menos eficientes.
// Insertion Sort

#include <stdio.h>

int main(){

    int vetor[10] = {5,1,8,2,6,9,3,7,4,10};
    int num,aux;

    for(int i = 1 ; i < 10 ; i++ ){
        num = vetor[i];
        for(int t = i - 1 ; t >= 0 ; t--){
            if(num < vetor[t]){
                aux = vetor[t];
                vetor[t] = num;
                vetor[t + 1] = aux;
            }
        }


    }

    return 0;
}