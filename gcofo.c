#ifndef _GCOFO_C_ 
#define _GCOFO_C_
#include "gcofo.h"
#include <stdlib.h>

typedef struct gcofo{ 
int numItens; 
int maxItens; 
int cur; 
void **itens; 
} gCofo;

gCofo *gcofoCriar (int n){
  gCofo *c;
  if(n>0){ //Verifica se n é válido
    c = malloc(sizeof(gCofo));
    if(c != NULL){ //Verifica se alocou a struct c
      c -> itens = malloc(sizeof(void*) * n);
      if(c -> itens != NULL){ //Verifica se alocou o vetor itens
        c -> numItens = 0;
        c -> maxItens = n;
	      c -> cur = 0;
        return c; //Retorna o endereço de um gcofo vazio se conseguiu criá-lo
      }
      free(c); //Desaloca c
    }
  }
  return NULL; //Retorna NULL se não conseguiu criar o gcofo
}

int gcofoInserir (gCofo *c, void *item){
  if(c != NULL){ //Verifica se o cofo foi criado
    if(c->numItens < c->maxItens){ //Verifica se ainda tem espaço no vetor
      c -> itens[c->numItens] = item;
      c -> numItens++;
      return 1; //Indica que inseriu o item (TRUE)
    }
  }
  return 0; //Indica que não inseriu o item (FALSE)
}

void *gcofoRemover (gCofo *c, void *chave, int (*cmp)(void*, void*)){
  int i=0; 
  void *data;
  int stat = cmp(c->itens[i], chave); //Compara o item i com a chave
  if(c != NULL){ //Verifica se o cofo foi criado
    if(c->numItens > 0){ //Verifica se existem itens no vetor
      while(i+1 < c->numItens && stat != 1){ 
        //Armazena no i a posição do item que se quer remover
        i++;
	      stat = cmp(c->itens[i], chave); //Retorna 1 se chegou no item desejado
      }
      if(stat == 1){ 
        data = c->itens[i];
        for(int j=i; j < c->numItens; j++){
          c -> itens[j] = c->itens[j+1]; 
          //Substitui o item da chave pelo da frente e reordena o vetor
        }
        c -> numItens--;
        return data; //Indica que removeu o item e o retorna
      }
    }
  }
  return NULL; //Retorna NULL se não conseguiu remover o item
}

void *gcofoEncontrar (gCofo *c, void *chave, int (*cmp)(void*, void*)){
  void *data;
  if(c != NULL){ //Verifica se o cofo foi criado
    if (c->numItens > 0){ //Verifica se existem itens no vetor
      int i=0;
      int stat = cmp(c->itens[i], chave);
      while(i+1 < c->numItens && stat != 1){ 
        //Armazena no i a posição do item que se quer encontrar
        i++;
	      stat = cmp(c->itens[i], chave); //Retorna 1 se chegou no item desejado
      }
      if(stat == 1){ 
        data = c->itens[i];
        return data; //Indica que encontrou o item e o retorna
      }
    }
  }
  return NULL; //Indica que não encontrou o item
}

void *gcofoPrimeiro (gCofo *c){
  if(c != NULL){ //Verifica se o cofo foi criado
	  if(c->numItens > 0){ //Verifica se existem itens no vetor
		  c->cur = 0; //Pega a posição do primeiro item
		  return c->itens[c->cur]; //Indica que conseguiu encontrar o primeiro item e o retorna
    }
  }
  return NULL; //Retorna NULL se não encontrou o primeiro item
}

void *gcofoProximo (gCofo *c){
  if(c != NULL){ //Verifica se o cofo foi criado
	  c->cur++;
	  if(c->cur < c->numItens){ //Verifica se existe um próximo item no vetor
		  return c->itens[c->cur]; //Indica que conseguiu encontrar o próximo item e o retorna
    }
  }
  return NULL; //Retorna NULL se não encontrou o próximo item
}

int gcofoEsvaziar (gCofo *c){
  if(c != NULL){ //Verifica se o cofo foi criado
	  c->numItens = 0;
		return 1; //Indica que conseguiu esvaziar o cofo
    }
  return 0; //Indica que não conseguiu esvaziar o cofo
}

int gcofoDestruir (gCofo *c){
  if(c != NULL){ //Verifica se o cofo foi criado
    if (c->numItens == 0){ //Garante que o vetor está vazio
      free(c->itens); //Libera o vetor de itens
      free(c); //Libera a struct c
      return 1; //Indica que destruiu o cofo
    }
  }
  return 0; //Indica que não destruiu o cofo
}

#endif