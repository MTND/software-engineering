package graph;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

class Roads
{
    public static void main(String[] args) {
        Scanner s;
		try {
			s = new Scanner(new File("dataFinal"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			return;
		}
		
        int vertices = Integer.parseInt(s.nextLine());
        int edges = Integer.parseInt(s.nextLine());
        String startVertex, endVertex;
        int weight;
        String owner;
          
        Graph graph = new Graph();
          
        int i = 0;
          
        while(i < vertices){
        	graph.addVertex(s.nextLine());
        	i++;
        }
        
        i = 0;
        
        while (i < edges) {
            startVertex = s.nextLine();
            endVertex = s.nextLine();
            weight = Integer.parseInt(s.nextLine());
            owner = s.nextLine();  
            graph.addEdge(startVertex, endVertex, weight, owner);
            i++;
        }
          
        graph.printAdjacencyList();
        graph.findShortestPath("A", "M");
        s.close();
        
    }
}