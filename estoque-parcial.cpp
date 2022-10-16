#include <stdio.h>
#include <stdlib.h>

typedef struct dados{
        int    reg;
        char   produto[20];
        int    qtde;
        float  preco;
        }dados;

void aloca(dados **p,int tam);  
int  verifica();  
void cadastro(dados *p,int qreg);    
void grava(dados *p);
void mostra(dados *p,int qreg);

main()
{
dados *pd=NULL;
char op;
int qreg;
aloca(&pd,1);
qreg=verifica();
do{
  cadastro(pd,qreg+1);
  qreg++;
  printf("\nDeseja continuar <S/N>:");
  scanf("%c",&op);
  fflush(stdin);
  }while(op!='n' && op!='N');
mostra(pd,qreg);
}//main

void aloca(dados **p,int tam)
{
if((*p=(dados*)realloc(*p,tam*sizeof(dados)))==NULL)
  exit(1);
}//aloca

int  verifica()
{
long int cont=0;
FILE *fptr=NULL;
if((fptr=fopen("estoque.bin","rb"))==NULL)
  return cont;
else
  {
  fseek(fptr,0,2);  //posiciona no fim do arquivo
  cont=ftell(fptr)/sizeof(dados);   //qtde de elementos
  fclose(fptr);    //dentro do ELSE por conta do rb
  return cont;
  }//else
}//verifica

void cadastro(dados *p,int qreg)
{
p->reg=qreg;
printf("\nRegistro: %i",p->reg);
printf("\nProduto: ");
gets(p->produto);
fflush(stdin);
printf("\nQtde estoque: ");
scanf("%i",&(p->qtde));
fflush(stdin);
printf("\nPreco: ");
scanf("%f",&(p->preco));
fflush(stdin);
grava(p);
}//cadastro

void grava(dados *p)
{
FILE *fptr=NULL;
if((fptr=fopen("estoque.bin","ab"))==NULL)	
  printf("\nErro ao abrir o arquivo");
else
  fwrite(p,sizeof(dados),1,fptr);
fclose(fptr);		//fora do ELSE por conta do ab	
}//grava
	
void mostra(dados *p,int qreg)
{
int i;
FILE *fptr=NULL;
system("cls");
if((fptr=fopen("estoque.bin","rb"))==NULL)
  printf("\nErro ao abrir o arquivo");
else
  {
  for(i=0;i<qreg;i++)
    {
	fseek(fptr,i*sizeof(dados),0);
	fread(p,sizeof(dados),1,fptr);
	printf("\nRegistro: %i\nProduto: %s\nQtde: %i\nPreco: %.2f\n\n",p->reg,p->produto,p->qtde,p->preco);
    }//for
  fclose(fptr);
  }//else
system("pause");
}//mostra
	
	
	
	
	
	
	
	
	
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	


































