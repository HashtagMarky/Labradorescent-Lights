HomelyJourney_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, HomelyJourney_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, HomelyJourney_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

HomelyJourney_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	gettime
	copyvar VAR_RESULT, VAR_0x8000
	compare VAR_RESULT, 13
	goto_if_lt HomelyJourney_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	compare VAR_RESULT, 21
	goto_if_ge HomelyJourney_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	return

HomelyJourney_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	initclock 13, 0
	return

HomelyJourney_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	initclock 8, 0
	return

HomelyJourney_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_1, 0, HomelyJourney_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

HomelyJourney_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	addvar VAR_TEMP_1, 1
	setmetatile 8, 6, METATILE_Petalburg_Door_Gym_Closed, TRUE
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	return


Homely_EventScript_Trigger::
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	getplayerxy VAR_TEMP_A, VAR_TEMP_1
	compare VAR_TEMP_A, 7
	goto_if_eq Homely_EventScript_Trigger_2
	compare VAR_TEMP_A, 8
	goto_if_eq Homely_EventScript_Trigger_3
	compare VAR_TEMP_A, 9
	goto_if_eq Homely_EventScript_Trigger_4
Homely_EventScript_Trigger_1:
	waitmovement 0
	msgbox Homely_EventScript_Trigger_Text_0, MSGBOX_DEFAULT
	closemessage
	goto Homely_EventScript_LeavePetalburg
	return

Homely_EventScript_Trigger_2:
	applymovement 1, Homely_Petalburg_Samuel_TalkToSamuel_Left
	applymovement 2, Homely_Petalburg_Infernape_TalkToSamuel_Left
	applymovement OBJ_EVENT_ID_PLAYER, Homely_Petalburg_Player_TalkToSamuel_Left
	goto Homely_EventScript_Trigger_1

Homely_EventScript_Trigger_3:
	applymovement 1, Homely_Petalburg_Samuel_TalkToSamuel_Middle
	applymovement 2, Homely_Petalburg_Infernape_TalkToSamuel_Middle
	applymovement OBJ_EVENT_ID_PLAYER, Homely_Petalburg_Player_TalkToSamuel_Middle
	goto Homely_EventScript_Trigger_1

Homely_EventScript_Trigger_4:
	applymovement 1, Homely_Petalburg_Samuel_TalkToSamuel_Right
	applymovement 2, Homely_Petalburg_Infernape_TalkToSamuel_Right
	applymovement OBJ_EVENT_ID_PLAYER, Homely_Petalburg_Player_TalkToSamuel_Right
	goto Homely_EventScript_Trigger_1


Homely_EventScript_LeavePetalburg::
	return


Homely_EventScript_GoToRoom::
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	return


Homely_Petalburg_Player_TalkToSamuel_Left:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	step_end

Homely_Petalburg_Player_TalkToSamuel_Middle:
	walk_down
	walk_down
	walk_down
	face_right
	step_end

Homely_Petalburg_Player_TalkToSamuel_Right:
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	face_right
	step_end

Homely_Petalburg_Samuel_TalkToSamuel_Left:
	delay_16
	delay_16
	delay_16
	delay_8
	face_left
	delay_8
	step_end

Homely_Petalburg_Samuel_TalkToSamuel_Middle:
	delay_16
	delay_16
	delay_8
	face_left
	delay_8
	step_end

Homely_Petalburg_Samuel_TalkToSamuel_Right:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	face_left
	delay_8
	step_end

Homely_Petalburg_Infernape_TalkToSamuel_Left:
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	step_end

Homely_Petalburg_Infernape_TalkToSamuel_Middle:
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	step_end

Homely_Petalburg_Infernape_TalkToSamuel_Right:
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	step_end

Homely_EventScript_Trigger_Text_0:
	.string "SAMUEL: Come on, {PLAYER}.\n"
	.string "We have a nice walk ahead of us.$"
