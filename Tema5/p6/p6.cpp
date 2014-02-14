#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
struct listad{int info;
listad *prec,*urm;
};
listad *p,*u;
int n,x,i,k,kx;
void creare(listad *p, int x)
{
	listad *s,*q;
			for(q=p;q->urm!=p;q=q->urm);
			s=new listad;
			s->info=x;
			s->prec=q;
			s->urm=p;
			q->urm=s;
	
}
void afis(listad *p)
{
	listad *q;
	for(q=p->urm;q!=p;q=q->urm)
		g<<q->info<<" ";
	g<<endl;
}
void insert(listad *p,int x)
{
	creare(p,x);
}
void ultim(listad *p ,listad *&u)
{
	listad *q;
	for(q=p->urm;q->urm!=p;q=q->urm);
		u=q;
}
void stergval(listad *p, int x)
{
	listad *q,*s;
	for(q=u;q->prec!=p;q=q->prec)
		if(q->info==x&&p!=q)
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
int main()
{
	f>>n>>k;
	p=new listad;
	p->urm=p;
	p->prec=p;
	for(i=1;i<=n;i++)
		{
			f>>x;
			creare(p,x);
	}
	afis(p);
	ultim(p,u);
	stergval(p,k);
	g<<endl;
	afis(p);
	return 0;
}

