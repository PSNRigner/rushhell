//
// Created by frasse_l on 02/12/2016.
//

#ifndef ETAPE2_FUNCTION_HPP
#define ETAPE2_FUNCTION_HPP

#include <string>

struct Base
{
    virtual void operator()(const std::string &) = 0;
    virtual ~Base(){}
};

template <typename T>
struct Functor : Base
{
    T func;
    Functor(T func) : func(func) {}
    virtual void operator()(const std::string &n)
    {
        func(n);
    }
};

template <typename T>
class Function
{
public:
    template <typename U>
    Function(U u)
    {
        this->ptr = new Functor<U>(u);
    }

    template <typename U>
    Function(U *u)
    {
        this->ptr = new Functor<U *>(u);
    }

    void operator()(const std::string & n)
    {
        return ptr->operator()(n);
    }

    template <typename U>
    Function &operator=(U u)
    {
        delete(this->ptr);
        this->ptr = new Functor<U>(u);
        return *this;
    }

    template <typename U>
    Function &operator=(U *u)
    {
        delete(this->ptr);
        this->ptr = new Functor<U *>(u);
        return *this;
    }

private:
    Base *ptr;
};

#endif //ETAPE2_FUNCTION_HPP
