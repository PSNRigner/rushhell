//
// Created by frasse_l on 03/12/2016.
//

#include "ExpressionParser.hpp"

ExpressionParser::ExpressionParser(const std::string &expression) : expression(expression)
{
}

ExpressionParser::~ExpressionParser()
{
}

FSA * ExpressionParser::parseFSA()
{
    delete(State::createState());
    std::vector<FSA *> list;
    FSA *tmp;
    while ((tmp = this->getNextFSA()))
        list.push_back(tmp);

    if (list.empty())
        return NULL;

    while (list.size() != 1)
    {
        list[0] = FSA::merge(*list[0], *list[1], FSA::UNION_2);
        list.erase(list.begin() + 1);
    }
    return list[0];
}

FSA * ExpressionParser::getNextFSA()
{
    if (!this->expression.empty() && this->expression[0] == '|')
        this->expression = this->expression.substr(1);

    if (this->expression.empty())
        return NULL;

    if (this->expression[0] == '(')
    {
        this->expression = this->expression.substr(1);

        std::vector<FSA *> list;
        while (!this->expression.empty() && this->expression[0] != ')')
        {
            FSA *fsa = this->getNextFSA();
            if (fsa == NULL)
                break;
            list.push_back(fsa);
        }

        if (this->expression.empty() || this->expression[0] != ')')
            return NULL;

        this->expression = this->expression.substr(1);

        while (list.size() != 1)
        {
            list[0] = FSA::merge(*list[0], *list[1], FSA::CONCAT);
            list.erase(list.begin() + 1);
        }
        return list[0];
    }

    FSA *newFSA = new FSA;
    State *state1 = State::createState();
    State *state2 = State::createState();
    state2->setFinal(true);
    Edge edge(this->expression[0]);
    state1->addLink(state2, edge);
    newFSA->addState(state1);
    newFSA->addState(state2);
    this->expression = this->expression.substr(1);
    return newFSA;
}