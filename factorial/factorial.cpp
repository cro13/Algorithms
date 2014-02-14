#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;
int nr_zero(long long x)
{
int sum = 0;
for (int i=5;x / i != 0;i*=5)
{
sum += x / i;
}
return sum;
}
int main()
{
FILE *input = fopen("fact.in","r");
FILE *output = fopen("fact.out","w");
long long p;
fscanf(input,"%lld",&p);
long long MAX = pow(10,9);
long long min = MAX;
long long right =MAX;
long long left = 1;
while (left <= right)
{
long long m = (left + right) / 2;
if (nr_zero(m) == p)
{
if (m< min) min = m;
right = m-1;
}
if (nr_zero(m) <  p)
{
left = m+1;
}
if (nr_zero(m) > p )
{
right = m-1;
}
}
if (min == MAX) min = -1;
fprintf(output,"%lld",min);
fclose(input);
fclose(output);
return 0;
}
