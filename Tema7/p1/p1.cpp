#include<iostream>
#include<cstring>
using namespace std;
struct nod{
	char cuv[20];
	nod *st, *dr;
};
nod *r;
void creare(nod *&p, char x[20])
{
	if(p==0)
	{
		p=new nod;
		strcpy(p->cuv,x);
		p->st=0;
		p->dr=0;
	}
	else
		if(strcmp(p->cuv,x)>0)
			creare(p->dr,x);
		else
			if(strcmp(p->cuv,x)<0)
				creare(p->st,x);
}
void srd(nod *p)
{
	if(p)
	{
		srd(p->st);
		printf(p->cuv);
		printf(" ");
		srd(p->dr);
	}
}
int main()
{
	int n;
char x[20];
	   scanf("%d",&n);
	   for(int i=1;i<=n;i++)
		   {
			   scanf("%s",x);
			   creare(r,x);
	   }
	   
srd(r);
return 0;
}