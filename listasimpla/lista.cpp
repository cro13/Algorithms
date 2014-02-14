#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
struct lista{ int info;
			  lista *urm;
};
lista *p;
int x,n,i;
void creare(lista *&p,int x)
{
	lista *q,*s;
	if(p==0)
	{
		p=new lista;
		p->info=x;
		p->urm=0;
	}
	else
	{
		for(q=p;q->urm;q=q->urm);
			s=new lista;
		s->info=x;
		s->urm=0;
		q->urm=s;
	}
}
void afis(lista *p)
{
	lista *q;
	for(q=p;q;q=q->urm)
		g<<q->info<<" ";
	g<<endl;
}
void cauta(lista *p, int x)
{
	lista *q;
	q=p;
	while(q)
	if(q->info==x)
		{
			g<<"exista";
			break;
	}
	else
		q=q->urm;
	if(q==0)
		g<<"Nu exista";
}
void stergere(lista *&p, int x)
{
	lista *q,*s;
	if(p->info==x&&p)
	{
		q=p;
		p=p->urm;
		delete q;
	}
	for(q=p;q->urm;q=q->urm)
		if(q->urm->info==x)
		{
			s=q->urm;
			q->urm=s->urm;
			delete s;
		}
		else
			q=q->urm;
}
void stergefull(lista *&p)
{
	lista *q,*s;
	while(p)
	{
		q=p;
		p=p->urm;
		delete q;
	}
}
int main()
{
	f>>n;
	for(i=1;i<=n;i++)
	{
		f>>x;
		creare(p,x);
	}
	afis(p);
	f>>x;
    cauta(p,x);
	g<<'\n';
	f>>x;
	stergere(p,x);
	afis(p);
	stergefull(p);
	afis(p);
	return 0;
}
