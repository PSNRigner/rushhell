//
// Created by frasse_l on 03/12/2016.
//

#ifndef ETAPE3_MATCHER_HPP
#define ETAPE3_MATCHER_HPP


#include "FSA.hpp"

static int no_ref = 0;

class Matcher
{
public:
    Matcher(const std::string &);
    ~Matcher();

    bool find(const std::string &, int & = no_ref);
private:
    FSA *fsa;
};


#endif //ETAPE3_MATCHER_HPP
