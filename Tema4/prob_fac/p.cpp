#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
struct lista{ int info;
              lista *urm;
};
lista *p,*t;
int x,i,n,k;
void creare(lista *&p,int x)
{
	lista *q,*s;
	if(p==0)
	{
		p=new lista;
		p->info=x;
		p->urm=p;
		t=p;
	}
	else
	{
		for(q=p;q->urm!=p;q=q->urm);
		s=new lista;
		s->info=x;
		s->urm=p;
		q->urm=s;
	}
}
void afis(lista *p)
{
	lista *q;
	g<<p->info<<" ";
	q=p;
	do{g<<q->info<<" ";
	q=q->urm;
	}
	while(q!=p);
}
void sterg(lista *&p,int k)
{

	lista *q,*t;
	for(q=p;q->urm!=p;q=q->urm)
	{
		for(i=1;i<=n/k;i=i+k)
			{
				q=q->urm;
				n--;
				t=q;
		}
		
	}
	g<<t->info<<" ";
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
	g<<endl;
	sterg(p,k);
	return 0;
}
