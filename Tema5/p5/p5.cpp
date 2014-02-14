#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
struct listad{int info;
listad *prec,*urm;
};
listad *p;
int n,x,i,k,kx;
void creare(listad *p, int x)
{
	listad *s,*q;
			for(q=p;q->urm;q=q->urm);
			s=new listad;
			s->info=x;
			s->prec=q;
			s->urm=0;
			q->urm=s;
	
}
void afis(listad *p)
{
	listad *q;
	for(q=p->urm;q;q=q->urm)
		g<<q->info<<" ";
	g<<endl;
}
void stergval(listad *p, int x)
{
	listad *q,*s;
	for(q=p;q;q=q->urm)
		if(q->info==x)
		{
			s=q;
			if(q->prec)
				q->prec->urm=q->urm;
			else
				p=q->urm;
			if(q->urm)
				q->urm->prec=q->prec;
			else
			q=q->urm;
		  delete s;	
		}
	
}
void insert(listad *p,int x)
{
	creare(p,x);
}
int main()
{
	f>>n>>k;
	p=new listad;
	p->urm=0;
	p->prec=0;
	for(i=1;i<=n;i++)
		{
			f>>x;
			creare(p,x);
	}
	afis(p);
	g<<endl;
	stergval(p,k);
	afis(p);
	return 0;
}

