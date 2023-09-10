.set LOCALID_KYOGRE, 1

Aquamarineabyss_End_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Aquamarineabyss_End_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Aquamarineabyss_End_OnTransition
	.byte 0

Aquamarineabyss_End_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Aquamarineabyss_End_EventScript_TryRemoveKyogre
	end

Aquamarineabyss_End_EventScript_TryRemoveKyogre::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_KYOGRE
	return

Aquamarineabyss_End_OnTransition:
	call_if_unset FLAG_DEFEATED_KYOGRE, Aquamarineabyss_End_EventScript_ShowKyogre
	end

Aquamarineabyss_End_EventScript_ShowKyogre::
	clearflag FLAG_HIDE_AQUAMARINE_ABYSS_KYOGRE
	setvar VAR_TEMP_1, 1
	return

Aquamarineabyss_End_EventScript_Kyogre::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_KYOGRE, Aquamarineabyss_End_Movement_KyogreApproach
	waitmovement 0
	waitse
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_KYOGRE
	setwildbattle SPECIES_KYOGRE, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_TEMP_1, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Aquamarineabyss_End_EventScript_DefeatedKyogre
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Aquamarineabyss_End_EventScript_RanFromKyogre
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Aquamarineabyss_End_EventScript_RanFromKyogre
	setvar VAR_SHOULD_END_ABNORMAL_WEATHER, 1
	setflag FLAG_DEFEATED_KYOGRE
	releaseall
	end

Aquamarineabyss_End_EventScript_DefeatedKyogre::
	setvar VAR_SHOULD_END_ABNORMAL_WEATHER, 1
	setflag FLAG_DEFEATED_KYOGRE
	goto Common_EventScript_RemoveStaticPokemon
	end

Aquamarineabyss_End_EventScript_RanFromKyogre::
	setvar VAR_0x8004, SPECIES_KYOGRE
	goto Common_EventScript_LegendaryFlewAway
	end

Aquamarineabyss_End_Movement_KyogreApproach:
	init_affine_anim
	walk_down_start_affine
	delay_16
	delay_16
	walk_down_affine
	delay_16
	delay_16
	walk_down_affine
	step_end

