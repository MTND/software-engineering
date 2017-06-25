package graph;

import java.util.HashMap;
import java.util.List;

public class Graph {
	private final HashMap<String, Vertex> adjacencyList;

	public Graph() {
		adjacencyList = new HashMap<String, Vertex>();
	}

	public void addVertex(String name){
		Vertex newVertex = new Vertex(name);
		adjacencyList.put(name, newVertex);
	}

	public void addEdge(String startVertex, String endVertex, double weight, String owner) {
		adjacencyList.get(startVertex).adjacencies.add(new Edge(adjacencyList.get(endVertex), weight, owner));
	}

	public void printAdjacencyList() {
		for (String name: adjacencyList.keySet()){
			String key = name.toString();
			String value = adjacencyList.get(key).adjacenciesToString();  
			System.out.println(key + "" + value);  
		}
	}

	public void findShortestPath(String source, String target){
		DijkstraAlgorithm.computePaths(adjacencyList.get(source));
		if((adjacencyList.get(target).minDistance) != Double.POSITIVE_INFINITY){
			System.out.println("Distance to " + target + ": " + adjacencyList.get(target).minDistance);
		} else{
			System.out.println("There is no connection from " + source + " to " + target + ".");
			return;
		}
		List<Vertex> path = DijkstraAlgorithm.getShortestPathTo(adjacencyList.get(target));
		System.out.println("Path: " + path);
	}
}