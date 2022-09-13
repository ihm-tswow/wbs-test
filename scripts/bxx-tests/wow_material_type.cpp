#include "wow_material_type.hpp"

namespace wbs
{
    bxx::enum_meta wow_material_type_meta(wow_material_type_enum value)
    {
        switch (value)
        {
        case wow_material_type_enum::M2:
            return bxx::enum_meta{ "M2", "", "" };
        case wow_material_type_enum::WMO:
            return bxx::enum_meta{ "WMO", "", "" };
        case wow_material_type_enum::ADT:
            return bxx::enum_meta{ "ADT", "", "" };
        case wow_material_type_enum::NONE:
            return bxx::enum_meta{ "None", "", "" };
        }
    }

    std::vector<bxx::property_group_targets> wow_material_type::targets()
    {
        return { bxx::property_group_targets::Material };
    }

    void wow_material_type_panel::draw_header(python_object ctx)
    {
        get_layout().label("WoW Object");
    }

    void wow_material_type_panel::draw(python_object ctx)
    {
        wow_material_type type = ctx.getattr("material").getattr<wow_material_type>("wow_material_type");
        get_layout().prop(type.material_type, bxx::kwarg("text", "WoW Material Type"));
    }

    wow_material_type_enum get_material_type(bxx::object obj)
    {
        return obj.getattr<wow_material_type>("wow_material_type").material_type.get_value();
    }

    void register_wow_material_type()
    {
        wow_material_type::register_class();
        wow_material_type_panel::register_class();
    }
}
