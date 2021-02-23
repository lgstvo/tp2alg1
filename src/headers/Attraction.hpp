#ifndef ATTRACTION
#define ATTRACTION
using namespace std;

class Attraction{
    private:
        int interestPointID;
        int attractionValue;

    public:
        Attraction();
        Attraction(int interestPointID, int attractionValue);

        int getInterestPointID();
        int getAttractionValue();
        
        void setAttractionValue(int attractionValue);
        void setInterestPointID(int interestPointID);

        ~Attraction();
};

#endif