#include<fstream.h>
#include<conio.h>
ifstream f("f.in");
ofstream g("g.out");
struct nod{char info;
               nod *back;};
 
nod *varf;
int ok;
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
	nod *c;
	if(v==0)
		return 0;
	else
	return 1;
}
int main()
{ ok=1;
	int n,i;
	char a;
	f>>n;
   for(int i=1;i<=n;i++)
    {
     f>>a;
	 if(a=='a')
     push(varf,a);
     }
   afisare(varf);
   g<<'\n';
for(i=1;i<=n/2;i++)
       {
		   pop(varf);
		   if(ok==0)
			   break;
}
if(ok==1)
if(pop1(varf))
	g<<"stiva proasta";
else
	g<<"stiva buna";
//afisare(varf);
 return 0;
}
