
package dictionaries;
import java.util.ArrayList;
import java.util.Collections;

public class SpellingDictionary extends Dictionary {
	private static final long serialVersionUID = 1L;
	private int letterCount;

	public Dictionary clone() throws CloneNotSupportedException{
		Dictionary newClone = (SpellingDictionary) super.clone();
		newClone.words = (ArrayList<String>) words.clone();
		return newClone;
	}

	public void loadDictionary(ArrayList<String> content){
		super.loadDictionary(content);
		Collections.sort(words);
	}
	
	public boolean checkSpelling(String word) throws NoContentException{    
		if(words != null){
			if (words.contains(word)){
				System.out.println("Word is spelled correctly");
				return true;
			} else{
				System.out.println("Word isn't spelled correctly");
				return false;
			}
		} else{
			throw new NoContentException("Dictionary was not loaded", "String");
		}
	}
}
