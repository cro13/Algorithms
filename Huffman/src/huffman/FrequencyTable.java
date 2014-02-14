/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package huffman;
import java.util.*;
import java.io.*;
/**
 *
 * @author Emanuel
 */
public class FrequencyTable extends HashMap<Character, Double> implements Serializable {
    
   
	public FrequencyTable() { clear(); }

	/**
	 Generez tabelul de frecvente
         */
	public FrequencyTable(String filename) throws FileNotFoundException {
		FileReader infile = new FileReader(filename);
		read(infile);

		try {
			infile.close();
		}
		catch (IOException ioex) {}	
	}

	
	public FrequencyTable(InputStream in) { this(new InputStreamReader(in)); }

	
	public FrequencyTable(Reader in) { read(in); }

	
	public void read(Reader in) {
	
		clear();
		int totalPrefixes = 0;

		
		int readResult;
		while (true) {
			try {
				readResult = in.read();
			}
			catch (IOException ioex) {
				
				readResult = -1;
			}

			if (readResult < 0)
				
				break;

			char readChar = (char) readResult;
			Double charFreq = get(readChar);
			if (charFreq == null)
				charFreq = 0.0;

			put(readChar, charFreq + 1);
			totalPrefixes++;
		}

		
		for (char prefix : keySet())
			put(prefix, get(prefix) / totalPrefixes);
	}
    
}
