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
	closemessage
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
	clearflag FLAG_HIDE_PETALBURG_FAMILY
	setvar VAR_FLYING_TAXI, 2
	setvar VAR_LAB_LIGHTS, 27
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
	addobject 1
	setobjectxy 1, 8, 11
	applymovement 1, Homely_Route103Mountains_Ignatius_Approach
	applymovement OBJ_EVENT_ID_PLAYER, Homely_Route103Mountains_Ignatius_ApproachPlayer
	waitmovement 0
	msgbox Homely_Route103Mountains_QueenAbsol_Encounter_Text_0, MSGBOX_SIGN
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, FaceUp
	waitmovement 0
	playmoncry SPECIES_QUEEN_ABSOL, 0
	msgbox Homely_Route103Mountains_QueenAbsol_Encounter_Text_1, MSGBOX_YESNO
Homely_Route103Mountains_QueenAbsol_Encounter_5:
	compare VAR_RESULT, NO
	goto_if_eq Homely_Route103Mountains_QueenAbsol_Encounter_6
	waitmoncry
	fadescreen FADE_TO_BLACK
	givecustommon SPECIES_QUEEN_ABSOL, 30, , , NATURE_ADAMANT, , 252, 252, , 4, , , 31, 31, , 31, , , MOVE_SWORDS_DANCE, MOVE_BITE, MOVE_QUICK_ATTACK, MOVE_CALAMITY, FALSE
	playmoncry SPECIES_QUEEN_ABSOL, 0
	switch VAR_RESULT
	case MON_GIVEN_TO_PARTY, Homely_Route103Mountains_QueenAbsol_Encounter_13
	case MON_GIVEN_TO_PC, Homely_Route103Mountains_QueenAbsol_Encounter_14
	case MON_CANT_GIVE, Homely_Route103Mountains_QueenAbsol_Encounter_15
Homely_Route103Mountains_QueenAbsol_Encounter_11:
	waitmoncry
	delay 60
	closemessage
	removeobject 8
	applymovement OBJ_EVENT_ID_PLAYER, FaceDown
	fadescreen FADE_FROM_BLACK
	waitmovement 0
	msgbox Homely_Route103Mountains_QueenAbsol_Encounter_Text_6, MSGBOX_SIGN
	applymovement 1, Homely_Route103Mountains_Ignatius_Leave
	waitmovement 0
	removeobject 1
	releaseall
	end

Homely_Route103Mountains_QueenAbsol_Encounter_6:
	msgbox Homely_Route103Mountains_QueenAbsol_Encounter_Text_2, MSGBOX_YESNO
	goto Homely_Route103Mountains_QueenAbsol_Encounter_5

Homely_Route103Mountains_QueenAbsol_Encounter_8:
	applymovement OBJ_EVENT_ID_PLAYER, WalkUp
	return

Homely_Route103Mountains_QueenAbsol_Encounter_13:
	message Homely_Route103Mountains_QueenAbsol_Encounter_Text_3
	goto Homely_Route103Mountains_QueenAbsol_Encounter_11

Homely_Route103Mountains_QueenAbsol_Encounter_14:
	message Homely_Route103Mountains_QueenAbsol_Encounter_Text_4
	goto Homely_Route103Mountains_QueenAbsol_Encounter_11

Homely_Route103Mountains_QueenAbsol_Encounter_15:
	message Homely_Route103Mountains_QueenAbsol_Encounter_Text_5
	goto Homely_Route103Mountains_QueenAbsol_Encounter_11


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

Homely_Route103Mountains_Ignatius_Approach:
	walk_up
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	step_end

Homely_Route103Mountains_Ignatius_ApproachPlayer:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	step_end

Homely_Route103Mountains_Ignatius_Leave:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_down
	step_end

Homely_Route103Mountains_Outside_SamuelLauren_Text_0:
	.string "MOM: You sent our child to do what-?!$"

Homely_Route103Mountains_Outside_SamuelLauren_Text_1:
	.string "DAD: {PLAYER} is about to challenge\n"
	.string "the PETALBURG CITY GYM.\p"
	.string "Doing so with an extraordinary team.\n"
	.string "Plus IGGY went up there as well.\l"
	.string "They will be more than fine…$"

Homely_Route103Mountains_Outside_SamuelLauren_Text_2:
	.string "DAD: Ah look, {PLAYER} is here just in\n"
	.string "time to prove me right.$"

Homely_Route103Mountains_Outside_SamuelLauren_Text_3:
	.string "MOM: Oh my {PLAYER}, are you okay?$"

Homely_Route103Mountains_Outside_SamuelLauren_Text_4:
	.string "MOM: Wow… I don't believe it…\n"
	.string "Your DAD… He… He was…\l"
	.string "He was right… Just wow!\p"
	.string "Well, I'm glad to hear it!\n"
	.string "I should've had more faith in you.\l"
	.string "You even have new company with you.$"

Homely_Route103Mountains_Outside_SamuelLauren_Text_5:
	.string "DAD: Well, this will be interesting.\n"
	.string "IGGY told me about this POKéMON…\p"
	.string "It must be a sign of some BAD OMEN\n"
	.string "that will occur in the area.\l"
	.string "I hope I'm wrong…\p"
	.string "Regardless…\n"
	.string "You're really coming along {PLAYER}.\l"
	.string "I'm excited for our battle.\p"
	.string "Speaking of, it's time we be off.\n"
	.string "We'll see you in PETALBURG CITY.\l"
	.string "For sure this time.$"

Homely_Route103Mountains_QueenAbsol_Encounter_Text_0:
	.string "PROF. IGNATIUS: Well well well…\n"
	.string "Look here, if it isn't {PLAYER}.\p"
	.string "Many people have been looking for this\n"
	.string "POKéMON, the elusive QUEEN ABSOL.\p"
	.string "Many people say she will be the bringer\n"
	.string "of a major CALAMITY across HOENN.\l"
	.string "Although, that may not be the case…\p"
	.string "Correlation is not always causation.\n"
	.string "People would be wise to remember that…\p"
	.string "ABSOL are well known for bringing\n"
	.string "CALAMITY to all those who see them,\l"
	.string "however, I've done the research.\p"
	.string "It is quite the contrary!\p"
	.string "Long ago, before humans could predict\n"
	.string "occurances like earthquakes or tidal\l"
	.string "waves, ABSOL would warn victims.\p"
	.string "The horn on its head can sense these\n"
	.string "occurances well ahead of time.\p"
	.string "They would appear to warn people, so\n"
	.string "that they could protect themselves.\p"
	.string "More recently people have confused the\n"
	.string "appearance of ABSOL as being the root\l"
	.string "cause of all CALAMITY that occurs.\p"
	.string "Though, the appearance of the QUEEN\n"
	.string "ABSOL shows that there may well be\l"
	.string "impending catastrophic danger.\p"
	.string "She seems to repesct you, {PLAYER}…\p"
	.string "Maybe she will allow you to help her\n"
	.string "prevent it from occuring.$"

Homely_Route103Mountains_QueenAbsol_Encounter_Text_1:
	.string "ABSOL seems to bow toward you…\n"
	.string "Would you like to use a POKé BALL?$"

Homely_Route103Mountains_QueenAbsol_Encounter_Text_2:
	.string "The QUEEN ABSOL seems certain!\n"
	.string "Would you like to use a POKé BALL?$"

Homely_Route103Mountains_QueenAbsol_Encounter_Text_3:
	.string "ABSOL has joined your PARTY!$"

Homely_Route103Mountains_QueenAbsol_Encounter_Text_4:
	.string "ABSOL has been sent to your PC!$"

Homely_Route103Mountains_QueenAbsol_Encounter_Text_5:
	.string "ABSOL tried to join your team but was\n"
	.string "unable to.$"

Homely_Route103Mountains_QueenAbsol_Encounter_Text_6:
	.string "PROF IGNATIUS: Take care of ABSOL,\n"
	.string "many people would not be so kind.\l"
	.string "See you in PETALBURG CITY, {PLAYER}.$"
