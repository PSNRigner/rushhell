//
// Created by frasse_l on 03/12/2016.
//

#ifndef ETAPE3_STATE_HPP
#define ETAPE3_STATE_HPP

#include <string>
#include <map>
#include "Edge.hpp"
#include "Function.hpp"

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
    const std::map<std::string, Edge> getLinks() const;
    const std::string &getName() const;

    void setFunctor(Function<void (const std::string &)> *);
    Function<void (const std::string &)> *getFunctor() const;

    static State *createState();

private:
    Function<void (const std::string &)> *functor;
    std::map<std::string, Edge> links;
    std::string name;
    bool final;
};


#endif //ETAPE3_STATE_HPP
