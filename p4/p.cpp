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
void stergere(lista *&p, int k)
{ 
	int nr=1;
	lista *q,*s;
	if(k==1&&p)
	{
		q=p;
		p=p->urm;
		delete q;
	}
	else
	for(q=p;q->urm;q=q->urm)
	{nr++;
		 if(nr==k)
		{
			s=q->urm;
			q->urm=s->urm;
			delete s;
		}
		else
			continue;
	}
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
	f>>n>>k;
	for(i=1;i<=n;i++)
	{
		f>>x;
		creare(p,x);
	}
	afis(p);
	stergere(p,k);
	afis(p);
	return 0;
}
