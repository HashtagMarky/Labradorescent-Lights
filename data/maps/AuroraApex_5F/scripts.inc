AuroraApex_5F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AuroraApex_5F_OnTransition
	.byte 0

AuroraApex_5F_OnTransition:
	call AuroraApex_5F_EventScript_CleanFloor
	return

AuroraApex_5F_EventScript_CleanFloor::
	setmaplayoutindex LAYOUT_AURORA_APEX_5F_CLEAN
	return
