#include "../headers/Attraction.hpp"
using namespace std;

Attraction::Attraction(){
    this->interestPointID = -1;
    this->attractionValue = 0;
}

Attraction::Attraction(int interestPointID, int attractionValue){
    this->interestPointID = interestPointID;
    this->attractionValue = attractionValue;
}


Attraction::~Attraction() {}

void Attraction::setInterestPointID(int interestPointID){
    this->interestPointID = interestPointID;
}

void Attraction::setAttractionValue(int attractionValue){
    this->attractionValue = attractionValue;
}

int Attraction::getInterestPointID(){
    return this->interestPointID;
}

int Attraction::getAttractionValue(){
    return this->attractionValue;
}