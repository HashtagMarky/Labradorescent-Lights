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
	fadescreen FADE_TO_BLACK
	delay 60
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, WalkDown
	waitmovement 0
	msgbox DemoEnd_Text_1, MSGBOX_DEFAULT
DemoEnd_1:
	goto_if_set FLAG_SYS_DEMO_MODE, DemoEnd_2
	return

DemoEnd_2:
	lockall
	goto DemoEnd_1


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


LabLights_AbsolCry::
	playmoncry SPECIES_ABSOL, 0
	msgbox LabLights_AbsolCry_Text_0, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	setvar VAR_LAB_LIGHTS, 0
	questmenu QUEST_MENU_CHECK_UNLOCKED, CALAMITY_QUEEN
	compare VAR_RESULT, FALSE
	goto_if_eq LabLights_AbsolCry_1
	return

LabLights_AbsolCry_1:
	startquest CALAMITY_QUEEN
	return


LabLights_LaprasCry::
	playmoncry SPECIES_SNORLAX, 0
	msgbox LabLights_LaprasCry_Text_0, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	setvar VAR_LAB_LIGHTS, 0
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
	.string "You can now turn off the system.$"

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

LabLights_AbsolCry_Text_0:
	.string "Aurrra!$"

LabLights_LaprasCry_Text_0:
	.string "Burrrurrrr!$"
