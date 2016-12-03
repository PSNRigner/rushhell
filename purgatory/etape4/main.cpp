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
    State *s8 = State::createState();
    State *s9 = State::createState();
    State *s10 = State::createState();
    State *s11 = State::createState();
    State *s12 = State::createState();
    State *s13 = State::createState();
    State *s14 = State::createState();
    State *s15 = State::createState();
    State *s16 = State::createState();
    State *s17 = State::createState();
    State *s18 = State::createState();

    Edge m('m');
    Edge e('e');
    Edge c('c');
    Edge h('h');
    Edge a('a');
    Edge n('n');
    Edge t('t');
    Edge r('r');
    Edge i('i');
    Edge l('l');
    Edge lambda(-1);

    s0->addLink(s1, lambda);
    s1->addLink(s2, m);
    s2->addLink(s3, e);
    s3->addLink(s4, c);
    s4->addLink(s5, h);
    s5->addLink(s6, a);
    s6->addLink(s7, n);
    s7->addLink(s8, t);
    s8->addLink(s18, lambda);
    s0->addLink(s9, lambda);
    s9->addLink(s10, c);
    s10->addLink(s11, r);
    s11->addLink(s12, i);
    s12->addLink(s13, m);
    s13->addLink(s14, i);
    s14->addLink(s15, n);
    s15->addLink(s16, e);
    s16->addLink(s17, l);
    s17->addLink(s18, lambda);
    s18->setFinal(true);

    FSA fsa;
    fsa.addState(s0);
    fsa.addState(s1);
    fsa.addState(s2);
    fsa.addState(s3);
    fsa.addState(s4);
    fsa.addState(s5);
    fsa.addState(s6);
    fsa.addState(s7);
    fsa.addState(s8);
    fsa.addState(s9);
    fsa.addState(s10);
    fsa.addState(s11);
    fsa.addState(s12);
    fsa.addState(s13);
    fsa.addState(s14);
    fsa.addState(s15);
    fsa.addState(s16);
    fsa.addState(s17);
    fsa.addState(s18);

    Matcher matcher(fsa);
    int nbr = 0;
    std::cout << matcher.find("mechant", nbr) << std::endl;
    std::cout << nbr << std::endl;
    std::cout << matcher.find("criminel") << std::endl;
    std::cout << matcher.find("mechantmechant", nbr) << std::endl;
    std::cout << nbr << std::endl;
    return 0;
}