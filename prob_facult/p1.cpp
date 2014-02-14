//Implementarea are la baza lista dubla inlantuita
#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
struct listad{char info;
listad *prec,*urm;
};
listad *p;
char x;
int n,i;
void creare(listad *&p, char x)//crearea listei duble inlantuite cu caractere
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
void afis(listad *p)//afisarea listei astfel create
{
	listad *q;
	for(q=p;q;q=q->urm)
		g<<q->info;
	g<<endl;
}
void margine(listad *p)//determinarea marginei maxime
{//algoritmul are la baza o interclasare modificata putin[mai mult]
	listad *q,*t;
	for(q=p;q;q=q->urm)//am parcurs lista pana la coada pentru a determina ultimul caracter
		t=q;
	q=p;
	int ok=1;
	while(q!=t)//cat timp ultimul nu a ajuns primul parcurg lista
	{
		if(q->info==t->info)//testez daca cele 2 capete sunt egale si le afisez in caz afirmativ
			{
				g<<q->info;
				q=q->urm;
				t=t->prec;
		}
		else
			ok=0;
		if(ok==0)
		{
			g<<"nu are margine";
			break;
		}
		
	}
	if(q->info==t->info)
			g<<q->info;
			
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
	margine(p);//Marginea se determina in O(n) deoarece lista se parcurge din cele 2 capete ale sale catre mijloc o singura data!
	return 0;
}
