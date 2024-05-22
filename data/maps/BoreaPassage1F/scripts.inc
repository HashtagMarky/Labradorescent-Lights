BoreaPassage1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BoreaPassage1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

BoreaPassage1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_1, 0, BoreaPassage1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

BoreaPassage1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	setvar VAR_TEMP_1, 1
	subquestmenu QUEST_MENU_CHECK_COMPLETE, HOMELY, DINNER
	compare VAR_RESULT, FALSE
	goto_if_eq BoreaPassage1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1
	return

BoreaPassage1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1:
	call BoreaPassage1F_AquaOpeningScene
	return


BoreaPassage1F_AquaOpeningScene::
	return

