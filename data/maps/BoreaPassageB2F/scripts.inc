BoreaPassageB2F_MapScripts::
	.byte 0


BoreaPassageB2F_EventScript_AquaGrunt::
	random 5
	switch VAR_RESULT
	case 0, BoreaPassageB2F_EventScript_AquaGrunt_2
	case 1, BoreaPassageB2F_EventScript_AquaGrunt_3
	case 2, BoreaPassageB2F_EventScript_AquaGrunt_4
	case 3, BoreaPassageB2F_EventScript_AquaGrunt_5
	case 4, BoreaPassageB2F_EventScript_AquaGrunt_6
	return

BoreaPassageB2F_EventScript_AquaGrunt_2:
	msgbox BoreaPassageB2F_EventScript_AquaGrunt_Text_0, MSGBOX_NPC
	return

BoreaPassageB2F_EventScript_AquaGrunt_3:
	msgbox BoreaPassageB2F_EventScript_AquaGrunt_Text_1, MSGBOX_NPC
	return

BoreaPassageB2F_EventScript_AquaGrunt_4:
	goto_if_unset FLAG_SYS_USE_FLASH, BoreaPassageB2F_EventScript_AquaGrunt_7
	msgbox BoreaPassageB2F_EventScript_AquaGrunt_Text_3, MSGBOX_NPC
	return

BoreaPassageB2F_EventScript_AquaGrunt_5:
	msgbox BoreaPassageB2F_EventScript_AquaGrunt_Text_4, MSGBOX_NPC
	return

BoreaPassageB2F_EventScript_AquaGrunt_6:
	msgbox BoreaPassageB2F_EventScript_AquaGrunt_Text_5, MSGBOX_NPC
	return

BoreaPassageB2F_EventScript_AquaGrunt_7:
	msgbox BoreaPassageB2F_EventScript_AquaGrunt_Text_2, MSGBOX_NPC
	return


BoreaPassageB2F_EventScript_AquaGrunt_Text_0:
	.string "Hey, aren't you the TRAINER who's been\n"
	.string "causing us trouble recently?$"

BoreaPassageB2F_EventScript_AquaGrunt_Text_1:
	.string "Four GRUNTS came running down here\n"
	.string "earlier, what waas that about?$"

BoreaPassageB2F_EventScript_AquaGrunt_Text_2:
	.string "I don't like being stuck down here,\n"
	.string "in get's kind of dark.$"

BoreaPassageB2F_EventScript_AquaGrunt_Text_3:
	.string "I don't like being stuck down here,\n"
	.string "but at least it's lighter now.$"

BoreaPassageB2F_EventScript_AquaGrunt_Text_4:
	.string "I wish I wasn't here, apparently there's\n"
	.string "some nice crystals above us.$"

BoreaPassageB2F_EventScript_AquaGrunt_Text_5:
	.string "This is quite the place, I'm having a\n"
	.string "good time exploring down here.$"
