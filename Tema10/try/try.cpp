#include<string>
#include<cstdio>
#include<cstdlib>
using namespace std;
char s[20],t[20],n;
void *copiaza_n(char *s,char *t,int n)
{char *p=s+strlen(s);
int i=0,x;
x=strlen(s);
while(n--)
{
	*(s+x+i)=*(t+i);
	i++;
}
//return p;
}
int main()
{
scanf("%s",&s);
printf("n=");
scanf("%d",&n);
scanf("%s",&t);
copiaza_n(s,t,n);
printf("%s",s);
return 0;
}
