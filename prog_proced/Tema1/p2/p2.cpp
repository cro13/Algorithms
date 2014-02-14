#include<iostream>
using namespace std;
int x,y;
int sumadiv(int n)
{
	int sd=0,i;
	for(i=1;i<=n/2;i++)
		if(n%i==0)
			sd+=i;
		return sd;
}
int main()
{
	scanf("%d %d",&x,&y);
	if(x==sumadiv(y)&&y==sumadiv(x))
		printf("Numere prietene");
	else
		printf("Nu sunt numere prietene");
	return 0;
}
