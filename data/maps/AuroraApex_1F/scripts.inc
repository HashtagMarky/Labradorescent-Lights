AuroraApex_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AuroraApex_1F_OnTransition
	.byte 0

AuroraApex_1F_OnTransition:
	call_if_lt VAR_AURORA_APEX_STATE, 2, AuroraApex_1F_EventScript_CleanFloor
	end

AuroraApex_1F_EventScript_CleanFloor::
	setmaplayoutindex LAYOUT_AURORA_APEX_1F_CLEAN
	return
