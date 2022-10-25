#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
char CPF[13]; // CPF  do  aluno
char nome[80]; // nome  do  aluno
int numaula; // número  do registro do  tipo  da  aula
}aluno;

typedef struct luta{
int regaula; //registro do  tipo  de aula
int qaluno;//registra a quantidade  de  alunos  matriculados
char modalidade[20]; //exemplo: jiu-jitsu, muay thai, boxe
int grau; // [1]iniciante, [2]intermediário, [3]avançado
float valor; //valor  da  aula
}luta;

void aloca_aluno(aluno **al, int cont);
void aloca_luta(luta **lt, int cont);
void registra_aluno(aluno *al,luta *lt,int cont);
void cadastra_luta(luta *lt, int cont);
void mostra_lutas(luta *lt, int cont);
void elimina_aluno(aluno *al,luta *lt, int cont);
int verifica_vazio(aluno *al, int cont);

main()
{ 
  luta *lt = NULL;
  aluno *al = NULL;

  int cont = 0;
  int vazio;
  int op;
  aloca_luta(&lt,9);
  cadastra_luta(lt,3);

  do{

    printf("REGISTRA ALUNO [1]\nELIMINA ALUNO [2]\nMOSTRAR LUTAS [3]\nSAIR [4]\n");
    scanf("%i",&op);
    fflush(stdin);


    switch(op)
    {
      case 1:
        mostra_lutas(lt,9);
        vazio = verifica_vazio(al,cont);
        if(vazio==-1)
        {
          printf("Entrou");
          aloca_aluno(&al,cont+1);
          cont++;
        }
        registra_aluno(al,lt,cont);
        break;
        case 2:
          elimina_aluno(al,lt,cont);
          break;
        case 3:
          mostra_lutas(lt,9);
          break;
        case 4:
          exit(1);
    }
    printf("\n");
  }while(op != 5);

}

int verifica_vazio(aluno *al, int cont)
{
  int i;
  for(i=0;i<cont;i++,al++)
  {
    if(al->numaula == -1)
    {
      return i;
    }
  }
  return -1;

}

void registra_aluno(aluno *al,luta *lt,int cont)
{
  int i;
  int j;

  
  printf("Registro de Aluno\n\n");
  printf("Nome:");
  gets(al->nome);
  fflush(stdin);
  printf("\nCPF:");
  gets(al->CPF);
  fflush(stdin);

  printf("\nModalidade: [1]jiu-jitsu - [2] muay thai - [3] boxe:");
  scanf("%i",&i);
  fflush(stdin);
  if(i==1)
    i=0;
  else if(i==2)
    i=3;
  else
    i=6;
  fflush(stdin);
  printf("Dificuldade : Noob[1] Intermediario [2]  Expert [3]");
  scanf("%i",&j);
  fflush(stdin);
  al->numaula = i+j;
  j = j-1;
  lt = lt + (i+j);
  lt->qaluno += 1;
  printf("\nRegistro: [%i]",al->numaula);




  system("pause");
  fflush(stdin);
  system("cls");
}

void mostra_lutas(luta *lt, int cont)
{
  int i;
  for(i=i;i<cont;i++,lt++)
  {
  printf("Numero de Registro: [%i]\n",lt->regaula);  
  printf("Nome da modalidade: [%s]\n",lt->modalidade);
  printf("Nivel de Dificuldade: [%i]\n",lt->grau);
  printf("Valor da Aula: [%f]\n",lt->valor);
  printf("Quantidade de Alunos: [%i]\n\n",lt->qaluno);
  }
  system("pause");
  fflush(stdin);

}



void cadastra_luta(luta *lt, int cont)
{
  int i;
  int j;
  
  
  for(i=0;i<cont;i++)
  {
    if(i==0)
    {
      for(j=0;j<3;j++,lt++)
      {
      lt->regaula=i+1;
      lt->qaluno = 0;
      strcpy(lt->modalidade,"jiu-jitsu");
      lt->grau = 1+j;
      lt->valor = 75*(j+1);
      }
    }
    else if(i==1)
    {
      for(j=0;j<3;j++,lt++)
      {
      lt->regaula=i+1;
      lt->qaluno = 0;
      strcpy(lt->modalidade,"muay thai");
      lt->grau = 1+j;
      lt->valor = 50*(j+1);
    }
    }
    else if(i==2)
    {
      for(j=0;j<3;j++,lt++)
      {
      lt->regaula=i+1;
      lt->qaluno = 0;
      strcpy(lt->modalidade,"boxe");
      lt->grau = 1+j;
      lt->valor = 25*(j+1);
    }
    }
  }
}

void elimina_aluno(aluno *al,luta *lt, int cont)
{
	int i;
  char CpF[13];
  printf("\nTirar Aluno");
  printf("Digite o CPF do Aluno");
  printf("\nCPF:");
  scanf("%s",&CpF);
  fflush(stdin);
  for(i = 0; i < cont; i++, al++)
  {
    if(strcmp(al->CPF,CpF) == 0)
    {
      lt = lt + al->numaula-1;
      printf("Nome [%s]\nCPF [%s]\nRegistro [%i]",al->CPF,al->nome,al->numaula);
      printf("\n\nEsse aluno deve pagar [%f] pela a aula de [%s]",lt->valor, lt->modalidade);
      al->numaula = -1;
      lt->qaluno -= 1;
      system("pause");
    }
    else
      printf("\nEsse aluno nao esta cadastrado");
  }
}

void aloca_aluno(aluno **al, int cont)
{
  if((*al=(aluno*)realloc(*al,cont*sizeof(aluno)))==NULL)
    exit(1);
}
void aloca_luta(luta **lt, int cont)
{
  if((*lt=(luta*)realloc(*lt,sizeof(luta)*cont))==NULL)
	exit(1);
}

