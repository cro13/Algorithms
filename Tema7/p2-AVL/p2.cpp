#include<fstream>
#include<iostream>
using namespace std;
ifstream f("f.in");
ofstream g("g.out");
struct nod 
{ 
    int info; 
    int ech; 
    nod *st, *dr; 
};
nod *r;
int n;	
void drum_maxim(nod* p,int &max,int lung){ 
    if (p){ 
        drum_maxim(p->dr,max,lung+1); 
        if ((p->st==NULL)&&(p->dr==NULL)&&(max<lung))  
            max=lung; 
        drum_maxim(p->st,max,lung+1); 
    } 
} 
void calcul_factor_echilibru(nod *p){ 
     int h_st,h_dr; 
     h_st=1; h_dr=1; 
     if(p->st!=NULL)   
        drum_maxim(p->st,h_st,1); 
     else  
         h_st=0; 
     if(p->dr!=NULL)  
        drum_maxim(p->dr,h_dr,1); 
     else  
         h_dr=0; 
     p->ech=h_dr-h_st; 
} 
nod *s_rot_dr(nod *p){
	nod *q;
	q=p->st;
	p->st=q->dr;
	q->dr=p;
	calcul_factor_echilibru(p);
	calcul_factor_echilibru(q);
	p=q;
	return p;
}
nod *s_rot_st(nod *p){
	nod *q;
	q=p->dr;
	p->dr=q->st;
	q->st=p;
	calcul_factor_echilibru(p);
	calcul_factor_echilibru(q);
	p=q;
	return p;
}
nod *d_rot_dr(nod *p){
	p->st=s_rot_st(p->st);
	p=s_rot_dr(p);
	return p;
}
nod *d_rot_st(nod *p){
	p->dr=s_rot_dr(p->dr);
	p=s_rot_st(p);
	return p;
}
nod* echilibrare(nod *p){     
    nod *w; 
    calcul_factor_echilibru(p);
    if(p->ech==-2){ 
      w=p->st;  
      if (w->ech==1)
            p = d_rot_dr(p);
      else
          p = s_rot_dr(p); 
    } 
    else 
    if(p->ech==2){
        w=p->dr;
        if (w->ech==-1) 
             p = d_rot_st(p);
        else
             p = s_rot_st(p); 
    } 
    return p; 
} 
nod * insereaza(nod *p,int x){ 
        if (p==0){   
        p=new nod;  
        p->info=x;  
        p->ech=0;    
        p->dr=0;
        p->st=0; 
        return p; 
    } 
    else {
        if (x<p->info) 
            p->st = insereaza(p->st,x);  
        else
            if (x>p->info) 
                p ->dr =insereaza(p->dr,x); 
            else 
                g<<"Nodul exista deja"<<endl; 
    }
	echilibrare(p);
}
nod* stergere(nod *p,int x){ 
    nod *q,*r,*w; 
    if (p!=NULL)
        if (x<p->info) 
            p->st = stergere(p->st,x); 
        else 
            if (x>p->info) 
                p->dr = stergere(p->dr,x);
            else{ 
            q=p; 
            if (q->dr==NULL) 
                p=q->st;
            else 
                if (q->st==NULL) 
                    p=q->dr;
                else{ 
                    w=q->st;
                    r=q;
                    if (w->dr!=NULL)
                    { 
                      while (w->dr!=NULL){ 
                          r=w;  
                          w=w->dr; 
                      } 
                      p->info=w->info;  
                      q=w; 
                      r->dr=w->st;   
                      r=p->st;  
                      w=w->st; 
                      if (r!=NULL) 
                        while ((r!=w)&&(r!=NULL)){ 
                            r = echilibrare(r); 
                            r=r->dr;   
                        } 
                    } 
                    else{ 
                        p->info=w->info;  
                        p->st=w->st; 
                        q=w;  
                    } 
                } 
                delete(q);
            } 
            if (p!=NULL)  
                p = echilibrare(p);
            return p; 
} 
void srd(nod *p)
{
	if(p)
	{
		srd(p->st);
		g<<p->info;
		srd(p->dr);
	}
}
void maxim(nod *p)
{
	while(p->dr)
	p=p->dr;
	g<<p->info<<" ";
}
void cauta(nod *p,int x)
{
int c;
if (p)
{
cauta(p->st,x);
c=p->info;
if(c==x){
	g<<"DA";
	return;}
cauta(p->dr,x);
}
}
int main()
{
	f>>n;
	int x,i;
	for(i=1;i<=n;i++)
	{
		f>>x;
		insereaza(r,x);
	}
	srd(r);
	g<<endl;
	cauta(r,x);
	g<<endl;
	//maxim(r);
	return 0;
	return 0;
}