#include "wow_object_type.hpp"

#include <magic_enum.hpp>

#define ADD_WOW_ENUM(vec,id,name,desc,icon)\
    vec.push_back(\
        bxx::enum_entry(\
            std::string(magic_enum::enum_name<wow_object_type_enum>(wow_object_type_enum::id)),\
            name,\
            desc,\
            icon,\
            static_cast<std::int64_t>(wow_object_type_enum::id)\
        )\
    )

namespace wbs
{

    std::vector<bxx::enum_entry> wow_object_type_entries(bxx::python_object cls, bxx::python_object ctx)
    {
        bxx::object obj = ctx.getattr<bxx::object>("object");
        if (!obj.is_valid())
        {
            return {};
        }

        std::vector<bxx::enum_entry> vec;
        ADD_WOW_ENUM(vec, NONE, "None", "Not a WoW Object", "");

        switch (obj.get_type())
        {
        case bxx::object_type::MESH:
            ADD_WOW_ENUM(vec, WMO, "WMO", "World map objects", "");
            ADD_WOW_ENUM(vec, M2, "M2", "Static or animated M2 models", "");
            ADD_WOW_ENUM(vec, ADT, "ADT", "ADT Map", "");
            break;
        case bxx::object_type::EMPTY:
            ADD_WOW_ENUM(vec, M2_ATTACHMENT, "Attachment", "", "");
            ADD_WOW_ENUM(vec, M2_EVENT, "Event", "", "");
            ADD_WOW_ENUM(vec, M2_RIBBON, "Ribbon Emitter", "", "");
            ADD_WOW_ENUM(vec, M2_PARTICLE, "Particle Emitter", "", "");
            break;
        case bxx::object_type::CAMERA:
            ADD_WOW_ENUM(vec, M2_CAMERA, "Camera", "", "");
            break;
        case bxx::object_type::LIGHT:
            ADD_WOW_ENUM(vec, M2_LIGHT, "Light", "", "");
            break;
        case bxx::object_type::ARMATURE:
            ADD_WOW_ENUM(vec, M2, "M2", "Static or animated M2 models", "");
        case bxx::object_type::CURVE:
        case bxx::object_type::FONT:
        case bxx::object_type::GPENCIL:
        case bxx::object_type::LATTICE:
        case bxx::object_type::LIGHT_PROBE:
        case bxx::object_type::META:
        case bxx::object_type::SPEAKER:
        case bxx::object_type::SURFACE:
            break;
        }
        return vec;
    }

    std::vector<bxx::property_group_targets> wow_object_type::targets()
    {
        return { bxx::property_group_targets::Object };
    }

    void wow_object_type_panel::draw_header(python_object ctx)
    {
        get_layout().label("WoW Object");
    }

    void wow_object_type_panel::draw(python_object ctx)
    {
        wow_object_type type = ctx.getattr("object").getattr<wow_object_type>("wow_object_type");
        get_layout().prop(type.object_type, bxx::kwarg("text", "WoW Object Type"));
    }

    wow_object_type_enum get_object_type(bxx::object obj)
    {
        return magic_enum::enum_cast<wow_object_type_enum>(obj.getattr<wow_object_type>("wow_object_type").object_type.get_value()).value();
    }

    void register_wow_object_type()
    {
        wow_object_type::register_class();
        wow_object_type_panel::register_class();
    }
}
