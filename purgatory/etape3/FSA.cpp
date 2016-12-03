//
// Created by frasse_l on 03/12/2016.
//

#include "FSA.hpp"

FSA::FSA() {}

FSA::~FSA() {}

void FSA::addState(State *state)
{
    this->states.push_back(state);
}

const std::vector<State *>& FSA::getStates() const
{
    return this->states;
}

State *FSA::operator[](const std::string &name) const
{
    for (std::vector<State *>::const_iterator it = this->states.begin(); it != this->states.end(); ++it)
        if (**it == name)
            return *it;
    return NULL;
}
