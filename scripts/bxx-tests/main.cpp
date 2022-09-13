#include "wow_object_type.hpp"

void script_register()
{
    wow_object_type::register_class();
    wow_object_type_panel::register_class();
}

void script_unregister()
{

}