#pragma once

#include <bxx/classes/property_group.hpp>
#include <bxx/classes/panel_class.hpp>
#include <bxx/classes/operator.hpp>
#include <bxx/classes/ui_list.hpp>
#include <bxx/blender_types/object.hpp>
#include <bxx/blender_types/context.hpp>
#include <bxx/blender_types/action.hpp>
#include <bxx/blender_types/scene.hpp>
#include <bxx/enums.hpp>

#include <iostream>

namespace wbs
{
    enum class animation_id
    {
        stand = 1,
        walk = 2,
        run = 3
    };

    enum class m2_animation_pair_type
    {
        OBJECT,
        SCENE
    };

    class m2_animation_pair : public bxx::property_group_class<m2_animation_pair>
    {
    public:
        bxx::pointer_property<bxx::object::ref, "Object", "">
            object;

        bxx::pointer_property<bxx::scene::ref, "Scene", "">
            scene;

        bxx::pointer_property<bxx::action::ref, "Action", "">
            action;

        bxx::enum_property<
            m2_animation_pair_type,
            "Type",
            "",
            m2_animation_pair_type::OBJECT,
            [](m2_animation_pair_type type)
            {
            switch (type)
            {
            case m2_animation_pair_type::OBJECT:
                return bxx::enum_meta{"Object", "", "OBJECT_DATA"};
            case m2_animation_pair_type::SCENE:
                return bxx::enum_meta{"Scene", "", "SCENE_DATA"};
            }
            }
        >
        type;

        PROPERTY_GROUP(
              m2_animation_pair
            , PROPERTY_ENTRY(object)
            , PROPERTY_ENTRY(scene)
            , PROPERTY_ENTRY(action)
            , PROPERTY_ENTRY(type)
        )
    };

    class m2_animation : public bxx::property_group_class<m2_animation>
    {
    public:
        bxx::bool_property<"Global Sequence", "", false>
        global_sequence;

        bxx::enum_property<
            /* TYPE           */ animation_id,
            /* NAME           */ "Animation ID",
            /* DESCRIPTION    */ "",
            /* DEFAULT        */ animation_id::stand,
            nullptr
        >
        animation_id;

        bxx::mask_property<
            /* TYPE           */ m2_animation_flags,
            /* NAME           */ "Flags",
            /* DESCRIPTION    */ ""
        >
        flags;

        bxx::collection_property<m2_animation_pair::ref, "Pairs", "">
        pairs;

        bxx::int_property<"Selected Pair", "", 0>
        selected_pair;

        bxx::float_property<"Playback speed", "", 0.0>
        playback_speed;

        bxx::float_property<"Move speed", "", 0.0>
        move_speed;

        bxx::int_property<"Blend Time", "", 0>
        blend_time;

        bxx::int_property<"Frequency", "", 0>
        frequency;

        bxx::int_property<"Min Repeat", "", 0>
        min_repeat;

        bxx::int_property<"Max Repeat", "", 0>
        max_repeat;

        bxx::int_property<"Next Alias", "", 0>
        next_alias;

        bxx::bool_property<"Use Preset Bounds", "", false>
        use_preset_bounds;

        bxx::float_vector_property<"Preset Bounds Min", "", 3>
        preset_bounds_min;

        bxx::float_vector_property<"Preset Bounds Max", "", 3>
        preset_bounds_max;

        bxx::float_property<"Preset Bounds Radius", "">
        preset_bounds_radius;

        PROPERTY_GROUP(
              m2_animation
            , PROPERTY_ENTRY(global_sequence)
            , PROPERTY_ENTRY(animation_id)
            , PROPERTY_ENTRY(flags)
            , PROPERTY_ENTRY(pairs)
            , PROPERTY_ENTRY(selected_pair)
            , PROPERTY_ENTRY(playback_speed)
            , PROPERTY_ENTRY(move_speed)
            , PROPERTY_ENTRY(blend_time)
            , PROPERTY_ENTRY(frequency)
            , PROPERTY_ENTRY(min_repeat)
            , PROPERTY_ENTRY(max_repeat)
            , PROPERTY_ENTRY(next_alias)
            , PROPERTY_ENTRY(use_preset_bounds)
            , PROPERTY_ENTRY(preset_bounds_min)
            , PROPERTY_ENTRY(preset_bounds_max)
            , PROPERTY_ENTRY(preset_bounds_radius)
        )
    };

    class scene_animations : public bxx::property_group_class<scene_animations>
    {
    public:
        std::vector<bxx::property_group_targets> targets() final;

        bxx::collection_property<m2_animation::ref, "Animations", "">
        animations;

        bxx::int_property<"Selected Animation", "">
        selected_animation;

        PROPERTY_GROUP(scene_animations
            , PROPERTY_ENTRY(animations)
            , PROPERTY_ENTRY(selected_animation)
        )
    };

    class OBJECT_UL_animation_list : public bxx::ui_list<OBJECT_UL_animation_list, m2_animation>
    {
    public:
        void draw_item(
            python_object ctx,
            bxx::ui_layout layout,
            bxx::generic_property_readonly<m2_animation, python_object> item,
            bxx::generic_property<std::int64_t, python_object> active,
            std::uint64_t icon
        ) final;
        UI_LIST_NO_PROPS(OBJECT_UL_animation_list)
    };

    class OBJECT_UL_pair_list: public bxx::ui_list<OBJECT_UL_pair_list, m2_animation_pair>
    {
    public:
        void draw_item(
            python_object ctx,
            bxx::ui_layout layout,
            bxx::generic_property_readonly<m2_animation_pair, python_object> item,
            bxx::generic_property<std::int64_t, python_object> active,
            std::uint64_t icon
        ) final;
        UI_LIST_NO_PROPS(OBJECT_UL_pair_list)
    };

    class animation_operator : public bxx::operator_class<animation_operator>
    {
    public:
        void execute() final;
        void draw() final;
        python_object invoke(bxx::context ctx, bxx::python_object evt) final;

        OPERATOR_NO_PROPS(animation_operator)
    };

    class animation_scene_panel : public bxx::panel_class
    <
        animation_scene_panel,
        bxx::bl_context::scene,
        bxx::bl_space_type::PROPERTIES,
        bxx::bl_region_type::WINDOW
    >
    {
    public:
        void draw(bxx::python_object ctx) final;
        UI_CLASS(animation_scene_panel)
    };

    void register_m2_animations();
}