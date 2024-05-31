BoreaPassage1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BoreaPassage1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

BoreaPassage1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_1, 0, BoreaPassage1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

BoreaPassage1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	setvar VAR_TEMP_1, 1
	goto_if_unset FLAG_HIDE_AQUA_IN_BOREA_PASSAGE, BoreaPassage1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1
	return

BoreaPassage1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1:
	call BoreaPassage1F_AquaOnLoad
	return


BoreaPassage1F_AquaOnLoad::
	setflag FLAG_SYS_NO_DIG_OR_ROPE
	setflag FLAG_SYS_NO_ENCOUNTER
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_1, 22
	goto_if_eq BoreaPassage1F_AquaOnLoad_1
	compare VAR_TEMP_1, 25
	goto_if_eq BoreaPassage1F_AquaOnLoad_2
	return

BoreaPassage1F_AquaOnLoad_1:
	return

BoreaPassage1F_AquaOnLoad_2:
	goto BoreaPassage1F_AquaOnLoad_WarpCave
	return


BoreaPassage1F_AquaOnLoad_WarpLadder::
	msgbox BoreaPassage1F_AquaOnLoad_WarpLadder_Text_0, MSGBOX_SIGN
	return


BoreaPassage1F_AquaOnLoad_WarpCave::
	applymovement OBJ_EVENT_ID_PLAYER, FaceLeft
	waitmovement 0
	msgbox BoreaPassage1F_AquaOnLoad_WarpCave_Text_0, MSGBOX_SIGN
	applymovement OBJ_EVENT_ID_PLAYER, FaceRight
	waitmovement 0
	msgbox BoreaPassage1F_AquaOnLoad_WarpCave_Text_1, MSGBOX_SIGN
	applymovement OBJ_EVENT_ID_PLAYER, WalkUp
	waitmovement 0
	setvar VAR_LAB_LIGHTS, 31
	releaseall
	return


BoreaPassage1F_EventScript_AquaGrunt::
	msgbox BoreaPassage1F_EventScript_AquaGrunt_Text_0, MSGBOX_NPC
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	return


BoreaPassage1F_EventScript_TriggerAquaGrunt::
	delay 15
	applymovement OBJ_EVENT_ID_PLAYER, FaceLeft
	waitmovement 0
	msgbox BoreaPassage1F_EventScript_TriggerAquaGrunt_Text_0, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, FaceRight
	waitmovement 0
	msgbox BoreaPassage1F_EventScript_TriggerAquaGrunt_Text_1, MSGBOX_DEFAULT
	closemessage
	applymovement 1, BoreaPassage1F_Movement_TriggerAquaGrunt_AquaGruntLeft
	applymovement 2, BoreaPassage1F_Movement_TriggerAquaGrunt_AquaGruntRight
	applymovement OBJ_EVENT_ID_PLAYER, BoreaPassage1F_Movement_TriggerAquaGrunt_AquaGruntPlayer
	waitmovement 0
	releaseall
	return


BoreaPassage1F_Movement_TriggerAquaGrunt_AquaGruntLeft:
	walk_in_place_right
	walk_in_place_right
	delay_16
	step_end

BoreaPassage1F_Movement_TriggerAquaGrunt_AquaGruntRight:
	walk_in_place_left
	walk_in_place_left
	delay_16
	step_end

BoreaPassage1F_Movement_TriggerAquaGrunt_AquaGruntPlayer:
	walk_in_place_down
	walk_in_place_down
	walk_up
	step_end

BoreaPassage1F_AquaOnLoad_WarpLadder_Text_0:
	.string "GRUNTS: I hope the boss deals\n"
	.string "with you good and proper!$"

BoreaPassage1F_AquaOnLoad_WarpCave_Text_0:
	.string "GRUNT 5: Hey now!\p"
	.string "Seen as you like causing trouble for us,\n"
	.string "you go see if you can handle the boss!$"

BoreaPassage1F_AquaOnLoad_WarpCave_Text_1:
	.string "GRUNT 6: Yeah, let's see if you can hold\n"
	.string "your own with someone bigger than us!\p"
	.string "You only have to go through the tunnels\n"
	.string "beneath us and up a level to get to him.$"

BoreaPassage1F_EventScript_AquaGrunt_Text_0:
	.string "GRUNTS: I hope the boss deals\n"
	.string "with you good and proper!\p"
	.string "You only have to go through the tunnels\n"
	.string "beneath us and up a level to get to him.$"

BoreaPassage1F_EventScript_TriggerAquaGrunt_Text_0:
	.string "GRUNT 5: Hey there!\n"
	.string "We're not letting you go and create\l"
	.string "more trouble out in PETALBURG CITY!$"

BoreaPassage1F_EventScript_TriggerAquaGrunt_Text_1:
	.string "GRUNT 6: Yeah, if you're going anywhere,\n"
	.string "you're going to see the boss!\p"
	.string "You only have to go through the tunnels\n"
	.string "beneath us and up a level to get to him.$"
