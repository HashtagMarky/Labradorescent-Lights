PetalburgCityAqua_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCityAqua_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCityAqua_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

PetalburgCityAqua_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, HOMELY, PROTECT
	compare VAR_RESULT, FALSE
	goto_if_eq PetalburgCityAqua_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

PetalburgCityAqua_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setflag FLAG_HIDE_MAP_NAME_POPUP
	savebgm MUS_PL_LOOKER
	return

PetalburgCityAqua_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_1, 0, PetalburgCityAqua_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

PetalburgCityAqua_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	addvar VAR_TEMP_1, 1
	setmetatile 15, 8, METATILE_Petalburg_Door_Gym_Closed, TRUE
	return


PetalburgCityAqua_EventScripts_AquaGrunt_Male::
	lock
	msgbox PetalburgCityAqua_EventScripts_AquaGrunt_Male_Text_0, MSGBOX_DEFAULT
	closemessage
	release
	return


PetalburgCityAqua_EventScripts_AquaGrunt_Female::
	lock
	msgbox PetalburgCityAqua_EventScripts_AquaGrunt_Female_Text_0, MSGBOX_DEFAULT
	closemessage
	release
	return


PetalburgCityAqua_EventScripts_SamuelIntro_Trigger::
	lock
	setvar VAR_TEMP_0, 1
	getplayerxy VAR_TEMP_A, VAR_TEMP_B
	switch VAR_TEMP_A
	case 12, PetalburgCityAqua_EventScripts_SamuelIntro_Trigger_3
	case 13, PetalburgCityAqua_EventScripts_SamuelIntro_Trigger_4
	case 14, PetalburgCityAqua_EventScripts_SamuelIntro_Trigger_5
	case 16, PetalburgCityAqua_EventScripts_SamuelIntro_Trigger_6
PetalburgCityAqua_EventScripts_SamuelIntro_Trigger_1:
	waitmovement 0
	goto PetalburgCityAqua_EventScripts_SamuelIntro
	return

PetalburgCityAqua_EventScripts_SamuelIntro_Trigger_3:
	applymovement 1, PetalburgCityAqua_Movement_SamuelIntro_One
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCityAqua_Movement_SamuelIntro_Player_One
	goto PetalburgCityAqua_EventScripts_SamuelIntro_Trigger_1

PetalburgCityAqua_EventScripts_SamuelIntro_Trigger_4:
	applymovement 1, PetalburgCityAqua_Movement_SamuelIntro_Two
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCityAqua_Movement_SamuelIntro_Player_Two
	goto PetalburgCityAqua_EventScripts_SamuelIntro_Trigger_1

PetalburgCityAqua_EventScripts_SamuelIntro_Trigger_5:
	applymovement 1, PetalburgCityAqua_Movement_SamuelIntro_Three
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCityAqua_Movement_SamuelIntro_Player_Three
	goto PetalburgCityAqua_EventScripts_SamuelIntro_Trigger_1

PetalburgCityAqua_EventScripts_SamuelIntro_Trigger_6:
	applymovement 1, PetalburgCityAqua_Movement_SamuelIntro_Four
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCityAqua_Movement_SamuelIntro_Player_Four
	goto PetalburgCityAqua_EventScripts_SamuelIntro_Trigger_1


PetalburgCityAqua_EventScripts_Samuel::
	subquestmenu QUEST_MENU_CHECK_COMPLETE, HOMELY, PROTECT
	compare VAR_RESULT, FALSE
	goto_if_eq PetalburgCityAqua_EventScripts_Samuel_1
	goto PetalburgCityAqua_EventScripts_SamuelLetsGo
	return

PetalburgCityAqua_EventScripts_Samuel_1:
	goto PetalburgCityAqua_EventScripts_SamuelIntro
	return


PetalburgCityAqua_EventScripts_SamuelIntro::
	lock
	clearflag FLAG_DONT_TRANSITION_MUSIC
	compare VAR_TEMP_0, 1
	goto_if_ne PetalburgCityAqua_EventScripts_SamuelIntro_2
PetalburgCityAqua_EventScripts_SamuelIntro_1:
	msgbox PetalburgCityAqua_EventScripts_SamuelIntro_Text_0, MSGBOX_DEFAULT
	closemessage
	applymovement 1, FaceDown
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement 1, Exclaim
	waitmovement 0
	compare VAR_TEMP_0, 1
	goto_if_ne PetalburgCityAqua_EventScripts_SamuelIntro_5
	switch VAR_TEMP_A
	case 12, PetalburgCityAqua_EventScripts_SamuelIntro_13
	case 13, PetalburgCityAqua_EventScripts_SamuelIntro_13
	case 14, PetalburgCityAqua_EventScripts_SamuelIntro_13
	case 16, PetalburgCityAqua_EventScripts_SamuelIntro_14
PetalburgCityAqua_EventScripts_SamuelIntro_4:
	waitmovement 0
	msgbox PetalburgCityAqua_EventScripts_SamuelIntro_Text_1, MSGBOX_YESNO
PetalburgCityAqua_EventScripts_SamuelIntro_9:
	compare VAR_RESULT, NO
	goto_if_eq PetalburgCityAqua_EventScripts_SamuelIntro_10
	msgbox PetalburgCityAqua_EventScripts_SamuelIntro_Text_3, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 1
	completesubquest HOMELY, PROTECT
	applymovement 1, FaceDown
	waitmovement 0
	releaseall
	return

PetalburgCityAqua_EventScripts_SamuelIntro_2:
	faceplayer
	goto PetalburgCityAqua_EventScripts_SamuelIntro_1

PetalburgCityAqua_EventScripts_SamuelIntro_5:
	faceplayer
	goto PetalburgCityAqua_EventScripts_SamuelIntro_4

PetalburgCityAqua_EventScripts_SamuelIntro_10:
	msgbox PetalburgCityAqua_EventScripts_SamuelIntro_Text_2, MSGBOX_YESNO
	goto PetalburgCityAqua_EventScripts_SamuelIntro_9

PetalburgCityAqua_EventScripts_SamuelIntro_13:
	applymovement 1, FaceLeft
	goto PetalburgCityAqua_EventScripts_SamuelIntro_4

PetalburgCityAqua_EventScripts_SamuelIntro_14:
	applymovement 1, FaceRight
	goto PetalburgCityAqua_EventScripts_SamuelIntro_4


PetalburgCityAqua_EventScripts_SamuelLetsGo::
	end


PetalburgCityAqua_Movement_SamuelIntro_One:
	delay_16
	delay_16
	delay_16
	delay_8
	delay_4
	delay_2
	face_left
	step_end

PetalburgCityAqua_Movement_SamuelIntro_Two:
	delay_16
	delay_8
	delay_4
	delay_2
	face_left
	step_end

PetalburgCityAqua_Movement_SamuelIntro_Three:
	delay_8
	delay_4
	delay_2
	face_left
	step_end

PetalburgCityAqua_Movement_SamuelIntro_Four:
	delay_8
	delay_4
	delay_2
	face_right
	step_end

PetalburgCityAqua_Movement_SamuelIntro_Player_One:
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

PetalburgCityAqua_Movement_SamuelIntro_Player_Two:
	walk_down
	walk_right
	step_end

PetalburgCityAqua_Movement_SamuelIntro_Player_Three:
	face_right
	step_end

PetalburgCityAqua_Movement_SamuelIntro_Player_Four:
	walk_down
	face_left
	step_end

PetalburgCityAqua_EventScripts_AquaGrunt_Male_Text_0:
	.string "We own PETALBURG CITY!\n"
	.string "TEAM AQUA on top!$"

PetalburgCityAqua_EventScripts_AquaGrunt_Female_Text_0:
	.string "TEAM AQUA is the best!\n"
	.string "PETALBURG CITY is ours!$"

PetalburgCityAqua_EventScripts_SamuelIntro_Text_0:
	.string "DAD: Is this the villainous TEAM AQUA\n"
	.string "that you've encountered, {PLAYER}?\l"
	.string "What are they doing in PETALBURG CITY?\p"
	.string "Everybody seems to be inside their\n"
	.string "homes, that's good for sure…$"

PetalburgCityAqua_EventScripts_SamuelIntro_Text_1:
	.string "DAD: {PLAYER}!\p"
	.string "We need to do something about this!\n"
	.string "I know we've just had a fierce battle,\l"
	.string "but will you help us handle TEAM AQUA?$"

PetalburgCityAqua_EventScripts_SamuelIntro_Text_2:
	.string "DAD: Please {PLAYER}, we need to drive\nTEAM AQUA out of PETALBURG CITY.\lWill you help us do it?$"

PetalburgCityAqua_EventScripts_SamuelIntro_Text_3:
	.string "DAD: Let's do it.\n"
	.string "Let's go and get them, {PLAYER}.$"
