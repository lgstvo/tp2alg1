#include "../headers/Graph.hpp"
#include "../headers/DisjointSets.hpp"
#include "../headers/EdgeSort.hpp"
using namespace std;

Graph::Graph(vector<Attraction> interestPointsList){
    mstAtractiviness = 0;
    mstCost = 0;
    this->edgesList = interestPointsList;
    this->edgesListSize = edgesList.size();
    this->interestPointsIDs = vector<int>(edgesListSize);
}

vector<int> Graph::getInterestPointsIDs(){
    return this->interestPointsIDs;
}

int Graph::getCost(){
    return this->mstCost;
}

int Graph::getAtractiviness(){
    return this->mstAtractiviness;
}

void Graph::addEdge(int cost, Attraction origin, Attraction endPoint){
    edges.push_back(Edge(cost, origin, endPoint));
}

vector<Edge> Graph::formMST(){
    EdgeSort sort = EdgeSort();
    
    edges = sort.sortEdges(edges);

    DisjointSets disjointSets = DisjointSets(edgesListSize);
    for (auto it = edges.begin(); it != edges.end(); it++)
    {
        int originSet = disjointSets.findRoot(it->getOrigin().getInterestPointID());
        int endPointSet = disjointSets.findRoot(it->getEndPoint().getInterestPointID());
        if (originSet != endPointSet)
        {
            mst.push_back(*it);
            mstCost += it->getCost();
            mstAtractiviness += it->getAtractiviness();
            interestPointsIDs.at(it->getOrigin().getInterestPointID())++;
            interestPointsIDs.at(it->getEndPoint().getInterestPointID())++;
            disjointSets.mergeByRank(originSet, endPointSet);
        }
    }

    return mst;
}

Graph::~Graph() {}