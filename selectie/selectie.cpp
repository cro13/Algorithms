#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
int i,n,j,k,a[100],aux,mini;
int main()
{
	f>>n;
	for(i=1;i<=n;i++)
		f>>a[i];
	for(i=1;i<n;i++)
	{
		mini=a[i];
		for(j=i+1;j<=n;j++)
			if(a[j]<mini)
				{
					mini=a[j];
					k=j;}
			if(a[i]>mini)
			{
				aux=a[i];
				a[i]=mini;
				a[k]=aux;
			}
	}
for(i=1;i<=n;i++)
g<<a[i]<<" ";
}
