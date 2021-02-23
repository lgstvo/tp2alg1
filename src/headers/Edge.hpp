#ifndef EDGE
#define EDGE
#include "Attraction.hpp"
using namespace std;
class Edge{
    private:
        Attraction origin;
        Attraction endPoint;

        int cost;
        int atractiviness;

    public:
        Edge(int cost, Attraction origin, Attraction endPoint);
        
        int getAtractiviness();
        int getCost();
        
        Attraction getOrigin();
        Attraction getEndPoint();

        ~Edge();
};

#endif