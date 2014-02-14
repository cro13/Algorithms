 #include<fstream>
 using namespace std;
 ifstream f("f.in");
 ofstream g("g.out");
 int n,A[100];
int random_partition(int* A, int start, int end)
{
    srand(time(NULL));
    int pivotIdx = start + rand() % (end-start+1);
    int pivot = A[pivotIdx];
    swap(A[pivotIdx], A[end]); 
    pivotIdx = end;
    int i = start -1;
 
    for(int j=start; j<=end-1; j++)
    {
        if(A[j] <= pivot)
        {
            i = i+1;
            swap(A[i], A[j]);
        }
    }
 
    swap(A[i+1], A[pivotIdx]);
    return i+1;
}
 
void random_quick_sort(int* A, int start, int end)
{
    if(start < end) {
        int mid = random_partition(A, start, end);
        random_quick_sort(A, start, mid-1);
        random_quick_sort(A, mid+1, end);
    }
}
int main()
{
	f>>n;
	for(int i=0;i<=n;i++)
		f>>A[i];
    random_quick_sort(A, 0,n);
	for(int i=1;i<=n;i++)
		g<<A[i]<<" ";
	return 0;
}
