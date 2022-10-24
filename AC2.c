/*

- - - Oficina Autorizada - - --

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct cliente
{
char CPF[13]; //CPF	do	cliente
char nome[80]; //nome	do	cliente	ou	empresa
int numcar; //guarda	o	registro	do	tipo	de	carro
};

typedef struct carro
{
int regcar; //	registro	do tipo	de carro
int qcarro; //	quantidade	de	carro	desse	modelo	e	marca
char modelo; //	descreve o	modelo	– [P]equeno,	[M]édio,	[G]rande
char marca[20]; //	marca	do	produto	– exemplo:	Fiat,	Honda
float valor; //	valor	da	revisão	do	carro
};


void alola_cl(cliente **cl, int cont);
void alola_car(carro **car, int cont);

void cadastro_cl(cliente *cl);
void cadastra_car(carro *car);
void mostra_car(carro *car);





main()
{
	//Ponteiro
	cliente *cl= NULL;
	carro *car= NULL;

	//Variaveis
	char whl1;
	int do1;
	int cont = 0;
	//-----------

	alola_car(&car,10);
	cadastra_car(car);

	do
	{
		printf("\nCadastro[1]\nDescadastro[2]\nSair[3]\nResposta: ");
		scanf("%i",&do1);
		fflush(stdin);

		switch(do1)
		{
			case 1:
				alola_cl(&cl,cont+1);
				mostra_car(car);
				cadastro_cl(cl+cont,car);
				cont++;
				break;
			case 2:

		}

		
	} while (whl1 != 'N' && whl1 != 'n');
	{

	}

}

void alola_cl(cliente **cl, int cont)
{
	if((*cl=(cliente*)realloc(*cl,cont*sizeof(cliente))) == NULL)
	{
		printf("\nErro alola_cl\n");
		exit(1);
	}
}

void alola_car(carro **car, int cont)
{
	if((*car=(carro*)realloc(*car,cont*sizeof(carro))) == NULL)
	{
		printf("\nErro alola_car\n");
		exit(1);
	}
}


void cadastro_cl(cliente *cl, carro *car)
{	

	char whl1;

	do
	{

		printf("\n");

	}while(whl1 != 'N' && whl1 != 'n');

}
/*
int regcar; //	registro	do tipo	de carro
int qcarro; //	quantidade	de	carro	desse	modelo	e	marca
char modelo; //	descreve o	modelo	– [P]equeno,	[M]édio,	[G]rande
char marca[20]; //	marca	do	produto	– exemplo:	Fiat,	Honda
float valor; //	valor	da	revisão	do	carro*/



void cadastra_car(carro *car, int cont)
{

	int i;
	for(i=0;i<cont;i++;)
	{
		car->i+regcar;
		car->qcarro = 10;
		if(i=<2)
		{
			car->modelo='P'; //Chevrolet
			strcpy(car->marca,"Chevrolet");
			car->valor = 150;
			car->qcarro = 2
		}
		else if(2<i=<4)
		{
			car->modelo='M';//Fiat
			strcpy(car->marca,"Fiat");
			car->valor = 175;
			car->qcarro = 2;
		}
		else if(4<i=<6)
		{
			car->modelo='G';//VW
			strcpy(car->marca,"VolksWagem");
			car->valor = 200;
			car->qcarro = 2;
		}
		else if(6<i=<8)
		{
			car->modelo='P';
			strcpy(car->marca,"Jaguar");
			car->valor = 225;
			car->qcarro = 2;
		}
		else
		{
			car->modelo='G';
			strcpy(car->marca,"Honda");
			car->valor = 250;
			car->qcarro = 2;
		}
	}
}

void mostra_car(carro *car)
{
	int i;
	for(i=0;i<cont;i++)
	{
		printf("\nCarro [%c]\n Marca [%s]\n Valor[%f]\nQuantidade no local [%i]\n");

	}
	system("pause");
	fflush(stdin);
}