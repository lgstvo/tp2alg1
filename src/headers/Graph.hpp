#ifndef GRAPH
#define GRAPH
#include <vector>
#include <algorithm>
#include "../headers/Attraction.hpp"
#include "../headers/Edge.hpp"
using namespace std;

class Graph{
    private:
        int edgesListSize, mstCost, mstAtractiviness;
        vector<int> interestPointsIDs;
        vector<Attraction> edgesList;
        vector<Edge> edges;
        vector<Edge> mst;

    public:
        Graph(vector<Attraction> interestPointsList);

        int getCost();
        int getAtractiviness();
        void addEdge(int cost, Attraction origin, Attraction endPoint);
        
        vector<Edge> formMST();
        vector<int> getInterestPointsIDs();

        ~Graph();
};
#endif