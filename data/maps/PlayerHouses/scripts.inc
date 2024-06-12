PlayerHouses_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PlayerHouses_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PlayerHouses_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

PlayerHouses_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	initclock 18, 30
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
