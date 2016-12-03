#include <iostream>

#include "Matcher.hpp"

int main()
{
    delete(State::createState());
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

    s1->addLink(s2, m);
    s2->addLink(s3, e);
    s3->addLink(s4, c);
    s4->addLink(s5, h);
    s5->addLink(s6, a);
    s6->addLink(s7, n);
    s7->addLink(s8, t);
    s8->setFinal(true);

    s9->addLink(s10, c);
    s10->addLink(s11, r);
    s11->addLink(s12, i);
    s12->addLink(s13, m);
    s13->addLink(s14, i);
    s14->addLink(s15, n);
    s15->addLink(s16, e);
    s16->addLink(s17, l);
    s17->setFinal(true);

    FSA fsa1;
    fsa1.addState(s1);
    fsa1.addState(s2);
    fsa1.addState(s3);
    fsa1.addState(s4);
    fsa1.addState(s5);
    fsa1.addState(s6);
    fsa1.addState(s7);
    fsa1.addState(s8);

    FSA fsa2;
    fsa2.addState(s9);
    fsa2.addState(s10);
    fsa2.addState(s11);
    fsa2.addState(s12);
    fsa2.addState(s13);
    fsa2.addState(s14);
    fsa2.addState(s15);
    fsa2.addState(s16);
    fsa2.addState(s17);

    std::cout << "FSA 1 :" << std::endl << fsa1 << std::endl;
    std::cout << "FSA 2 :" << std::endl << fsa2 << std::endl;
    FSA *fsa3 = FSA::merge(fsa1, fsa2, FSA::UNION_2);
    std::cout << "FSA 3 :" << std::endl << *fsa3 << std::endl;

    Matcher matcher(*fsa3);
    int nbr = 0;
    std::cout << matcher.find("mechant", nbr) << std::endl;
    std::cout << nbr << std::endl;
    std::cout << matcher.find("criminel") << std::endl;
    std::cout << matcher.find("mechantmechant", nbr) << std::endl;
    std::cout << nbr << std::endl;
    return 0;
}