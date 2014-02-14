#include<fstream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
int n,a[100],b[100];
void merge_sort(int l, int r)
{
    int m = (l + r) >> 1;
    int	i, j, k;
    if (l == r) return;
    merge_sort(l, m);
    merge_sort(m + 1, r);
    for (i=l, j=m+1, k=l; i<=m || j<=r; )
        if (j > r || (i <= m && a[i] < a[j]))
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    for (k = l; k <= r; k++) a[k] = b[k];
}int main()
{
		int i,k;
		f>>n;
		for(i=1;i<=n;i++)
			f>>a[i];
		for(i=1;i<=n;i++)
			if(a[i]>a[i+1])
			{
				k=i;
				break;
			}
			merge_sort(1,k);
			merge_sort(k+1,n);
		for(i=1;i<=n;i++)
			g<<a[i]<<" ";
		
		return 0;
}
