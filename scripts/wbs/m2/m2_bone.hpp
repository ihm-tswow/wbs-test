#pragma once

#include <bxx/classes/property_group.hpp>
#include <bxx/classes/panel_class.hpp>

namespace wbs
{
    enum class m2_key_bone
    {
        ArmL = 0,
        ArmR = 1,
        ShoulderL = 2,
        ShoulderR = 3,
        SpineLow = 4,
        Waist = 5,
        Head = 6,
        Jaw = 7,
        IndexFingerR = 8,
        MiddleFingerR = 9,
        PinkyFingerR = 10,
        RingFingerR = 11,
        ThumbR = 12,
        IndexFingerL = 13,
        MiddleFingerL = 14,
        PinkyFingerL = 15,
        RingFingerL = 16,
        ThumbL = 17,
        BTH = 18,
        CSR = 19,
        CSL = 20,
        Breath = 21,
        Name = 22,
        NameMount = 23,
        CHD = 24,
        CCH = 25,
        Root = 26,
        Wheel1 = 27,
        Wheel2 = 28,
        Wheel3 = 29,
        Wheel4 = 30,
        Wheel5 = 31,
        Wheel6 = 32,
        Wheel7 = 33,
        Wheel8 = 34,
        FaceAttenuation = 35,
        CapeParent = 36,
        CapeChild1 = 37,
        CapeChild2 = 38,
        CapeChild3 = 39,
        CapeChild4 = 40,
        TabardParent = 43,
        TabardChild1 = 44,
        TabardChild2 = 45,
        unk_head_top1 = 46,
        unk_head_top2 = 47,
        UpperBodyParent = 48,
        NeckParent = 49,
        NeckChild1 = 50,
        LowerBodyParent = 51,
        Buckle = 52,
        Chest = 53,
        Main = 54,
        LegR = 55,
        LegL = 56,
        KneeR = 57,
        KneeL = 58,
        FootL = 59,
        FootR = 60,
        ElbowR = 61,
        ElbowL = 62,
        Unk_ElbowL_Child = 63,
        HandR = 64,
        HandL = 65,
        WeaponR = 66,
        WeaponL = 67,
        Unk_WristL_Child = 68,
        Unk_WristR_Child = 69,
        KneeR_UpperRig = 70,
        KneeL_UpperRig = 71,
        ArmR_2 = 72,
        ArmL_2 = 73,
        ElbowR_UpperRig = 74,
        ElbowL_UpperRig = 75,
        ForearmR = 76,
        ForearmL = 77,
        WristR_UpperRig = 78,
        WristL_UpperRig = 79
    };
    bxx::enum_meta m2_key_bone_meta(m2_key_bone value);

    enum class m2_bone_flags
    {
        IGNORE_PARENT_TRANSLATE      = 0x1,
        IGNORE_PARENT_SCALE          = 0x2,
        IGNORE_PARENT_ROTATION       = 0x4,
        SPHERICAL_BILLBOARD          = 0x8,
        CYLINDRICAL_BILLBOARD_LOCK_X = 0x10,
        CYLINDRICAL_BILLBOARD_LOCK_Y = 0x20,
        CYLINDRICAL_BILLBOARD_LOCK_Z = 0x40,
        UNUSED_0                     = 0x80,
        UNUSED_1                     = 0x100,
        TRANSFORMED                  = 0x200,
        KINEMATIC_BONE               = 0x400,
        UNUSED_3                     = 0x800,
        HELMET_ANIM_SCALED           = 0x1000
    };
    bxx::enum_meta m2_bone_flags_meta(m2_bone_flags value);

    class m2_bone : public bxx::property_group_class<m2_bone>
    {
    public:
        bxx::enum_property<
            /* TYPE           */ m2_key_bone,
            /* NAME           */ "M2 Key Bone",
            /* DEFAULT        */ m2_key_bone::ArmL,
            /* DESCRIPTION    */ "Description",
            /* REPRESENTATION */ m2_key_bone_meta
        >
        key_bone;

        bxx::mask_property<
            /* TYPE           */ m2_bone_flags,
            /* NAME           */ "M2 Bone Flags",
            /* DESCRIPTION    */ "Description",
            /* REPRESENTATION */ m2_bone_flags_meta
        >
        flags;

        bxx::int_property<"Sort Index", -1>
        sort_index;

        bxx::int_property<"Submesh ID", 0, 0, 65535>
        submesh_id;

        bxx::int_property<"Bone Name CRC", 0>
        bone_name_crc;

        std::vector<bxx::property_group_targets> targets() final
        {
            return { bxx::property_group_targets::EditBone };
        }

        PROPERTY_GROUP(m2_bone
            , PROPERTY_ENTRY(key_bone)
            , PROPERTY_ENTRY(flags)
            , PROPERTY_ENTRY(sort_index)
            , PROPERTY_ENTRY(submesh_id)
            , PROPERTY_ENTRY(bone_name_crc)
        )
    };

    bool poll_m2_bone_panel(bxx::python_object cls, bxx::python_object ctx);

    class m2_bone_panel : public bxx::panel_class<
        m2_bone_panel,
        bxx::bl_context::bone,
        bxx::bl_space_type::PROPERTIES,
        bxx::bl_region_type::WINDOW,
        poll_m2_bone_panel
    >
    {
    public:
        void draw(python_object ctx) final;
        UI_CLASS(m2_bone_panel)
    };

    void register_m2_bones();
}
