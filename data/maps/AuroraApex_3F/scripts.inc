AuroraApex_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AuroraApex_3F_OnTransition
	.byte 0

AuroraApex_3F_OnTransition:
	call_if_lt VAR_AURORA_APEX_STATE, 2, AuroraApex_3F_EventScript_CleanFloor
	end

AuroraApex_3F_EventScript_CleanFloor::
	setmaplayoutindex LAYOUT_AURORA_APEX_3F_CLEAN
	return
