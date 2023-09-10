AuroraApex_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, AuroraApex_2F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, AuroraApex_2F_SetHoleWarp
	.byte 0

AuroraApex_2F_OnTransition:
	call_if_lt VAR_AURORA_APEX_STATE, 2, AuroraApex_2F_EventScript_CleanFloor
	copyvar VAR_ICE_STEP_COUNT, 1
	end

AuroraApex_2F_EventScript_CleanFloor::
	setmaplayoutindex LAYOUT_AURORA_APEX_2F_CLEAN
	return

AuroraApex_2F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_AURORA_APEX_1F
	end

