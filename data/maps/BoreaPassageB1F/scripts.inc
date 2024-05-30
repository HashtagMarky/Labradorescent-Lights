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
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
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
	setobjectxyperm 5, 10, 3
	setobjectxyperm 6, 10, 2
	special SpawnCameraObject
	fadeoutbgm 4
	applymovement OBJ_EVENT_ID_CAMERA, BoreaPassageB1F_Movement_CameraCutscene
	applymovement OBJ_EVENT_ID_PLAYER, BoreaPassageB1F_Movement_PlayerCutscene
	waitmovement OBJ_EVENT_ID_CAMERA
	applymovement 1, BoreaPassageB1F_Movement_ArchiePacing
	waitmovement 0
	msgbox BoreaPassageB1F_EventScript_AquaCutscene_Text_0, MSGBOX_DEFAULT
	closemessage
	applymovement 1, BoreaPassageB1F_Movement_ArchieLeaveBegin
	applymovement OBJ_EVENT_ID_PLAYER, BoreaPassageB1F_Movement_ArchieLeavePlayer
	waitmovement 0
	msgbox BoreaPassageB1F_EventScript_AquaCutscene_Text_1, MSGBOX_DEFAULT
	applymovement 1, FaceRight
	msgbox BoreaPassageB1F_EventScript_AquaCutscene_Text_2, MSGBOX_DEFAULT
	closemessage
	applymovement 1, BoreaPassageB1F_Movement_ArchieLeave
	waitmovement 0
	playmoncry SPECIES_LAPRAS, 0
	fadedefaultbgm
	waitmoncry
	special RemoveCameraObject
	return


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
	face_right
	delay_16
	delay_16
	delay_16
	walk_left
	delay_16
	face_down
	delay_16
	delay_16
	delay_16
	walk_right
	delay_16
	face_down
	step_end

BoreaPassageB1F_Movement_ArchieLeaveBegin:
	walk_up
	walk_left
	walk_left
	face_right
	step_end

BoreaPassageB1F_Movement_ArchieLeavePlayer:
	walk_down
	walk_down
	walk_down
	face_left
	step_end

BoreaPassageB1F_Movement_ArchieLeave:
	walk_left
	delay_16
	set_invisible
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
	.string "Though you didn't thrawt me this time…$"

BoreaPassageB1F_EventScript_AquaCutscene_Text_2:
	.string "I let down my old partner, who\n"
	.string "I hoped would rejoin me now.\p"
	.string "… … … … …\p"
	.string "LAPRAS decided to remain here…\n"
	.string "And I will respect it's wishes.\p"
	.string "TEAM AQUA will go on, but you won't\n"
	.string "be able to stop us next time.\l"
	.string "Until then, {PLAYER}.$"
