#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
int i,n,maxi,mini,a[100];
int maxim(int i, int n, int &maxi)
{
	if(i>n)
		return maxi;
	else
			if(a[i]>maxi)
				return maxim(i+1,n,a[i]);
				else
					return maxim(i+1,n,maxi);
				
}

int minim(int i, int n, int &mini)
{
	if(i>n)
		return mini;
	else
		if(a[i]<mini)
			return minim(i+1,n,a[i]);
		else
			return minim(i+1,n,mini);
}
int main()
{
	f>>n;
	for(i=1;i<=n;i++)
		f>>a[i];
	maxi=-32000;
	mini=32000;
	g<<"maximul este "<<maxim(1,n,maxi)<<'\n';
	g<<"minimul este "<<minim(1,n,mini);
	return 0;
}
