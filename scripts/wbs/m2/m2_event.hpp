#pragma once

#include <bxx/classes/property_group.hpp>
#include <bxx/enums.hpp>

namespace wbs
{
    class m2_event: public bxx::property_group_class<m2_event>
    {
    public:
        std::vector<bxx::property_group_targets> targets() final;

        bxx::enum_property<
            /* TYPE           */ m2_event_type,
            /* NAME           */ "M2 Event Type",
            /* DEFAULT        */ m2_event_type::AttackHold,
            /* DESCRIPTION    */ "What type of event this is"
        >
        event_type;

        bxx::int_property<"Data", 0>
        data;

        bxx::bool_property<"Fire", false>
        fire;

        PROPERTY_GROUP(
            m2_event,
            PROPERTY_ENTRY(event_type),
            PROPERTY_ENTRY(data),
            PROPERTY_ENTRY(fire)
        )
    };
}