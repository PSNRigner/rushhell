//
// Created by frasse_l on 02/12/2016.
//

#ifndef ETAPE2_FUNCTION_HPP
#define ETAPE2_FUNCTION_HPP

struct Base
{
    virtual void operator()(int) = 0;
    virtual ~Base(){}
};

template <typename T>
struct Functor : Base
{
    T func;
    Functor(T func) : func(func) {}
    virtual void operator()(int n)
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

    void operator()(int n)
    {
        return ptr->operator()(n);
    }

private:
    Base *ptr;
};

#endif //ETAPE2_FUNCTION_HPP
