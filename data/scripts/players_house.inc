@ Local IDs are the same for both players houses
.set LOCALID_MOM, 1
.set LOCALID_DAD, 5
.set LOCALID_MOM_2F, 14
.set LOCALID_DIANCIE, 15
.set LOCALID_INFERNAPE, 16
.set LOCALID_ESPURR, 17

PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet::
	setvar VAR_LITTLEROOT_INTRO_STATE, 5
	return

PlayersHouse_1F_EventScript_EnterHouseMovingIn::
	msgbox PlayersHouse_1F_Text_IsntItNiceInHere, MSGBOX_DEFAULT
	applymovement VAR_0x8004, Common_Movement_FacePlayer
	waitmovement 0
	call_if_eq VAR_0x8005, MALE, PlayersHouse_1F_EventScript_MomFacePlayerMovingInMale
	call_if_eq VAR_0x8005, FEMALE, PlayersHouse_1F_EventScript_MomFacePlayerMovingInFemale
	call_if_unset FLAG_SYS_DEMO_MODE, LabLights_StartEasyMode
	msgbox PlayersHouse_1F_Text_MoversPokemonGoSetClock, MSGBOX_DEFAULT
	closemessage
	setvar VAR_LITTLEROOT_INTRO_STATE, 4
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerWalkIn
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	releaseall
	end

PlayersHouse_1F_EventScript_MomFacePlayerMovingInMale::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

PlayersHouse_1F_EventScript_MomFacePlayerMovingInFemale::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

PlayersHouse_1F_Movement_PlayerWalkIn:
	walk_up
	step_end

PlayersHouse_1F_EventScript_MomGoSeeRoom::
	msgbox PlayersHouse_1F_Text_ArentYouInterestedInRoom, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_MovePlayerAwayFromDoor
	waitmovement 0
	releaseall
	end

BoreaGlade_BrendansHouse_2F_EventScript_WallClock::
	lockall
	setvar VAR_0x8004, MALE
	goto PlayersHouse_2F_EventScript_WallClock
	end

BoreaGlade_MaysHouse_2F_EventScript_WallClock::
	lockall
	setvar VAR_0x8004, FEMALE
	goto PlayersHouse_2F_EventScript_WallClock
	end

PlayersHouse_2F_EventScript_WallClock::
	goto_if_set FLAG_SET_WALL_CLOCK, PlayersHouse_2F_EventScript_CheckWallClock
	msgbox PlayersHouse_2F_Text_ClockIsStopped, MSGBOX_DEFAULT
	call PlayersHouse_2F_EventScript_SetWallClock
	delay 30
	setflag FLAG_SET_WALL_CLOCK
	setflag FLAG_MOVING_BOXES_HOME
	setflag FLAG_HIDE_BOREA_GLADE_PLAYERS_HOUSE_VIGOROTH
	checkplayergender
	call_if_eq VAR_RESULT, MALE, PlayersHouse_2F_EventScript_MomComesUpstairsMale
	call_if_eq VAR_RESULT, FEMALE, PlayersHouse_2F_EventScript_MomComesUpstairsFemale
	playse SE_EXIT
	removeobject VAR_0x8008
	setflag FLAG_SYS_QUEST_MENU_GET
	startquest ADVENTURE_BEGINS
	releaseall
	end

PlayersHouse_2F_EventScript_MomComesUpstairsMale::
	setvar VAR_0x8008, LOCALID_MOM_2F
	addobject VAR_0x8008
	applymovement VAR_0x8008, PlayersHouse_2F_Movement_MomEntersMale
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox PlayersHouse_2F_Text_HowDoYouLikeYourRoom, MSGBOX_DEFAULT
	giveitem ITEM_QUEST_BOOK
	setvar VAR_RESULT, 0
	msgbox PlayersHouse_2F_Text_CheckItemStorage, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8008, PlayersHouse_2F_Movement_MomExitsMale
	waitmovement 0
	return

PlayersHouse_2F_EventScript_MomComesUpstairsFemale::
	setvar VAR_0x8008, LOCALID_MOM_2F
	addobject VAR_0x8008
	applymovement VAR_0x8008, PlayersHouse_2F_Movement_MomEntersFemale
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PlayersHouse_2F_Text_HowDoYouLikeYourRoom, MSGBOX_DEFAULT
	giveitem ITEM_QUEST_BOOK
	setvar VAR_RESULT, 1
	msgbox PlayersHouse_2F_Text_CheckItemStorage, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8008, PlayersHouse_2F_Movement_MomExitsFemale
	waitmovement 0
	return

PlayersHouse_2F_EventScript_CheckWallClock::
	incrementgamestat GAME_STAT_CHECKED_CLOCK
	fadescreen FADE_TO_BLACK
	special Special_ViewWallClock
	waitstate
	releaseall
	end

PlayersHouse_2F_EventScript_SetWallClock::
	fadescreen FADE_TO_BLACK
	special StartWallClock
	waitstate
	return

PlayersHouse_2F_Movement_MomEntersMale:
	delay_8
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_8
	walk_left
	step_end

PlayersHouse_2F_Movement_MomExitsMale:
	walk_right
	walk_up
	delay_8
	step_end

PlayersHouse_2F_Movement_MomEntersFemale:
	delay_8
	walk_down
	walk_in_place_faster_right
	delay_16
	delay_8
	walk_right
	step_end

PlayersHouse_2F_Movement_MomExitsFemale:
	walk_left
	walk_up
	delay_8
	step_end

PlayersHouse_1F_EventScript_SetWatchedBroadcast::
	setvar VAR_LITTLEROOT_INTRO_STATE, 7
	releaseall
	end

PlayersHouse_1F_EventScript_PetalburgGymReportMale::
	removeitem ITEM_DIANCIE_POKEBALL, 1
	removeitem ITEM_ESPURR_POKEBALL, 1
	applymovement VAR_0x8005, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	call PlayersHouse_1F_EventScript_MomNoticeGymBroadcast
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerApproachTVForGymMale
	waitmovement 0
	playbgm MUS_DP_RIVAL, FALSE
	msgbox PlayersHouse_1F_Text_MaybeDadWillBeOn, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8005, PlayersHouse_1F_Movement_MomMakeRoomToSeeTVMale
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerMoveToTVMale
	waitmovement 0
	call PlayersHouse_1F_EventScript_WatchGymBroadcast
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PlayersHouse_1F_Text_ItsOverWeMissedHim, MSGBOX_DEFAULT
	msgbox PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor, MSGBOX_DEFAULT
	applymovement VAR_0x8005, Exclaim
	playse SE_PIN
	msgbox PlayersHouse_1F_Text_BeforeYouLeave, MSGBOX_DEFAULT
	waitmovement 0
	waitse
	closemessage
	playmoncry SPECIES_DIANCIE, 0
	setvar VAR_TEMP_1, 1
	applymovement VAR_0x8005, PlayersHouse_1F_Movement_MomReturnToSeatMale
	waitmoncry
	playmoncry SPECIES_ESPURR, 0
	waitmovement 0
	waitmoncry
	completesubquest ADVENTURE_BEGINS, MEET_NEIGHBOURS
	clearflag FLAG_HIDE_BRENDANS_HOUSE_DIANCIE
	clearflag FLAG_HIDE_BRENDANS_HOUSE_ESPURR
	goto PlayersHouse_1F_EventScript_SetWatchedBroadcast
	end

PlayersHouse_1F_EventScript_PetalburgGymReportFemale::
	removeitem ITEM_DIANCIE_POKEBALL, 1
	removeitem ITEM_ESPURR_POKEBALL, 1
	applymovement VAR_0x8005, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	call PlayersHouse_1F_EventScript_MomNoticeGymBroadcast
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerApproachTVForGymFemale
	waitmovement 0
	playbgm MUS_DP_RIVAL, FALSE
	msgbox PlayersHouse_1F_Text_MaybeDadWillBeOn, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8005, PlayersHouse_1F_Movement_MomMakeRoomToSeeTVFemale
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerMoveToTVFemale
	waitmovement 0
	call PlayersHouse_1F_EventScript_WatchGymBroadcast
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox PlayersHouse_1F_Text_ItsOverWeMissedHim, MSGBOX_DEFAULT
	msgbox PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor, MSGBOX_DEFAULT
	applymovement VAR_0x8005, Exclaim
	playse SE_PIN
	msgbox PlayersHouse_1F_Text_BeforeYouLeave, MSGBOX_DEFAULT
	waitmovement 0
	waitse
	closemessage
	playmoncry SPECIES_DIANCIE, 0
	setvar VAR_TEMP_1, 1
	applymovement VAR_0x8005, PlayersHouse_1F_Movement_MomReturnToSeatFemale
	waitmoncry
	playmoncry SPECIES_ESPURR, 0
	waitmovement 0
	waitmoncry
	completesubquest ADVENTURE_BEGINS, MEET_NEIGHBOURS
	clearflag FLAG_HIDE_MAYS_HOUSE_DIANCIE
	clearflag FLAG_HIDE_MAYS_HOUSE_ESPURR
	goto PlayersHouse_1F_EventScript_SetWatchedBroadcast
	end

PlayersHouse_1F_EventScript_MomNoticeGymBroadcast::
	playse SE_PIN
	applymovement VAR_0x8005, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8005, Common_Movement_Delay48
	waitmovement 0
	msgbox PlayersHouse_1F_Text_OhComeQuickly, MSGBOX_DEFAULT
	closemessage
	return

PlayersHouse_1F_EventScript_WatchGymBroadcast::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PlayersHouse_1F_Text_ReportFromPetalburgGym, MSGBOX_DEFAULT
	fadedefaultbgm
	special TurnOffTVScreen
	setflag FLAG_SYS_TV_HOME
	delay 35
	return

PlayersHouse_1F_Movement_MomApproachDadMale:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_in_place_faster_right
	step_end

PlayersHouse_1F_Movement_MomApproachDadFemale:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

PlayersHouse_1F_Movement_MomApproachPlayerMale:
	walk_right
	step_end

PlayersHouse_1F_Movement_MomApproachPlayerFemale:
	walk_left
	step_end

PlayersHouse_1F_Movement_MomNoticesLatiBroadcastMale:
	walk_in_place_faster_left
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_right
	delay_16
	delay_16
	step_end

PlayersHouse_1F_Movement_MomNoticesLatiBroadcastFemale:
	walk_in_place_faster_right
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	delay_16
	step_end

PlayersHouse_1F_Movement_MomApproachPlayerAfterTVMale:
	walk_up
	walk_left
	walk_left
	step_end

PlayersHouse_1F_Movement_MomApproachPlayerAfterTVFemale:
	walk_up
	walk_right
	walk_right
	step_end

PlayersHouse_1F_Movement_MomMakeRoomToSeeTVMale:
	walk_left
	walk_in_place_faster_right
	step_end

PlayersHouse_1F_Movement_MomMakeRoomToSeeTVFemale:
	walk_right
	walk_in_place_faster_left
	step_end

PlayersHouse_1F_Movement_MomReturnToSeatMale:
	walk_left
	walk_down
	walk_in_place_faster_right
	step_end

PlayersHouse_1F_Movement_MomReturnToSeatFemale:
	walk_right
	walk_down
	walk_in_place_faster_left
	step_end

PlayersHouse_1F_EventScript_Mom::
	lock
	faceplayer
	goto_if_eq VAR_LITTLEROOT_HOUSES_STATE_MAY, 4, PlayersHouse_1F_EventScript_DontPushYourselfTooHard
	goto_if_eq VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 4, PlayersHouse_1F_EventScript_DontPushYourselfTooHard
	goto_if_set FLAG_HAS_MATCH_CALL, PlayersHouse_1F_EventScript_TryRegisterMom
	goto_if_set FLAG_RESCUED_BIRCH, PlayersHouse_1F_EventScript_MomHealsParty
	goto_if_eq VAR_TEMP_1, 1, PlayersHouse_1F_EventScript_SeeYouHoney
	goto_if_eq VAR_LITTLEROOT_INTRO_STATE, 7, PlayersHouse_1F_EventScript_DidYouMeetProfBirch
	msgbox PlayersHouse_1F_Text_IsntItNiceInHere, MSGBOX_DEFAULT
	release
	end

PlayersHouse_1F_EventScript_DontPushYourselfTooHard::
	msgbox PlayersHouse_1F_Text_DontPushYourselfTooHard, MSGBOX_DEFAULT
	release
	end

PlayersHouse_1F_EventScript_TryRegisterMom::
	goto_if_set FLAG_ENABLE_MOM_MATCH_CALL, PlayersHouse_1F_EventScript_CheckGiveAmuletCoin
	msgbox PlayersHouse_1F_Text_IsThatAPokenav, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox PlayersHouse_1F_Text_RegisteredMom, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_MOM_MATCH_CALL
	release
	end

PlayersHouse_1F_EventScript_CheckGiveAmuletCoin::
	goto_if_set FLAG_BADGE05_GET, PlayersHouse_1F_EventScript_TryGiveAmuletCoin
	goto PlayersHouse_1F_EventScript_MomHealsParty

PlayersHouse_1F_EventScript_TryGiveAmuletCoin::
	goto_if_set FLAG_RECEIVED_AMULET_COIN, PlayersHouse_1F_EventScript_MomHealsParty
	msgbox PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom, MSGBOX_DEFAULT
	giveitem ITEM_AMULET_COIN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox PlayersHouse_1F_Text_DontPushYourselfTooHard, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_AMULET_COIN
	release
	end

PlayersHouse_1F_EventScript_MomHealsParty::
	call LabLights_ToggleEasyMode
	msgbox PlayersHouse_1F_Text_YouShouldRestABit, MSGBOX_DEFAULT
	goto PlayersHouse_1F_EventScript_HealParty
	end

PlayersHouse_1F_EventScript_SeeYouHoney::
	msgbox PlayersHouse_1F_Text_SeeYouHoney, MSGBOX_DEFAULT
	release
	end

PlayersHouse_1F_EventScript_HealParty::
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	incrementgamestat GAME_STAT_RESTED_AT_HOME
	msgbox PlayersHouse_1F_Text_TakeCareHoney, MSGBOX_DEFAULT
	release
	end

PlayersHouse_1F_EventScript_DidYouMeetProfBirch::
	msgbox PlayersHouse_1F_Text_DidYouMeetProfBirch, MSGBOX_DEFAULT
	release
	end

PlayersHouse_1F_EventScript_Vigoroth1::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VIGOROTH, CRY_MODE_NORMAL
	msgbox PlayersHouse_1F_Text_Vigoroth1, MSGBOX_DEFAULT
	waitmoncry
	release
	end

PlayersHouse_1F_EventScript_Vigoroth2::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VIGOROTH, CRY_MODE_NORMAL
	msgbox PlayersHouse_1F_Text_Vigoroth2, MSGBOX_DEFAULT
	waitmoncry
	release
	end

PlayersHouse_1F_EventScript_Vigoroth3::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VIGOROTH, CRY_MODE_NORMAL
	msgbox PlayersHouse_1F_Text_Vigoroth3, MSGBOX_DEFAULT
	waitmoncry
	release
	end

PlayersHouse_1F_EventScript_Vigoroth4::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VIGOROTH, CRY_MODE_NORMAL
	msgbox PlayersHouse_1F_Text_Vigoroth4, MSGBOX_DEFAULT
	waitmoncry
	release
	end

PlayersHouse_1F_Movement_PlayerApproachTVForGymMale:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

PlayersHouse_1F_Movement_PlayerMoveToTVMale:
	walk_left
	step_end

PlayersHouse_1F_Movement_PlayerApproachTVForGymFemale:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

PlayersHouse_1F_Movement_PlayerMoveToTVFemale:
	walk_right
	step_end

PlayersHouse_1F_Movement_MovePlayerAwayFromDoor:
	walk_up
	step_end

PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV::
	lockall
	checkplayergender
	call_if_eq VAR_RESULT, MALE, PlayersHouse_1F_EventScript_SetUpObjectEventVarsMale
	call_if_eq VAR_RESULT, FEMALE, PlayersHouse_1F_EventScript_SetUpObjectEventVarsFemale
	call_if_eq VAR_0x8008, MALE, PlayersHouse_1F_EventScript_PlayerEnterRoomMale
	call_if_eq VAR_0x8008, FEMALE, PlayersHouse_1F_EventScript_PlayerEnterRoomFemale
	applymovement VAR_0x8009, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement VAR_0x8009, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8009, Common_Movement_Delay48
	waitmovement 0
	delay 20
	call_if_eq VAR_0x8008, MALE, PlayersHouse_1F_EventScript_DadApproachPlayerMale
	call_if_eq VAR_0x8008, FEMALE, PlayersHouse_1F_EventScript_DadApproachPlayerFemale
	msgbox PlayersHouse_1F_Text_TicketFromBrineyCameForYou, MSGBOX_DEFAULT
	giveitem ITEM_SS_TICKET
	msgbox PlayersHouse_1F_Text_PortsInSlateportLilycove, MSGBOX_DEFAULT
	closemessage
	delay 20
	call_if_eq VAR_0x8008, MALE, PlayersHouse_1F_EventScript_MomApproachDadMale
	call_if_eq VAR_0x8008, FEMALE, PlayersHouse_1F_EventScript_MomApproachDadFemale
	msgbox PlayersHouse_1F_Text_BetterGetBackToGym, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, MALE, PlayersHouse_1F_EventScript_DadExitsMale
	call_if_eq VAR_0x8008, FEMALE, PlayersHouse_1F_EventScript_DadExitsFemale
	playse SE_DOOR
	removeobject VAR_0x8009
	setflag FLAG_RECEIVED_SS_TICKET
	delay 30
	call_if_eq VAR_0x8008, MALE, PlayersHouse_1F_EventScript_MomApproachPlayerMale
	call_if_eq VAR_0x8008, FEMALE, PlayersHouse_1F_EventScript_MomApproachPlayerFemale
	delay 20
	msgbox PlayersHouse_1F_Text_DadShouldStayLonger, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SYS_TV_LATIAS_LATIOS
	special TurnOnTVScreen
	delay 60
	call_if_eq VAR_0x8008, MALE, PlayersHouse_1F_EventScript_MomNoticesLatiBroadcastMale
	call_if_eq VAR_0x8008, FEMALE, PlayersHouse_1F_EventScript_MomNoticesLatiBroadcastFemale
	msgbox PlayersHouse_1F_Text_IsThatABreakingStory, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, MALE, PlayersHouse_1F_EventScript_PlayerApproachTVForLatiMale
	call_if_eq VAR_0x8008, FEMALE, PlayersHouse_1F_EventScript_PlayerApproachTVForLatiFemale
	msgbox PlayersHouse_1F_Text_LatiEmergencyNewsFlash, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_SYS_TV_LATIAS_LATIOS
	setflag FLAG_LATIOS_OR_LATIAS_ROAMING
	special TurnOffTVScreen
	call_if_eq VAR_0x8008, MALE, PlayersHouse_1F_EventScript_MomApproachPlayerAfterTVMale
	call_if_eq VAR_0x8008, FEMALE, PlayersHouse_1F_EventScript_MomApproachPlayerAfterTVFemale
	msgbox PlayersHouse_1F_Text_WhatColorDidTheySay, MSGBOX_DEFAULT
	multichoice 22, 8, MULTI_TV_LATI, TRUE
	copyvar VAR_0x8004, VAR_RESULT
	special InitRoamer
	copyvar VAR_ROAMER_POKEMON, VAR_RESULT
	msgbox PlayersHouse_1F_Text_StillUnknownPokemon, MSGBOX_DEFAULT
	closemessage
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 4
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 4
	releaseall
	end

@ Never called.
PlayersHouse_1F_EventScript_AirLatiBroadcast::
	setflag FLAG_SYS_TV_LATIAS_LATIOS
	return

PlayersHouse_1F_EventScript_SetUpObjectEventVarsMale::
	setvar VAR_0x8008, MALE
	setvar VAR_0x8009, LOCALID_DAD
	setvar VAR_0x800A, LOCALID_MOM
	return

PlayersHouse_1F_EventScript_SetUpObjectEventVarsFemale::
	setvar VAR_0x8008, FEMALE
	setvar VAR_0x8009, LOCALID_DAD
	setvar VAR_0x800A, LOCALID_MOM
	return

PlayersHouse_1F_EventScript_DadApproachPlayerMale::
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadApproachPlayerMale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_DadApproachPlayerFemale::
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadApproachPlayerFemale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_MomApproachDadMale::
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachDadMale
	waitmovement 0
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadFaceMomMale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_MomApproachDadFemale::
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachDadFemale
	waitmovement 0
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadFaceMomFemale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_DadExitsMale::
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_MomAndPlayerWatchDadExit
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomAndPlayerWatchDadExit
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadExitsMale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_DadExitsFemale::
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_MomAndPlayerWatchDadExit
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomAndPlayerWatchDadExit
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadExitsFemale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_PlayerEnterRoomMale::
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerEnterRoomMale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_PlayerEnterRoomFemale::
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerEnterRoomFemale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_PlayerApproachTVForLatiMale::
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerApproachTVForLatiMale
	waitmovement 0
	applymovement VAR_0x800A, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

PlayersHouse_1F_EventScript_PlayerApproachTVForLatiFemale::
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerApproachTVForLatiFemale
	waitmovement 0
	applymovement VAR_0x800A, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

PlayersHouse_1F_EventScript_MomApproachPlayerMale::
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachPlayerMale
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

PlayersHouse_1F_EventScript_MomApproachPlayerFemale::
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachPlayerFemale
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

PlayersHouse_1F_EventScript_MomNoticesLatiBroadcastMale::
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomNoticesLatiBroadcastMale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_MomNoticesLatiBroadcastFemale::
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomNoticesLatiBroadcastFemale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_MomApproachPlayerAfterTVMale::
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachPlayerAfterTVMale
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

PlayersHouse_1F_EventScript_MomApproachPlayerAfterTVFemale::
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachPlayerAfterTVFemale
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

PlayersHouse_1F_Movement_DadApproachPlayerMale:
	walk_right
	walk_right
	step_end

PlayersHouse_1F_Movement_DadApproachPlayerFemale:
	walk_left
	walk_left
	step_end

PlayersHouse_1F_Movement_DadFaceMomMale:
	face_left
	step_end

PlayersHouse_1F_Movement_DadFaceMomFemale:
	face_right
	step_end

PlayersHouse_1F_Movement_DadExitsMale:
	walk_down
	walk_right
	walk_down
	delay_8
	step_end

PlayersHouse_1F_Movement_DadExitsFemale:
	walk_down
	walk_left
	walk_down
	delay_8
	step_end

PlayersHouse_1F_Movement_PlayerEnterRoomMale:
	delay_16
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

PlayersHouse_1F_Movement_MomAndPlayerWatchDadExit:
	delay_8
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

PlayersHouse_1F_Movement_PlayerEnterRoomFemale:
	delay_16
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

PlayersHouse_1F_Movement_PlayerApproachTVForLatiMale:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

PlayersHouse_1F_Movement_PlayerApproachTVForLatiFemale:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

EventScript_RunningShoesManual::
	msgbox PlayersHouse_1F_Text_RunningShoesManual, MSGBOX_SIGN
	end

PlayerHouse_MovingBoxes::
	compare VAR_TEMP_A, 1
	goto_if_eq PlayerHouse_MovingBoxes_1
	return

PlayerHouse_MovingBoxes_1:
	lock
	msgbox PlayerHouse_MovingBoxes_Text_0, MSGBOX_DEFAULT
	closemessage
	release
	return


AsaParentBedroom::
	lock
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, WalkDown
	waitmovement 0
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq AsaParentBedroom_1
	goto RivalParentsRoom
	return

AsaParentBedroom_1:
	goto PlayerParentsRoom
	return


AriaParentBedroom::
	lock
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, WalkDown
	waitmovement 0
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq AriaParentBedroom_1
	goto PlayerParentsRoom
	return

AriaParentBedroom_1:
	goto RivalParentsRoom
	return


PlayerParentsRoom::
	msgbox PlayerParentsRoom_Text_0, MSGBOX_DEFAULT
	closemessage
	release
	return


RivalParentsRoom::
	msgbox RivalParentsRoom_Text_0, MSGBOX_DEFAULT
	closemessage
	release
	return


AsaSleepBed::
	lock
	questmenu QUEST_MENU_CHECK_COMPLETE, ADVENTURE_BEGINS
	compare VAR_RESULT, TRUE
	goto_if_eq AsaSleepBed_1
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq AsaSleepBed_7
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, WalkRight
	waitmovement 0
	goto RivalBed
	return

AsaSleepBed_1:
	delay 20
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq AsaSleepBed_4
	applymovement OBJ_EVENT_ID_PLAYER, WalkRight
	waitmovement 0
	goto RivalBed
	return

AsaSleepBed_4:
	goto PlayerBed
	return

AsaSleepBed_7:
	goto ShouldNotSleepYet
	return


AriaSleepBed::
	lock
	questmenu QUEST_MENU_CHECK_COMPLETE, ADVENTURE_BEGINS
	compare VAR_RESULT, TRUE
	goto_if_eq AriaSleepBed_1
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq AriaSleepBed_7
	goto ShouldNotSleepYet
	return

AriaSleepBed_1:
	delay 20
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq AriaSleepBed_4
	goto PlayerBed
	return

AriaSleepBed_4:
	applymovement OBJ_EVENT_ID_PLAYER, WalkLeft
	waitmovement 0
	goto RivalBed
	return

AriaSleepBed_7:
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, WalkLeft
	waitmovement 0
	goto RivalBed
	return


PlayerBed::
	goto_if_unset FLAG_SYS_REAL_TIME, PlayerBed_1
	call PlayerReturnToLastPosition
	msgbox PlayerBed_Text_1, MSGBOX_SIGN
	end

PlayerBed_1:
	applymovement OBJ_EVENT_ID_PLAYER, FaceDown
	waitmovement 0
	msgbox PlayerBed_Text_0, MSGBOX_DEFAULT
	waitmessage
	multichoice 25, 2, MULTI_TIME_OF_DAY, 0
	switch VAR_RESULT
	case 0, PlayerBed_6
	case 1, PlayerBed_7
	case 2, PlayerBed_8
	case 3, PlayerBed_9
	case 4, PlayerBed_10
PlayerBed_10:
	closemessage
	delay 20
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq PlayerBed_18
	applymovement OBJ_EVENT_ID_PLAYER, WalkLeft
	waitmovement 0
PlayerBed_17:
	msgbox PlayerBed_Text_1, MSGBOX_DEFAULT
	closemessage
	end

PlayerBed_4:
	fadescreen 1
	closemessage
	playse SE_EXP_MAX
	waitse
	delay 10
	playse SE_EXP_MAX
	waitse
	delay 10
	playse SE_EXP_MAX
	waitse
	delay 10
	special HealPlayerParty
	fadescreen 0
	delay 20
	switch VAR_RESULT
	case 0, PlayerBed_13
	case 1, PlayerBed_14
	case 2, PlayerBed_15
	case 3, PlayerBed_16
PlayerBed_11:
	closemessage
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq PlayerBed_22
	applymovement OBJ_EVENT_ID_PLAYER, WalkLeft
	waitmovement 0
PlayerBed_21:
	release
	return

PlayerBed_6:
	call MorningSleep
	goto PlayerBed_4

PlayerBed_7:
	call AfternoonSleep
	goto PlayerBed_4

PlayerBed_8:
	call EveningSleep
	goto PlayerBed_4

PlayerBed_9:
	call NightSleep
	goto PlayerBed_4

PlayerBed_13:
	msgbox PlayerBed_Text_2, MSGBOX_DEFAULT
	goto PlayerBed_11

PlayerBed_14:
	msgbox PlayerBed_Text_3, MSGBOX_DEFAULT
	goto PlayerBed_11

PlayerBed_15:
	msgbox PlayerBed_Text_4, MSGBOX_DEFAULT
	goto PlayerBed_11

PlayerBed_16:
	msgbox PlayerBed_Text_5, MSGBOX_DEFAULT
	goto PlayerBed_11

PlayerBed_18:
	applymovement OBJ_EVENT_ID_PLAYER, WalkRight
	waitmovement 0
	goto PlayerBed_17

PlayerBed_22:
	applymovement OBJ_EVENT_ID_PLAYER, WalkRight
	waitmovement 0
	goto PlayerBed_21


RivalBed::
	msgbox RivalBed_Text_0, MSGBOX_DEFAULT
	closemessage
	release
	return


ShouldNotSleepYet::
	applymovement OBJ_EVENT_ID_PLAYER, FaceDown
	waitmovement 0
	delay 30
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq ShouldNotSleepYet_2
	applymovement OBJ_EVENT_ID_PLAYER, WalkLeft
	waitmovement 0
ShouldNotSleepYet_1:
	msgbox ShouldNotSleepYet_Text_0, MSGBOX_DEFAULT
	closemessage
	release
	return

ShouldNotSleepYet_2:
	applymovement OBJ_EVENT_ID_PLAYER, WalkRight
	waitmovement 0
	goto ShouldNotSleepYet_1


PlayersHouse_1F_EventScript_Lauren::
	goto_if_unset FLAG_SET_HOMELY_STATE, PlayersHouse_1F_EventScript_Lauren_1
	return

PlayersHouse_1F_EventScript_Lauren_1:
	goto PlayersHouse_1F_EventScript_Mom
	return


PlayersHouse_1F_EventScript_Samuel::
	goto_if_unset FLAG_SET_HOMELY_STATE, PlayersHouse_1F_EventScript_Samuel_1
	return

PlayersHouse_1F_EventScript_Samuel_1:
	return


PlayersHouse_1F_EventScript_Diancie::
	lock
	showmonpic SPECIES_DIANCIE, 10, 3
	playmoncry SPECIES_DIANCIE, 0
	setseenmon SPECIES_DIANCIE
	faceplayer
	message PlayersHouse_1F_EventScript_Diancie_Text_0
	waitmessage
	waitmoncry
	waitbuttonpress
	hidemonpic
	release
	return


PlayersHouse_1F_EventScript_Infernape::
	lock
	showmonpic SPECIES_INFERNAPE, 10, 3
	playmoncry SPECIES_INFERNAPE, 0
	setseenmon SPECIES_INFERNAPE
	faceplayer
	message PlayersHouse_1F_EventScript_Infernape_Text_0
	waitmessage
	waitmoncry
	waitbuttonpress
	hidemonpic
	release
	return


PlayersHouse_1F_EventScript_Espurr::
	showmonpic SPECIES_ESPURR, 10, 3
	playmoncry SPECIES_ESPURR, 0
	setseenmon SPECIES_ESPURR
	msgbox PlayersHouse_1F_EventScript_Espurr_Text_0, MSGBOX_NPC
	waitmoncry
	closemessage
	hidemonpic
	subquestmenu QUEST_MENU_CHECK_COMPLETE, ADVENTURE_BEGINS, DAD_CATCH_UP
	goto_if_unset FLAG_CHOSEN_ESPURR_GENDER, PlayersHouse_1F_EventScript_Espurr_2
	return

PlayersHouse_1F_EventScript_Espurr_1:
	goto PlayersHouse_1F_EventScript_Espurr_ChooseGender
	return

PlayersHouse_1F_EventScript_Espurr_2:
	compare VAR_RESULT, TRUE
	goto_if_eq PlayersHouse_1F_EventScript_Espurr_1
	return


PlayersHouse_1F_EventScript_Espurr_ChooseGender::
	delay 30
	msgbox PlayersHouse_1F_EventScript_Espurr_ChooseGender_Text_0, MSGBOX_DEFAULT
	multichoice 4, 8, MULTI_POPPY_PEDRO, TRUE
	compare VAR_RESULT, 0
	goto_if_eq PlayersHouse_1F_EventScript_Espurr_ChooseGender_2
	compare VAR_RESULT, 1
	goto_if_eq PlayersHouse_1F_EventScript_Espurr_ChooseGender_3
PlayersHouse_1F_EventScript_Espurr_ChooseGender_1:
	setflag FLAG_CHOSEN_ESPURR_GENDER
	closemessage
	playmoncry SPECIES_ESPURR, 0
	waitmoncry
	goto_if_unset FLAG_SET_HOMELY_STATE, PlayersHouse_1F_EventScript_Espurr_ChooseGender_6
	goto PlayersHouse_1F_EventScript_Espurr_GiveAfterHomely
	return

PlayersHouse_1F_EventScript_Espurr_ChooseGender_2:
	setflag FLAG_ESPURR_GENDER
	msgbox PlayersHouse_1F_EventScript_Espurr_ChooseGender_Text_1, MSGBOX_DEFAULT
	goto PlayersHouse_1F_EventScript_Espurr_ChooseGender_1

PlayersHouse_1F_EventScript_Espurr_ChooseGender_3:
	msgbox PlayersHouse_1F_EventScript_Espurr_ChooseGender_Text_2, MSGBOX_DEFAULT
	goto PlayersHouse_1F_EventScript_Espurr_ChooseGender_1

PlayersHouse_1F_EventScript_Espurr_ChooseGender_6:
	goto PlayersHouse_1F_EventScript_Espurr_GiveBeforeHomely
	return


PlayersHouse_1F_EventScript_Espurr_GiveBeforeHomely::
	bufferleadmonspeciesname STR_VAR_1
	goto_if_set FLAG_ESPURR_GENDER, PlayersHouse_1F_EventScript_Espurr_GiveBeforeHomely_2
	msgbox PlayersHouse_1F_EventScript_Espurr_GiveBeforeHomely_Text_1, MSGBOX_DEFAULT
PlayersHouse_1F_EventScript_Espurr_GiveBeforeHomely_1:
	waitmoncry
	closemessage
	playmoncry SPECIES_ESPURR, 0
	waitmoncry
	goto_if_set FLAG_ESPURR_GENDER, PlayersHouse_1F_EventScript_Espurr_GiveBeforeHomely_6
	msgbox PlayersHouse_1F_EventScript_Espurr_GiveBeforeHomely_Text_2, MSGBOX_YESNO
PlayersHouse_1F_EventScript_Espurr_GiveBeforeHomely_5:
	compare VAR_RESULT, NO
	goto_if_eq PlayersHouse_1F_EventScript_Espurr_GiveBeforeHomely_10
	goto_if_set FLAG_ESPURR_GENDER, PlayersHouse_1F_EventScript_Espurr_GiveBeforeHomely_14
	msgbox PlayersHouse_1F_EventScript_Espurr_GiveBeforeHomely_Text_5, MSGBOX_DEFAULT
PlayersHouse_1F_EventScript_Espurr_GiveBeforeHomely_13:
	giveitem ITEM_ESPURR_POKEBALL, 1
	setcaughtmon SPECIES_ESPURR
	setflag FLAG_HIDE_BRENDANS_HOUSE_ESPURR
	setflag FLAG_HIDE_MAYS_HOUSE_ESPURR
PlayersHouse_1F_EventScript_Espurr_GiveBeforeHomely_9:
	closemessage
	end

PlayersHouse_1F_EventScript_Espurr_GiveBeforeHomely_2:
	msgbox PlayersHouse_1F_EventScript_Espurr_GiveBeforeHomely_Text_0, MSGBOX_DEFAULT
	goto PlayersHouse_1F_EventScript_Espurr_GiveBeforeHomely_1

PlayersHouse_1F_EventScript_Espurr_GiveBeforeHomely_6:
	msgbox PlayersHouse_1F_EventScript_Espurr_GiveBeforeHomely_Text_2, MSGBOX_YESNO
	goto PlayersHouse_1F_EventScript_Espurr_GiveBeforeHomely_5

PlayersHouse_1F_EventScript_Espurr_GiveBeforeHomely_10:
	msgbox PlayersHouse_1F_EventScript_Espurr_GiveBeforeHomely_Text_3, MSGBOX_DEFAULT
	goto PlayersHouse_1F_EventScript_Espurr_GiveBeforeHomely_9

PlayersHouse_1F_EventScript_Espurr_GiveBeforeHomely_14:
	msgbox PlayersHouse_1F_EventScript_Espurr_GiveBeforeHomely_Text_4, MSGBOX_DEFAULT
	goto PlayersHouse_1F_EventScript_Espurr_GiveBeforeHomely_13


PlayersHouse_1F_EventScript_Espurr_GiveAfterHomely::
	return


PlayerHouse_MovingBoxes_Text_0:
	.string "It's a box full of our family's things.\n"
	.string "The mover's POKéMON brought them in.$"

PlayerParentsRoom_Text_0:
	.string "This is MOM and DAD’s room.\n"
	.string "I should give them some privacy.$"

RivalParentsRoom_Text_0:
	.string "This is PROFESSOR IGNATIUS’ room.\n"
	.string "I should give him some privacy.$"

PlayerBed_Text_0:
	.string "What time should I sleep until?$"

PlayerBed_Text_1:
	.string "No time to sleep!\n"
	.string "I'm on an adventure!$"

PlayerBed_Text_2:
	.string "{PLAYER} WOKE UP AT 9AM$"

PlayerBed_Text_3:
	.string "{PLAYER} WOKE UP AT 1PM$"

PlayerBed_Text_4:
	.string "{PLAYER} WOKE UP AT 6PM$"

PlayerBed_Text_5:
	.string "{PLAYER} WOKE UP AT 10PM$"

RivalBed_Text_0:
	.string "This is {RIVAL}'s bed.\n"
	.string "I shouldn't sleep in here.$"

ShouldNotSleepYet_Text_0:
	.string "I shouldn't sleep yet,\n"
	.string "I need to finish moving in.$"

PlayersHouse_1F_EventScript_Diancie_Text_0:
	.string "It's MOM's DIANCIE!$"

PlayersHouse_1F_EventScript_Infernape_Text_0:
	.string "It's DAD's INFERNAPE!$"

PlayersHouse_1F_EventScript_Espurr_Text_0:
	.string "It's the family ESPURR!$"

PlayersHouse_1F_EventScript_Espurr_ChooseGender_Text_0:
	.string "MOM: That's our ESPURR, whilst one of\n"
	.string "the most adorable POKéMON I've ever,\l"
	.string "ESPURR is such a rambunctious scamp.\p"
	.string "I've been calling ESPURR “NORTI TORTI”,\n"
	.string "but we need to settle on a name.\l"
	.string "What do you think?$"

PlayersHouse_1F_EventScript_Espurr_ChooseGender_Text_1:
	.string "MOM: I knew it, that's the most\n"
	.string "wonderful name for her.\p"
	.string "ESPURR is so very shy, but I just know\n"
	.string "some adventure would do her good…$"

PlayersHouse_1F_EventScript_Espurr_ChooseGender_Text_2:
	.string "MOM: I knew it, that's the most\n"
	.string "wonderful name for him.\p"
	.string "ESPURR is so very shy, but I just know\n"
	.string "some adventure would do him good…$"

PlayersHouse_1F_EventScript_Espurr_GiveBeforeHomely_Text_0:
	.string "MOM: Wow, it sounds like ESPURR enjoys\n"
	.string "hanging out with {STR_VAR_1}.\p"
	.string "Maybe she can go with you on your\n"
	.string "adventure? She wouldn't battle, but,\l"
	.string "she could get out and see the world.\p"
	.string "Do you like the sound of that ESPURR?$"

PlayersHouse_1F_EventScript_Espurr_GiveBeforeHomely_Text_1:
	.string "MOM: Wow, it sounds like ESPURR enjoys\n"
	.string "hanging out with {STR_VAR_1}.\p"
	.string "Maybe he can go with you on your\n"
	.string "adventure? He wouldn't battle, but,\l"
	.string "he could get out and see the world.\p"
	.string "Do you like the sound of that ESPURR?$"

PlayersHouse_1F_EventScript_Espurr_GiveBeforeHomely_Text_2:
	.string "MOM: It sounds like she's really up for\n"
	.string "this experience with you!\l"
	.string "Is that okay, will you take ESPURR?$"

PlayersHouse_1F_EventScript_Espurr_GiveBeforeHomely_Text_3:
	.string "Don't worry, ESPURR will be here if you\n"
	.string "change your mind.\l"
	.string "Take good care, {PLAYER}!$"

PlayersHouse_1F_EventScript_Espurr_GiveBeforeHomely_Text_4:
	.string "Here, let me return her POKéBALL to you.\n"
	.string "Think of a name for her on your travels.\l"
	.string "Take good care of her, {PLAYER}!$"

PlayersHouse_1F_EventScript_Espurr_GiveBeforeHomely_Text_5:
	.string "Here, let me return him POKéBALL to you.\n"
	.string "Think of a name for him on your travels.\l"
	.string "Take good care of him, {PLAYER}!$"
