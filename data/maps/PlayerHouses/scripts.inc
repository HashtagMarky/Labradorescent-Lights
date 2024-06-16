PlayerHouses_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PlayerHouses_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_RESUME, PlayerHouses_MapScripts_MAP_SCRIPT_ON_RESUME
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PlayerHouses_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

PlayerHouses_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	initclock 19, 30
	call PlayerHouses_MoveDadToKitchen
	return

PlayerHouses_MapScripts_MAP_SCRIPT_ON_RESUME:
	compare VAR_TEMP_0, 1
	goto_if_eq PlayerHouses_MapScripts_MAP_SCRIPT_ON_RESUME_1
	return

PlayerHouses_MapScripts_MAP_SCRIPT_ON_RESUME_1:
	special SpawnCameraObject
	return

PlayerHouses_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_0, 0, PlayerHouses_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	map_script_2 VAR_TEMP_0, 2, PlayerHouses_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_1
	.2byte 0

PlayerHouses_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	setvar VAR_TEMP_0, 1
	call PlayerHouses_SetVariables
	goto_if_set FLAG_SET_HOMELY_STATE, PlayerHouses_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1
	return

PlayerHouses_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1:
	goto Homely_PlayerHouses_StartDinner
	return

PlayerHouses_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_1:
	goto Homely_PlayerHouses_EspurrAfterEvolve
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
	setobjectxyperm 7, 38, 3
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
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Homely_PlayerHouses_StartDinner_6
	applymovement VAR_TEMP_2, Homely_Movement_MaysHouse_DadWalkToTable
Homely_PlayerHouses_StartDinner_5:
	waitmovement 0
	delay 30
	special TurnOnTVScreen
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Homely_PlayerHouses_StartDinner_10
	applymovement VAR_TEMP_2, WalkIPLeft
Homely_PlayerHouses_StartDinner_9:
	delay 60
	checkplayergender
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
	checkplayergender
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
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Homely_PlayerHouses_AfterDinner_26
	setvar VAR_0x8006, MOVEMENT_TYPE_FACE_LEFT
Homely_PlayerHouses_AfterDinner_25:
	copyvar VAR_0x8005, VAR_TEMP_2
	special SetHomelyDadObjectMovementType
	compare VAR_RESULT, FEMALE
	goto_if_eq Homely_PlayerHouses_AfterDinner_30
Homely_PlayerHouses_AfterDinner_29:
	special MoveHomelyCameraObject
	completesubquest HOMELY, ESPURR
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

Homely_PlayerHouses_AfterDinner_26:
	setvar VAR_0x8006, MOVEMENT_TYPE_FACE_RIGHT
	goto Homely_PlayerHouses_AfterDinner_25

Homely_PlayerHouses_AfterDinner_30:
	applymovement 7, Homely_Movement_MaysHouse_DadWalkOutOfWay
	applymovement 6, Homely_Movement_MaysHouse_MomWalkOutOfWay
	waitmovement 0
	goto Homely_PlayerHouses_AfterDinner_29


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
	playmoncry SPECIES_ESPURR, 0
	getpartysize
	bufferleadmonspeciesname STR_VAR_1
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq Homely_PlayerHouses_Espurr_1
	goto Homely_PlayerHouses_EspurrJoin
	return

Homely_PlayerHouses_Espurr_1:
	goto Homely_PlayerHouses_EspurrFullParty
	return


Homely_PlayerHouses_EspurrFullParty::
	goto_if_set FLAG_CHOSEN_ESPURR_GENDER, Homely_PlayerHouses_EspurrFullParty_8
Homely_PlayerHouses_EspurrFullParty_6:
	goto_if_set FLAG_CHOSEN_ESPURR_GENDER, Homely_PlayerHouses_EspurrFullParty_5
Homely_PlayerHouses_EspurrFullParty_4:
	msgbox Homely_PlayerHouses_EspurrFullParty_Text_2, MSGBOX_DEFAULT
Homely_PlayerHouses_EspurrFullParty_1:
	closemessage
	return

Homely_PlayerHouses_EspurrFullParty_2:
	msgbox Homely_PlayerHouses_EspurrFullParty_Text_0, MSGBOX_DEFAULT
	goto Homely_PlayerHouses_EspurrFullParty_1

Homely_PlayerHouses_EspurrFullParty_3:
	msgbox Homely_PlayerHouses_EspurrFullParty_Text_1, MSGBOX_DEFAULT
	goto Homely_PlayerHouses_EspurrFullParty_1

Homely_PlayerHouses_EspurrFullParty_5:
	goto_if_set FLAG_ESPURR_GENDER, Homely_PlayerHouses_EspurrFullParty_3
	goto Homely_PlayerHouses_EspurrFullParty_4

Homely_PlayerHouses_EspurrFullParty_8:
	goto_if_unset FLAG_ESPURR_GENDER, Homely_PlayerHouses_EspurrFullParty_2
	goto Homely_PlayerHouses_EspurrFullParty_6


Homely_PlayerHouses_EspurrJoin::
	goto_if_set FLAG_CHOSEN_ESPURR_GENDER, Homely_PlayerHouses_EspurrJoin_8
Homely_PlayerHouses_EspurrJoin_6:
	goto_if_set FLAG_CHOSEN_ESPURR_GENDER, Homely_PlayerHouses_EspurrJoin_5
Homely_PlayerHouses_EspurrJoin_4:
	msgbox Homely_PlayerHouses_EspurrJoin_Text_2, MSGBOX_YESNO
Homely_PlayerHouses_EspurrJoin_1:
Homely_PlayerHouses_EspurrJoin_12:
	compare VAR_RESULT, NO
	goto_if_eq Homely_PlayerHouses_EspurrJoin_13
	closemessage
	playfanfare MUS_DP_EVOLVED
	msgbox Homely_PlayerHouses_EspurrJoin_Text_6, MSGBOX_DEFAULT
	waitfanfare
	delay 20
	closemessage
	setflag FLAG_HIDE_BRENDANS_HOUSE_ESPURR
	setflag FLAG_HIDE_MAYS_HOUSE_ESPURR
	givemon SPECIES_ESPURR, 20
	goto Homely_PlayerHouses_EspurrEvolve
	return

Homely_PlayerHouses_EspurrJoin_2:
	msgbox Homely_PlayerHouses_EspurrJoin_Text_0, MSGBOX_YESNO
	goto Homely_PlayerHouses_EspurrJoin_1

Homely_PlayerHouses_EspurrJoin_3:
	msgbox Homely_PlayerHouses_EspurrJoin_Text_1, MSGBOX_YESNO
	goto Homely_PlayerHouses_EspurrJoin_1

Homely_PlayerHouses_EspurrJoin_5:
	goto_if_set FLAG_ESPURR_GENDER, Homely_PlayerHouses_EspurrJoin_3
	goto Homely_PlayerHouses_EspurrJoin_4

Homely_PlayerHouses_EspurrJoin_8:
	goto_if_unset FLAG_ESPURR_GENDER, Homely_PlayerHouses_EspurrJoin_2
	goto Homely_PlayerHouses_EspurrJoin_6

Homely_PlayerHouses_EspurrJoin_13:
	goto_if_set FLAG_CHOSEN_ESPURR_GENDER, Homely_PlayerHouses_EspurrJoin_21
Homely_PlayerHouses_EspurrJoin_19:
	goto_if_set FLAG_CHOSEN_ESPURR_GENDER, Homely_PlayerHouses_EspurrJoin_18
Homely_PlayerHouses_EspurrJoin_17:
	msgbox Homely_PlayerHouses_EspurrJoin_Text_5, MSGBOX_YESNO
	goto Homely_PlayerHouses_EspurrJoin_12

Homely_PlayerHouses_EspurrJoin_15:
	msgbox Homely_PlayerHouses_EspurrJoin_Text_3, MSGBOX_YESNO
	goto Homely_PlayerHouses_EspurrJoin_12

Homely_PlayerHouses_EspurrJoin_16:
	msgbox Homely_PlayerHouses_EspurrJoin_Text_4, MSGBOX_YESNO
	goto Homely_PlayerHouses_EspurrJoin_12

Homely_PlayerHouses_EspurrJoin_18:
	goto_if_set FLAG_ESPURR_GENDER, Homely_PlayerHouses_EspurrJoin_16
	goto Homely_PlayerHouses_EspurrJoin_17

Homely_PlayerHouses_EspurrJoin_21:
	goto_if_unset FLAG_ESPURR_GENDER, Homely_PlayerHouses_EspurrJoin_15
	goto Homely_PlayerHouses_EspurrJoin_19


Homely_PlayerHouses_EspurrEvolve::
	goto_if_set FLAG_CHOSEN_ESPURR_GENDER, Homely_PlayerHouses_EspurrEvolve_8
Homely_PlayerHouses_EspurrEvolve_6:
	goto_if_set FLAG_CHOSEN_ESPURR_GENDER, Homely_PlayerHouses_EspurrEvolve_5
Homely_PlayerHouses_EspurrEvolve_4:
	goto Homely_PlayerHouses_EspurrChooseGender
Homely_PlayerHouses_EspurrEvolve_1:
	setvar VAR_TEMP_0, 2
	callnative EvolvePartyMonToSpecies
	removeobject VAR_TEMP_5
	end

Homely_PlayerHouses_EspurrEvolve_2:
	call Homely_PlayerHouses_EspurrPreEvolution
	setvar VAR_0x8001, SPECIES_MEOWSTIC_MALE
	goto Homely_PlayerHouses_EspurrEvolve_1

Homely_PlayerHouses_EspurrEvolve_3:
	call Homely_PlayerHouses_EspurrPreEvolution
	setvar VAR_0x8001, SPECIES_MEOWSTIC_FEMALE
	goto Homely_PlayerHouses_EspurrEvolve_1

Homely_PlayerHouses_EspurrEvolve_5:
	goto_if_set FLAG_ESPURR_GENDER, Homely_PlayerHouses_EspurrEvolve_3
	goto Homely_PlayerHouses_EspurrEvolve_4

Homely_PlayerHouses_EspurrEvolve_8:
	goto_if_unset FLAG_ESPURR_GENDER, Homely_PlayerHouses_EspurrEvolve_2
	goto Homely_PlayerHouses_EspurrEvolve_6


Homely_PlayerHouses_EspurrAfterEvolve::
	delay 30
	applymovement VAR_TEMP_1, FaceRight
	applymovement VAR_TEMP_2, FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, FaceLeft
	waitmovement 0
	delay 20
	msgbox Homely_PlayerHouses_EspurrAfterEvolve_Text_0, MSGBOX_DEFAULT
	delay 30
	msgbox Homely_PlayerHouses_EspurrAfterEvolve_Text_1, MSGBOX_DEFAULT
	closemessage
	copyvar VAR_0x8004, VAR_TEMP_F
	call Common_EventScript_NameReceivedPartyMon
	goto Homely_PlayerHouses_DinnerEnd
	return


Homely_PlayerHouses_EspurrChooseGender::
	applymovement VAR_TEMP_1, FaceRight
	applymovement VAR_TEMP_2, FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, FaceLeft
	waitmovement 0
	msgbox Homely_PlayerHouses_EspurrChooseGender_Text_0, MSGBOX_DEFAULT
	multichoice 4, 8, MULTI_POPPY_PEDRO, TRUE
	compare VAR_RESULT, 0
	goto_if_eq Homely_PlayerHouses_EspurrChooseGender_2
	compare VAR_RESULT, 1
	goto_if_eq Homely_PlayerHouses_EspurrChooseGender_3
Homely_PlayerHouses_EspurrChooseGender_1:
	setflag FLAG_CHOSEN_ESPURR_GENDER
	goto Homely_PlayerHouses_EspurrEvolve
	return

Homely_PlayerHouses_EspurrChooseGender_2:
	setflag FLAG_ESPURR_GENDER
	msgbox Homely_PlayerHouses_EspurrChooseGender_Text_1, MSGBOX_DEFAULT
	goto Homely_PlayerHouses_EspurrChooseGender_1

Homely_PlayerHouses_EspurrChooseGender_3:
	msgbox Homely_PlayerHouses_EspurrChooseGender_Text_2, MSGBOX_DEFAULT
	goto Homely_PlayerHouses_EspurrChooseGender_1


Homely_PlayerHouses_EspurrPreEvolution::
	call Common_EventScript_GetGiftMonPartySlot
	copyvar VAR_TEMP_F, VAR_0x8004
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Exclaim
	msgbox Homely_PlayerHouses_EspurrPreEvolution_Text_0, MSGBOX_DEFAULT
	delay 20
	closemessage
	copyvar VAR_0x8000, VAR_TEMP_F
	setvar VAR_0x8002, FALSE
	return


Homely_PlayerHouses_DinnerEnd::
	msgbox Homely_PlayerHouses_DinnerEnd_Text_0, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement VAR_TEMP_2, Exclaim
	msgbox Homely_PlayerHouses_DinnerEnd_Text_1, MSGBOX_DEFAULT
	closemessage
	getplayerxy VAR_TEMP_A, VAR_TEMP_B
	fadescreen FADE_TO_BLACK
	delay 60
	playse SE_EXIT
	delay 30
	msgbox Homely_PlayerHouses_DinnerEnd_Text_2, MSGBOX_DEFAULT
	closemessage
	delay 20
	giveitem ITEM_HM03
	completequest HOMELY
	setflag FLAG_RECEIVED_HM03
	setvar VAR_PETALBURG_CITY_STATE, 5
	clearflag FLAG_SET_HOMELY_STATE
	setflag FLAG_HIDE_PETALBURG_FAMILY
	initclock 9, 0
	clearflag FLAG_SYS_REAL_TIME
	setvar VAR_FLYING_TAXI, 2
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Homely_PlayerHouses_DinnerEnd_2
	setflag FLAG_HIDE_BOREA_GLADE_BRENDANS_HOUSE_MOM
	clearflag FLAG_HIDE_BOREA_GLADE_MAYS_HOUSE_MOM
	setflag FLAG_HIDE_BRENDANS_HOUSE_DAD
	clearflag FLAG_HIDE_MAYS_HOUSE_DAD
	setflag FLAG_HIDE_BRENDANS_HOUSE_DIANCIE
	clearflag FLAG_HIDE_MAYS_HOUSE_DIANCIE
	setflag FLAG_HIDE_BRENDANS_HOUSE_ESPURR
	setflag FLAG_HIDE_MAYS_HOUSE_ESPURR
	setrespawn HEAL_LOCATION_BOREA_GLADE_MAYS_HOUSE
	warpsilent MAP_BOREA_GLADE_MAYS_HOUSE_2F, 4, 2
Homely_PlayerHouses_DinnerEnd_1:
	waitstate
	return

Homely_PlayerHouses_DinnerEnd_2:
	clearflag FLAG_HIDE_BOREA_GLADE_BRENDANS_HOUSE_MOM
	setflag FLAG_HIDE_BOREA_GLADE_MAYS_HOUSE_MOM
	clearflag FLAG_HIDE_BRENDANS_HOUSE_DAD
	setflag FLAG_HIDE_MAYS_HOUSE_DAD
	clearflag FLAG_HIDE_BRENDANS_HOUSE_DIANCIE
	setflag FLAG_HIDE_MAYS_HOUSE_DIANCIE
	setflag FLAG_HIDE_BRENDANS_HOUSE_ESPURR
	setflag FLAG_HIDE_MAYS_HOUSE_ESPURR
	setrespawn HEAL_LOCATION_BOREA_GLADE_BRENDANS_HOUSE
	warpsilent MAP_BOREA_GLADE_BRENDANS_HOUSE_2F, 4, 2
	goto Homely_PlayerHouses_DinnerEnd_1


Homely_PlayerHouses_DoorTrigger::
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, WalkUp
	goto_if_set FLAG_CHOSEN_ESPURR_GENDER, Homely_PlayerHouses_DoorTrigger_8
Homely_PlayerHouses_DoorTrigger_6:
	goto_if_set FLAG_CHOSEN_ESPURR_GENDER, Homely_PlayerHouses_DoorTrigger_5
Homely_PlayerHouses_DoorTrigger_4:
	msgbox Homely_PlayerHouses_DoorTrigger_Text_2, MSGBOX_DEFAULT
Homely_PlayerHouses_DoorTrigger_1:
	waitmovement 0
	closemessage
	return

Homely_PlayerHouses_DoorTrigger_2:
	msgbox Homely_PlayerHouses_DoorTrigger_Text_0, MSGBOX_DEFAULT
	goto Homely_PlayerHouses_DoorTrigger_1

Homely_PlayerHouses_DoorTrigger_3:
	msgbox Homely_PlayerHouses_DoorTrigger_Text_1, MSGBOX_DEFAULT
	goto Homely_PlayerHouses_DoorTrigger_1

Homely_PlayerHouses_DoorTrigger_5:
	goto_if_set FLAG_ESPURR_GENDER, Homely_PlayerHouses_DoorTrigger_3
	goto Homely_PlayerHouses_DoorTrigger_4

Homely_PlayerHouses_DoorTrigger_8:
	goto_if_unset FLAG_ESPURR_GENDER, Homely_PlayerHouses_DoorTrigger_2
	goto Homely_PlayerHouses_DoorTrigger_6


Homely_PlayerHouses_RoomTrigger::
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, WalkDown
	goto_if_set FLAG_CHOSEN_ESPURR_GENDER, Homely_PlayerHouses_RoomTrigger_8
Homely_PlayerHouses_RoomTrigger_6:
	goto_if_set FLAG_CHOSEN_ESPURR_GENDER, Homely_PlayerHouses_RoomTrigger_5
Homely_PlayerHouses_RoomTrigger_4:
	msgbox Homely_PlayerHouses_DoorTrigger_Text_2, MSGBOX_DEFAULT
Homely_PlayerHouses_RoomTrigger_1:
	waitmovement 0
	closemessage
	return

Homely_PlayerHouses_RoomTrigger_2:
	msgbox Homely_PlayerHouses_DoorTrigger_Text_0, MSGBOX_DEFAULT
	goto Homely_PlayerHouses_RoomTrigger_1

Homely_PlayerHouses_RoomTrigger_3:
	msgbox Homely_PlayerHouses_DoorTrigger_Text_1, MSGBOX_DEFAULT
	goto Homely_PlayerHouses_RoomTrigger_1

Homely_PlayerHouses_RoomTrigger_5:
	goto_if_set FLAG_ESPURR_GENDER, Homely_PlayerHouses_RoomTrigger_3
	goto Homely_PlayerHouses_RoomTrigger_4

Homely_PlayerHouses_RoomTrigger_8:
	goto_if_unset FLAG_ESPURR_GENDER, Homely_PlayerHouses_RoomTrigger_2
	goto Homely_PlayerHouses_RoomTrigger_6


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
	walk_down
	walk_down
	walk_left
	walk_left
	face_down
	delay_16
	walk_in_place_down
	walk_in_place_down
	delay_16
	walk_left
	face_down
	delay_16
	walk_in_place_down
	delay_16
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	delay_16
	walk_in_place_left
	step_end

Homely_Movement_BrendansHouse_PlayerWalkToEspurr:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Homely_Movement_MaysHouse_PlayerWalkToEspurr:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Homely_Movement_BrendansHouse_PlayerWalkToBedLeft:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	delay_16
	set_invisible
	step_end

Homely_Movement_BrendansHouse_PlayerWalkToBedUp:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	delay_16
	set_invisible
	step_end

Homely_Movement_BrendansHouse_PlayerWalkToBedDown:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_16
	set_invisible
	step_end

Homely_Movement_BrendansHouse_PlayerWalkToBedRight:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	delay_16
	set_invisible
	step_end

Homely_Movement_MaysHouse_PlayerWalkToBedLeft:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	delay_16
	set_invisible
	step_end

Homely_Movement_MaysHouse_PlayerWalkToBedUp:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	delay_16
	set_invisible
	step_end

Homely_Movement_MaysHouse_PlayerWalkToBedDown:
	walk_down
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	delay_16
	set_invisible
	step_end

Homely_Movement_MaysHouse_DadWalkOutOfWay:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	face_right
	step_end

Homely_Movement_MaysHouse_MomWalkOutOfWay:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	face_right
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

Homely_PlayerHouses_EspurrFullParty_Text_0:
	.string "PEDRO looks determined to start\n"
	.string "battling alongside {STR_VAR_1}.\p"
	.string "I should prepare a space in my\n"
	.string "party so he can join.$"

Homely_PlayerHouses_EspurrFullParty_Text_1:
	.string "POPPY looks determined to start\n"
	.string "battling alongside {STR_VAR_1}.\p"
	.string "I should prepare a space in my\n"
	.string "party so she can join.$"

Homely_PlayerHouses_EspurrFullParty_Text_2:
	.string "ESPURR looks determined to start\n"
	.string "battling alongside {STR_VAR_1}.\p"
	.string "I should prepare a space in my\n"
	.string "party so it can join.$"

Homely_PlayerHouses_EspurrJoin_Text_0:
	.string "PEDRO looks determined to start\n"
	.string "battling alongside {STR_VAR_1}.\l"
	.string "Should he join your party?$"

Homely_PlayerHouses_EspurrJoin_Text_1:
	.string "POPPY looks determined to start\n"
	.string "battling alongside {STR_VAR_1}.\l"
	.string "Should she join your party?$"

Homely_PlayerHouses_EspurrJoin_Text_2:
	.string "ESPURR looks determined to start\n"
	.string "battling alongside {STR_VAR_1}.\l"
	.string "Should it join your party?$"

Homely_PlayerHouses_EspurrJoin_Text_3:
	.string "Are you sure?\n"
	.string "Should PEDRO join your party?$"

Homely_PlayerHouses_EspurrJoin_Text_4:
	.string "Are you sure?\n"
	.string "Should POPPY join your party?$"

Homely_PlayerHouses_EspurrJoin_Text_5:
	.string "Are you sure?\n"
	.string "Should ESPURR join your party?$"

Homely_PlayerHouses_EspurrJoin_Text_6:
	.string "ESPURR joined you on your adventure!$"

Homely_PlayerHouses_EspurrAfterEvolve_Text_0:
	.string "DAD: Wow!\p"
	.string "ESPURR just evolved into a MEOWSTIC!\p"
	.string "Purely out of love for you, {PLAYER}!$"

Homely_PlayerHouses_EspurrAfterEvolve_Text_1:
	.string "MOM: That is truly amazing!\p"
	.string "I'll leave you to officially\n"
	.string "give MEOWSTIC a name.$"

Homely_PlayerHouses_EspurrChooseGender_Text_0:
	.string "MOM: Wow, {PLAYER}!\p"
	.string "I'm surprised such a shy POKéMON\n"
	.string "decided to go with you.\p"
	.string "I've been calling ESPURR “NORTI TORTI”,\n"
	.string "but we need to settle on a name.\l"
	.string "What do you think?$"

Homely_PlayerHouses_EspurrChooseGender_Text_1:
	.string "MOM: I knew it, that's the most\n"
	.string "wonderful name for her.\p"
	.string "ESPURR is so very shy, but I just know\n"
	.string "some adventure would do her good…$"

Homely_PlayerHouses_EspurrChooseGender_Text_2:
	.string "MOM: I knew it, that's the most\n"
	.string "wonderful name for him.\p"
	.string "ESPURR is so very shy, but I just know\n"
	.string "some adventure would do him good…$"

Homely_PlayerHouses_EspurrPreEvolution_Text_0:
	.string "… … … … … …\n"
	.string "Oh?\l"
	.string "What's this?$"

Homely_PlayerHouses_DinnerEnd_Text_0:
	.string "MOM: What an eventful day it's been!\n"
	.string "You've done so much, {PLAYER}.\p"
	.string "Two evolutions, a new gym badge,\n"
	.string "even defeating TEAM AQUA.\l"
	.string "You must be tired!$"

Homely_PlayerHouses_DinnerEnd_Text_1:
	.string "DAD: Before I forget!\p"
	.string "WALLY's DAD dropped something off,\n"
	.string "I left it in your room.\p"
	.string "I think you'll find it useful, so be sure\n"
	.string "to thank him when you get the chance.\l"
	.string "Check it out before you head to sleep.$"

Homely_PlayerHouses_DinnerEnd_Text_2:
	.string "There's a gift from WALLY's DAD\n"
	.string "with a note alongside it.\p"
	.string "… … … … … …\n"
	.string "“Dear {PLAYER},\p"
	.string "Since he went to VERDANTURF TOWN,\n"
	.string "WALLY has become very healthy.\l"
	.string "We owe it all to you!\p"
	.string "When WALLY left town, you helped\n"
	.string "our boy catch a POKéMON.\l"
	.string "That made him extremely happy.\p"
	.string "Actually, not just WALLY.\n"
	.string "It made me, his father, happy too.\p"
	.string "I'm happy that he's gained such a\n"
	.string "great friend as you.\p"
	.string "This isn't a bribe or anything, but\n"
	.string "I'd really like you to have this.\p"
	.string "If your POKéMON can learn SURF,\n"
	.string "they can take you on new adventures.\l"
	.string "Try exploring ROUTE 118 with it!”$"

Homely_PlayerHouses_DoorTrigger_Text_0:
	.string "I should probably talk to\n"
	.string "PEDRO before I leave.$"

Homely_PlayerHouses_DoorTrigger_Text_1:
	.string "I should probably talk to\n"
	.string "POPPY before I leave.$"

Homely_PlayerHouses_DoorTrigger_Text_2:
	.string "I should probably talk to\n"
	.string "ESPURR before I leave.$"
