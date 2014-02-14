#include<fstream>
using namespace std;
ifstream f("fact.in");
ofstream g("fact.out");
int n;
long fact(int x)
{ 
	long nr,k,i;
 nr=0;
	if(x==0)
		return 1;
	for(i=5;i<=320000000;i+=5)
		if(i%5==0)
			{
				nr++;k=i;
				if(x==nr)
					break;
		}
		if(i>320000000)
			return -1;
		else
		return k;
}
int main()
{
	f>>n;
	g<<fact(n);
	return 0;
}
