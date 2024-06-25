SelenicSpirit_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SelenicSpirit_AddBoxes
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SelenicSpirit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SelenicSpirit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_1, 0, SelenicSpirit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

SelenicSpirit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	addvar VAR_TEMP_1, 1
	subquestmenu QUEST_MENU_CHECK_COMPLETE, ADVENTURE_BEGINS, FIND_RIVAL
	compare VAR_RESULT, TRUE
	goto_if_eq SelenicSpirit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_2
	return

SelenicSpirit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1:
	checkitem ITEM_LAB_ORB, 1
	compare VAR_RESULT, FALSE
	goto_if_eq SelenicSpirit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_5
	return

SelenicSpirit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_2:
	goto_if_unset FLAG_SYS_DEMO_MODE, SelenicSpirit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1
	return

SelenicSpirit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_5:
	applymovement OBJ_EVENT_ID_PLAYER, SelenicEntrance
	waitmovement 0
	delay 20
	goto SelenicSpirit_EventScript_ShopClerk
	return


SelenicSpirit_AddBoxes::
	checkitem ITEM_LAB_ORB, 1
	compare VAR_RESULT, FALSE
	goto_if_eq SelenicSpirit_AddBoxes_1
	return

SelenicSpirit_AddBoxes_1:
	setmetatile 2, 3, METATILE_Shop_MovingBox_Closed, TRUE
	setmetatile 6, 3, METATILE_Shop_MovingBox_Closed, TRUE
	setmetatile 10, 3, METATILE_Shop_MovingBox_Open, TRUE
	setmetatile 5, 4, METATILE_Shop_MovingBox_Closed_Shadow, TRUE
	setmetatile 15, 4, METATILE_Shop_MovingBox_Open, TRUE
	setmetatile 6, 6, METATILE_Shop_MovingBox_Open, TRUE
	setmetatile 10, 6, METATILE_Shop_MovingBox_Open, TRUE
	setmetatile 14, 6, METATILE_Shop_MovingBox_Closed, TRUE
	setmetatile 1, 7, METATILE_Shop_MovingBox_Closed_Shadow, TRUE
	setmetatile 10, 7, METATILE_Shop_MovingBox_Closed, TRUE
	setmetatile 13, 7, METATILE_Shop_MovingBox_Open_Shadow, TRUE
	setmetatile 9, 8, METATILE_Shop_MovingBox_Open_Shadow, TRUE
	setmetatile 14, 8, METATILE_Shop_MovingBox_Closed, TRUE
	setmetatile 6, 9, METATILE_Shop_MovingBox_Closed, TRUE
	return


SelenicSpirit_RemoveBoxes::
	setmetatile 2, 3, METATILE_Shop_Floor, FALSE
	setmetatile 6, 3, METATILE_Shop_Floor, FALSE
	setmetatile 10, 3, METATILE_Shop_Floor, FALSE
	setmetatile 5, 4, METATILE_Shop_Floor_Shadow, FALSE
	setmetatile 15, 4, METATILE_Shop_Floor, FALSE
	setmetatile 6, 6, METATILE_Shop_Floor, FALSE
	setmetatile 10, 6, METATILE_Shop_Floor, FALSE
	setmetatile 14, 6, METATILE_Shop_Floor, FALSE
	setmetatile 1, 7, METATILE_Shop_Floor_Shadow, FALSE
	setmetatile 10, 7, METATILE_Shop_Floor, FALSE
	setmetatile 13, 7, METATILE_Shop_Floor_Shadow, FALSE
	setmetatile 9, 8, METATILE_Shop_Floor_Shadow, FALSE
	setmetatile 14, 8, METATILE_Shop_Floor, FALSE
	setmetatile 6, 9, METATILE_Shop_Floor, FALSE
	return


SelenicSpirit_HideBoxObjects::
	setvar VAR_TEMP_1, 14
SelenicSpirit_HideBoxObjects_1:
	compare VAR_TEMP_1, 27
	goto_if_le SelenicSpirit_HideBoxObjects_2
	return

SelenicSpirit_HideBoxObjects_2:
	removeobject VAR_TEMP_1
	addvar VAR_TEMP_1, 1
	goto SelenicSpirit_HideBoxObjects_1


SelenicSpirit_MovingBoxes::
	lock
	msgbox SelenicSpirit_MovingBoxes_Text_0, MSGBOX_DEFAULT
	closemessage
	release
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
	setflag FLAG_MOVING_BOXES_SELENIC
	msgbox SelenicSpirit_EventScript_ShopClerk_Text_4, MSGBOX_DEFAULT
	setvar VAR_SELENIC_MARTS, 0
	closemessage
	fadescreen FADE_TO_BLACK
	delay 10
	playse SE_CONTEST_ICON_CLEAR
	delay 5
	playse SE_CONTEST_ICON_CLEAR
	call SelenicSpirit_RemoveBoxes
	call SelenicSpirit_HideBoxObjects
	special DrawWholeMapView
	waitse
	delay 10
	questmenu QUEST_MENU_CHECK_UNLOCKED, LAB_LIGHTS
	compare VAR_RESULT, FALSE
	goto_if_eq SelenicSpirit_EventScript_ShopClerk_10
SelenicSpirit_EventScript_ShopClerk_8:
	fadescreen FADE_FROM_BLACK
	msgbox SelenicSpirit_EventScript_ShopClerk_Text_5, MSGBOX_DEFAULT
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
	msgbox SelenicSpirit_EventScript_ShopClerk_Text_6, MSGBOX_DEFAULT
	closemessage
	release
	end

SelenicSpirit_EventScript_ShopClerk_16:
	msgbox SelenicSpirit_EventScript_ShopClerk_Text_7, MSGBOX_DEFAULT
	message SelenicSpirit_EventScript_ShopClerk_Text_8
	waitmessage
	pokemart OnlyForYou
	msgbox SelenicSpirit_EventScript_ShopClerk_Text_9, MSGBOX_NPC
	goto SelenicSpirit_EventScript_ShopClerk_1


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


SelenicSpirit_EventScript_Steven::
	msgbox SelenicSpirit_EventScript_Steven_Text_0, MSGBOX_NPC
	return


SelenicSpirit_EventScript_Aqua::
	msgbox SelenicSpirit_EventScript_Aqua_Text_0, MSGBOX_NPC
	return


SelenicSpirit_EventScript_Magma::
	msgbox SelenicSpirit_EventScript_Magma_Text_0, MSGBOX_NPC
	return


SelenicSpirit_EventScript_Man::
	msgbox SelenicSpirit_EventScript_Man_Text_0, MSGBOX_NPC
	return


SelenicSpirit_EventScript_Man2::
	msgbox SelenicSpirit_EventScript_Man2_Text_0, MSGBOX_NPC
	return


SelenicSpirit_EventScript_Woman2::
	msgbox SelenicSpirit_EventScript_Woman2_Text_0, MSGBOX_NPC
	return


SelenicSpirit_EventScript_Woman3::
	msgbox SelenicSpirit_EventScript_Woman3_Text_0, MSGBOX_NPC
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

SelenicSpirit_ChooseMart::
	checkitem ITEM_METEORITE, 1
	compare VAR_RESULT, TRUE
	goto_if_eq SelenicSpirit_ChooseMart_4
SelenicSpirit_ChooseMart_3:
	message SelenicSpirit_ChooseMart_Text_1
SelenicSpirit_ChooseMart_1:
	waitmessage
	switch VAR_SELENIC_MARTS
	case 0, SelenicSpirit_ChooseMart_9
	case 1, SelenicSpirit_ChooseMart_10
	case 2, SelenicSpirit_ChooseMart_11
	case 3, SelenicSpirit_ChooseMart_12
	case 4, SelenicSpirit_ChooseMart_13
	case 5, SelenicSpirit_ChooseMart_14
	case 6, SelenicSpirit_ChooseMart_15
	case 7, SelenicSpirit_ChooseMart_16
	case 8, SelenicSpirit_ChooseMart_17
	case 9, SelenicSpirit_ChooseMart_18
	case 10, SelenicSpirit_ChooseMart_19
	case 11, SelenicSpirit_ChooseMart_20
	case 12, SelenicSpirit_ChooseMart_21
SelenicSpirit_ChooseMart_21:
	pokemart SelenicChampion
SelenicSpirit_ChooseMart_7:
	msgbox SelenicSpirit_ChooseMart_Text_2, MSGBOX_NPC
	closemessage
	return

SelenicSpirit_ChooseMart_2:
	setflag FLAG_SELENIC_EARLY_METEORITE
	applymovement 1, Exclaim
	message SelenicSpirit_ChooseMart_Text_0
	goto SelenicSpirit_ChooseMart_1

SelenicSpirit_ChooseMart_4:
	goto_if_unset FLAG_SELENIC_EARLY_METEORITE, SelenicSpirit_ChooseMart_2
	goto SelenicSpirit_ChooseMart_3

SelenicSpirit_ChooseMart_9:
	pokemart OnlyForYou
	goto SelenicSpirit_ChooseMart_7

SelenicSpirit_ChooseMart_10:
	pokemart JustOpened
	goto SelenicSpirit_ChooseMart_7

SelenicSpirit_ChooseMart_11:
	pokemart SelenicBadgeOne
	goto SelenicSpirit_ChooseMart_7

SelenicSpirit_ChooseMart_12:
	pokemart SelenicBadgeTwo
	goto SelenicSpirit_ChooseMart_7

SelenicSpirit_ChooseMart_13:
	pokemart SelenicBadgeThree
	goto SelenicSpirit_ChooseMart_7

SelenicSpirit_ChooseMart_14:
	pokemart SelenicBadgeFour
	goto SelenicSpirit_ChooseMart_7

SelenicSpirit_ChooseMart_15:
	pokemart SelenicBadgeFive
	goto SelenicSpirit_ChooseMart_7

SelenicSpirit_ChooseMart_16:
	pokemart SelenicBadgeSix
	goto SelenicSpirit_ChooseMart_7

SelenicSpirit_ChooseMart_17:
	pokemart SelenicRedOrb
	goto SelenicSpirit_ChooseMart_7

SelenicSpirit_ChooseMart_18:
	pokemart SelenicBadgeSeven
	goto SelenicSpirit_ChooseMart_7

SelenicSpirit_ChooseMart_19:
	pokemart SelenicBlueOrb
	goto SelenicSpirit_ChooseMart_7

SelenicSpirit_ChooseMart_20:
	pokemart SelenicBadgeEight
	goto SelenicSpirit_ChooseMart_7


SelenicSpirit_EventScript_ProfessorCozmo::
	goto_if_unset FLAG_RETURNED_METEORITE, SelenicSpirit_EventScript_ProfessorCozmo_1
	return

SelenicSpirit_EventScript_ProfessorCozmo_1:
	checkitem ITEM_METEORITE, 1
	compare VAR_RESULT, TRUE
	goto_if_eq SelenicSpirit_EventScript_ProfessorCozmo_4
	setflag FLAG_RECEIVED_METEORITE
	goto_if_unset FLAG_RECEIVED_TM27, SelenicSpirit_EventScript_ProfessorCozmo_7
	return

SelenicSpirit_EventScript_ProfessorCozmo_4:
	return

SelenicSpirit_EventScript_ProfessorCozmo_7:
	setflag FLAG_RECEIVED_TM27
	return


	.align 2
OnlyForYou:
	.2byte ITEM_LABRADORITE_CHUNK
	.2byte ITEM_PREHNITE_CHUNK
	.2byte ITEM_NONE

	.align 2
JustOpened:
	.2byte ITEM_LABRADORITE_CHUNK
	.2byte ITEM_PREHNITE_CHUNK
	.2byte ITEM_CITRINE_CHUNK
	.2byte ITEM_TOPAZ_CHUNK
	.2byte ITEM_NONE

	.align 2
SelenicBadgeOne:
	.2byte ITEM_LABRADORITE_CHUNK
	.2byte ITEM_PREHNITE_CHUNK
	.2byte ITEM_CITRINE_CHUNK
	.2byte ITEM_TOPAZ_CHUNK
	.2byte ITEM_DEMORTIURITE_CHUNK
	.2byte ITEM_NONE

	.align 2
SelenicBadgeTwo:
	.2byte ITEM_LABRADORITE_CHUNK
	.2byte ITEM_PREHNITE_CHUNK
	.2byte ITEM_CITRINE_CHUNK
	.2byte ITEM_TOPAZ_CHUNK
	.2byte ITEM_DEMORTIURITE_CHUNK
	.2byte ITEM_MALACHITE_CHUNK
	.2byte ITEM_NONE

	.align 2
SelenicBadgeThree:
	.2byte ITEM_LABRADORITE_CHUNK
	.2byte ITEM_PREHNITE_CHUNK
	.2byte ITEM_CITRINE_CHUNK
	.2byte ITEM_TOPAZ_CHUNK
	.2byte ITEM_DEMORTIURITE_CHUNK
	.2byte ITEM_MALACHITE_CHUNK
	.2byte ITEM_AMETHYST_CHUNK
	.2byte ITEM_NONE

	.align 2
SelenicBadgeFour:
	.2byte ITEM_LABRADORITE_CHUNK
	.2byte ITEM_PREHNITE_CHUNK
	.2byte ITEM_CITRINE_CHUNK
	.2byte ITEM_TOPAZ_CHUNK
	.2byte ITEM_DEMORTIURITE_CHUNK
	.2byte ITEM_MALACHITE_CHUNK
	.2byte ITEM_AMETHYST_CHUNK
	.2byte ITEM_THULITE_CHUNK
	.2byte ITEM_NONE

	.align 2
SelenicBadgeFive:
	.2byte ITEM_LABRADORITE_CHUNK
	.2byte ITEM_PREHNITE_CHUNK
	.2byte ITEM_CITRINE_CHUNK
	.2byte ITEM_TOPAZ_CHUNK
	.2byte ITEM_DEMORTIURITE_CHUNK
	.2byte ITEM_MALACHITE_CHUNK
	.2byte ITEM_AMETHYST_CHUNK
	.2byte ITEM_THULITE_CHUNK
	.2byte ITEM_PIYRITE_CHUNK
	.2byte ITEM_NONE

	.align 2
SelenicBadgeSix:
	.2byte ITEM_LABRADORITE_CHUNK
	.2byte ITEM_PREHNITE_CHUNK
	.2byte ITEM_CITRINE_CHUNK
	.2byte ITEM_TOPAZ_CHUNK
	.2byte ITEM_DEMORTIURITE_CHUNK
	.2byte ITEM_MALACHITE_CHUNK
	.2byte ITEM_AMETHYST_CHUNK
	.2byte ITEM_THULITE_CHUNK
	.2byte ITEM_PIYRITE_CHUNK
	.2byte ITEM_TOURMALINE_CHUNK
	.2byte ITEM_NONE

	.align 2
SelenicRedOrb:
	.2byte ITEM_LABRADORITE_CHUNK
	.2byte ITEM_CARNELIAN_CHUNK
	.2byte ITEM_PREHNITE_CHUNK
	.2byte ITEM_CITRINE_CHUNK
	.2byte ITEM_TOPAZ_CHUNK
	.2byte ITEM_DEMORTIURITE_CHUNK
	.2byte ITEM_MALACHITE_CHUNK
	.2byte ITEM_AMETHYST_CHUNK
	.2byte ITEM_THULITE_CHUNK
	.2byte ITEM_PIYRITE_CHUNK
	.2byte ITEM_TOURMALINE_CHUNK
	.2byte ITEM_NONE

	.align 2
SelenicBadgeSeven:
	.2byte ITEM_LABRADORITE_CHUNK
	.2byte ITEM_CARNELIAN_CHUNK
	.2byte ITEM_PREHNITE_CHUNK
	.2byte ITEM_CITRINE_CHUNK
	.2byte ITEM_TOPAZ_CHUNK
	.2byte ITEM_DEMORTIURITE_CHUNK
	.2byte ITEM_MALACHITE_CHUNK
	.2byte ITEM_AMETHYST_CHUNK
	.2byte ITEM_THULITE_CHUNK
	.2byte ITEM_PIYRITE_CHUNK
	.2byte ITEM_TOURMALINE_CHUNK
	.2byte ITEM_RHODOCHROSITE_CHUNK
	.2byte ITEM_NONE

	.align 2
SelenicBlueOrb:
	.2byte ITEM_LABRADORITE_CHUNK
	.2byte ITEM_CARNELIAN_CHUNK
	.2byte ITEM_AQUAMARINE_CHUNK
	.2byte ITEM_PREHNITE_CHUNK
	.2byte ITEM_CITRINE_CHUNK
	.2byte ITEM_TOPAZ_CHUNK
	.2byte ITEM_DEMORTIURITE_CHUNK
	.2byte ITEM_MALACHITE_CHUNK
	.2byte ITEM_AMETHYST_CHUNK
	.2byte ITEM_THULITE_CHUNK
	.2byte ITEM_PIYRITE_CHUNK
	.2byte ITEM_TOURMALINE_CHUNK
	.2byte ITEM_RHODOCHROSITE_CHUNK
	.2byte ITEM_NONE

	.align 2
SelenicBadgeEight:
	.2byte ITEM_LABRADORITE_CHUNK
	.2byte ITEM_CARNELIAN_CHUNK
	.2byte ITEM_AQUAMARINE_CHUNK
	.2byte ITEM_PREHNITE_CHUNK
	.2byte ITEM_CITRINE_CHUNK
	.2byte ITEM_TOPAZ_CHUNK
	.2byte ITEM_DEMORTIURITE_CHUNK
	.2byte ITEM_MALACHITE_CHUNK
	.2byte ITEM_AMETHYST_CHUNK
	.2byte ITEM_THULITE_CHUNK
	.2byte ITEM_PIYRITE_CHUNK
	.2byte ITEM_TOURMALINE_CHUNK
	.2byte ITEM_RHODOCHROSITE_CHUNK
	.2byte ITEM_OBSIDIAN_CHUNK
	.2byte ITEM_NONE

	.align 2
SelenicChampion:
	.2byte ITEM_LABRADORITE_CHUNK
	.2byte ITEM_CARNELIAN_CHUNK
	.2byte ITEM_AQUAMARINE_CHUNK
	.2byte ITEM_GHOUL_STONE
	.2byte ITEM_ALTERNATE_STONE
	.2byte ITEM_PREHNITE_CHUNK
	.2byte ITEM_CITRINE_CHUNK
	.2byte ITEM_TOPAZ_CHUNK
	.2byte ITEM_DEMORTIURITE_CHUNK
	.2byte ITEM_MALACHITE_CHUNK
	.2byte ITEM_AMETHYST_CHUNK
	.2byte ITEM_THULITE_CHUNK
	.2byte ITEM_PIYRITE_CHUNK
	.2byte ITEM_TOURMALINE_CHUNK
	.2byte ITEM_RHODOCHROSITE_CHUNK
	.2byte ITEM_OBSIDIAN_CHUNK
	.2byte ITEM_OPAL_CHUNK
	.2byte ITEM_NONE

	.align 2
SelenicDeoxys:
	.2byte ITEM_LABRADORITE_CHUNK
	.2byte ITEM_CARNELIAN_CHUNK
	.2byte ITEM_AQUAMARINE_CHUNK
	.2byte ITEM_GHOUL_STONE
	.2byte ITEM_ALTERNATE_STONE
	.2byte ITEM_PREHNITE_CHUNK
	.2byte ITEM_CITRINE_CHUNK
	.2byte ITEM_TOPAZ_CHUNK
	.2byte ITEM_DEMORTIURITE_CHUNK
	.2byte ITEM_MALACHITE_CHUNK
	.2byte ITEM_AMETHYST_CHUNK
	.2byte ITEM_THULITE_CHUNK
	.2byte ITEM_PIYRITE_CHUNK
	.2byte ITEM_TOURMALINE_CHUNK
	.2byte ITEM_RHODOCHROSITE_CHUNK
	.2byte ITEM_OBSIDIAN_CHUNK
	.2byte ITEM_OPAL_CHUNK
	.2byte ITEM_METEORITE_CHUNK
	.2byte ITEM_NONE

SelenicPokeNavCall::
	lockall
	switch VAR_SELENIC_CALLS
	case 2, SelenicPokeNavCall_3
	case 3, SelenicPokeNavCall_4
	case 4, SelenicPokeNavCall_5
	case 5, SelenicPokeNavCall_6
	case 6, SelenicPokeNavCall_7
	case 7, SelenicPokeNavCall_8
	case 8, SelenicPokeNavCall_9
	case 9, SelenicPokeNavCall_10
	case 10, SelenicPokeNavCall_11
	case 11, SelenicPokeNavCall_12
SelenicPokeNavCall_1:
	compare VAR_SELENIC_CALLS, 5
	goto_if_eq SelenicPokeNavCall_14
	pokenavcall SelenicPokeNavCall_Text
SelenicPokeNavCall_13:
	setvar VAR_SELENIC_CALLS, 0
	waitmessage
	releaseall
	return

SelenicPokeNavCall_3:
	bufferitemname STR_VAR_1, ITEM_MALACHITE_CHUNK
	compare VAR_SELENIC_MARTS, 2
	goto_if_le SelenicPokeNavCall_17
	goto SelenicPokeNavCall_1

SelenicPokeNavCall_4:
	bufferitemname STR_VAR_1, ITEM_AMETHYST_CHUNK
	compare VAR_SELENIC_MARTS, 3
	goto_if_le SelenicPokeNavCall_19
	goto SelenicPokeNavCall_1

SelenicPokeNavCall_5:
	bufferitemname STR_VAR_1, ITEM_THULITE_CHUNK
	compare VAR_SELENIC_MARTS, 4
	goto_if_le SelenicPokeNavCall_21
	goto SelenicPokeNavCall_1

SelenicPokeNavCall_6:
	bufferitemname STR_VAR_1, ITEM_PIYRITE_CHUNK
	compare VAR_SELENIC_MARTS, 5
	goto_if_le SelenicPokeNavCall_23
	goto SelenicPokeNavCall_1

SelenicPokeNavCall_7:
	bufferitemname STR_VAR_1, ITEM_TOURMALINE_CHUNK
	compare VAR_SELENIC_MARTS, 6
	goto_if_le SelenicPokeNavCall_25
	goto SelenicPokeNavCall_1

SelenicPokeNavCall_8:
	bufferitemname STR_VAR_1, ITEM_CARNELIAN_CHUNK
	compare VAR_SELENIC_MARTS, 7
	goto_if_le SelenicPokeNavCall_27
	goto SelenicPokeNavCall_1

SelenicPokeNavCall_9:
	bufferitemname STR_VAR_1, ITEM_RHODOCHROSITE_CHUNK
	compare VAR_SELENIC_MARTS, 8
	goto_if_le SelenicPokeNavCall_29
	goto SelenicPokeNavCall_1

SelenicPokeNavCall_10:
	bufferitemname STR_VAR_1, ITEM_AQUAMARINE_CHUNK
	compare VAR_SELENIC_MARTS, 9
	goto_if_le SelenicPokeNavCall_31
	goto SelenicPokeNavCall_1

SelenicPokeNavCall_11:
	bufferitemname STR_VAR_1, ITEM_OBSIDIAN_CHUNK
	compare VAR_SELENIC_MARTS, 10
	goto_if_le SelenicPokeNavCall_33
	goto SelenicPokeNavCall_1

SelenicPokeNavCall_12:
	bufferitemname STR_VAR_1, ITEM_OPAL_CHUNK
	compare VAR_SELENIC_MARTS, 11
	goto_if_le SelenicPokeNavCall_35
	goto SelenicPokeNavCall_1

SelenicPokeNavCall_14:
	pokenavcall SelenicPokeNavCallHomely_Text
	goto SelenicPokeNavCall_13

SelenicPokeNavCall_17:
	setvar VAR_SELENIC_MARTS, 3
	goto SelenicPokeNavCall_1

SelenicPokeNavCall_19:
	setvar VAR_SELENIC_MARTS, 4
	goto SelenicPokeNavCall_1

SelenicPokeNavCall_21:
	setvar VAR_SELENIC_MARTS, 5
	goto SelenicPokeNavCall_1

SelenicPokeNavCall_23:
	setvar VAR_SELENIC_MARTS, 6
	goto SelenicPokeNavCall_1

SelenicPokeNavCall_25:
	setvar VAR_SELENIC_MARTS, 7
	goto SelenicPokeNavCall_1

SelenicPokeNavCall_27:
	setvar VAR_SELENIC_MARTS, 8
	goto SelenicPokeNavCall_1

SelenicPokeNavCall_29:
	setvar VAR_SELENIC_MARTS, 9
	goto SelenicPokeNavCall_1

SelenicPokeNavCall_31:
	setvar VAR_SELENIC_MARTS, 10
	goto SelenicPokeNavCall_1

SelenicPokeNavCall_33:
	setvar VAR_SELENIC_MARTS, 11
	goto SelenicPokeNavCall_1

SelenicPokeNavCall_35:
	setvar VAR_SELENIC_MARTS, 12
	goto SelenicPokeNavCall_1


SelenicSpirit_MovingBoxes_Text_0:
	.string "It's a box full of things for SELENIC,\n"
	.string "there is quite a lot to unpack.$"

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
	.string "sourced by DEVON CORP. in the PASSAGE.\l"
	.string "We'll update you when they arrive.\p"
	.string "Actually {PLAYER}, as you're here, can\n"
	.string "you give me a hand with these boxes?$"

SelenicSpirit_EventScript_ShopClerk_Text_5:
	.string "Thank you, that's much better.\n"
	.string "Have a splendid day, {PLAYER}!$"

SelenicSpirit_EventScript_ShopClerk_Text_6:
	.string "Welcome to SELENIC SPIRIT.\n"
	.string "We're not currently open.\l"
	.string "Sadly we'll be closed during the DEMO.$"

SelenicSpirit_EventScript_ShopClerk_Text_7:
	.string "Welcome to SELENIC SPIRIT.\n"
	.string "We're not currently open-\l"
	.string "Wait, you're {PLAYER}!\p"
	.string "Well if your MOM is the owner,\n"
	.string "I can hardly send you away.$"

SelenicSpirit_EventScript_ShopClerk_Text_8:
	.string "How can I help you today, {PLAYER}?$"

SelenicSpirit_EventScript_ShopClerk_Text_9:
	.string "Have a splendid day, {PLAYER}!\n"
	.string "We'll see you soon.$"

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

SelenicSpirit_EventScript_Steven_Text_0:
	.string "STEVEN: Well hello {PLAYER}!\p"
	.string "I decided to come and visit this store\n"
	.string "as I love collecting rare stones.\l"
	.string "I guess it's in the name!\p"
	.string "I didn't realise your MOM owned it!\n"
	.string "A very nice coincidence.\p"
	.string "It seems to be doing well, even with old\n"
	.string "TEAM AQUA and MAGMA GRUNTS enjoying\l"
	.string "it.\p"
	.string "I shouldn't be surprised, it seems like\n"
	.string "you learned from the best about\l"
	.string "keeping peace in the HOENN region!$"

SelenicSpirit_EventScript_Aqua_Text_0:
	.string "I was recommended some AQUAMARINE by\n"
	.string "the owner. Now I can't see why ARCHIE\l"
	.string "ever had us going after CARNELIAN.$"

SelenicSpirit_EventScript_Magma_Text_0:
	.string "I was recommended some CARNELIAN by\n"
	.string "the owner. Now I can't see why MAXIE\l"
	.string "ever had us going after AQUAMARINE.$"

SelenicSpirit_EventScript_Man_Text_0:
	.string "Have you seen these unique pieces?\n"
	.string "Stunning craftswomanship!$"

SelenicSpirit_EventScript_Man2_Text_0:
	.string "This place is a treasure trove of\n"
	.string "beautiful finds!$"

SelenicSpirit_EventScript_Woman2_Text_0:
	.string "Every item here feels so special and\n"
	.string "one-of-a-kind.$"

SelenicSpirit_EventScript_Woman3_Text_0:
	.string "I'm so inspired by all the beautiful\n"
	.string "things here!$"

SelenicSpirit_ChooseMart_Text_0:
	.string "Wow {PLAYER}!\n"
	.string "What's that you have there?\p"
	.string "A METEORITE? Where did you get that?\n"
	.string "Well it must be extremely rare!\p"
	.string "I'd love to take that off of your hands,\n"
	.string "but I know your MOM would never let me.\p"
	.string "I'm sure we're not the only collectors\n"
	.string "who would love to get our hands on it,\l"
	.string "even PROFESSORS to examine it fully.\p"
	.string "Anyway, {PLAYER}.\n"
	.string "How can I help you today?$"

SelenicSpirit_ChooseMart_Text_1:
	.string "Hello again, {PLAYER}!\nHow can I help you today?$"

SelenicSpirit_ChooseMart_Text_2:
	.string "Have a splendid day, {PLAYER}!\n"
	.string "We'll see you again soon.$"

SelenicPokeNavCall_Text::
	.string "MOM: Hey {PLAYER}, how are you doing?\p"
	.string "I wanted to let you know about\n"
	.string "some new stuff back at SELENIC!\l"
	.string "We got some new stock!\p"
	.string "That's right, we're now selling\n"
	.string "{STR_VAR_1}!\l"
	.string "Come and check it out!$"

SelenicPokeNavCallHomely_Text::
	.string "MOM: Hey {PLAYER}, before I forget…\p"
	.string "I wanted to let you know about\n"
	.string "some new stuff back at SELENIC!\l"
	.string "We got some new stock!\p"
	.string "That's right, we're now selling\n"
	.string "{STR_VAR_1}!\p"
	.string "Come and check it out!$"
