/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package selectia;

import java.io.File;
import java.util.Scanner;

/**
 *
 * @author Emanuel
 */
public class Selectia {

    /**
     * @param args the command line arguments
     */
    public static int partition(Integer [] d, int start, int end){
        int pivot=d[end];
        int l=start-1;
        int h=end;
       
        while(true){
            while(d[++l]<pivot);
            while(d[--h]>pivot && h>l);
                if(l>=h)
                  break;
                int temp=d[l];
                d[l]=d[h];
                d[h]=temp; 
        }
       // return 0;
        int temp;
        temp = d[l];
        d[l]=d[end];
        d[end]=temp;
        return l;
        
    }
    public static void select1(Integer [] a,int t){
        int l=0;
        int u=a.length-1;
        do{
            int j=partition(a,l,u);
            if(t==j)
            return; 
            else
                if(t<j)
                    u=j-1;
            else
                    l=j+1;
        }
        while(true);
  } 
    
    public static void main(String[] args) {
        // TODO code application logic here
        int n,t;
        Integer []a;
        File f=new File("in.txt");
        try{
         Scanner sc=new Scanner(f);
         int i = 1;
         n=sc.nextInt();
         t=sc.nextInt();
         a=new Integer[n+1];
         a[0]=0;
         while(sc.hasNextLine())
         {
            int x = sc.nextInt();
            
            a[i++]=x;
            
         }
         select1(a,t);
         System.out.println(a[t]);
        }
        catch(Exception ex){
            System.out.println(ex.toString());
            
        }
      
       //Integer [] a={3,7,2,0,-1,8,1,9,6,4,5,55,54};
       
       
        
        
        
    }
    
}
