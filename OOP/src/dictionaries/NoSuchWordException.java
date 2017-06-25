package dictionaries;

public class NoSuchWordException extends NoContentException {
	public static final long serialVersionUID = 42;
	public String word;
	
	public NoSuchWordException(){
		super();
	}
	
	public NoSuchWordException(String message){
		super(message);
	}
	  
	public NoSuchWordException(String message, String word){
		this.word = word;
	}
	  
	public NoSuchWordException(String message, Throwable cause){
		super(message, cause);
	}
	  
	public NoSuchWordException(Throwable cause){
		super(cause);
	}
	
	public String getWord(){
		return word;
	}
}
