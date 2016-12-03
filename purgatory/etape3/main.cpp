#include <iostream>

#include "Matcher.hpp"

int main()
{
    State *s0 = State::createState();
    State *s1 = State::createState();
    State *s2 = State::createState();
    State *s3 = State::createState();
    State *s4 = State::createState();
    State *s5 = State::createState();
    State *s6 = State::createState();
    State *s7 = State::createState();

    Edge m('m');
    Edge e('e');
    Edge c('c');
    Edge h('h');
    Edge a('a');
    Edge n('n');
    Edge t('t');

    s0->addLink(s1, m);
    s1->addLink(s2, e);
    s2->addLink(s2, e);
    s2->addLink(s3, c);
    s3->addLink(s4, h);
    s4->addLink(s5, a);
    s5->addLink(s6, n);
    s6->addLink(s7, t);
    s7->setFinal(true);

    FSA fsa;
    fsa.addState(s0);
    fsa.addState(s1);
    fsa.addState(s2);
    fsa.addState(s3);
    fsa.addState(s4);
    fsa.addState(s5);
    fsa.addState(s6);
    fsa.addState(s7);

    Matcher matcher(fsa);
    int nbr = 0;
    std::cout << matcher.find("meeeeeeeeeeeeeeeeeeeeeeechantmechant", nbr) << std::endl;
    std::cout << nbr << std::endl;
    std::cout << matcher.find("meeeeeeeeeeeeeeeeeeeeeeechant") << std::endl;
    return 0;
}