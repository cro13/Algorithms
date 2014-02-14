#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
int x;
struct nod{int info;
nod *st,*dr;
};
nod *r;
void creare(nod *&p)
{
	int x;
	f>>x;
	if(x)
	{
		p=new nod;
		p->info=x;
		creare(p->st);
		creare(p->dr);
	}
	else
		p=0;
}
void rsd(nod *p)
{
	if(p)
	{
		g<<p->info<<" ";
		rsd(p->st);
		rsd(p->dr);
	}
}
void srd(nod *p)
{
	if(p)
	{
		srd(p->st);
		g<<p->info<<" ";
		srd(p->dr);
	}
}
void sdr(nod *p)
{
	if(p)
	{
		sdr(p->st);
		sdr(p->dr);
		g<<p->info<<" ";
	}
}
int main()
{
	creare(r);
	rsd(r);
	g<<endl;
	srd(r);
	g<<endl;
	sdr(r);
	return 0;
}
