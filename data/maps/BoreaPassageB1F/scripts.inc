BoreaPassageB1F_MapScripts::
	.byte 0


BoreaPassageB1F_EventScript_AquaGrunt::
	random 5
	switch VAR_RESULT
	case 0, BoreaPassageB1F_EventScript_AquaGrunt_3
	case 1, BoreaPassageB1F_EventScript_AquaGrunt_4
	case 2, BoreaPassageB1F_EventScript_AquaGrunt_5
	case 3, BoreaPassageB1F_EventScript_AquaGrunt_6
	case 4, BoreaPassageB1F_EventScript_AquaGrunt_7
BoreaPassageB1F_EventScript_AquaGrunt_1:
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	return

BoreaPassageB1F_EventScript_AquaGrunt_3:
	msgbox BoreaPassageB1F_EventScript_AquaGrunt_Text_0, MSGBOX_NPC
	goto BoreaPassageB1F_EventScript_AquaGrunt_1

BoreaPassageB1F_EventScript_AquaGrunt_4:
	msgbox BoreaPassageB1F_EventScript_AquaGrunt_Text_1, MSGBOX_NPC
	goto BoreaPassageB1F_EventScript_AquaGrunt_1

BoreaPassageB1F_EventScript_AquaGrunt_5:
	msgbox BoreaPassageB1F_EventScript_AquaGrunt_Text_2, MSGBOX_NPC
	goto BoreaPassageB1F_EventScript_AquaGrunt_1

BoreaPassageB1F_EventScript_AquaGrunt_6:
	msgbox BoreaPassageB1F_EventScript_AquaGrunt_Text_3, MSGBOX_NPC
	goto BoreaPassageB1F_EventScript_AquaGrunt_1

BoreaPassageB1F_EventScript_AquaGrunt_7:
	msgbox BoreaPassageB1F_EventScript_AquaGrunt_Text_4, MSGBOX_NPC
	goto BoreaPassageB1F_EventScript_AquaGrunt_1


BoreaPassageB1F_EventScript_AquaCutscene::
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, BoreaPassageB1F_Movement_CameraCutscene
	applymovement OBJ_EVENT_ID_PLAYER, BoreaPassageB1F_Movement_PlayerCutscene
	fadeoutbgm 2
	waitmovement OBJ_EVENT_ID_CAMERA
	setobjectxyperm 5, 10, 3
	setobjectxyperm 6, 11, 3
	applymovement 1, BoreaPassageB1F_Movement_ArchiePacing
	waitmovement 0
	msgbox BoreaPassageB1F_EventScript_AquaCutscene_Text_0, MSGBOX_DEFAULT
	closemessage
	applymovement 1, BoreaPassageB1F_Movement_ArchieLeaveBegin
	applymovement OBJ_EVENT_ID_PLAYER, BoreaPassageB1F_Movement_ArchieLeavePlayer
	waitmovement 0
	msgbox BoreaPassageB1F_EventScript_AquaCutscene_Text_1, MSGBOX_DEFAULT
	closemessage
	applymovement 1, BoreaPassageB1F_Movement_ArchieLeave
	playmoncry SPECIES_LAPRAS, 0
	waitmovement 0
	waitmoncry
	goto BoreaPassageB1F_EventScript_SkipCutscene
	return


BoreaPassageB1F_EventScript_SkipCutscene::
	fadeinbgm 4
	fadescreen FADE_TO_WHITE
	delay 20
	showobjectat 7, MAP_BOREA_PASSAGE_B1F
	fadescreenspeed FADE_FROM_WHITE, 1
	playmoncry SPECIES_LAPRAS, 0
	delay 16
	applymovement OBJ_EVENT_ID_PLAYER, BoreaPassageB1F_Movement_PlayerExclaim
	playse SE_PIN
	waitmoncry
	delay 30
	fadescreenspeed FADE_TO_WHITE, 1
	removeobject 7
	fadescreen FADE_FROM_WHITE
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, BoreaPassageB1F_Movement_PlayerExit
	waitmovement 0
	playse SE_EXIT
	fadescreen FADE_TO_BLACK
	msgbox BoreaPassageB1F_EventScript_SkipCutscene_Text_0, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox BoreaPassageB1F_EventScript_SkipCutscene_Text_1, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_SYS_NO_DIG_OR_ROPE
	setvar VAR_LAB_LIGHTS, 0
	completesubquest HOMELY, DINNER
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq BoreaPassageB1F_EventScript_SkipCutscene_2
	clearflag FLAG_HIDE_BOREA_GLADE_MAYS_HOUSE_MOM
	clearflag FLAG_HIDE_MAYS_HOUSE_DIANCIE
	clearflag FLAG_HIDE_MAYS_HOUSE_DAD
	clearflag FLAG_HIDE_MAYS_HOUSE_ESPURR
	warpsilent MAP_PLAYER_HOUSES, 26, 8
BoreaPassageB1F_EventScript_SkipCutscene_1:
	waitstate
	releaseall
	return

BoreaPassageB1F_EventScript_SkipCutscene_2:
	clearflag FLAG_HIDE_BOREA_GLADE_BRENDANS_HOUSE_MOM
	clearflag FLAG_HIDE_BRENDANS_HOUSE_DIANCIE
	clearflag FLAG_HIDE_BRENDANS_HOUSE_DAD
	clearflag FLAG_HIDE_BRENDANS_HOUSE_ESPURR
	warpsilent MAP_PLAYER_HOUSES, 8, 8
	goto BoreaPassageB1F_EventScript_SkipCutscene_1


BoreaPassageB1F_EventScript_ParentsCutscene::
	special RemoveCameraObject
	fadeinbgm 4
	applymovement 5, BoreaPassageB1F_Movement_SamuelEntrance
	applymovement 6, BoreaPassageB1F_Movement_LaurenEntrance
	applymovement OBJ_EVENT_ID_PLAYER, BoreaPassageB1F_Movement_PlayerParentsEntrance
	waitmovement 0
	return


BoreaPassageB1F_EventScript_LaprasCutscene::
	fadescreen FADE_TO_WHITE
	showobjectat 7, MAP_BOREA_PASSAGE_B1F
	fadescreenspeed FADE_FROM_WHITE, 1
	playmoncry SPECIES_LAPRAS, 0
	delay 30
	fadescreenspeed FADE_TO_WHITE, 1
	removeobject 7
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq BoreaPassageB1F_EventScript_LaprasCutscene_2
	clearflag FLAG_HIDE_BOREA_GLADE_MAYS_HOUSE_MOM
	clearflag FLAG_HIDE_MAYS_HOUSE_DIANCIE
	clearflag FLAG_HIDE_MAYS_HOUSE_DAD
	clearflag FLAG_HIDE_MAYS_HOUSE_ESPURR
	warpsilent MAP_PLAYER_HOUSES, 26, 8
BoreaPassageB1F_EventScript_LaprasCutscene_1:
	waitstate
	releaseall
	return

BoreaPassageB1F_EventScript_LaprasCutscene_2:
	clearflag FLAG_HIDE_BOREA_GLADE_BRENDANS_HOUSE_MOM
	clearflag FLAG_HIDE_BRENDANS_HOUSE_DIANCIE
	clearflag FLAG_HIDE_BRENDANS_HOUSE_DAD
	clearflag FLAG_HIDE_BRENDANS_HOUSE_ESPURR
	warpsilent MAP_PLAYER_HOUSES, 8, 8
	goto BoreaPassageB1F_EventScript_LaprasCutscene_1


BoreaPassageB1F_Movement_CameraCutscene:
	walk_diag_southwest
	walk_diag_southwest
	walk_diag_southwest
	walk_diag_southwest
	walk_diag_southwest
	step_end

BoreaPassageB1F_Movement_PlayerCutscene:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

BoreaPassageB1F_Movement_ArchiePacing:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_left
	delay_16
	delay_16
	delay_16
	face_down
	delay_16
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_16
	face_down
	step_end

BoreaPassageB1F_Movement_ArchieLeaveBegin:
	walk_up
	walk_left
	walk_left
	delay_16
	face_right
	step_end

BoreaPassageB1F_Movement_ArchieLeavePlayer:
	walk_down
	walk_down
	face_left
	delay_16
	delay_16
	step_end

BoreaPassageB1F_Movement_ArchieLeave:
	walk_left
	delay_16
	set_invisible
	step_end

BoreaPassageB1F_Movement_SamuelEntrance:
	set_visible
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	face_left
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_right
	step_end

BoreaPassageB1F_Movement_LaurenEntrance:
	set_visible
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	face_left
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_right
	step_end

BoreaPassageB1F_Movement_PlayerParentsEntrance:
	face_up
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

BoreaPassageB1F_Movement_PlayerExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_16
	set_invisible
	step_end

BoreaPassageB1F_Movement_PlayerExclaim:
	delay_16
	emote_exclamation_mark
	face_down
	step_end

BoreaPassageB1F_EventScript_AquaGrunt_Text_0:
	.string "Hey, aren't you the TRAINER who's been\n"
	.string "causing us trouble recently?$"

BoreaPassageB1F_EventScript_AquaGrunt_Text_1:
	.string "This is beautiful, I love the\n"
	.string "LABRADORITE tunnels we're in!$"

BoreaPassageB1F_EventScript_AquaGrunt_Text_2:
	.string "This is beautiful, I love the\n"
	.string "AQUAMARINE crystals in the walls!$"

BoreaPassageB1F_EventScript_AquaGrunt_Text_3:
	.string "This is beautiful, but I hate the\n"
	.string "CARNELIAN crystals in the walls…$"

BoreaPassageB1F_EventScript_AquaGrunt_Text_4:
	.string "This is quite the place, I'm having a\n"
	.string "good time exploring down here.$"

BoreaPassageB1F_EventScript_AquaCutscene_Text_0:
	.string "ARCHIE: You would've been perfect…\n"
	.string "A near flawless way to ferry the sea…\l"
	.string "And a champion in battle.\p"
	.string "Alas…\n"
	.string "We'll find a way to do it without you…\l"
	.string "Goodbye old friend.$"

BoreaPassageB1F_EventScript_AquaCutscene_Text_1:
	.string "ARCHIE: It's you again.\n"
	.string "{PLAYER}, was it?\p"
	.string "You've really been a thorn in my\n"
	.string "side ever since we first met.\l"
	.string "Though you didn't thrawt me this time…\p"
	.string "I let down my old partner, who\n"
	.string "I hoped would rejoin me now.\p"
	.string "… … … … …\p"
	.string "LAPRAS decided to remain here…\n"
	.string "And I will respect it's wishes.\p"
	.string "TEAM AQUA will go on, and you won't\n"
	.string "be able to stop us.\l"
	.string "Until then, {PLAYER}.$"

BoreaPassageB1F_EventScript_SkipCutscene_Text_0:
	.string "DAD: {PLAYER}!\n"
	.string "I'm glad to see that you're okay!$"

BoreaPassageB1F_EventScript_SkipCutscene_Text_1:
	.string "MOM: Come on, let's go home.\n"
	.string "You can tell us everything over dinner.$"
