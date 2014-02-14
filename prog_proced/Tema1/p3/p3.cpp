#include<iostream>
using namespace std;
float a,b,c,d;
int k;
int main()
{
	printf(" Pentru ecuatie de gradul 1 apasati tasta 1 \n Pentru ecuatie de gradul 2 apasati tasta 2 \n");
	scanf("%d",&k);
	
	if(k==1)
	{
		printf("Introduceti coeficientul pentru X respectiv pentru termenul liber \n");
		scanf("%f %f",&a, &b);
		printf("%f %f",a,b);
		if(a==0)
			printf("Incorect ");
		else
		printf("Solutia este %f ",-b/a);
	}
	else
		if(k==2)
	{
		printf("Introduceti coeficientul lui X^2,X si termen liber in aceasta ordine \n");
		scanf("%f %f %f",&a,&b,&c);
		d=b*b-4*a*c;
		if(d>0)
		{
			printf("O solutie este %f ", (-b+sqrt(d))/(2*a));
			printf("O alta solutie este %f ", (-b-sqrt(d))/(2*a));
		}
		else
			if(d==0)
				printf("Solutia dubla este %f ", (-b+sqrt(d))/(2*a));
			else
				printf("Nu se poate rezolva in corpul numerelor reale");
	} 
	else
printf("Optiune nevalabila");		
	return 0;
}
