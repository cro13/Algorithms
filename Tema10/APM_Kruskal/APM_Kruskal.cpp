#include<fstream>
#include<cstdio>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
int main()
{
	struct muchie{
		int x,y,c;
	}v[100],aux;
	int i,n,m,j,mini,maxi,a[100],c[100];
	f>>n>>m;
	for(i=1;i<=m;i++)
		f>>v[i].x>>v[i].y>>v[i].c;
	for(i=1;i<m;i++)
		for(j=i+1;j<=m;j++)
			if(v[i].c>v[j].c)
			{
				aux=v[i];
				v[i]=v[j];
				v[j]=aux;
			}
			for(i=1;i<=n;i++)
				c[i]=i;
			int nr=0,k=1;
			while(nr<n-1)
			{
				if(c[v[k].x]!=c[v[k].y])
				{
					nr++;
					a[nr]=k;
					if(c[v[k].x]<c[v[k].y])
					{
						mini=c[v[k].x];
						maxi=c[v[k].y];
					}
					else
					{
						mini=c[v[k].y];
						maxi=c[v[k].x];
					}
					for(i=1;i<=n;i++)
						if(c[i]==maxi)
							c[i]=mini;
				}
				k++;
			}
			int cost=0;
			for(i=1;i<=nr;i++)
			{
				cost+=v[a[i]].c;
				g<<v[a[i]].x<<" "<<v[a[i]].y<<endl;
			}
			g<<cost<<endl;
f.close();
g.close();
return 0;
}
