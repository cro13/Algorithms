#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
void drum(int i,int r,int p[100])
{
	if(i==r)
		g<<r<<" ";
	else
	{
		drum(p[i],r,p);
		g<<i<<" ";
	}
}
int main()
{
	
	int n,m,i,j,r,mini,k,x,y,z,d[100],p[100],viz[100],c[20][20];
	f>>n>>m>>r;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			c[i][j]=c[j][i]=32000;
		for(i=1;i<=m;i++)
		{
			f>>x>>y>>z;
			c[x][y]=c[y][x]=z;
		}
		for(i=1;i<=n;i++)
		{
			d[i]=c[r][i];
			if(d[i]<32000)
				p[i]=r;
		}
		viz[r]=1;
		p[r]=0;
		for(j=1;j<n;j++)
		{
			mini=32000;
			for(i=1;i<=n;i++)
				if(!viz[i]&&d[i]<mini)
				//{	
					mini=d[i];
					k=i;
				//}
				if(mini==32000)
					break;
				viz[k]=1;
				for(i=1;i<=n;i++)
					if(!viz[i]&&c[k][i]<32000)
				if(d[i]>d[k]+c[k][i])
				{
					d[i]=d[k]+c[k][i];
					p[i]=k;
				}
		}
		for(i=1;i<=n;i++)
			if(i!=r)
				if(d[i]==32000)
					g<<"nu exista drum de la "<<r<<" la "<<i<<endl;
				else
				{
					g<<"Drum de la "<<i<<" la "<<r;
					g<<d[i]<<":";
					drum(i,r,p);
					g<<endl;
				}
f.close();
g.close();
return 0;
}
