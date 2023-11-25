#include <stdlib.h>

int main(){

    int tam;
    printf("O vetor terá que tamanho?\n");
    scanf("%d",&tam);
    int vetor[tam];
    for(int i = 0; i < tam; i++){
        printf("Insira o valor %d: ",i);
        scanf("%d",&vetor[i]);
        printf("\n");
    }
    for(int i = 0; i < tam;i++) printf("%d ",vetor[i]);

    return 0;
}