#include<iostream>
using namespace std;
int n,m,x,a[100],v[100];
int main()
{
	int i;
	scanf("%d", &n);
	for(i=1;i<=n;i++)
		v[i]=0;
	for(i=1;i<=n;i++)
		{
			scanf("%d", &x);
			v[x]++;
	}
	m=1;
	for(i=1;i<=n;i++)
		if(v[i]>0)
		{
			a[m]=i;
			m++;
		}
		m--;
			for(i=1;i<=m;i++)
				printf("%d ",a[i]);
			return 0;
}
