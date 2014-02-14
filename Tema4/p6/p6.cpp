#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
int i,j,x,k,m,a[20][20],b[20][20];
struct nod{int info,i,j;
               nod *next;};
nod *varf,*ultim;
void push(nod* &v,nod* &sf,int x,int i,int j)
{nod *c;
if(!v)
    {v=new nod;
     v->info=x;
	 v->i=i;
	 v->j=j;
     v->next=0;
     sf=v;}
 else
     {c=new nod;
      sf->next=c;
      c->info=x;
	  c->i=i;
	  c->j=j;
      sf=c;
      sf->next=0;}
}
void comp(nod *v, nod *sf,int b[20][20])
{
	nod *c;
	k=2;
	while(v)
	{
		if(v->info==v->next->info)
		{
			b[v->i][v->j]=b[v->next->i][v->next->j]=k;
			
		}
		else 
			k++;
		c=v;
		v=v->next;
		delete c;
	}
}
int main()
{
	f>>m;
	k=2;
	for(i=1;i<=m;i++)
		for(j=1;j<=m;j++)
		{
			f>>x;
			push(varf,ultim,x,i,j);
		}
	
//comp(varf,ultim,b);
for(i=1;i<=m;i++)
	{
		for(j=1;j<=m;j++)
		g<<b[i][j]<<" ";
		g<<endl;
}

return 0;
}
