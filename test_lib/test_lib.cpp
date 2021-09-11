#include "../lib/glade.h"

#include <iostream>

using namespace glade::lang;

extern "C" void __init(gc*, scope*);
extern "C" obj *__new(gc*);

class test_obj : public obj
{
    public:
        test_obj() : obj(false)
        {
            this->obj_class = new _class("test_obj");
        }

        virtual str to_string()
        {
            return str("test object!");
        }
};

void __init(gc *garb_coll, scope *g_scope)
{
    std::cout << "hello" << std::endl;
}

obj *__new(gc *garb_coll)
{
    return new(garb_coll->alloc(sizeof(test_obj))) test_obj;
}
