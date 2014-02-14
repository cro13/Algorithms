#include<fstream>
#include<conio.h>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
struct nod{char info;
               nod *back;};
 
nod *varf,*v,*v1;
int ok,n,i,x;
void push(nod* &v,int x)
{nod *c;
if(!v)
    {v=new nod;
     v->info=x;
     v->back=0;}
 else
     {c=new nod;
      c->back=v;
      c->info=x;
      v=c;}
}
 
void afisare(nod *v)
{nod *c;
 c=v;
 while(c)
    {g<<c->info<<" ";
     c=c->back;}
}
 
void pop(nod* &v)
{nod* c;
if(v==0)
	{
		g<<"stiva proasta";
		ok=0;
}
 else
    {c=v;
     v=v->back;
     delete c;}
 }
int pop1(nod *&v)
{
	if(v==0)
		return 0;
	else
	return 1;
}
int main()
{
	f>>n;
	for(i=1;i<=n/2;i++)
	{
		f>>x;
		push(v,x);
	}
	for(i=n/2+1;i<=n;i++)
	{
		f>>x;
		push(v1,x);
	}
	return 0;
}
