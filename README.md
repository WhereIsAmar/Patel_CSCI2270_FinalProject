# Patel_CSCI2270_FinalProject
Created by Amar Patel, on July 21 2017

# PROJECT NAME: 
## Airport Connections and Graphical Regions

# Purpose: 
I wanted to create a program that focused on collecting a list of various airports and
inputting their locations onto a graph. Within that graph it could show you the shortest path using several
traversals including Breadth First Search, Djikstras, and Depth First Search.

And with a "click" they would be able to map out their options and be on their way.

# Structure:

I aim to utilize a few of the data structures we were exposed to in my project.

I use vectors to hold my vertices. 

Each vertex would represent an airport of select cities.
For instance: JFK (New York), LAX (Los Angeles), LAS (Las Vegas), DEN (Denver),
SEA (Seattle), ORD (Chicago), and SFO (San Francisco).

I have a two dimensional array that is modified dynamically. The first dimension contains the airport.
The second dimension contains airport distance. I also implement the use of queues within my in Breadth First Search and other instances within my program. I aimed to use a large variety of data structures to solidy my understanding this semester.Stacks with my depth first search which I use recursively.

So the edges would be a set of distances. 

Then between those nodes they would be connected to various cities. Its important to always know your departing city and arrival city within this program. Basically the equivalent of start and end.

The program has 9 public functions which range from adding edges, add vertices, breadth first search, depth first search, dijkstra, breadth traversal, findFlightPlans (finds if its within a given distance of departing airport), and deletion of edges/airports.

All of which allow the graph to be modified and updated with the latest airport information and correct connections. 


# How to Run:
I would request this program be run within XCode I ran into a few issues using Code::Blocks. Also within XCode its important that one goes to XCode < Product < Scheme < Edit Scheme < Run < Options. Then select Use custom working directory and choose the directory that has your text file. 

If you believe terminal is your best option:

can use this:  

# System Requirements:
I have only tested this on Macintosh, however, I don't expect any issues to be run into on Linux. Windows on the other hand thats an unknown realm.

# Potential Bugs/Possible Advancements
Text file has a difficulty parsing once and a while. Every 5th compile, however, it doesn't affect the overall functionality. Just something a bit annoying to users.

Given that this project only utilizes like 10 airports. It would have been really interesting to have a large number of airports to mock reality. I think in addition to this having a customer feature to find whether they can afford a trip to an arrival airport from their departing airport would be a cool feature.


