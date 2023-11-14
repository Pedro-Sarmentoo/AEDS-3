//10 7 13 3 5 4 1 11 12 15

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

void move_mais_dir(FILE *p,Dados temp,Dados antes,int arq[],int c){
  if(antes.dir == -1) return;

  else{
    if(antes.dado < temp.dado){
      fseek(p,antes.dir*sizeof(Dados),SEEK_SET);
      fread(&antes,1,sizeof(Dados),p);
      move_mais_dir(p,temp,antes,arq,c);
    }
  }
}

void move_mais_esq(FILE *p,Dados temp,Dados antes,int arq[],int c){
  if(antes.dado > temp.dado && antes.esq == -1){ // problemas aqui, e se o numero for para a direita?????
    return;
  }
  else if(antes.dado < temp.dado && antes.dir == -1){
    return;
  }

  else{
    if(antes.dado > temp.dado){
      fseek(p,antes.esq*sizeof(Dados),SEEK_SET);
      fread(&antes,1,sizeof(Dados),p);
      move_mais_esq(p,temp,antes,arq,c);
    }
    else if(antes.dado < temp.dado){
      
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

  p = fopen("teste2.bin", "wb+");
    if (!p){
      printf("Arquivo não encontrado\n");
      return 1;
    }

    fread(&temp,1,sizeof(Dados),p); //Lê o arquivo para ver se tem dados
  
    if( temp.dado == 0){
      printf("não tem dados\n");
      temp.dado = arq[0]; temp.esq = temp.dir = -1; //Primeiro Dado
      fwrite(&temp,1,sizeof(Dados),p); //Escreve no arquivo o dado que está em temp
    }
    // o ultimo temp entra aqui
    if (temp.dado != 0){
      printf("tem dados\n");
      
      for(int c = 1;c < (sizeof(arq)/sizeof(int)); c++){
        temp.dado = arq[c]; temp.dir = temp.esq = -1;
        
        fseek(p,0,SEEK_SET);//volta o ponteiro do arquivo para o inicio
        fread(&antes,1,sizeof(Dados),p);
        
       if(antes.dado > temp.dado){// Inserir na direita se não tiver nada
         if(antes.esq == -1){
            antes.esq = c;// coloca a posição no bloco
            fwrite(&antes,1,sizeof(Dados),p);// atualiza o dado com a nova posição
            fseek(p,c*sizeof(Dados),SEEK_SET);// volta o ponteiro do arquivo para a posição antiga
         }
         else{ // caso o bloco já esteja cheio
           move_mais_esq(p,temp,antes,arq,c); //FUNÇÃO PARA DESLOCAR PELA ARVORE
           antes.esq = c;
           fwrite(&antes,1,sizeof(Dados),p);
           fseek(p,c*sizeof(Dados),SEEK_SET);
         }
        }
        else if (antes.dado < temp.dado && antes.dir == -1){ // Inserir na esquerda se não tiver nada
          antes.dir = c;
          fwrite(&antes,1,sizeof(Dados),p);
          fseek(p,c*sizeof(Dados),SEEK_SET);// volta o ponteiro do arquivo para a posição antiga
        }
        
        fwrite(&temp,1,sizeof(Dados),p);
      }
      
      //Comandos para mostrar o primeiro e ultimo dado
      /*fseek(p,0,SEEK_SET);
      fread(&antes,1,sizeof(Dados),p);
      printf("Os dados de antes no inicio são : %d %d %d\n",antes.esq,antes.dado,antes.dir);
      fseek(p,(cont*sizeof(Dados)),SEEK_SET);
      fread(&antes,1,sizeof(Dados),p);
      printf("Os dados de antes são : %d %d %d\n",antes.esq,antes.dado,antes.dir);*/
      
      /*for(fseek(p,0,SEEK_SET);cont < 10 ;cont++ ){ --> Comando para mostrar os dados que esão na variavel antes
        fread(&antes,1,sizeof(Dados),p);
        printf("Os dados de antes são : %d %d %d\n",antes.esq,antes.dado,antes.dir);
      }*/
      
    }
    ler_arquivo(p,x,(sizeof(arq)/sizeof(int) )); //Mostrar todos os dados do arquivo
  
  //fseek(p,2*sizeof(Dados),SEEK_SET); --> comando para andar pelo dados
  //printf("%ld\n",(ftell(p)/sizeof(Dados)) );
  fclose(p);
  printf("Acabou");
  return 0;
}