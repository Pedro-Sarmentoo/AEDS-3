// Este algoritmo é por comparação e do grupo dos menos eficientes.
// Bubble Sort

#include <stdio.h>

void print_vetor(int vetor[], int tam){
    for(int x = 0; x < tam ; x++) printf("%d ",vetor[x]);
}

int main(){

    int vetor[7] = {9,8,1,2,0,4,7};
    int maior=0,num,bolha = 6;

    for(int i = 0; i < 7 ; i++){
        for(int t = 0 ; t < bolha; t++){
            if(vetor[t] > vetor[t + 1]){
                num = vetor[t];
                vetor[t] = vetor[t+1];
                vetor[t + 1] = num;
            }
        }
        bolha--;
    }
    print_vetor(vetor,7);
    return 0;
}