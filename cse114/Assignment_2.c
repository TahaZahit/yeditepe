#include<stdio.h>

int main(){
	int pmin,pmax,hpmin,hpmax,ts,dvd,print=0;

	printf("Minimum Price:");
	scanf("%d",&pmin);
	printf("Maximum Price:");
	scanf("%d",&pmax);
	printf("Minimum HP:");	
	scanf("%d",&hpmin);
	printf("Maximum HP:");	
	scanf("%d",&hpmax);
	printf("Top Speed:");
	scanf("%d",&ts);
	printf("DVD (0 for No, 1 for Yes):");
	scanf("%d",&dvd);

	if(dvd){
		if(30000>=pmin && pmax>=40000 && 350>=hpmin && hpmax>=360 && ts>=180){
			printf("Audio\n");
			print=1;
		}
		if(35000>=pmin && pmax>=40000 && 350>=hpmin && hpmax>=360 && ts>=200){
			printf("Volvo\n");
			print=1;
		}
		if(41000>=pmin && pmax>=50000 && 380>=hpmin && hpmax>=400 && ts>=220){
			printf("BMW\n");
			print=1;
		}
	}
	else{
		if(10000>=pmin && pmax>=15000 && 230>=hpmin && hpmax>=250 && ts>=130){
			printf("Peugeot\n");
			print=1;
		}

		if(15000>=pmin && pmax>=25000 && 250>=hpmin && hpmax>=300 && ts>=140){
			printf("Renault\n");
			print=1;
		}
		if(20000>=pmin && pmax>=25000 && 300>=hpmin && hpmax>=320 && ts>=155){
			printf("Opel\n");
			print=1;
		}
	}

	if(print==0) 
		printf("No matching cars\n");

}
