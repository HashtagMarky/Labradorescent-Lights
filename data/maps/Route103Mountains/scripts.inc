Route103Mountains_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route103Mountains_MapScripts_OnLoad
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
	
