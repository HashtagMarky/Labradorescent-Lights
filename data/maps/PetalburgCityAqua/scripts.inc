PetalburgCityAqua_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCityAqua_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCityAqua_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

PetalburgCityAqua_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, HOMELY, PROTECT
	compare VAR_RESULT, FALSE
	goto_if_eq PetalburgCityAqua_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

PetalburgCityAqua_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setflag FLAG_HIDE_MAP_NAME_POPUP
	savebgm MUS_PL_LOOKER
	return

PetalburgCityAqua_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_1, 0, PetalburgCityAqua_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

PetalburgCityAqua_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	addvar VAR_TEMP_1, 1
	setmetatile 15, 8, METATILE_Petalburg_Door_Gym_Closed, TRUE
	return


PetalburgCityAqua_EventScripts_AquaGrunt_Male::
	lock
	msgbox PetalburgCityAqua_EventScripts_AquaGrunt_Male_Text_0, MSGBOX_DEFAULT
	closemessage
	release
	return


PetalburgCityAqua_EventScripts_AquaGrunt_Female::
	lock
	msgbox PetalburgCityAqua_EventScripts_AquaGrunt_Female_Text_0, MSGBOX_DEFAULT
	closemessage
	release
	return


PetalburgCityAqua_EventScripts_AquaGrunt_Male_Text_0:
	.string "We own PETALBURG CITY!\n"
	.string "TEAM AQUA on top!$"

PetalburgCityAqua_EventScripts_AquaGrunt_Female_Text_0:
	.string "TEAM AQUA is the best!\n"
	.string "PETALBURG CITY is ours!$"
