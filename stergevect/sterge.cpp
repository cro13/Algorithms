#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
int i,n,j,x,k,a[100];
int main()
{
	f>>n>>k;
	k=a[k];
	for(i=k;i<n;i++)
		a[i]=a[i+1];
	n--;
for(i=1;i<=n;i++)
	g<<a[i]<<" ";
return 0;
}
