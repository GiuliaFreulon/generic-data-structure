#ifndef _GCOFO_H_ 
#define _GCOFO_H_ 

typedef struct gcofo gCofo;

gCofo *gcofoCriar (int max_itens); 
int gcofoInserir (gCofo *c, void *item); 
void *gcofoRemover (gCofo *c, void *chave, int (*cmp)(void*, void*)); 
void *gcofoEncontrar (gCofo *c, void *chave, int (*cmp)(void*, void*)); 
void *gcofoPrimeiro (gCofo *c); 
void *gcofoProximo (gCofo *c); 
int gcofoEsvaziar (gCofo *c);
int gcofoDestruir (gCofo *c);

#endif