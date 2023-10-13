SelenicSpirit_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SelenicSpirit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SelenicSpirit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_1, 0, SelenicSpirit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

SelenicSpirit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	addvar VAR_TEMP_1, 1
	checkitem ITEM_LAB_ORB, 1
	compare VAR_RESULT, FALSE
	goto_if_eq SelenicSpirit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1
	return

SelenicSpirit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1:
	applymovement OBJ_EVENT_ID_PLAYER, SelenicEntrance
	waitmovement 0
	goto SelenicSpirit_EventScript_ShopClerk
	return


SelenicEntrance:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

SelenicSpirit_EventScript_ShopClerk::
	lock
	applymovement 1, FaceDown
	questmenu QUEST_MENU_CHECK_UNLOCKED, SELENIC_SPIRIT
	compare VAR_RESULT, FALSE
	goto_if_eq SelenicSpirit_EventScript_ShopClerk_1
	checkitem ITEM_LAB_ORB, 1
	compare VAR_RESULT, FALSE
	goto_if_eq SelenicSpirit_EventScript_ShopClerk_4
	msgbox SelenicSpirit_EventScript_ShopClerk_Text_1, MSGBOX_DEFAULT
	closemessage
	release
	return

SelenicSpirit_EventScript_ShopClerk_1:
	msgbox SelenicSpirit_EventScript_ShopClerk_Text_0, MSGBOX_NPC
	end

SelenicSpirit_EventScript_ShopClerk_4:
	msgbox SelenicSpirit_EventScript_ShopClerk_Text_1, MSGBOX_DEFAULT
	msgbox SelenicSpirit_EventScript_ShopClerk_Text_2, MSGBOX_DEFAULT
	giveitem ITEM_LAB_ORB
	msgbox SelenicSpirit_EventScript_ShopClerk_Text_3, MSGBOX_DEFAULT
	questmenu QUEST_MENU_CHECK_UNLOCKED, LAB_LIGHTS
	compare VAR_RESULT, FALSE
	goto_if_eq SelenicSpirit_EventScript_ShopClerk_8
SelenicSpirit_EventScript_ShopClerk_7:
	closemessage
	return

SelenicSpirit_EventScript_ShopClerk_8:
	startquest LAB_LIGHTS
	goto SelenicSpirit_EventScript_ShopClerk_7


SelenicSpirit_EventScript_Gent::
	lock
	msgbox SelenicSpirit_EventScript_Gent_Text_0, MSGBOX_DEFAULT
	closemessage
	release
	end


SelenicSpirit_EventScript_Lass::
	lock
	msgbox SelenicSpirit_EventScript_Lass_Text_0, MSGBOX_DEFAULT
	closemessage
	release
	end


SelenicSpirit_EventScript_Girl::
	lock
	msgbox SelenicSpirit_EventScript_Girl_Text_0, MSGBOX_DEFAULT
	closemessage
	release
	end


SelenicSpirit_EventScript_Woman::
	lock
	msgbox SelenicSpirit_EventScript_Woman_Text_0, MSGBOX_DEFAULT
	closemessage
	release
	end


SelenicSpirit_EventScript_ShopClerk_Text_0:
	.string "Welcome to SELENIC SPIRIT.\n"
	.string "We're not currently open.\l"
	.string "Please come back another time.$"

SelenicSpirit_EventScript_ShopClerk_Text_1:
	.string "Welcome to SELENIC SPIRIT.\n"
	.string "We're not currently open-\l"
	.string "Wait, you're {PLAYER}!\p"
	.string "Well if you're MOM is the owner,\n"
	.string "I can hardly send you away.$"

SelenicSpirit_EventScript_ShopClerk_Text_2:
	.string "Oh…\n"
	.string "The package from PROFESSOR IGNATIUS?\l"
	.string "It's exactly what LAUREN wanted!\p"
	.string "Tell the PROFESSOR that she really\n"
	.string "appreciates it!\p"
	.string "Actually, there was something inside\n"
	.string "for you.$"

SelenicSpirit_EventScript_ShopClerk_Text_3:
	.string "She wanted the PROFESSOR to get it for\n"
	.string "you, as a symbol of a fresh start.$"

SelenicSpirit_EventScript_Gent_Text_0:
	.string "I didn't think there would be something\n"
	.string "in here for me, but I love all of these!$"

SelenicSpirit_EventScript_Lass_Text_0:
	.string "Wow! This crystal jewellery sure is\n"
	.string "beautiful, I can't get enough of it!$"

SelenicSpirit_EventScript_Girl_Text_0:
	.string "I'm looking for something for my aunt.\n"
	.string "What do you think she'll like?$"

SelenicSpirit_EventScript_Woman_Text_0:
	.string "I used to buy from SELENIC online, I\n"
	.string "just knew I had to come in-store.$"
