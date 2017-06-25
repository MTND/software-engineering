package dictionaries;
import java.util.ArrayList;

public interface ReplacableDictionary extends EditableDictionary {
	void replaceContent(ArrayList<String> words) throws NoContentException;
}
