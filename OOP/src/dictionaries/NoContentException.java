package dictionaries;

public class NoContentException extends Exception {
	public static final long serialVersionUID = 42;
	public String expectedContentType;
	
	public NoContentException(){
		super();
	}
	  
	public NoContentException(String message){
		super(message);
	}
	
	public NoContentException(String message, String expectedType){
		super(message);
		expectedContentType = expectedType;
	}
	  
	public NoContentException(String message, Throwable cause){
		super(message, cause);
	}
	  
	public NoContentException(Throwable cause){
		super(cause);
	}
	
	public String getExcpectedContentType(){
		return expectedContentType;
	}
}
