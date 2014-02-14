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

void inserare(lista *p)
{
	lista *q,*s;
	q=p;
	while(q->urm!=0)
	{
		s=new lista;
		s->info=(q->info+q->urm->info)/2;
		s->urm=q->urm;
		q->urm=s;
		q=s->urm;;
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
	inserare(p);
	afis(p);
	return 0;
}
