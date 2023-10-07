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
	lock
	msgbox Route103Caves1FCheckSurf_Text_0, MSGBOX_AUTOCLOSE
	applymovement 1, WalkToPlayer
	waitmovement 0
	msgbox Route103Caves1FCheckSurf_Text_1, MSGBOX_NPC
	applymovement OBJ_EVENT_ID_PLAYER, WalkUp
	applymovement 1, ReturnFromPlayer
	waitmovement 0
	release
	return


WalkToPlayer:
	walk_right
	walk_right
	face_up
	step_end

ReturnFromPlayer:
	walk_left
	walk_left
	face_right
	step_end

Route103Caves1FHiker_Text_0:
	.string "Well look at this,\p"
	.string "you've learnt to SURF on water.\l"
	.string "Now for me to do the same!$"

Route103Caves1FCheckSurf_Text_0:
	.string "HOLD ON!$"

Route103Caves1FCheckSurf_Text_1:
	.string "Don't bother heading out to ROUTE 103,\n"
	.string "there isn't anywhere to go.\p"
	.string "At least, not without being able to\n"
	.string "cross the water.\l"
	.string "I guess we're both stuck in here!$"
