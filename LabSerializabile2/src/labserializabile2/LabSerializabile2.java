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
public class LabSerializabile2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        Student s=new Student("Ion","Vasile","Unibuc","FMI","Algebra","Geometrie",2,9,10);
        Student s2=new Student("Georgica","Ion","UPB","ACS","Fizica","OOP",1,8,5);
        System.out.println(s.prom());
        FileOutputStream fos=new FileOutputStream("student.ser");
        
        ObjectOutputStream oos=new ObjectOutputStream(fos);
        oos.writeObject(s);
        oos.writeObject(s2);
        
        fos.close();
        oos.close();
        
        FileInputStream fis=new FileInputStream("student.ser");
        ObjectInputStream ois=new ObjectInputStream(fis);
        Student s1=(Student)ois.readObject();
        Student s3=(Student)ois.readObject();
        System.out.println(s1);
        System.out.println(s3);
        
        
        
    }
    
}
