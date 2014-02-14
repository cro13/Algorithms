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
public class Nod<T>{
    T x;
    Nod <T> left;
    Nod <T> right;
    
        Nod(T val){
        x=val;
        left=null;
        right=null;
        }
        
        Nod(T val, Nod<T> l, Nod<T> r){
            x=val;
            left=l;
            right=r;
            
        }
    
}
