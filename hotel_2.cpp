#include <stdio.h>
#include <stdlib.h>

typedef struct quarto{
        int  num;
        char categoria;     //S-solteiro ou F-familiar
        char status;        //L-livre ou O-ocupado
        }quarto;

typedef struct hospede{
        int  quarto;
        char nome[30];
        int  acompanhante;
        int  dias;
        }hospede;

void aloca_quarto(quarto **q,int qtde);
void aloca_hospede(hospede **h,int qtde);
void cadastra_quarto(quarto *q,int qtde);
void cadastra_hospede(hospede *h,quarto *q);
int busca_quarto(quarto *q,char cat);
void check_out(hospede *h,int qtde,quarto *q);
int busca_vago(hospede *h,int qtde,int q);


main()
{
quarto *pq=NULL;
hospede *ph=NULL;
int op,cont=0,pos;
aloca_quarto(&pq,15);
cadastra_quarto(pq,15);
do{
  system("cls");
  printf("\n[1]Check-in \n[2]Check-out \n[3]Fim \nOpcao: ");
  scanf("%i",&op);
  fflush(stdin);
  switch(op)
    {
    case 1: pos=busca_vago(ph,cont,-1);  //procurar quarto=-1
            if(pos==-1)     // nao encontrou  
              {
              aloca_hospede(&ph,cont+1);
              pos=cont;
              cont++;
              }
            cadastra_hospede(ph+pos,pq);
			break;
    case 2: check_out(ph,cont,pq);
            break;
    }
  }while(op!=3);
}//main
    
void aloca_quarto(quarto **q,int qtde)
{
if((*q=(quarto*)realloc(*q,qtde*sizeof(quarto)))==NULL)
  exit(1);
}//aloca_quarto

void aloca_hospede(hospede **h,int qtde)
{
if((*h=(hospede*)realloc(*h,qtde*sizeof(hospede)))==NULL)
  exit(1);
}//aloca_hospede

void cadastra_quarto(quarto *q,int qtde)
{
int i;
for(i=0;i<qtde;i++,q++)
  {
  q->num=i+1;
  q->status='L';
  if(i<5)           //5 quartos de Solteiro
    q->categoria='S';
  else              //10 quartos Familiar
    q->categoria='F';
  }
}//cadastra_quarto

void cadastra_hospede(hospede *h,quarto *q)
{
char cat;
int pessoas,numq;
do{
   printf("\nQtde pessoas - max.4: ");
   scanf("%i",&pessoas);
   fflush(stdin);
   }while(pessoas<0 || pessoas>4);
if(pessoas==1)
  cat='S';
else
  cat='F';
numq=busca_quarto(q,cat);
if(numq==-1)
  printf("\nNao ha vagas\n\n\n");
else
  {
  h->quarto=numq;
  h->acompanhante=pessoas-1;
  printf("\nNome: ");
  gets(h->nome);
  fflush(stdin);
  printf("\nQtos dias: ");
  scanf("%i",&(h->dias));
  fflush(stdin);
  printf("\nCadastro feito com sucesso\nQuarto: %i\n\n\n",h->quarto);
  }
system("pause");
}//cadastro
 
int busca_quarto(quarto *q,char cat)
{
int i;
for(i=0;i<15;i++,q++)
  if(q->categoria==cat && q->status=='L')
    {
    q->status='O';
    return(q->num);
    }
return -1;
}//busca

void check_out(hospede *h,int qtde,quarto *q)
{
int numq,i;
printf("\nQuarto: ");
scanf("%i",&numq);
fflush(stdin);
(q+numq-1)->status='L';
for(i=0;i<qtde;i++,h++)
  if(h->quarto==numq)
    {
    printf("\nNome: %s\n",h->nome);
    if(h->acompanhante==0)
      printf("\nValor a pagar: %.2f\n\n\n",h->dias*85.00);
    else
      printf("\nValor a pagar: %.2f\n\n\n",h->dias*(h->acompanhante+1)*45.00);
    system("pause");
    h->quarto=-1;
    }//if
}//check-out

int busca_vago(hospede *h,int qtde,int q)
{
int i;
for(i=0;i<qtde;i++,h++)
   if(h->quarto==q)
     return i;
return -1;
}//vago
