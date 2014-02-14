#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
int n,m,x,y,nr,p,i,j,u,a[20][20],c[100],viz[100];
int main()
{
	f>>n>>m;
	for(i=1;i<=n;i++)
	{
		f>>x>>y;
		a[x][0]++;
		a[x][a[x][0]]=y;
		a[y][0]++;
		a[y][a[y][0]]=x;
	}
	p=i=nr=1;
	do
	{
		u=p;
		viz[i]=nr;
		c[p]=i;
		while(p<=u)
		{
			x=c[p];
			for(i=1;i<=n;i++)
				if(a[x][i]==1&&!viz[i])
				{
					u++;
					c[u]=i;
					viz[i]=nr;
				}
				p++;
		}
	
		for(i=1;i<=n;i++)
			if(!viz[i])
			{
				nr++;
				break;
			}
			while(i<=n);
			g<<nr<<'\n';
			for(i=1;i<=nr;i++)
				g<<"componenta"<<i<<": ";
			for(j=1;j<=n;j++)
				if(viz[j]==i)
			g<<j<<" ";
				g<<endl;
	return 0;