SelenicSpirit_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SelenicSpirit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SelenicSpirit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_1, 0, SelenicSpirit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

SelenicSpirit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	addvar VAR_TEMP_1, 1
	call CountBadges
	copyvar VAR_TEMP_2, VAR_RESULT
	checkitem ITEM_RED_ORB, 1
	compare VAR_RESULT, TRUE
	goto_if_eq SelenicSpirit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_2
SelenicSpirit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1:
	checkitem ITEM_BLUE_ORB, 1
	compare VAR_RESULT, TRUE
	goto_if_eq SelenicSpirit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_5
SelenicSpirit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_4:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, ADVENTURE_BEGINS, FIND_RIVAL
	compare VAR_RESULT, TRUE
	goto_if_eq SelenicSpirit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_8
	return

SelenicSpirit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_2:
	addvar VAR_TEMP_3, 1
	goto SelenicSpirit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1

SelenicSpirit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_5:
	addvar VAR_TEMP_3, 2
	goto SelenicSpirit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_4

SelenicSpirit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_7:
	checkitem ITEM_LAB_ORB, 1
	compare VAR_RESULT, FALSE
	goto_if_eq SelenicSpirit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_11
	return

SelenicSpirit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_8:
	goto_if_unset FLAG_SYS_DEMO_MODE, SelenicSpirit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_7
	return

SelenicSpirit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_11:
	applymovement OBJ_EVENT_ID_PLAYER, SelenicEntrance
	waitmovement 0
	delay 20
	goto SelenicSpirit_EventScript_ShopClerk
	return


SelenicSpirit_HideObjects::
	setflag FLAG_SELENIC_MOM
	setflag FLAG_SELENIC_CUSTOMER_1
	setflag FLAG_SELENIC_CUSTOMER_2
	setflag FLAG_SELENIC_CUSTOMER_3
	setflag FLAG_SELENIC_CUSTOMER_4
	setflag FLAG_SELENIC_CUSTOMER_5
	setflag FLAG_SELENIC_CUSTOMER_6
	setflag FLAG_SELENIC_CUSTOMER_7
	setflag FLAG_SELENIC_CUSTOMER_8
	setflag FLAG_SELENIC_CUSTOMER_CHAMPION
	setflag FLAG_SELENIC_CUSTOMER_AQUA
	setflag FLAG_SELENIC_CUSTOMER_MAGMA
	return


SelenicSpirit_EventScript_ShopClerk::
	lock
	applymovement 1, FaceDown
	questmenu QUEST_MENU_CHECK_UNLOCKED, SELENIC_SPIRIT
	compare VAR_RESULT, FALSE
	goto_if_eq SelenicSpirit_EventScript_ShopClerk_2
	checkitem ITEM_LAB_ORB, 1
	compare VAR_RESULT, FALSE
	goto_if_eq SelenicSpirit_EventScript_ShopClerk_5
	goto_if_set FLAG_SYS_DEMO_MODE, SelenicSpirit_EventScript_ShopClerk_13
	questmenu QUEST_MENU_CHECK_COMPLETE, ADVENTURE_BEGINS
	compare VAR_RESULT, FALSE
	goto_if_eq SelenicSpirit_EventScript_ShopClerk_16
	goto SelenicSpirit_ChooseMart
SelenicSpirit_EventScript_ShopClerk_1:
	closemessage
	return

SelenicSpirit_EventScript_ShopClerk_2:
	msgbox SelenicSpirit_EventScript_ShopClerk_Text_0, MSGBOX_NPC
	end

SelenicSpirit_EventScript_ShopClerk_5:
	msgbox SelenicSpirit_EventScript_ShopClerk_Text_1, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement 1, Exclaim
	msgbox SelenicSpirit_EventScript_ShopClerk_Text_2, MSGBOX_DEFAULT
	waitmovement 0
	applymovement 1, Question
	msgbox SelenicSpirit_EventScript_ShopClerk_Text_3, MSGBOX_DEFAULT
	waitmovement 0
	giveitem ITEM_LAB_ORB
	msgbox SelenicSpirit_EventScript_ShopClerk_Text_4, MSGBOX_DEFAULT
	questmenu QUEST_MENU_CHECK_UNLOCKED, LAB_LIGHTS
	compare VAR_RESULT, FALSE
	goto_if_eq SelenicSpirit_EventScript_ShopClerk_10
SelenicSpirit_EventScript_ShopClerk_8:
	closemessage
	release
	goto SelenicSpirit_EventScript_ShopClerk_1

SelenicSpirit_EventScript_ShopClerk_9:
	startquest LAB_LIGHTS
	goto SelenicSpirit_EventScript_ShopClerk_8

SelenicSpirit_EventScript_ShopClerk_10:
	goto_if_unset FLAG_SYS_DEMO_MODE, SelenicSpirit_EventScript_ShopClerk_9
	goto SelenicSpirit_EventScript_ShopClerk_8

SelenicSpirit_EventScript_ShopClerk_13:
	msgbox SelenicSpirit_EventScript_ShopClerk_Text_5, MSGBOX_DEFAULT
	closemessage
	release
	end

SelenicSpirit_EventScript_ShopClerk_16:
	msgbox SelenicSpirit_EventScript_ShopClerk_Text_6, MSGBOX_DEFAULT
	message SelenicSpirit_EventScript_ShopClerk_Text_7
	waitmessage
	pokemart OnlyForYou
	msgbox SelenicSpirit_EventScript_ShopClerk_Text_8, MSGBOX_NPC
	goto SelenicSpirit_EventScript_ShopClerk_1


SelenicSpirit_ChooseMart::
	message SelenicSpirit_ChooseMart_Text_0
	waitmessage
	switch VAR_TEMP_2
	case 0, SelenicSpirit_ChooseMart_3
	case 1, SelenicSpirit_ChooseMart_4
	case 2, SelenicSpirit_ChooseMart_5
	case 3, SelenicSpirit_ChooseMart_6
	case 4, SelenicSpirit_ChooseMart_7
	case 5, SelenicSpirit_ChooseMart_8
	case 6, SelenicSpirit_ChooseMart_9
	case 7, SelenicSpirit_ChooseMart_10
	case 8, SelenicSpirit_ChooseMart_11
	case 9, SelenicSpirit_ChooseMart_12
SelenicSpirit_ChooseMart_1:
	msgbox SelenicSpirit_ChooseMart_Text_1, MSGBOX_NPC
	closemessage
	return

SelenicSpirit_ChooseMart_3:
	pokemart JustOpened
	goto SelenicSpirit_ChooseMart_1

SelenicSpirit_ChooseMart_4:
	pokemart SelenicBadgeOne
	goto SelenicSpirit_ChooseMart_1

SelenicSpirit_ChooseMart_5:
	pokemart SelenicBadgeTwo
	goto SelenicSpirit_ChooseMart_1

SelenicSpirit_ChooseMart_6:
	pokemart SelenicBadgeThree
	goto SelenicSpirit_ChooseMart_1

SelenicSpirit_ChooseMart_7:
	pokemart SelenicBadgeFour
	goto SelenicSpirit_ChooseMart_1

SelenicSpirit_ChooseMart_8:
	pokemart SelenicBadgeFive
	goto SelenicSpirit_ChooseMart_1

SelenicSpirit_ChooseMart_9:
	pokemart SelenicBadgeSix
	goto SelenicSpirit_ChooseMart_1

SelenicSpirit_ChooseMart_10:
	pokemart SelenicBadgeSeven
	goto SelenicSpirit_ChooseMart_1

SelenicSpirit_ChooseMart_11:
	pokemart SelenicBadgeEight
	goto SelenicSpirit_ChooseMart_1

SelenicSpirit_ChooseMart_12:
	pokemart SelenicChampion
	goto SelenicSpirit_ChooseMart_1


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

	.align 2
OnlyForYou:
	.2byte ITEM_NONE

	.align 2
JustOpened:
	.2byte ITEM_NONE

	.align 2
SelenicRedOrb:
	.2byte ITEM_NONE

	.align 2
SelenicBlueOrb:
	.2byte ITEM_NONE

	.align 2
SelenicRedAndBlueOrb:
	.2byte ITEM_NONE

	.align 2
SelenicBadgeOne:
	.2byte ITEM_NONE

	.align 2
SelenicBadgeTwo:
	.2byte ITEM_NONE

	.align 2
SelenicBadgeThree:
	.2byte ITEM_NONE

	.align 2
SelenicBadgeFour:
	.2byte ITEM_NONE

	.align 2
SelenicBadgeFive:
	.2byte ITEM_NONE

	.align 2
SelenicBadgeSix:
	.2byte ITEM_NONE

	.align 2
SelenicBadgeSeven:
	.2byte ITEM_NONE

	.align 2
SelenicBadgeEight:
	.2byte ITEM_NONE

	.align 2
SelenicChampion:
	.2byte ITEM_NONE

SelenicSpirit_EventScript_ShopClerk_Text_0:
	.string "Welcome to SELENIC SPIRIT.\n"
	.string "We're not currently open.\l"
	.string "Please come back another time.$"

SelenicSpirit_EventScript_ShopClerk_Text_1:
	.string "Welcome to SELENIC SPIRIT.\n"
	.string "We're not currently open-$"

SelenicSpirit_EventScript_ShopClerk_Text_2:
	.string "Wait, you're {PLAYER}!\p"
	.string "Well if your MOM is the owner,\n"
	.string "I can hardly send you away.\p"
	.string "… … … … … …\n"
	.string "… … … … … …$"

SelenicSpirit_EventScript_ShopClerk_Text_3:
	.string "Oh…\n"
	.string "The package from PROFESSOR IGNATIUS?\l"
	.string "It's exactly what LAUREN wanted!\p"
	.string "Tell the PROFESSOR that she really\n"
	.string "appreciates it!\p"
	.string "Actually, there was something inside\n"
	.string "for you.$"

SelenicSpirit_EventScript_ShopClerk_Text_4:
	.string "She wanted the PROFESSOR to get it for\n"
	.string "you, as a ward of protection.\p"
	.string "Your MOM has more stock coming in soon,\n"
	.string "sourced by the miners in BOREA PASSAGE.\l"
	.string "I'll update you when they arrive.\p"
	.string "Have a splendid day, {PLAYER}!$"

SelenicSpirit_EventScript_ShopClerk_Text_5:
	.string "Welcome to SELENIC SPIRIT.\n"
	.string "We're not currently open.\l"
	.string "Sadly we'll be closed during the DEMO.$"

SelenicSpirit_EventScript_ShopClerk_Text_6:
	.string "Welcome to SELENIC SPIRIT.\n"
	.string "We're not currently open-\l"
	.string "Wait, you're {PLAYER}!\p"
	.string "Well if your MOM is the owner,\n"
	.string "I can hardly send you away.$"

SelenicSpirit_EventScript_ShopClerk_Text_7:
	.string "How can I help you today, {PLAYER}?$"

SelenicSpirit_EventScript_ShopClerk_Text_8:
	.string "Have a splendid day, {PLAYER}!\n"
	.string "We'll see you soon.$"

SelenicSpirit_ChooseMart_Text_0:
	.string "Hello again, {PLAYER}!\nHow can I help you today?$"

SelenicSpirit_ChooseMart_Text_1:
	.string "Have a splendid day, {PLAYER}!\n"
	.string "We'll see you again soon.$"

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
