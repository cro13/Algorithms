#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
struct listad{int info;
listad *prec,*urm;
};
listad *p;
int n,x,i,k,kx;
void creare(listad *&p, int x)
{
	listad *s,*q;
	if(p==0)
	{
		p=new listad;
		p->info=x;
		p->prec=0;
		p->urm=0;
	}
	else
		{
			for(q=p;q->urm;q=q->urm);
			s=new listad;
			s->info=x;
			s->prec=q;
			s->urm=0;
			q->urm=s;
	}
}
void afis(listad *p)
{
	listad *q;
	for(q=p;q;q=q->urm)
		g<<q->info<<" ";
	g<<endl;
}
void afis1(listad *p)
{
	listad *q,*t;
	for(q=p;q;q=q->urm)
		t=q;
	for(q=t;q;q=q->prec)
		g<<q->info<<" ";
}
void stergval(listad *&p, int x)
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
void stergpoz(listad *&p,int x)
{
	listad *q,*s;
	int k1=0;
	for(q=p;q;q=q->urm)
	{
		k1++;
		if(k1==x)
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
		}}
	
}
int main()
{
	f>>n>>k>>kx;
	for(i=1;i<=n;i++)
		{
			f>>x;
			creare(p,x);
	}
	afis(p);
	g<<endl;
	afis1(p);
	stergval(p,k);
	g<<endl;
	afis(p);
	stergpoz(p,kx);
	g<<endl;
	afis(p);
	return 0;
}

