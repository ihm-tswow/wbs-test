#include "wow_object_type.hpp"
#include "wow_material_type.hpp"

void script_register()
{
    wbs::register_wow_object_type();
    wbs::register_wow_material_type();
}

void script_unregister()
{

}