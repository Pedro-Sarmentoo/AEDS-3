// Este algoritmo é por comparação e do grupo dos menos eficientes.
// Bubble Sort
// Coloca o maior no ultimo e vai diminuindo na bolha

#include <stdio.h>

void print_vetor(int vetor[], int tam){
    for(int x = 0; x < tam ; x++) printf("%d ",vetor[x]);
}

int main(){

    int vetor[7] = {9,8,1,2,0,4,7};
    int maior=0,num,bolha = 6;

    for(int i = 0; i < bolha ; i++){
        for(int t = 1; t < bolha ; t++){
            if(vetor[i] < vetor[t]) maior = t;   
        }
        num = vetor[bolha];
        vetor[bolha] = vetor[maior];
        vetor[maior] = num;
        bolha--;
    }
    print_vetor(vetor,7);
    return 0;
}