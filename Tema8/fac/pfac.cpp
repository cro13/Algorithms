#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int h;
int fill=1;
int pw(int n,int x)
{
int i;
int y=1;
for(i=1;i<=x;i++)
y=y*n;
return y;
}
void tromino(int br,int **k,int n)
{
int **b,i,j,x,flag1=0,flag2=0,flag3=0,flag4=0,c,d;

x=pw(2,n);

b=(int**)malloc(sizeof(int)*(x/2)*(x/2));
for(i=0;i<(x/2);i++)
b[i]=(int*)malloc(sizeof(int)*(x/2));


for(i=0;i<(x/2);i++)
for(j=0;j<(x/2);j++)
{
if(k[i][j]!=0)
flag1=1;
}

for(i=(x/2);i<x;i++)
for(j=0;j<(x/2);j++)
{
if(k[i][j]!=0)
flag2=1;
}

for(i=0;i<(x/2);i++)
for(j=(x/2);j<x;j++)
{
if(k[i][j]!=0)
flag3=1;
}
for(i=(x/2);i<x;i++)
for(j=(x/2);j<x;j++)
{
if(k[i][j]!=0)
flag4=1;
}
if(flag1==1)
{
k[(x/2)][(x/2)]=fill;
k[((x/2)-1)][(x/2)]=fill;
k[(x/2)][((x/2)-1)]=fill;
fill++;
}

else if(flag2==1)
{
k[(x/2)][(x/2)]=fill;
k[((x/2)-1)][(x/2)]=fill;
k[((x/2)-1)][((x/2)-1)]=fill;
fill++;
}

else if(flag3==1)
{
k[(x/2)][(x/2)]=fill;
k[(x/2)][((x/2)-1)]=fill;
k[((x/2)-1)][((x/2)-1)]=fill;
fill++;
}
else
{
k[(x/2)][((x/2)-1)]=fill;
k[((x/2)-1)][(x/2)]=fill;
k[((x/2)-1)][((x/2)-1)]=fill;
fill++;
}
if(br<=(n+h))
{
for(i=0;i<(x/2);i++)
for(j=0;j<(x/2);j++)
{
b[i][j]=k[i][j];
}
tromino((br+1),b,(n-1));
for(i=0;i<(x/2);i++)
for(j=0;j<(x/2);j++)
{
k[i][j]=b[i][j];
}
for(c=0,i=(x/2);i<x&&c<(x/2);i++,c++)
for(j=0;j<(x/2);j++)
b[c][j]=k[i][j];
tromino((br+1),b,(n-1));
for(c=0,i=(x/2);i<x&&c<(x/2);i++,c++)
for(j=0;j<(x/2);j++)
k[i][j]=b[c][j];
for(i=0;i<(x/2);i++)
for(d=0,j=(x/2);j<x&&d<(x/2);j++,d++)
b[i][d]=k[i][j];
tromino((br+1),b,(n-1));

for(i=0;i<(x/2);i++)
for(d=0,j=(x/2);j<x&&d<(x/2);j++,d++)
k[i][j]=b[i][d];


for(c=0,i=(x/2);i<x&&c<(x/2);i++,c++)
for(d=0,j=(x/2);j<x&&d<(x/2);j++,d++)
b[c][d]=k[i][j];

tromino((br+1),b,(n-1));

for(c=0,i=(x/2);i<x&&c<(x/2);i++,c++)
for(d=0,j=(x/2);j<x&&d<(x/2);j++,d++)
k[i][j]=b[c][d];
}
}
int main()
{
int **a,i,j,n,x=1;

printf("Valoare pentru  n\n");
scanf("%d",&n);

x=pw(2,n);

h=n-3;
printf("Tromino Puzzle :: %dx%d \n",x,x);

a=(int**)malloc(sizeof(int)*x*x);
for(i=0;i<x;i++)
a[i]=(int*)malloc(sizeof(int)*x);

for(i=0;i<x;i++)
{
for(j=0;j<x;j++)
{
a[i][j]=0;
}
}

printf("Valorile lui i&j pentru coltul liber\n");
scanf("%d%d",&i,&j);
while(i>x || j>x)
{
printf("Introduceti valori corecte pentru i si j\n");
scanf("%d%d",&i,&j);
}
a[i][j]=10000;


tromino(1,a,n);

a[i][j]=0;


for(i=0;i<x;i++)
{
printf("\n\n");
for(j=0;j<x;j++)
{
printf("%d\t",a[i][j]);
}
}

printf("\n\n");
}