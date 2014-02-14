#include<fstream>
#include<cstring>
using namespace std;
ifstream f("sr.in");
ofstream g("sr.out");
char c,a[100000],b[100000];
int i,j,v[100000],k;
long n,m;
int main()
{
	f>>a;
	f>>b;
	n=strlen(a)-1;
	m=strlen(b)-1;
	i=j=0;
	k=0;
	while(i<=n||j<=m)
	{
		if(a[i]==b[j])
		{
			k++;
			v[k]=i+1;
			i++;
			j++;
		}
		else
			i++;
	}
	for(i=1;i<=k;i++)
		g<<v[i]<<" ";
	f.close();
	return 0;
}
