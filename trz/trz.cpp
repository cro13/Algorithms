#include<iostream>
using namespace std;
int n,i,*v,*w;
int main()
{
	//cin>>n;
	v=(int *) malloc(100*sizeof(int));
	for(i=0;i<100;i++)
		v[i]=i;
	w=v+1;
	cout<<w[-1000];
	return 0;
}