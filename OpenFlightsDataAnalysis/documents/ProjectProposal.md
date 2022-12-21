# Project Proposal

## Leading Question
The dataset we’ll be using for our project is the OpenFlights dataset. While we’re interested in learning more about the different statistics provided by the dataset, a few specific questions & data we hope to gather more information include: 

- Finding the average distance between all flight paths illustrated in the data set.
- Finding shortest & longest distance for flights that originate from Chicago. 
- Creating a visualization on the world map listing all the flights (and highlighting paths we find from our second goal).

While these goals might seem vague, they serve as a big picture for the project. Our goal is to use the dataset to learn more about the various statistics, & the 3 points listed above interest us the most & thus we decided to move forward with investigating more about them. We plan to implement BFS traversal to find average distances between all flight paths and Dijkstra’s Algorithm to find the shortest and longest path distance for flights from Chicago. We also plan to use Force Draw Graph Algorithm to project all paths (highlighting the shorts and longest paths) on a world map. 

## Dataset Acquisition
The dataset was acquired through the OpenFlights.org website. We sourced through the various datasets present at the website & downloaded one that contained information pertaining to route & route lengths & airport codes & information. We’ve stored this data in a .dat file in the GitHub repository & will be developing an algorithm to parse through & sort the data to make it better usable in order for us to generate information that allows us to answer our leading questions. 

## Data Format
The dataset we’re using is “routes” & “airports” from OpenFlight.org. The files we’ll be using are present in the .dat format’. The size of the routes file is 2.4MB, & the size of the airports file is 1.1MB. We plan to use all the data for the routes file, & only the airport’s name, longitude & latitude for the airports file. Here are the links to the datasets we will be using:

airports.dat: https://raw.githubusercontent.com/jpatokal/openflights/master/data/airports.dat
routes.dat: https://raw.githubusercontent.com/jpatokal/openflights/master/data/routes.dat

Please note that these datasets are what we'll be using throughout the duration of the project. These are in the raw form & not in the correct & cleaned format as we have yet to finish cleaning our data. 

## Data Correction
One of the ways we hope to check for correction & completeness of data present in the dataset is to create a parsing method that prints out the data in an ordered fashion such that each entry is matched with its corresponding data. We also hope to look for empty data entries & eliminate them from our implementation in order to ensure the data is complete & functional for usage. The implementation & nature of these algorithms and methods is discussed in the Data Storage section of the write up. As a brief overview, we'll be storing the data as a vector of strings where each row is a string (each row contains a different type of information pertaining to each airport such as IATA code, coordinates, origin, and other information as presented in the data set). We'll be parsing through the lenghts of the rows to remove any empty or invalid entires and then storing the airport data as an adjaceny list where there will be a list for each airport containing the following information: longitude, latitude, IATA code and all other airports that have flights to and from the given airport. We will then implement BFS & Dijkstra's on the adjacency list. As aforementioned, BFS will be used for finding the average path length between all coordinates (i.e. between all flight paths) given in the dataset and Dijkstra's will be used to find the shortest and longest flight paths to and from Chicago. We will then combine this information and project it onto a world map using Force Draw Algorithm.

## Data Storage
We will first store the data as a vector of strings and sort through the length of the rows as each string is a row containing information pertaining to the airport(s). We will then store all of this information (once corrected with all empty entries eliminated) as an adjacency list where the list will contain airport information (as listed in the dataset, such as coordinates, IATA code and other information) and distances to all destination airports. Through our implementation we hope to maintain the optimal runtime of O(n^2) for the algorithm. We hope to use Dijkstra's algorithm as a method of parsing our data (stored as adjacency lists) in order to parse through all the points & determine the shortest and longest fligth paths. (For storing we'll be using a specific method which we'll discuss next in this section). For data storage, we'll be storing our file as a vector of strings initially where each row will be a string containing some form of information about the airport(s). We then plan to parse the lenghts of the rows to eliminate any empty and invalid entires and to create adjancy lists that stores the airport informations and the informations of all other airports connected to it. Using BFS, we will then find the average distance between all coordinates (Longitude & latitude) in our data. While we understand that there are going to be empty rows & columns, (Which are linked in data acquisition) we hope to parse through the length of the rows & look for any rows with missing values & replace those missing values (Each row will be stored as a string). We hope to keep the total Big-O runtime for all of these components O(n^2) or better. 

## Algorithm
The 3 algorithms we plan to use are BFS, Dijkstra's algorithm, & Graphic output of a graph, which in our case will be Force-Directed Graph drawing algorithm. We plan to utilize a BFS traversal using Dijkstra’s Algorithm to find the shortest path between a given (Most probably Chicago) airport & all other airports in a graph. In addition we’ll utilize a graphic output of graphs to project onto a map based on data. For this we plan to use the Force-Directed Graph drawing algorithms, which are considered to have an O(n ^ 3) run time. We hope to implement this algorithm to map our flight paths on the world map, which is 1 of our project goals. This will most likely happen using the longitude & latitude values of the airports in the dataset & plotting points at those specific values & then constructing flight paths from those points between the origin airport and the destination airport. While this runtime might be on the higher end, it'll allow us to make a graphical output of the flight paths & will also fulfill the requirement to use an algorithm not covered in class.

## Timeline
Data Acquisition: Complete by 11/4
Data Processing: Complete by 11/11
Algorithm 1: Complete by 11/14 (For midpoint check in)
Algorithm 2: Complete by 11/25
Finished Product: Complete by 12/1
README: Complete by 12/4
Report: Complete by 12/7
Presentation: Complete by 12/7