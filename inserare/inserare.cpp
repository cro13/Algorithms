#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
int i,n,x,k,a[100]; 
int main()
{
	f>>n>>k>>x;
	for(i=1;i<=n;i++)
		f>>a[i];
			for(i=n;i>=k;i--)
				a[i+1]=a[i];
			a[k]=x;
			n++;
for(i=1;i<=n;i++)
	g<<a[i]<<" ";
return 0;
}
