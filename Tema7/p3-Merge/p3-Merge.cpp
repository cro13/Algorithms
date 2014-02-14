#include<cstring>
#include<iostream>
using namespace std;
int N, A[100], B[100];
void merge_sort(int l, int r)
{
    int m = (l + r) >> 1;
    int	i, j, k;
    if (l == r) return;
    merge_sort(l, m);
    merge_sort(m + 1, r);
    for (i=l, j=m+1, k=l; i<=m || j<=r; )
        if (j > r || (i <= m && A[i] < A[j]))
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    for (k = l; k <= r; k++) A[k] = B[k];
}
int main()
{
	cin>>N;
	int i;
	for(i=1;i<=N;i++)
		cin>>A[i];
	merge_sort(1,N);
	for(i=1;i<=N;i++)
		cout<<A[i]<<" ";
	return 0;
}
