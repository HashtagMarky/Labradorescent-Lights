.set LOCALID_IGNATIUS, 1
.set LOCALID_SNORLAX, 2

PetalburgClearingOBerryTreeScript::
    special ObjectEventInteractionGetBerryTreeData
	switch VAR_0x8004
	case BERRY_STAGE_SPARKLING, BerryTree_EventScript_Sparkling
	case BERRY_STAGE_NO_BERRY, BerryTree_EventScript_PetalburgCheckSoil
	case BERRY_STAGE_PLANTED, BerryTree_EventScript_CheckBerryStage1
	case BERRY_STAGE_SPROUTED, BerryTree_EventScript_CheckBerryStage2
	case BERRY_STAGE_TALLER, BerryTree_EventScript_CheckBerryStage3
	case BERRY_STAGE_FLOWERING, BerryTree_EventScript_CheckBerryStage4
	case BERRY_STAGE_BERRIES, PetalburgClearing_OBerryTree_EventScript_CheckBerryFullyGrown
	end

@ VAR_0x8006 here is the number of berries
PetalburgClearing_OBerryTree_EventScript_CheckBerryFullyGrown::
	buffernumberstring STR_VAR_2, VAR_0x8006
	lock
	faceplayer
	special ObjectEventInteractionGetBerryCountString
	msgbox BerryTree_Text_WantToPick, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgClearing_OBerryTree_EventScript_PickBerry
	goto_if_eq VAR_RESULT, NO, BerryTree_EventScript_CancelPickingBerry

PetalburgClearing_OBerryTree_EventScript_PickBerry::
	special ObjectEventInteractionPickBerryTree
	goto_if_eq VAR_0x8004, 0, BerryTree_EventScript_BerryPocketFull
	special IncrementDailyPickedBerries
	special ObjectEventInteractionRemoveBerryTree
	message BerryTree_Text_PickedTheBerry
    delay 10
	showberrydesc
	playfanfare MUS_OBTAIN_BERRY
    addvar VAR_TEMP_0, 1
	waitmessage
	waitfanfare
	waitbuttonpress
	message BerryTree_Text_PutAwayBerry
	waitmessage
	waitbuttonpress
    hideitemdesc
	release
	end

    PetalburgClearingPBerryTreeScript::
    special ObjectEventInteractionGetBerryTreeData
	switch VAR_0x8004
	case BERRY_STAGE_SPARKLING, BerryTree_EventScript_Sparkling
	case BERRY_STAGE_NO_BERRY, BerryTree_EventScript_PetalburgCheckSoil
	case BERRY_STAGE_PLANTED, BerryTree_EventScript_CheckBerryStage1
	case BERRY_STAGE_SPROUTED, BerryTree_EventScript_CheckBerryStage2
	case BERRY_STAGE_TALLER, BerryTree_EventScript_CheckBerryStage3
	case BERRY_STAGE_FLOWERING, BerryTree_EventScript_CheckBerryStage4
	case BERRY_STAGE_BERRIES, PetalburgClearing_PBerryTree_EventScript_CheckBerryFullyGrown
	end

@ VAR_0x8006 here is the number of berries
PetalburgClearing_PBerryTree_EventScript_CheckBerryFullyGrown::
	buffernumberstring STR_VAR_2, VAR_0x8006
	lock
	faceplayer
	special ObjectEventInteractionGetBerryCountString
	msgbox BerryTree_Text_WantToPick, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgClearing_PBerryTree_EventScript_PickBerry
	goto_if_eq VAR_RESULT, NO, BerryTree_EventScript_CancelPickingBerry

PetalburgClearing_PBerryTree_EventScript_PickBerry::
	special ObjectEventInteractionPickBerryTree
	goto_if_eq VAR_0x8004, 0, BerryTree_EventScript_BerryPocketFull
	special IncrementDailyPickedBerries
	special ObjectEventInteractionRemoveBerryTree
	message BerryTree_Text_PickedTheBerry
    delay 10
	showberrydesc
	playfanfare MUS_OBTAIN_BERRY
    addvar VAR_TEMP_0, 2
	waitmessage
	waitfanfare
	waitbuttonpress
    hideitemdesc
	message BerryTree_Text_PutAwayBerry
	waitmessage
	waitbuttonpress
	release
	end

PetalburgClearing_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgClearing_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

PetalburgClearing_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_1, 0, PetalburgClearing_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

PetalburgClearing_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	addvar VAR_TEMP_1, 1
	goto_if_unset FLAG_HIDE_SNORLAX, PetalburgClearing_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1
	end

PetalburgClearing_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1:
	getplayerxy VAR_TEMP_2, VAR_TEMP_3
	compare VAR_TEMP_2, 2
	goto_if_eq PetalburgClearing_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_4
	compare VAR_TEMP_2, 3
	goto_if_eq PetalburgClearing_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_5
	end

PetalburgClearing_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_4:
	applymovement OBJ_EVENT_ID_PLAYER, LeftTrigger
	goto PetalburgClearing_IgnatiusEntrance
	return

PetalburgClearing_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_5:
	applymovement OBJ_EVENT_ID_PLAYER, RightTrigger
	goto PetalburgClearing_IgnatiusEntrance
	return


BerryTree_EventScript_PetalburgCheckSoil::
	lock
	msgbox BerryTree_EventScript_PetalburgCheckSoil_Text_0, MSGBOX_DEFAULT
	release
	return


PetalburgClearing_LeftTrigger::
	lockall
	goto_if_set FLAG_HIDE_SNORLAX, PetalburgClearing_LeftTrigger_1
	applymovement OBJ_EVENT_ID_PLAYER, LeftTrigger
	waitmovement 0
	goto PetalburgClearing_IgnatiusEntrance
	return

PetalburgClearing_LeftTrigger_1:
	goto PetalburgClearing_ReturnToBerries
	return


PetalburgClearing_RightTrigger::
	lockall
	goto_if_set FLAG_HIDE_SNORLAX, PetalburgClearing_RightTrigger_1
	applymovement OBJ_EVENT_ID_PLAYER, RightTrigger
	waitmovement 0
	goto PetalburgClearing_IgnatiusEntrance
	return

PetalburgClearing_RightTrigger_1:
	goto PetalburgClearing_ReturnToBerries
	return


PetalburgClearing_IgnatiusEntrance::
	lockall
	applymovement LOCALID_IGNATIUS, HiddenEntrance
	waitmovement 0
	applymovement LOCALID_IGNATIUS, IgnatiusEntrance
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, FaceDown
	waitmovement 0
	msgbox PetalburgClearing_IgnatiusEntrance_Text_0, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_IGNATIUS, IgnatiusShowBerry
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, FaceUp
	waitmovement 0
	msgbox PetalburgClearing_IgnatiusEntrance_Text_1, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_SNORLAX
	releaseall
	return


PetalburgClearing_IgnatiusCollectBerries::
	compare VAR_LAB_LIGHTS, 1
	goto_if_eq PetalburgClearing_IgnatiusCollectBerries_1
	goto PetalburgClearing_Goodbye
	return

PetalburgClearing_IgnatiusCollectBerries_1:
	switch VAR_TEMP_0
	case 0, PetalburgClearing_IgnatiusCollectBerries_5
	case 1, PetalburgClearing_IgnatiusCollectBerries_6
	case 2, PetalburgClearing_IgnatiusCollectBerries_7
	case 3, PetalburgClearing_IgnatiusCollectBerries_8
	return

PetalburgClearing_IgnatiusCollectBerries_5:
	msgbox PetalburgClearing_IgnatiusCollectBerries_Text_0, MSGBOX_NPC
	applymovement LOCALID_IGNATIUS, FaceUp
	waitmovement 0
	return

PetalburgClearing_IgnatiusCollectBerries_6:
	msgbox PetalburgClearing_IgnatiusCollectBerries_Text_1, MSGBOX_NPC
	applymovement LOCALID_IGNATIUS, FaceUp
	waitmovement 0
	return

PetalburgClearing_IgnatiusCollectBerries_7:
	msgbox PetalburgClearing_IgnatiusCollectBerries_Text_2, MSGBOX_NPC
	applymovement LOCALID_IGNATIUS, FaceUp
	waitmovement 0
	return

PetalburgClearing_IgnatiusCollectBerries_8:
	lock
	faceplayer
	removeitem ITEM_ORAN_BERRY, 1
	removeitem ITEM_PECHA_BERRY, 1
	msgbox PetalburgClearing_IgnatiusCollectBerries_Text_3, MSGBOX_DEFAULT
	msgbox PetalburgClearing_IgnatiusCollectBerries_Text_4, MSGBOX_SIGN
	fadescreen 1
	clearflag FLAG_HIDE_SNORLAX
	showobjectat LOCALID_SNORLAX, MAP_PETALBURG_CLEARING
	playse SE_M_SNORE
	specialvar VAR_RESULT, GetPlayerFacingDirection
	compare VAR_RESULT, DIR_SOUTH
	goto_if_eq PetalburgClearing_IgnatiusCollectBerries_10
	compare VAR_RESULT, DIR_EAST
	goto_if_eq PetalburgClearing_IgnatiusCollectBerries_11
	applymovement OBJ_EVENT_ID_PLAYER, WalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, FaceRight
	waitmovement 0
	applymovement LOCALID_SNORLAX, HiddenEntrance
	waitmovement 0
PetalburgClearing_IgnatiusCollectBerries_9:
	applymovement LOCALID_IGNATIUS, IgnatiusMakeBerry
	waitmovement 0
	clearflag FLAG_HIDE_SNORLAX
	showobjectat LOCALID_SNORLAX, MAP_PETALBURG_CLEARING
	waitse
	fadescreen 0
	goto PetalburgClearing_Smoothie
	return

PetalburgClearing_IgnatiusCollectBerries_10:
	applymovement OBJ_EVENT_ID_PLAYER, WalkRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, WalkDown
	waitmovement 0
	clearflag FLAG_HIDE_SNORLAX
	showobjectat LOCALID_SNORLAX, MAP_PETALBURG_CLEARING
	applymovement LOCALID_SNORLAX, HiddenEntrance
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, WalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, FaceRight
	waitmovement 0
	goto PetalburgClearing_IgnatiusCollectBerries_9

PetalburgClearing_IgnatiusCollectBerries_11:
	applymovement OBJ_EVENT_ID_PLAYER, WalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, FaceRight
	waitmovement 0
	applymovement LOCALID_SNORLAX, HiddenEntrance
	waitmovement 0
	goto PetalburgClearing_IgnatiusCollectBerries_9


PetalburgClearing_ReturnToBerries::
	applymovement LOCALID_IGNATIUS, FaceLeft
	waitmovement 0
	msgbox PetalburgClearing_ReturnToBerries_Text_0, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_IGNATIUS, FaceUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, WalkUp
	waitmovement 0
	releaseall
	return


PetalburgClearing_Smoothie::
	msgbox PetalburgClearing_Smoothie_Text_0, MSGBOX_NPC
	delay 60
	playmoncry SPECIES_SNORLAX, 0
	msgbox PetalburgClearing_Smoothie_Text_1, MSGBOX_AUTOCLOSE
	waitmoncry
	applymovement OBJ_EVENT_ID_PLAYER, FaceLeft
	waitmovement 0
	applymovement LOCALID_SNORLAX, SnorlaxEntrance
	waitmovement 0
	msgbox PetalburgClearing_Smoothie_Text_2, MSGBOX_DEFAULT
	goto PetalburgClearing_SnorlaxAndIgnatius
	return


PetalburgClearing_SnorlaxAndIgnatius::
	lockall
	playmoncry SPECIES_SNORLAX, 0
	msgbox PetalburgClearing_Smoothie_Text_1, MSGBOX_AUTOCLOSE
	applymovement LOCALID_SNORLAX, GoToIgnatiusP1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, FaceRight
	applymovement LOCALID_SNORLAX, GoToIgnatiusP2
	waitmovement 0
	applymovement LOCALID_IGNATIUS, FaceUp
	waitmovement 0
	waitmoncry
	msgbox PetalburgClearing_SnorlaxAndIgnatius_Text_0, MSGBOX_DEFAULT
	playmoncry SPECIES_SNORLAX, 0
	msgbox PetalburgClearing_SnorlaxAndIgnatius_Text_1, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	delay 30
	applymovement LOCALID_IGNATIUS, FaceLeft
	waitmovement 0
	delay 30
	applymovement LOCALID_IGNATIUS, FaceDown
	waitmovement 0
	delay 30
	applymovement LOCALID_IGNATIUS, FaceLeft
	waitmovement 0
	delay 30
	applymovement LOCALID_IGNATIUS, FaceUp
	waitmovement 0
	delay 30
	msgbox PetalburgClearing_SnorlaxAndIgnatius_Text_2, MSGBOX_DEFAULT
	applymovement LOCALID_IGNATIUS, FaceLeft
	waitmovement 0
	msgbox PetalburgClearing_SnorlaxAndIgnatius_Text_3, MSGBOX_DEFAULT
	applymovement LOCALID_SNORLAX, FaceLeft
	waitmovement 0
	playmoncry SPECIES_SNORLAX, 0
	msgbox PetalburgClearing_Smoothie_Text_1, MSGBOX_DEFAULT
	waitmoncry
	msgbox PetalburgClearing_SnorlaxAndIgnatius_Text_4, MSGBOX_YESNO
PetalburgClearing_SnorlaxAndIgnatius_2:
	compare VAR_RESULT, 1
	goto_if_ne PetalburgClearing_SnorlaxAndIgnatius_3
	playmoncry SPECIES_SNORLAX, 0
	msgbox PetalburgClearing_Smoothie_Text_1, MSGBOX_DEFAULT
	waitmoncry
	goto PetalburgClearing_GiveEgg
	return

PetalburgClearing_SnorlaxAndIgnatius_3:
	playmoncry SPECIES_SNORLAX, 0
	msgbox PetalburgClearing_SnorlaxAndIgnatius_Text_1, MSGBOX_DEFAULT
	waitmoncry
	msgbox PetalburgClearing_SnorlaxAndIgnatius_Text_5, MSGBOX_YESNO
	goto PetalburgClearing_SnorlaxAndIgnatius_2


PetalburgClearing_GiveEgg::
	lockall
	msgbox PetalburgClearing_GiveEgg_Text_0, MSGBOX_DEFAULT
	getpartysize
	compare VAR_RESULT, 6
	goto_if_eq PetalburgClearing_GiveEgg_2
	playfanfare MUS_OBTAIN_ITEM
	msgbox PetalburgClearing_GiveEgg_Text_2, MSGBOX_DEFAULT
PetalburgClearing_GiveEgg_1:
	giveegg SPECIES_MUNCHLAX
	clearflag FLAG_SHINY_CREATION
	waitfanfare
	releaseall
	goto PetalburgClearing_GiveLeftovers
	return

PetalburgClearing_GiveEgg_2:
	msgbox PetalburgClearing_GiveEgg_Text_1, MSGBOX_DEFAULT
	goto PetalburgClearing_GiveEgg_1


PetalburgClearing_GiveLeftovers::
	lockall
	completequest FATHERS_REST
	applymovement LOCALID_SNORLAX, GiveLeftovers
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, FaceUp
	waitmovement 0
	msgbox PetalburgClearing_Smoothie_Text_1, MSGBOX_DEFAULT
	giveitem ITEM_LEFTOVERS, 1
	compare VAR_RESULT, 0
	goto_if_eq PetalburgClearing_GiveLeftovers_2
PetalburgClearing_GiveLeftovers_1:
	setvar VAR_RESULT, 0
	goto PetalburgClearing_Goodbye
	return

PetalburgClearing_GiveLeftovers_2:
	goto NoRoomLeftovers
	goto PetalburgClearing_GiveLeftovers_1


NoRoomLeftovers::
	message NoRoomLeftovers_Text_0
	goto PetalburgClearing_Goodbye
	return


PetalburgClearing_Goodbye::
	lockall
	msgbox PetalburgClearing_Goodbye_Text_0, MSGBOX_DEFAULT
	playmoncry SPECIES_SNORLAX, 0
	msgbox PetalburgClearing_Smoothie_Text_1, MSGBOX_DEFAULT
	closemessage
	waitmoncry
	setvar VAR_LAB_LIGHTS, 0
	setflag FLAG_HIDE_SNORLAX
	releaseall
	return


PetalburgClearing_SnorlaxCry::
	lock
	playmoncry SPECIES_SNORLAX, 0
	msgbox PetalburgClearing_Smoothie_Text_1, MSGBOX_NPC
	waitmoncry
	release
	return


GiveLeftovers:
	walk_left
	walk_left
	face_down
	step_end

WalkUpAndRight:
	walk_fast_up
	walk_fast_right
	step_end

WalkUpAndLeft:
	walk_fast_up
	walk_fast_left
	face_right
	step_end

IgnatiusLookAround:
	face_left
	face_down
	face_up
	step_end

LeftTrigger:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	face_left
	step_end

RightTrigger:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	face_left
	step_end

HiddenEntrance:
	walk_fast_up
	walk_fast_up
	step_end

IgnatiusEntrance:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	face_up
	step_end

MoveLeftFaceUp:
	walk_left
	face_up
	step_end

IgnatiusShowBerry:
	walk_left
	walk_left
	face_up
	step_end

IgnatiusMakeBerry:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	face_left
	step_end

ReturnToSpot:
	walk_fast_down
	face_right
	step_end

SnorlaxEntrance:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_right
	step_end

GoToIgnatiusP1:
	walk_right
	walk_right
	walk_right
	step_end

GoToIgnatiusP2:
	walk_right
	walk_right
	face_down
	step_end

BerryTree_EventScript_PetalburgCheckSoil_Text_0:
	.string "BERRIES cannot be regrown in\nPETALBURG CLEARING.$"

PetalburgClearing_IgnatiusEntrance_Text_0:
	.string "PROF. IGNATIUS: Here we are!\n"
	.string "Welcombe to a lesser known spot,\l"
	.string "PETALBURG CLEARING.\p"
	.string "I've set up an area for us to make some\n"
	.string "food. And honestly, that sums up the\l"
	.string "plan to awaken my SNORLAX.\p"
	.string "He adores the sweet taste of a\n"
	.string "smoothie made from PECHA BERRIES,\l"
	.string "so the trees ahead will be very useful.$"

PetalburgClearing_IgnatiusEntrance_Text_1:
	.string "Pick some PECHA and ORAN BERRIES, and\n"
	.string "bring them to me.\p"
	.string "I'm sure the smell of the crushed\n"
	.string "berries will do just the trick!$"

PetalburgClearing_IgnatiusCollectBerries_Text_0:
	.string "PROF. IGNATIUS: Pick some PECHA and\n"
	.string "ORAN BERRIES, and bring them to me.\l"
	.string "I'm sure SNORLAX will love them!$"

PetalburgClearing_IgnatiusCollectBerries_Text_1:
	.string "PROF. IGNATIUS: That's a great start,\n"
	.string "can you also pick some PECHA BERRIES.$"

PetalburgClearing_IgnatiusCollectBerries_Text_2:
	.string "PROF. IGNATIUS: That's a great start,\n"
	.string "can you also pick some ORAN BERRIES.$"

PetalburgClearing_IgnatiusCollectBerries_Text_3:
	.string "PROF. IGNATIUS: Thank you, {PLAYER}!\p"
	.string "BERRIES can be picked all over HOENN.\n"
	.string "More will grow if you replant them,\l"
	.string "but you can't in PETALBURG CLEARING.\p"
	.string "Now just hold on, and I'll get started on\n"
	.string "making this smoothie.$"

PetalburgClearing_IgnatiusCollectBerries_Text_4:
	.string "{PLAYER} handed PROF. IGNATIUS the\n"
	.string "BERRIES.$"

PetalburgClearing_ReturnToBerries_Text_0:
	.string "PROF. IGNATIUS: {PLAYER}!\n"
	.string "Don't leave yet, we're almost done!$"

PetalburgClearing_Smoothie_Text_0:
	.string "PROF. IGNATIUS: Consider this,\n"
	.string "a delicious smoothie!\p"
	.string "Let's see if my dear SNORLAX would like\n"
	.string "to wake up and try some.$"

PetalburgClearing_Smoothie_Text_1:
	.string "SNORLAX: Snorr!$"

PetalburgClearing_Smoothie_Text_2:
	.string "PROF. IGNATIUS: Wow!\n"
	.string "It seems like the scent attracted\l"
	.string "SNORLAX all the way from here.$"

PetalburgClearing_SnorlaxAndIgnatius_Text_0:
	.string "PROF. IGNATIUS: My dear friend,\n"
	.string "why would you run away from me?$"

PetalburgClearing_SnorlaxAndIgnatius_Text_1:
	.string "SNORLAX: Snorr…$"

PetalburgClearing_SnorlaxAndIgnatius_Text_2:
	.string "PROF. IGNATIUS: Oh…\n"
	.string "Really?\l"
	.string "My friend, I am so sorry.\n"
	.string "You didn't have to do all of that.\n"
	.string "I would've happily helped you.\p"
	.string "No amount of research could be more\n"
	.string "important than this.$"

PetalburgClearing_SnorlaxAndIgnatius_Text_3:
	.string "SNORLAX says that he came into\n"
	.string "PETALBURG WOODS because he found\l"
	.string "a POKéMON EGG!\p"
	.string "He was worried that raising a POKéMON\n"
	.string "would interfere with the research we\l"
	.string "are doing alongside my team.$"

PetalburgClearing_SnorlaxAndIgnatius_Text_4:
	.string "PROF. IGNATIUS: {PLAYER}!\n"
	.string "He's asking for your help!\l"
	.string "Can you raise his POKéMON EGG?$"

PetalburgClearing_SnorlaxAndIgnatius_Text_5:
	.string "PROF. IGNATIUS: Are you sure?\n"
	.string "He's asking for your help!\l"
	.string "Can you raise his POKéMON EGG?$"

PetalburgClearing_GiveEgg_Text_0:
	.string "PROF. IGNATIUS: Really and truly?\n"
	.string "My SNORLAX is overjoyed!\l"
	.string "He's so glad that you'll help him!$"

PetalburgClearing_GiveEgg_Text_1:
	.string "You have no room in your party.\nSNORLAX's EGG has been sent to your PC.$"

PetalburgClearing_GiveEgg_Text_2:
	.string "{PLAYER} received SNORLAX's EGG!$"

NoRoomLeftovers_Text_0:
	.string "You have no room for SNORLAX's\n"
	.string "LEFTOVERS.$"

PetalburgClearing_Goodbye_Text_0:
	.string "PROF. IGNATIUS: Thank you {PLAYER}!\n"
	.string "Thank you from the both of us,\l"
	.string "I know you'll take good care of it.$"
