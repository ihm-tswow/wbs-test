#include "m2_animations.hpp"

#include <bxx/blender_types/context.hpp>
#include <bxx/blender_types/scene.hpp>

#include <iostream>

namespace wbs
{
    void OBJECT_UL_animation_list::draw_item
    (
        python_object ctx,
        bxx::ui_layout layout,
        bxx::generic_property_readonly<m2_animation, python_object> item,
        bxx::generic_property<std::int64_t, python_object> active,
        std::uint64_t icon
    )
    {
        animation_id id = item.get_value().animation_id.get_value();
        std::string name = bxx::enums::get_enum_name(id);
        layout.label(name);
    }


    void OBJECT_UL_pair_list::draw_item
    (
        python_object ctx,
        bxx::ui_layout layout,
        bxx::generic_property_readonly<m2_animation_pair, python_object> item,
        bxx::generic_property<std::int64_t, python_object> active,
        std::uint64_t icon
    )
    {
        switch (item.get_value().type.get_value())
        {
        case m2_animation_pair_type::OBJECT:
        {
            bxx::object obj = item.get_value().object.get_value();
            std::string name = obj.is_valid() ? obj.get_name() : "Empty Object";
            layout.label(name);
            break;
        }
        case m2_animation_pair_type::SCENE:
        {
            bxx::scene scene = item.get_value().scene.get_value();
            std::string name = scene.is_valid() ? scene.get_name() : "Empty Scene";
            layout.label(name);
            break;
        }
        }
    }

    void animation_scene_panel::draw(bxx::python_object ctx)
    {
        scene_animations animations = ctx.getattr("scene").getattr<scene_animations>("scene_animations");
        get_layout().template_list("OBJECT_UL_animation_list", animations.animations, animations.selected_animation);
        get_layout().operator_button("bxx.op_animation_operator", bxx::kwarg("text", "Open Animation Editor"));
    }

    SIMPLE_OPERATOR(add_animation, () {
        bxx::get_context().get_scene().getattr<scene_animations>("scene_animations").animations.add();
    })

    SIMPLE_OPERATOR(remove_animation, () {

    })

    SIMPLE_OPERATOR(move_anim_up, () {

    })

    SIMPLE_OPERATOR(move_anim_down, () {

    })

    SIMPLE_OPERATOR(play_animation, () {

    })

    SIMPLE_OPERATOR(add_pair, () {
        scene_animations anims = bxx::get_context().get_scene().getattr<scene_animations>("scene_animations");
        anims.animations.get_item(anims.selected_animation.get_value()).pairs.add();
    })

    SIMPLE_OPERATOR(remove_pair, () {

    })

    SIMPLE_OPERATOR(deselect_animation_editor, () {

    })

    bxx::python_object animation_operator::invoke(bxx::context ctx, bxx::python_object evt)
    {
        return ctx.get_window_manager().invoke_props_dialog(get_pyobject(), bxx::kwarg("width", 820));
    }

    void animation_operator::draw()
    {
        bxx::ui_layout split = get_layout().split(0.5);

        // Top row - collections: animations, objects
        // Animations Column

        bxx::ui_layout col = split.column();
        col.label("Animations", bxx::kwarg("icon", "SEQUENCE"));

        bxx::ui_layout row = col.row();
        bxx::ui_layout sub_col1 = row.column();
        scene_animations anims = bxx::get_context().get_scene().getattr<scene_animations>("scene_animations");
        sub_col1.template_list("OBJECT_UL_animation_list", anims.animations, anims.selected_animation);
        bxx::ui_layout sub_col_parent = row.column();
        bxx::ui_layout sub_col2 = sub_col_parent.column(bxx::kwarg("align", true));

        sub_col2.operator_button("bxx.op_add_animation", bxx::kwarg("text", ""), bxx::kwarg("icon","ERROR"));
        sub_col2.operator_button("bxx.op_remove_animation", bxx::kwarg("text", ""), bxx::kwarg("icon","ERROR"));

        sub_col_parent.separator();

        bxx::ui_layout sub_col3 = sub_col_parent.column(bxx::kwarg("align", true));
        sub_col3.operator_button("bxx.op_move_anim_up", bxx::kwarg("text", ""), bxx::kwarg("icon", "ERROR"));
        sub_col3.operator_button("bxx.op_move_anim_down", bxx::kwarg("text", ""), bxx::kwarg("icon", "ERROR"));

        col = split.column();

        std::int64_t selected_anim = anims.selected_animation.get_value();

        m2_animation anim;
        m2_animation_pair pair;
        if (selected_anim >= 0 && selected_anim < anims.animations.len())
        {
            anim = anims.animations.get_item(selected_anim);
            row = col.row();
            sub_col1 = row.column();
            sub_col1.template_list("OBJECT_UL_pair_list", anim.pairs, anim.selected_pair);
            sub_col2 = row.column(bxx::kwarg("align", true));

            sub_col2.operator_button("bxx.op_add_pair", bxx::kwarg("text",""), bxx::kwarg("icon","ERROR"));
            sub_col2.operator_button("bxx.op_remove_pair", bxx::kwarg("text", ""), bxx::kwarg("icon", "ERROR"));

            if (anim.selected_pair.get_value() >= 0 && anim.selected_pair.get_value() < anim.pairs.len())
            {
                pair = anim.pairs.get_item(anim.selected_pair.get_value());
            }
        }
        else
        {
            col.label("No sequence selected", bxx::kwarg("icon","ERROR"));
        }

        split = get_layout().split(0.5);
        col = split.column();

        if (anim.is_valid())
        {
            row = col.row();
            bxx::ui_layout row_split = row.split(0.935);
            row_split = row_split.row(bxx::kwarg("align", true));
            row_split.prop(anim.playback_speed);

            // if context.scene.sync_mode == 'AUDIO_SYNC' and context.user_preferences.system.audio_device == 'JACK':
            if (false)
            {
                bxx::ui_layout sub = row.row(bxx::kwarg("align", true));
                sub.set_scale_x(2.0);
                sub.operator_button("bxx.op_play_animation", bxx::kwarg("text", ""), bxx::kwarg("icon", "PLAY"));
            }

            // todo: if not context.screen.is_animation_playing
            if (false)
            {
                // todo: if context.scene.sync_mode == 'AUDIO_SYNC' and context.user_preferences.system.audio_device == 'JACK':
                if (false)
                {
                    bxx::ui_layout sub = row.row(bxx::kwarg("align", true));
                    sub.set_scale_x(2.0);
                    sub.operator_button("bxx.op_play_animation", bxx::kwarg("text",""), bxx::kwarg("icon", "PLAY"));
                }
                else
                {
                    row.operator_button("bxx.op_play_animation", bxx::kwarg("text",""), bxx::kwarg("icon", "PLAY_REVERSE"));
                    row.operator_button("bxx.op_play_animation", bxx::kwarg("text",""), bxx::kwarg("icon", "PLAY"));
                }
            }
            else
            {
                bxx::ui_layout sub = row.row(bxx::kwarg("align", false));
                sub.set_scale_x(2.0);
                row.operator_button("bxx.op_play_animation", bxx::kwarg("icon", "PAUSE"));
            }

            row = row_split.row(bxx::kwarg("align", true));
            row.operator_button("bxx.op_deselect_animation_editor", bxx::kwarg("icon", "ARMATURE_DATA"));

            if (pair.is_valid())
            {
                col = split.column();
                row_split = col.row().split(0.93);
                row = row_split.row(bxx::kwarg("align", true));
                row_split = row.split(0.3);
                row_split.row().label(pair.type.get_value() == m2_animation_pair_type::OBJECT ? "Object" : "Scene");
                row = row_split.row(bxx::kwarg("align", true));
                row.prop(pair.type, bxx::kwarg("text",""), bxx::kwarg("expand",true));

                switch (pair.type.get_value())
                {
                case m2_animation_pair_type::OBJECT:
                {
                    row.prop(pair.object);
                    if (false)
                    {
                        // operator
                    }
                    else
                    {
                        bxx::ui_layout sub_row = row.row();
                        sub_row.set_enabled(false);
                        sub_row.label("", bxx::kwarg("icon", "ZOOM_SELECTED"));
                    }
                    break;
                }
                case m2_animation_pair_type::SCENE:
                {
                    row.prop(pair.scene);
                    break;
                }
                default:
                    break;
                }
                row_split = col.row().split(0.93);
                row = row_split.row(bxx::kwarg("align", true));
                col = row.column();
                col.set_scale_x(0.54);
                col.label("Action:");
                col = row.column(bxx::kwarg("align", true));
                col.set_scale_x(pair.action.get_value().is_valid() ? 1.0 : 1.55);
                col.prop(pair.action); // todo: change to template_ID
            }
            else
            {
                col = split.column();
                row = col.row();
                row_split = row.split(0.88);
                row_split.label("Object: no object selected");
                row = col.row();
                row_split = row.split(0.88);
                row_split.label("Action: no action available");
            }

            // lower row
            row = get_layout().row();
            row.separator();
            get_layout().row().label("Animation properties", bxx::kwarg("icon", "SETTINGS"));
            split = get_layout().split(0.5);
            col = split.column();
            col.separator();
            col.prop(anim.global_sequence);

            col = col.column();
            col.set_enabled(!anim.global_sequence.get_value());

            row = col.row(bxx::kwarg("align", true));
            row.label("Animation ID");
            row.prop(anim.animation_id);
            col.prop(anim.move_speed);

            // todo: version check
            col.prop(anim.blend_time);
            col.prop(anim.frequency);

            col.label("Random repeat:");
            col.prop(anim.min_repeat);
            col.prop(anim.max_repeat);

            col.label("Releations");
            row = col.row(bxx::kwarg("align", true));
            row.set_enabled(false); // todo: "is alias" check

            row.label("", bxx::kwarg("icon", "FILE_TICK")); // todo: check validity
            row.prop(anim.next_alias);
            // todo: operator

            row.label("Bounds");
            row = col.row(bxx::kwarg("align", true));
            row.set_enabled(!anim.global_sequence.get_value());
            row.prop(anim.use_preset_bounds);
            row = col.row(bxx::kwarg("align", true));
            row.set_enabled(!anim.global_sequence.get_value() && anim.use_preset_bounds.get_value());
            row.prop(anim.preset_bounds_min);

            row = col.row(bxx::kwarg("align", true));
            row.set_enabled(!anim.global_sequence.get_value() && anim.use_preset_bounds.get_value());
            row.prop(anim.preset_bounds_max);

            row = col.row(bxx::kwarg("align", true));
            row.set_enabled(!anim.global_sequence.get_value() && anim.use_preset_bounds.get_value());
            row.prop(anim.preset_bounds_radius);

            col = split.column();
            col.set_enabled(!anim.global_sequence.get_value());
            col.label("Flags:");
            col.separator();
            col.prop(anim.flags);
            col.separator();
        }
    }

    void animation_operator::execute()
    {
        std::cout << "Execute!\n";
    }

    std::vector<bxx::property_group_targets> scene_animations::targets()
    {
        return { bxx::property_group_targets::Scene };
    }

    void register_m2_animations()
    {
        m2_animation_pair::register_class();
        m2_animation::register_class();
        scene_animations::register_class();
        animation_operator::register_class();
        animation_scene_panel::register_class();
        OBJECT_UL_animation_list::register_class();
        OBJECT_UL_pair_list::register_class();
        add_animation::register_class();
        remove_animation::register_class();
        move_anim_up::register_class();
        move_anim_down::register_class();
        add_pair::register_class();
        remove_pair::register_class();
        play_animation::register_class();
        deselect_animation_editor::register_class();
    }
}