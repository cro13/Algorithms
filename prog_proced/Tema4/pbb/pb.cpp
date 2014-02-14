#include<cstdio>
#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<time.h>
//+sortare descresc dupa nota iar mai apoi dupa nume
using namespace std;
struct elev{
	char nume[10];
	int nota;
};
int main()
{
	elev *a,aux1;
	int i,n,j;
	FILE *p;
	p=fopen("intrare.txt","r");
	a=(elev *)malloc(n*sizeof(elev));
	fscanf(p,"%d",&n);
	srand(time(NULL));
	for(i=0;i<n;i++)
		{
  			fscanf(p,"%s",&a[i].nume);
			a[i].nota=rand()%10+1;
	}
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(a[i].nota<a[j].nota)
			{
				aux1=a[i];
				a[i]=a[j];
				a[j]=aux1;
				
			}
			else
				if(a[i].nota==a[j].nota)
					if(strcmp(a[i].nume,a[j].nume)>0)
					{
						aux1=a[i];
						a[i]=a[j];
						a[j]=aux1;
					}
	for(i=0;i<n;i++)
		{
			printf(a[i].nume);
			printf(" ");
			printf("%d",a[i].nota);
			printf(" ");
			printf("\n"); 
	}
	return 0;
}

