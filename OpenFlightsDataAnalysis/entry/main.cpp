/**
* @file main.cpp
* Calls all the functions neccesary for the analysis
* of the OpenFlights flight data. Please note data
* has been preprocessed and cleaned by cleaner.py in
* the data directory.
* 
* @author Luke G, Ram G, Jimmy M
*/
#include "../src/graph.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using std::string;
using std::ifstream;
 
int main() {
    /**
     * Set filepaths to datasets
    */
    const string airports = "../data/airports_clean.csv";
    const string routes = "../data/routes_clean.csv";
    /**
     * Parse the data into graph data structure
    */
    cout << std::setfill(' ') << std::setw(20) << std::setiosflags(std::ios::left) << "\033[1;32mCalling Graph with airports and routes\033[0m" << endl;
    Graph flights;
    flights = Graph(airports, routes);
    cout << "Num Airports Parsed: "<< flights.getAirports_() << endl;
    cout << "Num Routes Parsed: "<< flights.getRoutes_() << endl;
    cout << "Average Route Length: " << flights.getAverageDist() << " km";
    cout << endl;
    cout << endl;
    cout << std::setfill(' ') << std::setw(20) << std::setiosflags(std::ios::left) << "\033[1;32mGet Longest and Shortest Routes in Dataset\033[0m" << endl;
    
    cout << "Longest Route: "<< flights.getLongestFlight() << endl;
    cout << "Shortest Route: "<< flights.getShortestFlight() << endl;  
    cout << endl;
    /**
     * Call the BFS traversal on the graph data structure to verify
     * it is a valid graph and all Airports are visited
     */  
    cout << std::setfill(' ') << std::setw(20) << std::setiosflags(std::ios::left) << "\033[1;32mCalling BFS traversal on Graph\033[0m" << endl;
    flights.BFS();
    /**
     * Ask the user if they want to graphically display how the graph is
     * traversed by the BFS
    */
    string answer;
    cout << std::setfill(' ') << std::setw(20) << std::setiosflags(std::ios::left) << "\033[1;31mDo you want to print the BFS Traversal Graph (Y/N) (Note for large datasets this is overwhelming)?\033[0m" << std::endl;
    getline(cin, answer);
    if(answer == "Y" || answer == "y"){
       flights.printGraph();
    }
    else if (!(answer == "N" || answer == "n")){
        cout << "Invalid input" << endl;
    }
    
    cout << endl;
    cout << std::setfill(' ') << std::setw(20) << std::setiosflags(std::ios::left) << "\033[1;32mMin and Max Flight Distance from an Airport\033[0m" << endl;
    cout << "Enter airport to get shortest and longest flight from. (Ex. Chicago O'Hare International Airport) ";
    string temp;
    getline(cin, temp);
    vector<string> shortLong = flights.getShortLongFlight(temp);
    cout << "Shortest Flight: " << shortLong[0] << endl;
    cout << "Longest Flight: " << shortLong[1] << endl;
    cout << endl;
    /**
     * Call the Dijkstra algorithm to determine the shortest path between
     * two airports.
    */
    cout << std::setfill(' ') << std::setw(20) << std::setiosflags(std::ios::left) << "\033[1;32mStarting Dijkstra Shortest Path Algorithm\033[0m" << endl;
    cout << "Enter origin airport for Dijkstras shortest path. (Ex. Chicago O'Hare International Airport) ";
    string dijOrigin;
    getline(cin, dijOrigin);
    cout << endl;
    cout << "Enter origin airport for Dijkstras shortest path. (Ex. Fresno Yosemite International Airport) ";
    string dijDest;
    getline(cin, dijDest);
    std::pair<vector<string>,double> sol = flights.Dijkstra(dijOrigin, dijDest);
    cout << "The total stops: " << sol.first.size() - 2 << endl;
    cout << "The shortest route: ";
    unsigned int count = 0;
    for (string i: sol.first) {
        cout<<i;
        if (count != sol.first.size() - 1) {
            cout <<" -> ";
        }
        count++;
    }
    cout << '\n';
    cout << "Total travel distance: " << sol.second << endl;
    return 0;
}
