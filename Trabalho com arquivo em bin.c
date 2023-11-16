//10 7 13 3 5 4 1 11 12 15

#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int esq;
  int dir;
  int dado;
}Dados;

void ler_arquivo(FILE *p,Dados x,int tam){
    fopen("teste.bin","rb");
    if (!p){
      printf("Arquivo não encontrado\n");
      return;
    }
    fseek(p,0,SEEK_SET);
    for(int c = 0; c < tam; c++){
      fread(&x,1,sizeof(Dados),p);
      printf("%d %d %d\n",x.esq,x.dado,x.dir);
    }
}

int main(void) {
    FILE *p;
    int arq[] = {10,7,13,3,5,4,1,11,12,15};
    Dados temp; temp.dado = temp.esq = temp.dir = 0;
    Dados antes; antes.dado = antes.esq = antes.dir = 0;
    Dados x,atual; atual.dado = atual.esq = atual.dir = 0;
    int primeiro,ultimo;

    p = fopen("teste.bin","wb+");
        for (int c = 0; c < sizeof(arq)/sizeof(int); c++){
          if(temp.dado == 0){// Caso não tenha dados
            temp.dado = arq[c]; temp.dir = temp.esq = -1;
            fwrite( &temp, 1, sizeof(Dados), p);
          }
          else{
            printf("O ponteiro esta no %d depois do for\n",(ftell(p)/sizeof(Dados)));
            ultimo = (ftell(p)/sizeof(Dados));
            rewind(p);
            fread(&antes,1,sizeof(Dados),p);
            if( ){

            }
            temp.dado = arq[c]; temp.dir = temp.esq = -1;
            fwrite( &temp, 1, sizeof(Dados), p);
          }
                
        }

        /*
        fseek(p,-2*sizeof(Dados),SEEK_END);
        fread(&temp,1,sizeof(Dados),p);
        printf("O ponteiro esta no %d depois do for\n",(ftell(p)/sizeof(Dados)));
        printf("%d %d %d\n",temp.esq,temp.dado,temp.dir);
        fseek(p,1*sizeof(Dados),SEEK_CUR);
        printf("O ponteiro esta no %d depois do for\n",(ftell(p)/sizeof(Dados)));*/
        
    ler_arquivo( p, x, ( sizeof(arq)/sizeof(int)) );
    fclose(p);
    printf("Acabou\n");
    return 0;
}