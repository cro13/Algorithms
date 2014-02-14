#include<cstdio>
#include<stdlib.h>
using namespace std;
void afisl(FILE*q,int**a,int m,int n,int i,int j)
{
	int k;
	for(k=j;k<m;k++)
		 fprintf(q,"%d ",a[i][k]);
}
void afisc(FILE*q,int **a,int m,int n,int j, int i)
{
	int k;
	for(k=i;k<n;k++)
		fprintf(q,"%d ",a[k][j]);
}
int main()
{
	FILE *p,*q;
	int **a,n,m,i,j;
	p=fopen("intrare.txt","r");
	q=fopen("iesire.txt","w");
	fscanf(p,"%d %d",&n,&m);
	a = (int **) malloc (n*sizeof(int*));
	for(i=0;i<n;i++)
     a[i]=(int*) malloc (m*sizeof(int)); 
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			fscanf(p,"%d",&a[i][j]);
		for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
					fprintf(q,"%d ",a[i][j]);
				  fprintf(q,"\n");
		}
		 fprintf(q,"\n");
		 //afisl(0);
		 i=0;
		j=0;
	while(i<n&&j<m)
	{
		
		afisl(q,a,m,n,i,j);
		fprintf(q,"\n");
		afisc(q,a,m,n,m-1,i);
		fprintf(q,"\n");
		afisl(q,a,m,n,n-1,j);
		fprintf(q,"\n");
		afisc(q,a,m,n,j,i);
		fprintf(q,"\n");
		i++;j++;m--;n--;
	}
	return 0;
	
}
