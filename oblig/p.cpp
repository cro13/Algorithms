#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
struct lista{ int info;
			  lista *urm;
};
lista *p;
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
void insertie(lista *p)
{
	lista *q,*s,*r;
	int aux;
	r=p;
	for(q=p;q->urm;q=q->urm)
	{
		s=q;
		while (s>0&&s->info>s->urm->info) 
        {  
            aux=s->urm->info;  
            s->urm->info=s->info;  
            s->info=aux;  
			q=p;
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
	insertie(p);
	afis(p);
	return 0;
	
}
