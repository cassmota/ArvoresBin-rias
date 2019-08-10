#include <stdio.h>
#include <stdlib.h>

typedef struct Tnode* ArvBin;
typedef struct Tnode{
  int info;

  ArvBin e;
  ArvBin d;

}Tnode;

//Função para criar uma arvore
ArvBin criaArvore()
{
  return NULL;
}

//Função para adicionar um elemento na arvore binaria
void insereNaArvore(ArvBin *T, int num)
{
  if(*T==NULL)
  {
    *T = (ArvBin)malloc(sizeof(ArvBin));
    (*T)->e = NULL;
    (*T)->d = NULL;
    (*T)->info = num;
  }
  else
  {
    if(num < (*T)->info)
    {
      insereNaArvore(&(*T)->e, num);
    }
    else{
      insereNaArvore(&(*T)->d, num);
    }

  }

}//Fim insereNaArvore

int verificaArvore(ArvBin T, int num)
{
  if(T==NULL)
  {
    return -1;
  }
  
  //Verifica a informação do nó e o número buscado
  if(T->info == num){
    printf("%d", T->info);
    return 1;
  }
  
  //Procura recursivamente nas arvores esquerda e direita
  verificaArvore(T->e, num);
  verificaArvore(T->d, num);

  return 0;

}


void mostraArvore(ArvBin T)
{
  printf("<");

  if(T!=NULL)
  {
    printf("%d", T->info);
    mostraArvore(T->e);
    mostraArvore(T->d);
  }

  printf(">");

}

int main()
{
  int check;
  ArvBin T = criaArvore();

  //Mostrando a arvore vazia
  mostraArvore(T);
  printf("\n\n");

  insereNaArvore(&T, 10);
  insereNaArvore(&T, 4);
  insereNaArvore(&T, 16);
  insereNaArvore(&T, 11);
  
  mostraArvore(T);
  
 

  if(verificaArvore(T, 15))
    printf("\n\nNumero esta na Arvore \n");
  else
    printf("\n\nNumero não esta na Arvore \n\n");

  free(T);/* Libera a memória alocada pela estrutura árvore */
  
  return 0;
}
