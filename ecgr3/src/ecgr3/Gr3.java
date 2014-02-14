/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package ecgr3;

/**
 *
 * @author Emanuel
 */
class Ec {
     int a,b,c;
   public Ec(int x,int y,int z){
    a=x;
    b=y;
    c=z;
    }
    public int delta(){
        int delt;
        delt=b*b-4*a*c;
        return delt;
    }
    public void solutii(){
        int d=delta();
        int x,x2;
        if(d<0)
        {
            System.out.println("Ecuatia nu are solutii reale!");
        }
        else
        if(d==0)
        {
            System.out.println("Ecuatia are solutie dubla si este:");
            x=(-b)/2*a;
            System.out.println(x);
        }
        else
        {
            System.out.println("Ecuatia are 2 solutii reale distincte si acestea sunt");
            x=(-b)+(int)Math.sqrt(d)/2*a;
            x2=(-b)-(int)Math.sqrt(d)/2*a;
            System.out.println(x);
            System.out.println(" ");
            System.out.println(x2);
     
        }
      }
    
    
}
public class Gr3 {
    int a,b,c,d;
   public Gr3(int x,int y,int z,int t){
       a=x;
       b=y;
       c=z;
       d=t;
   }
  void rad(){
      int coef=d/a;
      if(coef<0)
          coef=-coef;
      System.out.println(coef);
      int []v=new int[4];
      int x1,x2,x3;
      int div;
      for(div=1;div<=coef;div++)
      {
          if(a*div*div*div+b*div*div+c*div+d==0)
          {
              System.out.println("O solutie este: "+div);
              int t1,t2,t3,t4;
              t1=div*a+b;
              t2=div*t1+c;
              t3=div*t2+d;
              t4=d;
              System.out.println(t1+" "+t2+" "+t3+" "+t4);
              
          }
          else
          if(a*(-div)*(-div)*(-div)+b*(-div)*(-div)+c*(-div)+d==0)
          {
              System.out.println("O solutie este: "+(-div));
              int t1,t2,t3,t4;
              t1=-div*a+b;
              t2=-div*t1+c;
              t3=-div*t2+d;
              t4=d;
              System.out.println(t1+" "+t2+" "+t3+" "+t4);
              Ec e=new Ec(t2,t3,t4);
              e.solutii();
          }
      }
              
      
      
  }
    
}
