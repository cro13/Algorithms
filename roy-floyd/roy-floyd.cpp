#include<fstream>
using namespace std;
ifstream f("royfloyd.in");
ofstream g("royfloyd.out");
int n,m,i,j,x,y,z,k,c[100][100],d[100][100];
void drum(int i,int j)
{
	if(j)
		if(i==j)
			g<<i<<" ";
		else
		{
			drum(i,d[i][j]);
			g<<j<<" ";
		}
}
int main()
{
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
								g<<c[i][j]<<" ";
								drum(i,j);
								g<<endl;
							}
}
