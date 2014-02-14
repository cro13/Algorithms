#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
struct lista{ int gr,coef;
			  lista *urm;
};
lista *p;
int x,n,i,a,y;
void creare(lista *&p,int x,int y)
{
	lista *q,*s;
	if(p==0)
	{
		p=new lista;
		p->gr=x;
		p->coef=y;
		p->urm=0;
	}
	else
	{
		for(q=p;q->urm;q=q->urm);
			s=new lista;
		s->gr=x;
		s->coef=y;
		s->urm=0;
		q->urm=s;
	}
}
void afis(lista *p)
{
	lista *q;
	g<<"coeficientii sunt : ";
	for(q=p;q;q=q->urm)
		g<<q->coef*a<<" ";
	g<<endl;
}
int main()
{
	f>>n>>a;
	for(i=1;i<=n;i++)
	{
		f>>x>>y;
		creare(p,x,y);
	}
	afis(p);
	return 0;
}
