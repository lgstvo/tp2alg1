#include "../headers/DisjointSets.hpp"
using namespace std;

DisjointSets::DisjointSets(int totalVerticies){
    this->totalVerticies = totalVerticies;

    parent = new int[totalVerticies + 1];
    rank = new int[totalVerticies + 1];
    
    for (int i = 0; i <= totalVerticies; i++){
        rank[i] = 0;
        parent[i] = i;
    }
}

int DisjointSets::findRoot(int node){
    if (node != parent[node]){
        parent[node] = findRoot(parent[node]);
    }
    return parent[node];
}

void DisjointSets::mergeByRank(int origin, int endPoint){
    origin = findRoot(origin);
    endPoint = findRoot(endPoint);
    if (rank[origin] > rank[endPoint]){
        parent[endPoint] = origin;
    }
    else{
        parent[origin] = endPoint;
    }
    if (rank[origin] == rank[endPoint]){
        rank[endPoint]++;
    }
}

DisjointSets::~DisjointSets() {}