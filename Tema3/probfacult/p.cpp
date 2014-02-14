#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
int i,n,a[100],v[100],k,nr,maxi;
int main()
{
	//ideea se bazeaza pe un vector caracteristic care memoreaza nr de aparitii a unui nr intr-un vector
	f>>n;
	for(i=1;i<=n;i++)
		{
			f>>a[i];
			v[a[i]]++;
	}
	maxi=0;
	for(i=1;i<=n;i++)
		if(v[i]>maxi)
			{
				maxi=v[i];
				k=i;
		}
		if(maxi>n/2)
			g<<"exista element majoritar si acesta este "<<a[k];
		else
			g<<"nu exista";
		
		return 0;
}
