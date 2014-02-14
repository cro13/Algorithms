#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
int main()
{
	int i,j,n,p,u,x,a[20][20],viz[100],c[100];
	f>>n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			f>>a[i][j];
		c[1]=1;
		viz[1]=1;
		p=u=1;
		while(p<=u)
		{
			x=c[p];
			for(i=1;i<=n;i++)
				if(a[x][i]==1&&!viz[i])
				{
					u++;
					c[u]=i;
					viz[i]=1;
				}
				p++;
		}
		if(u==n)
			g<<"Graf conex";
		else
			g<<"Nu e conex";
		return 0;
}
