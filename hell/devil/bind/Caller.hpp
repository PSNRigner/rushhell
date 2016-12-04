//
// Created by frasse_l on 04/12/2016.
//

#ifndef BIND_CALLER_HPP
#define BIND_CALLER_HPP

template <typename ReturnType, typename Callable, typename List>
struct Caller;

#include "TypeTraits.hpp"

template <typename ReturnType, typename Callable, typename List>
struct Caller
{
    Caller(Callable &callable, List& list) : _callable(callable), _list(list)
    {
    }

    ReturnType operator()()
    {
        return this->_list(TypeTraits<ReturnType>(), this->_callable, this->_list);
    }

    Callable _callable;
    List _list;
};

#endif //BIND_CALLER_HPP
