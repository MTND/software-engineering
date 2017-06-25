package dictionaries;

import java.io.*;

public class DictionarySaver implements Runnable {
	Dictionary dict;
	
	public DictionarySaver(Dictionary dict){
		this.dict = dict;
	}
	
	public void run(){
		try{
			ObjectOutputStream os = new ObjectOutputStream(new FileOutputStream("Dictionaries.ser"));
			os.writeObject(dict);
			os.close();
		} catch(IOException e){
			e.printStackTrace();
		}
		System.out.println("Irasyta");
	}
}
