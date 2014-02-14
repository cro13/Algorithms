/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package bfs;
import java.io.File;
import java.util.*;
/**
 *
 * @author Emanuel
 */
public class BFS {
      
    /**
     * @param args the command line arguments
     */
    static void BFS(Lista a[], int n) {
        
        int i,j,info;
        boolean marc[] = new boolean[n+1];
        Lista<Integer> coada = new Lista <Integer>();
        
        coada.add(2);
        info = 2; // bfs din 1
        Nod<Integer> k = coada.p;
        marc[2] = true;
       
        while( true )
        {
            System.out.println(info);
            for(Nod <Integer> q=a[info-1].p;q!=null;q=q.next)
                    if(marc[q.x]==false)
                    {
                        marc[q.x]=true;
                        coada.add(q.x);
                        //System.out.println(q.x);
                    }
            if(k.next==null)
                break;
            
                info=k.next.x;
         
                k=k.next;
          
              
        }
        
        
        
    }
    public static void main(String[] args) {
        File f=new File("in.txt");
        Lista <Integer>[] L;
        
        try{
         Scanner sc=new Scanner(f);
         
         int n;
         n=sc.nextInt();
          
            L = new Lista [n];
         while(sc.hasNextLine())
         {
            
           
            for(int i=0;i<n;i++)
            L[i]=new Lista <Integer>();
            
            for(int i=0;i<n;i++)
            {
               int m=sc.nextInt();
               //L[i].add(i);
               for(int j=0;j<m;j++)
                    L[i].add(sc.nextInt());
            }
            
            
            for(int i=0;i<n;i++)
                System.out.println(L[i]);
             System.out.println('\n');
           BFS(L,n);
         }
         
         //foreach
         System.out.println('\n');
         System.out.println('\n');
         for(int i=0;i<n;i++)
         {
             for (Iterator<Integer> it = L[i].iterator(); it.hasNext();) {
               Integer x = it.next();
                System.out.print(x+" ");
            }
            System.out.println();
         }
         System.out.println('\n');
         System.out.println('\n');
         //foreach2
         for(Lista<Integer> y:L)
             System.out.println(y);
         
         
        }
        catch(Exception e)
        {
            System.out.println(e); 
        }
        
        
         
       
         //(x:L)
            // System.out.println('\n');
        
    }
    
}
