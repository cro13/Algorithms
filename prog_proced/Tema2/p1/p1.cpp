#include<cstdio>
using namespace std;
int n;
int numar(int n)
{
	int nr=0;
	for(int i=0;i<8*sizeof(int);i++)
		if (n & (1 << i))
		nr++;
	return nr;
}
int main()
{
	scanf("%d", &n);
	printf("%d",numar(n));
	return 0;
}
