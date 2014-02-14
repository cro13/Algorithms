/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package jocul;

import java.io.File;
import static java.lang.Math.max;
import static java.lang.Math.min;
import java.util.Scanner;

/**
 *
 * @author Emanuel
 */
public class Jocul {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        File f=new File("jocul.in");
        
        int n,s1=0,s2=0,l=0;
        int s=0;
        Scanner sc=new Scanner(f);
        n=sc.nextInt();
        int L[],D[][],rez[][];
        L=new int[n+1];
        
        for(int i=1;i<=n;i++){
            L[i]=sc.nextInt();
            s+=L[i];
           
        }
        D=new int[2][s+1];
        rez=new int[n*s+1][n*s+1];
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=s/2;j++){
                D[1-l][j]=D[l][j];
            if(j>=L[i])
            D[1-l][j]=max(D[1-l][j],D[l][j-L[i]]+L[i]);
       
                }
           l=1-l;
        }
        
        s1=D[l][s/2];
        s2=s-D[l][s/2];
        System.out.println(min(s1,s2)+" "+max(s1,s2));
    }
   
}
