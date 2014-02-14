#include<cstdio>
using namespace std;
int x;
int MP(int x)
{
	if(x>=12)
		return x-1;
	else
		return MP(MP(x+2));
}
int main()
{
	scanf("%d",&x);
	printf("%d",MP(x));
	return 0;
}
