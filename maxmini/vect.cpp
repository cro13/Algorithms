#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
int i,n,maxi,mini,a[100];
int main()
{
	f>>n;
	for(i=1;i<=n;i++)
		f>>a[i];
	maxi=-32000;
	mini=32000;
	for(i=1;i<=n;i++)
	{
		if(a[i]>maxi)
			maxi=a[i];
		if(a[i]<mini)
			mini=a[i];
	}
	g<<"maximul este "<<maxi<<endl<<"minimul este "<<mini<<" ";
	return 0;
}
