#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
struct lista{ int info;
			  lista *urm;
};
lista *p,*t,*w;
int x,n,i,m;
//am presupus ca elementele sunt deja in ordine crescatoare, altfel se poate face crearea listei ordonate 
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
void inter(lista *&w,lista *p,lista *t)
{
	lista *q,*s;
    q=t;
	s=p;
	while(q&&s)
	{
		if(q->info<s->info)
			{
				creare(w,q->info);
				q=q->urm;
		}
		else
			{
				creare(w,s->info);
				s=s->urm;
		}
	}
		while(q)
		{
			creare(w,q->info);
			q=q->urm;
		}
		while(s)
		{
			creare(w,s->info);
			s=s->urm;
		}
	}

int main()
{
	f>>n>>m;
	for(i=1;i<=n;i++)
	{
		f>>x;
		creare(p,x);
	}
	for(i=1;i<=m;i++)
	{
		f>>x;
		creare(t,x);
	}
	afis(p);
	afis(t);
	inter(w,p,t);
	afis(w);
}
