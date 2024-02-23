Debug_ShowFieldMessageStringVar4::
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	releaseall
	end

Debug_CheckWeekDay_Text:
	.string "Aaaaah, yes!\l"
	.string "{STR_VAR_1}s are made for dads!\l"
	.string "And dad's car!$"

Debug_MiniCheat::
	givemon SPECIES_SINISTEA, 20, ITEM_NONE
	givemon SPECIES_CHARCADET, 20, ITEM_NONE
	givemon SPECIES_BASULIN, 20, ITEM_NONE
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	setflag FLAG_HIDE_ROUTE_101_ZIGZAGOON
	clearflag FLAG_HIDE_BOREA_GLADE_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	setflag FLAG_RESCUED_BIRCH
	setvar VAR_BOREA_GLADE_STATE, 2
	setvar VAR_BIRCH_LAB_STATE, 2
	setvar VAR_ROUTE101_STATE, 3
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route101_EventScript_HideMayInBedroom
	call_if_eq VAR_RESULT, FEMALE, Route101_EventScript_HideBrendanInBedroom
	return

Debug_CheatStart::
	lockall
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_RESCUED_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	clearflag FLAG_HIDE_BOREA_GLADE_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	setvar VAR_BIRCH_LAB_STATE, 2
	setvar VAR_ROUTE101_STATE, 3
	givemon SPECIES_SINISTEA, 20, ITEM_NONE
	givemon SPECIES_CHARCADET, 20, ITEM_NONE
	givemon SPECIES_BASULIN, 20, ITEM_NONE
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	@ setflag FLAG_SYS_NATIONAL_DEX
	@ special EnableNationalPokedex
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH
	setvar VAR_BOREA_GLADE_STATE, 4 @ 4: Received Running Shoes
	setvar VAR_LITTLEROOT_INTRO_STATE, 7 @ 7: Told to go meet rival
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 2 @ 2: Met Rival's Mom (and is corresponding gender)
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2 @ 2: Met Rival's Mom (and is corresponding gender)
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4 @ 4: Received Pokedex
	setflag FLAG_RECEIVED_BIKE
	giveitem ITEM_ACRO_BIKE
	setvar VAR_BRINEY_HOUSE_STATE, 1
	setvar VAR_ROUTE116_STATE, 2
	setflag FLAG_HIDE_ROUTE_116_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	@ additem ITEM_MAX_REPEL, 10
	@ giveitem ITEM_EON_TICKET
	@ setflag FLAG_SYS_HAS_EON_TICKET
	@ setvar VAR_DISTRIBUTE_EON_TICKET, 0
	@ giveitem ITEM_MYSTIC_TICKET
	@ setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	@ setflag FLAG_RECEIVED_MYSTIC_TICKET
	@ giveitem ITEM_AURORA_TICKET
	@ setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	@ setflag FLAG_RECEIVED_AURORA_TICKET
	@ setflag FLAG_BADGE06_GET @ Badge for flying filed move
	@ setweather WEATHER_VOLCANIC_ASH
	@ doweather
	closemessage
	releaseall
	end

Debug_Script_1::
	givemon SPECIES_MUNCHLAX, 20, ITEM_NONE
	givemon SPECIES_SNORLAX, 20, ITEM_NONE
	givemon SPECIES_RAYQUAZA, 20, ITEM_LEFTOVERS
	giveitem ITEM_MASTER_BALL, 99
	msgbox DebugText, MSGBOX_NPC
	end

Debug_Script_2::
	end

Debug_Script_3::
	end

Debug_Script_4::
	end

Debug_Script_5::
	end

Debug_Script_6::
	end

Debug_Script_7::
	end

Debug_Script_8::
	end

DebugText:
	.string "Hello {PLAYER}! I am the DEBUG MAN.\p"
	.string "DEBUG MAN: I've just run your\n"
	.string "DEBUG Script.$"

DebugMan::
	lockall
	faceplayer
	setvar VAR_TEMP_D, 0
	msgbox DebugMan_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq DebugMan_1
	goto Debug_CheatStart
	return

DebugMan_1:
	goto ChooseCustomDebug
	return


ChooseCustomDebug::
	switch VAR_TEMP_D
	case 0, ChooseCustomDebug_3
	case 1, ChooseCustomDebug_4
	case 2, ChooseCustomDebug_5
	case 3, ChooseCustomDebug_6
	case 4, ChooseCustomDebug_7
	msgbox ChooseCustomDebug_Text_0, MSGBOX_NPC
	releaseall
	return

ChooseCustomDebug_3:
	msgbox ChooseCustomDebug_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq ChooseCustomDebug_8
	goto CustomDebug1
	return

ChooseCustomDebug_4:
	msgbox ChooseCustomDebug_Text_2, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq ChooseCustomDebug_11
	goto CustomDebug2
	return

ChooseCustomDebug_5:
	msgbox ChooseCustomDebug_Text_3, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq ChooseCustomDebug_14
	goto CustomDebug3
	return

ChooseCustomDebug_6:
	msgbox ChooseCustomDebug_Text_4, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq ChooseCustomDebug_17
	goto CustomDebug4
	return

ChooseCustomDebug_7:
	msgbox ChooseCustomDebug_Text_5, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq ChooseCustomDebug_20
	goto CustomDebug5
	return

ChooseCustomDebug_8:
	addvar VAR_TEMP_D, 1
	goto ChooseCustomDebug
	return

ChooseCustomDebug_11:
	addvar VAR_TEMP_D, 1
	goto ChooseCustomDebug
	return

ChooseCustomDebug_14:
	addvar VAR_TEMP_D, 1
	goto ChooseCustomDebug
	return

ChooseCustomDebug_17:
	addvar VAR_TEMP_D, 1
	goto ChooseCustomDebug
	return

ChooseCustomDebug_20:
	addvar VAR_TEMP_D, 1
	goto ChooseCustomDebug
	return


CustomDebug1::
	call Debug_MiniCheat
	msgbox CustomDebug1_Text_0, MSGBOX_NPC
	releaseall
	return


CustomDebug2::
	giveitem ITEM_INFERNAPE_POKEBALL, 1
	giveitem ITEM_DIANCIE_POKEBALL, 1
	msgbox CustomDebug1_Text_0, MSGBOX_NPC
	releaseall
	return


CustomDebug3::
	msgbox CustomDebug1_Text_0, MSGBOX_NPC
	releaseall
	return


CustomDebug4::
	msgbox CustomDebug1_Text_0, MSGBOX_NPC
	releaseall
	return


CustomDebug5::
	msgbox CustomDebug1_Text_0, MSGBOX_NPC
	releaseall
	return


DebugMan_Text_0:
	.string "Hello {PLAYER}!\n"
	.string "I am the DEBUG MAN.\l"
	.string "Would you like to run the {COLOR RED}DEBUG CHEATS{COLOR DARK_GRAY}?$"

ChooseCustomDebug_Text_0:
	.string "No more {COLOR RED}custom debug scripts{COLOR DARK_GRAY} written.$"

ChooseCustomDebug_Text_1:
	.string "Would you like to run {COLOR RED}Custom Debug 1{COLOR DARK_GRAY}?$"

ChooseCustomDebug_Text_2:
	.string "Would you like to run {COLOR RED}Custom Debug 2{COLOR DARK_GRAY}?$"

ChooseCustomDebug_Text_3:
	.string "Would you like to run {COLOR RED}Custom Debug 3{COLOR DARK_GRAY}?$"

ChooseCustomDebug_Text_4:
	.string "Would you like to run {COLOR RED}Custom Debug 4{COLOR DARK_GRAY}?$"

ChooseCustomDebug_Text_5:
	.string "Would you like to run {COLOR RED}Custom Debug 5{COLOR DARK_GRAY}?$"

CustomDebug1_Text_0:
	.string "Custom Debug {COLOR GREEN}Complete{COLOR DARK_GRAY}.$"
