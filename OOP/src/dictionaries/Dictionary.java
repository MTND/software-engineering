
package dictionaries;
import java.util.ArrayList;
import java.io.*;

abstract public class Dictionary implements ReplacableDictionary, Cloneable, Serializable { 
	private static final long serialVersionUID = 1L;
	protected ArrayList<String> words;
	

	public Dictionary clone() throws CloneNotSupportedException{
		return (Dictionary) super.clone();
	}

	public void addToDictionary(String word) throws NoContentException{
		if(words != null){
			words.add(word);
		} else{
			throw new NoContentException("Dictionary was not loaded", "String");
		}
	}

	public void deleteFromDictionary(String word) throws NoContentException{
		if(words != null){
			if (words.contains(word) == true){
				words.remove(word);
			} else{
				throw new NoSuchWordException("Word is not avaible", word);
			}
		} else{
			throw new NoContentException("Dictionary was not loaded", "String");
		}
	}

	public void replaceContent(ArrayList<String> words) throws NoContentException{
		if(words != null){
			this.words = words;
		} else{
			throw new NoContentException("Dictionary was not loaded", "String");
		}
	}

	public void loadDictionary(ArrayList<String> content){
		words = new ArrayList<String>(content);
	}

	public boolean wordExists(String word) throws NoContentException{
		if(words != null){
			if (words.contains(word)){
				return true;
			} else{
				return false;
			}
		} else{
			throw new NoContentException("Dictionary was not loaded", "String");
		}
	}

}
