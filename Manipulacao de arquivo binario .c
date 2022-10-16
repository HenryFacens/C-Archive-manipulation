#include <stdio.h>
#include <stdlib.h>


typedef struct pessoas{
	
	char nome[30];
	int idade;
	char CPF[12];
	
	
}pessoas;

typedef struct carros{
	
	char tipos_de_carros[20];
	int tamanho;
	
}carros;

void aloca_pessoas(pessoas **p, int count);
void aloca_carros(carros  **c, int count);
void cadastra_pessoas(pessoas *p);
void grava_p(pessoas *p);
void grava_c(carros *c);
void mostra_dados_clientes(pessoas *p,int count);


main(){
	
	pessoas *p = NULL;
	carros  *c = NULL;
	int count = 0;
	char opdo;
	int swt;
	


	aloca_carros(&c,10);
	aloca_pessoas(&p,count+1);
	
	printf("\t-----Bem-Vindo-----\n\n\n\n\n\n");
	system("pause");
	fflush(stdin);
	system("cls");
	
	do{
		printf("Cadastrar Pessoas[1]\nCadastrar Produtos[2]\n");
		printf("Mostrar Produtos[3]\n");
		printf("Resposta:");
		scanf("%i",&swt);
		fflush(stdin);
		
		switch(swt){
		
				case 1:
					
					cadastra_pessoas(p+count);
					count++;
					break;
					
				case 3:
					mostra_dados_clientes(p,count);
					break;
					
				//case 3:
					
				//case 4:
				
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
void cadastra_pessoas(pessoas *p)
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
FILE *f=NULL;

system("cls");

if((f=fopen("pessoas.bin","rb"))==NULL)
  printf("\n\nErro ao abrir o arquivo");
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



