#include <stdlib.h>
#include <stdio.h>

typedef struct{
  int esq;
  int dir;
  int dado;
}Dados;

void ler_arquivo(FILE *p,Dados x,int tam){
    fopen("agoravai.bin","rb");
    if (!p){
      printf("Arquivo não encontrado\n");
      return;
    }
    rewind(p);
    for(int c = 0; c < tam; c++){
      fread(&x,1,sizeof(Dados),p);
      printf("%d %d %d\n",x.esq,x.dado,x.dir);
    }
}

//10 7 13 3 5 4 1 11 12 15
int main(){
    FILE *p;
    int tam;
    //int vetor[] = {10, 7, 13, 3, 5, 4, 1, 11, 12, 15};
    Dados temp,antes,x;
    int a = 0;
    printf("O vetor tera que tamanho?\n");
    scanf("%d",&tam);
    int vetor[tam];
    for(int i = 0; i < tam; i++){
        printf("Insira o valor %d: ",i);
        scanf("%d",&vetor[i]);
    }

    p = fopen("agoravai.bin","wb+");
    if(!p){
        printf("Arquivo nao encontrado\n");
        return 0;
    }

    for(int i = 0; i < (sizeof(vetor)/sizeof(int)) ; i++){
        if(i == 0){
            temp.dado = vetor[i]; temp.esq = -1; temp.dir = -1;
            fwrite(&temp,1,sizeof(Dados),p);
        }
        else{
            a = 0;
            temp.dado = vetor[i]; temp.esq = -1; temp.dir = -1;
            fwrite(&temp,1,sizeof(Dados),p);
            rewind(p);
            fread(&antes,1,sizeof(Dados),p);
            
            while(a != 1){
                if(antes.dado > temp.dado){//Inserir na esquerda
                    if(antes.esq == -1){
                        antes.esq = i;
                        fseek(p, -sizeof(Dados), SEEK_CUR);
                        fwrite(&antes,1,sizeof(Dados),p);
                        a = 1;
                    }
                    else{
                        fseek(p,antes.esq*sizeof(Dados),SEEK_SET);
                        fread(&antes,1,sizeof(Dados),p);
                    }
                }
                if(antes.dado < temp.dado){//Inserir na direita
                    if(antes.dir == -1){
                        antes.dir = i;
                        fseek(p, -sizeof(Dados), SEEK_CUR);
                        fwrite(&antes,1,sizeof(Dados),p);
                        a = 1;
                    }
                    else{
                        fseek(p,antes.dir*sizeof(Dados),SEEK_SET);
                        fread(&antes,1,sizeof(Dados),p);
                    }
                }
            }
            fseek(p, 0, SEEK_END);
        }
    }
    ler_arquivo(p,x,(sizeof(vetor)/sizeof(int) ));
    fclose(p);
    return 0;
}