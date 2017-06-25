package dictionaries;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

public class DictionarySync implements Runnable {
	public PredictionDictionary dict;

	public DictionarySync(PredictionDictionary pd){
		dict = pd;
	}

	public synchronized void run(){
		try{
			ObjectInputStream is = new ObjectInputStream(new FileInputStream("Dictionaries.ser"));
			dict = (PredictionDictionary) is.readObject();
			is.close();
		} catch(Exception e){
			e.printStackTrace();
		}
		
		for(int i = 0; i < 10; i++){
			dict.avaiblePredictions++;
		}
	
		try{
			ObjectOutputStream os = new ObjectOutputStream(new FileOutputStream("Dictionaries.ser"));
			os.writeObject(dict);
			os.close();
		} catch(IOException e){
			e.printStackTrace();
		}
	}
}
