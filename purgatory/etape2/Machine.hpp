//
// Created by frasse_l on 02/12/2016.
//

#ifndef ETAPE1_MACHINE_HPP
#define ETAPE1_MACHINE_HPP

enum eState
{
    S0 = 0,
    S1,
    S2,
    S3,
    S4,
    S5,
    S6,
    S7,
    STATE_ERROR
};

enum eAction
{
    MA,
    HR,
    ACTION_ERROR
};

extern eState gStateTable[8][8];
extern eAction gActionTable[8][8];

#endif //ETAPE1_MACHINE_HPP
