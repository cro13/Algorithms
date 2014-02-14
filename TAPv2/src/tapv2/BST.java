/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package tapv2;

/**
 *
 * @author Emanuel
 */
public class BST <T extends Comparable <T>> {
    Nod<T> root=null;
    
    public BST(){
       
    }
    
    public BST(T val){
       
        root=new Nod<T>(val);
        
    }
    
    public BST(Nod<T> rad){
        
        root=rad;
        
    }
    
   public Nod<T> insert(T val,Nod<T> node){
        if(node==null)
            return new Nod<T>(val);
        if(val.compareTo(node.x)==0)
            node.x=val;
        else
            if(val.compareTo(node.x)<0)
                node.left=insert(val,node.left);
        else
                node.right=insert(val,node.right);
        return node;
            
    }
    public void insert(T val){
        root=insert(val,root);
        
    }
   
    public T getRightson(Nod<T> node){
        //if(node!=null)
            Nod<T> right=node.right;
            if(right==null)
                return node.x;
            else
                return getRightson(right);
      
        
    }
    
    public Nod<T> remove(T value,Nod<T> node){
        if(node==null)
            return null;
        if(value.compareTo(node.x)==0){
            if(node.left==null)
                return node.right;
        else
                if(node.right==null)
                    return node.left;
        else
                {
                    node.x=getRightson(node.left);
                    node.left=remove(node.x,node.left);
                    
                }
        }
        else
            if(value.compareTo(node.x)<0)
                node.left=remove(value,node.left);
            else
                node.right=remove(value,node.right);
        return node;
        
    }
    
    public void remove(T val){
        if(remove(val,root)!=null)
            root=remove(val,root);
        else
            System.out.println("Elementul nu exista");
    }
    
    public void srd(Nod<T> rad){
        if(rad!=null){
            srd(rad.left);
            System.out.print(rad.x+" ");
            srd(rad.right);
        }
      
    }
    
    public void rsd(Nod<T> rad){
        if(rad!=null){
            System.out.print(rad.x+" ");
            rsd(rad.left);
            rsd(rad.right);
        }
      
       
    }
    
    public void sdr(Nod<T> rad){
        if(rad!=null){
            sdr(rad.left);
            sdr(rad.right);
            System.out.print(rad.x+" ");
        }
      
       
    }
    
    
}
