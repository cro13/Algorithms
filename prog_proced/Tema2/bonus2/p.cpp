#include<cstdio>
using namespace std;

double putere(float x, float exp)
{
		while(exp > 1)
		{
			x=x*x; 
			exp--;}
	return x;
}

double arctan(float x, int n, float exp)
{
	if(!n)
	  return putere(x,exp)/exp;
	else 
		if(!(n&1))
			return putere(x,exp)/exp-arctan(x,n-1,exp+2);
	else 
		return putere(x, exp)/exp+arctan(x,n-1,exp+2);
}
	

int main()
	{
		
		
		double pi,y;
		y=arctan(1.0/239.0, 10, 1);
		pi = 4* (4*arctan(1.0/5.0, 10, 1) -  y);
		
		printf("%f",pi);
		
		return 0;
}
