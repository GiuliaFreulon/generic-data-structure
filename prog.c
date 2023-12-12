#include "gcofo.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct aluno{ 
  char nome[30];
  int matricula; 
  float nota; 
}Aluno; 

int cmpNome(void *item, void *chave){
  Aluno *pi;
  char *pc;
  pi = item;
  pc = chave;

  if(strcmp(pi->nome, pc) == 0){
    return 1;
  }
  else{return 0;}
}

int cmpMatricula(void *item, void *chave){
  Aluno *pi;
  int *pc;
  pi = item;
  pc = chave;

  if(pi->matricula == *pc){
    return 1;
  }
  else{return 0;}
}

int cmpNota(void *item, void *chave){
  Aluno *pi;
  float *pc;
  pi = item;
  pc = chave;

  if(pi->nota == *pc){ 
    return 1;
  }
  else{return 0;}
}



int main(void){ 
  gCofo *gcofo; 
  Aluno *a; 
  int tam, matrchave, aux, loop = 0, operacao, limite = 0;
  char nomechave[30];
  float notachave;

  printf("Insira o tamanho do seu cofo: ");
  scanf("%d", &tam);
  printf("\n");
      
  gcofo = gcofoCriar(tam);
      
  if(gcofo != NULL){ 
    printf("Cofo criado\n");
    loop = 1;
  }
  else{
    printf("Cofo não criado");
  }

  while (loop == 1){
    printf("\nEscolha uma opção: \n1 - INSERIR ALUNO\n2 - REMOVER ALUNO\n3 - ENCONTRAR ALUNO\n4 - LISTAR ELEMENTOS DO COFO\n5 - ESVAZIAR COFO\n6 - DESTRUIR COFO\n");
    scanf("%d", &operacao);
  
    switch(operacao){
      case 1 : 
        if(limite<tam){
          a = malloc(sizeof(Aluno));
          if(a != NULL){ 
              printf("\nInsira o nome do aluno no cofo: ");
              scanf ("%s", &a->nome); 
              printf("Insira a matrícula do aluno no cofo: ");
              scanf ("%d", &a->matricula); 
              printf("Insira a nota do aluno no cofo: ");
              scanf ("%f", &a->nota); 
              gcofoInserir(gcofo, (void *)a); 
            }
          limite++;
        }
        else{printf("\nTamanho limite do cofo atingido\n");}
      break;

      
      case 2 : 
          printf("\nInsira o nome, a matrícula e a nota do aluno que deseja remover: ");
          scanf("%s %d %f", &nomechave, &matrchave, &notachave); 
          a = gcofoEncontrar(gcofo, &nomechave, cmpNome);
            if(a != NULL){ 
              a = gcofoEncontrar(gcofo, &matrchave, cmpMatricula);
              if(a != NULL){ 
                a = gcofoEncontrar(gcofo, &notachave, cmpNota);
                if(a != NULL){ 
                  a = gcofoRemover(gcofo, &notachave, cmpNota);
                  printf("\nAluno removido\n");
                }
                else{printf("\nNão foi possível remover o aluno\n");}
              }
              else{printf("\nNão foi possível remover o aluno\n");}
            }
            else{
              printf("\nNão foi possível remover o aluno\n");
            }
      break;

      
      case 3 : 
        printf("\n\nInsira o nome, a matrícula e a nota do aluno que deseja encontrar: ");
      scanf("%s %d %f", &nomechave, &matrchave, &notachave);
      a = gcofoEncontrar(gcofo, &nomechave, cmpNome);
      if(a != NULL){ 
        a = gcofoEncontrar(gcofo, &matrchave, cmpMatricula);
        if(a != NULL){ 
          a = gcofoEncontrar(gcofo, &notachave, cmpNota);
          if(a != NULL){ 
        printf("\nAluno encontrado\n");
          }
          else{printf("\nNão foi possível encontrar o aluno\n");}
        }
        else{printf("\nNão foi possível encontrar o aluno\n");}
      }
      else{
        printf("\nNão foi possível encontrar o aluno\n");
      }
      break;

      
      case 4 : 
        printf("\nListando os elementos da coleção\n");
        
        a = gcofoPrimeiro(gcofo); 
        while(a != NULL){ 
          printf("%s %d %.1f ", a->nome, a->matricula, a->nota); 
          a = gcofoProximo(gcofo); 
        } 
        printf("\n");
      break;


       case 5 : 
        printf("\nEsvaziando o cofo\n");
        aux = gcofoEsvaziar(gcofo); 
        if(aux == 1){ 
          printf("Cofo esvaziado\n"); 
        } 
        else{
          printf("Cofo não esvaziado\n"); 
        }
      break;

          
      case 6 : 
        printf("\nDestruindo o cofo\n");
        aux = gcofoDestruir(gcofo); 
        if(aux == 1){ 
          printf("Cofo destruído\n"); 
          loop = 0;
        } 
        else{
          printf("Cofo não destruído\n"); 
        }
      break;

      
      default : 
        printf("Opção inválida\n");
        loop = 0; 
      break;
    }
  }
  return 0;
}
