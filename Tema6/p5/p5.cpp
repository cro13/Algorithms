#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
struct nod{
	nod *st, *dr;
	int info, LeftSize;
};
nod *r;
int nr,x,y,n;
void creare(nod *&p,int x,int y){
	if(p==0){
		p=new nod;
		p->info=x;
		p->LeftSize=y;
		p->st=0;
		p->dr=0;
	}
	else
		if(p->info<x)
			creare(p->dr,x,y);
		else
		if(p->info>x)
			creare(p->st,x,y);
}
void cautare(nod *p, int nr){
if(p)
	if(nr==p->LeftSize)
g<<p->info<<" ";
  else
	if(nr<p->LeftSize)
		cautare(p->st,nr);
	else
		if(nr>p->LeftSize)
			cautare(p->dr,nr-p->LeftSize-1);
		else
			g<<"nu s-a gasit";
}
int main()
{
	f>>n>>nr;
	for(int i=1;i<=n;i++){
		f>>x>>y;
		creare(r,x,y);
	}
 cautare(r,nr);
	return 0;
}
