#include <stdio.h>
#include <stdlib.h>

typedef struct products{

	int id_product;
	char name_product[20];
	float value;

}products;

//--------Verifica se o arquivo foi criado------------

int verifica();

//----------------------------------------------------

void aloca_produtos(products **p, int count);

void cadastra_produtos(products *p, int ver);

void show_products(products *p,int ver);
void store_produtct(products *p);
void edit_products(products *p,int ver);



main(){

//-------------

products *p = NULL;

//-------------
	char op;
	int swt;
	//int count = 0;
	int ver;
//-------------

aloca_produtos(&p,1);

ver=verifica();



do{

	printf("\nCadastramento [1]\nMostra Produtos Cadastrados[2]\n");
	printf("Resposta:");
	scanf("%i",&swt);
	fflush(stdin);

	switch(swt){

		case 1:

			system("cls");
			cadastra_produtos(p,ver+1);
			ver++;
			break;

		case 2:
			show_products(p,ver);
			break;

	}

	printf("Deseja continuar ? (S/N)");
	scanf("%c",&op);
	fflush(stdin);

}while(op != 'N' && op != 'n');
	
	printf("ByE :)");

}

//---------------------Aloca dinamicamente os Produtos-----------------------

void aloca_produtos(products **p, int count)
{
if((*p=(products*)realloc(*p,count*sizeof(products)))==NULL)
	exit(1);
}

//-----------------Coloca o Ponteiro no Final--------------------------

int verifica()
{

long int count = 0;

FILE *f = NULL;

if((f=fopen("products.bin","rb"))==NULL){
	printf("\nErr.Verificacao");
	return count;
}

else
{
	fseek(f,0,2);
	count = ftell(f)/sizeof(products);
	fclose(f);
	return count;
}

}
//-------------------Cadastramento de Produtos-------------------------

void cadastra_produtos(products *p, int ver)

{
	p->	id_product = ver;
	printf("\n-------------------------------\n"); // Basic separation TERMINAL
	printf("\nCadastramento de Produtos Selecionado\n\n\n");
	printf("\n-------------------------------\n\n\n\n\n");
	system("pause");
	system("cls");
	fflush(stdin);
	printf("\nNome do Produto:");
	gets(p->name_product);
	printf("\nID do Produto:");
	scanf("%i",&(p->id_product));
	fflush(stdin);
	printf("\nValor:");
	scanf("%f",&(p->value));
	fflush(stdin);
	store_produtct(p);
	printf("\n-------------------------------\n\n\n\n");
	system("pause");


}

//-------------------Armazena produtos-------------------------

void store_produtct(products *p)
{

	FILE *f = NULL;

if((f = fopen("products.bin","ab+"))==NULL)
	printf("\nStore Err");
else
{
	//fseek(f,sizeof(products),2);

	fwrite(f,sizeof(products),1,f);

	fclose(f); 
}

}
//------------------Mostra os Produtos Cadastrados---------------

void show_products(products *p, int ver)
{

	FILE *f = NULL;

	system("cls");
 	int i;
 	
	 f=fopen("products.bin","rb");
 	
 	for(i=0;i<ver;i++)
 	{
		
 		fseek(f,i*sizeof(products),0); // int fseek (FILE * fluxo, int deslocamento, int origem);

 		fread(f,sizeof(products),1,f); // size_t fread(void * dados, size_t tamanho, size_t numero_itens, FILE * fluxo);

 		printf("\nNome do Produto: %s\nID: %i\nValor: %f",p->name_product,p->id_product,p->value);
 	}
 	fclose(f);
 	system("pause");
}

//---------------------Edita Produtos-------------------

void edit_products(products *p,int ver)
{
	FILE *f = NULL;
	//int i = 1;
	int id;

	if((f=fopen("products.bin","rb+"))==NULL)
		printf("\nEdit Err");
	else
	{
		printf("\nLista de Produtos\n");
		show_products(p,ver);
		printf("\nDigite o ID do Produto:");
		scanf("%i",&id);
		fflush(stdin);
	}
	


}
