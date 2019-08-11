//https://pt.wikibooks.org/wiki/Programar_em_C/%C3%81rvores_bin%C3%A1rias
//https://repl.it/languages/c

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

int altura(ArvBin T)
{
  int he, hd;

  if(T == NULL)
  {
    return -1;
  }

  he = altura(T->e);
  hd = altura(T->d);

  if(he>hd)
  {
    return 1 + he;
  }
  else
  {
    return 1 + hd;
  }

}

int contanoh(ArvBin T)
{
  if(T==NULL)
    return 0;
  else
    return 1 + contanoh(T->e)+contanoh(T->d);

}

int verificaOrdenacao(ArvBin T)
{
  int x, i;
  i=0;
  
  x = contanoh(T);

  int vetor[x];

  
  if(T==NULL)
    return -1;
  else{
 
    verificaOrdenacao(T->e);
    
    vetor[i] = T->info;
    i=i+1;

    verificaOrdenacao(T->d);
  }
  
  for(i=0;i<=x;i++){
    if(vetor[i]<=vetor[i+1])
    {
      printf("\n Vetor[i] - %d", vetor[i]);
      printf("\n Vetor[i+1] - %d", vetor[i+1]);
      continue;
      
    }
    else{
      
      return 1;
    }
  }

  return 0;

}


//Função para contar o número de nós filhos
int contaFilho(ArvBin T)
{

  if(T==NULL)
    return -1;

  //se for um nó folha retorna 1
  if((T->e==NULL)&&(T->d == NULL))
  {
    return 1;
  }
  else
  {
    //chama recursivamente a função somando os nós folhas
    return contaFilho(T->e)+contaFilho(T->d);

  }

  
}

int main()
{
  int check;
  ArvBin T = criaArvore();

  //Mostrando a arvore vazia
  mostraArvore(T);
  printf("\n\n");

  insereNaArvore(&T, 10);
  //insereNaArvore(&T, 4);
  //insereNaArvore(&T, 3);
  //insereNaArvore(&T, 5);
  insereNaArvore(&T, 16);
  //insereNaArvore(&T, 11);
 // insereNaArvore(&T, 17);
  //insereNaArvore(&T, 18);
  
  mostraArvore(T);
  
  if(verificaArvore(T, 15))
    printf("\n\nNumero esta na Arvore \n");
  else
    printf("\n\nNumero não esta na Arvore \n\n");


  printf("A altura da árvore é: %d",altura(T));

 
  printf("\n\nO Número de Filhos da árvore é: %d",contaFilho(T));

  printf("\n\nO Número de nós da árvore é: %d\n",contanoh(T));


  
  if(verificaOrdenacao(T)==0)
    printf("\n\nArvore Ordenada");
  else
    printf("\n\nNão Ordenada");

  free(T);/* Libera a memória alocada pela estrutura árvore */
  
  return 0;
}
