/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package bfs;

/**
 *
 * @author Emanuel
 */
public class Nod <T> {
    T x;
    Nod <T> next;
    public Nod(T xx){
        x=xx;
        next=null;
    }
    @Override
    public String toString()
    {
        return x.toString();
    }
        
}
