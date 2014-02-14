#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
int i,j,n,a[100],x,ok=0;
int main()
{
	f>>n>>x;
	for(i=1;i<=n;i++)
		f>>a[i];
	for(i=1;i<=n;i++)
		if(a[i]==x)
			ok=1;
		if(ok==1)
			g<<"DA";
		else
			g<<"NU";
		return 0;
}
