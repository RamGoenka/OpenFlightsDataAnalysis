# Project Results
Our project results are not quite what we had expected. We successly, fully, implemented 2 out of our 3 algorithms. The two we completed being Dijkstra's shortest path algorithm and the Breadth First Search Traversal algorithm. However, we were still able to address our leading question and project statement. Chiefly through our greater understanding of the ways in which we can manipulate large flight data datasets. We were able to leverage python to quickly clean and format our data with the ``cleaner.py`` file in the ``/data/`` directory. We also used our knowledge of BFS and Dikstra's algorihm from class to efficiently implement them according to their theoretical runtimes.
## Addressing our leading question
### What we were able to complete
1. Find the average distance travelled on all flight paths in the data set with the ``getAverageDist`` function in ``src/graph.cpp``
    ![alt text](https://github.com/lukeag3/OpenFlightsDataAnalysis/blob/main/documents/Avg_route_length.png?raw=true)
2. Find the shortest and longest flight path from O'Hare (or any) airport with the ``getShortLongFlight`` function in ``src/graph.cpp``
    ![alt text](https://github.com/lukeag3/OpenFlightsDataAnalysis/blob/main/documents/Min_max_flight.png?raw=true)
3. Utilize Dijstrkas Algorithim to find the shortest path between Chicago O'Hare International to Fresno Yosemite International (or any pair of airports) with the ``Dijkstra`` function in ``src/dijkstra.cpp``
    ![alt text](https://github.com/lukeag3/OpenFlightsDataAnalysis/blob/main/documents/dijkstra_result.png?raw=true)

### We were not able to complete
1. Create a visualization on the world map listing all the flights.

__Why we could not complete this portion__
- One of the major roadblocks to completing this project was our orginal fourth group member. He did not assist with the code or documentation for this project and repeatedly caused large merge conflicts from adjusting spacing, capitalization, converting ``and`` to ``&``.
- Another issue was that the algorithm was fairly new for us and understanding and being able to compose it was a challenge as we were functioning with one less group memeber as he did not contribute to any of the code and thus each member had to try and now code one algorithm, a lot of which now had to be done individually, and thus working with a very new algorithm was challenging. 

## Graph Data Structure
Our graph data structure takes in the ``airports_clean.csv`` and ``routes_clean.csv`` files in ``/data/`` directory and parses them into a vector of Airports as vertices and an adjacency list of routes connected to each Airport. The data structure also determines the distance between each Airport along the routes and the average distance.
### How we confirmed its function
- Tested that all airports and routes are stored in the graph.
    - ``Small Graph Test`` and ``Large Graph Test`` in ``/tests/tests.cpp`` confirms this is true by checking that the number of airports and routes in the data structure are the same as the known values of Airports and the known number of __Non-repeat__ routes.
## Breadth First Search
Our breadth first search traversal was used to ensure that our graph data structure is a valid data structure. The algorithm begins by queueing a starting vertex (Airport) and then popping it, marking it visited and then queues all of its unvisited neighbors. The process repeats until all nodes are visited. 
### How we confirmed its function
- Tested that all vertices (Airports) are visited.
    - ``Small BFS test`` and ``Large BFS test`` in ``/tests/tests.cpp`` confirms this is true by showing that the number of vertices visited is equal to the number of airports in the dataset.
- Tested that the traversal occurs according to the BFS algorithm
    - ``Small BFS print test`` in ``/tests/tests.cpp`` confirms this by printing the order in which the traversal occurred. Visually it can be seen that the traversal is correct if it appears as such: ![alt text](https://github.com/lukeag3/OpenFlightsDataAnalysis/blob/main/documents/BFS_proper_print_order.png?raw=true)
## Dijkstra algoithm
Our dijkstra algorithm is to find the shortest path between two airports. The main data structure is min-heap priority que. The algorithm begins by queueing a starting vertex (Airport) and then popping it. Find all the unvisited neighbors of the current vertex and compare their distance, if the weight of that neighbor is less than the stored distance, update the new distance. The process repeats until all nodes are visited. Then extracts the result path from 'previous' map.
### How we confirmed its function.
- Tested finding the shortest route
    - ``Dijkstra Test zero stop 1 test`` and ``Dijkstra Test zero stop 2 test`` in ``/tests/tests.cpp`` confirms this is true by showing that the size of the returned vector, and the order of the airports. 
    - ``Dijkstra Test One Stop`` in ``/tests/tests.cpp`` confirms dijsktras works properly by showing that the shortest path from O'Hare to Fresno is through Salt Lake City. Which is the the correct shortest path. The below demonstrates the test requirements.
    ![alt text](https://github.com/lukeag3/OpenFlightsDataAnalysis/blob/main/documents/dijkstra_test.png?raw=true)

## Force-Drawn Graph Algorithm
- While we were unable to fully compose and run this algorithm, we were able to get one of the major functions written for it which served the purpose of finding edge force as well as displacement between any two points which would then be utilized by our ``d_draw()`` function. The main implementation missing from the force directed graph drawing algorithm was to implement the ``d_draw()`` function and one main helper method which would allow us to get all edges and draw them.
