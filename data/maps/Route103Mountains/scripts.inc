Route103Mountains_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route103Mountains_MapScripts_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Route103Mountains_EventScript_OnTransition
	.byte 0
	
Route103Mountains_MapScripts_OnLoad:
	call_if_set FLAG_SYS_DEMO_MODE, Route103Mountains_EventScript_DemoMetatile
	return

Route103Mountains_EventScript_DemoMetatile:
	setmetatile 15, 15, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 15, 14, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 7, 19, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 7, 20, METATILE_General_RockWall_GrassBase, TRUE
	special DrawWholeMapView
	end

Route103Mountains_EventScript_OnTransition:
	special GetTimeOfDay
	goto_if_eq VAR_RESULT, 0, Route103Mountains_OnTransition_Day
	goto_if_eq VAR_RESULT, 1, Route103Mountains_OnTransition_Twilight
	goto_if_eq VAR_RESULT, 2, Route103Mountains_OnTransition_Night
	end

Route103Mountains_OnTransition_Day:
	setvar VAR_TIMEOFDAY, 0
	end

Route103Mountains_OnTransition_Twilight:
	setvar VAR_TIMEOFDAY, 1
	end

Route103Mountains_OnTransition_Night:
	setvar VAR_TIMEOFDAY, 2
	end

Homely_Route103Mountains_Outside_SamuelLauren::
	msgbox Homely_Route103Mountains_Outside_SamuelLauren_Text_0, MSGBOX_SIGN
	delay 60
	msgbox Homely_Route103Mountains_Outside_SamuelLauren_Text_1, MSGBOX_SIGN
	goto_if_set FLAG_HIDE_QUEEN_ABSOL, Homely_Route103Mountains_Outside_SamuelLauren_1
	return

Homely_Route103Mountains_Outside_SamuelLauren_1:
	playse SE_PIN
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement 6, Homely_LookUp_Exclaim
	applymovement 7, Homely_LookUp_Exclaim
	waitse
	waitmovement 0
	msgbox Homely_Route103Mountains_Outside_SamuelLauren_Text_2, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox Homely_Route103Mountains_Outside_SamuelLauren_Text_3, MSGBOX_DEFAULT
	applymovement 6, Homely_Talk_FacingUp
	applymovement 7, Homely_Talk_FacingUp
	applymovement OBJ_EVENT_ID_PLAYER, Homely_Talk_FacingDown
	waitmovement 0
	msgbox Homely_Route103Mountains_Outside_SamuelLauren_Text_4, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox Homely_Route103Mountains_Outside_SamuelLauren_Text_5, MSGBOX_DEFAULT
	closemessage
	completequest CALAMITY_QUEEN
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement 6, Homely_Oldale_LaurenSamuel_Leave
	applymovement 7, Homely_Oldale_LaurenSamuel_Leave
	fadescreen FADE_TO_BLACK
	waitmovement 0
	playfanfare MUS_DP_HEAL
	removeobject 6
	removeobject 7
	waitfanfare
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	setflag FLAG_HIDE_OLDALE_FAMILY
	setvar VAR_FLYING_TAXI, 2
	fadescreen FADE_FROM_BLACK
	releaseall
	return


Homely_Route103Mountains_QueenAbsol_Encounter::
	goto_if_unset FLAG_HIDE_QUEEN_ABSOL, Homely_Route103Mountains_QueenAbsol_Encounter_1
	special GetPlayerFacingDirection
	compare VAR_RESULT, DIR_NORTH
	goto_if_eq Homely_Route103Mountains_QueenAbsol_Encounter_8
	applymovement OBJ_EVENT_ID_PLAYER, WalkDown
	return

Homely_Route103Mountains_QueenAbsol_Encounter_1:
	setvar VAR_LAB_LIGHTS, 0
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	delay 8
	applymovement OBJ_EVENT_ID_FOLLOWER, FaceUp
	waitmovement 0
	fadeoutbgm 2
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, Homely_QueenAbsol_CameraPan
	waitmovement 0
	playmoncry SPECIES_QUEEN_ABSOL, CRY_MODE_ENCOUNTER
	applymovement 8, Homely_QueenAbsolJump
	waitmovement 0
	waitmoncry
	delay 30
	setwildbattle SPECIES_QUEEN_ABSOL, 30, ITEM_SCARY_CHARM
	setflag FLAG_SYS_NO_CATCHING
	special RemoveCameraObject
	dowildbattle
	clearflag FLAG_SYS_NO_CATCHING
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_FOLLOWER, EnterPokeballMovement
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Homely_QueenAbsol_PlayerApproach
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, Homely_QueenAbsol_CameraRevert
	waitmovement 0
	special RemoveCameraObject
	delay 30
	playmoncry SPECIES_QUEEN_ABSOL, 0
	msgbox Homely_Route103Mountains_QueenAbsol_Encounter_Text_0, MSGBOX_YESNO
Homely_Route103Mountains_QueenAbsol_Encounter_5:
	compare VAR_RESULT, NO
	goto_if_eq Homely_Route103Mountains_QueenAbsol_Encounter_6
	waitmoncry
	fadescreen FADE_TO_BLACK
	givecustommon SPECIES_QUEEN_ABSOL, 30, , , NATURE_ADAMANT, , 252, 252, , 4, , , 31, 31, , 31, , , MOVE_SWORDS_DANCE, MOVE_BITE, MOVE_QUICK_ATTACK, MOVE_RAZOR_WIND, FALSE
	playmoncry SPECIES_QUEEN_ABSOL, CRY_MODE_DOUBLES
	switch VAR_RESULT
	case MON_GIVEN_TO_PARTY, Homely_Route103Mountains_QueenAbsol_Encounter_13
	case MON_GIVEN_TO_PC, Homely_Route103Mountains_QueenAbsol_Encounter_14
	case MON_CANT_GIVE, Homely_Route103Mountains_QueenAbsol_Encounter_15
Homely_Route103Mountains_QueenAbsol_Encounter_11:
	waitmoncry
	setvar VAR_RESULT, MON_GIVEN_TO_PARTY
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_ne Homely_Route103Mountains_QueenAbsol_Encounter_17
Homely_Route103Mountains_QueenAbsol_Encounter_16:
	fadescreen FADE_FROM_BLACK
	releaseall
	end

Homely_Route103Mountains_QueenAbsol_Encounter_6:
	msgbox Homely_Route103Mountains_QueenAbsol_Encounter_Text_1, MSGBOX_YESNO
	goto Homely_Route103Mountains_QueenAbsol_Encounter_5

Homely_Route103Mountains_QueenAbsol_Encounter_8:
	applymovement OBJ_EVENT_ID_PLAYER, WalkUp
	return

Homely_Route103Mountains_QueenAbsol_Encounter_13:
	msgbox Homely_Route103Mountains_QueenAbsol_Encounter_Text_2, MSGBOX_SIGN
	goto Homely_Route103Mountains_QueenAbsol_Encounter_11

Homely_Route103Mountains_QueenAbsol_Encounter_14:
	msgbox Homely_Route103Mountains_QueenAbsol_Encounter_Text_3, MSGBOX_SIGN
	goto Homely_Route103Mountains_QueenAbsol_Encounter_11

Homely_Route103Mountains_QueenAbsol_Encounter_15:
	msgbox Homely_Route103Mountains_QueenAbsol_Encounter_Text_4, MSGBOX_SIGN
	goto Homely_Route103Mountains_QueenAbsol_Encounter_11

Homely_Route103Mountains_QueenAbsol_Encounter_17:
	goto Homely_Route103Mountains_QueenAbsol_End
	goto Homely_Route103Mountains_QueenAbsol_Encounter_16


Homely_Route103Mountains_QueenAbsol_End::
	removeobject 8
	fadescreen FADE_FROM_BLACK
	releaseall
	end


Homely_Route103Mountains_QueenAbsol::
	playmoncry SPECIES_QUEEN_ABSOL, 0
	msgbox Homely_Route103Mountains_QueenAbsol_Encounter_Text_0, MSGBOX_YESNO
Homely_Route103Mountains_QueenAbsol_2:
	compare VAR_RESULT, NO
	goto_if_eq Homely_Route103Mountains_QueenAbsol_3
	waitmoncry
	fadescreen FADE_TO_BLACK
	givecustommon SPECIES_QUEEN_ABSOL, 30, , , NATURE_ADAMANT, , 252, 252, , 4, , , 31, 31, , 31, , , MOVE_SWORDS_DANCE, MOVE_BITE, MOVE_QUICK_ATTACK, MOVE_RAZOR_WIND, FALSE
	playmoncry SPECIES_QUEEN_ABSOL, CRY_MODE_DOUBLES
	switch VAR_RESULT
	case MON_GIVEN_TO_PARTY, Homely_Route103Mountains_QueenAbsol_7
	case MON_GIVEN_TO_PC, Homely_Route103Mountains_QueenAbsol_8
	case MON_CANT_GIVE, Homely_Route103Mountains_QueenAbsol_9
Homely_Route103Mountains_QueenAbsol_5:
	waitmoncry
	setvar VAR_RESULT, MON_GIVEN_TO_PARTY
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_ne Homely_Route103Mountains_QueenAbsol_11
Homely_Route103Mountains_QueenAbsol_10:
	fadescreen FADE_FROM_BLACK
	releaseall
	end

Homely_Route103Mountains_QueenAbsol_3:
	msgbox Homely_Route103Mountains_QueenAbsol_Encounter_Text_1, MSGBOX_YESNO
	goto Homely_Route103Mountains_QueenAbsol_2

Homely_Route103Mountains_QueenAbsol_7:
	msgbox Homely_Route103Mountains_QueenAbsol_Encounter_Text_2, MSGBOX_SIGN
	goto Homely_Route103Mountains_QueenAbsol_5

Homely_Route103Mountains_QueenAbsol_8:
	msgbox Homely_Route103Mountains_QueenAbsol_Encounter_Text_3, MSGBOX_SIGN
	goto Homely_Route103Mountains_QueenAbsol_5

Homely_Route103Mountains_QueenAbsol_9:
	msgbox Homely_Route103Mountains_QueenAbsol_Encounter_Text_4, MSGBOX_SIGN
	goto Homely_Route103Mountains_QueenAbsol_5

Homely_Route103Mountains_QueenAbsol_11:
	goto Homely_Route103Mountains_QueenAbsol_End
	goto Homely_Route103Mountains_QueenAbsol_10


Homely_LookUp_Exclaim:
	face_up
	emote_exclamation_mark
	step_end

Homely_QueenAbsolJump:
	delay_16
	jump_in_place_down
	delay_8
	jump_in_place_down
	delay_16
	step_end

Homely_QueenAbsol_CameraPan:
	walk_up
	walk_up
	walk_up
	step_end

Homely_QueenAbsol_CameraRevert:
	delay_16
	walk_down
	step_end

Homely_QueenAbsol_PlayerApproach:
	walk_up
	walk_up
	step_end

Homely_Oldale_LaurenSamuel_Leave:
	walk_down
	walk_down
	walk_down
	step_end

Homely_Route103Mountains_Outside_SamuelLauren_Text_0:
	.string "MOM: You sent our child to do what-?!$"

Homely_Route103Mountains_Outside_SamuelLauren_Text_1:
	.string "DAD: {PLAYER} is about to challenge\n"
	.string "the PETALBURG CITY GYM.\p"
	.string "Doing so with an extraordinary team.\n"
	.string "They will be more than fine…$"

Homely_Route103Mountains_Outside_SamuelLauren_Text_2:
	.string "DAD: Ah look, {PLAYER} is here just in\n"
	.string "time to prove me right.$"

Homely_Route103Mountains_Outside_SamuelLauren_Text_3:
	.string "MOM: Oh my {PLAYER}, are you okay?$"

Homely_Route103Mountains_Outside_SamuelLauren_Text_4:
	.string "MOM: Wow… I don't believe it…\n"
	.string "Your DAD… He… He was…\l"
	.string "He was right…\p"
	.string "Well, I'm glad to hear it!\n"
	.string "I should've had more faith in you.\l"
	.string "You even have new company with you.$"

Homely_Route103Mountains_Outside_SamuelLauren_Text_5:
	.string "DAD: Well, this will be interesting.\n"
	.string "IGGY told me about this POKéMON…\l"
	.string "ABSOL is a sign of CALMITY to come.\p"
	.string "It must be a sign of some BAD OMEN\n"
	.string "that will occur in the area.\l"
	.string "I hope I'm wrong…\p"
	.string "Regardless…\n"
	.string "You're really coming along {PLAYER}.\l"
	.string "I'm excited for our battle.\p"
	.string "Speaking of, it's time we be off.\n"
	.string "See you in PETALBURG CITY, {PLAYER}.\l"
	.string "For sure this time.$"

Homely_Route103Mountains_QueenAbsol_Encounter_Text_0:
	.string "ABSOL seems to bow toward you…\n"
	.string "Would you like to use a POKé BALL?$"

Homely_Route103Mountains_QueenAbsol_Encounter_Text_1:
	.string "Are you sure?\n"
	.string "Would you like to use a POKé BALL?$"

Homely_Route103Mountains_QueenAbsol_Encounter_Text_2:
	.string "ABSOL has joined your PARTY!$"

Homely_Route103Mountains_QueenAbsol_Encounter_Text_3:
	.string "ABSOL has been sent to your PC!$"

Homely_Route103Mountains_QueenAbsol_Encounter_Text_4:
	.string "ABSOL tried to join your team but was\n"
	.string "unable to.$"
