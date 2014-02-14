#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
int i,j,n,a[100],b[100]; 
int main()
{
	f>>n;
	for(i=1;i<=n;i++)
		{
			f>>a[i];
			b[i]=0;
	}
	for(i=1;i<n;i++)
		for(j=i+1;j<=n;j++)
			if(a[i]==a[j])
				b[i]=1;
			for(i=1;i<n;i++)
				if(a[i]==a[n])
					b[i]=1;
				for(i=1;i<=n;i++)
					if(b[i]==1)
						{
							for(j=i;j<n;j++)
							{a[j]=a[j+1];
							b[j]=b[j+1];

							}
							n--;
							i=0;
							
					}
for(i=1;i<=n;i++)
	g<<a[i]<<" ";
return 0;
}

