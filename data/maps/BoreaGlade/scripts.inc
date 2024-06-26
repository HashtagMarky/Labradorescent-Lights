.set LOCALID_TWIN, 1
.set LOCALID_MOM, 4
.set LOCALID_RIVAL, 7
.set LOCALID_BIRCH, 8

BoreaGlade_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BoreaGlade_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BoreaGlade_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BoreaGlade_OnWarp
	.byte 0

	@ State descriptions for VAR_BOREA_GLADE_STATE
	@ 1: Met Rival
	@ 2: Saving Birch
	@ 3: Received Pokedex
	@ 4: Received Running Shoes

	@ State descriptions for VAR_LITTLEROOT_INTRO_STATE
	@ 1: In truck male
	@ 2: In truck female
	@ 3: Entered house
	@ 4: Told to go set clock
	@ 5: Entered 2F to set clock
	@ 6: Set clock
	@ 7: Told to go meet rival

	@ State descriptions for VAR_LITTLEROOT_HOUSES_STATE_MAY
	@                    and VAR_LITTLEROOT_HOUSES_STATE_BRENDAN
	@ 1: On Truck (and is corresponding gender)
	@ 2: Met Rival's Mom (and is corresponding gender)
	@ 3: Entered Hall of Fame
	@ 4: Completed Lati TV / SS Ticket event
	@ 5: Exited house after above event

	@ State descriptions for VAR_LITTLEROOT_RIVAL_STATE
	@ 1: Never occurs
	@ 2: Entered Rival's bedroom
	@ 3: Met Rival
	@ 4: Received Pokedex


BoreaGlade_OnTransition:
	setflag FLAG_VISITED_BOREA_GLADE
	call Common_EventScript_SetupRivalGfxId
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 2, BoreaGlade_EventScript_MoveMomToMaysDoor
	call_if_unset FLAG_RESCUED_BIRCH, BoreaGlade_EventScript_SetTwinPos
	call_if_eq VAR_BOREA_GLADE_STATE, 3, BoreaGlade_EventScript_SetMomStandingInFrontOfDoorPos
	call_if_eq VAR_LITTLEROOT_HOUSES_STATE_MAY, 4, BoreaGlade_EventScript_SetExitedHouseAfterLatiSSTicketEvent
	call_if_eq VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 4, BoreaGlade_EventScript_SetExitedHouseAfterLatiSSTicketEvent
	call_if_eq VAR_OLDALE_RIVAL_STATE, 1, BoreaGlade_EventScript_MoveRivalFromOldale
	call_if_eq VAR_LITTLEROOT_RIVAL_STATE, 3, BoreaGlade_EventScript_SetRivalLeftForRoute103
	call_if_eq VAR_POSTGAME_BIRCH_GIFT, 1, BoreaGlade_EventScript_HideMapNamePopup
	call_if_eq VAR_POSTGAME_BIRCH_GIFT, 3, BoreaGlade_EventScript_LeftLabAfterPostgameGift
	end

BoreaGlade_EventScript_LeftLabAfterPostgameGift::
	call_if_unset FLAG_SCOTT_POSTGAME_CALL, BoreaGlade_EventScript_EnableScottCall
	return

BoreaGlade_EventScript_EnableScottCall::
	setvar VAR_SCOTT_BF_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_BATTLE_FRONTIER
	setvar VAR_POSTGAME_BIRCH_GIFT, 4
	return

BoreaGlade_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

BoreaGlade_EventScript_SetRivalLeftForRoute103::
	setflag FLAG_RIVAL_LEFT_FOR_ROUTE103
	return

BoreaGlade_EventScript_MoveRivalFromOldale::
	setvar VAR_OLDALE_RIVAL_STATE, 2
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	return

BoreaGlade_EventScript_SetExitedHouseAfterLatiSSTicketEvent::
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 5
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 5
	return

BoreaGlade_EventScript_MoveMomToMaysDoor::
	setobjectxyperm LOCALID_MOM, 14, 8
	return

BoreaGlade_EventScript_SetTwinPos::
	goto_if_eq VAR_BOREA_GLADE_STATE, 0, BoreaGlade_EventScript_SetTwinGuardingRoutePos
	setobjectxyperm LOCALID_TWIN, 10, 1
	setobjectmovementtype LOCALID_TWIN, MOVEMENT_TYPE_FACE_UP
	return

BoreaGlade_EventScript_SetTwinGuardingRoutePos::
	setobjectxyperm LOCALID_TWIN, 7, 2
	setobjectmovementtype LOCALID_TWIN, MOVEMENT_TYPE_FACE_DOWN
	return

BoreaGlade_EventScript_SetMomStandingInFrontOfDoorPos::
	clearflag FLAG_HIDE_BOREA_GLADE_MOM_OUTSIDE
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_DOWN
	checkplayergender
	call_if_eq VAR_RESULT, MALE, BoreaGlade_EventScript_SetMomInFrontOfDoorMale
	call_if_eq VAR_RESULT, FEMALE, BoreaGlade_EventScript_SetMomInFrontOfDoorFemale
	return

BoreaGlade_EventScript_SetMomInFrontOfDoorMale::
	setobjectxyperm LOCALID_MOM, 5, 9
	return

BoreaGlade_EventScript_SetMomInFrontOfDoorFemale::
	setobjectxyperm LOCALID_MOM, 14, 9
	return

BoreaGlade_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 1, BoreaGlade_EventScript_StepOffTruckMale
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 2, BoreaGlade_EventScript_StepOffTruckFemale
	map_script_2 VAR_POSTGAME_BIRCH_GIFT, 1, BoreaGlade_EventScript_BeginPostgameBirchScene
	map_script_2 VAR_TEMP_0, 0, BoreaGlade_LockPlayerDoor
	map_script_2 VAR_SELENIC_CALLS, 5, SelenicPokeNavCall
	.2byte 0

BoreaGlade_EventScript_StepOffTruckMale::
	lockall
	setvar VAR_0x8004, 5
	setvar VAR_0x8005, 8
	call BoreaGlade_EventScript_GoInsideWithMom
	setflag FLAG_HIDE_BOREA_GLADE_BRENDANS_HOUSE_TRUCK
	warpsilent MAP_BOREA_GLADE_BRENDANS_HOUSE_1F, 8, 8
	waitstate
	releaseall
	end

BoreaGlade_EventScript_StepOffTruckFemale::
	lockall
	setvar VAR_0x8004, 14
	setvar VAR_0x8005, 8
	call BoreaGlade_EventScript_GoInsideWithMom
	setflag FLAG_HIDE_BOREA_GLADE_MAYS_HOUSE_TRUCK
	warpsilent MAP_BOREA_GLADE_MAYS_HOUSE_1F, 2, 8
	waitstate
	releaseall
	end

BoreaGlade_EventScript_GoInsideWithMom::
	delay 15
	playse SE_LEDGE
	applymovement OBJ_EVENT_ID_PLAYER, BoreaGlade_Movement_PlayerStepOffTruck
	waitmovement 0

	@ Demo Mode Begin Announcement
	call_if_set FLAG_SYS_DEMO_MODE, DemoBegin

	opendoor VAR_0x8004, VAR_0x8005
	waitdooranim
	addobject LOCALID_MOM
	applymovement LOCALID_MOM, BoreaGlade_Movement_MomExitHouse
	waitmovement 0
	closedoor VAR_0x8004, VAR_0x8005
	waitdooranim
	delay 10
	applymovement LOCALID_MOM, BoreaGlade_Movement_MomApproachPlayerAtTruck
	waitmovement 0
	msgbox BoreaGlade_Text_OurNewHomeLetsGoInside, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOM, BoreaGlade_Movement_MomApproachDoor
	applymovement OBJ_EVENT_ID_PLAYER, BoreaGlade_Movement_PlayerApproachDoor
	waitmovement 0
	opendoor VAR_0x8004, VAR_0x8005
	waitdooranim
	applymovement LOCALID_MOM, BoreaGlade_Movement_MomEnterHouse
	applymovement OBJ_EVENT_ID_PLAYER, BoreaGlade_Movement_PlayerEnterHouse
	waitmovement 0
	setflag FLAG_HIDE_BOREA_GLADE_MOM_OUTSIDE
	setvar VAR_LITTLEROOT_INTRO_STATE, 3
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	closedoor VAR_0x8004, VAR_0x8005
	waitdooranim
	clearflag FLAG_HIDE_BOREA_GLADE_FAT_MAN
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	return

BoreaGlade_Movement_MomExitHouse:
	walk_down
	step_end

BoreaGlade_Movement_MomApproachPlayerAtTruck:
	walk_down
	walk_in_place_faster_left
	step_end

BoreaGlade_Movement_MomApproachDoor:
	delay_16
	delay_8
	walk_up
	step_end

BoreaGlade_Movement_MomEnterHouse:
	walk_up
	set_invisible
	step_end

BoreaGlade_Movement_PlayerApproachDoor:
	delay_16
	delay_8
	walk_right
	walk_in_place_faster_up
	step_end

BoreaGlade_Movement_PlayerEnterHouse:
	walk_up
	walk_up
	step_end

BoreaGlade_Movement_PlayerStepOffTruck:
	jump_right
	delay_16
	delay_16
	delay_16
	step_end

BoreaGlade_EventScript_BeginPostgameBirchScene::
	lockall
	playse SE_PIN
	applymovement LOCALID_BIRCH, Common_Movement_ExclamationMark
	waitmovement 0
	delay 80
	msgbox BoreaGlade_Text_BirchSomethingToShowYouAtLab, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_BOREA_GLADE_RIVAL
	clearflag FLAG_HIDE_BOREA_GLADE_BIRCH
	delay 20
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	warp MAP_BOREA_GLADE_PROFESSOR_BIRCHS_LAB, 6, 5
	setflag FLAG_HIDE_BOREA_GLADE_RIVAL
	setflag FLAG_HIDE_BOREA_GLADE_BIRCH
	waitstate
	releaseall
	end

BoreaGlade_OnWarp:
	map_script_2 VAR_POSTGAME_BIRCH_GIFT, 1, BoreaGlade_EventScript_SetRivalBirchPostgamePos
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 1, TruckFacingDirection
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 2, TruckFacingDirection
	.2byte 0

BoreaGlade_EventScript_SetRivalBirchPostgamePos::
	addobject LOCALID_BIRCH
	addobject LOCALID_RIVAL
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, BoreaGlade_EventScript_SetRivalBirchPostgamePosMale
	goto BoreaGlade_EventScript_SetRivalBirchPostgamePosFemale
	end

BoreaGlade_EventScript_SetRivalBirchPostgamePosMale::
	setobjectxy LOCALID_RIVAL, 6, 10
	setobjectxy LOCALID_BIRCH, 5, 10
	end

BoreaGlade_EventScript_SetRivalBirchPostgamePosFemale::
	setobjectxy LOCALID_RIVAL, 13, 10
	setobjectxy LOCALID_BIRCH, 14, 10
	end

BoreaGlade_EventScript_FatMan::
	msgbox BoreaGlade_Text_CanUsePCToStoreItems, MSGBOX_NPC
	end

BoreaGlade_EventScript_Boy::
	msgbox BoreaGlade_Text_BirchSpendsDaysInLab, MSGBOX_NPC
	end

BoreaGlade_EventScript_Twin::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, BoreaGlade_EventScript_GoodLuck
	goto_if_set FLAG_RESCUED_BIRCH, BoreaGlade_EventScript_YouSavedBirch
	goto_if_ne VAR_BOREA_GLADE_STATE, 0, BoreaGlade_EventScript_GoSaveBirch
	msgbox BoreaGlade_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
	release
	end

BoreaGlade_EventScript_GoSaveBirch::
	special GetPlayerBigGuyGirlString
	msgbox BoreaGlade_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setvar VAR_BOREA_GLADE_STATE, 2
	release
	end

BoreaGlade_EventScript_YouSavedBirch::
	special GetPlayerBigGuyGirlString
	msgbox BoreaGlade_Text_YouSavedBirch, MSGBOX_DEFAULT
	release
	end

BoreaGlade_EventScript_GoodLuck::
	msgbox BoreaGlade_Text_GoodLuckCatchingPokemon, MSGBOX_DEFAULT
	release
	end

BoreaGlade_EventScript_NeedPokemonTriggerLeft::
	lockall
	applymovement LOCALID_TWIN, BoreaGlade_Movement_TwinApproachPlayerLeft
	waitmovement 0
	call BoreaGlade_EventScript_DangerousWithoutPokemon
	applymovement LOCALID_TWIN, BoreaGlade_Movement_TwinReturnLeft
	waitmovement 0
	releaseall
	end

BoreaGlade_EventScript_DangerousWithoutPokemon::
	msgbox BoreaGlade_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TWIN, BoreaGlade_Movement_TwinPushPlayerFromRoute
	applymovement OBJ_EVENT_ID_PLAYER, BoreaGlade_Movement_PushPlayerBackFromRoute
	waitmovement 0
	msgbox BoreaGlade_Text_DangerousIfYouDontHavePokemon, MSGBOX_DEFAULT
	closemessage
	return

BoreaGlade_Movement_TwinApproachPlayerLeft:
	face_right
	delay_8
	disable_jump_landing_ground_effect
	jump_in_place_right
	delay_8
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_left
	face_down
	step_end

BoreaGlade_Movement_TwinPushPlayerFromRoute:
	walk_down
	step_end

BoreaGlade_Movement_TwinReturnLeft:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_in_place_faster_down
	step_end

BoreaGlade_Movement_PushPlayerBackFromRoute:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

BoreaGlade_EventScript_NeedPokemonTriggerRight::
	lockall
	applymovement LOCALID_TWIN, BoreaGlade_Movement_TwinApproachPlayerRight
	waitmovement 0
	call BoreaGlade_EventScript_DangerousWithoutPokemon
	applymovement LOCALID_TWIN, BoreaGlade_Movement_TwinReturnRight
	waitmovement 0
	releaseall
	end

BoreaGlade_Movement_TwinApproachPlayerRight:
	face_right
	delay_8
	disable_jump_landing_ground_effect
	jump_in_place_right
	delay_8
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_right
	face_down
	step_end

BoreaGlade_Movement_TwinReturnRight:
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

BoreaGlade_EventScript_GoSaveBirchTrigger::
	lockall
	applymovement LOCALID_TWIN, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	special GetPlayerBigGuyGirlString
	msgbox BoreaGlade_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setvar VAR_BOREA_GLADE_STATE, 2
	releaseall
	end

BoreaGlade_EventScript_TownSign::
	msgbox BoreaGlade_Text_TownSign, MSGBOX_SIGN
	end

BoreaGlade_EventScript_BirchsLabSign::
	msgbox BoreaGlade_Text_ProfBirchsLab, MSGBOX_SIGN
	end

BoreaGlade_EventScript_BrendansHouseSign::
	lockall
	checkplayergender
	call_if_eq VAR_RESULT, MALE, BoreaGlade_EventScript_PlayersHouseSignMale
	call_if_eq VAR_RESULT, FEMALE, BoreaGlade_EventScript_BirchsHouseSignFemale
	releaseall
	end

BoreaGlade_EventScript_PlayersHouseSignMale::
	msgbox BoreaGlade_Text_PlayersHouse, MSGBOX_DEFAULT
	return

BoreaGlade_EventScript_BirchsHouseSignFemale::
	msgbox BoreaGlade_Text_ProfBirchsHouse, MSGBOX_DEFAULT
	return

BoreaGlade_EventScript_MaysHouseSign::
	lockall
	checkplayergender
	call_if_eq VAR_RESULT, MALE, BoreaGlade_EventScript_BirchsHouseSignMale
	call_if_eq VAR_RESULT, FEMALE, BoreaGlade_EventScript_PlayersHouseSignFemale
	releaseall
	end

BoreaGlade_EventScript_BirchsHouseSignMale::
	msgbox BoreaGlade_Text_ProfBirchsHouse, MSGBOX_DEFAULT
	return

BoreaGlade_EventScript_PlayersHouseSignFemale::
	msgbox BoreaGlade_Text_PlayersHouse, MSGBOX_DEFAULT
	return

BoreaGlade_EventScript_GiveRunningShoesTrigger0::
	lockall
	setvar VAR_0x8008, 0
	setobjectxy LOCALID_MOM, 10, 9
	goto BoreaGlade_EventScript_GiveRunningShoesTrigger
	end

BoreaGlade_EventScript_GiveRunningShoesTrigger1::
	lockall
	setvar VAR_0x8008, 1
	setobjectxy LOCALID_MOM, 11, 9
	goto BoreaGlade_EventScript_GiveRunningShoesTrigger
	end

BoreaGlade_EventScript_GiveRunningShoesTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto BoreaGlade_EventScript_GiveRunningShoesTrigger
	end

BoreaGlade_EventScript_GiveRunningShoesTrigger3::
	lockall
	setvar VAR_0x8008, 3
	goto BoreaGlade_EventScript_GiveRunningShoesTrigger
	end

BoreaGlade_EventScript_GiveRunningShoesTrigger4::
	lockall
	setvar VAR_0x8008, 4
	goto BoreaGlade_EventScript_GiveRunningShoesTrigger
	end

BoreaGlade_EventScript_GiveRunningShoesTrigger5::
	lockall
	setvar VAR_0x8008, 5
	goto BoreaGlade_EventScript_GiveRunningShoesTrigger
	end

BoreaGlade_EventScript_GiveRunningShoesTrigger::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, BoreaGlade_EventScript_MomNoticePlayerMale
	call_if_eq VAR_RESULT, FEMALE, BoreaGlade_EventScript_MomNoticePlayerFemale
	checkplayergender
	call_if_eq VAR_RESULT, MALE, BoreaGlade_EventScript_SetHomeDoorCoordsMale
	call_if_eq VAR_RESULT, FEMALE, BoreaGlade_EventScript_SetHomeDoorCoordsFemale
	msgbox BoreaGlade_Text_WaitPlayer, MSGBOX_DEFAULT
	closemessage
	checkplayergender
	call_if_eq VAR_RESULT, MALE, BoreaGlade_EventScript_MomApproachPlayerMale
	call_if_eq VAR_RESULT, FEMALE, BoreaGlade_EventScript_MomApproachPlayerFemale
	call BoreaGlade_EventScript_GiveRunningShoes
	checkplayergender
	call_if_eq VAR_RESULT, MALE, BoreaGlade_EventScript_MomReturnHomeMale
	call_if_eq VAR_RESULT, FEMALE, BoreaGlade_EventScript_MomReturnHomeFemale
	goto BoreaGlade_EventScript_SetReceivedRunningShoes
	end

BoreaGlade_EventScript_SetHomeDoorCoordsMale::
	setvar VAR_0x8009, 5
	setvar VAR_0x800A, 8
	return

BoreaGlade_EventScript_SetHomeDoorCoordsFemale::
	setvar VAR_0x8009, 14
	setvar VAR_0x800A, 8
	return

BoreaGlade_EventScript_MomNoticePlayerMale::
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

BoreaGlade_EventScript_MomNoticePlayerFemale::
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

BoreaGlade_EventScript_MomApproachPlayerMale::
	call_if_eq VAR_0x8008, 0, BoreaGlade_EventScript_MomApproachPlayer0
	call_if_eq VAR_0x8008, 1, BoreaGlade_EventScript_MomApproachPlayer1
	call_if_eq VAR_0x8008, 2, BoreaGlade_EventScript_MomApproachPlayerMale2
	call_if_eq VAR_0x8008, 3, BoreaGlade_EventScript_MomApproachPlayerMale3
	call_if_eq VAR_0x8008, 4, BoreaGlade_EventScript_MomApproachPlayerMale4
	call_if_eq VAR_0x8008, 5, BoreaGlade_EventScript_MomApproachPlayerMale5
	return

BoreaGlade_EventScript_MomApproachPlayerFemale::
	call_if_eq VAR_0x8008, 0, BoreaGlade_EventScript_MomApproachPlayer0
	call_if_eq VAR_0x8008, 1, BoreaGlade_EventScript_MomApproachPlayer1
	call_if_eq VAR_0x8008, 2, BoreaGlade_EventScript_MomApproachPlayerFemale2
	call_if_eq VAR_0x8008, 3, BoreaGlade_EventScript_MomApproachPlayerFemale3
	call_if_eq VAR_0x8008, 4, BoreaGlade_EventScript_MomApproachPlayerFemale4
	call_if_eq VAR_0x8008, 5, BoreaGlade_EventScript_MomApproachPlayerFemale5
	return

BoreaGlade_EventScript_MomApproachPlayer0::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_MOM, BoreaGlade_Movement_MomApproachPlayer0
	waitmovement 0
	return

BoreaGlade_EventScript_MomApproachPlayer1::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_MOM, BoreaGlade_Movement_MomApproachPlayer1
	waitmovement 0
	return

BoreaGlade_EventScript_MomApproachPlayerMale2::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_MOM, BoreaGlade_Movement_MomApproachPlayerMale2
	waitmovement 0
	return

BoreaGlade_EventScript_MomApproachPlayerMale3::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_MOM, BoreaGlade_Movement_MomApproachPlayerMale3
	waitmovement 0
	return

BoreaGlade_EventScript_MomApproachPlayerMale4::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_MOM, BoreaGlade_Movement_MomApproachPlayerMale4
	waitmovement 0
	return

BoreaGlade_EventScript_MomApproachPlayerMale5::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_MOM, BoreaGlade_Movement_MomApproachPlayerMale5
	waitmovement 0
	return

BoreaGlade_EventScript_MomApproachPlayerFemale2::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement LOCALID_MOM, BoreaGlade_Movement_MomApproachPlayerFemale2
	waitmovement 0
	return

BoreaGlade_EventScript_MomApproachPlayerFemale3::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement LOCALID_MOM, BoreaGlade_Movement_MomApproachPlayerFemale3
	waitmovement 0
	return

BoreaGlade_EventScript_MomApproachPlayerFemale4::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement LOCALID_MOM, BoreaGlade_Movement_MomApproachPlayerFemale4
	waitmovement 0
	return

BoreaGlade_EventScript_MomApproachPlayerFemale5::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement LOCALID_MOM, BoreaGlade_Movement_MomApproachPlayerFemale5
	waitmovement 0
	return

BoreaGlade_EventScript_MomReturnHomeMale::
	call_if_eq VAR_0x8008, 0, BoreaGlade_EventScript_MomReturnHome0
	call_if_eq VAR_0x8008, 1, BoreaGlade_EventScript_MomReturnHome1
	call_if_eq VAR_0x8008, 2, BoreaGlade_EventScript_MomReturnHomeMale2
	call_if_eq VAR_0x8008, 3, BoreaGlade_EventScript_MomReturnHomeMale3
	call_if_eq VAR_0x8008, 4, BoreaGlade_EventScript_MomReturnHomeMale4
	call_if_eq VAR_0x8008, 5, BoreaGlade_EventScript_MomReturnHomeMale5
	return

BoreaGlade_EventScript_MomReturnHomeFemale::
	call_if_eq VAR_0x8008, 0, BoreaGlade_EventScript_MomReturnHome0
	call_if_eq VAR_0x8008, 1, BoreaGlade_EventScript_MomReturnHome1
	call_if_eq VAR_0x8008, 2, BoreaGlade_EventScript_MomReturnHomeFemale2
	call_if_eq VAR_0x8008, 3, BoreaGlade_EventScript_MomReturnHomeFemale3
	call_if_eq VAR_0x8008, 4, BoreaGlade_EventScript_MomReturnHomeFemale4
	call_if_eq VAR_0x8008, 5, BoreaGlade_EventScript_MomReturnHomeFemale5
	return

BoreaGlade_EventScript_MomReturnHome0::
	applymovement LOCALID_MOM, BoreaGlade_Movement_MomReturnHome0
	waitmovement 0
	return

BoreaGlade_EventScript_MomReturnHome1::
	applymovement LOCALID_MOM, BoreaGlade_Movement_MomReturnHome1
	waitmovement 0
	return

BoreaGlade_EventScript_MomReturnHomeMale2::
	applymovement LOCALID_MOM, BoreaGlade_Movement_MomReturnHomeMale2
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement LOCALID_MOM, BoreaGlade_Movement_MomExitThroughDoor
	waitmovement 0
	hideobjectat LOCALID_MOM, MAP_BOREA_GLADE
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

BoreaGlade_EventScript_MomReturnHomeMale3::
	applymovement LOCALID_MOM, BoreaGlade_Movement_MomReturnHomeMale3
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement LOCALID_MOM, BoreaGlade_Movement_MomExitThroughDoor
	waitmovement 0
	hideobjectat LOCALID_MOM, MAP_BOREA_GLADE
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

BoreaGlade_EventScript_MomReturnHomeMale4::
	applymovement LOCALID_MOM, BoreaGlade_Movement_MomReturnHomeMale4
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement LOCALID_MOM, BoreaGlade_Movement_MomExitThroughDoor
	waitmovement 0
	hideobjectat LOCALID_MOM, MAP_BOREA_GLADE
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

BoreaGlade_EventScript_MomReturnHomeMale5::
	applymovement LOCALID_MOM, BoreaGlade_Movement_MomReturnHomeMale5
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement LOCALID_MOM, BoreaGlade_Movement_MomExitThroughDoor
	waitmovement 0
	hideobjectat LOCALID_MOM, MAP_BOREA_GLADE
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

BoreaGlade_EventScript_MomReturnHomeFemale2::
	applymovement LOCALID_MOM, BoreaGlade_Movement_MomReturnHomeFemale2
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement LOCALID_MOM, BoreaGlade_Movement_MomExitThroughDoor
	waitmovement 0
	hideobjectat LOCALID_MOM, MAP_BOREA_GLADE
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

BoreaGlade_EventScript_MomReturnHomeFemale3::
	applymovement LOCALID_MOM, BoreaGlade_Movement_MomReturnHomeFemale3
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement LOCALID_MOM, BoreaGlade_Movement_MomExitThroughDoor
	waitmovement 0
	hideobjectat LOCALID_MOM, MAP_BOREA_GLADE
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

BoreaGlade_EventScript_MomReturnHomeFemale4::
	applymovement LOCALID_MOM, BoreaGlade_Movement_MomReturnHomeFemale4
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement LOCALID_MOM, BoreaGlade_Movement_MomExitThroughDoor
	waitmovement 0
	hideobjectat LOCALID_MOM, MAP_BOREA_GLADE
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

BoreaGlade_EventScript_MomReturnHomeFemale5::
	applymovement LOCALID_MOM, BoreaGlade_Movement_MomReturnHomeFemale5
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement LOCALID_MOM, BoreaGlade_Movement_MomExitThroughDoor
	waitmovement 0
	hideobjectat LOCALID_MOM, MAP_BOREA_GLADE
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

BoreaGlade_Movement_MomApproachPlayer0:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BoreaGlade_Movement_MomApproachPlayer1:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BoreaGlade_Movement_MomApproachPlayerMale2:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

BoreaGlade_Movement_MomApproachPlayerMale3:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

BoreaGlade_Movement_MomApproachPlayerMale4:
	walk_right
	walk_right
	step_end

BoreaGlade_Movement_MomApproachPlayerMale5:
	walk_right
	walk_right
	walk_right
	step_end

BoreaGlade_Movement_MomApproachPlayerFemale2:
	walk_left
	walk_left
	walk_left
	step_end

BoreaGlade_Movement_MomApproachPlayerFemale3:
	walk_left
	walk_left
	step_end

BoreaGlade_Movement_MomApproachPlayerFemale4:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

BoreaGlade_Movement_MomApproachPlayerFemale5:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

BoreaGlade_Movement_MomReturnHome0:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

BoreaGlade_Movement_MomReturnHome1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

BoreaGlade_Movement_MomReturnHomeMale2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

BoreaGlade_Movement_MomReturnHomeMale3:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

BoreaGlade_Movement_MomReturnHomeMale4:
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

BoreaGlade_Movement_MomReturnHomeMale5:
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

BoreaGlade_Movement_MomReturnHomeFemale2:
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

BoreaGlade_Movement_MomReturnHomeFemale3:
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

BoreaGlade_Movement_MomReturnHomeFemale4:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

BoreaGlade_Movement_MomReturnHomeFemale5:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

BoreaGlade_Movement_MomExitThroughDoor:
	walk_up
	step_end

BoreaGlade_EventScript_Mom::
	lock
	faceplayer
	checkplayergender
	call_if_eq VAR_RESULT, MALE, BoreaGlade_EventScript_SetHomeDoorCoordsMale
	call_if_eq VAR_RESULT, FEMALE, BoreaGlade_EventScript_SetHomeDoorCoordsFemale
	call BoreaGlade_EventScript_GiveRunningShoes
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement LOCALID_MOM, BoreaGlade_Movement_MomExitThroughDoor
	waitmovement 0
	hideobjectat LOCALID_MOM, MAP_BOREA_GLADE
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	goto BoreaGlade_EventScript_SetReceivedRunningShoes
	end

BoreaGlade_EventScript_SetReceivedRunningShoes::
	removeobject LOCALID_MOM
	setflag FLAG_SYS_B_DASH
	setvar VAR_BOREA_GLADE_STATE, 4
	completesubquest ADVENTURE_BEGINS, DAD_CATCH_UP
	release
	end

BoreaGlade_Text_OurNewHomeLetsGoInside:
	.string "MOM: {PLAYER}, we're here, honey!\p"
	.string "It must be tiring riding with our things\n"
	.string "in the moving truck.\p"
	.string "Well, this is BOREA GLADE.\p"
	.string "How do you like it?\n"
	.string "This is our new home!\p"
	.string "It has a quaint feel, but it seems to be\n"
	.string "an easy place to live, don't you think?\p"
	.string "And, you get your own room, {PLAYER}!\n"
	.string "Let's go inside.$"

BoreaGlade_Text_WaitPlayer:
	.string "MOM: Wait, {PLAYER}!$"

BoreaGlade_Text_WearTheseRunningShoes:
	.string "MOM: {PLAYER}! {PLAYER}! Did you\n"
	.string "introduce yourself to PROF. IGNATIUS?\l"
	.string "… … … … … … … … … … …\p"
	.string "What an adorable POKéMON you have.\n"
	.string "… … … … … … … … … … …\p"
	.string "It was a present from PROF. IGNATIUS?\n" 
	.string "Oh that is so kind!\p"
	.string "You're your father's child, all right.\n"
	.string "You look good together with POKéMON!\p"
	.string "Here, honey! If you're going out on an\n"
	.string "adventure, wear these RUNNING SHOES.\p"
	.string "They'll put a zip in your step!$"

BoreaGlade_Text_WearTheseRunningShoes_Selenic:
	.string "MOM: {PLAYER}! {PLAYER}! Did you\n"
	.string "introduce yourself to PROF. IGNATIUS?\l"
	.string "… … … … … … … … … … …\p"
	.string "Oh! And you went to SELENIC too!\n"
	.string "What an adorable POKéMON you have.\l"
	.string "… … … … … … … … … … …\p"
	.string "It was a present from PROF. IGNATIUS?\n" 
	.string "Oh that is so kind!\p"
	.string "You're your father's child, all right.\n"
	.string "You look good together with POKéMON!\p"
	.string "Here, honey! If you're going out on an\n"
	.string "adventure, wear these RUNNING SHOES.\p"
	.string "They'll put a zip in your step!$"

BoreaGlade_Text_SwitchShoesWithRunningShoes:
	.string "{PLAYER} switched shoes with the\n"
	.string "RUNNING SHOES.$"

BoreaGlade_Text_ExplainRunningShoes:
	.string "MOM: {PLAYER}, those shoes came with\n"
	.string "instructions.\p"
	.string "“Hold the B Button while wearing these\n"
	.string "RUNNING SHOES to run extra-fast!\l"
	.string "Press the R Button to toggle Auto-Run”\p"
	.string "So slip on these RUNNING SHOES and go\n"
	.string "and race in the great outdoors!$"

BoreaGlade_Text_ComeHomeIfAnythingHappens:
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "To think that you have your very own\n"
	.string "POKéMON now…\l"
	.string "Your father will be overjoyed.\p" 
	.string "You should surprise him with a visit,\n"
	.string "I'm sure he'd love that!\l"
	.string "You can even bring him his INFERNAPE.\p"
	.string "…But please be careful. If anything,\n"
	.string "happens, wherever you are,\l"
	.string "you can come home.\p"
	.string "Ride on a SWELLOW using a FLYING TAXI\n"
	.string "from the inside of a POKéMON CENTRE.\l"
	.string "Don't worry about me, {PLAYER}…\p"
	.string "I'll have DIANCIE and ESPURR to keep\n"
	.string "me company, just don't forget us!\l"
	.string "Go on! Go get them, honey!$"
	
BoreaGlade_Text_CanUsePCToStoreItems:
	.string "If you use a PC, you can store items\n"
	.string "and POKéMON.\p"
	.string "The power of science is staggering!$"

BoreaGlade_Text_BirchSpendsDaysInLab:
	.string "PROF. IGNATIUS spends days in his LAB\n"
	.string "studying, then he'll suddenly go out in\l"
	.string "the wild to do more research…\p"
	.string "When does PROF. IGNATIUS spend time\n"
	.string "at home?$"

BoreaGlade_Text_IfYouGoInGrassPokemonWillJumpOut:
	.string "Um, um, um!\p"
	.string "If you go outside and go in the grass,\n"
	.string "wild POKéMON will jump out!$"

BoreaGlade_Text_DangerousIfYouDontHavePokemon:
	.string "It's dangerous if you don't have\n"
	.string "your own POKéMON.$"

BoreaGlade_Text_CanYouGoSeeWhatsHappening:
	.string "Um, hi!\p"
	.string "There are scary POKéMON outside!\n"
	.string "I can hear their cries!\p"
	.string "I want to go see what's going on,\n"
	.string "but I don't have any POKéMON…\p"
	.string "Can you go see what's happening\n"
	.string "for me?$"

BoreaGlade_Text_YouSavedBirch:
	.string "You saved PROF. IGNATIUS!\n"
	.string "I'm so glad!$"

BoreaGlade_Text_GoodLuckCatchingPokemon:
	.string "Are you going to catch POKéMON?\n"
	.string "Good luck!$"

BoreaGlade_Text_TownSign:
	.string "BOREA GLADE\n"
	.string "“A town that can't be shaded any hue.”$"

BoreaGlade_Text_ProfBirchsLab:
	.string "PROF. IGNATIUS' POKéMON LAB$"

BoreaGlade_Text_PlayersHouse:
	.string "LAUREN, SAMUEL &\n"
	.string "{PLAYER}'s HOUSE$"

BoreaGlade_Text_ProfBirchsHouse:
	.string "PROF. IGNATIUS' &\n"
	.string "{RIVAL}'s HOUSE$"

BoreaGlade_Text_BirchSomethingToShowYouAtLab:
	.string "PROF. IGNATIUS: Well, well, {PLAYER}{KUN}!\n"
	.string "That was good work out there!\p"
	.string "I knew there was something special\n"
	.string "about you when I first saw you,\l"
	.string "but I never expected this.\p"
	.string "I have something to show you.\n"
	.string "Let's go to my LAB.$"

BoreaGlade_EventScript_ScottAboardSSTidalCall::
	lockall
	pokenavcall BoreaGlade_Text_ScottAboardSSTidalCall
	waitmessage
	clearflag FLAG_SCOTT_CALL_BATTLE_FRONTIER
	releaseall
	end

BoreaGlade_Text_ScottAboardSSTidalCall:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "SCOTT: Hi, hi, {PLAYER}!\n"
	.string "It's me, SCOTT.\p"
	.string "I'm aboard the S.S. TIDAL now.\n"
	.string "It feels great to be on the sea!\p"
	.string "By the way…\p"
	.string "There's this place that I'd like to\n"
	.string "invite you to for a visit.\p"
	.string "If you're interested, board a ferry\n"
	.string "at either SLATEPORT or LILYCOVE.\p"
	.string "I'll fill you in on the details when\n"
	.string "we meet. I'll be waiting!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

BoreaGlade_EventScript_Selenic_Absol::
	checkitem ITEM_LAB_ORB, 1
	compare VAR_RESULT, FALSE
	goto_if_eq BoreaGlade_EventScript_Selenic_Absol_3
BoreaGlade_EventScript_Selenic_Absol_2:
	goto LabLights_AbsolCry
	return

BoreaGlade_EventScript_Selenic_Absol_1:
	lock
	delay 20
	call PlayerReturnToLastPosition
	msgbox BoreaGlade_EventScript_Selenic_Absol_Text_0, MSGBOX_DEFAULT
	closemessage
	release
	return

BoreaGlade_EventScript_Selenic_Absol_3:
	goto_if_unset FLAG_SYS_DEMO_MODE, BoreaGlade_EventScript_Selenic_Absol_1
	goto BoreaGlade_EventScript_Selenic_Absol_2


BoreaGlade_EventScript_SelenicSign::
	msgbox BoreaGlade_EventScript_SelenicSign_Text_0, MSGBOX_SIGN
	end


BoreaGlade_EventScript_OldLady::
	lock
	faceplayer
	msgbox BoreaGlade_EventScript_OldLady_Text_0, MSGBOX_DEFAULT
	closemessage
	questmenu QUEST_MENU_CHECK_UNLOCKED, LAB_LIGHTS
	compare VAR_RESULT, FALSE
	goto_if_eq BoreaGlade_EventScript_OldLady_3
BoreaGlade_EventScript_OldLady_1:
	release
	end

BoreaGlade_EventScript_OldLady_2:
	startquest LAB_LIGHTS
	goto BoreaGlade_EventScript_OldLady_1

BoreaGlade_EventScript_OldLady_3:
	goto_if_unset FLAG_SYS_DEMO_MODE, BoreaGlade_EventScript_OldLady_2
	goto BoreaGlade_EventScript_OldLady_1


BoreaGlade_EventScript_RichBoy::
	msgbox BoreaGlade_EventScript_RichBoy_Text_0, MSGBOX_NPC
	return


BoreaGlade_EventScript_LitleBoy::
	msgbox BoreaGlade_EventScript_LitleBoy_Text_0, MSGBOX_NPC
	return


BoreaGlade_EventScript_RayquazaStatue::
	lock
	msgbox BoreaGlade_EventScript_RayquazaStatue_Text_0, MSGBOX_NPC
	questmenu QUEST_MENU_CHECK_UNLOCKED, LAB_LIGHTS
	compare VAR_RESULT, FALSE
	goto_if_eq BoreaGlade_EventScript_RayquazaStatue_3
BoreaGlade_EventScript_RayquazaStatue_1:
	release
	end

BoreaGlade_EventScript_RayquazaStatue_2:
	startquest LAB_LIGHTS
	goto BoreaGlade_EventScript_RayquazaStatue_1

BoreaGlade_EventScript_RayquazaStatue_3:
	goto_if_unset FLAG_SYS_DEMO_MODE, BoreaGlade_EventScript_RayquazaStatue_2
	goto BoreaGlade_EventScript_RayquazaStatue_1


BoreaGlade_EventScript_BoreaPassageSign::
	msgbox BoreaGlade_EventScript_BoreaPassageSign_Text_0, MSGBOX_SIGN
	return


BoreaGladeBerryTree::
	questmenu QUEST_MENU_CHECK_COMPLETE, FATHERS_REST
	compare VAR_RESULT, FALSE
	goto_if_eq BoreaGladeBerryTree_1
	goto BerryTreeScript
	return

BoreaGladeBerryTree_1:
	msgbox BoreaGladeBerryTree_Text_0, MSGBOX_SIGN
	return


BoreaGlade_EventScript_GiveRunningShoes::
	goto_if_set FLAG_SYS_DEMO_MODE, BoreaGlade_EventScript_GiveRunningShoes_2
	msgbox BoreaGlade_Text_WearTheseRunningShoes_Selenic, MSGBOX_DEFAULT
BoreaGlade_EventScript_GiveRunningShoes_1:
	playfanfare MUS_OBTAIN_ITEM
	message BoreaGlade_Text_SwitchShoesWithRunningShoes
	waitfanfare
	setflag FLAG_RECEIVED_RUNNING_SHOES
	msgbox BoreaGlade_Text_ExplainRunningShoes, MSGBOX_DEFAULT
	msgbox BoreaGlade_Text_ComeHomeIfAnythingHappens, MSGBOX_DEFAULT
	closemessage
	setvar VAR_FLYING_TAXI, 1
	clearflag FLAG_DISALLOW_FLYING_TAXI
	delay 30
	return

BoreaGlade_EventScript_GiveRunningShoes_2:
	msgbox BoreaGlade_Text_WearTheseRunningShoes, MSGBOX_DEFAULT
	goto BoreaGlade_EventScript_GiveRunningShoes_1


BoreaGlade_LockPlayerDoor::
	addvar VAR_TEMP_0, 1
	goto_if_unset FLAG_HIDE_OLDALE_FAMILY, BoreaGlade_LockPlayerDoor_1
	goto_if_unset FLAG_HIDE_ROUTE103MT_FAMILY, BoreaGlade_LockPlayerDoor_1
	goto_if_unset FLAG_HIDE_PETALBURG_FAMILY, BoreaGlade_LockPlayerDoor_1
	return

BoreaGlade_LockPlayerDoor_1:
	setmetatile 5, 8, METATILE_Petalburg_Door_Littleroot_Locked, TRUE
	setmetatile 14, 8, METATILE_Petalburg_Door_Littleroot_Locked, TRUE
	setmetatile 7, 16, METATILE_Petalburg_Door_BirchsLab_Locked, TRUE
	return


BoreaGlade_EventScript_Selenic_Absol_Text_0:
	.string "I should check on the parcel PROFESSOR\n"
	.string "IGNATIUS delivered,\l"
	.string "I'll head to SELENIC SPIRIT now.$"

BoreaGlade_EventScript_SelenicSign_Text_0:
	.string "SELENIC SPIRIT\p"
	.string "We stock the finest crystals and\n"
	.string "gemstones in all of HOENN!$"

BoreaGlade_EventScript_OldLady_Text_0:
	.string "Oh, my dear, let me tell you about this\n"
	.string "sculpture my father crafted.\l"
	.string "It represents our protector, you see.\p"
	.string "It's carved into the LABRADORITE below\n"
	.string "our very feet.\p"
	.string "And those enchanting colors trapped\n"
	.string "within, shine like the Northern Lights.$"

BoreaGlade_EventScript_RichBoy_Text_0:
	.string "I'm checking out this new gemstone and\n"
	.string "crystal store while I visit my grandma.\p"
	.string "She really loves the sculpture her\n"
	.string "father built when she was a child.$"

BoreaGlade_EventScript_LitleBoy_Text_0:
	.string "I was looking for a POKéMON to play with\n"
	.string "but there aren't any in BOREA GLADE.\l"
	.string "It's so annoying!$"

BoreaGlade_EventScript_RayquazaStatue_Text_0:
	.string "An old carving with an inscription.\p"
	.string "“The sculpture that cradles the AURORA\n"
	.string "BOREALIS within its very essence.”$"

BoreaGlade_EventScript_BoreaPassageSign_Text_0:
	.string "BOREA PASSAGE\p"
	.string "The LABRADORITE tunnels that connect\n"
	.string "BOREA GLADE to PETALBURG CITY.$"

BoreaGladeBerryTree_Text_0:
	.string "I'm unsure whether or not to pick\n"
	.string "these BERRIES.\l"
	.string "I better leave them for now!$"
