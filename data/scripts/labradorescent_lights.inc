BeginTeaser_TeaserOne::
	gettime
	initclock 19, 00
	setvar VAR_RESULT, 1
	warpsilent MAP_BOREA_GLADE_TEASER, 6, 19
	waitstate
	releaseall
	return


FaceUp:
	face_up
	step_end

FaceDown:
	face_down
	step_end

FaceLeft:
	face_left
	step_end

FaceRight:
	face_right
	step_end

WalkUp:
	walk_up
	step_end

WalkDown:
	walk_down
	step_end

WalkLeft:
	walk_left
	step_end

WalkRight:
	walk_right
	step_end

Invisible:
	set_invisible
	step_end

Visible:
	set_visible
	step_end

JumpIPUp:
	jump_in_place_up
	step_end

JumpIPDown:
	jump_in_place_down
	step_end

JumpIPLeft:
	jump_in_place_left
	step_end

JumpIPRight:
	jump_in_place_right
	step_end

TruckFacingDirection::
	applymovement OBJ_EVENT_ID_PLAYER, FaceRight
	return


PlayerReturnToLastPosition::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	compare VAR_RESULT, DIR_NORTH
	goto_if_eq PlayerReturnToLastPosition_1
	compare VAR_RESULT, DIR_EAST
	goto_if_eq PlayerReturnToLastPosition_2
	compare VAR_RESULT, DIR_SOUTH
	goto_if_eq PlayerReturnToLastPosition_3
	compare VAR_RESULT, DIR_WEST
	goto_if_eq PlayerReturnToLastPosition_4
	return

PlayerReturnToLastPosition_1:
	applymovement OBJ_EVENT_ID_PLAYER, WalkDown
	waitmovement 0
	return

PlayerReturnToLastPosition_2:
	applymovement OBJ_EVENT_ID_PLAYER, WalkLeft
	waitmovement 0
	return

PlayerReturnToLastPosition_3:
	applymovement OBJ_EVENT_ID_PLAYER, WalkUp
	waitmovement 0
	return

PlayerReturnToLastPosition_4:
	applymovement OBJ_EVENT_ID_PLAYER, WalkRight
	waitmovement 0
	return


Exclaim:
	emote_exclamation_mark
	step_end

Question:
	emote_question_mark
	step_end

Heart:
	emote_heart
	step_end

Talk:
	step_end

Think:
	step_end

DemoBegin::
	lock
	msgbox DemoBegin_Text_0, MSGBOX_DEFAULT
	closemessage
	release
	return


DemoEnd::
	lockall
	fadenewbgm MUS_DP_POKEMON_LEAGUE_NIGHT
	delay 30
	closemessage
	delay 30
	msgbox DemoEnd_Text_0, MSGBOX_DEFAULT
	waitmessage
	delay 30
	fadescreen FADE_TO_WHITE
	delay 60
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, WalkDown
	waitmovement 0
	msgbox DemoEnd_Text_1, MSGBOX_DEFAULT
	waitmessage
	closemessage
	fadeoutbgm 4
	special DoSoftReset
	return


CountBadges::
	setvar VAR_RESULT, 0
	goto_if_set FLAG_BADGE01_GET, CountBadges_2
CountBadges_1:
	goto_if_set FLAG_BADGE02_GET, CountBadges_5
CountBadges_4:
	goto_if_set FLAG_BADGE03_GET, CountBadges_8
CountBadges_7:
	goto_if_set FLAG_BADGE04_GET, CountBadges_11
CountBadges_10:
	goto_if_set FLAG_BADGE05_GET, CountBadges_14
CountBadges_13:
	goto_if_set FLAG_BADGE06_GET, CountBadges_17
CountBadges_16:
	goto_if_set FLAG_BADGE07_GET, CountBadges_20
CountBadges_19:
	goto_if_set FLAG_BADGE08_GET, CountBadges_23
CountBadges_22:
	goto_if_set FLAG_IS_CHAMPION, CountBadges_25
	return

CountBadges_2:
	addvar VAR_RESULT, 1
	goto CountBadges_1

CountBadges_5:
	addvar VAR_RESULT, 1
	goto CountBadges_4

CountBadges_8:
	addvar VAR_RESULT, 1
	goto CountBadges_7

CountBadges_11:
	addvar VAR_RESULT, 1
	goto CountBadges_10

CountBadges_14:
	addvar VAR_RESULT, 1
	goto CountBadges_13

CountBadges_17:
	addvar VAR_RESULT, 1
	goto CountBadges_16

CountBadges_20:
	addvar VAR_RESULT, 1
	goto CountBadges_19

CountBadges_23:
	addvar VAR_RESULT, 1
	goto CountBadges_22

CountBadges_25:
	addvar VAR_RESULT, 1
	return


PrintBadges::
	closemessage
	switch VAR_RESULT
	case 0, PrintBadges_3
	case 1, PrintBadges_4
	case 2, PrintBadges_5
	case 3, PrintBadges_6
	case 4, PrintBadges_7
	case 5, PrintBadges_8
	case 6, PrintBadges_9
	case 7, PrintBadges_10
	case 8, PrintBadges_11
	case 9, PrintBadges_12
	msgbox PrintBadges_Text_10, MSGBOX_NPC
PrintBadges_1:
	closemessage
	releaseall
	return

PrintBadges_3:
	msgbox PrintBadges_Text_0, MSGBOX_NPC
	goto PrintBadges_1

PrintBadges_4:
	msgbox PrintBadges_Text_1, MSGBOX_NPC
	goto PrintBadges_1

PrintBadges_5:
	msgbox PrintBadges_Text_2, MSGBOX_NPC
	goto PrintBadges_1

PrintBadges_6:
	msgbox PrintBadges_Text_3, MSGBOX_NPC
	goto PrintBadges_1

PrintBadges_7:
	msgbox PrintBadges_Text_4, MSGBOX_NPC
	goto PrintBadges_1

PrintBadges_8:
	msgbox PrintBadges_Text_5, MSGBOX_NPC
	goto PrintBadges_1

PrintBadges_9:
	msgbox PrintBadges_Text_6, MSGBOX_NPC
	goto PrintBadges_1

PrintBadges_10:
	msgbox PrintBadges_Text_7, MSGBOX_NPC
	goto PrintBadges_1

PrintBadges_11:
	msgbox PrintBadges_Text_8, MSGBOX_NPC
	goto PrintBadges_1

PrintBadges_12:
	msgbox PrintBadges_Text_9, MSGBOX_NPC
	goto PrintBadges_1


SetKantoCaught::
	setvar VAR_TEMP_A, SPECIES_BULBASAUR
SetKantoCaught_1:
	compare VAR_TEMP_A, SPECIES_MEW
	goto_if_le SetKantoCaught_2
	return

SetKantoCaught_2:
	setcaughtmonvar VAR_TEMP_A
	addvar VAR_TEMP_A, 1
	goto SetKantoCaught_1


SetAllCaught::
	setvar VAR_TEMP_A, ( SPECIES_NONE + 1 )
SetAllCaught_1:
	compare VAR_TEMP_A, NUM_SPECIES
	goto_if_le SetAllCaught_2
	return

SetAllCaught_2:
	setcaughtmonvar VAR_TEMP_A
	addvar VAR_TEMP_A, 1
	goto SetAllCaught_1


LabLights_StartEasyMode::
	msgbox LabLights_StartEasyMode_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LabLights_StartEasyMode_1
	msgbox LabLights_StartEasyMode_Text_4, MSGBOX_DEFAULT
	return

LabLights_StartEasyMode_1:
	setflag FLAG_SYS_GAMEMODE_EASY
	msgbox LabLights_StartEasyMode_Text_1, MSGBOX_DEFAULT
	msgbox LabLights_StartEasyMode_Text_2, MSGBOX_DEFAULT
	msgbox LabLights_StartEasyMode_Text_3, MSGBOX_DEFAULT
	return


LabLights_ToggleEasyMode::
	questmenu QUEST_MENU_CHECK_COMPLETE, ADVENTURE_BEGINS
	compare VAR_RESULT, TRUE
	goto_if_eq LabLights_ToggleEasyMode_1
	return

LabLights_ToggleEasyMode_1:
	goto_if_set FLAG_SYS_GAMEMODE_EASY, LabLights_ToggleEasyMode_4
	msgbox LabLights_ToggleEasyMode_Text_1, MSGBOX_YESNO
LabLights_ToggleEasyMode_3:
	compare VAR_RESULT, YES
	goto_if_eq LabLights_ToggleEasyMode_8
	msgbox LabLights_ToggleEasyMode_Text_3, MSGBOX_DEFAULT
	clearflag FLAG_SYS_GAMEMODE_EASY
	clearflag FLAG_SYS_NO_ENCOUNTER
	compare VAR_RESULT, TRUE
	goto_if_eq LabLights_ToggleEasyMode_15
LabLights_ToggleEasyMode_14:
	compare VAR_RESULT, TRUE
	goto_if_eq LabLights_ToggleEasyMode_21
LabLights_ToggleEasyMode_20:
	msgbox LabLights_ToggleEasyMode_Text_4, MSGBOX_DEFAULT
	closemessage
	delay 20
	msgbox LabLights_ToggleEasyMode_Text_5, MSGBOX_DEFAULT
	closemessage
LabLights_ToggleEasyMode_7:
	delay 20
	return

LabLights_ToggleEasyMode_4:
	msgbox LabLights_ToggleEasyMode_Text_0, MSGBOX_YESNO
	goto LabLights_ToggleEasyMode_3

LabLights_ToggleEasyMode_8:
	msgbox LabLights_ToggleEasyMode_Text_2, MSGBOX_DEFAULT
	setflag FLAG_SYS_GAMEMODE_EASY
	clearflag FLAG_SYS_NO_ENCOUNTER
	compare VAR_RESULT, FALSE
	goto_if_eq LabLights_ToggleEasyMode_12
LabLights_ToggleEasyMode_11:
	compare VAR_RESULT, FALSE
	goto_if_eq LabLights_ToggleEasyMode_18
LabLights_ToggleEasyMode_17:
	closemessage
	goto LabLights_ToggleEasyMode_7

LabLights_ToggleEasyMode_12:
	goto LabLights_ToggleEasyMode_11

LabLights_ToggleEasyMode_15:
	goto LabLights_ToggleEasyMode_14

LabLights_ToggleEasyMode_18:
	goto LabLights_ToggleEasyMode_17

LabLights_ToggleEasyMode_21:
	goto LabLights_ToggleEasyMode_20


LabLights_AbsolCry::
	playmoncry SPECIES_ABSOL, 0
	msgbox LabLights_AbsolCry_Text_0, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	setvar VAR_LAB_LIGHTS, 0
	questmenu QUEST_MENU_CHECK_UNLOCKED, CALAMITY_QUEEN
	delay 20
	compare VAR_RESULT, FALSE
	goto_if_eq LabLights_AbsolCry_1
	msgbox LabLights_AbsolCry_Text_2, MSGBOX_SIGN
	return

LabLights_AbsolCry_1:
	msgbox LabLights_AbsolCry_Text_1, MSGBOX_SIGN
	startquest CALAMITY_QUEEN
	return


LabLights_LaprasCry::
	playmoncry SPECIES_SNORLAX, 0
	msgbox LabLights_LaprasCry_Text_0, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	setvar VAR_LAB_LIGHTS, 0
	questmenu QUEST_MENU_CHECK_UNLOCKED, TEAM_AQUA
	delay 20
	compare VAR_RESULT, FALSE
	goto_if_eq LabLights_LaprasCry_1
	return

LabLights_LaprasCry_1:
	msgbox LabLights_LaprasCry_Text_1, MSGBOX_SIGN
	return


LabLights_EventScript_MineOwner::
	compare VAR_TEMP_1, 0
	goto_if_eq LabLights_EventScript_MineOwner_1
	msgbox LabLights_EventScript_MineOwner_Text_1, MSGBOX_NPC
	return

LabLights_EventScript_MineOwner_1:
	msgbox LabLights_EventScript_MineOwner_Text_0, MSGBOX_NPC
	addvar VAR_TEMP_1, 1
	return


OpenTheQuestMenu::
	openquestmenu
	end


DemoBegin_Text_0:
	.string "You are playing a DEMO of\n"
	.string "POKéMON LABRADORESCENT LIGHTS.\l"
	.string "This only contains the tutorial.$"

DemoEnd_Text_0:
	.string "You have now completed the DEMO of\n"
	.string "POKéMON LABRADORESCENT LIGHTS.$"

DemoEnd_Text_1:
	.string "Thank you very much for playing!\n"
	.string "Press A to return to the title screen.$"

PrintBadges_Text_0:
	.string "None$"

PrintBadges_Text_1:
	.string "One$"

PrintBadges_Text_2:
	.string "Two$"

PrintBadges_Text_3:
	.string "Three$"

PrintBadges_Text_4:
	.string "Four$"

PrintBadges_Text_5:
	.string "Five$"

PrintBadges_Text_6:
	.string "Six$"

PrintBadges_Text_7:
	.string "Seven$"

PrintBadges_Text_8:
	.string "Eight$"

PrintBadges_Text_9:
	.string "Champion$"

PrintBadges_Text_10:
	.string "Broken$"

LabLights_StartEasyMode_Text_0:
	.string "Moving is a fresh start for all of us,\n"
	.string "but I don't want to be overbearing.\p"
	.string "I can still try and make your life a\n"
	.string "little bit easier if you'd like?$"

LabLights_StartEasyMode_Text_1:
	.string "Alright my love,\n"
	.string "I'll be sure to help you out.\l"
	.string "Start by taking this.$"

LabLights_StartEasyMode_Text_2:
	.string "MOM: Your DAD gave this to me, in order\n"
	.string "to help fit POKéMON training around\l"
	.string "a busy schedule working on SELENIC.\p"
	.string "You may find it more useful now,\n"
	.string "and he also gave me something else.$"

LabLights_StartEasyMode_Text_3:
	.string "MOM: When we were first adventuring,\n"
	.string "I was anxious of wild POKéMON.\p"
	.string "This long lasting REPEL made sure\n"
	.string "that I didn't run into any POKéMON.\l"
	.string "Well, only when I didn't want to!\p"
	.string "Anyway…$"

LabLights_StartEasyMode_Text_4:
	.string "Don't worry my love,\n"
	.string "I won't spoil your style.\l"
	.string "Anyway…$"

LabLights_ToggleEasyMode_Text_0:
	.string "MOM: You seem to be doing great honey!\n"
	.string "Would you still like to me to help out?$"

LabLights_ToggleEasyMode_Text_1:
	.string "MOM: You seem to be doing great honey!\n"
	.string "Would you like to me to help out?$"

LabLights_ToggleEasyMode_Text_2:
	.string "Of course, I'll always be here for you.$"

LabLights_ToggleEasyMode_Text_3:
	.string "Don't worry, {PLAYER}.\n"
	.string "I know you'll be amazing on your own.$"

LabLights_ToggleEasyMode_Text_4:
	.string "{PLAYER} returned DAD's\n"
	.string "TRAINING KIT to MOM.$"

LabLights_ToggleEasyMode_Text_5:
	.string "{PLAYER} returned DAD's\n"
	.string "REPEL to MOM.$"

LabLights_AbsolCry_Text_0:
	.string "Aurrra!$"

LabLights_AbsolCry_Text_1:
	.string "Oh?\n"
	.string "Was that a POKéMON cry?$"

LabLights_AbsolCry_Text_2:
	.string "There's that cry again,\n"
	.string "I wonder what POKéMON it was.$"

LabLights_LaprasCry_Text_0:
	.string "Burrrurrrr!$"

LabLights_LaprasCry_Text_1:
	.string "Whoa! That cry was definitely made by\n"
	.string "a different POKéMON.\p"
	.string "I wonder what it was.$"

LabLights_EventScript_MineOwner_Text_0:
	.string "On behalf of the DEVON CORPORATION,\n"
	.string "hold it right there!\p"
	.string "We're tunneling and our workers are\n"
	.string "mining LABRADORITE up ahead.\p"
	.string "I can't let anyone by.\n"
	.string "You're going to have to leave.$"

LabLights_EventScript_MineOwner_Text_1:
	.string "Didn't you hear me?\p"
	.string "We're tunneling and our workers are\n"
	.string "mining LABRADORITE up ahead.\p"
	.string "I can't let anyone by, so\n"
	.string "you're going to have to leave.$"
