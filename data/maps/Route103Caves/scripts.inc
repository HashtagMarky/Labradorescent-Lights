Route103Caves_MapScripts::
	.byte 0

Route103Caves1FHiker::
	msgbox Route103Caves1FHiker_Text_0
	return


Route103Caves1FCheckSurf::
	compare VAR_TEMP_0 == 0, 0
	goto_if_ne Route103Caves1FCheckSurf_1
	return

Route103Caves1FCheckSurf_1:
	lockall
	msgbox Route103Caves1FCheckSurf_Text_0, MSGBOX_DEFAULT
	closemessage
	applymovement 1, WalkToPlayer
	waitmovement 0
	msgbox Route103Caves1FCheckSurf_Text_1, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, WalkUp
	applymovement 1, ReturnFromPlayer
	waitmovement 0
	releaseall
	return


WalkToPlayer:
	walk_right
	step_end

ReturnFromPlayer:
	walk_left
	face_right
	step_end

Route103Caves1FHiker_Text_0:
	.string "Well look at this,\p"
	.string "you've learnt to SURF on water.\l"
	.string "Now for me to do the same!$"

Route103Caves1FCheckSurf_Text_0:
	.string "HOLD ON!\p"
	.string "$"

Route103Caves1FCheckSurf_Text_1:
	.string "Don't bother heading out there,\n"
	.string "you can't go anywhere.\l"
	.string "Not without being able to cross the\l"
	.string "water.\p"
	.string "I guess we're both stuck in here!$"
