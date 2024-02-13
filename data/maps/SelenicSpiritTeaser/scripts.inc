SelenicSpiritTeaser_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SelenicSpiritTeaser_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SelenicSpiritTeaser_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SelenicSpiritTeaser_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
	map_script_2 VAR_TEMP_1, 0, SelenicSpiritTeaser_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

SelenicSpiritTeaser_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
	call TeaserTwo_Hide_Objects
	return

SelenicSpiritTeaser_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_RESULT, 2, SelenicSpiritTeaser_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

SelenicSpiritTeaser_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	call TeaserTwo_Setup
	call TeaserTwo
	return


TeaserTwo_Hide_Objects::
	applymovement OBJ_EVENT_ID_PLAYER, Invisible
	return


TeaserTwo_Setup::
	special SpawnCameraObject
	return


TeaserTwo::
	setvar VAR_RESULT, 0
	call TeaserTwo_Entrance
	call TeaserTwo_Conversation
	call TeaserTwo_CameraPanToBlack
	call TeaserTwo_CameraPanToOriginal
	goto TeaserTwo_End
	return


TeaserTwo_Entrance::
	applymovement 1, LaurenPace
	applymovement 2, SelenicEntrance
	delay 30
	applymovement OBJ_EVENT_ID_CAMERA, CameraPan_PartOne
	delay 165
	applymovement OBJ_EVENT_ID_CAMERA, CameraPan_PartTwo
	waitmovement 2
	waitmovement 1
	return


TeaserTwo_Conversation::
	applymovement 1, LaurenSurprise
	cutscenebox TeaserTwo_Conversation_Text_0
	cutscenebox TeaserTwo_Conversation_Text_1
	cutscenebox TeaserTwo_Conversation_Text_2
	cutscenebox TeaserTwo_Conversation_Text_3
	call TeaserTwo_PartnerCry
	cutscenebox TeaserTwo_Conversation_Text_4
	cutscenebox TeaserTwo_Conversation_Text_5
	cutscenebox TeaserTwo_Conversation_Text_6
	call TeaserTwo_PartnerCry
	cutscenebox TeaserTwo_Conversation_Text_7
	cutscenebox TeaserTwo_Conversation_Text_8
	return


TeaserTwo_End::
	goto_if_set FLAG_SYS_RELEASE_VERSION, TeaserTwo_End_1
	goto TeaserTwo_Restart
	return

TeaserTwo_End_1:
	initclock VAR_0x8000, VAR_0x8001
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq TeaserTwo_End_4
	warpsilent MAP_BOREA_GLADE_MAYS_HOUSE_2F, 5, 3
	waitstate
	releaseall
	return

TeaserTwo_End_4:
	warpsilent MAP_BOREA_GLADE_BRENDANS_HOUSE_2F, 3, 3
	waitstate
	releaseall
	return


TeaserTwo_Restart::
	goto BeginTeaser_TeaserTwo
	return


TeaserTwo_PartnerCry::
	compare VAR_TEMP_0, 0
	goto_if_eq TeaserTwo_PartnerCry_2
	compare VAR_TEMP_0, 1
	goto_if_eq TeaserTwo_PartnerCry_3
TeaserTwo_PartnerCry_1:
	applymovement 2, SamuelCry
	applymovement 1, LaurenCry
	waitmovement 0
	waitmoncry
	return

TeaserTwo_PartnerCry_2:
	playmoncry SPECIES_INFERNAPE, 0
	addvar VAR_TEMP_0, 1
	goto TeaserTwo_PartnerCry_1

TeaserTwo_PartnerCry_3:
	playmoncry SPECIES_DIANCIE, 0
	goto TeaserTwo_PartnerCry_1


TeaserTwo_CameraPanToBlack::
	applymovement OBJ_EVENT_ID_CAMERA, Teaser_CameraPanUpAndAway
	fadescreenspeed FADE_TO_BLACK, 8
	waitmovement 0
	return


TeaserTwo_CameraPanToOriginal::
	applymovement OBJ_EVENT_ID_CAMERA, TeaserTwo_CameraDisable
	waitmovement 0
	special RemoveCameraObject
	return


LaurenPace:
	walk_left
	walk_left
	walk_in_place_up
	walk_in_place_left
	walk_right
	walk_right
	walk_in_place_up
	walk_in_place_down
	walk_left
	walk_in_place_up
	walk_left
	walk_in_place_down
	walk_in_place_left
	walk_right
	walk_right
	walk_in_place_left
	walk_in_place_left
	walk_in_place_right
	walk_in_place_right
	step_end

CameraPan_PartOne:
	walk_up
	walk_up
	step_end

CameraPan_PartTwo:
	walk_right
	walk_right
	step_end

LaurenSurprise:
	face_down
	emote_question_mark
	step_end

SamuelCry:
	walk_in_place_up
	walk_in_place_up
	walk_in_place_up
	walk_in_place_up
	step_end

LaurenCry:
	jump_in_place_down
	jump_in_place_down
	step_end

TeaserTwo_CameraDisable:
	walk_faster_down
	walk_faster_down
	walk_faster_left
	walk_faster_left
	step_end

TeaserTwo_Conversation_Text_0:
	.string "LAUREN: Well this is a surprise.\n"
	.string "What are you doing here, my love?$"

TeaserTwo_Conversation_Text_1:
	.string "SAMUEL: We finished setting up,\n"
	.string "then we decided to check on you.$"

TeaserTwo_Conversation_Text_2:
	.string "LAUREN: How is it looking over there?\n"
	.string "Were our partners helpful?$"

TeaserTwo_Conversation_Text_3:
	.string "SAMUEL: Yours more than mine.\n"
	.string "Someone was far too conceited to help.$"

TeaserTwo_Conversation_Text_4:
	.string "LAUREN: I'm glad someone was helpful.\n"
	.string "I've done as much as I can today.$"

TeaserTwo_Conversation_Text_5:
	.string "SAMUEL: Awesome. I'm so proud of\n"
	.string "everything that you're doing here.$"

TeaserTwo_Conversation_Text_6:
	.string "LAUREN: Now that we've finished, all\n"
	.string "four of us should head back home.$"

TeaserTwo_Conversation_Text_7:
	.string "SAMUEL: We should, but we'll all be\n"
	.string "back soon. After our move that is.$"

TeaserTwo_Conversation_Text_8:
	.string "LAUREN: Come on, let's save the\n"
	.string "baby-sitter from the little terror.$"
