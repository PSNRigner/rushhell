//
// Created by frasse_l on 03/12/2016.
//

#ifndef ETAPE3_EDGE_HPP
#define ETAPE3_EDGE_HPP

class Edge
{
public:
    Edge(const char &);
    Edge(const Edge &);
    ~Edge();
    Edge &operator=(const Edge &);
    Edge &operator=(const char &);
};

#endif //ETAPE3_EDGE_HPP
