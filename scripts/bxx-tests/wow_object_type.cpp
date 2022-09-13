#include "wow_object_type.hpp"

bxx::enum_meta wow_object_type_meta(wow_object_type_enum value)
{
    switch (value)
    {
    case wow_object_type_enum::M2:
        return bxx::enum_meta{ "M2", "", "" };
    case wow_object_type_enum::WMO:
        return bxx::enum_meta{ "WMO", "", "" };
    case wow_object_type_enum::ADT:
        return bxx::enum_meta{ "ADT", "", "" };
    case wow_object_type_enum::M2_PROP:
        return bxx::enum_meta{ "M2 Prop", "M2 part of a WMO", "" };
    case wow_object_type_enum::NONE:
        return bxx::enum_meta{ "None", "", "" };
    }
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
    return obj.getattr<wow_object_type>("wow_object_type").object_type.get_value();
}
