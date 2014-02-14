#include<cstdio>
#include<cstdlib>
#include<time.h>
using namespace std;
int main()
{
	int i,n,*v,x;
	FILE *p=fopen("intrare.txt","r");
	FILE *q=fopen("iesire.txt","w");
	fscanf(p,"%d",&n);
	v=(int*)malloc(n*sizeof(int));
	for(i=1;i<=n;i++)
		fscanf(p,"%d",&v[i]);
	srand(time(NULL));
	for(i=1;i<=n;i++)
		fprintf(q,"%d ",v[i]);
	printf("%d",x);
	return 0;
}
