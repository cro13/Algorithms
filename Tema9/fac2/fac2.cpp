#include<iostream>
using namespace std;
int i,n,maxi,s,v[100];
int main()
{
	cin>>n;
	 for(i=1;i<=n;i++)
		cin>>v[i];
	maxi=v[1];
	for(i=1;i<=n;i++)
	{
		s+=v[i];
		if(maxi<s)
			maxi=s;
		if(s<0)
			s=0;
	}
 cout<<maxi<<endl;
return 0;
}
