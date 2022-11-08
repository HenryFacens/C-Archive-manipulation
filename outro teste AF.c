typedef strcut sneakers{
	

}sneakers;

main()
{
	sneakers *sk;
	int ver;
	ver = verify();
	aloca(&sk,ver+1);

	do
	{
	switch()

	{

		case 1:
			register_sneakers(sk,ver);
			ver++;
			break;
	}

	}while();

}

int verify()
{

long int count;

 FILE *f = NULL;

 if(f=fopen("sneakers.bin","ab")==NULL)
 	reuturn count;
 else
 {
 fseek(sk,0,2);
 count=ftell(f)/sizeof(sneakers);
 fclose(f)
 reuturn count;
 }
	
}


void aloca(sneakers **sk,int var)
{
	if((*sk=(sneakers*)realloc(*sk,var*(sneakers)))==NULL)
		exit(1);
}

void store(sneakers *sk){
		
	FILE *f = NULL;

	if(f=fopen("sneakers.bin","ab")==NULL)
		exit(1);
	else
		fwrite(sk,sizeof(sneakers),1,f);

	fclose(sk);
}

void show_elements(sneakers *sk)
{
	
	FILE *f = NULL;
	int i;

	if(f=fopen("sneakers.bin","rb")==NULL)
		exit(1);
	else
	{
	for(i;i<ver;i++)
	fseek(sk,i*sizeof(sneakers),0);
	fread(sk,sizeof(sneakers),1,f);
	printf("",);
	}
	fclose(f);
}