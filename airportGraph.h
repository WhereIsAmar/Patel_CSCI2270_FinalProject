// ---------------------------------------------------------
//  Created by Amar Patel on 7/27/17.                      -
//  Copyright © 2017 Amar Patel. All rights reserved.      -
//  --------------------------------------------------------

#ifndef AIRPORT_H
#define AIRPORT_H

#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>


using namespace std;

struct vertex;


struct adjVertex{
    vertex *v;
    int weight;
};

//Vertex struct
struct vertex{
    string name;
    bool visited;
    int distance;
    vector<adjVertex> adj;
    vertex *previous;
    int airportNum; //Integer that is associated with airport region
    int deletedNum;   //Integer to see if its been removed from our graph
};

//Queue used in Djikstra
struct queueVertex{
    int distance;
    vector<vertex> path;
};


class airportGraph
{
public:
    airportGraph();    //Constructor
    ~airportGraph();   //Destructor
    void addEdge(string v1, string v2, int weight);
    
    void addVertex(string name);
    
    void BFS(string startingAirport, string endingAirport); //Breadth-first search
    
    void dftRecursive(string startingAirport);   //Depth-first search recursively
    
    void dijkstra(string startingAirport, string endingAirport);  //Dijkstra's algorithm
    
    void breadthTraversal(string startingAirport);  //Breadth Traversal
    
    void findFlightPlans(string startingAirport);
    
    void deleteEdge(string startingAirport, string endingAirport);
    void deleteVertex(string airport);
    void displayEdges();
    
private:
   
    vector<vertex> vertices;   //Vertices Vector
    int airportNumIndex;
    
    void search(vertex v);  // used recursively in various traversals
    
};

#endif
