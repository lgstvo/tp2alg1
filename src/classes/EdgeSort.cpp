#include "../headers/EdgeSort.hpp"
using namespace std;

vector<Edge> EdgeSort::sortEdges(vector<Edge> edges){
    int vecsize = edges.size();

    for (int j = 0; j < vecsize - 1; ++j) {

        int min = j;
        for (int i = j+1; i < vecsize; ++i) {
            if ((edges.at(i).getCost() < edges.at(min).getCost()) || 
                        ((edges.at(i).getCost() == edges.at(min).getCost()) && 
                        edges.at(i).getAtractiviness() > edges.at(min).getAtractiviness()))  {
                min = i;
            }

        }
        if (min != j)
            swap(edges.at(j), edges.at(min));
    }

    return edges;
}

void swap(Edge &a, Edge &b){
    Edge *tempEdge;
    tempEdge = &a;
    
    a = b;
    b = *tempEdge;
}