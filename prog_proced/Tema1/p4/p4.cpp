#include<fstream>
using namespace std;
int n,nrp=0,s=0,maxi=-32000,v[100];
int main()
{
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d",&v[i]);
	for(int i=1;i<=n;i++)
	{
		if(v[i]%2==0)
			nrp++;
		if(v[i]>=0)
			s+=v[i];
		else
			if(v[i]>maxi)
				maxi=v[i];
	}
	printf("%d %d %d",nrp,s,maxi);
	return 0;
}
