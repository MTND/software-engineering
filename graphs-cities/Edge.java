package graph;

public class Edge {

	public final Vertex target;
	public final double weight;
	public final String owner;
	
	public Edge(Vertex Target, double weight, String owner){
		this.target = Target;
		this.weight = weight; 
		this.owner = owner;
	}
}
