#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
struct nod{ int info;
nod *back;
};
nod *v;
int x,i,n;
void push(nod* &v,int x)
{nod *c;
if(!v)
    {
	 v=new nod;
     v->info=x;
     v->back=0;
	}
 else
     {c=new nod;
      c->back=v;
      c->info=x;
      v=c;}
}
void pop(nod* &v)
{nod* c;
if(!v)
    g<<"stiva este vida si nu mai ai ce elimina!!!";
 else
    {
	 c=v;
     v=v->back;
     delete c;
 }
 }
void top(nod *&v) 
{nod *c;
 if(!v)
	 g<<"stiva este vida";
 else
 {
	 c=v;
	 v=v->back;
	 g<<c;
 }
}
int main()
{
	f>>n;
	for(i=1;i<=n;i++)
	{
		f>>x;
		push(v,x);
	}
	pop(v);
	return 0;
}
