from enum import Enum

class m2_event_type(Enum):
    CustomAttack1 = '$AH0'
    PlaySoundKitCustomAttack2 = '$AH1'
    PlaySoundKitCustomAttack3 = '$AH2'
    PlaySoundKitCustomAttack4 = '$AH3'

    BowMissleDestination = "$BMD"
    MissileFirePos = '$AIM'
    DisplayTransition = '$ALT'

    FootstepLeftBackwards1 = '$BL0'
    FootstepLeftBackwards2 = '$BL1'
    FootstepLeftBackwards3 = '$BL2'
    FootstepLeftBackwards4 = '$BL3'
    FootstepRightBackwards1 = '$BR0'
    FootstepRightBackwards2 = '$BR1'
    FootstepRightBackwards3 = '$BR2'
    FootstepRightBackwards4 = '$BR3'

    FootstepLeftForward1 = '$FL0'
    FootstepLeftForward2 = '$FL1'
    FootstepLeftForward3 = '$FL2'
    FootstepLeftForward4 = '$FL3'
    FootstepRightForward1 = '$FR0'
    FootstepRightForward2 = '$FR1'
    FootstepRightForward3 = '$FR2'
    FootstepRightForward4 = '$FR3'

    FootstepLeftRunning1 = '$RL0'
    FootstepLeftRunning2 = '$RL1'
    FootstepLeftRunning3 = '$RL2'
    FootstepLeftRunning4 = '$RL3'
    FootstepRightRunning1 = '$RR0'
    FootstepRightRunning2 = '$RR1'
    FootstepRightRunning3 = '$RR2'
    FootstepRightRunning4 = '$RR3'

    FootstepLeftStop1 = '$SL0'
    FootstepLeftStop2 = '$SL1'
    FootstepLeftStop3 = '$SL2'
    FootstepLeftStop4 = '$SL3'
    FootstepRightStop1 = '$SR0'
    FootstepRightStop2 = '$SR1'
    FootstepRightStop3 = '$SR2'
    FootstepRightStop4 = '$SR3'

    FootstepLeftWalk1 = '$WL0'
    FootstepLeftWalk2 = '$WL1'
    FootstepLeftWalk3 = '$WL2'
    FootstepLeftWalk4 = '$WL3'

    FootstepRightWalk1 = '$WR0'
    FootstepRightWalk2 = '$WR1'
    FootstepRightWalk3 = '$WR2'
    FootstepRightWalk4 = '$WR3'

    PlaySoundKitBirth = '$BRT'                                  # soundEffect ID is defined by CreatureSoundDatarec::m_birthSoundID
    Breath = '$BTH'                                             # All situations, where nothing happens or breathing.
    PlayRangedItemPull = '$BWP'                                 # LoadRifle, LoadBow
    BowRelease = '$BWR'                                         # AttackRifle, AttackBow, AttackThrown
    AttackHold = '$CAH'                                          # Attack*, *Unarmed, ShieldBash, Special*
    AttackThrown = '$CCH'                                       # CEffect::DrawFishingString needs this on the model for getting the string attachments.
    UpdateMountHeightOrOffset = '$CFM'                          # CGCamera::UpdateMountHeightOrOffset: Only z is used. Non-animated. Not used if $CMA
    Unknown1 = '$CHD'                                           # Does not exist?
    CameraPosition = '$CMA'
    PlayCombatActionAnimKit = '$CPP'                            # parry, anims, depending on some state, also some callback which might do more
    PlayEmoteSound = '$CSD'                                     # data: soundEntryId
    ReleaseMissilesLeft = '$CSL'                                # AttackRifle, SpellCast*, ChannelCast
    ReleaseMissilesRight = '$CSR'                               # AttackBow, AttackRifle, AttackThrown, SpellCast*, ChannelCast*
    PlayWeaponSwooshSound = '$CSS'
    ReleaseMissiles = '$CST'                                    # SpellCast, Parry*, EmoteEat, EmoteRoar, Kick, ...
    PlaySoundEntryAdvanced = '$CVS'                             # Data: SoundEntriesAdvanced.dbc, Sound — Not present in 6.0.1.18179
    DestroyEmitter = '$DSE'
    DoodadSoundUnknown = '$DSL'                                 # Gameobjects,  data: soundEntryId
    DoodadSoundOneShot = '$DSO'                                 # data: soundEntryId
    Death = '$DTH'                                              # DeathThud + LootEffect,
    ObjectPackageEnterState2 = '$EWT'
    ObjectPackageEnterState3 = '$EAC'
    ObjectPackageEnterState4 = '$EMV'
    ObjectPackageEnterState5 = '$EDC'

    PlayEmoteStateSound = '$ESD'

    # CreatureSoundDataRec::m_soundFidget (only has 5 entries, so don’t use 6-9) # TODO: scan client if 6-9 are used
    PlayFidgetSound1 = '$FD1'
    PlayFidgetSound2 = '$FD2'
    PlayFidgetSound3 = '$FD3'
    PlayFidgetSound4 = '$FD4'
    PlayFidgetSound5 = '$FD5'

    PlayUnitSound = '$FDX'                                      # soundEffect ID is defined by CreatureSoundDataRec::m_soundStandID. Stand.
    HandleFootfallAnimEvent = '$FSD'                            # Plays some sound. Footstep? Also seen at several emotes etc. where feet are moved. CGUnit_C::HandleFootfallAnimEvent

    GOPlayAnimatedSoundCustom1 = '$GC0'
    GOPlayAnimatedSoundCustom2 = '$GC1'
    GOPlayAnimatedSoundCustom3 = '$GC2'
    GOPlayAnimatedSoundCustom4 = '$GC3'
    GOPlayAnimatedSound1 = '$GO0'
    GOPlayAnimatedSound2 = '$GO1'
    GOPlayAnimatedSound3 = '$GO2'
    GOPlayAnimatedSound4 = '$GO3'
    PlayWoundAnimKit = '$HIT'                                   # Attack*, *Unarmed, ShieldBash, Special*, soundEntryId depends on SpellVisualKit
    MapLoadUnknown = '$KVS'                                     # MapLoad.cpp -- not found in 6.0.1.18179

    SpellCastDirectedSound = '$SCD'                             # soundEffect ID is defined by CreatureSoundDataRec::m_spellCastDirectedSoundID
    GOAddShake = '$SHK'                                         # data: spellEffectCameraShakesID
    ExchangeSheathedWeaponLeft = '$SHL'                         # Sheath, HipSheath
    ExchangeSheathedWeaponRight = '$SHR'                        # Sheath, HipSheath

    PlaySoundKitSubmerged = '$SMD'                              # soundEffect ID is defined by CreatureSoundDatarec::m_submergedSoundID
    PlaySoundKitSubmerge = '$SMG'                               # soundEffect ID is defined by CreatureSoundDatarec::m_submergeSoundID
    GOPlaySoundKitCustom = '$SND'
    MountTransitionObjectE = '$STE'                             # Not seen in 6.0.1.18179 -- x is {E and B} , sequence time is taken of both, pivot of $STB. (Also, attachment info for attachment 0)
    MountTransitionObjectB = '$STB'
    HandleSpellEventSound = '$TRD'                              # EmoteWork*, UseStanding*, soundEffect ID is implicit by SpellRec

    HandleBoneAnimGrabEvent1 = '$VG0'
    HandleBoneAnimGrabEvent2 = '$VG1'
    HandleBoneAnimGrabEvent3 = '$VG2'
    HandleBoneAnimGrabEvent4 = '$VG3'
    HandleBoneAnimGrabEvent5 = '$VG4'
    HandleBoneAnimGrabEvent6 = '$VG5'
    HandleBoneAnimGrabEvent7 = '$VG6'
    HandleBoneAnimGrabEvent8 = '$VG7'
    HandleBoneAnimGrabEvent9 = '$VG8'

    HandleBoneAnimThrowEvent1 = '$VT0'
    HandleBoneAnimThrowEvent2 = '$VT1'
    HandleBoneAnimThrowEvent3 = '$VT2'
    HandleBoneAnimThrowEvent4 = '$VT3'
    HandleBoneAnimThrowEvent5 = '$VT4'
    HandleBoneAnimThrowEvent6 = '$VT5'
    HandleBoneAnimThrowEvent7 = '$VT6'
    HandleBoneAnimThrowEvent8 = '$VT7'
    HandleBoneAnimThrowEvent9 = '$VT8'

    PlayUnitSoundWingGlide = '$WGG'
    PlayUnitSoundWingFlap = '$WNG'
    WeaponTrailBottomPos = '$WTB'
    WeaponTrailTopPos = '$WTT'
    Unknown2 = '$WWG'                                           # Calls some function in the Object VMT. -- Not seen in 6.0.1.18179
    ExploadBallista = 'DEST'
    Unknown3 = 'POIN'
    Unknown4 = 'WHEE'                                           # Data: 601+, Used on wheels at vehicles.
    Unknown5 = 'BOTT'                                           # seen in well_vortex01.m2
    Unknown6 = 'TOP'                                            # seen in well_vortex01.m2
    Unknown7 = '$BWA'
    Unknown8 = '$BWS'