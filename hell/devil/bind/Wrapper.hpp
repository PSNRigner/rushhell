//
// Created by frasse_l on 04/12/2016.
//

#ifndef BIND_WRAPPER_HPP_HH
#define BIND_WRAPPER_HPP_HH

template <typename ReturnType, typename Object>
struct ObjectWrapper0
{
    ObjectWrapper0(Object *obj, ReturnType (Object::*ptr)()) : _obj(obj), _ptr(ptr)
    {
    }

    Object *_obj;
    ReturnType (Object::*_ptr)();

    ReturnType operator()()
    {
        return (this->_obj->*this->_ptr)();
    }
};

template <typename ReturnType, typename Object, typename Param1>
struct ObjectWrapper1
{
    ObjectWrapper1(Object *obj, ReturnType (Object::*ptr)(Param1)) : _obj(obj), _ptr(ptr)
    {
    }

    Object *_obj;
    ReturnType (Object::*_ptr)(Param1);

    ReturnType operator()(Param1 p1)
    {
        return (this->_obj->*this->_ptr)(p1);
    }
};

template <typename ReturnType, typename Object, typename Param1, typename Param2>
struct ObjectWrapper2
{
    ObjectWrapper2(Object *obj, ReturnType (Object::*ptr)(Param1, Param2)) : _obj(obj), _ptr(ptr)
    {
    }

    Object *_obj;
    ReturnType (Object::*_ptr)(Param1, Param2);

    ReturnType operator()(Param1 p1, Param2 p2)
    {
        return (this->_obj->*this->_ptr)(p1, p2);
    }
};

template <typename ReturnType, typename Object, typename Param1, typename Param2, typename Param3>
struct ObjectWrapper3
{
    ObjectWrapper3(Object *obj, ReturnType (Object::*ptr)(Param1, Param2, Param3)) : _obj(obj), _ptr(ptr)
    {
    }

    Object *_obj;
    ReturnType (Object::*_ptr)(Param1, Param2, Param3);

    ReturnType operator()(Param1 p1, Param2 p2, Param3 p3)
    {
        return (this->_obj->*this->_ptr)(p1, p2, p3);
    }
};

template <typename ReturnType, typename Object, typename Param1, typename Param2, typename Param3, typename Param4>
struct ObjectWrapper4
{
    ObjectWrapper4(Object *obj, ReturnType (Object::*ptr)(Param1, Param2, Param3, Param4)) : _obj(obj), _ptr(ptr)
    {
    }

    Object *_obj;
    ReturnType (Object::*_ptr)(Param1, Param2, Param3, Param4);

    ReturnType operator()(Param1 p1, Param2 p2, Param3 p3, Param4 p4)
    {
        return (this->_obj->*this->_ptr)(p1, p2, p3, p4);
    }
};

template <typename ReturnType, typename Object, typename Param1, typename Param2, typename Param3, typename Param4, typename Param5>
struct ObjectWrapper5
{
    ObjectWrapper5(Object *obj, ReturnType (Object::*ptr)(Param1, Param2, Param3, Param4, Param5)) : _obj(obj), _ptr(ptr)
    {
    }

    Object *_obj;
    ReturnType (Object::*_ptr)(Param1, Param2, Param3, Param4, Param5);

    ReturnType operator()(Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5)
    {
        return (this->_obj->*this->_ptr)(p1, p2, p3, p4, p5);
    }
};

template <typename ReturnType, typename Object, typename Param1, typename Param2, typename Param3, typename Param4, typename Param5, typename Param6>
struct ObjectWrapper6
{
    ObjectWrapper6(Object *obj, ReturnType (Object::*ptr)(Param1, Param2, Param3, Param4, Param5, Param6)) : _obj(obj), _ptr(ptr)
    {
    }

    Object *_obj;
    ReturnType (Object::*_ptr)(Param1, Param2, Param3, Param4, Param5, Param6);

    ReturnType operator()(Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6)
    {
        return (this->_obj->*this->_ptr)(p1, p2, p3, p4, p5, p6);
    }
};

#endif //BIND_WRAPPER_HPP_HH
