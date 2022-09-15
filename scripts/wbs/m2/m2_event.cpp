#include "m2_event.hpp"
#include "../wow_object_type.hpp"

namespace wbs
{
    std::vector<bxx::property_group_targets> m2_event::targets()
    {
        return { bxx::property_group_targets::Object };
    }

    void wow_object_type_panel::draw_event(bxx::object obj)
    {
        m2_event attachment = obj.getattr<m2_event>("m2_event");
        get_layout().prop(attachment.event_type, bxx::kwarg("text", "Attachment Type"));
        get_layout().prop(attachment.data, bxx::kwarg("text", "Data"));
        get_layout().prop(attachment.fire, bxx::kwarg("text", "Fire"));
    }
}