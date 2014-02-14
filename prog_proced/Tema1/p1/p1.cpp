#include<iostream>
#include<cstdio>
using namespace std;
int n;
bool prim(int x, int d)
{
	if(x<=1)
		return 0;
	else
		if(d==1)
			return 1;
		else
			if(x%d==0)
				return 0;
			else
				return prim(x,d-1);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		if(n%i==0&&prim(i,i/2))
			printf("%d ",i);
	return 0;
}
