//
// Created by frasse_l on 03/12/2016.
//

#ifndef ETAPE3_STATE_HPP
#define ETAPE3_STATE_HPP

#include <string>
#include <map>
#include "Edge.hpp"

class State
{
public:
    State(const std::string &);
    State(const State &);
    ~State();

    State &operator=(const State &);
    bool operator==(const State &) const;
    bool operator==(const std::string &) const;
    void setFinal(bool);
    bool isFinal() const;
    void addLink(State *, Edge &);
    std::vector<std::string> getLinked(char) const;
    const std::vector<std::string> getLinks() const;
    const std::string &getName() const;

    static State *createState();

private:
    std::map<std::string, Edge> links;
    std::string name;
    bool final;
};


#endif //ETAPE3_STATE_HPP
