#include<fstream>
using namespace std;
ifstream f("combinari.in");
ofstream g("combinari.out");
int n,p,x[20];
void back()
{
	int i,k;
	k=1;
	x[k]=0;
	while(k)
	{
		while(x[k]<n&&k<=p)
		{
			x[k]++;
			if(k==p)
			{
				for(i=1;i<=k;i++)
					g<<x[i]<<" ";
				g<<endl;
			}
			else
			{
				k++;
				x[k]=x[k-1];
			}
		}
		k--;
	}
}
int main()
{
	f>>n>>p;
	back();
}
