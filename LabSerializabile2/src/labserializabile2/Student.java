/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package labserializabile2;
import java.io.*;
/**
 *
 * @author Emanuel
 */
public class Student implements Serializable {
    String nume,prenume,universitatea,facultatea,d1,d2;
    int an,n1,n2;
    public Student(String fname,String lname,String uni,String fac,String d1,String d2,int an,int n1,int n2){
        nume=fname;
        prenume=lname;
        universitatea=uni;
        facultatea=fac;
        this.d1=d1;
        this.d2=d2;
        this.an=an;
        this.n1=n1;
        this.n2=n2;
        
    }
    public String prom(){
        double med;
        med=(n1+n2)/2;
        if(med<5)
            return "repetent";
        return "promovat";
    }
    @Override
    public String toString(){
        return nume+" "+prenume+" "+universitatea+" "+facultatea+" "+d1+" "+d2+" "+n1+" "+n2+'\n';
        
        
        
    }
}
