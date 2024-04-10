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
	msgbox HomelyJourney_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Homely_Samuel_Petalburg_Left_MoveOutOfWay
	applymovement 2, Homely_Infernape_Petalburg_Left_MoveOutOfWay
	waitmovement 0
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	return


Homely_EventScript_TriggerAuto::
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement OBJ_EVENT_ID_PLAYER, WalkDown
	goto Homely_EventScript_Trigger
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
	return

Homely_EventScript_Trigger_2:
	applymovement 1, Homely_Samuel_LeavePetalburg_Left
	applymovement 2, Homely_Infernape_LeavePetalburg_Left
	applymovement OBJ_EVENT_ID_PLAYER, Homely_Player_LeavePetalburg_Left
	goto Homely_EventScript_Trigger_1

Homely_EventScript_Trigger_3:
	applymovement 1, Homely_MeetPlayer_Middle
	goto Homely_EventScript_Trigger_1

Homely_EventScript_Trigger_4:
	applymovement 1, Homely_MeetPlayer_Right
	goto Homely_EventScript_Trigger_1


Homely_EventScript_LetsGoHome::
	compare VAR_TEMP_A, 7
	goto_if_eq Homely_EventScript_LetsGoHome_2
	compare VAR_TEMP_A, 8
	goto_if_eq Homely_EventScript_LetsGoHome_3
	compare VAR_TEMP_A, 9
	goto_if_eq Homely_EventScript_LetsGoHome_4
Homely_EventScript_LetsGoHome_1:
	waitmovement 0
	return

Homely_EventScript_LetsGoHome_2:
	applymovement 1, Homely_Samuel_LeavePetalburg_Left
	applymovement OBJ_EVENT_ID_PLAYER, Homely_Player_LeavePetalburg_Left
	goto Homely_EventScript_LetsGoHome_1

Homely_EventScript_LetsGoHome_3:
	applymovement 1, Homely_Samuel_LeavePetalburg_Middle
	applymovement OBJ_EVENT_ID_PLAYER, Homely_Player_LeavePetalburg_Middle
	goto Homely_EventScript_LetsGoHome_1

Homely_EventScript_LetsGoHome_4:
	applymovement 1, Homely_Samuel_LeavePetalburg_Right
	applymovement OBJ_EVENT_ID_PLAYER, Homely_Player_LeavePetalburg_Right
	goto Homely_EventScript_LetsGoHome_1


Homely_EventScript_GoToRoom::
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	return


Homely_Samuel_Petalburg_Left_MoveOutOfWay:
	delay_16
	delay_16
	walk_right
	face_up
	step_end

Homely_Samuel_LeavePetalburg_Left:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_down
	step_end

Homely_Infernape_Petalburg_Left_MoveOutOfWay:
	walk_right
	walk_up
	walk_up
	face_up
	step_end

Homely_Infernape_LeavePetalburg_Left:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Homely_Player_LeavePetalburg_Left:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

Homely_MeetPlayer_Left:
	walk_up
	walk_left
	walk_up
	step_end

Homely_MeetPlayer_Middle:
	walk_up
	step_end

Homely_MeetPlayer_Right:
	walk_up
	walk_right
	walk_up
	step_end

Homely_Samuel_LeavePetalburg_LeftOld:
	walk_down
	walk_down
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Homely_Samuel_LeavePetalburg_Middle:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Homely_Samuel_LeavePetalburg_Right:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Homely_Player_LeavePetalburg_LeftOld:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Homely_Player_LeavePetalburg_Middle:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Homely_Player_LeavePetalburg_Right:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Homely_Follower_LeavePetalburg_Left:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

HomelyJourney_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0:
	.string "SAMUEL: Come on, {PLAYER}.\n"
	.string "We have a nice walk ahead of us.$"
