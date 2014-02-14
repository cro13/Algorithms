#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
struct nod{int info;
nod *st,*dr;
};
nod *r;
int n,x,k,maxi,k1;
void inserare(nod *&p,int x)
{if(p)
   if(p->info==x)
        g<<"nr deja inserat "<<endl;
   else
     if(p->info<x)
             inserare(p->dr,x);
     else
             inserare(p->st,x);
 
 else
     {p=new nod;
      p->info=x;
      p->st=p->dr=0;}
}
void srd(nod *p)
{
	if(p)
	{
		srd(p->st);
		g<<p->info<<" ";
		srd(p->dr);
	}
}
int main()
{ int i;
	f>>n;
	for(i=1;i<=n;i++)
	{
		f>>x;
		inserare(r,x);
	}
	srd(r);
	return 0;
}
