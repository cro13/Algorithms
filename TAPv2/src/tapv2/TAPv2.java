/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package tapv2;
import java.util.*;
import java.io.File;
/**
 *
 * @author Emanuel
 */
public class TAPv2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        BST<Integer> t=new BST<Integer>();
        File f=new File("in.txt");
        
        try{
              Scanner sc=new Scanner(f);
                while(sc.hasNextLine())
                     t.insert(sc.nextInt());
        }
        catch(Exception e)
        {
            System.out.println(e);
        }
         System.out.print("SRD: ");
        t.srd(t.root);
        System.out.print('\n'+"SDR: ");
        t.sdr(t.root);
        System.out.print('\n'+"RSD: ");
        t.rsd(t.root);
        System.out.println();
        System.out.println();
        t.remove(7);
        
        System.out.print("SRD: ");
        t.srd(t.root);
        System.out.print('\n'+"SDR: ");
        t.sdr(t.root);
        System.out.print('\n'+"RSD: ");
        t.rsd(t.root);
        System.out.println();
        
        
        
    }
    
}
