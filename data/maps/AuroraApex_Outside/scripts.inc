.set LOCALID_WALLACE, 1

AuroraApex_Outside_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AuroraApex_Outside_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, AuroraApex_Outside_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AuroraApex_Outside_OnFrame
	.byte 0

AuroraApex_Outside_OnTransition:
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 3, AuroraApex_Outside_EventScript_HideMapNamePopup
	call_if_ge VAR_SOOTOPOLIS_CITY_STATE, 4, AuroraApex_Outside_EventScript_CheckSetAbnormalWeather
	end

AuroraApex_Outside_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

AuroraApex_Outside_EventScript_CheckSetAbnormalWeather::
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	return

AuroraApex_Outside_OnLoad:
	call_if_set FLAG_WALLACE_GOES_TO_AURORA_APEX, AuroraApex_Outside_EventScript_OpenDoor
	end

AuroraApex_Outside_EventScript_OpenDoor::
	setmetatile 14, 4, METATILE_Pacifidlog_AuroraApex_DoorOpen_Top, FALSE
	setmetatile 14, 5, METATILE_Pacifidlog_AuroraApex_DoorOpen_Bottom, FALSE
	return

AuroraApex_Outside_OnFrame:
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 3, AuroraApex_Outside_EventScript_WallaceScene
	.2byte 0

AuroraApex_Outside_EventScript_WallaceScene::
	lockall
	applymovement LOCALID_WALLACE, AuroraApex_Outside_Movement_WallaceApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox AuroraApex_Outside_Text_OpenedDoorToAuroraApex, MSGBOX_DEFAULT
	closemessage
	delay 30
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
	delay 40
	msgbox AuroraApex_Outside_Text_EarthquakeNotMomentToWaste, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, AuroraApex_Outside_Movement_PlayerClimbAuroraApex
	applymovement LOCALID_WALLACE, AuroraApex_Outside_Movement_WallaceClimbAuroraApex
	waitmovement 0
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 3   @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 5   @ shake delay
	special ShakeCamera
	waitstate
	delay 20
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 10
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 20
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	msgbox AuroraApex_Outside_Text_SituationGettingWorse, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SYS_WEATHER_CTRL
	setweather WEATHER_ABNORMAL
	doweather
	special WaitWeather
	waitstate
	delay 30
	msgbox AuroraApex_Outside_Text_GotToGoBackForSootopolis, MSGBOX_DEFAULT
	closemessage
	playse SE_EXIT
	fadescreenswapbuffers FADE_TO_BLACK
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_SOOTOPOLIS_CITY_STATE, 4
	removeobject LOCALID_WALLACE
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	fadescreenswapbuffers FADE_FROM_BLACK
	releaseall
	end

AuroraApex_Outside_Movement_WallaceApproachPlayer:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

AuroraApex_Outside_Movement_WallaceClimbAuroraApex:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

AuroraApex_Outside_Movement_PlayerClimbAuroraApex:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

AuroraApex_Outside_EventScript_Wallace::
	end

AuroraApex_Outside_EventScript_ClosedDoor::
	msgbox AuroraApex_Outside_Text_DoorIsClosed, MSGBOX_SIGN
	end

AuroraApex_Outside_Text_DoorIsClosed:
	.string "The door is closed.$"

AuroraApex_Outside_Text_OpenedDoorToAuroraApex:
	.string "WALLACE: Oh, my, I'm terribly sorry!\p"
	.string "In my haste, I didn't notice that\n"
	.string "I'd left you behind!\p"
	.string "I've opened the locked door of\n"
	.string "the AURORA APEX.\p"
	.string "{PLAYER}{KUN}, let's be on our way!$"

AuroraApex_Outside_Text_EarthquakeNotMomentToWaste:
	.string "WALLACE: It's an earthquake!\p"
	.string "There's not a moment to waste!\n"
	.string "We've got to hurry!$"

AuroraApex_Outside_Text_SituationGettingWorse:
	.string "WALLACE: Hmm…\n"
	.string "The situation is getting worse…$"

AuroraApex_Outside_Text_GotToGoBackForSootopolis:
	.string "WALLACE: This isn't good…\p"
	.string "The weather distortion is spreading\n"
	.string "even here…\p"
	.string "{PLAYER}{KUN}.\p"
	.string "RAYQUAZA should be farther up\n"
	.string "from here.\p"
	.string "I'm worried about SOOTOPOLIS.\n"
	.string "I've got to go back.\p"
	.string "Everything is in your hands now.\n"
	.string "Don't fail us!$"
