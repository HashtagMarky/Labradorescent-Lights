.set LOCALID_MRSTONE, 1
.set LOCALID_DEVON_EMPLOYEE, 2
.set LOCALID_LANETTE, 4

RustboroCity_DevonCorp_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_3F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, RustboroCity_DevonCorp_3F_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_DevonCorp_3F_OnFrame
	.byte 0

RustboroCity_DevonCorp_3F_OnTransition:
	call_if_eq VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos
	end

RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos::
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 3, 2
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_LEFT
	return

RustboroCity_DevonCorp_3F_OnWarp:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	end

RustboroCity_DevonCorp_3F_OnFrame:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_MeetPresident
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_MeetPresident::
	lockall
	msgbox RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloor, MSGBOX_DEFAULT
	startquest DEVON_DELIVERY
	completesubquest DEVON_DELIVERY, DEVON_GOODS
	delay 20
	msgbox RustboroCity_DevonCorp_3F_Text_WaitHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen
	waitmovement 0
	delay 80
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_FOLLOW_ME, FALSE
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_PleaseGoAhead, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor, MSGBOX_DEFAULT
	giveitem ITEM_LETTER
	completesubquest DEVON_DELIVERY, STEVEN_LETTER
	delay 20
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_3F_Text_ReceivedPokenav
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenav, MSGBOX_DEFAULT
	call RustboroCity_DevonCorp_3F_EventScript_MeetLanette
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneExplainRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare, MSGBOX_DEFAULT
	setflag FLAG_HIDE_ROUTE_116_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDA
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	clearflag FLAG_HIDE_RUSTBORO_IGNATIUS
	clearflag FLAG_HIDE_RUSTBORO_MOM
	setvar VAR_BRINEY_LOCATION, 1
	clearflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setvar VAR_DEVON_CORP_3F_STATE, 1
	setvar VAR_RUSTBORO_CITY_STATE, 6
	releaseall
	end

RustboroCity_DevonCorp_3F_Movement_Unused:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk:
	delay_16
	walk_in_place_faster_down
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

RustboroCity_DevonCorp_3F_EventScript_MrStone::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_EXP_SHARE, RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, RustboroCity_DevonCorp_3F_EventScript_GiveExpShare
	msgbox RustboroCity_DevonCorp_3F_Text_CountingOnYou, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_GiveExpShare::
	msgbox RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor::
	msgbox RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REPEAT_BALL, RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls
	msgbox RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls::
	msgbox RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_RareRocksDisplay::
	msgbox RustboroCity_DevonCorp_3F_Text_RareRocksDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor:
	.string "I'm MR. STONE, the PRESIDENT of\n"
	.string "the DEVON CORPORATION.\p"
	.string "You may have heard about our mining\n"
	.string "operations in BOREA PASSAGE,\l"
	.string "similar to those in RUSTURF TUNNEL.\p"
	.string "I'd just got word about you!\p"
	.string "You saved our staff not just once,\n"
	.string "but twice!\p"
	.string "I have a favor to ask of an amazing\n"
	.string "person like you.\p"
	.string "I understand that you're delivering\n"
	.string "a package to SLATEPORT's SHIPYARD.\p"
	.string "Well, on the way, could you stop off in\n"
	.string "DEWFORD TOWN?\p"
	.string "I was hoping that you'd deliver a\n"
	.string "LETTER to STEVEN in DEWFORD.$"

RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis:
	.string "MR. STONE: Now, you should know that\n"
	.string "I am a great PRESIDENT.\p"
	.string "So, I'd never be so cheap as to ask\n"
	.string "a favor for nothing in return.\p"
	.string "That's why I want you to have this!$"

RustboroCity_DevonCorp_3F_Text_ReceivedPokenav:
	.string "{PLAYER} received a POKéNAV.$"

RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenav:
	.string "MR. STONE: That device…\p"
	.string "It's a POKéMON NAVIGATOR, or POKéNAV\n"
	.string "for short.\p"
	.string "It's an indispensable tool for any\n"
	.string "TRAINER on an adventure.\p"
	.string "It has a map of the HOENN region.\p"
	.string "You can check the locations of\n"
	.string "DEWFORD and SLATEPORT easily!\p"
	.string "Actually, one of the lead developers\n"
	.string "should be on her way here as we speak.$"

RustboroCity_DevonCorp_3F_Text_MrStoneExplainRestUp:
	.string "I'm glad LANETTE likes you, she's an\n"
	.string "exceptional talent at the DEVON CORP.\p"
	.string "I've heard that sinister criminals\n"
	.string "--TEAM MAGMA and AQUA, I believe--\l"
	.string "have been making trouble far and wide.\p"
	.string "I think it would be best if you rested\n"
	.string "up before you go on your way.$"

RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare:
	.string "MR. STONE: Maybe try speaking to MR.\n"
	.string "BRINEY, he may consider giving you a\l"
	.string "ride to either DEWFORD or SLATEPORT.\p"
	.string "Well then {PLAYER}{KUN}, be safe.\n"
	.string "Go with caution and care!$"
	
RustboroCity_DevonCorp_3F_Text_CountingOnYou:
	.string "MR. STONE: I'm counting on you!$"

RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter:
	.string "MR. STONE: You delivered my LETTER?\n"
	.string "Thank you kindly!\p"
	.string "Did you receive the EXP. SHARE that\n"
	.string "I had sent to you?\l"
	.string "It should help you as a TRAINER.$"

RustboroCity_DevonCorp_3F_Text_ExplainExpShare:
	.string "MR. STONE: A POKéMON holding that\n"
	.string "EXP. SHARE will be given some of the\l"
	.string "EXP Points from battle.\p"
	.string "It will get EXP Points even if it didn't\n"
	.string "actually battle.\p"
	.string "I would say EXP. SHARE is quite useful\n"
	.string "for raising weak POKéMON.$"

RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends:
	.string "MR. STONE: Since my youth, I've immersed\n"
	.string "myself in work.\p"
	.string "Consequently, I'm not familiar with\n"
	.string "trends and that sort of thing.\p"
	.string "But do young people all want to be\n"
	.string "TRAINERS in the POKéMON LEAGUE?$"

RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloor:
	.string "This is the DEVON CORPORATION's\n"
	.string "third floor.\p"
	.string "Our PRESIDENT's OFFICE is on\n"
	.string "this floor.\p"
	.string "Anyway, I can't tell you how much I'm\n"
	.string "grateful for what you've done.\p"
	.string "Um… By the way, that parcel\n"
	.string "you got back for us…\p"
	.string "Could I get you to deliver that to\n"
	.string "the SHIPYARD in SLATEPORT?\p"
	.string "It would be awful if those robbers\n"
	.string "tried to take it again.\p"
	.string "Uh… Hehehe, so, uh, could I count\n"
	.string "on you to do that for me?\l"
	.string "Oh, I can? Thank you so much!$"

RustboroCity_DevonCorp_3F_Text_WaitHere:
	.string "Oh, that's right.\n"
	.string "Could you wait here a second?$"

RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe:
	.string "Our PRESIDENT would like to have\n"
	.string "a word with you.\p"
	.string "Please come with me.$"

RustboroCity_DevonCorp_3F_Text_PleaseGoAhead:
	.string "Please, go ahead.$"

RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard:
	.string "If you visit the SHIPYARD in SLATEPORT,\n"
	.string "you should go see CAPT. STERN.$"

RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular:
	.string "DEVON's new products, the REPEAT BALL\n"
	.string "and TIMER BALL, have become hugely\l"
	.string "popular among TRAINERS.$"

RustboroCity_DevonCorp_3F_Text_RareRocksDisplay:
	.string "It's a collection of rare rocks and\n"
	.string "stones assembled by the PRESIDENT.$"

RustboroCity_DevonCorp_3F_Text_LanetteGreeting:
	.string "LANETTE: Oh, hello there.\n"
	.string "So you're the hero of DEVON CORP.?\l"
	.string "What's your name?\p"
	.string "Okay, so it's {PLAYER}{KUN}.\n"
	.string "I can see that you're a TRAINER.\p"
	.string "Does that mean you use the Storage\n"
	.string "System that MR. STONE mentioned?\p"
	.string "How I arrived at that conclusion is\n"
	.string "a simple deductive process.\p"
	.string "A TRAINER as strong as you certainly\n"
	.string "has raised a plethora of POKéMON.\p"
	.string "Honestly, I'm glad to meet you--it's\n"
	.string "great you're using the Storage System.\l"
	.string "In fact, you could make use of this!$"

RustboroCity_DevonCorp_3F_EventScript_MeetLanette::
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, FaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, FaceLeft
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, RustboroCity_DevonCorp_3F_CameraPan
	waitmovement 0
	playse SE_EXIT
	delay 10
	addobject LOCALID_LANETTE
	delay 30
	applymovement LOCALID_LANETTE, RustboroCity_DevonCorp_3F_LanetteEntrance
	applymovement OBJ_EVENT_ID_CAMERA, RustboroCity_DevonCorp_3F_CameraRevert
	applymovement OBJ_EVENT_ID_PLAYER, FaceUp
	message RustboroCity_DevonCorp_3F_EventScript_MeetLanette_Text_0
	waitmessage
	delay 120
	closemessage
	waitmovement LOCALID_LANETTE
	applymovement LOCALID_LANETTE, FaceDown
	applymovement OBJ_EVENT_ID_PLAYER, FaceUp
	applymovement LOCALID_DEVON_EMPLOYEE, FaceDown
	msgbox RustboroCity_DevonCorp_3F_Text_LanetteGreeting, MSGBOX_DEFAULT
	giveitem ITEM_PSS_LAPTOP, 1
	applymovement OBJ_EVENT_ID_PLAYER, FaceRight
	msgbox RustboroCity_DevonCorp_3F_EventScript_MeetLanette_Text_1, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, FaceUp
	msgbox RustboroCity_DevonCorp_3F_EventScript_MeetLanette_Text_2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LANETTE, RustboroCity_DevonCorp_3F_LanetteExit
	applymovement LOCALID_DEVON_EMPLOYEE, FaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, FaceLeft
	applymovement OBJ_EVENT_ID_CAMERA, RustboroCity_DevonCorp_3F_CameraPan
	waitmovement LOCALID_LANETTE
	playse SE_EXIT
	removeobject LOCALID_LANETTE
	delay 30
	setflag FLAG_MET_LANETTE
	clearflag FLAG_HIDE_LANETTES_HOUSE_LANETTE
	clearflag FLAG_HIDE_LANETTE_AT_LEAGUE
	setflag FLAG_SYS_PC_LANETTE
	waitmovement OBJ_EVENT_ID_CAMERA
	applymovement OBJ_EVENT_ID_CAMERA, RustboroCity_DevonCorp_3F_CameraRevert
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, FaceRight
	applymovement LOCALID_DEVON_EMPLOYEE, FaceDown
	special RemoveCameraObject
	return


RustboroCity_DevonCorp_3F_LanetteEntrance:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_LanetteExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	step_end

RustboroCity_DevonCorp_3F_CameraPan:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RustboroCity_DevonCorp_3F_CameraRevert:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_EventScript_MeetLanette_Text_0:
	.string "MR. STONE: This is LANETTE, she's known\n"
	.string "for developing the {PKMN} Storage System.$"

RustboroCity_DevonCorp_3F_EventScript_MeetLanette_Text_1:
	.string "MR STONE: Ah is this the prototype\n"
	.string "you have been developing?$"

RustboroCity_DevonCorp_3F_EventScript_MeetLanette_Text_2:
	.string "LANETTE: Yes it is exactly!\p"
	.string "This is a way to acess the {PKMN} Storage\n"
	.string "System on the go, wherever you are!\p"
	.string "I was going to test it out, but I\n"
	.string "thought {PLAYER} could do it for me!\l"
	.string "I'm sure they'll find it useful.\p"
	.string "Thanks, {PLAYER}. I must be off now.\n"
	.string "If you could, please visit me at home.\l"
	.string "My house is on ROUTE 114.$"
