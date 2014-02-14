#include<fstream>
#include<iostream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
struct listad{int info;
listad *prec,*urm;
};
listad *p;
int n,x,i,k;
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
void stergcoada(listad *&p)
{
	listad *q,*t;
	for(q=p;q;q=q->urm);
		t=q;
	q->urm=0;
	delete q;
}
void sterginceput(listad *&p)
{
	listad *q;
	q=p;
	stergval(p,q->info);
	delete q;
}
void insertcoada(listad *p,int x)
{
	creare(p,x);
}
void insertinceput(listad *&p,int x)
{
	listad *q;
	q=new listad;
	q->info=x;
	q->urm=p;
	q->prec=0;
	p->prec=q;
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
	cout<<"Optiuni: "<<endl<<"1) Pentru a stergere un element de la sfarsitul listei apasati tasta 1"<<endl<<"2) Pentru a sterge un element de la inceputul listei apasati tasta 2"<<endl<<"3) Pentru a insera un element la sfarsitul listei apasati tasta 3"<<endl<<"4) Pentru a insera un element la inceputul listei apasati tasta 4"<<endl;
	cin>>k;
	if(k==1)
		stergcoada(p);
		else
			if(k==2)
				sterginceput(p);
			else
				if(k==3)
					{
						cout<<"Dati valoare: ";
						cin>>x;
						insertcoada(p,x);
				}
				else
					if(k==4)
						{
							cout<<"Dati valoare: ";
							cin>>x;
							insertinceput(p,x);
					}
					else
						cout<<"Optiune nevalida ";
					afis(p);
					
	return 0;
}
