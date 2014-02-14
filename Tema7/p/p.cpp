#include<cstdio>
#include<stdlib.h>
using namespace std;
int main()
{
	int **a,i,n,j;
	scanf("%d",&n);
	FILE *q;
	q=fopen("Triunghi.out","w");
	a = (int **) malloc (n*sizeof(int*));
	a[0]=(int*) malloc (1*sizeof(int));
	a[1]=(int*) malloc (2*sizeof(int));
	a[1][0]=a[1][1]=1;
	a[0][0]=1;
	for(i=2;i<n;i++)
	{
		a[i]=(int*) malloc ((i+1)*sizeof(int));
		a[i][0]=1;
		for(j=1;j<i;j++)
				a[i][j]=a[i-1][j-1]+a[i-1][j];
			a[i][i]=1;
	}
	for(i=0;i<n;i++)
			{
				for(j=0;j<=i;j++)
					fprintf(q,"%d ",a[i][j]);
				  fprintf(q,"\n");
		}
	return 0;
}
	