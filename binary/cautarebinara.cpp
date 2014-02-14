#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
int i,n,x,a[100];
int cauta(int x, int li, int ls)
{
	int m;
	if(li>ls)
		return 0;
	else
		
	if(li<=ls)
	{
		m=(li+ls)/2;
		if(a[m]==x)
			return 1;
		else
			if(a[m]>x)
				return cauta(x,li,ls-1);
				else
					return cauta(x,li+1,ls);
	}}
	int main()
	{ f>>n;
	for(i=1;i<=n;i++)
		f>>a[i];
	f>>x;
	if(cauta(x,1,n))
		g<<"DA";
	else
		g<<"NU";
	return 0;
	}
	