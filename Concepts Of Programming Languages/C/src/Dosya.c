#include "Dosya.h"
#include "Kisi.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Dosya Dosyaa()
{
	Dosya this;
	this = (Dosya)malloc(sizeof(struct DOSYA));
	this->topOfList=NULL;
	this->endOfList=NULL;
	this->ReturnNumbers = &returnNumbers;
	this->ReturnKisi = &returnKisi;
	this->DeleteItemFromArray=&deleteItemFromArray;
	this->ReturnNumberOfKisi=&returnNumberOfKisi;
	this->ReturnNumberOfSayi=&returnNumberOfSayi;
	return this;
}
int returnNumberOfKisi(Dosya dosya){
	char line[500];
	FILE *ptr;
	ptr = fopen("C:\\Users\\ASUS\\Documents\\GitHub\\SAU-Assignments-and-Projects\\Concepts Of Programming Languages\\C\\src\\Kisiler.txt", "r");
	int counter=0;
	while (fgets(line, sizeof(line), ptr))
	{
		
			

		
		
        
		counter++;

	}
	return counter;

}

int returnNumberOfSayi(Dosya dosya){
	char line[500];
	FILE *ptr;
	ptr = fopen("C:\\Users\\ASUS\\Documents\\GitHub\\SAU-Assignments-and-Projects\\Concepts Of Programming Languages\\C\\src\\Sayilar.txt", "r");
	int counter=0;
	while (fgets(line, sizeof(line), ptr))
	{
		
			

		
		
        
		counter++;

	}
	return counter;

}
void remove_spaces(char *s)
{
	char *d = s;
	do
	{
		while (*d == ' ')
		{
			++d;
		}
	} while (*s++ = *d++);
}
int *returnNumbers(Dosya dosya)
{
	int size=returnNumberOfSayi(dosya);
	int* array=(int*)malloc(sizeof(int)*returnNumberOfSayi(dosya));
	int counter = 0;

	FILE *ptr;
	char number;
	ptr = fopen("C:\\Users\\ASUS\\Documents\\GitHub\\SAU-Assignments-and-Projects\\Concepts Of Programming Languages\\C\\src\\Sayilar.txt", "r");

	if (NULL == ptr)
	{
		// printf("file can't be opened \n");
	}

	char line[500];
	while (fgets(line, sizeof(line), ptr))
	{

		remove_spaces(line);
		int number_line = atoi(line);
		array[counter] = number_line;
		

		counter++;
	}
	
	

	return array;
}
void deleteItemFromArray(Dosya dosya,Kisi* kisiler,int position){
	int i;
	int size=1000;
	for(i=position-1; i<size-1; i++)
        {
            kisiler[i] = kisiler[i + 1];
        }

       
        

}
struct Kisi* returnKisi(Dosya dosya)
{

	int counter = 0;
	int counter2 = 0;
	char *delimiter = "#";
	char *token;
	FILE *ptr;
	char number;

	ptr = fopen("C:\\Users\\ASUS\\Documents\\GitHub\\SAU-Assignments-and-Projects\\Concepts Of Programming Languages\\C\\src\\Kisiler.txt", "r");

	if (NULL == ptr)
	{
		 printf("file can't be opened \n");
	}
	
	char line[1000];
	Kisi* kisiler=(Kisi*)malloc(returnNumberOfKisi(dosya)*sizeof(Kisi));
	while (fgets(line, sizeof(line), ptr))
	{
			char* isim=(char*)malloc(40);
			float para;
			float yatirilanParaOrani;
			int sansliSayi;
			token = strtok(line, delimiter);

		while (token != NULL)
		{
			

			if (counter2 == 0)
			{
				strcpy(isim,token);
				
			}
			else if (counter2 == 1)
			{
				para=atof(token);
			}
			else if (counter2 == 2)
			{
				yatirilanParaOrani=atof(token);
			}
			else if (counter2 == 3)
			{
				sansliSayi=atoi(token);
			}
			
			token = strtok(NULL, delimiter);
			counter2++;
		}
		counter2=0;
		Kisi kisi=Kisii(isim,para,yatirilanParaOrani,sansliSayi);
		
	    kisiler[counter]=kisi;
        
		counter++;

	}

	
	
	
	
	
	
	
	return kisiler;

}

