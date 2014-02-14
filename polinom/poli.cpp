#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
struct pol{ int gr,coef;
pol *urm;
};
pol *p,*t,*w;
int grad,coeficient,i,n,m;
void creare(pol *&p, int grad, int coeficient)
{
	pol *q, *s;
	if(p==0)
	{
		p=new pol;
		p->gr=grad;
		p->coef=coeficient;
		p->urm=0;
	}
	else
	{
		for(q=p;q->urm;q=q->urm);
		s=new pol;
		s->gr=grad;
		s->coef=coeficient;
		s->urm=0;
		q->urm=s;
	}
}
void afis(pol *p)
{
	pol *q;
	for(q=p;q;q=q->urm)
		g<<q->gr<<" "<<q->coef<<" ";
	g<<endl;
}
void adun(pol *p,pol *t, pol *&w)
{
	pol *q,*s;
	//if(p->urm||t->urm)
		if(w==0)
		{
		w=new pol;
		w->gr=p->gr+t->gr;
		w->coef=p->coef+t->coef;
		p=p->urm;
		t=t->urm;
		w->urm=0;
	}
	else
	{
		for(q=w;q->urm;q=q->urm);
		s=new pol;
		s->gr=p->gr+t->gr;
		s->coef=p->coef+t->coef;
		p=p->urm;
		t=t->urm;
		s->urm=0;
		q->urm=s;
	}
	}

int main()
{
	f>>n>>m;
	for(i=1;i<=n;i++)
	{
		f>>grad>>coeficient;
		creare(p,grad,coeficient);
	}
	for(i=1;i<=m;i++)
	{
		f>>grad>>coeficient;
		creare(t,grad,coeficient);
	}
	afis(p);
	afis(t);
	
	adun(p,t,w);
	afis(w);
}
