/**
 * @file graph.h
 * Stores flight information in a graph data structure
 * where edges are flight routes & are weighted by the
 * distance in kilometers between the source & destination
 * airports.
 * 
 * Some inspiration taken from lab_ml nim_graph structure.
 * 
 * @author Luke G
 */

#pragma once
#include <cmath>
#include <list>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <map>
#include <string>
#include <cstdlib>
#include <climits>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <set>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <limits>
using std::vector;
using std::string;
using std::vector;
using std::unordered_map;
using std::map;
using std::list;
using std::ifstream;
using std::getline;
using std::isnan;
using std::stringstream;
using std::stod;
using std::stoi;
using std::pair;
using std::cout, std::endl, std::cin;
using std:: priority_queue;
using std::to_string;
using std::stack;
using std::queue;
using std::abs;

/**
 * Use the routes class as our graph edges
 */
class Routes { 
    public:
        // Constructors
        Routes();
        Routes(int src, int dest, int src_pos, int dest_pos, int numRoutes, float dist);

        // Variables
        int src_; // OpenFlights ID of source
        int dest_; // OpenFlights ID of destination
        int src_pos_ = INT_MAX; // Position of airport in airports_
        int dest_pos_ = INT_MAX; // Position of airport in airports_
        int numRoutes_; // If there are duplicates how many of this route are there
        float distance_; // Edge weight
};

/**
* Airports struct to be used as the vertices in our graph.
*/
struct Airport {
    public:
        // Constructors
        Airport();
        Airport(int id, string name, string city, string country, double lat, double lon, vector<Routes> adjacencyList);

        // Variables
        int id_; //OpenFlights ID of the Airport
        string name_; //Name of the Airport
        string city_; //City in which the Airport is located
        string country_ ; //Country in which the Airport is located
        float latitude_; //Latitude of the Airport
        float longitude_; //Longitude of the Airport
        vector<Routes> adjacencyList_; //A list of routes from the Airport
};

/**
 * Graph data structure where edges are flight routes and are weighted by the
 * distance in kilometers between the source and destination
 * airports.
 */
class Graph {
    public:
        /**
         * Constructors to create a connected, weighted graph with airports and routes.
         */
        Graph(string const& airports, string const& routes);
        Graph();

        /**
         * Getter functions for private variables.
         */
        int getAirports_();
        int getRoutes_();
        int getRoutesVisited();
        int getAirportsVisited();
        long double getAverageDist();

        /**
        * Function to get the shortest and longest flights from an origin airport
        */
        vector<string> getShortLongFlight(string airportName);

        /**
         * Getters for longest and shortest flights in the dataset
        */
        string getShortestFlight();
        string getLongestFlight();
        /**
        * Function to perform a BFS traversal of the graph to find the shortest route
        */
        void BFS();

        /**
         * Function to print out in the terminal the BFS traversal of a graph.
         */
        void printGraph();

        /**
         * Function to return the node traversal order of the BFS traversal.
         */
        vector<unsigned int> getPrint();

        /**
        * Funcction to find the shortest route using the Dijkstra algorithm.
        */
        std::pair<vector<string>,double> Dijkstra(string start_airport, string dest_airport);

        /**
         * Function to find where an airport is in the airports_ vector 
         * given the name of the airport.
         */
        unsigned int findVertex(string str);

    private:

        /**
         * Contains all the airports in the dataset in a vector of Airport structs.
         */
        vector<Airport> airports_;

        /**
         * Contains an airport ID string as a key and the value is its index in airports_ vector.
         */
        unordered_map<string, unsigned int> id_map_;

        /**
         * Number of airports loaded from the dataset.
         */
        int numAirports_ = 0;

        /**
         * Number of routes loaded from the dataset.
         */
        int numRoutes_ = 0;

        /**
         * Vector including the order in which the nodes are traversed in the BFS traversal algorithm.
         */
        vector<unsigned int> print;

        /**
         * Unorder map whose keys are strings for a route edge in the form of 
         * src_pos_ + " " + dst_pos_
         * Where the two variables are the locations of the source and destination
         * airports in the airports_ vector.
         */
        unordered_map<string, bool> edgeVisited;
        
        /**
         * The number of routes or edges visited in the BFS traversal algorithm.
         */
        int routesVisited = 0;

        /**
         * The number of airports or edges visited in the BFS traversal algorithm.
         */
        int airportsVisited = 0;

        /**
        * Total combined distance of all routes in the dataset
        */
        long double totalDistance = 0.0;

        /**
         * Function to read in the airports file.
         */
        void airportFileReader(ifstream& airports);

        /**
         * Function to read in the routes file.
         */
        void routeFileReader(ifstream& routes);

        /**
         * Function to calculate the length of a route in kilometers to be used for 
         * the edge weights of routes.
         */
        float calculateDistance(const Airport& source, const Airport& destination) const;

        /**
         * Helper function to execute the BFS traversal algorithim in bfs.cpp.
         */
        void BFSsolve(unsigned int airportId, unordered_map<int, bool>& vertexVisited);
};