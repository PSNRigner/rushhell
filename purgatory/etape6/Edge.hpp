//
// Created by frasse_l on 03/12/2016.
//

#ifndef ETAPE3_EDGE_HPP
#define ETAPE3_EDGE_HPP

#include <iostream>

class Edge
{
public:
    Edge(const char &);
    Edge(const Edge &);
    ~Edge();

    Edge &operator=(const Edge &);
    Edge &operator=(const char &);

    bool operator()(char) const;

    bool isLambda() const;

    char getContent() const;

    static Edge LAMBDA;

private:
    char c;
};

std::ostream &operator<<(std::ostream &, const Edge &);

#endif //ETAPE3_EDGE_HPP
