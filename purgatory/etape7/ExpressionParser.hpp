//
// Created by frasse_l on 03/12/2016.
//

#ifndef ETAPE6_EXPRESSIONPARSER_HPP
#define ETAPE6_EXPRESSIONPARSER_HPP

#include "FSA.hpp"

class ExpressionParser
{
public:
    ExpressionParser(const std::string &);
    ~ExpressionParser();

    FSA *getNextFSA();
    FSA *parseFSA();

private:
    std::string expression;
};


#endif //ETAPE6_EXPRESSIONPARSER_HPP
