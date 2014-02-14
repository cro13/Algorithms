#include<cstdio>
using namespace std;
int n,m;
long ack(int n, int m)
{
	if(n==0)
		return m+1;
	else
		if(m==0)
			return ack(n-1,1);
		else
			if(n&m)
				return ack(n-1,ack(n,m-1));
}
	
int main()
{
	scanf("%d %d",&n,&m);
	printf("%ld",ack(n,m));
	return 0;
}
