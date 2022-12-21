/**
 * @file bfs.cpp
 * Implements a breadth first traversal on our graph
 * data structure. The Traversal order can be printed
 * and accessed by outside functions.
 * 
 * Some inspiration taken from mp_traversal BFS traversal
 * @author Luke G
 */

#include "graph.h"

void Graph::BFS() {
  unordered_map<int, bool> vertexVisited;
  for (Airport& a: airports_) {
    vertexVisited.insert({id_map_[to_string(a.id_)], false});
    for (Routes r : a.adjacencyList_) {
      edgeVisited[(to_string(r.src_pos_) + " " + to_string(r.dest_pos_))] = false;
    }
  }
  for (Airport& a: airports_) {
    if (!vertexVisited[id_map_[to_string(a.id_)]]) {
      BFSsolve(id_map_[to_string(a.id_)], vertexVisited);
    }
  }
  for(auto i = edgeVisited.begin(); i != edgeVisited.end(); i++){
    if(i->second){
      routesVisited++;
    }
  }
  for(auto i = vertexVisited.begin(); i != vertexVisited.end(); i++){
    if(i->second){
      airportsVisited++;
    }
  }
  cout << "Airports explored by BFS: " << airportsVisited << endl;
  cout << "Routes explored by BFS: " << routesVisited << endl;
}

void Graph::BFSsolve(unsigned int airportId, unordered_map<int, bool>& vertexVisited) {
  queue<unsigned int> que;
  vertexVisited[airportId] = true;
  que.push(airportId);
  // Break when the queue is empty
  while (!que.empty()) {
      unsigned int& node = que.front();
      print.push_back(node);
      que.pop();
      // Find the neighbors of the queue
      Airport& a = airports_[node];
      for (Routes& r: a.adjacencyList_) {
        // Create string to index into the map of edges
        string routeName = to_string(r.src_pos_) + " " + to_string(r.dest_pos_);
          if (!vertexVisited[r.dest_pos_]) {
              // Mark visited
              vertexVisited[r.dest_pos_] = true;
              edgeVisited[routeName] = true;
              que.push(r.dest_pos_);
          }
      }
  }
}

// Print the graph
void Graph::printGraph() {
  cout << "\n Exploration order of BFS" << endl;
  for (unsigned int i = 0; i < print.size(); i ++) {
    cout << "\n Vertex: " << airports_[print[i]].name_;
    for (Routes r : airports_[print[i]].adjacencyList_) {
      string routeName = to_string(r.src_pos_) + " " + to_string(r.dest_pos_);
      if(edgeVisited[routeName] == true){
        string rname = " -> " + airports_[r.dest_pos_].name_;
        cout << rname;
      }
    }
    printf("\n");
  }
}

// Return the vector that has BFS order
vector<unsigned int> Graph::getPrint() {
  return print;
}

int Graph::getRoutesVisited(){
  return routesVisited;
}

int Graph::getAirportsVisited(){
  return airportsVisited;
}