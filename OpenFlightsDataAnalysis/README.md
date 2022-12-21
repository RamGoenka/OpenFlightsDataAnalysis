# Team FerociousFinalFour - CS225 Final Project: Flight Paths
**By Luke G, Ram G, and Jimmy M**

This repository contains the code base for our UIUC CS225 Final Project. The main goal(s) of our project is to utilize the [airports.dat](https://raw.githubusercontent.com/jpatokal/openflights/master/data/airports.dat) and [routes.dat](https://raw.githubusercontent.com/jpatokal/openflights/master/data/routes.dat) data files which we sourced from the [OpenFlights Website](https://openflights.org/data.html), to find the shortest path between any to given airports, average length of all routes, shortest and longest route originating from a specific airport. We utilize a BFS traversal, Dijkstra's algorithm and attempted to use a Force-Directed Graph Drawing algorithm in our project to accomplish these goals.

[Presentation Link](https://drive.google.com/file/d/1OdY6NemwXTfYr8PuDhhIlgw0DOYS4d8F/view?usp=share_link): https://drive.google.com/file/d/1OdY6NemwXTfYr8PuDhhIlgw0DOYS4d8F/view?usp=share_link

[Report Link](https://github.com/lukeag3/OpenFlightsDataAnalysis/blob/main/documents/results.md): https://github.com/lukeag3/OpenFlightsDataAnalysis/blob/main/documents/results.md

[airports.dat](https://raw.githubusercontent.com/jpatokal/openflights/master/data/airports.dat)

[routes.dat](https://raw.githubusercontent.com/jpatokal/openflights/master/data/routes.dat)

## Location of files
All of our major code files (i.e. the files where we implement our algorithms) reside within the ``src`` folder, and here are the specifications of each file:

- ``graph.cpp & graph.h: These files contain the definition and implementation of the Graph class which is utilized in the implementations of our chosen algorithms.``

- ``Dijkstra.cpp: This contains our implementation of the Dijkstra's algorithm, which takes in a source (origin) airport location and a destination airport as it's inputs and outputs the shortest path from the origin to the destination.``

- ``BFS.cpp: This contains our implementation of the BFS algorithm which takes in our graph data structure and executes a Breadth First Traversal on it to verify the grpah data structure is valid.``

- ``forceDraw.h & forceDraw.cpp: These contain our implementation of the Force-Directed Graph Drawing algrithm which would take in a source (origin) location and a destination location as inputs and draws all flight paths too it.``

- ``main.cpp: The main function that will be used to call our implemented algorithms.``

The ``data`` folder contains a set of files which include the raw files we downloaded from the OpenFlights website and the clean versions of the files which we generated as a result of data correction and cleaning. This folder also contains ``cleaner.py`` the python program we created to clean the OpenFlights datasets and remove any extra information provided in them.

The ``tests`` folder contains some basic test cases we composed that allow us to test our algorithm implementations. 

## Building and Running the Project
The environment used to run and test this code is the Fall 2022 CS225 Docker container. Compatibility is not guranteed outside of this container setup.

- To prepare to build the project create a ``build`` directory and while inside the build directory execute the command ``$ cmake ..``. This will create the neccesary files needed to build the project.
- To build the project execute ``$ make`` in the ``build`` directory.
- To run the project execute ``$ ./main`` in the ``build`` directory.
    - The program will request user input, the inputs are case sensitive and airport names __must appear exactly__ as they do in [/data/airports_clean.csv](https://github.com/lukeag3/OpenFlightsDataAnalysis/blob/main/data/airports_clean.csv).

## Running the Test Suite
To run the test suite first follow the instructions on Building and Runnin the Project.

- To build the test suite execute ``$ make test`` in the ``build`` directory.
- To run the test suite execute ``$ ./test`` in the ``build`` directory.

### What the Test Suite Does
- The __BFS tests__ ensure all nodes or airports in the dataset are traversed by the BFS traversal. There is versions of this test for both a small subset of the dataset and the full, cleaned, OpenFlights dataset.
- - Additionally there is a BFS test to ensure the ``printGraph()`` BFS method works with a small subset of the dataset and prints out the traversal in order on the terminal.
- The __Graph tests__ ensure the entirety of the Airports dataset is stored in the graph data structure and that the entirety of the Routes dataset is stored in the graph data structure, less repeat routes.
- The __Dijkstra tests__ ensure the output of the algorithm contains the shortest route when taking in a source airport location and a destination airport.
- The __Force-Directed Graph Drawing tests (not fully implemented)__ would ensure that the input and output nodes exist. They also make sure that the weight/force of the edge is not out of bounds (unreasonably large or too small). 
