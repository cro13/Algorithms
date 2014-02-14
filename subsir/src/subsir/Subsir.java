/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package subsir;

import java.io.File;
import static java.lang.Math.max;
import java.util.Scanner;

/**
 *
 * @author Emanuel
 */
public class Subsir {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        File f=new File("Intrare.txt");
        
        int n, m;
        Scanner sc=new Scanner(f);
        n=sc.nextInt();
        m=sc.nextInt();
        
        int x[],y[];
        int c[][];
        c=new int[n+m+1][m+n+1];
        x=new int[n+1];
        y=new int[m+1];
        
        for(int i=1;i<=n;i++)
            x[i]=sc.nextInt();
        
        for(int i=1;i<=m;i++)
            y[i]=sc.nextInt();
        
        for(int i=1;i<=n;i++)
            if(x[i] == y[0])
                c[i][0]=1;
        else
                c[i][0]=c[i-1][0];
        for(int j=1;j<=m;j++)
            if(x[0] == y[j])
                c[0][j]=1;
        else
                c[0][j]=c[0][j-1];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(x[i]==y[j])
                    c[i][j]=c[i-1][j-1]+1;
        else
                    if(c[i-1][j]>c[i][j-1])
                        c[i][j]=c[i-1][j];
        else
                        c[i][j]=c[i][j-1];
        
        int i=n;int j=m;int lg=0;
        int s[];
        s=new int[n+m+1];
        while(i >= 0 && j >= 0)
        {
            if(i>0 && j>0 && x[i] == y[j])
            {
                lg++;
                s[lg]=x[i];
                i--; j--;
            }
            else
                if(i>0 && j>0 && c[i-1][j] == c[i][j] )
                    i--;
            else
                    j--;
        }
        
        for(int k = lg;k >= 1;k --)
            System.out.print(s[k]+" ");
            }
        }
                
