#pragma once
#include <bxx/classes/property_group.hpp>
#include <bxx/classes/panel_class.hpp>
#include <bxx/classes/ui_layout.hpp>
#include <bxx/classes/operator.hpp>
#include <bxx/blender_types/object.hpp>
#include <bxx/blender_types/context.hpp>
#include <bxx/objects/python_object.hpp>

#include <vector>

namespace wbs
{
    enum class wow_object_type_enum
    {
        // Global
        NONE,

        // Mesh Types
        WMO,
        M2,
        ADT,

        // Empty Types
        M2_ATTACHMENT,
        M2_EVENT,
        M2_RIBBON,
        M2_PARTICLE,

        // Camera Types
        M2_CAMERA,

        // Light Types
        M2_LIGHT,
    };

    std::vector<bxx::enum_entry> wow_object_type_entries(bxx::python_object,bxx::python_object);

    class wow_object_type : public bxx::property_group_class<wow_object_type>
    {
    public:
        std::vector<bxx::property_group_targets> targets() final;

        bxx::dynamic_enum_property<
            "WoW Object Type",
            "",
            wow_object_type_entries
        >
        object_type;

        wow_object_type_enum get_object_type_enum();

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
    protected:
        void draw_attachment(bxx::object obj);
        void draw_event(bxx::object obj);
    };

    wow_object_type_enum get_object_type(bxx::object obj);

    void register_wow_object_type();
}
