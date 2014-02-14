#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
struct lista{ int info;
			  lista *urm;
};
lista *p,*t;
int x,n,i,a[100];
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
void vect(lista *p)
{ 
	int j=1;
	lista *q;
	for(q=p;q;q=q->urm)
	{
		a[j]=q->info;
		j++;
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
	vect(p);
	for(i=n;i>=1;i--)
	creare(t,a[i]);
	afis(t);
	return 0;
}
