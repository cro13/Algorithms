#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
int n,n1,i,x,aux,v[100];
void insereaza(int i, int x)
{
	int c,p,aux;
	v[i]=x;
	c=i;
	p=i/2;
	while(p>0&&v[p]>v[c])
	{
		aux=v[c];
		v[c]=v[p];
		v[p]=aux;
		c=p;
		p=p/2;
	}
}
void ajust(int n)
{
	int p,c;
	p=1;
	c=2;
	while(c<=n&&v[p]>v[c])
	{
		if(c+1<=n&&v[c]>v[c+1])
			c++;
		aux=v[p];
		v[p]=v[c];
		v[c]=aux;
		p=c;
		c=c*2;
	}
}
int main()
{
	f>>n;
	for(i=1;i<=n;i++)
	{
		f>>x;
		insereaza(i,x);
	}
	n1=n;
	for(i=n;i>1;i--)
	{
		aux=v[i];
		v[i]=v[1];
		v[1]=aux;
		ajust(i-1);
	}
	for(i=1;i<=n;i++)
		g<<v[i]<<" ";
	return 0;
}
