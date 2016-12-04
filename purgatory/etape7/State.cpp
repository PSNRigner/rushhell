//
// Created by frasse_l on 03/12/2016.
//

#include <sstream>
#include <vector>
#include <iostream>
#include "State.hpp"

State::State(const std::string &name) : name(name), final(false)
{
}

State::State(const State &other) : links(other.links), name(other.name), final(other.final)
{
}

State::~State() {}

State& State::operator=(const State &other)
{
    this->links = other.links;
    this->name = other.name;
    this->final = other.final;
    return *this;
}

bool State::operator==(const State &other) const
{
    return other.name == this->name;
}

void State::setFinal(bool b)
{
    this->final = b;
}

bool State::isFinal() const
{
    return this->final;
}

State *State::createState()
{
    static int generator = 0;

    std::ostringstream oss;
    oss << "S" << generator++;

    return new State(oss.str());
}

void State::addLink(State *state, Edge &edge)
{
    this->links.insert(std::pair<std::string, Edge>(state->name, edge));
}

bool State::operator==(const std::string &name) const
{
    return this->name == name;
}

std::vector<std::string> State::getLinked(char c) const
{
    std::vector<std::string> result;
    for (std::map<std::string, Edge>::const_iterator it = this->links.begin(); it != this->links.end(); ++it)
        if (it->second(c))
            result.push_back(it->first);
    return result;
}

const std::map<std::string, Edge> State::getLinks() const
{
    return this->links;
}

const std::string &State::getName() const
{
    return this->name;
}
