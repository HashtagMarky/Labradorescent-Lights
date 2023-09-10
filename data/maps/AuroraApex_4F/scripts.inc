AuroraApex_4F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, AuroraApex_4F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, AuroraApex_4F_SetHoleWarp
	.byte 0

AuroraApex_4F_OnTransition:
	call_if_lt VAR_AURORA_APEX_STATE, 2, AuroraApex_4F_EventScript_CleanFloor
	copyvar VAR_ICE_STEP_COUNT, 1
	end

AuroraApex_4F_EventScript_CleanFloor::
	setmaplayoutindex LAYOUT_AURORA_APEX_4F_CLEAN
	return

AuroraApex_4F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_AURORA_APEX_3F
	end

