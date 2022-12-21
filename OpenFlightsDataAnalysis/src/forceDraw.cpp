/**
 * @file forceDraw.cpp
 * Implements a ForceDrawn graph algorithm to draw 
 * flight data on a map.
 * 
 * @author Ram G
 */
//This file is going to be used to implement our force draw algo
//A fixed input will be provided which will lead to an output of dist
#include "graph.h"
#include "forceDraw.h"
#include "../lib/cs225/PNG.h"
#include "../lib/cs225/HSLAPixel.h"
using namespace std;
using cs225::PNG;
ForceDirected::ForceDirected() {
    //constructor--nothing to do here
}

ForceDirected::ForceDirected(Graph* input_) {
    draw_ = new PNG(width_, height_);
    //this is the part where I need to get the force and the number of edges
    //not yet, need to write helper
    //get the force constant and the number of vertex in the graph_
}

ForceDirected::~ForceDirected() {
    delete pos_;
    delete draw_;
//distructor for FD algo
}

//find the displacement between any two pair of vertex (v1, v2) 
void ForceDirected::disp() {
    double hort_one; double vert_one;
    double hort_two; double vert_two;
    double disp_hort; double disp_vert;
    int factor = 4; //this is a numeric factor for the for-loop in this function
    int multiple = 1;
    //this entire logic is going to be used for all (v1, v2)
    //v1 = vertex 1
    //v2 = vertex 2
    for (int i = multiple; i < (int)(count_edge * factor); i++) {
        for (auto ii = pos_->begin(); ii != pos_->end(); ii++) {
            disp_h[ii->first] = 0.0;
            disp_v[ii->first] = 0.0;
            for (auto iii = pos_->begin(); iii != pos_->end(); iii++) {
                if (ii->first != iii->first) {
                hort_one = pos_->at(ii->first)[0];
                vert_one = pos_->at(ii->first)[1];
                hort_two = pos_->at(iii->first)[0];
                vert_two = pos_->at(iii->first)[1];
                disp_vert = hort_one - hort_two;
                disp_hort = vert_one - vert_two;
                double _distance = getDistance(disp_hort, disp_vert);
                disp_h[ii->first] += (disp_hort / _distance) * force_one(disp_hort, disp_vert);
                disp_v[ii->first] += (disp_vert / _distance) * force_one(disp_hort, disp_vert);
                } else {
                    continue;
                }
            }
        } //This loop has ended (for tracking purposes)
        
        // vector<Routes *> vect_ = graph_->getAllEdges(); //NOTE: need to implement this helper
        //this helper will allow me to get all the edges to be able to sort the ones between the src and the dest.
        // //so now we need to look for the edge,
        // //the main thing here is that when 
        // for (auto e = vect_.begin(); e != vect_.end(); ++e) {
        //     Airport * source_node = (*e)->getVertexsource();
        //     Airport * destination_node = (*e)->getVertexdestination();
        //     hort_one = pos_->at(source_node)[0];
        //     vert_one = pos_->at(source_node)[1];
        //     hort_two = pos_->at(destination_node)[0];
        //     vert_two = pos_->at(destination_node)[1];
        //     disp_hort = hort_one - hort_two;
        //     disp_vert = vert_one - vert_two;
        //     double _distance = getDistance(dx, disp_vert);
        //     disp_h[source_node] -= (disp_hort / _distance) * force_two(disp_hort, disp_vert);
        //     disp_v[source_node] -= (disp_vert / _distance) * force_two(disp_hort, disp_vert);
        //     disp_h[destination_node] += (disp_hort / _distance) * force_two(disp_hort, disp_vert);
        //     disp_v[destination_node] += (disp_vert / _distance) * force_two(disp_hort, disp_vert);
        // } //Edge logic ends here: this is just to keep track

        for (auto i_vertex = pos_->begin(); i_vertex != pos_->end(); i_vertex++) {
            double value_disp = getDistance(disp_h[i_vertex->first], disp_v[i_vertex->first]);
            pos_->at(i_vertex->first)[0] += disp_h[i_vertex->first] * inverseTime(i) / value_disp;
            pos_->at(i_vertex->first)[1] += disp_v[i_vertex->first] * inverseTime(i) / value_disp;

            pos_->at(i_vertex->first)[0] = fmin(width_ - gap_, fmax(gap_, pos_->at(i_vertex->first)[0]));
            pos_->at(i_vertex->first)[1] = fmin(height_ - gap_, fmax(gap_, pos_->at(i_vertex->first)[1]));
        }
    }
} //This function has ended here

float ForceDirected::getDistance(unsigned int x, unsigned int y){
    return -1.0;
}
double ForceDirected::inverseTime(int i){
    return -1.0;
}
double force_two(unsigned int x, unsigned int y){
    return -1.0;
}
vector<Routes> ForceDirected::getAllEdges(){
    return vector<Routes>();
}
