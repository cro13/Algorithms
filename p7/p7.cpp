#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
struct nod{int info;
               nod *next;};
nod *varf,*ultim,*varf1,*ultim1,*varfx,*ultimx;
int v[100];
int n,a,k;
void push(nod* &v,nod* &sf,int x)
{nod *c;
if(!v)
    {v=new nod;
     v->info=x;
     v->next=0;
     sf=v;}
 else
     {c=new nod;
      sf->next=c;
      c->info=x;
      sf=c;
      sf->next=0;}
}
 
void afisare(nod *v)
{nod *c;
 c=v;
 while(c)
    {g<<c->info<<" ";
     c=c->next;}
}
void empty(nod *v)
{
	if(!v)
    g<<"coada este vida";
	else 
		g<<"coada este nevida";
}
int minim(nod *v, nod *sf)
{
	nod *c;
	int maxi=32000;
	c=v;
	while(c)
	{
		if(c->info<maxi&&c->info!=sf->info)
			maxi=c->info;
		c=c->next;
	}
	return maxi;
}
void intermediar(nod *v,int k)
{
	nod*c;
	int i;
	for(i=1;i<=k;i++)
		push(varf1,ultim1,minim(varf,ultim1));
	c=v;
	while(c)
	{
		push(varfx,ultimx,c->info);
		c=c->next;
	}
}
	
int main()
{
 f>>n>>k;
 for(int i=1;i<=n;i++)
    {
     f>>a;
     push(varf,ultim,a);
     }
 afisare(varf);
 intermediar(varf1,k);
 afisare(varfx);
 
}
