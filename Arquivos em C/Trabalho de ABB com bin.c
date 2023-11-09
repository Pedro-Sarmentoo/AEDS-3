// 10 7 13 3 5 4 1 11 12 15

#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int esq;
  int dir;
  int dado;
}Dados;

void ler_arquivo(FILE *p,Dados x,int tam){
    fopen("teste2.bin","rb");
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

void inserir(FILE *p,Dados temp,int arq[],int tam,int c){
  if(tam == 0) return;
  
  fopen("teste2.bin","ab");
    if (!p){
      printf("Arquivo não encontrado\n");
      return;
    }
    else{
      fread(&temp,1,sizeof(Dados),p); //Lê o arquivo para ver se tem coisa
      if( temp.dado == 0){
        printf("não tem nenhum dado\n");
        temp.dado = arq[0]; temp.esq = temp.dir = 5;
        fwrite(&temp,1,sizeof(Dados),p);
        inserir(p,temp,arq,tam-1,c+1);
      }
      else{
        printf("tem dados\n");
        temp.dado = arq[c]; temp.esq = temp.dir = -1;
        fwrite(&temp,1,sizeof(Dados),p);
        inserir(p,temp,arq,tam,(c+1));
      }
    }
}

int main(void) {
  FILE *p;
  int arq[] = {10,7,13,3,5,4,1,11,12,15};
  Dados temp,x;
  Dados *ant;
  Dados antes;
  int cont = 0;

  p = fopen("teste2.bin", "rb+");
    if (!p){
      printf("Arquivo não encontrado\n");
      return 1;
    }

    fread(&temp,1,sizeof(Dados),p); //Lê o arquivo para ver se tem coisa
    if( temp.dado == 0){
      printf("não tem dados\n");
      temp.dado = arq[0]; temp.esq = temp.dir = 5;
      fwrite(&temp,1,sizeof(Dados),p);
    }
    if (temp.dado != 0){
      printf("tem dados\n");
      for(int c = 1;c < 10; c++){
          temp.dado = arq[c]; temp.dir = temp.esq = -1;
          fwrite(&temp,1,sizeof(Dados),p);
      }
      for(fseek(p,0,SEEK_SET);cont < 10 ;cont++ ){
        fread(&antes,1,sizeof(Dados),p);
        printf("Os dados de antes são : %d %d %d\n",antes.esq,antes.dado,antes.dir);
        if (temp.dado < antes.dado){
          antes.esq = cont;
        }
        else{
          antes.dir = cont;
        }
      }
    }
    //inserir(p,temp,arq,10,0);
    ler_arquivo(p,x,(sizeof(arq)/sizeof(int) ));
  //fseek(p,2*sizeof(Dados),SEEK_SET);
  //printf("%ld\n",(ftell(p)/sizeof(Dados)) );
  fclose(p);
  printf("Acabou");
  return 0;
}