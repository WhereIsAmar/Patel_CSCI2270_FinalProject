// ---------------------------------------------------------
//  Created by Amar Patel on 7/27/17.                      -
//  Copyright © 2017 Amar Patel. All rights reserved.      -
//  --------------------------------------------------------
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include "airportGraph.h"
using namespace std;

airportGraph::airportGraph()
{
    //constructor
    airportNumIndex = 1;
}

airportGraph::~airportGraph()
{
    //deconstructor
}

void airportGraph::addVertex(string name)
{
    bool located = false;
    
    //Move through all vertices
    for(int i = 0; i < vertices.size(); i++)
    {
        // If located then go into this loop
        if(vertices[i].name == name)
        {
            located = true;
            cout<< vertices[i].name<<" Located."<<endl;
        }
    }
    
    
    if(located == false){
        vertex v;
        v.name = name;
        v.distance = 0;
        v.airportNum = -1;
        vertices.push_back(v);
    }
}

void airportGraph::addEdge(string v1, string v2, int weight)
{
    //Loop through all of the vertices
    for(int i = 0; i < vertices.size(); i++)
    {
       
        if(vertices[i].name == v1)
        {
            
            for(int j = 0; j < vertices.size(); j++)
            {
                if(vertices[j].name == v2 && i != j)
                {
                    // After sucessfully finding v1 and v2 create an Adjacent vertex
                    adjVertex av;
                    av.v = &vertices[j];
                    av.weight = weight;
                    vertices[i].adj.push_back(av);
                   
                    adjVertex av2;
                    av2.v = &vertices[i];
                    av2.weight = weight;
                    vertices[j].adj.push_back(av2);
                }
            }
        }
    }
}

void airportGraph::BFS(string airport_1, string airport_2)
{
    vector<vertex> path; //Vector to stores the shortest
    int distance;
    
    vertex *departingAirport1 = NULL;
    vertex *arrivalAirport = NULL;
    
    vertex u;
    
   
    bool airports1found = false;
    bool airports2found = false;
    
    queue<queueVertex> shortestPathQueue;
    
   
    for (int i = 0; i < vertices.size(); i++)
    {
        if (vertices[i].name == airport_1)
        {
            airports1found = true;
            departingAirport1 = &vertices[i];
        }
        else if (vertices[i].name == airport_2)
        {
            airports2found = true;
            arrivalAirport = &vertices[i];
        }
    }
    
    if (airports1found == false || airports2found == false)
    {
        cout << "Airport is either the Departing airport or not Present" << endl;
        return;
    }
    
    if(departingAirport1->airportNum == -1)
    {
        cout << "Airports were not Generated, choose option 3. Then try again." << endl;
        return;
    }
    else if(departingAirport1->airportNum != arrivalAirport->airportNum)
    {
        cout << "These Airports are not in the Same Flight Region" << endl;
        return;
    }
    
    if (airports1found && airports2found)
    {
        
        for (int i = 0; i < vertices.size(); i++)
        {
            if (vertices[i].name != departingAirport1->name)
            {
                vertices[i].visited = false;
            }
            else
            {
                vertices[i].visited = true;
            }
            
        }
        
        departingAirport1->visited = true;
        
        queueVertex qv; //Instance of queue vertex
        
        qv.distance = 0;
        qv.path.push_back(*departingAirport1);
        
        shortestPathQueue.push(qv); //Add the queue vertex to shortestPathQueue
        
        while (!(shortestPathQueue.empty()))
        {
            qv = shortestPathQueue.front();
            shortestPathQueue.pop();          //Remove the current queue vertex
            
            vertex *v = NULL;
            
            int endFlight = qv.path.size();
            
            
            for (int i = 0; i < qv.path[endFlight-1].adj.size(); i++)
            {
                v = qv.path[endFlight-1].adj[i].v;
                
                if (v->visited == false)
                {
                    path = qv.path;
                    v->visited = true;
                    
                    distance = qv.distance + 1;
                    path.push_back(*v);
                    
              
                    queueVertex temp;
                    temp.path = path;
                    temp.distance = distance;
                    
                
                    if (v->name == airport_2)
                    {
                      
                        cout << temp.distance << ", ";
                        for (int j = 0; j < temp.path.size(); j++)
                        {
                            if(j != temp.path.size()-1)
                                cout << " " << temp.path[j].name << ", ";
                            else
                                cout << " " << temp.path[j].name;
                        }
                    }
                    else
                    {
                      
                        shortestPathQueue.push(temp);
                    }
                    
                }
            }
        }
        cout << endl;
        
    }
}

void airportGraph::dftRecursive(string airportStart)
{
    vertex *departingAirport1 = NULL;
    
    bool airport_1 = false;
    
    for (int i = 0; i < vertices.size(); i++)
    {
        if (vertices[i].name == airportStart)
        {
            vertices[i].visited = true;
            departingAirport1 = &vertices[i];
            airport_1 = true;
        }
        else
        {
            vertices[i].visited = false;
        }
    }
    
    if(airport_1 == false)
    {
        cout << "Airport could not be located" << endl;
        return;
    }
    
    if(departingAirport1->airportNum == -1)
    {
        cout << "Airports were not Generated, choose option 3. Then try again." << endl;
        return;
    }
    
    cout << departingAirport1->airportNum << ":" << departingAirport1->name << " ";            for (int i = 0; i < departingAirport1->adj.size(); i++)
    {
        if (departingAirport1->adj[i].v->visited == false)
        {
            cout << departingAirport1->adj[i].v->airportNum << ":" << departingAirport1->adj[i].v->name << " ";
            departingAirport1->adj[i].v->visited = true;
            
         // search method prints Adjacent vertices as a priority
            search(*departingAirport1->adj[i].v);
            
        }
    }
    cout << endl;
    
}


void airportGraph::search(vertex u)
{
    u.visited = true;   //Set vertex u to visited
    
  
    for (int i = 0; i < u.adj.size(); i++)
    {
        if (u.adj[i].v->visited == false)
        {
            u.adj[i].v->visited = true;
            
          
            bool visited = true;
            for (int i = 0; i < vertices.size(); i ++)
            {
                if (vertices[i].visited == false)
                {
                    visited = false;
                }
            }
            if (visited)
            {
                cout << u.adj[i].v->airportNum << ":" << u.adj[i].v->name << endl;
            }
            else
            {
                cout << u.adj[i].v->airportNum << ":" << u.adj[i].v->name << " ";
            }
            
            //Recursively call search
            search(*u.adj[i].v);
            
        }
    }
}


void airportGraph::breadthTraversal(string airportStart)
{
    vertex *departingAirport1 = NULL;    // stores our starting Airport
    
    bool airport_1 = false; // was it found?
    
   
    for (int i = 0; i < vertices.size(); i ++)
    {
        vertices[i].visited = false;
        if (vertices[i].name == airportStart)
        {
            departingAirport1 = &vertices[i];
            vertices[i].visited = true;
            airport_1 = true;
        }
    }
    
    if(airport_1 == false)
    {
        cout << "Airport could not be located" << endl;
        return;
    }
    
    if(departingAirport1->airportNum == -1)
    {
        cout << "Airports were not Generated, choose option 3. Then try again." << endl;
        return;
    }
    
    cout << departingAirport1->airportNum << ":" << departingAirport1->name << " "; // Prints based on our starting airport
    vertex u;
    
    queue<vertex> breadthQueue;
    breadthQueue.push(*departingAirport1);
    
    while (!(breadthQueue.empty()))
    {
        u = breadthQueue.front();
        breadthQueue.pop();
        
       
        for (int i = 0; i < u.adj.size(); i++)
        {
            if (u.adj[i].v->visited == false)
            {
                u.adj[i].v->visited = true;
                
                bool visited = true;
                
                
                for (int i = 0; i < vertices.size(); i ++)
                {
                    if (vertices[i].visited == false)
                    {
                        visited = false;
                    }
                }
                
              
                if (visited)
                {
                    cout << u.adj[i].v->airportNum << ":" << u.adj[i].v->name << endl;
                }
                else
                {
                    cout << u.adj[i].v->airportNum << ":" << u.adj[i].v->name << " ";
                }
                
           
                breadthQueue.push(*u.adj[i].v);
            }
        }
    }
    cout << endl;
    
}


void airportGraph::dijkstra(string airportStart, string landingAirport)
{
    
    vertex A;
    A.name = "NULL";
    vertex B;
    B.name = "NULL";
    
    vertex *finalDestination;  // Stores final destination, most optimal route
    
    for(int i = 0; i < vertices.size(); i++)
    {
        if(airportStart == vertices[i].name)
        {
            A = vertices[i];
        }
        
        if(landingAirport == vertices[i].name && landingAirport != airportStart)
        {
            B = vertices[i];
        }
    }
    
  
    if(A.name == "NULL" || B.name == "NULL")
    {
        cout << "Airport is either the Departing airport or not Present" << endl;
        return;
    }
    
    if(A.airportNum == -1)
    {
        cout << "Airports were not Generated, choose option 3. Then try again." << endl;
        return;
    }
    else if(A.airportNum != B.airportNum)
    {
        cout << "These Airports are not in the Same Flight Region" << endl;
        return;
    }
    
    vertex *departingAirport1 = NULL;
    vertex temp;
    
    int minDistance = 0;
    
        for(int j = 0; j < vertices.size(); j++)
    {
        vertices[j].visited = false;
        vertices[j].previous = NULL;
        vertices[j].distance = 0;
    }
    A.visited = false;
    B.visited = false;
    
   
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].name == airportStart)
        {
            vertices[i].visited = true;
            vertices[i].previous = NULL;
            departingAirport1 = &vertices[i];
            break;
        }
    }
    
   
    departingAirport1->visited = true;
    departingAirport1->distance = 0;
    departingAirport1->previous = NULL;
    
        int minIndex = -1;
    int minAdjIndex = -1;
    
    int distance;
    
  
    //Add starting Airport to our solved
    vector <vertex*> solved;
    solved.push_back(departingAirport1);
    
   
    while(B.visited == false)
    {
       
        minDistance = INT_MAX;
        
        //Loop through vertices in solved
        for(int k = 0; k < solved.size(); k++)
        {
            //Loop through adjacent vertices in solved
            for(int a = 0; a < solved[k]->adj.size(); a++)
            {
              
                if(solved[k]->adj[a].v->visited == false)
                {
                    //Calculate the distance to the adjacent vertex
                    distance = solved[k]->distance+solved[k]->adj[a].weight;
                    
                    //Set the minimum distance if it has not been set yet
                    
                    if(minDistance == INT_MAX)
                    {
                        minDistance = distance;
                        minIndex = k;
                        minAdjIndex = a;
                    }
                    //If the minimum distance is greater than the calculated distance
                   
                    else if(minDistance > distance)
                    {
                        minDistance = distance;
                        minIndex = k;
                        minAdjIndex = a;
                    }
                }
            }
        }
        //Assign minimum distance for adjacent
        solved[minIndex]->adj[minAdjIndex].v->distance = minDistance;
        
        solved[minIndex]->adj[minAdjIndex].v->visited = true;
        
      
        solved[minIndex]->adj[minAdjIndex].v->previous = solved[minIndex];
        
        //Set Final destination to Final adjacent, since it has nothing by it
       
        finalDestination = solved[minIndex]->adj[minAdjIndex].v;
  
        if(solved[minIndex]->adj[minAdjIndex].v->name == B.name)
            B.visited = true;
    
        solved.push_back(solved[minIndex]->adj[minAdjIndex].v);
    }
    
  
    vector<vertex*> finalPath;
    
   // output for minimum distance path
    cout << minDistance << ", ";
    
    while(finalDestination != NULL)
    {
        finalPath.push_back(finalDestination);
        finalDestination = finalDestination->previous;
    }
    
    for(int j = finalPath.size()-1; j >= 0; j--)
    {
        if(j != 0)
            cout << finalPath[j]->name << ", ";
        else
            cout << finalPath[j]->name << endl;
    }
    
    return;
}


void airportGraph::findFlightPlans(string airportStart)
{
    vertex departingAirport1;
    bool locatedAirport = false;
    
   
    for(int j = 0; j < vertices.size(); j++)
    {
        if(vertices[j].airportNum == -1)
            vertices[j].visited = false;
    }
    
 
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].name == airportStart)
        {
            locatedAirport = true;
            vertices[i].visited = true;
            vertices[i].airportNum = airportNumIndex;
            departingAirport1 = vertices[i];
            break;
        }
    }
    
    if(!locatedAirport)
    {
        cout << "" << endl;
        return;
    }
    

    departingAirport1.visited = true;
    
    queue <vertex> flightQueue;
    
  
    flightQueue.push(departingAirport1);
    
    //while the queue is not empty
    while(!flightQueue.empty())
    {
        //Set vertex u to the next element
        //Pop element off the queue
        vertex u = flightQueue.front();
        flightQueue.pop();
        
        //Loop through  adjacent vertices
        for(int a = 0; a < u.adj.size(); a++)
        {
            if(u.adj[a].v->visited == false)
            {
              
                u.adj[a].v->visited = true;
                u.adj[a].v->airportNum = airportNumIndex;
                
             
                flightQueue.push(*u.adj[a].v);
            }
        }
    }
    
    
    for(int i = 0; i < vertices.size(); i++)
    {
        
        if(vertices[i].visited == false)
        {
            airportNumIndex++;
            findFlightPlans(vertices[i].name);
        }
    }
}

void airportGraph::deleteEdge(string airportStart, string landingAirport)
{
    
    vertex *departingAirport1 = NULL;
    vertex *arrivalAirport = NULL;
    
    //Boolean which will store if our airports that correalate to start and end
    bool foundStart = false;
    bool foundEnd = false;
    
   
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].name == airportStart)
        {
            departingAirport1 = &vertices[i];
            foundStart = true;
        }
        
        if(vertices[i].name == landingAirport && airportStart != landingAirport)
        {
            arrivalAirport = &vertices[i];
            foundEnd = true;
        }
        
    }
    
  
    if(!foundEnd || !foundStart)
    {
        cout << "Airport is either the Departing airport or not Present" << endl;
        return;
    }
    
    if(departingAirport1->airportNum == -1)
    {
        cout << "Airports were not Generated, choose option 3. Then try again." << endl;
        return;
    }
    else if(departingAirport1->airportNum != arrivalAirport->airportNum && (departingAirport1->deletedNum != -10 && arrivalAirport->deletedNum != -10))
    {
        cout << "Both Airports have Different Regions/Flight Plan" << endl;
        return;
    }
    
    //Boolean to store if the vertices are adjacent
    bool adjacentVertices = false;
    
    
    for(int i = departingAirport1->adj.size()-1; i >= 0; i--)
    {
        if(departingAirport1->adj[i].v->name == landingAirport)
        {
            departingAirport1->adj.erase(departingAirport1->adj.begin()+i);
            adjacentVertices = true;
            break;
        }
    }
    

    if(!adjacentVertices)
    {
        cout << "The Airports are not Adjacent" << endl;
        return;
    }
    
    
    for(int i = arrivalAirport->adj.size()-1; i >= 0; i--)
    {
        if(arrivalAirport->adj[i].v->name == airportStart)
        {
            arrivalAirport->adj.erase(arrivalAirport->adj.begin()+i);
            break;
        }
    }
    
    
   // Redetermine flight patterns/regions
    airportNumIndex = 1;
    for(int i = 0; i < vertices.size(); i++)
        vertices[i].airportNum = -1;
    
    findFlightPlans(airportStart);
    
}



void airportGraph::deleteVertex(string airport)
{
    vertex *v = NULL;
    
    bool locatedAirport = false;
    
    for (int i = 0; i < vertices.size(); i++)
    {
        if (vertices[i].name == airport)
        {
            v = &vertices[i];
            locatedAirport = true;
            vertices[i].deletedNum = -10;
        }
    }
    
    if(!locatedAirport)
    {
        cout << "Airport could not be located" << endl;
        return;
    }
    
    if(v->airportNum == -1)
    {
        cout << "Airports were not Generated, choose option 3. Then try again." << endl;
        return;
    }
    
    
    v->adj.erase(v->adj.begin(), v->adj.end());
    
    //Delete other edges that may be connected
    for (int i = 0; i < vertices.size(); i ++)
    {
        for (int k = 0; k < vertices[i].adj.size(); k++)
        {
            if (vertices[i].adj[k].v->name == airport)
            {
                deleteEdge(vertices[i].name, vertices[i].adj[k].v->name);
            }
        }
    }
    

    for (int i = 0; i < vertices.size(); i++)
    {
        if (vertices[i].name == airport)
        {
            vertices[i].name = "";
            vertices[i].deletedNum = -10;
            vertices[i].distance = 0;
        }
    }
    
}



void airportGraph::displayEdges()
{
    
  
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].name != "")
        {
            if(vertices[i].airportNum == -1)
            {
                cout << "Airports were not Generated, choose option 3. Then try again." << endl;
                return;
            }
            cout<<vertices[i].airportNum << ":" << vertices[i].name<<"--->";
            for(int j = 0; j < vertices[i].adj.size(); j++)
            {
                cout<<vertices[i].adj[j].v->name;
                if(j != vertices[i].adj.size()-1)
                    cout << "*/*/*/*";
            }
            cout<<endl;
        }
    }
}
