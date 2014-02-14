#include<cstdio>
using namespace std;
int n,k;
int number;

int mirror(int n)
{n |= 1 << (k-1);

return n;
}

int main()
{	

scanf("%d %d",&n,&k);

printf("%d",mirror(n));

return 0;
}
