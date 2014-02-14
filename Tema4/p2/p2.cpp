#include<fstream.h>
#include<conio.h>
ifstream f("f.in");
ofstream g("g.out");
struct nod{char info;
               nod *back;};
 
nod *varf,*varf1;
int ok,k,i;
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
		k=i;
		ok=0;
}
 else
    {c=v;
     v=v->back;
     delete c;}
 }
int main()
{ ok=1;
	int n;
	char a;
	f>>n;
   for(i=1;i<=n;i++)
    {
     f>>a;
	 if(a=='(')
		 push(varf,a);
	 else 
		 push(varf1,a);
     }
   for(i=1;i<=n/2;i++)
   {
	   pop(varf);
	   pop(varf1);
   }
   if(ok==0)
	   {
		   g<<"prost"<<'\n';
		   g<<"pozitia este "<<k;
   }
   else 
	   g<<"bun";
   //afisare(varf);
   g<<'\n';
//afisare(varf);
 return 0;
}
