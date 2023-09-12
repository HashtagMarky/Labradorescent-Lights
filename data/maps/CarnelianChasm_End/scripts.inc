.set LOCALID_GROUDON, 1

CarnelianChasm_End_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, CarnelianChasm_End_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, CarnelianChasm_End_OnTransition
	.byte 0

CarnelianChasm_End_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, CarnelianChasm_End_EventScript_TryRemoveGroudon
	end

CarnelianChasm_End_EventScript_TryRemoveGroudon::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_GROUDON
	return

CarnelianChasm_End_OnTransition:
	call_if_unset FLAG_DEFEATED_GROUDON, CarnelianChasm_End_EventScript_ShowGroudon
	end

CarnelianChasm_End_EventScript_ShowGroudon::
	clearflag FLAG_HIDE_CARNELIAN_CHASM_GROUDON
	setvar VAR_TEMP_1, 1
	return

CarnelianChasm_End_EventScript_Groudon::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_GROUDON, CarnelianChasm_End_Movement_GroudonApproach
	waitmovement 0
	waitse
	playmoncry SPECIES_GROUDON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_GROUDON
	setwildbattle SPECIES_GROUDON, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_TEMP_1, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CarnelianChasm_End_EventScript_DefeatedGroudon
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CarnelianChasm_End_EventScript_RanFromGroudon
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CarnelianChasm_End_EventScript_RanFromGroudon
	setvar VAR_SHOULD_END_ABNORMAL_WEATHER, 1
	setflag FLAG_DEFEATED_GROUDON
	releaseall
	end

CarnelianChasm_End_EventScript_DefeatedGroudon::
	setvar VAR_SHOULD_END_ABNORMAL_WEATHER, 1
	setflag FLAG_DEFEATED_GROUDON
	goto Common_EventScript_RemoveStaticPokemon
	end

CarnelianChasm_End_EventScript_RanFromGroudon::
	setvar VAR_0x8004, SPECIES_GROUDON
	goto Common_EventScript_LegendaryFlewAway
	end

CarnelianChasm_End_Movement_GroudonApproach:
	init_affine_anim
	walk_down_start_affine
	delay_16
	delay_16
	walk_down_affine
	delay_16
	delay_16
	walk_down_affine
	step_end
