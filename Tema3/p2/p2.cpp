#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
struct lista{ int info;
			  lista *urm;
};
lista *p;
int x,n,i,nr,s,nrp;
float ma;
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
void proc(lista *p)
{
	lista *q;
	for(q=p;q;q=q->urm)
		if(q->info<0)
		{
			s+=q->info;
			nr++;
		}
		else
			nrp++;
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
	nr=0;
	nrp=0;
	s=0;
	proc(p);
	if(nr!=0)
	ma=s/nr;
	else
		g<<"Nu exista numere negative in lista"<<endl;
	g<<"Numarul de numere pare din lista este "<<nrp<<" media aritmetica este "<<ma<<endl;
	return 0;
}
