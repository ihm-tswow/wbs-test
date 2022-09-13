#pragma once
#include <bxx/classes/property_group.hpp>
#include <bxx/classes/panel_class.hpp>
#include <bxx/classes/ui_layout.hpp>
#include <bxx/classes/operator.hpp>
#include <bxx/blender_types/object.hpp>
#include <bxx/blender_types/context.hpp>
#include <bxx/objects/python_object.hpp>

enum class wow_object_type_enum
{
    NONE,
    WMO,
    M2_PROP,
    M2,
    ADT
};

bxx::enum_meta wow_object_type_meta(wow_object_type_enum value);

class wow_object_type : public bxx::property_group_class<wow_object_type>
{
public:
    std::vector<bxx::property_group_targets> targets() final;

    bxx::enum_property<
        /* TYPE           */ wow_object_type_enum,
        /* NAME           */ "Test Enum Value",
        /* DEFAULT        */ wow_object_type_enum::NONE,
        /* DESCRIPTION    */ "Description",
        /* REPRESENTATION */ wow_object_type_meta
    >
    object_type;

    PROPERTY_GROUP(
        wow_object_type,
        PROPERTY_ENTRY(object_type)
    )
};

class wow_object_type_panel : public bxx::panel_class<
    wow_object_type_panel,
    bxx::bl_context::object,
    bxx::bl_space_type::PROPERTIES,
    bxx::bl_region_type::WINDOW
>
{
public:
    void draw_header(python_object ctx) final;
    void draw(python_object ctx) final;
    UI_CLASS(wow_object_type_panel)
};

wow_object_type_enum get_object_type(bxx::object obj);