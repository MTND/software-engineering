
package dictionaries;
import java.util.ArrayList;
import java.util.Collections;

public class PredictionDictionary extends Dictionary implements Comparable<PredictionDictionary>{
	private static final long serialVersionUID = 1L;
	public int avaiblePredictions = 0;
    
	public int compareTo(PredictionDictionary pd){
		if(avaiblePredictions > pd.avaiblePredictions){
			return 1;
		}
		if(avaiblePredictions < pd.avaiblePredictions){
			return -1;
		}
		if(avaiblePredictions == pd.avaiblePredictions){
			return 0;
		}
		return 0;
	}
	
    public Dictionary clone() throws CloneNotSupportedException{
    	PredictionDictionary newClone = (PredictionDictionary) super.clone();
    	newClone.words = (ArrayList<String>) words.clone();
    	return newClone;
    }
    
	public void loadDictionary(ArrayList<String> content){
		super.loadDictionary(content);
		Collections.sort(words);
	}
    
    public void predictWord(String word) throws NoContentException{
    	avaiblePredictions = 0;
    	if(words != null){
    		if (words.contains(word)){
    			avaiblePredictions++;
    			System.out.println("Predicted word:" + word);
    		} else{
    			System.out.println("Couldn't match word");
    		}
    	} else{
    		new NoContentException("Dictionary was not loaded", "String");
    	}
    }
}
