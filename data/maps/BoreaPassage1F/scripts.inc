BoreaPassage1F_MapScripts::
	return


BoreaPassage_WorkerSendAway::
	goto_if_unset FLAG_BADGE05_GET, BoreaPassage_WorkerSendAway_1
	release
	end

BoreaPassage_WorkerSendAway_1:
	lock
	specialvar VAR_RESULT, GetPlayerFacingDirection
	switch VAR_RESULT
	case DIR_NORTH, BoreaPassage_WorkerSendAway_6
	case DIR_EAST, BoreaPassage_WorkerSendAway_7
	case DIR_WEST, BoreaPassage_WorkerSendAway_8
BoreaPassage_WorkerSendAway_4:
	applymovement OBJ_EVENT_ID_PLAYER, FaceUp
	compare VAR_TEMP_1, 0
	goto_if_eq BoreaPassage_WorkerSendAway_10
	msgbox BoreaPassage_WorkerSendAway_Text_1, MSGBOX_DEFAULT
BoreaPassage_WorkerSendAway_9:
	closemessage
	switch VAR_RESULT
	case DIR_NORTH, BoreaPassage_WorkerSendAway_14
	case DIR_EAST, BoreaPassage_WorkerSendAway_15
	case DIR_WEST, BoreaPassage_WorkerSendAway_16
	return

BoreaPassage_WorkerSendAway_6:
	applymovement 1, WorkerToNorth
	waitmovement 0
	goto BoreaPassage_WorkerSendAway_4

BoreaPassage_WorkerSendAway_7:
	applymovement 1, WorkerToEast
	waitmovement 0
	goto BoreaPassage_WorkerSendAway_4

BoreaPassage_WorkerSendAway_8:
	applymovement 1, WorkerToWest
	waitmovement 0
	goto BoreaPassage_WorkerSendAway_4

BoreaPassage_WorkerSendAway_10:
	msgbox BoreaPassage_WorkerSendAway_Text_0, MSGBOX_DEFAULT
	addvar VAR_TEMP_1, 1
	goto BoreaPassage_WorkerSendAway_9

BoreaPassage_WorkerSendAway_14:
	applymovement OBJ_EVENT_ID_PLAYER, WalkDown
	applymovement 1, WorkerFromNorth
	waitmovement 0
	return

BoreaPassage_WorkerSendAway_15:
	applymovement OBJ_EVENT_ID_PLAYER, PlayerToLeaveEast
	applymovement 1, WorkerFromEast
	waitmovement 0
	return

BoreaPassage_WorkerSendAway_16:
	applymovement OBJ_EVENT_ID_PLAYER, PlayerToLeaveWest
	applymovement 1, WorkerFromWest
	waitmovement 0
	return


WorkerToNorth:
	walk_down
	step_end

WorkerToEast:
	walk_down
	walk_right
	walk_down
	step_end

WorkerToWest:
	walk_down
	walk_left
	walk_down
	step_end

WorkerFromNorth:
	walk_up
	step_end

WorkerFromEast:
	walk_up
	walk_left
	walk_up
	step_end

WorkerFromWest:
	walk_up
	walk_right
	walk_up
	step_end

PlayerToLeaveEast:
	walk_left
	face_down
	step_end

PlayerToLeaveWest:
	walk_right
	face_down
	step_end

BoreaPassage_WorkerSendAway_Text_0:
	.string "Hold it right there!\p"
	.string "My workers are mining LABRADORITE up\n"
	.string "ahead, so I can't let anyone by.\l"
	.string "You're going to have to leave.$"

BoreaPassage_WorkerSendAway_Text_1:
	.string "Didn't you hear me?\p"
	.string "My workers are mining LABRADORITE up\n"
	.string "ahead, so I can't let anyone by.\l"
	.string "You're going to have to leave.$"
