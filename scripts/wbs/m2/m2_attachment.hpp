#pragma once

#include <bxx/classes/property_group.hpp>

namespace wbs
{
    enum class m2_attachment_type
    {
        Shield_MountMain_ItemVisual0 = 0,
        HandRight_ItemVisual1 = 1,
        HandLeft_ItemVisual2 = 2,
        ElbowRight_ItemVisual3 = 3,
        ElbowLeft_ItemVisual4 = 4,
        ShoulderRight = 5,
        ShoulderLeft = 6,
        KneeRight = 7,
        KneeLeft = 8,
        HipRight = 9,
        HipLeft = 10,
        Helm = 11,
        Back = 12,
        ShoulderFlapRight = 13,
        ShoulderFlapLeft = 14,
        ChestBloodFront = 15,
        ChestBloodBack = 16,
        Breath = 17,
        PlayerName = 18,
        Base = 19,
        Head = 20,
        SpellLeftHand = 21,
        SpellRightHand = 22,
        Special1 = 23,
        Special2 = 24,
        Special3 = 25,
        SheathMainHand = 26,
        SheathOffHand = 27,
        SheathShield = 28,
        PlayerNameMounted = 29,
        LargeWeaponLeft = 30,
        LargeWeaponRight = 31,
        HipWeaponLeft = 32,
        HipWeaponRight = 33,
        Chest = 34,
        HandArrow = 35,
        Bullet = 36,
        SpellHandOmni = 37,
        SpellHandDirected = 38,
        VehicleSeat1 = 39,
        VehicleSeat2 = 40,
        VehicleSeat3 = 41,
        VehicleSeat4 = 42,
        VehicleSeat5 = 43,
        VehicleSeat6 = 44,
        VehicleSeat7 = 45,
        VehicleSeat8 = 46,
        LeftFoot = 47,
        RightFoot = 48,
        ShieldNoGlove = 49,
        SpineLow = 50,
        AlteredShoulderR = 51,
        AlteredShoulderL = 52,
        BeltBuckle = 53,
        SheathCrossbow = 54,
        HeadTop = 55,
        Backpack = 57,
        Unknown = 58,
    };

    bxx::enum_meta m2_attachment_meta(m2_attachment_type value);

    class m2_attachment: public bxx::property_group_class<m2_attachment>
    {
    public:
        std::vector<bxx::property_group_targets> targets() final;

        bxx::enum_property<
            /* TYPE           */ m2_attachment_type,
            /* NAME           */ "Attachment Type",
            /* DEFAULT        */ m2_attachment_type::Chest,
            /* DESCRIPTION    */ "What type of attachment this point should count as",
            /* REPRESENTATION */ m2_attachment_meta
        >
        attachment_type;

        bxx::bool_property<"Animate", true>
        animate;

        PROPERTY_GROUP(
            m2_attachment,
            PROPERTY_ENTRY(attachment_type),
            PROPERTY_ENTRY(animate)
        )
    };
}