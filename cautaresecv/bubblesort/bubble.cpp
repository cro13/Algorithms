#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
int i,n,j,aux,v[100]; 
int main()
{
	f>>n;
	for(i=1;i<=n;i++)
		f>>v[i];
	for(i=1;i<n;i++)
		for(j=i+1;j<=n;j++)
			if(v[i]>v[j])
			{
				aux=v[i];
				v[i]=v[j];
				v[j]=aux;
			}
for(i=1;i<=n;i++)
	g<<v[i]<<" ";
return 0;
}
