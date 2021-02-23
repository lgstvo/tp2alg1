#ifndef DISJOINT_SETS
#define DISJOINT_SETS
#include <iostream>

class DisjointSets{
    private:
        int *parent, *rank;
        int totalVerticies;

    public:
        DisjointSets(int totalVerticies);

        int findRoot(int node);
        void mergeByRank(int origin, int endPoint);

        ~DisjointSets();
};

#endif