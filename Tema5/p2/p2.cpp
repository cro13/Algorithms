#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
struct listad{char info;
listad *prec,*urm;
};
listad *p;
char x;
int n,i,ok;
void creare(listad *&p, char x)
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
		g<<q->info;
	g<<endl;
}
void verif(listad *p)
{
	listad *q,*t;
	for(q=p;q;q=q->urm)
		t=q;
	q=p;
	while(q!=t)
	{
		if(q->info!=t->info)
			{
				ok=0;
				break;
		}
		else
		{
			q=q->urm;
			t=t->prec;
		}
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
	ok=1;
	verif(p);
	if(ok==1)
		g<<"Palindrom";
	else
		g<<"nu e palindrom";
	return 0;
}
