.set LOCALID_MART_EMPLOYEE, 2
.set LOCALID_FOOTPRINTS_MAN, 3
.set LOCALID_RIVAL, 4
.set LOCALID_Gabby, 8
.set LOCALID_Ty, 7
.set LOCALID_Ignatius, 10
.set LOCALID_Snorlax, 11
.set LOCALID_Lauren, 12
.set LOCALID_Diance, 13
.set LOCALID_Samuel, 14
.set LOCALID_Infernape, 15

OldaleTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OldaleTown_OnFrame
	.byte 0

OldaleTown_OnFrame::
	map_script_2 VAR_TEMP_0, 0, OldaleTown_EventScript_LockDoors
	.2byte 0

OldaleTown_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	special Overworld_PlaySpecialMapMusic
	setflag FLAG_VISITED_OLDALE_TOWN
	call_if_unset FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_BlockWestEntrance
	call_if_unset FLAG_RECEIVED_POTION_OLDALE, OldaleTown_EventScript_MoveMartEmployee
	call_if_set FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_SetOldaleState
	end

@ This script seems pointless because nothing uses VAR_OLDALE_TOWN_STATE
OldaleTown_EventScript_SetOldaleState::
	setvar VAR_OLDALE_TOWN_STATE, 1
	return

OldaleTown_EventScript_BlockWestEntrance::
	setobjectxyperm LOCALID_FOOTPRINTS_MAN, 1, 11
	setobjectmovementtype LOCALID_FOOTPRINTS_MAN, MOVEMENT_TYPE_FACE_LEFT
	return

OldaleTown_EventScript_MoveMartEmployee::
	setobjectxyperm LOCALID_MART_EMPLOYEE, 13, 14
	setobjectmovementtype LOCALID_MART_EMPLOYEE, MOVEMENT_TYPE_FACE_DOWN
	return

OldaleTown_EventScript_CitySign::
	msgbox OldaleTown_Text_CitySign, MSGBOX_SIGN
	end

OldaleTown_EventScript_Girl::
	msgbox OldaleTown_Text_SavingMyProgress, MSGBOX_NPC
	end

OldaleTown_EventScript_MartEmployee::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POTION_OLDALE, OldaleTown_EventScript_ExplainPotion
	goto_if_set FLAG_TEMP_1, OldaleTown_EventScript_ExplainPotion
	setflag FLAG_TEMP_1
	playbgm MUS_FOLLOW_ME, FALSE
	msgbox OldaleTown_Text_IWorkAtPokemonMart, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case DIR_SOUTH, OldaleTown_EventScript_GoToMartSouth
	case DIR_NORTH, OldaleTown_EventScript_GoToMartNorth
	case DIR_EAST, OldaleTown_EventScript_GoToMartEast
	end

OldaleTown_EventScript_GoToMartSouth::
	applymovement LOCALID_MART_EMPLOYEE, OldaleTown_Movement_EmployeeSouth
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerSouth
	waitmovement 0
	goto OldaleTown_EventScript_ExplainPokemonMart
	end

OldaleTown_EventScript_GoToMartNorth::
	applymovement LOCALID_MART_EMPLOYEE, OldaleTown_Movement_EmployeeNorth
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerNorth
	waitmovement 0
	goto OldaleTown_EventScript_ExplainPokemonMart
	end

OldaleTown_EventScript_GoToMartEast::
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerEast
	applymovement LOCALID_MART_EMPLOYEE, OldaleTown_Movement_EmployeeEast
	waitmovement 0
	goto OldaleTown_EventScript_ExplainPokemonMart
	end

OldaleTown_EventScript_ExplainPokemonMart::
	msgbox OldaleTown_Text_ThisIsAPokemonMart, MSGBOX_DEFAULT
	giveitem ITEM_POTION, 3
	giveitem ITEM_FULL_HEAL, 1
	goto_if_eq VAR_RESULT, FALSE, OldaleTown_EventScript_BagIsFull
	msgbox OldaleTown_Text_PotionExplanation, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_POTION_OLDALE
	fadedefaultbgm
	release
	end

OldaleTown_EventScript_ExplainPotion::
	msgbox OldaleTown_Text_PotionExplanation, MSGBOX_DEFAULT
	release
	end

OldaleTown_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	fadedefaultbgm
	release
	end

OldaleTown_Movement_EmployeeEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

OldaleTown_Movement_EmployeeSouth:
	walk_left
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

OldaleTown_Movement_EmployeeNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

OldaleTown_Movement_Unknown1:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	walk_in_place_faster_down
	step_end

OldaleTown_Movement_PlayerEast:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_Movement_PlayerSouth:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_Movement_PlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_Movement_Unknown2:
	walk_left
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_EventScript_FootprintsMan::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_NotBlockingPath
	msgbox OldaleTown_Text_DiscoveredFootprints, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FOOTPRINTS_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

OldaleTown_EventScript_BlockedPath::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerStepBack
	applymovement LOCALID_FOOTPRINTS_MAN, OldaleTown_Movement_BackUp
	waitmovement 0
	msgbox OldaleTown_Text_WaitDontComeInHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FOOTPRINTS_MAN, OldaleTown_Movement_ReturnToOriginalPosition
	waitmovement 0
	releaseall
	end

OldaleTown_EventScript_NotBlockingPath::
	msgbox OldaleTown_Text_FinishedSketchingFootprints, MSGBOX_DEFAULT
	release
	end

OldaleTown_EventScript_Rival::
	lockall
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_0x8009, 0
	goto OldaleTown_EventScript_ShowRivalMessage
	end

OldaleTown_EventScript_RivalTrigger1::
	lockall
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalApproachPlayer1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	setvar VAR_0x8009, 1
	goto OldaleTown_EventScript_ShowRivalMessage
	end

OldaleTown_EventScript_RivalTrigger2::
	lockall
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalApproachPlayer2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	setvar VAR_0x8009, 1
	goto OldaleTown_EventScript_ShowRivalMessage
	end

OldaleTown_EventScript_RivalTrigger3::
	lockall
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalApproachPlayer3
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	setvar VAR_0x8009, 1
	goto OldaleTown_EventScript_ShowRivalMessage
	end

OldaleTown_EventScript_ShowRivalMessage::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, OldaleTown_EventScript_ShowMayMessage
	goto_if_eq VAR_RESULT, FEMALE, OldaleTown_EventScript_ShowBrendanMessage
	end

OldaleTown_EventScript_ShowMayMessage::
	msgbox OldaleTown_Text_MayLetsGoBack, MSGBOX_DEFAULT
	goto OldaleTown_EventScript_RivalFinish
	end

OldaleTown_EventScript_ShowBrendanMessage::
	msgbox OldaleTown_Text_BrendanLetsGoBack, MSGBOX_DEFAULT
	goto OldaleTown_EventScript_RivalFinish
	end

OldaleTown_EventScript_RivalFinish::
	closemessage
	call_if_eq VAR_0x8009, 0, OldaleTown_EventScript_DoExitMovement1
	call_if_eq VAR_0x8009, 1, OldaleTown_EventScript_DoExitMovement2
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalExit
	waitmovement 0
	removeobject LOCALID_RIVAL
	setvar VAR_OLDALE_RIVAL_STATE, 2
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	releaseall
	end

OldaleTown_EventScript_DoExitMovement1::
	goto_if_ne VAR_FACING, DIR_SOUTH, OldaleTown_EventScript_DoExitMovement2
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalExit
	waitmovement 0
	return

OldaleTown_EventScript_DoExitMovement2::
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_WatchRivalExit
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalExit
	waitmovement 0
	return

OldaleTown_Movement_RivalApproachPlayer1:
	walk_left
	walk_left
	step_end

OldaleTown_Movement_RivalApproachPlayer2:
	walk_left
	step_end

OldaleTown_Movement_RivalApproachPlayer3:
	face_left
	step_end

OldaleTown_Movement_RivalExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

OldaleTown_Movement_WatchRivalExit:
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

OldaleTown_Movement_PlayerStepBack:
	delay_8
	walk_right
	step_end

OldaleTown_Movement_BackUp:
	walk_fast_up
	walk_in_place_faster_left
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

OldaleTown_Movement_ReturnToOriginalPosition:
	walk_down
	walk_left
	step_end

OldaleTown_Text_SavingMyProgress:
	.string "I want to take a rest, so I'm saving my\n"
	.string "progress.$"

OldaleTown_Text_IWorkAtPokemonMart:
	.string "Hi!\n"
	.string "I work at a POKéMON MART.\p"
	.string "Can I get you to come with me?$"

OldaleTown_Text_ThisIsAPokemonMart:
	.string "This is a POKéMON MART.\n"
	.string "Just look for our blue roof.\p"
	.string "We sell a variety of goods including\n"
	.string "POKé BALLS for catching POKéMON.\p"
	.string "Here, I'd like you to have these as\n"
	.string "a few promotional items.$"

OldaleTown_Text_PotionExplanation:
	.string "A POTION can be used anytime to\n"
	.string "restore the HP of a POKéMON, a\l"
	.string "FULL HEAL removes any status\l"
	.string "ailment from them instead.\p"
	.string "Using them together can be more\n"
	.string "useful than a POKéMON CENTER,\l"
	.string "in certain situations.$"

OldaleTown_Text_WaitDontComeInHere:
	.string "Aaaaah! Wait!\n"
	.string "Please don't come in here.\p"
	.string "I just discovered the footprints of\n"
	.string "a rare POKéMON!\p"
	.string "Wait until I finish sketching\n"
	.string "them, okay?$"

OldaleTown_Text_DiscoveredFootprints:
	.string "I just discovered the footprints of\n"
	.string "a rare POKéMON!\p"
	.string "Wait until I finish sketching\n"
	.string "them, okay?$"

OldaleTown_Text_FinishedSketchingFootprints:
	.string "I finished sketching the footprints of\n"
	.string "a rare POKéMON.\p"
	.string "But it turns out they were only my\n"
	.string "own footprints…$"

OldaleTown_Text_MayLetsGoBack:
	.string "{RIVAL}: {PLAYER}{KUN}!\n"
	.string "Over here!\l"
	.string "Let's hurry home!$"

OldaleTown_Text_BrendanLetsGoBack:
	.string "{RIVAL}: I'm heading back to my dad's\n"
	.string "LAB now.\l"
	.string "{PLAYER}, you should hustle back, too.$"

OldaleTown_Text_CitySign:
	.string "OLDALE TOWN\n"
	.string "“Where things start off scarce.”$"

OldaleTown_Text_FollowingTip:
	.string "My PIKACHU likes to follow me around\n"
	.string "when we go out for a walk!\p"
	.string "My dad said that's because I have\n"
	.string "FOLLOWERS turned on in my OPTIONS,\l"
	.string "but I don't know what that even means…$"

OldaleTown_Text_FollowingTipDemo:
	.string "My PIKACHU likes to follow me around\n"
	.string "when we go out for a walk!\p"
	.string "My dad said that's because I have\n"
	.string "FOLLOWERS turned on in my OPTIONS,\l"
	.string "but I don't think it works in the DEMO…$"

OldaleTown_EventScript_Pikachu::
	faceplayer
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	waitmoncry
	release
	end

OldaleTown_EventScript_FollowingTip::
	goto_if_unset FLAG_SYS_DEMO_MODE, OldaleTown_EventScript_FollowingTip_1
	msgbox OldaleTown_Text_FollowingTipDemo, MSGBOX_NPC
	return

OldaleTown_EventScript_FollowingTip_1:
	msgbox OldaleTown_Text_FollowingTip, MSGBOX_NPC
	return


OldaleTown_Gabby::
	lock
	goto_if_set FLAG_MET_OLDALE_GABBY_AND_TY, OldaleTown_Gabby_2
	msgbox OldaleTown_Gabby_Text_1, MSGBOX_DEFAULT
	msgbox OldaleTown_Gabby_Text_2, MSGBOX_NPC
	setflag FLAG_MET_OLDALE_GABBY_AND_TY
OldaleTown_Gabby_1:
	applymovement LOCALID_Gabby, Common_Movement_FaceOriginalDirection
	waitmovement 0
	call StartGabbyTyQuest
	release
	end

OldaleTown_Gabby_2:
	msgbox OldaleTown_Gabby_Text_0, MSGBOX_NPC
	goto OldaleTown_Gabby_1


OldaleTown_Ty::
	lock
	specialvar VAR_RESULT, GetPlayerFacingDirection
	compare VAR_RESULT, DIR_WEST
	goto_if_eq OldaleTown_Ty_2
OldaleTown_Ty_1:
	goto_if_set FLAG_MET_OLDALE_GABBY_AND_TY, OldaleTown_Ty_5
	msgbox OldaleTown_Ty_Text_2, MSGBOX_DEFAULT
	msgbox OldaleTown_Ty_Text_3, MSGBOX_NPC
	setflag FLAG_MET_OLDALE_GABBY_AND_TY
OldaleTown_Ty_4:
	applymovement LOCALID_Ty, Common_Movement_FaceOriginalDirection
	waitmovement 0
	call StartGabbyTyQuest
	release
	end

OldaleTown_Ty_2:
	msgbox OldaleTown_Ty_Text_0, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, OutOfWay1
	waitmovement 0
	goto OldaleTown_Ty_1

OldaleTown_Ty_5:
	msgbox OldaleTown_Ty_Text_1, MSGBOX_DEFAULT
	goto OldaleTown_Ty_4


OldaleTown_Hunter::
	lock
	specialvar VAR_RESULT, GetPlayerFacingDirection
	compare VAR_RESULT, DIR_EAST
	goto_if_eq OldaleTown_Hunter_2
OldaleTown_Hunter_1:
	msgbox OldaleTown_Hunter_Text_0, MSGBOX_DEFAULT
	closemessage
	release
	end

OldaleTown_Hunter_2:
	msgbox OldaleTown_Ty_Text_0, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, OutOfWay2
	waitmovement 0
	goto OldaleTown_Hunter_1


OutOfWay1:
	walk_down
	walk_left
	face_up
	step_end

OutOfWay2:
	walk_up
	walk_right
	face_down
	step_end

OldaleTown_Thief::
	lockall
	msgbox OldaleTown_Thief_Text_0, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox OldaleTown_Thief_Text_1, MSGBOX_NPC
	applymovement 10, FaceUp
	return


OldaleTown_EventScript_CaveEntrance_Gentleman::
	lock
	applymovement 5, Common_Movement_WalkInPlaceRight
	msgbox OldaleTown_EventScript_CaveEntrance_Gentleman_Text_0, MSGBOX_DEFAULT
	waitmovement 0
	closemessage
	release
	return


OldaleTown_EventScript_CaveEntrance_Gentleman_Flag::
	goto_if_unset FLAG_SYS_DEMO_MODE, OldaleTown_EventScript_CaveEntrance_Gentleman_Flag_1
	return

OldaleTown_EventScript_CaveEntrance_Gentleman_Flag_1:
	setflag FLAG_ROUTE_103_CAVE_MAN
	return


OldaleTown_Homely_Samuel::
	playmoncry SPECIES_ABSOL, 0
	getplayerxy VAR_TEMP_A, VAR_TEMP_1
	compare VAR_TEMP_1, 0
	goto_if_eq OldaleTown_Homely_Samuel_2
	compare VAR_TEMP_1, 1
	goto_if_eq OldaleTown_Homely_Samuel_2
	msgbox OldaleTown_Homely_Samuel_Text_0, MSGBOX_SIGN
OldaleTown_Homely_Samuel_1:
	waitmoncry
	releaseall
	return

OldaleTown_Homely_Samuel_2:
	call OldaleTown_Homely_SamuelInfernape
	applymovement LOCALID_Samuel, OldaleTown_Homely_SamuelOutOfWay_Left
	applymovement LOCALID_Infernape, OldaleTown_Homely_InfernapeOutOfWay_Left
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Homely_PlayerPass_Left
	waitmovement 0
	goto OldaleTown_Homely_Samuel_1


OldaleTown_Homely_Infernape::
	playmoncry SPECIES_ABSOL, 0
	getplayerxy VAR_TEMP_A, VAR_TEMP_1
	compare VAR_TEMP_1, 0
	goto_if_eq OldaleTown_Homely_Infernape_2
	compare VAR_TEMP_1, 1
	goto_if_eq OldaleTown_Homely_Infernape_2
	msgbox OldaleTown_Homely_Samuel_Text_0, MSGBOX_SIGN
OldaleTown_Homely_Infernape_1:
	waitmoncry
	releaseall
	return

OldaleTown_Homely_Infernape_2:
	call OldaleTown_Homely_SamuelInfernape
	applymovement LOCALID_Samuel, OldaleTown_Homely_SamuelOutOfWay_Right
	compare VAR_TEMP_A, 1
	goto_if_eq OldaleTown_Homely_Infernape_8
	applymovement LOCALID_Infernape, OldaleTown_Homely_InfernapeOutOfWay_RightLeft
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Homely_PlayerPass_RightLeft
OldaleTown_Homely_Infernape_7:
	waitmovement 0
	goto OldaleTown_Homely_Infernape_1

OldaleTown_Homely_Infernape_8:
	applymovement LOCALID_Infernape, OldaleTown_Homely_InfernapeOutOfWay_RightUp
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Homely_PlayerPass_RightUp
	goto OldaleTown_Homely_Infernape_7


OldaleTown_Homely_SamuelInfernape::
	msgbox OldaleTown_Homely_SamuelInfernape_Text_0, MSGBOX_SIGN
	getplayerxy VAR_TEMP_A, VAR_TEMP_1
	compare VAR_TEMP_1, 1
	goto_if_eq OldaleTown_Homely_SamuelInfernape_2
	applymovement LOCALID_Infernape, FaceRight
	applymovement LOCALID_Samuel, OldaleTown_Homely_SamuelExclaimRight
OldaleTown_Homely_SamuelInfernape_1:
	playse SE_PIN
	waitmovement 0
	msgbox OldaleTown_Homely_SamuelInfernape_Text_1, MSGBOX_SIGN
	waitse
	setrespawn HEAL_LOCATION_ROUTE_103_MOUNTAINS
	setvar VAR_LAB_LIGHTS, 1
	return

OldaleTown_Homely_SamuelInfernape_2:
	applymovement LOCALID_Infernape, FaceDown
	applymovement LOCALID_Samuel, OldaleTown_Homely_SamuelExclaimDown
	goto OldaleTown_Homely_SamuelInfernape_1


OldaleTown_Homely_Lauren::
	playmoncry SPECIES_ABSOL, 0
	msgbox OldaleTown_Homely_Lauren_Text_0, MSGBOX_SIGN
	waitmoncry
	return


OldaleTown_Homely_Ignatius::
	playmoncry SPECIES_ABSOL, 0
	msgbox OldaleTown_Homely_Ignatius_Text_0, MSGBOX_SIGN
	waitmoncry
	return


OldaleTown_EventScript_LockDoors::
	addvar VAR_TEMP_0, 1
	goto_if_unset FLAG_HIDE_QUEEN_ABSOL, OldaleTown_EventScript_LockDoors_1
	return

OldaleTown_EventScript_LockDoors_1:
	setmetatile 6, 7, METATILE_Petalburg_Locked_Town_Door, TRUE
	setmetatile 15, 16, METATILE_Petalburg_Locked_Town_Door, TRUE
	return


OldaleTown_Homely_SamuelExclaimDown:
	emote_exclamation_mark
	face_down
	step_end

OldaleTown_Homely_SamuelExclaimRight:
	emote_exclamation_mark
	face_right
	step_end

OldaleTown_Homely_SamuelOutOfWay_Left:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	step_end

OldaleTown_Homely_SamuelOutOfWay_Right:
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	step_end

OldaleTown_Homely_InfernapeOutOfWay_Left:
	delay_16
	walk_right
	face_left
	delay_4
	delay_2
	delay_8
	delay_16
	walk_left
	face_down
	step_end

OldaleTown_Homely_InfernapeOutOfWay_RightUp:
	walk_right
	face_left
	delay_4
	delay_2
	delay_8
	delay_16
	walk_left
	face_down
	step_end

OldaleTown_Homely_InfernapeOutOfWay_RightLeft:
	walk_down
	face_up
	delay_4
	delay_2
	delay_8
	delay_16
	walk_up
	face_down
	step_end

OldaleTown_Homely_PlayerPass_Left:
	walk_right
	walk_up
	walk_up
	walk_up
	delay_16
	delay_2
	step_end

OldaleTown_Homely_PlayerPass_RightUp:
	walk_up
	walk_up
	walk_up
	delay_16
	delay_2
	step_end

OldaleTown_Homely_PlayerPass_RightLeft:
	walk_left
	walk_up
	walk_up
	delay_16
	delay_2
	step_end

OldaleTown_Gabby_Text_0:
	.string "GABBY: Watching this angers me!\p"
	.string "I saw the BAD OMEN whilst I was hiking\n"
	.string "in the mountainous highlands.\p"
	.string "This man wants to hunt it down, because\n"
	.string "he thinks it brings upon CALAMITY,\l"
	.string "but the BAD OMEN is not truly the cause.$"

OldaleTown_Gabby_Text_1:
	.string "Gosh… I can't stand this man.\n"
	.string "He's a real piece of work!$"

OldaleTown_Gabby_Text_2:
	.string "Oh hey there, the name's GABBY!\n"
	.string "Next to me is my partner, TY.\p"
	.string "GABBY: We're unfortunately in the\n"
	.string "middle of a terrible interview.\l"
	.string "I really wish I was battling instead.\p"
	.string "What's that?\n"
	.string "You want us to interview you?\p"
	.string "You know what, one day we will, but only\n"
	.string "if you battle us first.\l"
	.string "See you around!$"

OldaleTown_Ty_Text_0:
	.string "Excuse me, out of the way!\n"
	.string "You're in my shot!$"

OldaleTown_Ty_Text_1:
	.string "TY: This guy sure thinks this interview\n"
	.string "will make him famous, he's so arrogant.$"

OldaleTown_Ty_Text_2:
	.string "Gosh… This guy is a real piece of work.\n"
	.string "I can't stand him!$"

OldaleTown_Ty_Text_3:
	.string "Oh hey there, the name's TY!\n"
	.string "Next to me is my partner, GABBY.\p"
	.string "TY: We're unfortunately in the middle of\n"
	.string "a terrible interview.\l"
	.string "I really wish I was battling instead.\p"
	.string "What's that?\n"
	.string "You want us to interview you?\p"
	.string "You know what, one day we will, but only\n"
	.string "if you battle us first.\l"
	.string "See you around!$"

OldaleTown_Hunter_Text_0:
	.string "Yes, I will find the CALAMITY BRINGER.\n"
	.string "It's been sighted near here,\l"
	.string "and I will bring it to justice!\p"
	.string "Hmm … … … … … … …\n"
	.string "… … … … … … … … …\p"
	.string "Yes, yes … … … … … …\n"
	.string "… … … … … … … … … … …\p"
	.string "Of course I'm not worried about it's\n"
	.string "tendancy to attack when threatened,\l"
	.string "I'm a master huntsman after all!$"

OldaleTown_Thief_Text_0:
	.string "Hmm…\n"
	.string "I wonder how much it'll be worth…\p"
	.string "$"

OldaleTown_Thief_Text_1:
	.string "AHHH!\p"
	.string "Don't mind me.\n"
	.string "I'm just waiting here.\p"
	.string "The POKé MART employee is distracted\n"
	.string "due to the news being filmed out front.$"

OldaleTown_EventScript_CaveEntrance_Gentleman_Text_0:
	.string "I've got to find it, I've just got to\n"
	.string "find the treasure.$"

OldaleTown_Homely_Samuel_Text_0:
	.string "DAD: Come on, INFERNAPE.\n"
	.string "We have to make sure LAUREN is okay!$"

OldaleTown_Homely_SamuelInfernape_Text_0:
	.string "DAD: That POKéMON sounds like it's just\n"
	.string "up ahead, up on the mountain top.\l"
	.string "We need to make sure LAUREN is okay!$"

OldaleTown_Homely_SamuelInfernape_Text_1:
	.string "DAD: Oh!\n"
	.string "It's only {PLAYER}…\p"
	.string "What's that, you want to go on ahead?\n"
	.string "Your MOM won't be happy…\p"
	.string "Alright then, I'll make sure she's okay.\n"
	.string "Just be careful…$"

OldaleTown_Homely_Lauren_Text_0:
	.string "MOM: That POKéMON sounds hurt, DIANCE.\n"
	.string "We've got to help it!$"

OldaleTown_Homely_Ignatius_Text_0:
	.string "PROF IGNATIUS: That POKéMON sounds\n"
	.string "like it's in danger, SNORLAX.\l"
	.string "We've got to find it!$"
