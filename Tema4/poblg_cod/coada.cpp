#include<fstream>
#include<conio.h>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");

struct nod{int info;
               nod *next;};
nod *varf,*ultim;
int n,a;
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
void scoate(nod* &v)
{nod* c;
if(!v)
    g<<"coada este vida si nu mai ai ce elimina";
 else
    {c=v;
     v=v->next;
     delete c;}
 }
void empty(nod *v)
{
	if(!v)
    g<<"coada este vida";
	else 
		g<<"coada este nevida";
}
int main()
{
 f>>n;
 for(int i=1;i<=n;i++)
    {
     f>>a;
     push(varf,ultim,a);
     }
afisare(varf);
scoate(varf);
empty(varf);
return 0;

 }
