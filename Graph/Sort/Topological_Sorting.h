#ifndef __TOPOLOGICAL__
#define __TOPOLOGICAL__

#include <iostream>
#include <list>
#include <queue>

class Graph
{
public:
    Graph();
    ~Graph();
    std::queue<int> Topological();
private:
    int n;
    std::list<int>* adj;
    std::queue<int> q;
    int* indegree;
};


#endif // __TOPOLOGICAL__