#include<cstdio>
using namespace std;
float x,n,pi,a,b,k;
long calc(int x,int n)
{
	int i,y;
	for(i=1;i<=n;i++)
		y=x*x;
	return y;
}
float arctg(int x,int n)
{
	int k=0;
	k++;
	  if(k%2&&k<10)
		return arctg(calc(x,n)/n,n+2);
	  else
		return arctg(-calc(x,n)/n,n+2);

}
int main()
{
	scanf("%d",&k);
	while(k--)
	{
		a=arctg(1/5,k);
		b=arctg(1/239,1);
	}
	pi=(float)4*(a-b);
	printf("%f",pi);
	return 0;
}
	