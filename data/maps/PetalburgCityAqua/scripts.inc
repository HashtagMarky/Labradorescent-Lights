PetalburgCityAqua_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCityAqua_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCityAqua_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

PetalburgCityAqua_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setrespawn HEAL_LOCATION_PETALBURG_CITY_AQUA
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
	goto PetalburgCityAqua_EventScripts_StartAttack
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


PetalburgCityAqua_EventScripts_StartAttack::
	switch VAR_TEMP_A
	case 12, PetalburgCityAqua_EventScripts_StartAttack_3
	case 13, PetalburgCityAqua_EventScripts_StartAttack_3
	case 14, PetalburgCityAqua_EventScripts_StartAttack_3
	case 16, PetalburgCityAqua_EventScripts_StartAttack_4
	applymovement 1, PetalburgCityAqua_Movement_StartAttack_SamuelWalk_Two
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCityAqua_Movement_StartAttack_PlayerWalk_Two
PetalburgCityAqua_EventScripts_StartAttack_1:
	waitmovement 0
	applymovement 9, FaceUp
	applymovement 10, FaceUp
	waitmovement 0
	playse SE_PIN
	applymovement 9, Exclaim
	applymovement 10, Exclaim
	waitmovement 0
	msgbox PetalburgCityAqua_EventScripts_StartAttack_Text_0, MSGBOX_YESNO
PetalburgCityAqua_EventScripts_StartAttack_7:
	compare VAR_RESULT, YES
	goto_if_eq PetalburgCityAqua_EventScripts_StartAttack_8
	msgbox PetalburgCityAqua_EventScripts_StartAttack_Text_2, MSGBOX_SIGN
	special SpawnCameraObject
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_DOWN
	switch VAR_TEMP_A
	case 12, PetalburgCityAqua_EventScripts_StartAttack_12
	case 13, PetalburgCityAqua_EventScripts_StartAttack_12
	case 14, PetalburgCityAqua_EventScripts_StartAttack_12
	setvar VAR_TEMP_B, 2
	applymovement 2, PetalburgCityAqua_Movement_StartAttack_Lauren_Two
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCityAqua_Movement_StartAttack_LaurenOutOfWay_Two
PetalburgCityAqua_EventScripts_StartAttack_10:
	waitmovement 0
	special RemoveCameraObject
	goto PetalburgCityAqua_EventScripts_AttackSetup
	return

PetalburgCityAqua_EventScripts_StartAttack_3:
	applymovement 1, PetalburgCityAqua_Movement_StartAttack_SamuelWalk_One
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCityAqua_Movement_StartAttack_PlayerWalk_One
	goto PetalburgCityAqua_EventScripts_StartAttack_1

PetalburgCityAqua_EventScripts_StartAttack_4:
	applymovement 1, PetalburgCityAqua_Movement_StartAttack_SamuelWalk_Three
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCityAqua_Movement_StartAttack_PlayerWalk_Three
	goto PetalburgCityAqua_EventScripts_StartAttack_1

PetalburgCityAqua_EventScripts_StartAttack_8:
	msgbox PetalburgCityAqua_EventScripts_StartAttack_Text_1, MSGBOX_YESNO
	goto PetalburgCityAqua_EventScripts_StartAttack_7

PetalburgCityAqua_EventScripts_StartAttack_12:
	setvar VAR_TEMP_B, 1
	applymovement 2, PetalburgCityAqua_Movement_StartAttack_Lauren_One
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCityAqua_Movement_StartAttack_LaurenOutOfWay_One
	goto PetalburgCityAqua_EventScripts_StartAttack_10


PetalburgCityAqua_EventScripts_AttackSetup::
	savepartypokemon
	deletepartypokemon
	givecustommon SPECIES_DIANCIE, 30, , , NATURE_RELAXED, , 4, , 252, , , 252, 31, 31, 31, 0, 31, 31, MOVE_ROCK_SLIDE, MOVE_MOONBLAST, MOVE_DEFENSE_CURL, MOVE_DOUBLE_EDGE
	givecustommon SPECIES_INFERNAPE, 31, , , NATURE_JOLLY, , 2, 128, , 252, 128, , 31, 31, 31, 31, 31, 31, MOVE_BLAZE_DANCE, MOVE_INFERNO, MOVE_RAGING_FURY, MOVE_HEAT_STRIKE
	givecustommon SPECIES_CARBINK, 28, , , NATURE_SASSY, , 4, , 252, , , 252, 31, 31, 31, 0, 31, 31, MOVE_ROCK_THROW, MOVE_ROLLOUT, MOVE_DEFENSE_CURL, MOVE_TACKLE
	givecustommon SPECIES_SWABLU, 27, , , NATURE_QUIRKY, , 252, , 128, 2, , 128, 31, 31, 31, 31, 31, 31, MOVE_DISARMING_VOICE, MOVE_DRAGON_BREATH, MOVE_DRAGON_DANCE, MOVE_AERIAL_ACE
	goto PetalburgCityAqua_EventScripts_AttackOne
	return


PetalburgCityAqua_EventScripts_AttackOne::
	msgbox PetalburgCityAqua_EventScripts_AttackOne_Text_0, MSGBOX_DEFAULT
	closemessage
	delay 30
	playse SE_PIN
	applymovement 1, Exclaim
	applymovement OBJ_EVENT_ID_PLAYER, Exclaim
	waitmovement 0
	msgbox PetalburgCityAqua_EventScripts_AttackOne_Text_1, MSGBOX_DEFAULT
	setflag FLAG_PARENTS_BACK_PIC
	closemessage
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT_DOUBLE_NO_MUSIC, TRAINER_GRUNT_ATTACK_1, 9, PetalburgCityAqua_Text_AttackOne_Intro, PetalburgCityAqua_Text_AttackOne_Defeat, PetalburgCityAqua_Text_AttackOne_NoPokemon, PetalburgCityAqua_EventScripts_AttackTwo
	return


PetalburgCityAqua_EventScripts_AttackTwo::
	special HealPlayerParty
	msgbox PetalburgCityAqua_EventScripts_AttackTwo_Text_0, MSGBOX_DEFAULT
	closemessage
	applymovement 9, PetalburgCityAqua_Movement_Grunts_RunAway
	applymovement 10, PetalburgCityAqua_Movement_Grunts_RunAway
	waitmovement 0
	compare VAR_TEMP_B, 1
	goto_if_eq PetalburgCityAqua_EventScripts_AttackTwo_2
	applymovement 1, FaceRight
	applymovement 2, FaceLeft
PetalburgCityAqua_EventScripts_AttackTwo_1:
	waitmovement 0
	delay 30
	msgbox PetalburgCityAqua_EventScripts_AttackTwo_Text_1, MSGBOX_DEFAULT
	return

PetalburgCityAqua_EventScripts_AttackTwo_2:
	applymovement 2, FaceRight
	applymovement 1, FaceLeft
	goto PetalburgCityAqua_EventScripts_AttackTwo_1


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

PetalburgCityAqua_Movement_StartAttack_PlayerWalk_One:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PetalburgCityAqua_Movement_StartAttack_PlayerWalk_Two:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PetalburgCityAqua_Movement_StartAttack_PlayerWalk_Three:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PetalburgCityAqua_Movement_StartAttack_SamuelWalk_One:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PetalburgCityAqua_Movement_StartAttack_SamuelWalk_Two:
	delay_16
	delay_8
	face_down
	delay_1
	delay_2
	delay_4
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PetalburgCityAqua_Movement_StartAttack_SamuelWalk_Three:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PetalburgCityAqua_Movement_StartAttack_Lauren_One:
	delay_16
	set_visible
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

PetalburgCityAqua_Movement_StartAttack_Lauren_Two:
	walk_right
	set_visible
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

PetalburgCityAqua_Movement_StartAttack_LaurenOutOfWay_One:
	delay_16
	delay_16
	delay_16
	lock_facing_direction
	walk_left
	face_down
	unlock_facing_direction
	step_end

PetalburgCityAqua_Movement_StartAttack_LaurenOutOfWay_Two:
	delay_16
	delay_16
	delay_16
	lock_facing_direction
	walk_right
	face_down
	unlock_facing_direction
	step_end

PetalburgCityAqua_Movement_Grunts_RunAway:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	set_invisible
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
	.string "DAD: Let's do it, {PLAYER}.\n"
	.string "But first, to the POKéMON CENTER.$"

PetalburgCityAqua_EventScripts_StartAttack_Text_0:
	.string "SAMUEL: Watch out, {PLAYER}!\p"
	.string "Those two GRUNTS look like their\n"
	.string "getting ready to give us some trouble…\p"
	.string "Wait, you haven't healed your party yet.\n"
	.string "Will you be able to handle this battle?$"

PetalburgCityAqua_EventScripts_StartAttack_Text_1:
	.string "SAMUEL: Are you sure?\n"
	.string "Can your party handle this battle?$"

PetalburgCityAqua_EventScripts_StartAttack_Text_2:
	.string "SAMUEL: Well you may not get\n"
	.string "much of a choice here.$"

PetalburgCityAqua_EventScripts_AttackOne_Text_0:
	.string "MOM: Stay back, {PLAYER}!\p"
	.string "Let your MOM handle this until we\n"
	.string "get you to a POKéMON CENTER.\l"
	.string "I'll battle in your stead!$"

PetalburgCityAqua_EventScripts_AttackOne_Text_1:
	.string "DAD: We're battling together?\n"
	.string "It's been a while…\l"
	.string "Let's get them!$"

PetalburgCityAqua_EventScripts_AttackTwo_Text_0:
	.string "GRUNT 1: You were right!\n"
	.string "Let's get out of here!$"

PetalburgCityAqua_EventScripts_AttackTwo_Text_1:
	.string "MOM: Now wasn't that fun!\n"
	.string "I might have to get back into battling.$"

PetalburgCityAqua_Text_AttackOne_Intro::
	.string "GRUNT 1: You ran all the way here,\n"
	.string "thinking that you can stop us!\l"
	.string "Well trust me, you can't!\p"
	.string "GRUNT 2: Wait, isn't that the gym\n"
	.string "leader around these parts?\l"
	.string "And his wife to boot?$"

PetalburgCityAqua_Text_AttackOne_Defeat::
	.string "GRUNT 1: I guess you two\n"
	.string "really are a good team…\p"
	.string "GRUNT 2: I'm jealous that you two\n"
	.string "can work so well together…$"

PetalburgCityAqua_Text_AttackOne_NoPokemon::
	.string "GRUNT 1: You're right!\n"
	.string "Let's get out of here!$"
