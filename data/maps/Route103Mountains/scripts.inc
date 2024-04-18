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
	goto_if_unset FLAG_HIDE_QUEEN_ABSOL, Homely_Route103Mountains_Outside_SamuelLauren_1
	return

Homely_Route103Mountains_Outside_SamuelLauren_1:
	playse SE_PIN
	applymovement 6, Homely_LookUp_Exclaim
	applymovement 7, Homely_LookUp_Exclaim
	waitse
	waitmovement 0
	msgbox Homely_Route103Mountains_Outside_SamuelLauren_Text_2, MSGBOX_DEFAULT
	applymovement 6, Homely_Talk_FacingUp
	applymovement 7, Homely_Talk_FacingUp
	applymovement OBJ_EVENT_ID_PLAYER, Homely_Talk_FacingDown
	waitmovement 0
	msgbox Homely_Route103Mountains_Outside_SamuelLauren_Text_3, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	playfanfare MUS_DP_HEAL
	removeobject 6
	removeobject 7
	waitfanfare
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	fadescreen FADE_FROM_BLACK
	return


Homely_LookUp_Exclaim:
	face_up
	emote_exclamation_mark
	step_end

Homely_Route103Mountains_Outside_SamuelLauren_Text_0:
	.string "MOM: You sent our child to do what-?!$"

Homely_Route103Mountains_Outside_SamuelLauren_Text_1:
	.string "DAD: {PLAYER} is about to challenge\n"
	.string "the PETALBURG CITY GYM.\p"
	.string "{PLAYER} will be more than fine…$"

Homely_Route103Mountains_Outside_SamuelLauren_Text_2:
	.string "DAD: Ah look, {PLAYER} is here to\n"
	.string "prove me right.\p"
	.string "MOM: Oh my gosh {PLAYER}, are you\n"
	.string "okay?$"

Homely_Route103Mountains_Outside_SamuelLauren_Text_3:
	.string "MOM: Wow…\n"
	.string "Your DAD…\l"
	.string "Was right…\p"
	.string "Well, I'm glad to hear it!\n"
	.string "I should've had more faith in you.\l"
	.string "You even have new company with you.\p"
	.string "DAD: Well, this will be interesting.\n"
	.string "You're really coming along {PLAYER}.\l"
	.string "I'm excited for our battle.\p"
	.string "Speaking of, it's time we be off.\n"
	.string "See you in PETALBURG CITY, {PLAYER}.\l"
	.string "For sure this time.$"
