#include<iostream>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	n = ((n * 0x0802LU & 0x22110LU) | (n * 0x8020LU & 0x88440LU)) * 0x10101LU >> 16;
	printf("%d",n);
	return 0;
}
