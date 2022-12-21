/**
 * @file graph.cpp
 * Stores flight information in a graph data structure
 * where edges are flight routes & are weighted by the
 * distance in kilometers between the source & destination
 * airports.
 * 
 * Some inspiration taken from lab_ml nim_graph structure.
 * 
 * @author Luke G
 */
#include "graph.h"

void Graph::airportFileReader(ifstream& airports) {
    // Read the file
    string line;
    while (getline(airports, line)) {
        // Stringstream for each line in the csvfile
        stringstream ss(line);
        // Define variables for the data in columns
        string id, name, city, country, latitude, longitude;
        // Parse the stringstream for the data in columns
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, city, ',');
        getline(ss, country, ',');
        getline(ss, latitude, ',');
        getline(ss, longitude, ',');
        // Insert the data
        airports_.emplace_back(stoi(id), name, city, country, stod(latitude), stod(longitude), vector<Routes>{});
        numAirports_++;
        // Map where this airport is in the airports_ vector
        unsigned int position = airports_.size()-1;        
        id_map_.insert({id, position});
    }
}

void Graph::routeFileReader(ifstream& routes) {
    string line;
    while (getline(routes, line)) {
        // Stringstream for each line in the csvfile
        stringstream ss(line);
        // Define variables for the data in columns
        string source, destination;
        // Parse the stringstream for the data in columns
        getline(ss, source, ',');
        getline(ss, destination, ',');
        // Find position of source airport in airports_
        auto const src_position = id_map_.find(source);
        // Check if source location exists
        if (src_position == id_map_.end()) {
            continue;
        }
        int source_pos = src_position->second;
        // Find position of destination airport in airports_
        auto const dest_position = id_map_.find(destination);
        // Check if destination location exists
        if (dest_position == id_map_.end()) {
            continue;
        }
        int destination_pos = dest_position->second;
        bool alreadyExists = false;
        for (Routes r: airports_[source_pos].adjacencyList_) {
            if (r.dest_ == destination_pos) {
                r.numRoutes_++;
                alreadyExists = true;
            }
        }
        /**
         * Check if the route is already in the airports adjacency list.
        */
        if (!alreadyExists) {
            totalDistance += calculateDistance(airports_[source_pos], airports_[destination_pos]);
            airports_[source_pos].adjacencyList_.emplace_back(stoi(source), stoi(destination), source_pos, destination_pos, 1, calculateDistance(airports_[source_pos], airports_[destination_pos]));
            numRoutes_++;
        }
    }
}

float Graph::calculateDistance(const Airport& source, const Airport& destination) const {
	// Pull the longitude & latitude of destination & source airports
    float sourceLat = source.latitude_;
    float destLat = destination.latitude_;
    float sourceLon = source.longitude_;
    float destLon = destination.longitude_;
    // Earth's radius in kilometers
    float R = 6371.00;
    // Calculate the difference between the latitudes & the longitudes
	float deltaLat = (M_PI/180)*(destLat - sourceLat);
	float deltaLon = (M_PI/180)*(destLon - sourceLon);
    //haversine formula to calculate distance
	float a = sin(deltaLat / 2) * sin(deltaLat / 2) + cos((M_PI/180)*sourceLat) * cos((M_PI/180)*destLat) * sin(deltaLon / 2) * sin(deltaLon / 2);
	// Angle in radians
    float c = 2 * atan2(sqrt(a), sqrt(1 - a));
	// Distance between airports in kilometers
	float distance = R * c;
    if((destination.id_ == 3921) && (source.id_==3830)){
        cout << "Distance: " << distance << endl;
    }
	return distance;
}

Graph::Graph(string const& airports, string const& routes) {
    // Open ifstream for the airport file
    ifstream airport(airports);
    if (!airport.is_open()) {
        throw std::runtime_error{"Can't open airports file, sadge"};
    }
    // Open ifstream for the routes file
    ifstream route(routes);
    if (!route.is_open()) {
        throw std::runtime_error{"Can't open routes file, sadge"};
    }
    // Parse the airport & route files
    airportFileReader(airport);
    routeFileReader(route);
    if (numAirports_ == 0) {
        throw std::runtime_error{"No airports were found"};
    }
    if (numRoutes_ == 0) {
        throw std::runtime_error{"No routes were found"};
    }
    airport.close();
    route.close();
}

Graph::Graph() {}

vector<string> Graph::getShortLongFlight(string airportName){
    //initialize the return value
    vector<string> retVal;
    //convert name string to the airport ID
    unsigned int airID = findVertex(airportName);
    //convert the airport ID to the index in airports_
    unsigned int airportIndex = id_map_[to_string(airID)];
    //initialize variables for longest and shortest distance
    long double longest = LONG_MIN;
    long double shortest = LONG_MAX;
    string longestName;
    string shortestName;
    //step through all routes from an airport and find the shortest and longest distance
    for(Routes r : airports_[airportIndex].adjacencyList_){
        if(r.distance_ > longest){
            longest = r.distance_;
            longestName = airports_[r.src_pos_].name_ + " to " + airports_[r.dest_pos_].name_ + " in " + airports_[r.dest_pos_].city_ + ", " + airports_[r.dest_pos_].country_;
        }
        if(r.distance_ < shortest){
            shortest = r.distance_;
            shortestName = airports_[r.src_pos_].name_ + " to " + airports_[r.dest_pos_].name_+ " in " + airports_[r.dest_pos_].city_ + ", " + airports_[r.dest_pos_].country_;
        }
    }
    retVal.push_back(shortestName);
    retVal.push_back(longestName);
    return retVal;
}

string Graph::getShortestFlight(){
    Routes shortest;
    long shortestDist = LONG_MAX;
    for(Airport& a: airports_){
        for(Routes& r : a.adjacencyList_){
            if(r.distance_ < shortestDist){
                shortestDist = r.distance_;
                shortest = r;
            }
        }
    }
    return airports_[shortest.src_pos_].name_ + " to " + airports_[shortest.dest_pos_].name_;
}

string Graph::getLongestFlight(){
    Routes longest;
    long longestDist = LONG_MIN;
    for(Airport& a: airports_){
        for(Routes& r : a.adjacencyList_){
            if(r.distance_ > longestDist){
                longestDist = r.distance_;
                longest = r;
            }
        }
    }
    return airports_[longest.src_pos_].name_ + " to " + airports_[longest.dest_pos_].name_;
}
long double Graph::getAverageDist(){
    return totalDistance/numRoutes_;
}

int Graph::getAirports_(){
    return numAirports_;
}
int Graph::getRoutes_(){
    return numRoutes_;
}

Airport::Airport() : id_{}, name_{}, city_{}, country_{}, latitude_{}, longitude_{}, adjacencyList_{} {}
Airport::Airport(int id, string name, string city, string country, double lat, double lon, vector<Routes> adjacencyList) {
    id_ = id;
    name_ = name;
    city_ = city;
    country_ = country;
    latitude_ = lat;
    longitude_ = lon;
    adjacencyList_ = adjacencyList;
}

Routes::Routes() : src_{}, dest_{}, src_pos_{}, dest_pos_{}, numRoutes_{}, distance_{} {}
Routes::Routes(int src, int dest, int src_pos, int dest_pos, int numRoutes, float dist) {
    src_= src;
    dest_= dest;
    src_pos_ = src_pos;
    dest_pos_ = dest_pos;
    numRoutes_ = numRoutes;
    distance_ = dist;
}