#pragma once

#include <bxx/classes/property_group.hpp>
#include <bxx/classes/panel_class.hpp>
#include <bxx/classes/ui_layout.hpp>
#include <bxx/classes/operator.hpp>
#include <bxx/blender_types/object.hpp>
#include <bxx/blender_types/context.hpp>
#include <bxx/objects/python_object.hpp>

namespace wbs
{
    enum class wow_material_type_enum
    {
        NONE,
        WMO,
        M2,
        ADT
    };

    bxx::enum_meta wow_material_type_meta(wow_material_type_enum value);

    class wow_material_type : public bxx::property_group_class<wow_material_type>
    {
    public:
        std::vector<bxx::property_group_targets> targets() final;

        bxx::enum_property<
            /* TYPE           */ wow_material_type_enum,
            /* NAME           */ "WoW Material Type",
            /* DEFAULT        */ wow_material_type_enum::NONE,
            /* DESCRIPTION    */ "Description",
            /* REPRESENTATION */ wow_material_type_meta
        >
        material_type;

        PROPERTY_GROUP(
            wow_material_type,
            PROPERTY_ENTRY(material_type)
        )
    };

    class wow_material_type_panel : public bxx::panel_class<
        wow_material_type_panel,
        bxx::bl_context::material,
        bxx::bl_space_type::PROPERTIES,
        bxx::bl_region_type::WINDOW
    >
    {
    public:
        void draw_header(python_object ctx) final;
        void draw(python_object ctx) final;
        UI_CLASS(wow_material_type_panel)
    };

    wow_material_type_enum get_material_type(bxx::object obj);

    void register_wow_material_type();
}
