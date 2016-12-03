//
// Created by frasse_l on 03/12/2016.
//

#ifndef ETAPE3_FSA_HPP
#define ETAPE3_FSA_HPP


#include <vector>
#include "State.hpp"

class FSA
{
public:
    FSA();
    ~FSA();

    void addState(State *);
    const std::vector<State *> &getStates() const;

    State *operator[](const std::string &) const;

private:
    std::vector<State *> states;
};


#endif //ETAPE3_FSA_HPP
