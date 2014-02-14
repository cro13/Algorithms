#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
struct lista{ int info,fr;
			  lista *urm;
};
lista *p,*t,*w;
int x,n,i,ok;
void creare(lista *&p,int x)
{
	lista *q,*s;
	if(p==0)
	{
		p=new lista;
		p->info=x;
		p->urm=0;
		p->fr=1;
	}
	else
	{
	   ok=0;
		if(ok==0)
		for(q=p;q;q=q->urm)
				if(x==q->info)
				{
					q->fr++;
					ok=1;
					break;
				}
			if(!ok)
		{
			for(q=p;q->urm;q=q->urm);
				s=new lista;
			s->info=x;
			s->fr=1;
			s->urm=0;
			q->urm=s;
			}
	}
}
void afis(lista *p)
{
	lista *q;
	for(q=p;q;q=q->urm)
		g<<q->info<<" "<<q->fr<<" ";
	g<<endl;
}
void maxim()
{
	int x,maxi=-32000;
	lista *q;
	for(q=p;q;q=q->urm)
		if(q->fr>maxi)
		{
			maxi=q->fr;
			x=q->info;
		}
		if(maxi>n/2)
			g<<"exista si este "<<x;
		else 
			g<<"nu exista";
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
	maxim();
	return 0;
}
