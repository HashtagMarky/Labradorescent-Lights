Route103Caves_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route103Caves_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Route103Caves_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Route103Caves_MapScripts_OnTransition
	return


Route103Caves_MapScripts_OnTransition::
	questmenu QUEST_MENU_CHECK_COMPLETE, CALAMITY_QUEEN
	goto_if_set FLAG_SET_HOMELY_STATE, Route103Caves_MapScripts_OnTransition_2
	return

Route103Caves_MapScripts_OnTransition_1:
	setflag FLAG_HIDE_OLDALE_FAMILY
	clearflag FLAG_HIDE_ROUTE103MT_FAMILY
	return

Route103Caves_MapScripts_OnTransition_2:
	compare VAR_RESULT, FALSE
	goto_if_eq Route103Caves_MapScripts_OnTransition_1
	return


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


Route103_Caves_EventScripts_HexManiac::
	lock
	faceplayer
	applymovement 6, Exclaim
	delay 60
	specialvar VAR_RESULT, GetPlayerFacingDirection
	compare VAR_RESULT, DIR_SOUTH
	goto_if_eq Route103_Caves_EventScripts_HexManiac_2
	compare VAR_RESULT, DIR_WEST
	goto_if_eq Route103_Caves_EventScripts_HexManiac_3
Route103_Caves_EventScripts_HexManiac_1:
	msgbox Route103_Caves_EventScripts_HexManiac_Text_0, MSGBOX_DEFAULT
	closemessage
	release
	return

Route103_Caves_EventScripts_HexManiac_2:
	applymovement 6, FaceRight
	delay 60
	applymovement 6, FaceUp
	goto Route103_Caves_EventScripts_HexManiac_1

Route103_Caves_EventScripts_HexManiac_3:
	applymovement 6, FaceUp
	delay 60
	applymovement 6, FaceRight
	goto Route103_Caves_EventScripts_HexManiac_1


Route103_Caves_EventScripts_Gentleman::
	trainerbattle_single TRAINER_R103C_DON, Route103_Caves_DonIntro, Route103_Caves_DonDefeated, Route103_Caves_EventScript_DonPostBattle
	msgbox Route103_Caves_EventScripts_Gentleman_Text_0, MSGBOX_NPC
	return


Route103_Caves_EventScript_DonPostBattle::
	msgbox Route103_Caves_EventScript_DonPostBattle_Text_0, MSGBOX_NPC
	return


Route103_Caves_EventScripts_OldMan::
	msgbox Route103_Caves_EventScripts_OldMan_Text_0, MSGBOX_NPC
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
	.string "Hold it there!$"

Route103Caves1FCheckSurf_Text_1:
	.string "Don't bother heading out to ROUTE 103,\n"
	.string "there isn't anywhere to go.\p"
	.string "At least, not without being able to\n"
	.string "cross the water.\l"
	.string "I guess we're both stuck in here!$"

Route103_Caves_EventScripts_HexManiac_Text_0:
	.string "There’s an eerie presence about\n"
	.string "these caves…\p"
	.string "I heard there is a just as eerie item\n"
	.string "that was dropped in here as well.$"

Route103_Caves_EventScripts_Gentleman_Text_0:
	.string "The treasure still awaits,\n"
	.string "maybe it will be yours.$"

Route103_Caves_EventScript_DonPostBattle_Text_0:
	.string "Wow! You're really strong.\p"
	.string "The treasure still awaits,\n"
	.string "maybe it will be yours.$"

Route103_Caves_EventScripts_OldMan_Text_0:
	.string "I wander across the bridge in this cave,\n"
	.string "but I don't know how to get down!$"

Route103_Caves_DonIntro::
	.string "I'm training my POKéMON in order to get\n"
	.string "to some treasure!$"

Route103_Caves_DonDefeated::
	.string "I… I lost.\n"
	.string "Maybe I need to train some more…$"
