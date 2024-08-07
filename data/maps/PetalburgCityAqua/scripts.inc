PetalburgCityAqua_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCityAqua_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCityAqua_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

PetalburgCityAqua_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setrespawn HEAL_LOCATION_PETALBURG_CITY_AQUA
	clearflag FLAG_HIDE_AQUA_IN_BOREA_PASSAGE
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
	playse SE_SELECT
	goto PetalburgCityAqua_EventScripts_Samuel
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
	goto PetalburgCityAqua_EventScripts_SamuelLookLost
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


PetalburgCityAqua_EventScripts_SamuelLookLost::
	lock
	clearflag FLAG_DONT_TRANSITION_MUSIC
	compare VAR_TEMP_0, 1
	goto_if_ne PetalburgCityAqua_EventScripts_SamuelLookLost_2
PetalburgCityAqua_EventScripts_SamuelLookLost_1:
	msgbox PetalburgCityAqua_EventScripts_SamuelLookLost_Text_0, MSGBOX_DEFAULT
	closemessage
	cleartrainerflag TRAINER_GRUNT_ATTACK_1
	cleartrainerflag TRAINER_GRUNT_ATTACK_2
	delay 60
	goto PetalburgCityAqua_EventScripts_SamuelIntro
	return

PetalburgCityAqua_EventScripts_SamuelLookLost_2:
	faceplayer
	goto PetalburgCityAqua_EventScripts_SamuelLookLost_1


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
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, WalkDown
	waitmovement 0
	special RemoveCameraObject
	applymovement 9, FaceUp
	applymovement 10, FaceUp
	waitmovement 0
	playse SE_PIN
	applymovement 9, Exclaim
	applymovement 10, Exclaim
	waitmovement 0
	msgbox PetalburgCityAqua_EventScripts_StartAttack_Text_0, MSGBOX_DEFAULT
	closemessage
	delay 30
	playse SE_PIN
	applymovement 1, Exclaim
	msgbox PetalburgCityAqua_EventScripts_StartAttack_Text_1, MSGBOX_YESNO
PetalburgCityAqua_EventScripts_StartAttack_7:
	compare VAR_RESULT, YES
	goto_if_eq PetalburgCityAqua_EventScripts_StartAttack_8
	msgbox PetalburgCityAqua_EventScripts_StartAttack_Text_3, MSGBOX_DEFAULT
	closemessage
	special SpawnCameraObject
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
	msgbox PetalburgCityAqua_EventScripts_StartAttack_Text_4, MSGBOX_DEFAULT
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
	msgbox PetalburgCityAqua_EventScripts_StartAttack_Text_2, MSGBOX_YESNO
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
	givecustommon SPECIES_SABLEYE, 28, , , NATURE_RELAXED, , 4, , 252, , , 252, 31, 31, 31, 0, 31, 31, MOVE_FURY_SWIPES, MOVE_FEINT_ATTACK, MOVE_CALM_MIND, MOVE_SHADOW_BALL, TRUE
	givecustommon SPECIES_SWABLU, 27, , , NATURE_QUIRKY, , 252, , 128, 2, , 128, 31, 31, 31, 31, 31, 31, MOVE_DISARMING_VOICE, MOVE_DRAGON_BREATH, MOVE_DRAGON_DANCE, MOVE_AERIAL_ACE
	goto PetalburgCityAqua_EventScripts_AttackOne
	return


PetalburgCityAqua_EventScripts_AttackOne::
	closemessage
	delay 30
	playse SE_PIN
	applymovement 1, Exclaim
	applymovement OBJ_EVENT_ID_PLAYER, Exclaim
	waitmovement 0
	compare VAR_TEMP_B, 1
	goto_if_eq PetalburgCityAqua_EventScripts_AttackOne_2
	applymovement 1, FaceRight
	applymovement 2, FaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, FaceLeft
PetalburgCityAqua_EventScripts_AttackOne_1:
	waitmovement 0
	msgbox PetalburgCityAqua_EventScripts_AttackOne_Text_0, MSGBOX_DEFAULT
	applymovement 1, FaceDown
	applymovement 2, FaceDown
	applymovement OBJ_EVENT_ID_PLAYER, FaceDown
	waitmovement 0
	setflag FLAG_PARENTS_BACK_PIC
	closemessage
	delay 30
	msgbox PetalburgCityAqua_EventScripts_AttackOne_Text_1, MSGBOX_DEFAULT
	closemessage
	delay 30
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT_DOUBLE_NO_MUSIC, TRAINER_GRUNT_ATTACK_1, 9, PetalburgCityAqua_Text_AttackOne_Intro, PetalburgCityAqua_Text_AttackOne_Defeat, PetalburgCityAqua_Text_AttackOne_NoPokemon, PetalburgCityAqua_EventScripts_AttackTwo
	return

PetalburgCityAqua_EventScripts_AttackOne_2:
	applymovement 2, FaceRight
	applymovement 1, FaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, FaceRight
	goto PetalburgCityAqua_EventScripts_AttackOne_1


PetalburgCityAqua_EventScripts_AttackTwo::
	msgbox PetalburgCityAqua_EventScripts_AttackTwo_Text_0, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox PetalburgCityAqua_EventScripts_AttackTwo_Text_1, MSGBOX_DEFAULT
	closemessage
	applymovement 9, PetalburgCityAqua_Movement_Grunts_RunAway
	applymovement 10, PetalburgCityAqua_Movement_Grunts_RunAway
	waitmovement 0
	compare VAR_TEMP_B, 1
	goto_if_eq PetalburgCityAqua_EventScripts_AttackTwo_2
	applymovement 1, FaceRight
	applymovement 2, FaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, FaceLeft
PetalburgCityAqua_EventScripts_AttackTwo_1:
	waitmovement 0
	delay 30
	msgbox PetalburgCityAqua_EventScripts_AttackTwo_Text_2, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox PetalburgCityAqua_EventScripts_AttackTwo_Text_3, MSGBOX_DEFAULT
	closemessage
	compare VAR_TEMP_B, 1
	goto_if_eq PetalburgCityAqua_EventScripts_AttackTwo_6
PetalburgCityAqua_EventScripts_AttackTwo_5:
	applymovement 2, PetalburgCityAqua_Movement_StartAttackTwo
	applymovement 1, PetalburgCityAqua_Movement_StartAttackTwo
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCityAqua_Movement_StartAttackTwo
	waitmovement 0
	playse SE_PIN
	applymovement 14, Exclaim
	applymovement 13, Exclaim
	waitmovement 0
	msgbox PetalburgCityAqua_EventScripts_AttackTwo_Text_4, MSGBOX_DEFAULT
	closemessage
	delay 30
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT_DOUBLE_NO_MUSIC, TRAINER_GRUNT_ATTACK_2, 13, PetalburgCityAqua_Text_AttackTwo_Intro, PetalburgCityAqua_Text_AttackTwo_Defeat, PetalburgCityAqua_Text_AttackTwo_NoPokemon, PetalburgCityAqua_EventScripts_RetreatToPassage
	return

PetalburgCityAqua_EventScripts_AttackTwo_2:
	applymovement 2, FaceRight
	applymovement 1, FaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, FaceRight
	goto PetalburgCityAqua_EventScripts_AttackTwo_1

PetalburgCityAqua_EventScripts_AttackTwo_6:
	applymovement 2, WalkRight
	applymovement 1, WalkRight
	applymovement OBJ_EVENT_ID_PLAYER, WalkRight
	waitmovement 0
	goto PetalburgCityAqua_EventScripts_AttackTwo_5


PetalburgCityAqua_EventScripts_RetreatToPassage::
	msgbox PetalburgCityAqua_EventScripts_RetreatToPassage_Text_0, MSGBOX_DEFAULT
	closemessage
	applymovement 15, PetalburgCityAqua_Movement_ItemBallAppear
	applymovement 11, PetalburgCityAqua_Movement_GruntOne_RunToPassage
	applymovement 12, PetalburgCityAqua_Movement_GruntTwo_RunToPassage
	applymovement 14, PetalburgCityAqua_Movement_GruntThree_RunToPassage
	applymovement 13, PetalburgCityAqua_Movement_GruntFour_RunToPassage
	waitmovement 13
	compare VAR_TEMP_B, 1
	goto_if_eq PetalburgCityAqua_EventScripts_RetreatToPassage_2
	applymovement 1, FaceRight
	applymovement 2, FaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, FaceLeft
PetalburgCityAqua_EventScripts_RetreatToPassage_1:
	waitmovement 0
	msgbox PetalburgCityAqua_EventScripts_RetreatToPassage_Text_1, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox PetalburgCityAqua_EventScripts_RetreatToPassage_Text_2, MSGBOX_DEFAULT
	closemessage
	applymovement 2, FaceDown
	waitmovement 0
	playse SE_PIN
	applymovement 2, Exclaim
	msgbox PetalburgCityAqua_EventScripts_RetreatToPassage_Text_3, MSGBOX_DEFAULT
	waitmovement 0
	closemessage
	applymovement 1, FaceDown
	applymovement OBJ_EVENT_ID_PLAYER, FaceDown
	waitmovement 0
	delay 30
	playse SE_PIN
	applymovement 1, Exclaim
	applymovement OBJ_EVENT_ID_PLAYER, Exclaim
	waitmovement 0
	msgbox PetalburgCityAqua_EventScripts_RetreatToPassage_Text_4, MSGBOX_DEFAULT
	closemessage
	special SpawnCameraObject
	compare VAR_TEMP_B, 1
	goto_if_eq PetalburgCityAqua_EventScripts_RetreatToPassage_6
	applymovement 1, PetalburgCityAqua_BlockSeeItem_Right
	applymovement 2, PetalburgCityAqua_BlockSeeItem_Right
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCityAqua_GoSeeItem_Right
	applymovement OBJ_EVENT_ID_CAMERA, PetalburgCityAqua_CameraSeeItem_Right
PetalburgCityAqua_EventScripts_RetreatToPassage_5:
	waitmovement OBJ_EVENT_ID_PLAYER
	goto PetalburgCityAqua_EventScripts_HealTeam
	return

PetalburgCityAqua_EventScripts_RetreatToPassage_2:
	applymovement 2, FaceRight
	applymovement 1, FaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, FaceRight
	goto PetalburgCityAqua_EventScripts_RetreatToPassage_1

PetalburgCityAqua_EventScripts_RetreatToPassage_6:
	applymovement 2, PetalburgCityAqua_BlockSeeItem_Left
	applymovement 1, PetalburgCityAqua_BlockSeeItem_Left
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCityAqua_GoSeeItem_Left
	applymovement OBJ_EVENT_ID_CAMERA, PetalburgCityAqua_CameraSeeItem_Left
	goto PetalburgCityAqua_EventScripts_RetreatToPassage_5


PetalburgCityAqua_EventScripts_HealTeam::
	giveitem ITEM_MAX_REVIVE, 6
	closemessage
	delay 30
	giveitem ITEM_FULL_RESTORE, 6
	closemessage
	delay 30
	applymovement 15, PetalburgCityAqua_HideItemBall
	applymovement OBJ_EVENT_ID_PLAYER, FaceUp
	waitmovement 15
	msgbox PetalburgCityAqua_EventScripts_HealTeam_Text_0, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_DP_HEAL
	loadpartypokemon
	clearflag FLAG_PARENTS_BACK_PIC
	special HealPlayerParty
	removeitem ITEM_MAX_REVIVE, 6
	removeitem ITEM_FULL_RESTORE, 6
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	waitfanfare
	delay 60
	msgbox PetalburgCityAqua_EventScripts_HealTeam_Text_1, MSGBOX_DEFAULT
	closemessage
	compare VAR_TEMP_B, 1
	goto_if_eq PetalburgCityAqua_EventScripts_HealTeam_2
	applymovement 1, FaceRight
PetalburgCityAqua_EventScripts_HealTeam_1:
	waitmovement 0
	playse SE_PIN
	applymovement 1, Exclaim
	delay 90
	applymovement 1, FaceDown
	msgbox PetalburgCityAqua_EventScripts_HealTeam_Text_2, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_DP_LEVEL_UP
	waitfanfare
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCityAqua_EnterPassage
	waitmovement 0
	warp MAP_BOREA_PASSAGE1F, 2
	waitstate
	return

PetalburgCityAqua_EventScripts_HealTeam_2:
	applymovement 1, FaceLeft
	goto PetalburgCityAqua_EventScripts_HealTeam_1


PetalburgCityAqua_EventScripts_SamuelDefendPetalburg::
	msgbox PetalburgCityAqua_EventScripts_SamuelDefendPetalburg_Text_0, MSGBOX_DEFAULT
	closemessage
	return


PetalburgCityAqua_EventScripts_LaurenDefendPetalburg::
	msgbox PetalburgCityAqua_EventScripts_LaurenDefendPetalburg_Text_0, MSGBOX_DEFAULT
	closemessage
	return


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

PetalburgCityAqua_Movement_StartAttackTwo:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PetalburgCityAqua_Movement_GruntOne_RunToPassage:
	walk_fast_right
	walk_fast_up
	delay_16
	set_invisible
	walk_faster_up
	walk_faster_up
	step_end

PetalburgCityAqua_Movement_GruntTwo_RunToPassage:
	walk_fast_right
	walk_fast_up
	delay_16
	walk_fast_up
	delay_16
	set_invisible
	walk_faster_up
	walk_faster_up
	step_end

PetalburgCityAqua_Movement_GruntThree_RunToPassage:
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	delay_16
	set_invisible
	walk_faster_up
	walk_faster_up
	step_end

PetalburgCityAqua_Movement_GruntFour_RunToPassage:
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	face_up
	delay_16
	walk_fast_up
	delay_16
	set_invisible
	walk_faster_up
	walk_faster_up
	step_end

PetalburgCityAqua_Movement_ItemBallAppear:
	delay_16
	delay_4
	set_visible
	step_end

PetalburgCityAqua_GoSeeItem_Left:
	walk_down
	walk_down
	walk_down
	step_end

PetalburgCityAqua_GoSeeItem_Right:
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

PetalburgCityAqua_CameraSeeItem_Left:
	walk_diag_southwest
	walk_diag_southwest
	step_end

PetalburgCityAqua_CameraSeeItem_Right:
	walk_diag_southwest
	walk_diag_southwest
	step_end

PetalburgCityAqua_BlockSeeItem_Left:
	walk_left
	walk_down
	walk_down
	step_end

PetalburgCityAqua_BlockSeeItem_Right:
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	step_end

PetalburgCityAqua_HideItemBall:
	set_invisible
	walk_faster_down
	walk_faster_down
	walk_faster_down
	step_end

PetalburgCityAqua_EnterPassage:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	delay_16
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
	.string "DAD: Let's do it, {PLAYER}!\n"
	.string "But first, to the POKéMON CENTER.\l"
	.string "Let's get your team rested up.$"

PetalburgCityAqua_EventScripts_SamuelLookLost_Text_0:
	.string "DAD: Are you alright there {PLAYER}?\n"
	.string "You seem lost, was your mind elsewhere…$"

PetalburgCityAqua_EventScripts_StartAttack_Text_0:
	.string "SAMUEL: Watch out, {PLAYER}!\p"
	.string "Those shady characters look like their\n"
	.string "getting ready to give us some trouble…$"

PetalburgCityAqua_EventScripts_StartAttack_Text_1:
	.string "Wait, you haven't healed your party yet!\p"
	.string "They're probably still tired from our\n"
	.string "battle, can they battle again?$"

PetalburgCityAqua_EventScripts_StartAttack_Text_2:
	.string "DAD: Are you sure?\n"
	.string "Can your party handle this battle?$"

PetalburgCityAqua_EventScripts_StartAttack_Text_3:
	.string "DAD: Well you may not get\n"
	.string "much of a choice here.\p"
	.string "My team is weak too, I don't know if I\n"
	.string "can handle them both alone…$"

PetalburgCityAqua_EventScripts_StartAttack_Text_4:
	.string "MOM: Stay back, {PLAYER}!\p"
	.string "Let your MOM handle this until we\n"
	.string "get you to a POKéMON CENTER.\l"
	.string "I'll battle on your behalf!$"

PetalburgCityAqua_EventScripts_AttackOne_Text_0:
	.string "DAD: We're battling together?\n"
	.string "It's been a while…\p"
	.string "Now, this will be some fun.\n"
	.string "Let's get them, my love!$"

PetalburgCityAqua_EventScripts_AttackOne_Text_1:
	.string "GRUNT 1: Even though you ran all the\n"
	.string "way here, you still can't stop us!$"

PetalburgCityAqua_EventScripts_AttackTwo_Text_0:
	.string "GRUNT 1: You were right!\n"
	.string "Let's get out of here!$"

PetalburgCityAqua_EventScripts_AttackTwo_Text_1:
	.string "GRUNT 2: The POKéMON CENTER is still\n"
	.string "shut, the next team can avenge us.$"

PetalburgCityAqua_EventScripts_AttackTwo_Text_2:
	.string "MOM: Now wasn't that alot of fun!\n"
	.string "I may have to start battling again.$"

PetalburgCityAqua_EventScripts_AttackTwo_Text_3:
	.string "DAD: It really was amazing!\n"
	.string "I look forward to doing it more.\l"
	.string "And actually, we may have to!\p"
	.string "They said the POKéMON CENTER is shut,\n"
	.string "so if you don't mind {PLAYER},\l"
	.string "I'll handle this with your MOM.$"

PetalburgCityAqua_EventScripts_AttackTwo_Text_4:
	.string "GRUNT 3: So it was you guys who\n"
	.string "beat those other two GRUNTS.\l"
	.string "We'll make you regret it.$"

PetalburgCityAqua_EventScripts_RetreatToPassage_Text_0:
	.string "GRUNT 4: The BOSS isn't gonna be happy,\n"
	.string "I'm not looking forward to telling him.$"

PetalburgCityAqua_EventScripts_RetreatToPassage_Text_1:
	.string "MOM: That seems like the last of them.$"

PetalburgCityAqua_EventScripts_RetreatToPassage_Text_2:
	.string "DAD: Those folks needed to be stopped,\n"
	.string "I'm glad that I could help!$"

PetalburgCityAqua_EventScripts_RetreatToPassage_Text_3:
	.string "DAD: Look at that over there!\n"
	.string "What is that?$"

PetalburgCityAqua_EventScripts_RetreatToPassage_Text_4:
	.string "MOM: Those GRUNTS must've dropped it.\n"
	.string "Go on {PLAYER}, go see what it is.$"

PetalburgCityAqua_EventScripts_HealTeam_Text_0:
	.string "MOM: Oh wow, who needs a POKéMON\n"
	.string "CENTER with items like this, {PLAYER}.\l"
	.string "You can use them to heal your own team.$"

PetalburgCityAqua_EventScripts_HealTeam_Text_1:
	.string "MOM: I can't believe that I'm going to\n"
	.string "suggest this, but now you're ready to\l"
	.string "battle, you should follow TEAM AQUA!\p"
	.string "Your DAD and I can make sure PETALBURG\n"
	.string "CITY is rid of the members that remain.$"

PetalburgCityAqua_EventScripts_HealTeam_Text_2:
	.string "DAD: I can't believe she suggested it\n"
	.string "either, but I think your MOM is right.\p"
	.string "Go stop TEAM AQUA from causing any\n"
	.string "more damage in BOREA PASSAGE!$"

PetalburgCityAqua_EventScripts_SamuelDefendPetalburg_Text_0:
	.string "DAD: Go on {PLAYER}!\n"
	.string "Go and stop TEAM AQUA!$"

PetalburgCityAqua_EventScripts_LaurenDefendPetalburg_Text_0:
	.string "MOM: Go on {PLAYER}!\n"
	.string "We'll look after the people of PETALBUG!$"

PetalburgCityAqua_Text_AttackOne_Intro::
	.string "GRUNT 2: Wait, isn't that the GYM\n"
	.string "LEADER around these parts?\l"
	.string "And his wife to boot?$"

PetalburgCityAqua_Text_AttackOne_Defeat::
	.string "GRUNT 1: I guess you two really\n"
	.string "make a superbly good team…\p"
	.string "GRUNT 2: I'm just jealous that you\n"
	.string "two can work so well together…$"

PetalburgCityAqua_Text_AttackOne_NoPokemon::
	.string "GRUNT 1: You're right!\n"
	.string "Let's get out of here!$"

PetalburgCityAqua_Text_AttackTwo_Intro::
	.string "GRUNT 4: We're not gonna let you into\n"
	.string "the BOREA PASSAGE and stop the BOSS!$"

PetalburgCityAqua_Text_AttackTwo_Defeat::
	.string "GRUNT 3: Well no wonder you\n"
	.string "beat the other two…\p"
	.string "GRUNT 4: Yeah…\n"
	.string "You're a great team…$"

PetalburgCityAqua_Text_AttackTwo_NoPokemon::
	.string "GRUNT 4: No, the BOSS wants us\n"
	.string "to retreat into BOREA PASSAGE.\l"
	.string "Let's ditch these guys.$"
