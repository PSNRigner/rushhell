//
// Created by frasse_l on 03/12/2016.
//

#include "Matcher.hpp"

Matcher::Matcher(const FSA &fsa) : fsa(fsa)
{
}

Matcher::~Matcher() {}

bool Matcher::find(const std::string &str, int &n)
{
    n = 0;
    bool ok = false;
    std::string state = "S0";
    for (int i = 0; i < str.length(); ++i)
    {
        State *st = this->fsa[state];
        if (st == NULL)
            return ok;
        if (st->isFinal())
        {
            state = "S0";
            ok = true;
            ++n;
            st = this->fsa[state];
            if (st == NULL)
                return ok;
        }
        std::string *next = st->getLinked(str[i]);
        if (next == NULL)
            return ok;
        state = *next;
        delete(next);
    }

    State *st = this->fsa[state];
    if (st != NULL && st->isFinal())
    {
        ok = true;
        ++n;
    }
    return ok;
}