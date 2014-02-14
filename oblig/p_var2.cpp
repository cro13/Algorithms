#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
struct lista{ int info;
			  lista *urm;
};
lista *p;
int x,n,i;
void creare(lista *&p, int X)
{
lista *q,*s;
if(p==0)
{
p=new lista;
p->info=x;
p->urm=0;
}
else
if(p->info>x)
{
s=new lista;
s->info=x;
s->urm=p;
p=s;
}
else
{for(q=p;q->urm&&q->urm->info<x;q=q->urm);
if(q->urm)
{
s=new lista;
s->info=x;
s->urm=q->urm;
q->urm=s;
}
else
{
s=new lista;
s->info=x;
s->urm=0;
q->urm=s;
}

void afis(lista *p)
{
	lista *q;
	for(q=p;q;q=q->urm)
		g<<q->info<<" ";
	g<<endl;
}
int main()
{
f>>x;
while(x)
{
creare(p,x);
f>>x;
}
afis(p);
return 0;
}
