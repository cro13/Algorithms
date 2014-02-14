#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
int n,i,a[100];
int poz (int li, int ls)
{
	int x,i,j;
	i=li;
	j=ls;
	x=a[li];
	while(i<j)
	{
		while(a[j]>x&&i<j)
			j--;
		a[i]=a[j];
		while(a[i]<x&&i<j)
			i++;
		a[j]=a[i];
	}
	a[i]=x;
	return i;
}
void quick(int li,int ls)
{
	int k;
	if(li<ls)
	{
		k=poz(li,ls);
		if(li<k-1)
			quick(li,k-1);
		if(k+1<ls)
			quick(k+1,ls);
	}
}
void insdirect()
{
	int i,j,aux;
	for(i=1;i<=n;i++)
	{
		j=i;
		while (j>0&&a[j-1]>a[j]) 
        {  
            aux=a[j];  
            a[j]=a[j-1];  
            a[j-1] =aux;  
            j--;  
        }  
     }  
}
int main()
{
	f>>n;
	for(i=1;i<=n;i++)
		f>>a[i];
	if(n<=11)
		insdirect();
	else
	quick(1,n);
	for(i=1;i<=n;i++)
		g<<a[i]<<" ";
	return 0;
}
