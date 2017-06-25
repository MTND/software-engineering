package dictionaries;

import java.io.*;

public class DictionaryReader implements Runnable {
	public Dictionary dict;
	
	public void run(){
		try{
			ObjectInputStream is = new ObjectInputStream(new FileInputStream("Dictionaries.ser"));
			dict = (Dictionary) is.readObject();
			is.close();
		} catch(Exception e){
			e.printStackTrace();
		}
		System.out.println("Nuskaityta");
	}
}
