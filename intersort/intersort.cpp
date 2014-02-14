#include<fstream>
using namespace std;
ifstream f("intersort.in");
ofstream g("intersort.out");
int i,j;
long aux,n,mini,v[100000];
int main()
{
	f>>n;
	mini=0;
	for(i=1;i<=n;i++)
		f>>v[i];
	for(i=1;i<n;i++)
		for(j=i+1;j<=n;j++)
			if(v[i]>v[j])
			{
				aux=v[i];
				v[i]=v[j];
				v[j]=aux;
				mini++;
			}
			g<<mini<<" ";
	return 0;
}
