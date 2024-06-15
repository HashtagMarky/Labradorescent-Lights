PlayerHouses_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PlayerHouses_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PlayerHouses_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

PlayerHouses_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	initclock 18, 30
	call PlayerHouses_MoveDadToKitchen
	return

PlayerHouses_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_0, 0, PlayerHouses_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

PlayerHouses_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	setvar VAR_TEMP_0, 1
	call PlayerHouses_SetVariables
	goto_if_set FLAG_SET_HOMELY_STATE, PlayerHouses_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1
	return

PlayerHouses_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1:
	goto Homely_PlayerHouses_StartDinner
	return


PlayerHouses_SetVariables::
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq PlayerHouses_SetVariables_1
	setvar VAR_TEMP_1, 6
	setvar VAR_TEMP_2, 7
	setvar VAR_TEMP_3, 8
	setvar VAR_TEMP_4, 9
	setvar VAR_TEMP_5, 10
	return

PlayerHouses_SetVariables_1:
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_2, 2
	setvar VAR_TEMP_3, 3
	setvar VAR_TEMP_4, 4
	setvar VAR_TEMP_5, 5
	return


PlayerHouses_MoveDadToKitchen::
	setobjectxyperm 2, 2, 3
	setobjectmovementtype 2, MOVEMENT_TYPE_WALK_IN_PLACE_UP
	setobjectxyperm 7, 34, 3
	setobjectmovementtype 7, MOVEMENT_TYPE_WALK_IN_PLACE_UP
	return


Homely_PlayerHouses_StartDinner::
	special SpawnCameraObject
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Homely_PlayerHouses_StartDinner_2
	applymovement OBJ_EVENT_ID_PLAYER, Homely_Movement_MaysHouse_WalkToTable
	applymovement OBJ_EVENT_ID_CAMERA, Homely_Movement_MaysHouse_CameraWalkToTable
Homely_PlayerHouses_StartDinner_1:
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox Homely_PlayerHouses_StartDinner_Text_0, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox Homely_PlayerHouses_StartDinner_Text_1, MSGBOX_DEFAULT
	closemessage
	compare VAR_RESULT, MALE
	goto_if_eq Homely_PlayerHouses_StartDinner_6
	applymovement VAR_TEMP_2, Homely_Movement_MaysHouse_DadWalkToTable
Homely_PlayerHouses_StartDinner_5:
	waitmovement 0
	delay 30
	special TurnOnTVScreen
	compare VAR_RESULT, MALE
	goto_if_eq Homely_PlayerHouses_StartDinner_10
	applymovement VAR_TEMP_2, WalkIPLeft
Homely_PlayerHouses_StartDinner_9:
	delay 60
	compare VAR_RESULT, MALE
	goto_if_eq Homely_PlayerHouses_StartDinner_14
	applymovement VAR_TEMP_1, JumpIPLeft
	applymovement VAR_TEMP_2, JumpIPLeft
Homely_PlayerHouses_StartDinner_13:
	msgbox Homely_PlayerHouses_StartDinner_Text_2, MSGBOX_DEFAULT
	waitmovement 0
	closemessage
	delay 60
	fadescreen FADE_TO_BLACK
	playfanfare MUS_DP_HEAL
	waitfanfare
	special HealPlayerParty
	fadescreen FADE_FROM_BLACK
	goto Homely_PlayerHouses_AfterDinner
	return

Homely_PlayerHouses_StartDinner_2:
	applymovement OBJ_EVENT_ID_PLAYER, Homely_Movement_BrendansHouse_WalkToTable
	applymovement OBJ_EVENT_ID_CAMERA, Homely_Movement_BrendansHouse_CameraWalkToTable
	goto Homely_PlayerHouses_StartDinner_1

Homely_PlayerHouses_StartDinner_6:
	applymovement VAR_TEMP_2, Homely_Movement_BrendansHouse_DadWalkToTable
	goto Homely_PlayerHouses_StartDinner_5

Homely_PlayerHouses_StartDinner_10:
	applymovement VAR_TEMP_2, WalkIPRight
	goto Homely_PlayerHouses_StartDinner_9

Homely_PlayerHouses_StartDinner_14:
	applymovement VAR_TEMP_1, JumpIPRight
	applymovement VAR_TEMP_2, JumpIPRight
	goto Homely_PlayerHouses_StartDinner_13


Homely_PlayerHouses_AfterDinner::
	delay 30
	special TurnOffTVScreen
	compare VAR_RESULT, MALE
	goto_if_eq Homely_PlayerHouses_AfterDinner_2
	applymovement VAR_TEMP_2, WalkIPLeft
Homely_PlayerHouses_AfterDinner_1:
	delay 30
	msgbox Homely_PlayerHouses_AfterDinner_Text_0, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox Homely_PlayerHouses_AfterDinner_Text_1, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement VAR_TEMP_2, Exclaim
	playse SE_PIN
	msgbox Homely_PlayerHouses_AfterDinner_Text_2, MSGBOX_DEFAULT
	waitmovement 0
	waitse
	closemessage
	delay 30
	goto_if_set FLAG_CHOSEN_ESPURR_GENDER, Homely_PlayerHouses_AfterDinner_12
Homely_PlayerHouses_AfterDinner_10:
	goto_if_set FLAG_CHOSEN_ESPURR_GENDER, Homely_PlayerHouses_AfterDinner_9
Homely_PlayerHouses_AfterDinner_8:
	msgbox Homely_PlayerHouses_AfterDinner_Text_5, MSGBOX_DEFAULT
Homely_PlayerHouses_AfterDinner_5:
	closemessage
	delay 30
	bufferleadmonspeciesname STR_VAR_1
	goto_if_set FLAG_CHOSEN_ESPURR_GENDER, Homely_PlayerHouses_AfterDinner_22
Homely_PlayerHouses_AfterDinner_20:
	goto_if_set FLAG_CHOSEN_ESPURR_GENDER, Homely_PlayerHouses_AfterDinner_19
Homely_PlayerHouses_AfterDinner_18:
	msgbox Homely_PlayerHouses_AfterDinner_Text_8, MSGBOX_DEFAULT
Homely_PlayerHouses_AfterDinner_15:
	closemessage
	return

Homely_PlayerHouses_AfterDinner_2:
	applymovement VAR_TEMP_2, WalkIPRight
	goto Homely_PlayerHouses_AfterDinner_1

Homely_PlayerHouses_AfterDinner_6:
	msgbox Homely_PlayerHouses_AfterDinner_Text_3, MSGBOX_DEFAULT
	goto Homely_PlayerHouses_AfterDinner_5

Homely_PlayerHouses_AfterDinner_7:
	msgbox Homely_PlayerHouses_AfterDinner_Text_4, MSGBOX_DEFAULT
	goto Homely_PlayerHouses_AfterDinner_5

Homely_PlayerHouses_AfterDinner_9:
	goto_if_set FLAG_ESPURR_GENDER, Homely_PlayerHouses_AfterDinner_7
	goto Homely_PlayerHouses_AfterDinner_8

Homely_PlayerHouses_AfterDinner_12:
	goto_if_unset FLAG_ESPURR_GENDER, Homely_PlayerHouses_AfterDinner_6
	goto Homely_PlayerHouses_AfterDinner_10

Homely_PlayerHouses_AfterDinner_16:
	msgbox Homely_PlayerHouses_AfterDinner_Text_6, MSGBOX_DEFAULT
	goto Homely_PlayerHouses_AfterDinner_15

Homely_PlayerHouses_AfterDinner_17:
	msgbox Homely_PlayerHouses_AfterDinner_Text_7, MSGBOX_DEFAULT
	goto Homely_PlayerHouses_AfterDinner_15

Homely_PlayerHouses_AfterDinner_19:
	goto_if_set FLAG_ESPURR_GENDER, Homely_PlayerHouses_AfterDinner_17
	goto Homely_PlayerHouses_AfterDinner_18

Homely_PlayerHouses_AfterDinner_22:
	goto_if_unset FLAG_ESPURR_GENDER, Homely_PlayerHouses_AfterDinner_16
	goto Homely_PlayerHouses_AfterDinner_20


Homely_PlayerHouses_Parents::
	special GetOverworldObject
	compare VAR_RESULT, OBJ_EVENT_GFX_MOM
	goto_if_eq Homely_PlayerHouses_Parents_1
	compare VAR_RESULT, OBJ_EVENT_GFX_NORMAN
	goto_if_eq Homely_PlayerHouses_Parents_2
	return

Homely_PlayerHouses_Parents_1:
	goto Homely_PlayerHouses_Mom
	return

Homely_PlayerHouses_Parents_2:
	goto Homely_PlayerHouses_Dad
	return


Homely_PlayerHouses_Mom::
	faceplayer
	goto_if_set FLAG_CHOSEN_ESPURR_GENDER, Homely_PlayerHouses_Mom_8
Homely_PlayerHouses_Mom_6:
	goto_if_set FLAG_CHOSEN_ESPURR_GENDER, Homely_PlayerHouses_Mom_5
Homely_PlayerHouses_Mom_4:
	msgbox Homely_PlayerHouses_Mom_Text_2, MSGBOX_DEFAULT
Homely_PlayerHouses_Mom_1:
	closemessage
	applymovement 1, FaceRight
	applymovement 6, FaceLeft
	return

Homely_PlayerHouses_Mom_2:
	msgbox Homely_PlayerHouses_Mom_Text_0, MSGBOX_DEFAULT
	goto Homely_PlayerHouses_Mom_1

Homely_PlayerHouses_Mom_3:
	msgbox Homely_PlayerHouses_Mom_Text_1, MSGBOX_DEFAULT
	goto Homely_PlayerHouses_Mom_1

Homely_PlayerHouses_Mom_5:
	goto_if_set FLAG_ESPURR_GENDER, Homely_PlayerHouses_Mom_3
	goto Homely_PlayerHouses_Mom_4

Homely_PlayerHouses_Mom_8:
	goto_if_unset FLAG_ESPURR_GENDER, Homely_PlayerHouses_Mom_2
	goto Homely_PlayerHouses_Mom_6


Homely_PlayerHouses_Dad::
	faceplayer
	goto_if_set FLAG_CHOSEN_ESPURR_GENDER, Homely_PlayerHouses_Dad_8
Homely_PlayerHouses_Dad_6:
	goto_if_set FLAG_CHOSEN_ESPURR_GENDER, Homely_PlayerHouses_Dad_5
Homely_PlayerHouses_Dad_4:
	msgbox Homely_PlayerHouses_Dad_Text_2, MSGBOX_DEFAULT
Homely_PlayerHouses_Dad_1:
	closemessage
	applymovement 2, FaceRight
	applymovement 7, FaceLeft
	return

Homely_PlayerHouses_Dad_2:
	msgbox Homely_PlayerHouses_Dad_Text_0, MSGBOX_DEFAULT
	goto Homely_PlayerHouses_Dad_1

Homely_PlayerHouses_Dad_3:
	msgbox Homely_PlayerHouses_Dad_Text_1, MSGBOX_DEFAULT
	goto Homely_PlayerHouses_Dad_1

Homely_PlayerHouses_Dad_5:
	goto_if_set FLAG_ESPURR_GENDER, Homely_PlayerHouses_Dad_3
	goto Homely_PlayerHouses_Dad_4

Homely_PlayerHouses_Dad_8:
	goto_if_unset FLAG_ESPURR_GENDER, Homely_PlayerHouses_Dad_2
	goto Homely_PlayerHouses_Dad_6


Homely_PlayerHouses_Espurr::
	return


Homely_Movement_BrendansHouse_WalkToTable:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	delay_16
	walk_in_place_left
	step_end

Homely_Movement_MaysHouse_WalkToTable:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	delay_16
	walk_in_place_right
	step_end

Homely_Movement_BrendansHouse_CameraWalkToTable:
	walk_up
	walk_up
	walk_diag_northwest
	step_end

Homely_Movement_MaysHouse_CameraWalkToTable:
	walk_diag_northeast
	walk_diag_northeast
	walk_diag_northeast
	walk_right
	walk_right
	walk_right
	step_end

Homely_Movement_BrendansHouse_DadWalkToTable:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_right
	face_down
	delay_16
	walk_in_place_down
	walk_in_place_down
	delay_16
	walk_right
	face_down
	delay_16
	walk_in_place_down
	delay_16
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_right
	delay_16
	walk_in_place_right
	step_end

Homely_Movement_MaysHouse_DadWalkToTable:
	step_end

Homely_PlayerHouses_StartDinner_Text_0:
	.string "DAD: Great timing, {PLAYER}.\n"
	.string "I'm bringing dinner over now!$"

Homely_PlayerHouses_StartDinner_Text_1:
	.string "MOM: You can tell us everything\n"
	.string "that happened in BOREA PASSAGE!\p"
	.string "What is like exploring right beneath us,\n"
	.string "in the DEVON CORP.'s latest project?$"

Homely_PlayerHouses_StartDinner_Text_2:
	.string "MOM & DAD: Time to eat!$"

Homely_PlayerHouses_AfterDinner_Text_0:
	.string "DAD: Wow!\n"
	.string "So that's what happened down there.\p"
	.string "Even prepared, I'm relieved that you\n"
	.string "didn't need battle down there.\l"
	.string "Especially against someone like…\p"
	.string "What was his name again?$"

Homely_PlayerHouses_AfterDinner_Text_1:
	.string "MOM: His name was ARCHIE, dear…\p"
	.string "But anyway, he wouldn't be any trouble\n"
	.string "for a LABRADORITE BADGE holder!\l"
	.string "Isn't that right, {PLAYER}!$"

Homely_PlayerHouses_AfterDinner_Text_2:
	.string "DAD: Well, you're not wrong there!\p"
	.string "I could still give {PLAYER} a run for\n"
	.string "their money, if I wanted to that is.$"

Homely_PlayerHouses_AfterDinner_Text_3:
	.string "MOM: Oh stop it, you know that you\n"
	.string "got beaten fair and square.\p"
	.string "It was so fun to watch.\n"
	.string "Even PEDRO loved it!$"

Homely_PlayerHouses_AfterDinner_Text_4:
	.string "MOM: Oh stop it, you know that you\n"
	.string "got beaten fair and square.\p"
	.string "It was so fun to watch.\n"
	.string "Even POPPY loved it!$"

Homely_PlayerHouses_AfterDinner_Text_5:
	.string "MOM: Oh stop it, you know that you\n"
	.string "got beaten fair and square.\p"
	.string "It was so fun to watch.\n"
	.string "Even ESPURR loved it!$"

Homely_PlayerHouses_AfterDinner_Text_6:
	.string "DAD: Speaking about our battle,\n"
	.string "it seemed PEDRO really enjoyed\l"
	.string "seeing {STR_VAR_1} in action.\p"
	.string "I think he would even like to have\n"
	.string "his own attempt at a POKéMON battle.\p"
	.string "PEDRO has had a weird energy recently,\n"
	.string "why don't you see what he thinks.$"

Homely_PlayerHouses_AfterDinner_Text_7:
	.string "DAD: Speaking about our battle,\n"
	.string "it seemed POPPY really enjoyed\l"
	.string "seeing {STR_VAR_1} in action.\p"
	.string "I think she would even like to have\n"
	.string "her own attempt at a POKéMON battle.\p"
	.string "POPPY has had a weird energy recently,\n"
	.string "why don't you see what she thinks.$"

Homely_PlayerHouses_AfterDinner_Text_8:
	.string "DAD: Speaking about our battle,\n"
	.string "it seemed ESPURR really enjoyed\l"
	.string "seeing {STR_VAR_1} in action.\p"
	.string "I think it would even like to have\n"
	.string "its own attempt at a POKéMON battle.\p"
	.string "ESPURR has had a weird energy recently,\n"
	.string "why don't you see what it thinks.$"

Homely_PlayerHouses_Mom_Text_0:
	.string "MOM: Why don't you go see\n"
	.string "how PEDRO is doing, honey?$"

Homely_PlayerHouses_Mom_Text_1:
	.string "MOM: Why don't you go see\n"
	.string "how POPPY is doing, honey?$"

Homely_PlayerHouses_Mom_Text_2:
	.string "MOM: Why don't you go see\n"
	.string "how ESPURR is doing, honey?$"

Homely_PlayerHouses_Dad_Text_0:
	.string "DAD: You should go and see if PEDRO is\n"
	.string "interested in learning how to battle.$"

Homely_PlayerHouses_Dad_Text_1:
	.string "DAD: You should go and see if POPPY is\n"
	.string "interested in learning how to battle.$"

Homely_PlayerHouses_Dad_Text_2:
	.string "DAD: You should go and see if ESPURR is\n"
	.string "interested in learning how to battle.$"
