#include "m2_bone.hpp"

#include <magic_enum.hpp>

#include <iostream>

namespace wbs
{
    bxx::enum_meta m2_key_bone_meta(m2_key_bone value)
    {
        return { std::string(magic_enum::enum_name<m2_key_bone>(value)),"",""};
    }

    bxx::enum_meta m2_bone_flags_meta(m2_bone_flags value)
    {
        return { std::string(magic_enum::enum_name<m2_bone_flags>(value)),"",""};
    }

    bool poll_m2_bone_panel(bxx::python_object cls, bxx::python_object ctx)
    {
        return ctx.getattr("edit_bone").is_valid();
    }

    void m2_bone_panel::draw(python_object ctx)
    {
        m2_bone bone = ctx.getattr("edit_bone").getattr<m2_bone>("m2_bone");
        get_layout().prop(bone.key_bone, bxx::kwarg("text", "Key Bone"));
        get_layout().prop(bone.flags, bxx::kwarg("text", "Flags"));
        get_layout().prop(bone.submesh_id, bxx::kwarg("text", "Submesh ID"));
        get_layout().prop(bone.sort_index, bxx::kwarg("text", "Sort Index"));
        get_layout().prop(bone.bone_name_crc, bxx::kwarg("text", "Bone Name CRC"));
    }

    void register_m2_bones()
    {
        m2_bone::register_class();
        m2_bone_panel::register_class();
    }
}
