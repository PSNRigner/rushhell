//
// Created by frasse_l on 04/12/2016.
//

#ifndef DEVIL_INSPECTOR_HPP
#define DEVIL_INSPECTOR_HPP

#include <typeinfo>
#include <iostream>

template <typename T, typename U>
struct IsPrintable
{
    typedef char Yes[1];
    typedef char No[2];

    template <size_t X>
    struct S {};

    template <typename V, typename W>
    static Yes &isPrintable(S<sizeof( *static_cast<V*>(NULL) << *static_cast<W*>(NULL) )>* = 0);

    template <typename V, typename W>
    static No &isPrintable(...);

    static const bool ISPRINTABLE = sizeof(isPrintable<T, U>(NULL)) == sizeof(Yes);
};

template <bool Cond, typename T = void*>
struct enable_if
{
    typedef T type;
};

template <typename T>
struct enable_if<0, T>
{};

template <typename T>
struct Printer
{
    template <typename U>
    static void print(T &t, const U &u, typename enable_if<IsPrintable<T, U>::ISPRINTABLE, U>::type * = 0)
    {
        t << u;
    }

    template <typename U>
    static void print(T &t, const U &u, typename enable_if<!IsPrintable<T, U>::ISPRINTABLE, U>::type * = 0)
    {
        t << typeid(u).name();
    }
};

template <typename T>
void inspect(const T &t)
{
    Printer<std::ostream>::print(std::cout, t);
}

#endif //DEVIL_INSPECTOR_HPP
