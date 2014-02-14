/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package fillmatrix;
import java.util.*;
/**
 *
 * @author Emanuel
 */
public class FillMatrix {
    public static int a[][],l,c;
    public static int p=1;
    /**
     * @param args the command line arguments
     */
   public static void DI(int i, int j,int d,int l,int c){
       if(d==2)
       {
           for(int k=i;k<i+d;k++)
               for(int t=j;t<j+d;t++)
                   if(a[k][t]!=-1&&a[k][t]!=1)
                       a[k][t]=p;
           p++;
           }
       else
       {
           int mi=i+d/2;
           int mj=j+d/2;
          // System.out.println(mi+" "+mj+" "+l+" "+c+" ");
           if(l<mi&&c<mj){//cadran 1
               
               a[mi-1][mj]=p; //marc 2
               a[mi][mj]=p; //marc  4
               a[mi][mj-1]=p;//marc 3
              // a[mi-1][mj-1]=p; //marc 1
               p++;
               DI(mi,mj,d/2,mi,mj);//cadran 4
               DI(mi,j,d/2,mi,mj-1);//cadran 3
               DI(i,mj,d/2,mi-1,mj);//cadran 2
               DI(i,j,d/2,l,c);//cadran 1
               
               }
           else
               if(l<mi&&c>=mj){//cadran 2
                  // a[mi-1][mj]=p; //marc 2
                   a[mi][mj]=p; //marc  4
                   a[mi][mj-1]=p;//marc 3
                   a[mi-1][mj-1]=p; //marc 1
                   p++;
                 DI(mi,mj,d/2,mi,mj);//cadran 4
                 DI(mi,j,d/2,mi,mj-1);//cadran 3
                 DI(i,mj,d/2,mi-1,mj);//cadran 2
                 DI(i,j,d/2,l,c);//cadran 1
               }
           else
               if(l>=mi&&c<mj){//cadran 3
                   a[mi-1][mj]=p; //marc 2
                   a[mi][mj]=p; //marc  4
                  // a[mi][mj-1]=p;//marc 3
                   a[mi-1][mj-1]=p; //marc 1
                   p++;
                 DI(mi,mj,d/2,mi,mj);//cadran 4
                 DI(mi,j,d/2,mi,mj-1);//cadran 3
                 DI(i,mj,d/2,mi-1,mj);//cadran 2
                 DI(i,j,d/2,l,c);//cadran 1
                   
                   
                   
               }
           else
                   if(l>=mi&&c>=mj){//cadran 4
                   a[mi-1][mj]=p; //marc 2
                  // a[mi][mj]=p; //marc  4
                   a[mi][mj-1]=p;//marc 3
                   a[mi-1][mj-1]=p; //marc 1
                   p++;
                 DI(mi,mj,d/2,mi,mj);//cadran 4
                 DI(mi,j,d/2,mi,mj-1);//cadran 3
                 DI(i,mj,d/2,mi-1,mj);//cadran 2
                 DI(i,j,d/2,l,c);//cadran 1
                       
                       
                       
                   }
           
       }
        
        
    }
    
    
    public static void main(String[] args) {
        // TODO code application logic here
        //a[][]=new int[5][5];
        a=new int [5][5];
        for(int i=1;i<5;i++)
            for(int j=1;j<5;j++)
                a[i][j]=0;
        l=3;
        c=1;
        a[l][c]=-1;
        DI(1,1,4,l,c);
        for(int i=1;i<5;i++)
        {
            for(int j=1;j<5;j++)
                System.out.print(a[i][j]+" ");
            System.out.print('\n');
    }
        
    }
    
}
