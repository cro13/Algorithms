#include <cstdio>
using namespace std;
#define ELEMENTS 6
void shellsort(int A[],int max)
{
	 int stop,swap,limit,temp;
   int x=(int)(max/2)-1;
   while(x>0)
   {
		stop=0;
	  limit=max-x;
	  while(stop==0)
	  {
		   swap=0;
		 for(int k=0;k<limit;k++)
		 {
			  if(A[k]>A[k+x])
			{
				 temp=A[k];
			   A[k]=A[k+x];
			   A[k+x]=temp;
			   swap=k;
			}
		 }
		 limit=swap-x;
		 if(swap==0)
			  stop=1;
	  }
	  x=(int)(x/2);
   }
}

int main()
{
  int i;
  int X[ELEMENTS]={5,2,4,6,1,3};
  printf("Unsorted Array:\n");
  for(i=0;i<ELEMENTS;i++)
			printf("%d ",X[i]);

  shellsort(X,ELEMENTS);
  printf("\nSORTED ARRAY\n");
  for(i=0;i<ELEMENTS;i++)
			printf("%d ",X[i]);
  return 0;

}

