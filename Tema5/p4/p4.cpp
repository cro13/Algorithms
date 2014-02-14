#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
struct lista{ int info,pr;
			  lista *urm;
};
lista *p;
int x,n,i,y;
void creare(lista *&p, int x, int y)
{
lista *q,*s;
if(p==0)
{
	p=new lista;
	p->info=x;
	p->pr=y;
	p->urm=0;
}
else
if(p->pr>y)
{
	s=new lista;
	s->info=x;
	s->pr=y;
	s->urm=p;
	p=s;
}
else
{	for(q=p;q->urm&&q->urm->pr<y;q=q->urm);
	if(q->urm)
{
		s=new lista;
		s->info=x;
		s->pr=y;
		s->urm=q->urm;
		q->urm=s;
	}
else
{
s=new lista;
s->info=x;
s->pr=y;
s->urm=0;
q->urm=s;
}}}
void scot(lista *p)
{
	lista *q;
	for(q=p;q;q=q->urm)
		g<<q->info<<" "<<q->pr<<" ";
	g<<endl;
}
void afis(lista *p)
{
	lista *q;
	for(q=p;q;q=q->urm)
		g<<q->info<<" "<<q->pr<<" ";
	g<<endl;
}
int main()
{
	f>>n;
	for(i=1;i<=n;i++)
	{
		f>>x>>y;
		creare(p,x,y);
	}
	afis(p);
	return 0;
	
}
