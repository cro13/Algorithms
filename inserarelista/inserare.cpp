#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
struct lista{ int info;
			  lista *urm;
};
lista *p;
int x,n,i,k;
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

//inserare la inceput 
void inserarei(lista *&p, int x)
{
	lista *s;
	s=new lista;
	s->info=x;
	s->urm=p;
	p=s;
}

//inserare interior pe pozitia k
void inserarein(lista *p, int x, int k)
{
	lista *q,*s;
	int nr=0;
	for(q=p;q->urm;q=q->urm)
	{
		nr++;
		if(nr==k)
		{
			s=new lista;
			s->info=x;
			s->urm=q->urm;
			q->urm=s;
			q=q->urm;
		}
	}
}
//inserez la coada
void inserarec(lista *p, int x)
{
	lista *q,*s;
	for(q=p;q->urm;q=q->urm);
	s=new lista;
	s->info=x;
	s->urm=0;
	q->urm=s;
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
	inserarei(p,x);
	afis(p);
	f>>x>>k;
	inserarein(p,x,k);
	afis(p);
	f>>x;
	inserarec(p,x);
	afis(p);
}
