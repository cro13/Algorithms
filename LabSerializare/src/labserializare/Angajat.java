/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package labserializare;
import java.io.*;
/**
 *
 * @author Emanuel
 */
public class Angajat implements Serializable {
     String firma,nume;
    int age,salary;
    public Angajat(String f,String n,int a,int s){
        firma=f;
        nume=n;
        age=a;
        salary=s;
        
    }
}
