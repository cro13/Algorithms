#include<iostream>
using namespace std;
int i,n,j,a[20][20];
void matr(int i,int j)
{
	if(i<=n)
	if(i==1||j==1)
		{
			a[i][j]=1;
				if(j>n)
				   matr(i+1,1);
				else
					matr(i,j+1);
						
	}
	else
		if(i+j<=n+1)
			{
				a[i][j]=i+j-2;
				if(j>n)
				   matr(i+1,1);
				else
					matr(i,j+1);
		}
	
	else
	if(j>n)
		matr(i+1,1);
				else
					matr(i,j+1);
}
int main()
{
	cin>>n;
	matr(1,1);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}