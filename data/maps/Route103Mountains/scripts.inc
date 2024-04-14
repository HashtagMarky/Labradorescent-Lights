Route103Mountains_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route103Mountains_MapScripts_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Route103Mountains_EventScript_OnTransition
	.byte 0
	
Route103Mountains_MapScripts_OnLoad:
	call_if_set FLAG_SYS_DEMO_MODE, Route103Mountains_EventScript_DemoMetatile
	return

Route103Mountains_EventScript_DemoMetatile:
	setmetatile 15, 15, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 15, 14, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 7, 19, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 7, 20, METATILE_General_RockWall_GrassBase, TRUE
	special DrawWholeMapView
	end

Route103Mountains_EventScript_OnTransition:
	special GetTimeOfDay
	goto_if_eq VAR_RESULT, 0, Route103Mountains_OnTransition_Day
	goto_if_eq VAR_RESULT, 1, Route103Mountains_OnTransition_Twilight
	goto_if_eq VAR_RESULT, 2, Route103Mountains_OnTransition_Night
	end

Route103Mountains_OnTransition_Day:
	setvar VAR_TIMEOFDAY, 0
	end

Route103Mountains_OnTransition_Twilight:
	setvar VAR_TIMEOFDAY, 1
	end

Route103Mountains_OnTransition_Night:
	setvar VAR_TIMEOFDAY, 2
	end
