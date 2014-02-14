#include<fstream.h>
#include<iostream.h>
fstream f("nr.in",ios::in);
struct nod{int info;
	   nod *leg;
	  };
nod *prim;

void adaugf(nod *&prim,int x)
{nod *nou=new nod;
 nou->info=x;
 nou->leg=prim;
 prim=nou;
}

void inserare(nod *prim,int x)
{nod *p=prim;
 while(p->leg->info<x&&p->leg)p=p->leg;
 nod *nou=new nod;
 nou->info=x;
 nou->leg=p->leg;
 p->leg=nou;
}
void citire()
{int x;
 while(f>>x)
 if(x<prim->info||prim==0)adaugf(prim,x);
  else inserare(prim,x);
}

void afis(nod *prim)
{nod *p=prim;
 while(p){cout<<p->info<<" ";p=p->leg;}
 cout<<endl;
}

int main()
{citire();
 afis(prim);
 return 0;
}
