#include <stdio.h>
#include <stdlib.h>


typedef struct pessoas{
	
	char nome[30];
	int idade;
	char CPF[12];
	
	
}pessoas;

typedef struct carros{
	
	char marca[20];
	char car_name[20];
	int year;
	char tamanho[1];
	float price;
	
}carros;

void aloca_pessoas(pessoas **p, int count);
void aloca_carros(carros  **c, int count);

void cadastra_pessoas(pessoas *p,int count);

void grava_p(pessoas *p);
void grava_c(carros *c);

int  verifica();
void cadastra_carros(carros *c,int count);

void mostra_carros_cadastrados(carros *c,int count);
void mostra_dados_clientes(pessoas *p,int count);


main(){
	
	pessoas *p = NULL;
	carros  *c = NULL;
	int count;
	char opdo;
	int swt;
	
	count = verifica();

	aloca_carros(&c,count+1);
	//cadastra_carros(c,10);

	aloca_pessoas(&p,count+1);
	
	printf("\t-----Bem-Vindo-----\n\n\n\n\n\n");
	system("pause");
	fflush(stdin);
	system("cls");
	
	do{
		printf("Cadastrar Pessoas[1]\nCadastrar Carros[2]\n");
		printf("Lista de Clientes[3]\nLista de Carros[4]\n");
		printf("Resposta:");
		scanf("%i",&swt);
		fflush(stdin);
		
		switch(swt){
		
				case 1:
					cadastra_pessoas(p,count+1);
					count++;
					break;
					
				case 2:
					cadastra_carros(c,count);
					break;
				case 3:
					mostra_dados_clientes(p,count);
					break;
					
				case 4:
					mostra_carros_cadastrados(c,count);
					break;
				
				//case 5:
					

		}
		
		printf("Deseja continuar (S/N):");
		scanf("%c",&opdo);
		fflush(stdin);
		
	}while(opdo != 'N' && opdo != 'n');
		
		printf("Obrigado por utilizar o prgrama :)");
		
}

void aloca_pessoas(pessoas **p,int count)
{
if((*p=(pessoas*)realloc(*p,count*sizeof(pessoas)))==NULL)
  exit(1);
}


void aloca_carros(carros **c,int count)
{
if((*c=(carros*)realloc(*c,count*sizeof(carros)))==NULL)
  exit(1);
}


void cadastra_pessoas(pessoas *p,int count)
{	
	char op;

	do{	
	system("cls");
	printf("Nome:");
	gets(p->nome);
	printf("\nCPF:");
	gets(p->CPF);
	printf("\nIdade:");
	scanf("%i",&p->idade);
	fflush(stdin);
	grava_p(p);
	printf("\n\nCliente Cadastrado com Sucesso :))");
	printf("\n\n-----------------------------------");
	printf("\n\nDeseja Cadastrar outra pessoa ?");
	scanf("%c",&op);
	fflush(stdin);
	
	
	}while(op != 'n' && op != 'N');
		
	
}

void grava_p(pessoas *p){
	
	FILE *f = NULL;
	fseek(f,sizeof(pessoas),2);
if((f=fopen("pessoas.bin","ab"))==NULL)
	printf("\nErr");
else
	fwrite(p,sizeof(pessoas),1,f);
fclose(f);

}



void grava_c(carros *c){
	
	FILE *f = NULL;

if((f=fopen("carros.bin","ab"))==NULL)

	printf("\nErr");

else
	fwrite(c,sizeof(pessoas),1,f);

fclose(f);

}


void mostra_dados_clientes(pessoas *p,int count)
{
int i;

FILE *f = NULL;

system("cls");

if((f=fopen("pessoas.bin","rb"))==NULL)
  printf("\n\nErr");
else
  {
  for(i=0;i<count;i++)
    {
fseek(f,i*sizeof(pessoas),0);

fread(p,sizeof(pessoas),1,f);

printf("\nNome: %s\nIdade: %i\nCPF: %s\n\n\n",p->nome,p->idade,p->CPF);

    }

  fclose(f);

  }

system("pause");
}

int  verifica()
{
	
long int cont=0;

FILE *f=NULL;

if((f=fopen("pessoas.bin","rb"))==NULL)

  return cont;
  
else

  {
  fseek(f,0,2);
  cont=ftell(f)/sizeof(pessoas); 
  fclose(f); 
  return cont;
  
  }
  
}


void cadastra_carros(carros *c,int count){

	char op;

	do{
		printf("\nMarca:");
		gets(c->marca);
		printf("\nNome do Carro:");
		gets(c->car_name);
		printf("\nAno do Carro");
		scanf("%i",&c->year);
		fflush(stdin);
		printf("\nTamanho(G/M/P)");
		gets(c->tamanho);
		printf("\nValor:");
		scanf("%f",&c->price);
		fflush(stdin);
		grava_c(c);

	printf("\n\nCarro Cadastrado com Sucesso !!");
	printf("\n\n-----------------------------------");
	printf("\n\nDeseja Cadastrar outro carro ?");
	scanf("%c",&op);
	fflush(stdin);

	}while(op != 'N' && op != 'n');


}

void mostra_carros_cadastrados(carros *c,int count)
{
int i;

FILE *f = NULL;

system("cls");

if((f=fopen("carros.bin","rb"))==NULL)
  printf("\n\nErr");
else
  {
	
  for(i=0;i<count;i++)
    {
fseek(f,i*sizeof(carros),0);
fread(c,sizeof(carros),1,f);

printf("\nMarca: %s\nNome do Carro: %s\nAno do Carro: %i\nTamanho: %s\n Preco: %i\n\n\n",c->marca,c->car_name,c->year,c->tamanho,c->price);

    }

  fclose(f);

  }

system("pause");
}
