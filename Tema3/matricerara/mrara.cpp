#include<iostream>
using namespace std;
//ifstream f("f.in");
//ofstream g("g.out");
struct ElementMR{
	 int l,c;
	double val;
};
struct NodMR{
	ElementMR tuplu;
	NodMR *next;
};
 
NodMR* InserareSf(NodMR* l,ElementMR e){
	NodMR* nou=new NodMR;
	nou->tuplu=e;
	nou->next=NULL;
	if(!l)
		return nou;
	else{
		NodMR* temp=l;
		while(temp->next)
			temp=temp->next;
		temp->next=nou;
		return l;
	}
}
 
NodMR* ConversieToLSMatriceRara(double A[][100],  int m,  int n, 
char *err,  int *nrEl){
	*nrEl=0;
	 int i,j;
	NodMR *lstMR=NULL;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			if(A[i][j])
				(*nrEl)++;
	double pondere=*nrEl;
	pondere=pondere/(m*n);
	if(pondere>=0.0015 && pondere<=0.03){
		*err=1;
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				if(A[i][j]){
					ElementMR t;
					t.l=i+1;
					t.c=j+1;
					t.val=A[i][j];
					lstMR=InserareSf(lstMR,t);
				}
		return lstMR;
	}
	else{
		*err=0;
		return 0;
	}
}
 
NodMR* StergereInc(NodMR* l){
	if(l){
		NodMR* temp=l;
		l=l->next;
		delete temp;
	}
	return l;
}
 
 
NodMR* ExtragereNodPoz(NodMR* l, int poz,  int n){
	if(poz<1 || poz >n)
		return 0;
	else{
		NodMR *temp=l;
		 int i;
		for(i=1;i<poz;i++)
			temp=temp->next;
		return temp;
	}
}
 
int main(){
	double Mat[25][100],val;
	 int m, n, i, j;
	 int nrEl;
	char err;
	m=25;
	n=100;
	NodMR *lstMatRara=NULL;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			Mat[i][j]=0;
 
	char opt='y';
	while(opt=='y'){
		do{
			cout<<"Introduceti linia elementului dorit ";
			cin>>i;
		}
		while(i>25 || i==0);
		do{
			cout<<"Introduceti coloana elementului dorit  ";
			cin>>j;
		}
		while(j>100 || j==0);
		cout<<"Introduceti valoarea elementului dorit ";
		cin>>val;
		if(!Mat[i-1][j-1])
			Mat[i-1][j-1]=val;
		else{
			cout<<"Dati pozitia elementului care nu este null! Suprascrieti elementul?(y/n): ";
			cin>>opt;
			if(opt=='y')
				Mat[i-1][j-1]=val;
		}
		cout<<"Continuati?(y/n): ";
		cin>>opt;
	}
 
	lstMatRara=ConversieToLSMatriceRara(Mat,m,n,&err,&nrEl);
 
	if(err){
		cout<<"Structura matricei rare este: "<<endl;
		//displaying the linked list
		for(i=1;i<=nrEl;i++){
			NodMR *t;
			t=ExtragereNodPoz(lstMatRara,i,nrEl);
			if(t){
				cout<<t->tuplu.l<<"\t"<<t->tuplu.c<<"\t" \
<<t->tuplu.val<<endl;
			}
		}
 
		//deleting the linked list
		while(lstMatRara)
			lstMatRara=StergereInc(lstMatRara);
	}
	else
		cout<<"Matricea nu respecta criteriile de matrice rara"<<endl;
return 0;
}
