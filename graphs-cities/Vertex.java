package graph;

import java.util.LinkedList;

public class Vertex implements Comparable<Vertex> {

	public final String name;
	public LinkedList<Edge> adjacencies = new LinkedList<Edge>();
	public double minDistance = Double.POSITIVE_INFINITY;
	public Vertex previous;
	public String prevEdgeOwner = "";
	public boolean ownerFlag = false;
	
	public Vertex(String argName){
		name = argName;
	}
	
	public String toString(){
		return name;
	}
	
	public String adjacenciesToString(){
		int i;
		String message= "";
		StringBuilder e = new StringBuilder();
		for(i = 0; i < adjacencies.size(); i++){
			e.append(" -> "+ adjacencies.get(i).target.name);
		}
		message = e.toString();
		return message;
	}
	
	public int compareTo(Vertex other){
		return Double.compare(minDistance, other.minDistance);
	}
}
