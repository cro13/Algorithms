#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
void drum(int i,int j,int d[20][20])
{
	if(i==j&&j)
		g<<i<<" ";
	else
	{
		drum(i,d[i][j],d);
		g<<j<<" ";
	}
}
int main()
{
	int i,j,n,m,z,k,x,y,c[20][20],d[20][20];
	f>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			c[i][j]=32000;
		for(i=1;i<=m;i++)
		{
			f>>x>>y>>z;
			c[x][y]=c[y][x]=z;
			d[x][y]=x;
			d[y][x]=y;
		}
		for(k=1;k<=n;k++)
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
					if(i!=j&&i!=k&&j!=k)
						if(c[i][j]>c[i][k]+c[k][j])
						{
							c[i][j]=c[i][k]+c[k][j];
							d[i][j]=d[i][k];
						}
						for(i=1;i<=n;i++)
							for(j=1;j<=n;j++)
								if(c[i][j]<32000&&i!=j)
								{
									g<<c[i][j]<<" " <<":";
									drum(i,j,d);
									g<<endl;
								}
								f.close();
								g.close();
								return 0;
}
