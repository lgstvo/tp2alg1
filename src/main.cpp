#include <iostream>
#include "./headers/Graph.hpp"

vector<Attraction> fillInterestPoints(int , int*);
void addEdges2Graph(int, vector<Attraction>, Graph*);
void outputResult(int, Graph, vector<Edge>);

int main()
{
    int nInterestPoints, nPaths;
    std::cin >> nInterestPoints >> nPaths;
    int attractionValues[nInterestPoints];

    vector<Attraction> interestPoints = fillInterestPoints(nInterestPoints, attractionValues);

    Graph graph = Graph(interestPoints);

    addEdges2Graph(nPaths, interestPoints, &graph);

    vector<Edge> mst = graph.formMST();
    
    outputResult(nInterestPoints, graph, mst);

    return 0;
}

vector<Attraction> fillInterestPoints(int nInterestPoints, int *attractionValues){

    vector<Attraction> interestPoints;

    for (int i = 0; i < nInterestPoints; i++){
        std::cin >> attractionValues[i];
        interestPoints.push_back(Attraction(i, attractionValues[i]));
    }

    return interestPoints;
}

void addEdges2Graph(int nPaths, vector<Attraction> interestPoints, Graph *graph){
    for (int i = 0; i < nPaths; i++){
        int cost, origin, endPoint;
        std::cin >> origin >> endPoint >> cost;
        graph->addEdge(cost, interestPoints[origin], interestPoints[endPoint]);
    }
}

void outputResult(int nInterestPoints, Graph graph, vector<Edge> mst){

    std::cout << graph.getCost() << " " << graph.getAtractiviness() << std::endl;
    vector<int> interestPointsIDs = graph.getInterestPointsIDs();

    std::cout << interestPointsIDs.at(0);
    for (int i = 1; i < nInterestPoints; i++){
        std::cout << " ";
        std::cout << interestPointsIDs.at(i);
    }
    std::cout << std::endl;

    for (auto it = mst.begin(); it != mst.end(); it++){
        std::cout << it->getOrigin().getInterestPointID() << " " << it->getEndPoint().getInterestPointID() << " " << it->getCost() << std::endl;
    }

}