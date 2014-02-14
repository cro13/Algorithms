#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
int i,x1,x2;
struct lista{
	int info;
	lista *urm;
};
char n1[100],n2[100];
lista *nr1,*nr2,*sum;
void creare(lista *&p,int x)
{
	lista *q,*s;
	if(p==0)
		{p=new lista;
		p->info=x;
		p->urm=0;
		}
		else
			{q=p;
			while(q->urm)
				q=q->urm;
			s=new lista;
			s->info=x;
			s->urm=0;
			q->urm=s;
			}
}
void afis(lista *p)
{
	lista *q;
	q=p;
	while(q)
		{g<<q->info;
		q=q->urm;
		}
		g<<'\n';
}
int t;
void suma(lista *nr1,lista *nr2,lista *&sum)
{
	lista *q1,*q2,*q3,*s;
	q1=nr1;
	q2=nr2;
	sum=new lista;
	sum->info=(q1->info+q2->info)%10;
	t=(q1->info+q2->info)/10;
	sum->urm=0;
	q1=q1->urm;
	q2=q2->urm;
	q3=sum;
	while(q1&&q2)
		{s=new lista;
		s->info=(t+q1->info+q2->info)%10;
		t=(t+q1->info+q2->info)/10;
		s->urm=0;
		q3->urm=s;
		q1=q1->urm;
		q2=q2->urm;
		q3=q3->urm;
		}
	while(q1)
		{s=new lista;
		s->info=t+q1->info;
		s->urm=0;
		q3->urm=s;
		q3=q3->urm;
		t=0;
		q1=q1->urm;
		}
	while(q2)
		{s=new lista;
		s->info=t+q2->info;
		s->urm=0;
		q3->urm=s;
		q3=q3->urm;
		t=0;
		q2=q2->urm;
		}
}
void afisinvers(lista *&p)
{
	lista *q;
	q=p;
	while(p)
	{q=p;
	while(q->urm->urm)
		q=q->urm;
	if(p->urm->urm==0)
		{g<<p->urm->info<<p->info;
		p=0;
		}
	else
	{
	g<<q->urm->info;
	delete(q->urm);
	q->urm=0;
	}
	}
}

int main()
{
	f>>n1>>n2;
	strrev(n1);
	strrev(n2);
	x1=strlen(n1);
	x2=strlen(n2);
	for(i=0;i<x1;i++)
		creare(nr1,n1[i]-48);
	for(i=0;i<x2;i++)
		creare(nr2,n2[i]-48);
	afis(nr1);
	g<<'\n';
	afis(nr2);
	g<<'\n';
	/*afisinvers(nr1);
	g<<'\n';
	afisinvers(nr2);
	g<<'\n';*/
	suma(nr1,nr2,sum);
	afisinvers(sum);
	f.close();
	g.close();
	return 0;
}
