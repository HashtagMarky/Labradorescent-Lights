.set LOCALID_RAYQUAZA_SLEEPING, 1

AuroraApex_Top_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AuroraApex_Top_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, AuroraApex_Top_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, AuroraApex_Top_OnWarp
	.byte 0

AuroraApex_Top_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AuroraApex_Top_EventScript_TryRemoveRayquaza
	end

AuroraApex_Top_EventScript_TryRemoveRayquaza::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

AuroraApex_Top_OnTransition:
	call AuroraApex_Top_EventScript_SetCleanLayout
	call_if_ge VAR_AURORA_APEX_STATE, 2, AuroraApex_Top_EventScript_TryShowRayquaza
	end

AuroraApex_Top_EventScript_SetCleanLayout::
	setmaplayoutindex LAYOUT_AURORA_APEX_TOP_CLEAN
	setobjectmovementtype LOCALID_RAYQUAZA_SLEEPING, MOVEMENT_TYPE_FACE_DOWN
	return

AuroraApex_Top_EventScript_TryShowRayquaza::
	call_if_unset FLAG_DEFEATED_RAYQUAZA, AuroraApex_Top_EventScript_ShowRayquaza
	return

AuroraApex_Top_EventScript_ShowRayquaza::
	clearflag FLAG_HIDE_AURORA_APEX_TOP_RAYQUAZA_STILL
	return

AuroraApex_Top_OnWarp:
	map_script_2 VAR_AURORA_APEX_STATE, 0, AuroraApex_Top_EventScript_RayquazaFaceDown
	.2byte 0

AuroraApex_Top_EventScript_RayquazaFaceDown::
	turnobject LOCALID_RAYQUAZA_SLEEPING, DIR_SOUTH
	end

AuroraApex_Top_EventScript_Rayquaza::
	lockall
	waitse
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SHINY_CREATION
	setwildbattle SPECIES_RAYQUAZA, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	clearflag FLAG_SHINY_CREATION
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AuroraApex_Top_EventScript_DefeatedRayquaza
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AuroraApex_Top_EventScript_RanFromRayquaza
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AuroraApex_Top_EventScript_RanFromRayquaza
	setflag FLAG_DEFEATED_RAYQUAZA
	releaseall
	end

AuroraApex_Top_EventScript_DefeatedRayquaza::
	setflag FLAG_DEFEATED_RAYQUAZA
	goto AuroraApex_Top_EventScript_DefeatedRayquaza2
	end

AuroraApex_Top_EventScript_RanFromRayquaza::
	setvar VAR_0x8004, SPECIES_RAYQUAZA
	goto AuroraApex_Top_EventScript_RanFromRayquaza2
	end

AuroraApex_Top_EventScript_DefeatedRayquaza2::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	releaseall
	end

AuroraApex_Top_EventScript_RanFromRayquaza2::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	bufferspeciesname STR_VAR_1, VAR_0x8004
	msgbox gText_LegendaryFlewAway, MSGBOX_DEFAULT
	releaseall
	end

AuroraApex_Top_EventScript_AwakenRayquaza::
	lockall
	fadeoutbgm 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, AuroraApex_Top_Movement_CameraPanUp
	waitmovement 0
	special RemoveCameraObject
	applymovement LOCALID_RAYQUAZA_SLEEPING, AuroraApex_Top_Movement_RayquazaStir
	waitmovement 0
	waitse
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
	waitse
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	waitmoncry
	applymovement LOCALID_RAYQUAZA_SLEEPING, AuroraApex_Top_Movement_RayquazaFlyOff
	waitmovement 0
	removeobject LOCALID_RAYQUAZA_SLEEPING
	msgbox AuroraApex_Top_Text_RayquazaFlewOff, MSGBOX_DEFAULT
	closemessage
	delay 20
	fadeinbgm 1
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, AuroraApex_Top_Movement_CameraPanDown
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_SOOTOPOLIS_CITY_STATE, 5
	setvar VAR_AURORA_APEX_STATE, 1
	setvar VAR_AURORA_APEX_RAQUAZA_CRY_DONE, 1
	releaseall
	end

@ Rayquaza has unusual movement frames
@ See comments, or sAnimTable_Rayquaza
AuroraApex_Top_Movement_RayquazaStir:
	delay_16
	walk_in_place_fast_left  @ Coiled, awake
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_left  @ Coiled, mouth open
	delay_16
	walk_in_place_right  @ Normal, awake
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

AuroraApex_Top_Movement_RayquazaFlyOff:
	delay_16
	walk_in_place_down  @ Coiled, asleep
	delay_8
	walk_in_place_right  @ Normal, awake
	delay_8
	walk_faster_up  @ Fly up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	step_end

AuroraApex_Top_Movement_CameraPanUp:
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end

AuroraApex_Top_Movement_CameraPanDown:
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end

AuroraApex_Top_Text_RayquazaFlewOff:
	.string "The awakened RAYQUAZA flew off…$"
