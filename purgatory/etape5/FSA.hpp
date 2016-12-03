//
// Created by frasse_l on 03/12/2016.
//

#ifndef ETAPE3_FSA_HPP
#define ETAPE3_FSA_HPP


#include <iostream>
#include <vector>
#include "State.hpp"

class FSA
{
public:
    FSA();
    ~FSA();

    void addState(State *);

    State *operator[](const std::string &) const;
    const std::vector<State *> &getStates() const;

    std::vector<std::string> closure(const std::vector<std::string> &) const;
    std::vector<std::string> move(const std::string &, char) const;
    FSA *subset(const std::string &) const;

private:
    std::vector<State *> states;
};

std::ostream &operator<<(std::ostream &, const FSA &);

#endif //ETAPE3_FSA_HPP
