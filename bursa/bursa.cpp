#include<fstream>
using namespace std;
ifstream f("bursa.in");
ofstream g("bursa.out");
long n,s,nr,maxi,mini,s1,x;
int i;
int main()
{
	maxi=-9999999;
	mini=999999;
	f>>n>>s;
	for(i=1;i<=n;i++)
		{
			f>>x;
			if(x>=maxi)
			maxi=x;
		if(x<=mini)
			mini=x;
	}
	if(mini!=0)
	nr=s/mini;
	x=s-nr*mini;
	s1=nr*maxi;
	//g<<mini<<endl<<s1<<endl<<x<<endl;
	if(s1-s>s)
		g<<s1+x-s<<" ";
	else
		g<<s<<" ";
	return 0;
}
