#include "wow_object_type.hpp"
#include "wow_material_type.hpp"
#include "m2/m2_bone.hpp"

void script_register()
{
    wbs::register_wow_object_type();
    wbs::register_wow_material_type();
    wbs::register_m2_bones();
}

void script_unregister()
{

}