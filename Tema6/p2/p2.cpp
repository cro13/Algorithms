#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
struct nod{int info;
nod *st,*dr;
};
nod *r;
int n,x,k,maxi,k1;
void inserare(nod *&p,int x)
{if(p)
   if(p->info==x)
        g<<"nr deja inserat "<<endl;
   else
     if(p->info<x)
             inserare(p->dr,x);
     else
             inserare(p->st,x);
 
 else
     {p=new nod;
      p->info=x;
      p->st=p->dr=0;}
}
int cautare(nod *p,int x)
{if(p)
    if(p->info==x)
            return 1;
    else
            if(p->info<x)
               return cautare(p->dr,x);
            else
               return cautare(p->st,x);
 else
    return 0;
}
void maxim(nod *p)
{
	if(p)
	{
		if(p->info>maxi)
		maxi=p->info;
	maxim(p->st);
	maxim(p->dr);
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
void cmd(nod *&p,nod *&f)
{nod *aux;
 if(f->dr)
    cmd(p,f->dr);
 else
     {p->info=f->info;
      aux=f;
      f=f->st;
      delete aux;
      }
}
void sterg(nod *&p,int k1)
{nod *aux;
 if(p)
   if(p->info==k)
       if(p->st==0&&p->dr==0)  
               {delete p;
                p=0;
                }
            else
               if(p->st==0)      //are numai subordonat drept
                 {aux=p->dr;
                  delete p;
                  p=aux;}
                else
                   if(p->dr==0)    //are numai subordonat drept
                          {aux=p->st;
                           delete p;
                           p=aux;}
                   else
                           cmd(p,p->st);  //are ambii subordonati
 
   else
     if(p->info<k)
            sterg(p->dr,k);
     else
            sterg(p->st,k);
 
 else
      g<<"valoarea de sters nu se gaseste in arbore ";
}
int main()
{ int i;
	f>>n;
	for(i=1;i<=n;i++)
	{
		f>>x;
		inserare(r,x);
	}
	f>>k;
	if(cautare(r,k))
		g<<"DA";
	else 
		g<<"NU";
	g<<endl;
	maxi=-32000;
	srd(r);
	g<<endl;
	maxim(r);
	g<<maxi<<" ";
	f>>k1;
	sterg(r,k1);
	return 0;
}
