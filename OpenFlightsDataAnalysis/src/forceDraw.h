/**
 * @file forceDraw.h
 * Implements a ForceDrawn graph algorithm to draw 
 * flight data on a map.
 * 
 * @author Ram G
 */
#pragma once
#include <cmath>
#include <iostream>
#include "graph.h"
#include "../lib/cs225/PNG.h"
#include "../lib/cs225/HSLAPixel.h"
#include "../lib/cs225/RGB_HSL.h"
using namespace std;
class ForceDirected {
    public:
        ForceDirected();
        ForceDirected(Graph *);
        ~ForceDirected();
        double force_one(double, double);
        double fource_two(double, double);
        void disp();
        cs225::PNG * d_draw();
    
    private:
        Graph * graph_;
        cs225::PNG * draw_;
        map <Airport *, vector<double>> * pos_;
        map <Airport *, double> disp_h; //hortizontal displacement 
        map <Airport *, double> disp_v; //verticle displacement

        int count_edge; //number of edges
        int count_vertex; //number of vertex
        int force_algo_f; //force directed graphs use forces to develope edges and connections
        //this is going to be used to calculate the force constant as used by the algo

        //these are going to set the height and width of the visualization graph
        int width_ = 3500;
        int height_ = 3500;
        int gap_ = 300;

        double distance(double, double); //getter for distance
        double slope(int, int, double); //getter for the slope, the logic is to find the slope between two points
        //or perhaps use a^2 + b^2 = c^2
        float getDistance(unsigned int x, unsigned int y);
        vector<Routes> getAllEdges();
        double inverseTime(int i);

};
