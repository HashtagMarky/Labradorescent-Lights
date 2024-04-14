HomelyJourney_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, HomelyJourney_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, HomelyJourney_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

HomelyJourney_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	gettime
	compare VAR_0x8000, 21
	goto_if_ge HomelyJourney_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	compare VAR_0x8000, 5
	goto_if_lt HomelyJourney_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	compare VAR_0x8000, 5
	goto_if_ge HomelyJourney_MapScripts_MAP_SCRIPT_ON_TRANSITION_8
HomelyJourney_MapScripts_MAP_SCRIPT_ON_TRANSITION_6:
	compare VAR_0x8000, 17
	goto_if_ge HomelyJourney_MapScripts_MAP_SCRIPT_ON_TRANSITION_5
HomelyJourney_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
	return

HomelyJourney_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	initclock 7, 0
	return

HomelyJourney_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	initclock 13, 0
	return

HomelyJourney_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
	initclock 7, 0
	return

HomelyJourney_MapScripts_MAP_SCRIPT_ON_TRANSITION_5:
	compare VAR_0x8000, 21
	goto_if_lt HomelyJourney_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
	goto HomelyJourney_MapScripts_MAP_SCRIPT_ON_TRANSITION_4

HomelyJourney_MapScripts_MAP_SCRIPT_ON_TRANSITION_8:
	compare VAR_0x8000, 9
	goto_if_lt HomelyJourney_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	goto HomelyJourney_MapScripts_MAP_SCRIPT_ON_TRANSITION_6

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
	goto Homely_EventScript_Petalburg_Leave
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


Homely_EventScript_Petalburg_Leave::
	applymovement 1, Homely_Petalburg_Samuel_Leave
	applymovement 2, Homely_Petalburg_Infernape_Leave
	applymovement OBJ_EVENT_ID_PLAYER, Homely_Petalburg_Player_Leave
	waitmovement 0
	msgbox Homely_EventScript_Petalburg_Leave_Text_0, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Homely_Talk_FacingDown
	applymovement OBJ_EVENT_ID_PLAYER, Homely_Talk_FacingUp
	waitmovement 0
	special SpawnCameraObject
	applymovement 1, Homely_Petalburg_Fadescreen
	applymovement 2, Homely_Petalburg_Fadescreen
	applymovement OBJ_EVENT_ID_PLAYER, Homely_Petalburg_Fadescreen
	fadescreenspeed FADE_TO_BLACK, 4
	waitmovement 0
	goto Homely_EventScript_MoveToRoute102
	return


Homely_EventScript_MoveToRoute102::
	setobjectxy OBJ_EVENT_ID_PLAYER, 8, 30
	setobjectxy OBJ_EVENT_ID_FOLLOWER, 8, 29
	applymovement OBJ_EVENT_ID_CAMERA, Homely_Camera_PetalburgToRoute102
	waitmovement 0
	goto Homely_EventScript_Route102_TalkToSamuel
	return


Homely_EventScript_Route102_TalkToSamuel::
	applymovement 3, Homely_Route102_Samuel_FromFadescreen
	applymovement 4, Homely_Route102_Infernape_FromFadescreen
	applymovement OBJ_EVENT_ID_PLAYER, Homely_Route102_Player_FromFadescreen
	fadescreenspeed FADE_FROM_BLACK, 4
	waitmovement 0
	msgbox Homely_EventScript_Route102_TalkToSamuel_Text_0, MSGBOX_DEFAULT
	closemessage
	applymovement 3, Homely_Talk_FacingLeft
	applymovement OBJ_EVENT_ID_PLAYER, Homely_Talk_FacingRight
	waitmovement 0
	applymovement 3, Homely_Route102_Samuel_Leave
	applymovement 4, Homely_Route102_Infernape_Leave
	applymovement OBJ_EVENT_ID_PLAYER, Homely_Route102_Player_Leave
	delay 80
	fadescreenspeed FADE_TO_BLACK, 4
	waitmovement 0
	goto Homely_EventScript_MoveToOldale
	return


Homely_EventScript_MoveToOldale::
	setobjectxy OBJ_EVENT_ID_PLAYER, 7, 55
	setobjectxy OBJ_EVENT_ID_FOLLOWER, 6, 55
	applymovement OBJ_EVENT_ID_CAMERA, Homely_Camera_Route102ToOldale
	waitmovement 0
	gettime
	compare VAR_0x8000, 7
	goto_if_eq Homely_EventScript_MoveToOldale_2
	initclock 18, 0
Homely_EventScript_MoveToOldale_1:
	goto Homely_EventScript_Oldale_TalkToSamuel
	return

Homely_EventScript_MoveToOldale_2:
	initclock 13, 0
	goto Homely_EventScript_MoveToOldale_1


Homely_EventScript_Oldale_TalkToSamuel::
	applymovement 5, Homely_Oldale_Samuel_FromFadescreen
	applymovement 6, Homely_Oldale_Infernape_FromFadescreen
	applymovement OBJ_EVENT_ID_PLAYER, Homely_Oldale_Player_FromFadescreen
	fadescreenspeed FADE_FROM_BLACK, 4
	waitmovement 0
	msgbox Homely_EventScript_Oldale_TalkToSamuel_Text_0, MSGBOX_DEFAULT
	closemessage
	applymovement 5, Homely_Talk_FacingDown
	applymovement OBJ_EVENT_ID_PLAYER, Homely_Talk_FacingUp
	waitmovement 0
	applymovement 5, Homely_Oldale_Samuel_Leave
	applymovement 6, Homely_Oldale_Infernape_Leave
	applymovement OBJ_EVENT_ID_PLAYER, Homely_Oldale_Player_Leave
	delay 128
	fadescreenspeed FADE_TO_BLACK, 4
	waitmovement 0
	goto Homely_EventScript_MoveToRoute101
	return


Homely_EventScript_MoveToRoute101::
	setobjectxy OBJ_EVENT_ID_PLAYER, 17, 76
	setobjectxy OBJ_EVENT_ID_FOLLOWER, 18, 76
	applymovement OBJ_EVENT_ID_CAMERA, Homely_Camera_OldaleToRoute101
	waitmovement 0
	initclock 18, 0
	goto Homely_EventScript_Route101_TalkToSamuel
	return


Homely_EventScript_Route101_TalkToSamuel::
	applymovement 7, Homely_Route101_Samuel_FromFadescreen
	applymovement 8, Homely_Route101_Infernape_FromFadescreen
	applymovement OBJ_EVENT_ID_PLAYER, Homely_Route101_Player_FromFadescreen
	fadescreenspeed FADE_FROM_BLACK, 4
	waitmovement 0
	checkitem ITEM_ESPURR_POKEBALL, 1
	compare VAR_RESULT, TRUE
	goto_if_eq Homely_EventScript_Route101_TalkToSamuel_2
	msgbox Homely_EventScript_Route101_TalkToSamuel_Text_3, MSGBOX_DEFAULT
Homely_EventScript_Route101_TalkToSamuel_1:
	closemessage
	applymovement 7, Homely_Talk_FacingUp
	applymovement OBJ_EVENT_ID_PLAYER, Homely_Talk_FacingDown
	waitmovement 0
	return

Homely_EventScript_Route101_TalkToSamuel_2:
	msgbox Homely_EventScript_Route101_TalkToSamuel_Text_0, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_ESPURR, 0
	delay 20
	applymovement 7, JumpIPUp
	waitmovement 0
	waitmoncry
	delay 30
	applymovement 7, Exclaim
	playse SE_PIN
	goto_if_unset FLAG_ESPURR_GENDER, Homely_EventScript_Route101_TalkToSamuel_6
	msgbox Homely_EventScript_Route101_TalkToSamuel_Text_2, MSGBOX_DEFAULT
Homely_EventScript_Route101_TalkToSamuel_5:
	waitmovement 0
	waitse
	goto Homely_EventScript_Route101_TalkToSamuel_1

Homely_EventScript_Route101_TalkToSamuel_6:
	msgbox Homely_EventScript_Route101_TalkToSamuel_Text_1, MSGBOX_DEFAULT
	goto Homely_EventScript_Route101_TalkToSamuel_5


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

Homely_Talk_FacingUp:
	walk_in_place_up
	delay_16
	walk_in_place_up
	delay_16
	step_end

Homely_Talk_FacingDown:
	delay_8
	walk_in_place_down
	delay_16
	walk_in_place_down
	delay_8
	step_end

Homely_Talk_FacingLeft:
	walk_in_place_left
	delay_16
	walk_in_place_left
	delay_16
	step_end

Homely_Talk_FacingRight:
	delay_8
	walk_in_place_right
	delay_16
	walk_in_place_right
	delay_8
	step_end

Homely_Petalburg_Player_Leave:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	delay_1
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

Homely_Petalburg_Samuel_Leave:
	walk_down
	walk_down
	walk_down
	walk_down
	delay_16
	delay_8
	face_down
	delay_8
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

Homely_Petalburg_Infernape_Leave:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_down
	walk_in_place_down
	walk_down
	delay_1
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Homely_Petalburg_Fadescreen:
	walk_right
	walk_right
	walk_right
	step_end

Homely_Petalburg_Camera_Fadescreen_Reset:
	walk_faster_right
	walk_faster_right
	walk_faster_right
	step_end

Homely_Route102_Player_FromFadescreen:
	walk_down
	walk_down
	walk_down
	face_right
	step_end

Homely_Route102_Samuel_FromFadescreen:
	walk_down
	walk_down
	walk_down
	face_left
	step_end

Homely_Route102_Infernape_FromFadescreen:
	walk_down
	walk_down
	walk_down
	step_end

Homely_Camera_PetalburgToRoute102:
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	step_end

Homely_Route102_Player_Leave:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Homely_Route102_Samuel_Leave:
	walk_down
	walk_down
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Homely_Route102_Infernape_Leave:
	walk_down
	walk_down
	walk_in_place_down
	walk_in_place_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Homely_Camera_Route102ToOldale:
	walk_faster_right
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	step_end

Homely_Oldale_Player_FromFadescreen:
	walk_right
	walk_right
	walk_right
	face_up
	step_end

Homely_Oldale_Samuel_FromFadescreen:
	walk_right
	walk_right
	walk_right
	face_down
	step_end

Homely_Oldale_Infernape_FromFadescreen:
	walk_right
	walk_right
	walk_right
	step_end

Homely_Oldale_Player_Leave:
	walk_right
	walk_right
	walk_right
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Homely_Oldale_Samuel_Leave:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Homely_Oldale_Infernape_Leave:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Homely_Camera_OldaleToRoute101:
	walk_faster_left
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	step_end

Homely_Route101_Player_FromFadescreen:
	walk_left
	walk_left
	walk_left
	face_down
	step_end

Homely_Route101_Samuel_FromFadescreen:
	walk_left
	walk_left
	walk_left
	face_up
	step_end

Homely_Route101_Infernape_FromFadescreen:
	walk_left
	walk_left
	walk_left
	step_end

Homely_EventScript_Trigger_Text_0:
	.string "SAMUEL: Come on, {PLAYER}.\n"
	.string "We have a nice walk ahead of us.$"

Homely_EventScript_Petalburg_Leave_Text_0:
	.string "SAMUEL: Here we are {PLAYER}, almost\n"
	.string "at ROUTE 102. Can you remember when\l"
	.string "I sent you on this road with WALLY?\p"
	.string "Developing as a TRAINER…\n"
	.string "Catching so many POKéMON…\l"
	.string "You've come such a long way since then.\p"
	.string "Have you seen WALLY recently?\n"
	.string "How is VERDANTURF TOWN treating him?$"

Homely_EventScript_Route102_TalkToSamuel_Text_0:
	.string "DAD: {PLAYER}, I'm sure you're familiar\n"
	.string "with roaming in the tall grass like this.\p"
	.string "Maybe we'll encounter some wild POKéMON\n"
	.string "on our journey back to BOREA GLADE.\p"
	.string "Did you catch anything on this ROUTE?\n"
	.string "I hope to see them in our battle…$"

Homely_EventScript_Oldale_TalkToSamuel_Text_0:
	.string "DAD: I sometimes like to make a\n"
	.string "pit-stop in OLDALE TOWN on the way\l"
	.string "to the PETLABURG CITY GYM.\p"
	.string "They journey isn't too long but I enjoy\n"
	.string "spending time with the townsfolk here.\p"
	.string "I met and battled a particularly odd\n"
	.string "couple after doing an INTERVIEW about\l"
	.string "my new role as PETALBURG GYM LEADER.\p"
	.string "They travel all over HOENN, so you may\n"
	.string "even run into them at some point.$"

Homely_EventScript_Route101_TalkToSamuel_Text_0:
	.string "DAD: We're almost home now, {PLAYER}.\n"
	.string "I am really looking forward to seeing\l"
	.string "your MOM, DIANCIE & ESPURR.\p"
	.string "I know you must be as well, but this\n"
	.string "has been a nice journey together.$"

Homely_EventScript_Route101_TalkToSamuel_Text_1:
	.string "DAD: Was that--?!\n"
	.string "You have ESPURR with you?!\p"
	.string "Well, I never would've thought that…\n"
	.string "He was always so unadventurous.\p"
	.string "I'm glad he's gotten to see the world by\n"
	.string "accompanying you on your travels.\p"
	.string "Even if we don't make a batller of him,\n"
	.string "he can show off how handsome he is,\l"
	.string "at the POKéMON CONTEST HALL.$"

Homely_EventScript_Route101_TalkToSamuel_Text_2:
	.string "DAD: Was that--?!\n"
	.string "You have ESPURR with you?!\p"
	.string "Well, I never would've thought that…\n"
	.string "She was always so unadventurous.\p"
	.string "I'm glad she's gotten to see the world\n"
	.string "by accompanying you on your travels.\p"
	.string "Even if we don't make a batller of her,\n"
	.string "she can show off how pretty she is,\l"
	.string "at the POKéMON CONTEST HALL.$"

Homely_EventScript_Route101_TalkToSamuel_Text_3:
	.string "DAD: We're almost home now, {PLAYER}.\n"
	.string "I am really looking forward to seeing\l"
	.string "your MOM, DIANCIE & ESPURR.\p"
	.string "I know you must be as well, but this\n"
	.string "has been a nice journey together.\p"
	.string "I heard when you first met my friend,\n"
	.string "PROF. IGNATIUS, that you saved him\l"
	.string "from a wild POKéMON on this very ROUTE.\p"
	.string "It's amazing to hear that you were so\n"
	.string "brave, but it's also very funny…\l"
	.string "He and I met in a very similar way.$"
