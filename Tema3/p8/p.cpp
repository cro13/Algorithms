#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
struct lista{ int info;
			  lista *urm;
};
lista *p,*t,*w;
int x,n,i;
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
void distr(lista *p, lista *&t, lista *&w)
{
	int k=1;
	while(p)
	{
	 if(k%2==1)
	 {
		 creare(t,p->info);
		 k++;
		 p=p->urm;
	 }
	 else
	 {
		 creare(w,p->info);
		 k++;
		 p=p->urm;
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
	distr(p,t,w);
	afis(t);
	afis(w);
	return 0;
}
