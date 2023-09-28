// Este algoritmo é por comparação e do grupo dos menos eficientes.
// Selection Sort
#include <stdio.h>

void print_vetor(int vetor[], int tam){
    for(int x = 0; x < tam ; x++) printf("%d ",vetor[x]);
}

int main(){

    int vetor[7] = {9,8,1,2,0,4,7};
    int menor,aux;

    for(int i = 0 ; i < 7 ; i++){
        menor = i;
        for(int t = i ; t < 7 - i ; t++){
            if (vetor[menor] > vetor[t]) menor = t;
        }
        aux = vetor[menor];
        vetor[menor] = vetor[i];
        vetor[i] = aux; 
    }
    print_vetor(vetor,7);
    return 0;
}