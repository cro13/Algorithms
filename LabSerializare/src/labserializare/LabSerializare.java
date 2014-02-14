/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package labserializare;
import java.util.*;
import java.io.*;
/**
 *
 * @author Emanuel
 */

public class LabSerializare {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        Angajat a1=new Angajat("Bitdefender","Ionica V",28,1800);
	Angajat a2=new Angajat("Microsoft","Bill G.",65,17000);
	FileOutputStream fis=new FileOutputStream("aganajat.ser"); //numele fisierului
	ObjectOutputStream oos=new ObjectOutputStream(fis);
	oos.writeObject(a1);
	oos.writeObject(a2);
	fis.close();
	oos.close();
    }
    
}
