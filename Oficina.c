#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cliente{
char CPF[13]; //CPF do  cliente
char nome[80]; //nome   do  cliente ou  empresa
int numcar; //guarda    o   registro    do  tipo    de  carro
}cliente;

typedef struct carro{
int regcar; //  registro    do tipo de carro
int qcarro; //  quantidade  de  carro   desse   modelo  e   marca
char modelo; // descreve o  modelo  â€“ [P]equeno,    [M]Ã©dio,    [G]rande
char marca[20]; //  marca   do  produto â€“ exemplo:  Fiat,   Honda
float valor; // valor   da  revisÃ£o do  carro
}carro;


void aloca_carro(carro **car, int count);
void aloca_cliente(cliente **cl, int count);
int verifica_vazio(cliente *cl, carro *car, int count);
void cadastra_cliente(cliente *cl, carro *car);
void cadastra_carro(carro *car, int count);
void mostra_carros(cliente *cl, carro *car, int count);
void exclui_cliente(cliente *cl, carro *car, int count);
void mostra_carros_entrada(cliente *cl, carro *car, int count);
void mostra_dados_cl(cliente *cl, carro *car, int count);

//clinte *cl, carro *car, int count

main()
{
    carro *car = NULL;
    cliente *cl = NULL;
    char op;
    int sw;
    int vazio;
    int count = 0;

    aloca_carro(&car,9);
    cadastra_carro(car,9);

    do
    {
        printf("\nCadastra [1]\nExclui Cliente [2]\nMostra Carros [3]\nMostrar Clientes [4]\nCarros Cadastrados no Local [5]\nSair [6]\n\n\n\nResposta: ");
        scanf("%i",&sw);
        fflush(stdin);
		system("cls");
        switch(sw)
        {
            case 1:
            vazio = verifica_vazio(cl,car,count);
                if(vazio == -1)
                {   
                    aloca_cliente(&cl,count+1);
                    
                }
                cadastra_cliente(cl+count,car);
                count++;
                break;
            case 2:
                exclui_cliente(cl,car,count);
                break;
            case 3:
                mostra_carros(cl,car,9);
                break;
            case 4:
            	mostra_dados_cl(cl,car,count);
                break;
            case 5:
            	mostra_carros_entrada(cl,car,9);
            	break;
            	//exit(1);
            case 6:
            	printf("Obrigador por utilizar");
            	exit(1);

        }
        
        printf("\n\nDeseja Fazer outra execucao ? (S ; N)");
        scanf("%c",&op);
        fflush(stdin);
        
    }while(op != 'N' && op != 'n');
}

void mostra_dados_cl(cliente *cl, carro *car, int count)
{

    int i;
    char CpF[13];
		
		printf("CPF Cliente: ");
        scanf("%s",&CpF);
        fflush(stdin);
		
        for(i=0;i<count;i++,cl++)
        {
            if(strcmp(cl->CPF,CpF) == 0 && cl->numcar != -1)
            {
                printf("\nNome do cliente : [%s]",cl->nome);
                printf("\nRegistro de Carro [%i]",car->regcar);
                printf("\nModelo cadastrado : [%c]",car->modelo);
                printf("\nValor da Revisao do Carro : [%.2f]",car->valor);
                printf("\nMarca do Carro: [%s]\n\n",car->marca);

                system("pause");
                system("cls");
                break;
            }
        }

}


void exclui_cliente(cliente *cl, carro *car, int count)
{
    int i;
    char CpF[13];

        printf("CPF Cliente: ");
        scanf("%s",&CpF);
        fflush(stdin);
        for(i=0;i<count;i++,cl++)
        {
            if(strcmp(cl->CPF,CpF) == 0 && cl->numcar != -1)
            {   
                car = car + cl->numcar-1;
                printf("\nNome :[%s]",cl->nome);
                printf("\nRegistor do Carro [%i]",car->regcar);
                printf("\nModelo escolhido [%c]",car->modelo);
                printf("\nValor a ser pago [%f]",car->valor);
                      cl->numcar = -1;
                car->qcarro -= 1;
                system("pause");

            }

        }



}


void cadastra_cliente(cliente *cl, carro *car)
{
    int i;
    int j;

    printf("\nNome: ");
    gets(cl->nome);
    printf("\nCPF :");
    gets(cl->CPF);
    printf("\nModelo de entrada FIAT [1] Volvo [2] Ferrari [3]\n\nResposta: ");
    scanf("%i",&i);
    fflush(stdin);
    if(i==1)
        {i=0;}
    else if(i==2)
        {i=3;}
    else
        {i=6;}
    printf("\n Tamanho do Carro de entrada\n\n");
    printf("[1] Pequeno,    [2] MÃ©dio,  [3] Grande\n\nResposta :");
    scanf("%i",&j);
    fflush(stdin);
    cl->numcar = j+i;
    j = j-1;	
    car = car + (i+j);
    car->qcarro += 1;
    printf("\n\nRegistro [%i]",cl->numcar);
    system("cls");
    fflush(stdin);

}



void cadastra_carro(carro *car, int count)
{
    int i;
    int j;

    for(i=0;i<count;i++)
    {
        if(i==0)
        {
            for(j=0;j<3;j++,car++)
            {
            	if(j==0)
					car->modelo = 'P';
				else if (j==1)
					car->modelo = 'M';
				else
					car->modelo = 'G';
                car->regcar = j+1;
                strcpy(car->marca,"FIAT");
                car->qcarro = 0;
                car->valor = 150*j+1;
            }
        }
            else if(i==1)
        {
            for(j=0;j<3;j++,car++)
            {
            	if(j==0)
					car->modelo = 'P';
				else if (j==1)
					car->modelo = 'M';
				else
					car->modelo = 'G';
                car->regcar = j+1;
                strcpy(car->marca,"Volvo");
                car->qcarro = 0;
                car->valor = 250*j+1;
            }
        }
            else if(i==2)
        {
            for(j=0;j<3;j++,car++)
            {
            	if(j==0)
					car->modelo = 'P';
				else if (j==1)
					car->modelo = 'M';
				else
					car->modelo = 'G';
                car->regcar = j+1;
                strcpy(car->marca,"Ferrari");
                car->qcarro = 0;
                car->valor = 500*j+1;
            }
        }
    }

}

void mostra_carros(cliente *cl, carro *car, int count)
{	
system("cls");
    int i;
        for(i=0;i<count;i++,car++)
        {
            //printf("\nQuantidades no Local [%i]",car->qcarro);
            printf("\nTamanho [%c]",car->modelo);
            printf("\nMarca [%s]",car->marca);
            printf("\nValor [%f]\n\n",car->valor);
        }
}



void mostra_carros_entrada(cliente *cl, carro *car, int count)
{	
system("cls");
    int i;
        for(i=0;i<count;i++,car++)
        {
        	if(car->qcarro != 0){
			
            printf("\nQuantidades no Local [%i]",car->qcarro);
            printf("\nTamanho [%c]",car->modelo);
            printf("\nMarca [%s]",car->marca);
            printf("\nValor [%f]\n\n",car->valor);
			}
        }
}



void aloca_cliente(cliente **cl, int count)
{
    if((*cl=(cliente*)realloc(*cl,count*sizeof(cliente)))==NULL)
        exit(1);
}


void aloca_carro(carro **car, int count)
{
    if((*car=(carro*)realloc(*car,count*sizeof(carro)))==NULL)
        exit(1);
}


int verifica_vazio(cliente *cl, carro *car, int count)
{
    int i;
        for(i=0;i<count;i++,cl++)
        {
            if(cl->numcar == -1)
            {
                return i;
            }
        }
        return -1;
}
