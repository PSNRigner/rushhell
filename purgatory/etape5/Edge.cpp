//
// Created by frasse_l on 03/12/2016.
//

#include "Edge.hpp"

Edge::Edge(const char &c) : c(c){}

Edge::Edge(const Edge &other) : c(other.c){}

Edge::~Edge() {}

Edge& Edge::operator=(const char &c)
{
    this->c = c;
    return *this;
}

Edge& Edge::operator=(const Edge &other)
{
    this->c = other.c;
    return *this;
}

bool Edge::operator()(char c) const
{
    return this->c == c;
}

bool Edge::isLambda() const
{
    return this->c == -1;
}