# Patel_CSCI2270_FinalProject
Created by Amar Patel, on July 21 2017

### Proposal:
Phase 1 Final Project:


# PROJECT NAME: 
## Random Flight Generator

# Purpose: 
So recently, I attempted to simply call Denver International Airport
with the intention of booking a flight that night. I was hoping I could just go
somewhere that night randomly for the cheapest price. Multiple airlines failed
to provide me with any information on how to do this. So, I tried Google Flights,
but not really a platform designed for spontaneity that many young people have.

I want create a program that focuses on collecting a list of various airports and
inputting their departing flights and a user would input the current time and get a
list of flights and it would choose the most optimal flight for that user.

And with a "click" they would be able to book a flight and be on their way.

Currently, in early stages of development, however, having hotel amenities available
in that city that fit their budget would be a cool addition.

# Structure:

I aim to utilize a few of the data structures we were exposed to in my project.
The data types would be a linked lists, a unweighted graph, and potentially trees in the path
of adjacent nodes.

Each vertex would represent an airport of select cities.
For instance: JFK (New York), LAX (Los Angeles), LAS (Las Vegas), DEN (Denver),
SEA (Seattle), ORD (Chicago), and SFO (San Francisco).

So the edges would be what is connected the nodes. Thats where the trees would be.
The tree would contain options for pricing and if it was within your budget it would go through and pull
the flight thats the best for your time/budget.

In theory longer the flight and not non-stop probably costs more.
Cost will always be on the right side of the subtree.

In theory we would not need to worry about utilizing a Dijkstra traversal as we are not concerned
with distance.

Then between those nodes they would be connected to various cities
So each city if connected to another city that would be considered an outgoing flight.

![Alt text]( "Optional Title")


# Alternative Method:

Using a hash table that has a size of 15 for instance. Each airport is the key and
within it I can store the values of the flight details and pricing if I want.

Traverse through each of the values until I find a match.

# Chaining:

If I run into an issue where elements hash so a collision

I can fix it using chaining and implement a linked list to the same slot.

// Some dictionary operations
// Chained-Hash-Insert
// Chained-Hash-Search
// Chained-Hash-Delete

# Open Addressing:
I think I will be implementing an open addressing method, but not entirely set on that
since I want have each table  contain an dynamic set or nil
