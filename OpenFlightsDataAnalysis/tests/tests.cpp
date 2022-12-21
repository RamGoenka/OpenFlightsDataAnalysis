/**
 * @file tests.cpp
 * This file includes tests to check the functionality of 
 * our algorithms and data structures.
 * 
 * @author Luke G, Jimmy M
 */
#include <catch2/catch_test_macros.hpp>
#include "../src/graph.h"
#include <unistd.h>
#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <vector>
#include <string>
#include <utility>
#include <map>

TEST_CASE("Small Graph Test", "[Graph]"){
    const string airports = "../tests/data/airportTest1.csv";
    const string routes = "../tests/data/routesTest1.csv";
    Graph flights;
    flights = Graph(airports, routes);
    REQUIRE(flights.getAirports_() == 6);
    REQUIRE(flights.getRoutes_() == 8);
}
TEST_CASE("Large Graph Test", "[Graph]"){
    const string airports = "../data/airports_clean.csv";
    const string routes = "../data/routes_clean.csv";
    Graph flights;
    flights = Graph(airports, routes);
    REQUIRE(flights.getAirports_() == 7697);
    REQUIRE(flights.getRoutes_() == 64557);
}
TEST_CASE("Small BFS test", "[BFS]") {
    const string airports = "../tests/data/airportTest1.csv";
    const string routes = "../tests/data/routesTest1.csv";
    Graph flights;
    flights = Graph(airports, routes);
    flights.BFS();
    REQUIRE(flights.getAirportsVisited() == 6);
}
TEST_CASE("Small BFS Print test", "[BFS]") {
    const string airports = "../tests/data/airportTest1.csv";
    const string routes = "../tests/data/routesTest1.csv";
    Graph flights;
    flights = Graph(airports, routes);
    flights.BFS();
    flights.printGraph();
}
TEST_CASE("Large BFS test", "[BFS]") {
    const string airports = "../data/airports_clean.csv";
    const string routes = "../data/routes_clean.csv";
    Graph flights;
    flights = Graph(airports, routes);
    flights.BFS();
    REQUIRE(flights.getAirportsVisited() == 7697);
}

TEST_CASE("Dijkstra Test zero stop 1", "[Dijkstra]") {
    const string airports = "../data/airports_clean.csv";
    const string routes = "../data/routes_clean.csv";
    Graph flights;
    flights = Graph(airports, routes);
    std::pair<vector<string>,double> sol = flights.Dijkstra("Chicago O'Hare International Airport","Decatur Airport");
    REQUIRE(sol.first.size() == 2);
    REQUIRE(sol.first[0] == "Chicago O'Hare International Airport");
    REQUIRE(sol.first[1] == "Decatur Airport");
}

TEST_CASE("Dijkstra Test zero stop 2", "[Dijkstra]") {
    const string airports = "../data/airports_clean.csv";
    const string routes = "../data/routes_clean.csv";
    Graph flights;
    flights = Graph(airports, routes);
    std::pair<vector<string>,double> sol = flights.Dijkstra("Perth International Airport","Brisbane International Airport");
    REQUIRE(sol.first.size() == 2);
    REQUIRE(sol.first[0] == "Perth International Airport");
    REQUIRE(sol.first[1] == "Brisbane International Airport");
}

TEST_CASE("Dijkstra Test One Stop", "[Dijkstra]") {
    const string airports = "../data/airports_clean.csv";
    const string routes = "../data/routes_clean.csv";
    Graph flights;
    flights = Graph(airports, routes);
    std::pair<vector<string>,double> sol = flights.Dijkstra("Chicago O'Hare International Airport","Fresno Yosemite International Airport");
    REQUIRE(sol.first.size() == 3);
    REQUIRE(sol.first[0] == "Chicago O'Hare International Airport");
    REQUIRE(sol.first[1] == "Salt Lake City International Airport");
    REQUIRE(sol.first[2] == "Fresno Yosemite International Airport");
}
