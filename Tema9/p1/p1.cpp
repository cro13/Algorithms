#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
int i,j,n,a[20][20];
int gr(int i)
{
	int s=0;
	for(j=1;j<=n;j++)
		s+=a[i][j];
	return s;
}
int nrm()
{
	int nr=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(j>i)
				nr+=a[i][j];
			return nr;
}
int grmax()
{
	int maxi=0;
	for(i=1;i<=n;i++)
		if(gr(i)>maxi)
			maxi=gr(i);
		return maxi;
}
int main()
{
	f>>n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			f>>a[i][j];
		for(i=1;i<=n;i++)
			g<<gr(i)<<" ";
		g<<endl;
		g<<nrm()<<endl;
		g<<grmax();
		return 0;
		f.close();
		g.close();
}
