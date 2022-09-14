#include "m2_attachment.hpp"
#include "../wow_object_type.hpp"

#include <magic_enum.hpp>

namespace wbs
{
    bxx::enum_meta m2_attachment_meta(m2_attachment_type value)
    {
        return bxx::enum_meta(std::string(magic_enum::enum_name<m2_attachment_type>(value)),"","");
    }

    std::vector<bxx::property_group_targets> m2_attachment::targets()
    {
        return { bxx::property_group_targets::Object };
    }

    void wow_object_type_panel::draw_attachment(bxx::object obj)
    {
        m2_attachment attachment = obj.getattr<m2_attachment>("m2_attachment");
        get_layout().prop(attachment.attachment_type, bxx::kwarg("text", "Attachment Type"));
        get_layout().prop(attachment.animate, bxx::kwarg("text", "Animate"));
    }
}