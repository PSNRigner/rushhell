//
// Created by frasse_l on 02/12/2016.
//

#ifndef ETAPE2_FUNCTION_HPP
#define ETAPE2_FUNCTION_HPP


template <typename R, typename ... Args>
class Function<R(Args...)>
{
public:
    Function(R (*ptr)(Args...)) : _ptr(ptr)
    {
    }

    R operator()(Args &&... args)
    {
        return _ptr(std::forward<Args>(args)...);
    }

private:
    R (*_ptr)(Args...);
};

#endif //ETAPE2_FUNCTION_HPP
