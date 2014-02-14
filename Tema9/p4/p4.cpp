#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
int n,m,i,a[20][20],viz[100];
void dfs(int x)
{
	int i;
	g<<x<<" ";
	viz[x]=1;
	for(i=1;i<=a[x][0];i++)
		if(!viz[a[x][i]])
			dfs(a[x][i]);
}
int main()
{
	f>>n>>m;
	for(i=1;i<=m;i++)
	{
		int x,y;
		f>>x>>y;
		a[x][0]++;
		a[x][a[x][0]]=y;
		a[y][0]++;
		a[y][a[y][0]]=x;
	}
	for(i=1;i<=n;i++)
		if(!viz[i])
			dfs(i);
		return 0;
}
