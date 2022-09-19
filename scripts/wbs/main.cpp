#include "wow_object_type.hpp"
#include "wow_material_type.hpp"
#include "m2/m2_bone.hpp"
#include "m2/m2_attachment.hpp"
#include "m2/m2_event.hpp"
#include "m2/m2_animations.hpp"

void script_register()
{
    wbs::register_wow_object_type();
    wbs::register_wow_material_type();
    wbs::register_m2_bones();
    wbs::m2_attachment::register_class();
    wbs::m2_event::register_class();
    wbs::register_m2_animations();
}

void script_unregister()
{

}