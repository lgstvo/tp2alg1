#include "../headers/Edge.hpp"
using namespace std;

Edge::Edge(int cost, Attraction origin, Attraction endPoint){
    this->origin = origin;
    this->endPoint = endPoint;
    this->cost = cost;
    this->atractiviness = this->getAtractiviness();
}

int Edge::getAtractiviness(){
    return endPoint.getAttractionValue() + origin.getAttractionValue();
}

int Edge::getCost(){
    return this->cost;
}

Attraction Edge::getOrigin(){
    return this->origin;
}

Attraction Edge::getEndPoint(){
    return this->endPoint;
}

Edge::~Edge() {}