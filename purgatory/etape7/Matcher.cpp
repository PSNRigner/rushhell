//
// Created by frasse_l on 03/12/2016.
//

#include <iostream>
#include "ExpressionParser.hpp"
#include "Matcher.hpp"

Matcher::Matcher(const std::string &expression)
{
    ExpressionParser expressionParser(expression);
    this->fsa = expressionParser.parseFSA();
}

Matcher::~Matcher() {}

static bool recur(const std::string &str, int &n, int &index, FSA *fsa, const std::string &state, std::string &token)
{
    State *st = (*fsa)[state];
    if (st == NULL)
        return false;
    if (st->isFinal())
    {
        ++n;
        if (st->getFunctor() != NULL)
            st->getFunctor()->operator()(token);
        return true;
    }
    std::vector<std::string> next = st->getLinked(str[index]);
    std::vector<std::string> next2 = st->getLinked(-1);
    for (int i = 0; i < next2.size(); ++i)
        if (recur(str, n, index, fsa, next2[i], token))
            return true;
    ++index;
    std::string nextToken = token;
    nextToken.push_back(str[index - 1]);
    for (int i = 0; i < next.size(); ++i)
        if (recur(str, n, index, fsa, next[i], nextToken))
            return true;
    --index;
    return false;
}

bool Matcher::find(const std::string &str, int &n)
{
    if (this->fsa == NULL)
        return false;

    FSA *sub = this->fsa->subset(str);
    n = 0;
    bool ok = false;
    std::string token;
    for (int i = 0; i < str.size(); ++i)
    {
        if (recur(str, n, i, sub, "S0", token))
        {
            ok = true;
            --i;
        }
    }

    return ok;
}

Matcher::Matcher(FSA *fsa) : fsa(fsa)
{
}
