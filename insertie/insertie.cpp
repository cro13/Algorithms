#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
int i,n,j,aux,a[100];
int main()
{
	f>>n;
	for(i=1;i<=n;i++)
		f>>a[i];
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
for(i=1;i<=n;i++)
	g<<a[i]<<" ";
return 0;
}
