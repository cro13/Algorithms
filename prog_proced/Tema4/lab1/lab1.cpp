#include<stdlib.h>
#include<cstdio>
using namespace std;
int main()
{
	FILE *s;
	int nr=0,x;
		int i,n;
		struct pereche{int *v;
		               float *w;
		}t;
	float y;
	s=fopen("intrare.txt","r");
	//fscanf(s,"%d",&n);
	FILE *p=fopen("iesire.bin","wb");
	//for(i=0;i<n;i++)
	while(fscanf(s,"%d %f",&x,&y)!=EOF)
	{
		nr++;
		fwrite(&x,sizeof(int),1,p);
		fwrite(&y,sizeof(float),1,p);
	}
	//fwrite(&nr,sizeof(int),1,p);
	fclose(p);
	int m;
	FILE *q=fopen("iesire.bin","rb");
	fread(&m,sizeof(int),1,q);
	t.w=(float *)malloc(nr*sizeof(float));
	t.v=(int *)malloc(nr*sizeof(int));
	for(i=0;i<nr;i++)
		{
			fread(&t.v[i],sizeof(int),1,q);
			fread(&t.w[i],sizeof(float),1,q);
	}
	printf("Numarul de perechi este %d \n", nr);
	for(i=0;i<nr;i++)
	{
		printf("%d %f", t.v[i],t.w[i]);
		printf("\n");
	}
	return 0;
}
