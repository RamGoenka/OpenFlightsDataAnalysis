/**
 * @file dijkstra.cpp
 * Implements Dijkstra's algorithm to find the shortest path
 * between two airports.
 * 
 * @author Jimmy M
 */

#include "graph.h"
    
pair<vector<string>,double> Graph::Dijkstra(string start_airport, string dest_airport) {
    cout <<"From " << start_airport <<" to "<< dest_airport << endl;
    vector<string> result;

    //lambda comparator
    //min heap as a priority queue
    auto y = [](pair<unsigned int, double> a, pair<unsigned int, double> b){return a.second > b.second;}; 
    priority_queue<pair<unsigned int,double>,vector<pair<unsigned int,double>>,decltype(y)> que(y);
    //track the previous airport_id, first -> curr, second -> curr's parent
    unordered_map<int,int> prev;
    //test to see if a vertex has been visited or not, true -> visited, false -> not visited yet
    unordered_map<int, bool> visited;
    //track each airpot's distance, first -> airport_ai, second -> distance
    unordered_map<int, double> dist;
    //set all the visit to false, and set all the distance to infinitiy
    for(Airport& a: airports_) {
        visited.insert({id_map_[to_string(a.id_)], false});
        dist.insert({id_map_[to_string(a.id_)], INT_MAX});
    }
    //translate the start's and the dest's id
    unsigned int start = id_map_[to_string(findVertex(start_airport))];
    unsigned int dest = id_map_[to_string(findVertex(dest_airport))];
    //set the starting airport's distance to 0;
    dist[start] = 0;
    que.push({start, 0});
    while (!que.empty()) {
        //curr airport id;
        unsigned int curr = que.top().first;
        que.pop();
        //find all the neighbor airports of the current airport
        Airport& a = airports_[curr];
        for (Routes& r: a.adjacencyList_) {
            //tmp is the neighbor's airport
            Airport& tmp = airports_[r.dest_pos_];
            //ignore if neighbor is visited
            if(!visited[id_map_[to_string(tmp.id_)]]) {
                //this distance between curr airport and the neighboar airport
                double weight = calculateDistance(a, tmp);
                //if the weight between current and temp is less than the the neighbor's weight, aka infinity as default
                if(dist[id_map_[to_string(tmp.id_)]] > weight + dist[curr]){
                    prev.insert_or_assign(id_map_[to_string(tmp.id_)],curr);
                    que.push({id_map_[to_string(tmp.id_)], weight + dist[curr]});
                    //update the distance of the neighbor airport
                    dist[id_map_[to_string(tmp.id_)]] = weight + dist[curr];
                }
            }
        }
        //set curr to visit
        visited[curr] = true;
    }

    //Extracts shortest path from previous map
    unsigned int curr = dest;
    stack<int> stack;
    stack.push(curr);
    while(curr != start){
        stack.push(prev[curr]);
        curr = prev[curr];
    }
    curr = prev[curr];
    
    //transfer the from the airport id to airport name, then push the airport to the result vector in tranversal order
    while(!stack.empty()){
        result.push_back(airports_[stack.top()].name_);
        stack.pop();
    }
    //return a vector contains the shortest route, and the total travel distance
    return {result,dist[dest]};
}
    
//passing in an airport name, return the match airport id
unsigned int Graph::findVertex(string str) {
    for (Airport& tmp: airports_) {
        if (tmp.name_ == str) {
            return tmp.id_;
        }
    }
    return 0;
}
