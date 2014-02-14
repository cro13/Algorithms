/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package huffman;
import static huffman.HuffmanTree.buildTree;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.*;
/**
 *
 * @author Emanuel
 */

class HuffmanTree implements Comparable<HuffmanTree>,Serializable {
	/** The value stored in this tree node. */
	public Character value;

	//stanga
	public HuffmanTree left;

	//dreapta
	public HuffmanTree right;

	//frecventa
	public double frequency;

	//constructor
	public HuffmanTree(Character value, double freq, HuffmanTree left, HuffmanTree right) {
		this.value = value;
		this.frequency = freq;
		this.left = left;
		this.right = right;
	}

	//frunza cu caracter+frecv
	public HuffmanTree(Character value, double freq) { this(value, freq, null, null); }

	/** Creates a null-valued 0-frequency leaf node. */
	public HuffmanTree() { this(null, 0.0); }


	/** Construieste huffman din tabelul de frecvente
	  * @param freqs a table containing character frequencies.
	  * @return a Huffman tree containing the characters prefix codes. */
	public static HuffmanTree buildTree(FrequencyTable freqs) {
		
            //Algoritmul realizeaza un arbore pornind de la cele mai mici frecvente asociate
            //literelor din tabelul de frecvente cu coada de prioritati

		PriorityQueue<HuffmanTree> huffq = new PriorityQueue<HuffmanTree>();

		//adaug intai frunzele din tabelul de frecventa
		for (Map.Entry<Character, Double> mapping : freqs.entrySet())
			huffq.add(new HuffmanTree(mapping.getKey(), mapping.getValue()));

                //construiesc arborele scotand din coada noduri
		while (huffq.size() > 1) {
			HuffmanTree newnode = new HuffmanTree();
			newnode.left = huffq.remove();
			newnode.right = huffq.remove();

			//frecventa este schimbata
			newnode.frequency = newnode.left.frequency + newnode.right.frequency;

			huffq.add(newnode);
		}

		//nodul ramas in coada devine radacina arborelui
		return huffq.remove();
	}


	/** Traversarea arborelui
	  * @return a HashMap containing mappings between characters and codes, in ASCII. */
	public final HashMap<Character, String> getCodes() {
		//No use traversing an empty tree!
		if (left == null && right == null)
			return null;

		HashMap<Character, String> ret = new HashMap<Character, String>();

		//Traverse the tree and populate the HashMap each time we reach a leaf.
		traverse("", ret);
		return ret;
	}


	/** A recursive tree traversal call. Builds Huffman codes when leaves are traversed. */
	private void traverse(String currentcode, HashMap<Character, String> curmappings) {
		//Associate each leaf's value with its Huffman code.
		if (left == null && right == null)
			curmappings.put(value, currentcode);
		
		if (left != null)
			left.traverse(currentcode + "0", curmappings);

		if (right != null)
			right.traverse(currentcode + "1", curmappings);
	}

	/** Compares by frequency. */
	public int compareTo(HuffmanTree rhs) {
		return (frequency < rhs.frequency) ? -1 : ((frequency > rhs.frequency) ? 1 : 0);
	}
}
public class Huffman{
    
    /**
     * @param args the command line arguments
     */
    

    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        String test = "this is an example for huffman encoding";
        
        //tabelul de frecvente
        FrequencyTable fr=new FrequencyTable("in.txt");
        HuffmanTree ht;
        ht=buildTree(fr);
        HashMap<Character,String> hs=ht.getCodes();
        System.out.println(hs);
        
        
        //serializarea
        FileOutputStream fos=new FileOutputStream("huff.ser");
        ObjectOutputStream oos=new ObjectOutputStream(fos);
        oos.writeObject(ht);
        fos.close();
        oos.close();
        
        //deserializarea
        FileInputStream fis=new FileInputStream("huff.ser");
        ObjectInputStream ois=new ObjectInputStream(fis);
        HuffmanTree ht2;
        ht2=(HuffmanTree)ois.readObject();
        HashMap<Character,String> hs2=ht2.getCodes();
        System.out.println(hs2);
        fis.close();
        ois.close();
        
    }
}
