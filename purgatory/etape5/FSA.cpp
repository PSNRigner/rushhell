//
// Created by frasse_l on 03/12/2016.
//

#include <queue>
#include <set>
#include <iostream>
#include "FSA.hpp"

FSA::FSA() {}

FSA::~FSA() {}

void FSA::addState(State *state)
{
    this->states.push_back(state);
}

State *FSA::operator[](const std::string &name) const
{
    for (std::vector<State *>::const_iterator it = this->states.begin(); it != this->states.end(); ++it)
        if (**it == name)
            return *it;
    return NULL;
}

std::vector<std::string> FSA::closure(const std::vector<std::string> &initials) const
{
    std::set<std::string> result;
    for (int i = 0; i < initials.size(); ++i)
    {
        State *state = (*this)[initials[i]];
        if (state != NULL)
        {
            result.insert(initials[i]);
            std::vector<std::string> res = state->getLinked(-1);
            result.insert(res.begin(), res.end());
        }
    }

    return std::vector<std::string>(result.begin(), result.end());
}

std::vector<std::string> FSA::move(const std::string &current, char c) const
{
    std::set<std::string> result;
    State *state = (*this)[current];
    if (state != NULL)
    {
        std::vector<std::string> res = state->getLinked(c);
        result.insert(res.begin(), res.end());
    }

    return std::vector<std::string>(result.begin(), result.end());
}

FSA *FSA::subset(const std::string &alphabet) const
{
    std::vector<State *> dfa_states;
    std::queue<std::string> processing;
    processing.push("S0");
    bool first = true;
    while (!processing.empty())
    {
        std::string current = processing.front();
        processing.pop();
        for (int i = 0; i < alphabet.size(); ++i)
        {
            std::vector<std::string> states;
            if (first)
                states.push_back(current);
            else
                states = this->move(current, alphabet[i]);
            std::vector<std::string> cl = this->closure(states);
            for (int j = 0; j < cl.size(); ++j)
            {
                State *state = (*this)[cl[j]];
                if (state == NULL)
                    continue;
                bool found = false;
                for (int k = 0; k < dfa_states.size(); ++k)
                    if (*dfa_states[k] == *state)
                    {
                        found = true;
                        break;
                    }
                if (!found)
                {
                    dfa_states.push_back(state);
                    processing.push(cl[j]);
                }
            }
        }
        first = false;
    }
    FSA *fsa = new FSA;
    for (int i = 0; i < dfa_states.size(); ++i)
        fsa->addState(dfa_states[i]);
    return fsa;
}

const std::vector<State *> &FSA::getStates() const
{
    return this->states;
}

std::ostream &operator<<(std::ostream &out, const FSA &fsa)
{
    out << "digraph fsa {" << std::endl;
    for (std::vector<State *>::const_iterator it = fsa.getStates().begin(); it != fsa.getStates().end(); ++it)
    {
        std::vector<std::string> links = (*it)->getLinks();
        for (std::vector<std::string>::const_iterator it2 = links.begin(); it2 != links.end(); ++it2)
        {
            State *state = fsa[*it2];
            if (state != NULL && state->getLinks().empty())
                out << "    node [style=filled,color=red]" << std::endl;
            out << "    " << (*it)->getName() << " -> " << *it2 << std::endl;
        }
    }
    out << "}" << std::endl;
    return out;
}