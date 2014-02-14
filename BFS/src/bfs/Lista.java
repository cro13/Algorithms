/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package bfs;
import java.util.*;
/**
 *
 * @author Emanuel
 */
public class Lista <T extends Comparable <T>> implements Iterable <T>{
    public Nod<T> p;
    
    @Override
    public Iterator<T> iterator() 
    { 
        return new cIterator<T>();
    } 
    
    
    public boolean isEmpty(){
        return p==null;
    }
    public void add(T v1){
        if(p==null)
        {
            Nod<T> q=new Nod<T>(v1);
            q.next=p;
            p=q;
        }
        else
        {
            Nod<T> q;
            q=p;
            
            while(q.next!=null)
                 q=q.next;
            Nod<T> s=new Nod(v1);
            s.next=null;
            q.next=s;
            //System.out.println(v1);
            
        }
    }

   @Override
    public String toString(){
        Nod<T> q=p;
        String huge="";
        while(q!=null)
        {
            huge=huge+q.toString()+" ";
            q=q.next;
        }
        return huge;
    }
    
    public void del(){
        Nod<T> q,s;
        q=p;
        if(q.next!=null){
            while(q.next.next!=null)
                 q=q.next;
        
        s=q.next;
        q.next=null;
        s=null;
        }
        else
        {
            p=null;
           }
        
    }
    
    public class cIterator <T extends Comparable> implements Iterator<T>{
        
        Nod<T> nxt;
    public cIterator(){
        
        nxt=(Nod<T>)p;
        
    }
    @Override
     public boolean hasNext() {
    
       if (nxt== null) 
               return (p == null);   
            else 
               return (nxt != null); 
    }
    @Override
    public T next() throws NoSuchElementException{
         if (!hasNext())  
                throw new NoSuchElementException(); 
         else
         {
             Nod<T> prev=nxt;
            // if(nxt.next==null)
                 //return prev.x;
             nxt=nxt.next;
             
             return prev.x; 
         }  
       
    }
    @Override
    public void remove() {
        //nu e necesar
    }
    
}
    
        
}
          
 
      
