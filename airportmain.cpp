// ---------------------------------------------------------
//  Created by Amar Patel on 7/27/17.                      -
//  Copyright © 2017 Amar Patel. All rights reserved.      -
//  --------------------------------------------------------

#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include "airportGraph.h"

using namespace std;

int main()
{
    ifstream file;
    string line;
    string *airports;
    int **airportDistance;
    
    
    int lineNumber = -1;
    
    airportGraph a;    // We create an instance
    
    file.open ("airports.txt");    //Parsing the data
    
    if(file.fail())
        cout << "File did not open." << endl;
    else
    {
        // Will go til end of file
        while(file.good()) // checking if the state of stream was good
        {                       // ran into a lot of issues with opening the file, thought this might be a fix
            getline(file, line);
            lineNumber++;
        }
        
        //Dynamic arrays
        
        airports = new string [lineNumber-1]; //1st dimension
        airportDistance = new int *[lineNumber-1]; // 2nd dimension
     
        
        for(int i = 0; i < lineNumber-1; i++)
            airportDistance[i] = new int[lineNumber-1];
        
       
        file.clear();
        file.seekg(0, ios::beg);
        
        
        getline(file, line);
        
     
        int position1 = line.find(',');
        int position2 = line.find(',', position1+1);
        
        for(int i = 0; i < lineNumber-1; i++)
        {
            
            airports[i] = line.substr(position1+1, position2-position1-1);
            position1 = position2;
            position2 = line.find(',', position2+1);
        }
        
        int index = 0;  //Keeps track of the lines we have gone through within the file
        
        while(file.good())
        {
            
            getline(file, line);
            
            int position3 = line.find(',');
            int position4 = line.find(',', position3+1);
            
            for(int i = 0; i < lineNumber-1; i++)
            {
                airportDistance[index][i] = atoi(line.substr(position3+1, position4-position3-1).c_str());
                position3 = position4;
                position4 = line.find(',', position4+1);
            }
            
            index++;
            if(index == lineNumber-1)
                break;
            
        }
    }
    
    file.close();
    
    
    for(int k = 0; k < lineNumber-1; k++)
    {
        a.addVertex(airports[k]);       // adds the airport vertices
    }
    
    for(int i = 0; i < lineNumber-1; i++)
    {
        for(int j = 0; j < lineNumber-1; j++)
        {
            
            if(airportDistance[i][j] > 0)
            {
                a.addEdge(airports[i], airports[j], airportDistance[i][j]);
             
                airportDistance[j][i] = -10;    // just in case same vertices set the distance to -10
                
            }
        }
    }
    
    
    cout << "--------------# Welcome to the Airport Connections --------------# " << endl;
    
    cout << "Given that airports are connected they will be in a similar flight pattern, this is prone to change with the various menu options" << endl;
    
    cout << "--------------# OTHER COOL OPTIONS --------------# " << endl;
    
    
    cout << "In this program one can remove airports in given fight plans" << endl << "Also can traverse and print the flight graph." << endl << endl;
    
LOOP:while(1 == 1)
{
    //Out to the console our main menu, behaves as controller for program
    cout << "*=*=*=*= MENU *=*=*=*=" << endl;
    cout << "Select an Option Below" << endl;
    cout << "1) List all Airports" << endl;
    cout << "2) Print Airports" << endl;
    cout << "3) Generate Airports" << endl;
    cout << "4) Find Shortest Airport Path" << endl;
    cout << "5) Find Shortest Airport Distance" << endl;
    cout << "6) Delete Flight Option" << endl;
    cout << "7) Delete Airport" << endl;
    cout << "8) Exit " << endl;
    
    // numInput is the option the program will run
    string numInput = "";
    getline(cin, numInput);
    
    if(numInput == "1")
    {
        a.displayEdges();
    }
    
    else if(numInput == "2")
    {
        cout << "Select a means for Traversal Below" << endl;
        cout << "1. Breadth First Traversal" << endl;
        cout << "2. Depth First Traversal (Recursive)" << endl;
        
        string airport1;
        numInput = "";
        getline(cin, numInput);
        
        if (numInput == "1")
        {
            cout << "Enter a Departing Airport:" << endl;
            getline(cin, airport1);
            numInput = "";
            a.breadthTraversal(airport1);
        }
        
        else if (numInput == "2")
        {
            cout << "Enter a Departing Airport:" << endl;
            getline(cin, airport1);
            numInput = "";
            a.dftRecursive(airport1);
        }
        
    }
    
    else if(numInput == "3")
    {
        numInput = "";
        
        a.findFlightPlans(airports[0]);
        cout << "The number in front is associated with the airports flight region. We use this information to know if they are in the same flight route. "<< endl;
    }
    
    else if(numInput == "4")
    {
        
      
        string airport1;
        string airport2;
        
        //Allows us to find shortest path between two airports
        cout << "Enter a Departing Airport:" << endl;
        getline(cin, airport1);
        cout << "Enter an Arrival Airport:" << endl;
        getline(cin, airport2);
        numInput = "";
        a.BFS(airport1, airport2);
        
    }
    
    else if(numInput == "5")
    {
        //Shortest distance using Djikstra
        string airport1;
        string airport2;
        cout << "Select and Enter a Departure Airport:" << endl;
        getline(cin, airport1);
        cout << "Select and Enter an Arrival Airport:" << endl;
        getline(cin, airport2);
        
        a.dijkstra(airport1, airport2);
    }
    
    else if(numInput == "6")
    {
        //Delete an edge
        string airport1;
        string airport2;
        cout << "Select and Enter a Departure Airport:" << endl;
        getline(cin, airport1);
        cout << "Select and Enter the Adjacent Airport:" << endl;
        getline(cin, airport2);
        numInput = "";
        
        a.deleteEdge(airport1, airport2);
    }
    
    else if(numInput == "7")
    {
        //Delete an airport
        string airport1;
        cout << "Enter the Airport to be Removed:" << endl;
        getline(cin, airport1);
        numInput = "";
        
        a.deleteVertex(airport1);
    }
    
    else if (numInput == "8")
    {
        cout << "Thanks for using our program!" << endl;
        return 0;
    }
    
    else
    {
       
        cout << "Cannot understand. Please try again enter a NUMBER" << endl;
        goto LOOP;  // if the input does not match anything we go back to the loop, until an appropriate option is selected
    }
    
}
    return 0;
}
