//
// Created by frasse_l on 04/12/2016.
//

#ifndef BIND_TYPETRAITS_HPP
#define BIND_TYPETRAITS_HPP

template <typename T>
struct Value;

template <typename T>
struct GetType;

template <typename T>
struct TypeTraits;

struct Traits0;

template <typename P1>
struct Traits1;

template <typename P1, typename P2>
struct Traits2;

template <typename P1, typename P2, typename P3>
struct Traits3;

template <typename P1, typename P2, typename P3, typename P4>
struct Traits4;

template <typename P1, typename P2, typename P3, typename P4, typename P5>
struct Traits5;

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
struct Traits6;

#include "TypeList.hpp"

template <typename T>
struct Value
{
public:
    Value(T &t) : _value(t){}
    ~Value(){}

    T &get() { return this->_value; }
    const T &get() const { return this->_value; }

private:
    T _value;
};

template <typename T>
struct GetType
{
    typedef Value<T> Type;
};

template <typename T>
struct TypeTraits {};

struct Traits0
{
    typedef TypeList0 Type;
};

template <typename P1>
struct Traits1
{
    typedef typename GetType <P1>::Type Type_Parameter_1;
    typedef TypeList1 <Type_Parameter_1> Type;
};

template <typename P1, typename P2>
struct Traits2
{
    typedef typename GetType <P1>::Type Type_Parameter_1;
    typedef typename GetType <P2>::Type Type_Parameter_2;
    typedef TypeList2 <Type_Parameter_1, Type_Parameter_2> Type;
};

template <typename P1, typename P2, typename P3>
struct Traits3
{
    typedef typename GetType <P1>::Type Type_Parameter_1;
    typedef typename GetType <P2>::Type Type_Parameter_2;
    typedef typename GetType <P3>::Type Type_Parameter_3;
    typedef TypeList3 <Type_Parameter_1, Type_Parameter_2, Type_Parameter_3> Type;
};

template <typename P1, typename P2, typename P3, typename P4>
struct Traits4
{
    typedef typename GetType <P1>::Type Type_Parameter_1;
    typedef typename GetType <P2>::Type Type_Parameter_2;
    typedef typename GetType <P3>::Type Type_Parameter_3;
    typedef typename GetType <P4>::Type Type_Parameter_4;
    typedef TypeList4 <Type_Parameter_1, Type_Parameter_2, Type_Parameter_3, Type_Parameter_4> Type;
};

template <typename P1, typename P2, typename P3, typename P4, typename P5>
struct Traits5
{
    typedef typename GetType <P1>::Type Type_Parameter_1;
    typedef typename GetType <P2>::Type Type_Parameter_2;
    typedef typename GetType <P3>::Type Type_Parameter_3;
    typedef typename GetType <P4>::Type Type_Parameter_4;
    typedef typename GetType <P5>::Type Type_Parameter_5;
    typedef TypeList5 <Type_Parameter_1, Type_Parameter_2, Type_Parameter_3, Type_Parameter_4, Type_Parameter_5> Type;
};

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
struct Traits6
{
    typedef typename GetType <P1>::Type Type_Parameter_1;
    typedef typename GetType <P2>::Type Type_Parameter_2;
    typedef typename GetType <P3>::Type Type_Parameter_3;
    typedef typename GetType <P4>::Type Type_Parameter_4;
    typedef typename GetType <P5>::Type Type_Parameter_5;
    typedef typename GetType <P6>::Type Type_Parameter_6;
    typedef TypeList6 <Type_Parameter_1, Type_Parameter_2, Type_Parameter_3, Type_Parameter_4, Type_Parameter_5, Type_Parameter_6> Type;
};

#endif //BIND_TYPETRAITS_HPP
