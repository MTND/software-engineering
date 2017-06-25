package dictionaries;

public interface EditableDictionary {
	void addToDictionary(String word) throws NoContentException;
	void deleteFromDictionary(String word) throws NoContentException;
}
