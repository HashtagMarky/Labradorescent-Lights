BeginTeaser_TeaserOne::
	gettime
	initclock 19, 00
	setvar VAR_RESULT, 1
	warpsilent MAP_BOREA_GLADE_TEASER, 6, 19
	waitstate
	releaseall
	return


BeginTeaser_TeaserTwo::
	gettime
	setvar VAR_RESULT, 2
	warpsilent MAP_SELENIC_SPIRIT_TEASER, 6, 6
	waitstate
	releaseall
	return


FaceUp:
	face_up
	step_end

FaceDown:
	face_down
	step_end

FaceLeft:
	face_left
	step_end

FaceRight:
	face_right
	step_end

WalkUp:
	walk_up
	step_end

WalkDown:
	walk_down
	step_end

WalkLeft:
	walk_left
	step_end

WalkRight:
	walk_right
	step_end

Invisible:
	set_invisible
	step_end

Visible:
	set_visible
	step_end

JumpIPUp:
	jump_in_place_up
	step_end

JumpIPDown:
	jump_in_place_down
	step_end

JumpIPLeft:
	jump_in_place_left
	step_end

JumpIPRight:
	jump_in_place_right
	step_end

TruckFacingDirection::
	applymovement OBJ_EVENT_ID_PLAYER, FaceRight
	return


PlayerReturnToLastPosition::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	compare VAR_RESULT, DIR_NORTH
	goto_if_eq PlayerReturnToLastPosition_1
	compare VAR_RESULT, DIR_EAST
	goto_if_eq PlayerReturnToLastPosition_2
	compare VAR_RESULT, DIR_SOUTH
	goto_if_eq PlayerReturnToLastPosition_3
	compare VAR_RESULT, DIR_WEST
	goto_if_eq PlayerReturnToLastPosition_4
	return

PlayerReturnToLastPosition_1:
	applymovement OBJ_EVENT_ID_PLAYER, WalkDown
	waitmovement 0
	return

PlayerReturnToLastPosition_2:
	applymovement OBJ_EVENT_ID_PLAYER, WalkLeft
	waitmovement 0
	return

PlayerReturnToLastPosition_3:
	applymovement OBJ_EVENT_ID_PLAYER, WalkUp
	waitmovement 0
	return

PlayerReturnToLastPosition_4:
	applymovement OBJ_EVENT_ID_PLAYER, WalkRight
	waitmovement 0
	return


DaySkip::
	callnative RtcAdvanceTimeOneDay
	dotimebasedevents
	call EverGrandeCity_HallOfFame_EventScript_ResetDefeatedEventLegendaries
	return


MorningSleep::
	gettime
	initclock 9, 00
	compare VAR_0x8000, 9
	goto_if_ge MorningSleep_1
	return

MorningSleep_1:
	call DaySkip
	return


AfternoonSleep::
	gettime
	initclock 13, 00
	compare VAR_0x8000, 13
	goto_if_ge AfternoonSleep_1
	return

AfternoonSleep_1:
	call DaySkip
	return


EveningSleep::
	gettime
	initclock 17, 00
	compare VAR_0x8000, 17
	goto_if_ge EveningSleep_1
	return

EveningSleep_1:
	call DaySkip
	return


NightSleep::
	gettime
	initclock 21, 00
	compare VAR_0x8000, 21
	goto_if_ge NightSleep_1
	return

NightSleep_1:
	call DaySkip
	return


Exclaim:
	emote_exclamation_mark
	step_end

Question:
	emote_question_mark
	step_end

Heart:
	emote_heart
	step_end

Talk:
	step_end

Think:
	step_end

DemoBegin::
	lock
	msgbox DemoBegin_Text_0, MSGBOX_DEFAULT
	closemessage
	release
	return


DemoEnd::
	lockall
	fadenewbgm MUS_DP_POKEMON_LEAGUE_NIGHT
	delay 30
	closemessage
	delay 30
	msgbox DemoEnd_Text_0, MSGBOX_DEFAULT
	waitmessage
	delay 30
	fadescreen FADE_TO_WHITE
	delay 60
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, WalkDown
	waitmovement 0
	msgbox DemoEnd_Text_1, MSGBOX_DEFAULT
	waitmessage
	closemessage
	fadeoutbgm 4
	special DoSoftReset
	return


CountBadges::
	setvar VAR_RESULT, 0
	goto_if_set FLAG_BADGE01_GET, CountBadges_2
CountBadges_1:
	goto_if_set FLAG_BADGE02_GET, CountBadges_5
CountBadges_4:
	goto_if_set FLAG_BADGE03_GET, CountBadges_8
CountBadges_7:
	goto_if_set FLAG_BADGE04_GET, CountBadges_11
CountBadges_10:
	goto_if_set FLAG_BADGE05_GET, CountBadges_14
CountBadges_13:
	goto_if_set FLAG_BADGE06_GET, CountBadges_17
CountBadges_16:
	goto_if_set FLAG_BADGE07_GET, CountBadges_20
CountBadges_19:
	goto_if_set FLAG_BADGE08_GET, CountBadges_23
CountBadges_22:
	goto_if_set FLAG_IS_CHAMPION, CountBadges_25
	return

CountBadges_2:
	addvar VAR_RESULT, 1
	goto CountBadges_1

CountBadges_5:
	addvar VAR_RESULT, 1
	goto CountBadges_4

CountBadges_8:
	addvar VAR_RESULT, 1
	goto CountBadges_7

CountBadges_11:
	addvar VAR_RESULT, 1
	goto CountBadges_10

CountBadges_14:
	addvar VAR_RESULT, 1
	goto CountBadges_13

CountBadges_17:
	addvar VAR_RESULT, 1
	goto CountBadges_16

CountBadges_20:
	addvar VAR_RESULT, 1
	goto CountBadges_19

CountBadges_23:
	addvar VAR_RESULT, 1
	goto CountBadges_22

CountBadges_25:
	addvar VAR_RESULT, 1
	return


PrintBadges::
	closemessage
	switch VAR_RESULT
	case 0, PrintBadges_3
	case 1, PrintBadges_4
	case 2, PrintBadges_5
	case 3, PrintBadges_6
	case 4, PrintBadges_7
	case 5, PrintBadges_8
	case 6, PrintBadges_9
	case 7, PrintBadges_10
	case 8, PrintBadges_11
	case 9, PrintBadges_12
	msgbox PrintBadges_Text_10, MSGBOX_NPC
PrintBadges_1:
	closemessage
	releaseall
	return

PrintBadges_3:
	msgbox PrintBadges_Text_0, MSGBOX_NPC
	goto PrintBadges_1

PrintBadges_4:
	msgbox PrintBadges_Text_1, MSGBOX_NPC
	goto PrintBadges_1

PrintBadges_5:
	msgbox PrintBadges_Text_2, MSGBOX_NPC
	goto PrintBadges_1

PrintBadges_6:
	msgbox PrintBadges_Text_3, MSGBOX_NPC
	goto PrintBadges_1

PrintBadges_7:
	msgbox PrintBadges_Text_4, MSGBOX_NPC
	goto PrintBadges_1

PrintBadges_8:
	msgbox PrintBadges_Text_5, MSGBOX_NPC
	goto PrintBadges_1

PrintBadges_9:
	msgbox PrintBadges_Text_6, MSGBOX_NPC
	goto PrintBadges_1

PrintBadges_10:
	msgbox PrintBadges_Text_7, MSGBOX_NPC
	goto PrintBadges_1

PrintBadges_11:
	msgbox PrintBadges_Text_8, MSGBOX_NPC
	goto PrintBadges_1

PrintBadges_12:
	msgbox PrintBadges_Text_9, MSGBOX_NPC
	goto PrintBadges_1


SetKantoCaught::
	setvar VAR_TEMP_A, SPECIES_BULBASAUR
SetKantoCaught_2:
	compare VAR_TEMP_A, SPECIES_MEW
	goto_if_le SetKantoCaught_3
	setcaughtmon SPECIES_MUNCHLAX
	return

SetKantoCaught_3:
	setcaughtmonvar VAR_TEMP_A
	addvar VAR_TEMP_A, 1
	goto SetKantoCaught_2


SetAllCaught::
	setvar VAR_TEMP_A, ( SPECIES_NONE + 1 )
SetAllCaught_1:
	compare VAR_TEMP_A, NUM_SPECIES
	goto_if_le SetAllCaught_2
	return

SetAllCaught_2:
	setcaughtmonvar VAR_TEMP_A
	addvar VAR_TEMP_A, 1
	goto SetAllCaught_1


SetStartersSeen::
	setseenmon SPECIES_SINISTEA
	setseenmon SPECIES_CHARCADET
	setseenmon SPECIES_BASULIN
	return


LabLights_StartEasyMode::
	msgbox LabLights_StartEasyMode_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LabLights_StartEasyMode_1
	msgbox LabLights_StartEasyMode_Text_5, MSGBOX_DEFAULT
	return

LabLights_StartEasyMode_1:
	setflag FLAG_SYS_GAMEMODE_EASY
	msgbox LabLights_StartEasyMode_Text_1, MSGBOX_DEFAULT
	giveitem ITEM_TRAINING_KIT
	msgbox LabLights_StartEasyMode_Text_2, MSGBOX_DEFAULT
	giveitem ITEM_UNLIMITED_REPEL
	msgbox LabLights_StartEasyMode_Text_3, MSGBOX_DEFAULT
	giveitem ITEM_HOF_MEDAL
	msgbox LabLights_StartEasyMode_Text_4, MSGBOX_DEFAULT
	return


LabLights_ToggleEasyMode::
	questmenu QUEST_MENU_CHECK_COMPLETE, ADVENTURE_BEGINS
	compare VAR_RESULT, TRUE
	goto_if_eq LabLights_ToggleEasyMode_1
	return

LabLights_ToggleEasyMode_1:
	goto_if_set FLAG_SYS_GAMEMODE_EASY, LabLights_ToggleEasyMode_4
	msgbox LabLights_ToggleEasyMode_Text_1, MSGBOX_YESNO
LabLights_ToggleEasyMode_3:
	compare VAR_RESULT, YES
	goto_if_eq LabLights_ToggleEasyMode_8
	msgbox LabLights_ToggleEasyMode_Text_3, MSGBOX_DEFAULT
	clearflag FLAG_SYS_GAMEMODE_EASY
	clearflag FLAG_SYS_NO_ENCOUNTER
	clearflag FLAG_SYS_NO_TRAINER_SEE
	checkitem ITEM_TRAINING_KIT
	compare VAR_RESULT, TRUE
	goto_if_eq LabLights_ToggleEasyMode_15
LabLights_ToggleEasyMode_14:
	checkitem ITEM_UNLIMITED_REPEL
	compare VAR_RESULT, TRUE
	goto_if_eq LabLights_ToggleEasyMode_21
LabLights_ToggleEasyMode_20:
	checkitem ITEM_HOF_MEDAL
	compare VAR_RESULT, TRUE
	goto_if_eq LabLights_ToggleEasyMode_27
LabLights_ToggleEasyMode_26:
	msgbox LabLights_ToggleEasyMode_Text_4, MSGBOX_DEFAULT
	closemessage
	delay 20
	msgbox LabLights_ToggleEasyMode_Text_5, MSGBOX_DEFAULT
	closemessage
	delay 20
	msgbox LabLights_ToggleEasyMode_Text_6, MSGBOX_DEFAULT
	closemessage
LabLights_ToggleEasyMode_7:
	delay 20
	return

LabLights_ToggleEasyMode_4:
	msgbox LabLights_ToggleEasyMode_Text_0, MSGBOX_YESNO
	goto LabLights_ToggleEasyMode_3

LabLights_ToggleEasyMode_8:
	msgbox LabLights_ToggleEasyMode_Text_2, MSGBOX_DEFAULT
	setflag FLAG_SYS_GAMEMODE_EASY
	clearflag FLAG_SYS_NO_ENCOUNTER
	clearflag FLAG_SYS_NO_TRAINER_SEE
	checkitem ITEM_TRAINING_KIT
	compare VAR_RESULT, FALSE
	goto_if_eq LabLights_ToggleEasyMode_12
LabLights_ToggleEasyMode_11:
	checkitem ITEM_UNLIMITED_REPEL
	compare VAR_RESULT, FALSE
	goto_if_eq LabLights_ToggleEasyMode_18
LabLights_ToggleEasyMode_17:
	checkitem ITEM_HOF_MEDAL
	compare VAR_RESULT, FALSE
	goto_if_eq LabLights_ToggleEasyMode_24
LabLights_ToggleEasyMode_23:
	closemessage
	goto LabLights_ToggleEasyMode_7

LabLights_ToggleEasyMode_12:
	giveitem ITEM_TRAINING_KIT
	goto LabLights_ToggleEasyMode_11

LabLights_ToggleEasyMode_15:
	removeitem ITEM_TRAINING_KIT
	goto LabLights_ToggleEasyMode_14

LabLights_ToggleEasyMode_18:
	giveitem ITEM_UNLIMITED_REPEL
	goto LabLights_ToggleEasyMode_17

LabLights_ToggleEasyMode_21:
	removeitem ITEM_UNLIMITED_REPEL
	goto LabLights_ToggleEasyMode_20

LabLights_ToggleEasyMode_24:
	giveitem ITEM_HOF_MEDAL
	goto LabLights_ToggleEasyMode_23

LabLights_ToggleEasyMode_27:
	removeitem ITEM_HOF_MEDAL
	goto LabLights_ToggleEasyMode_26


LabLights_SkipCry_Triggers::
	goto_if_set FLAG_SYS_DEMO_MODE, LabLights_SkipCry_Triggers_1
	return

LabLights_SkipCry_Triggers_1:
	setvar VAR_LAB_LIGHTS, 0
	return


LabLights_AbsolCry::
	playmoncry SPECIES_ABSOL, 0
	msgbox LabLights_AbsolCry_Text_0, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	setvar VAR_LAB_LIGHTS, 0
	delay 20
	goto_if_unset FLAG_SYS_DEMO_MODE, LabLights_AbsolCry_1
	subquestmenu QUEST_MENU_CHECK_COMPLETE, ADVENTURE_BEGINS, FIND_RIVAL
	compare VAR_RESULT, FALSE
	goto_if_eq LabLights_AbsolCry_7
	msgbox LabLights_AbsolCry_Text_2, MSGBOX_SIGN
	return

LabLights_AbsolCry_1:
	questmenu QUEST_MENU_CHECK_UNLOCKED, CALAMITY_QUEEN
	compare VAR_RESULT, FALSE
	goto_if_eq LabLights_AbsolCry_4
	msgbox LabLights_AbsolCry_Text_2, MSGBOX_SIGN
	return

LabLights_AbsolCry_4:
	msgbox LabLights_AbsolCry_Text_1, MSGBOX_SIGN
	startquest CALAMITY_QUEEN
	return

LabLights_AbsolCry_7:
	msgbox LabLights_AbsolCry_Text_1, MSGBOX_SIGN
	return


LabLights_LaprasCry::
	playmoncry SPECIES_SNORLAX, 0
	msgbox LabLights_LaprasCry_Text_0, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	setvar VAR_LAB_LIGHTS, 0
	questmenu QUEST_MENU_CHECK_UNLOCKED, TEAM_AQUA
	delay 20
	compare VAR_RESULT, FALSE
	goto_if_eq LabLights_LaprasCry_1
	return

LabLights_LaprasCry_1:
	msgbox LabLights_LaprasCry_Text_1, MSGBOX_SIGN
	return


LabLights_EventScript_MineOwner::
	compare VAR_TEMP_1, 0
	goto_if_eq LabLights_EventScript_MineOwner_1
	msgbox LabLights_EventScript_MineOwner_Text_1, MSGBOX_NPC
	return

LabLights_EventScript_MineOwner_1:
	msgbox LabLights_EventScript_MineOwner_Text_0, MSGBOX_NPC
	addvar VAR_TEMP_1, 1
	return


LabLights_PokedexCompleted::
	questmenu QUEST_MENU_CHECK_COMPLETE, POKEDEX
	compare VAR_RESULT, FALSE
	goto_if_eq LabLights_PokedexCompleted_1
	return

LabLights_PokedexCompleted_1:
	completequest POKEDEX
	return


LabLights_Slateport_AquaSubquest::
	subquestmenu QUEST_MENU_CHECK_COMPLETE, TEAM_AQUA, SLATEPORT_DRIVE_OUT
	compare VAR_RESULT, FALSE
	goto_if_eq LabLights_Slateport_AquaSubquest_1
	return

LabLights_Slateport_AquaSubquest_1:
	completesubquest TEAM_AQUA, SLATEPORT_DRIVE_OUT
	return


LabLights_ItemScript_OpenTheQuestMenu::
	openquestmenu
	releaseall
	return


LabLights_ItemScript_Repel::
	goto_if_unset FLAG_SYS_NO_ENCOUNTER, LabLights_ItemScript_Repel_2
	msgbox LabLights_ItemScript_Repel_Text_3, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LabLights_ItemScript_Repel_8
	msgbox LabLights_ItemScript_Repel_Text_5, MSGBOX_SIGN
LabLights_ItemScript_Repel_1:
	releaseall
	return

LabLights_ItemScript_Repel_2:
	msgbox LabLights_ItemScript_Repel_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LabLights_ItemScript_Repel_5
	msgbox LabLights_ItemScript_Repel_Text_2, MSGBOX_SIGN
	goto LabLights_ItemScript_Repel_1

LabLights_ItemScript_Repel_5:
	setflag FLAG_SYS_NO_ENCOUNTER
	setvar VAR_REPEL_STEP_COUNT, 0
	msgbox LabLights_ItemScript_Repel_Text_1, MSGBOX_SIGN
	goto LabLights_ItemScript_Repel_1

LabLights_ItemScript_Repel_8:
	clearflag FLAG_SYS_NO_ENCOUNTER
	msgbox LabLights_ItemScript_Repel_Text_4, MSGBOX_SIGN
	goto LabLights_ItemScript_Repel_1


LabLights_ItemScript_HoFMedal::
	goto_if_unset FLAG_SYS_NO_TRAINER_SEE, LabLights_ItemScript_HoFMedal_2
	msgbox LabLights_ItemScript_HoFMedal_Text_3, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LabLights_ItemScript_HoFMedal_8
	msgbox LabLights_ItemScript_HoFMedal_Text_4, MSGBOX_SIGN
LabLights_ItemScript_HoFMedal_1:
	releaseall
	return

LabLights_ItemScript_HoFMedal_2:
	msgbox LabLights_ItemScript_HoFMedal_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LabLights_ItemScript_HoFMedal_5
	msgbox LabLights_ItemScript_HoFMedal_Text_2, MSGBOX_SIGN
	goto LabLights_ItemScript_HoFMedal_1

LabLights_ItemScript_HoFMedal_5:
	setflag FLAG_SYS_NO_TRAINER_SEE
	msgbox LabLights_ItemScript_HoFMedal_Text_1, MSGBOX_SIGN
	goto LabLights_ItemScript_HoFMedal_1

LabLights_ItemScript_HoFMedal_8:
	clearflag FLAG_SYS_NO_TRAINER_SEE
	msgbox LabLights_ItemScript_HoFMedal_Text_2, MSGBOX_SIGN
	goto LabLights_ItemScript_HoFMedal_1


LabLights_ItemScript_InfernapePokeball::
	playmoncry SPECIES_INFERNAPE, 0
	msgbox LabLights_DadsAdvice, MSGBOX_SIGN
	releaseall
	return


LabLights_ItemScript_DianciePokeball::
	playmoncry SPECIES_DIANCIE, 0
	msgbox LabLights_DadsAdvice, MSGBOX_SIGN
	releaseall
	return


LabLights_ItemScript_LanetteLaptop::
	lock
	playse SE_PC_LOGIN
	call_if_unset FLAG_SYS_PC_LANETTE, EventScript_AccessSomeonesPC
	call_if_set FLAG_SYS_PC_LANETTE, EventScript_AccessLanettesPC
	msgbox gText_StorageSystemOpened, MSGBOX_DEFAULT
	special ShowPokemonStorageSystemPC
	waitstate
	playse SE_PC_OFF
	release
	end


DemoBegin_Text_0:
	.string "You are playing a DEMO of\n"
	.string "POKéMON LABRADORESCENT LIGHTS.\l"
	.string "This only contains the tutorial.$"

DemoEnd_Text_0:
	.string "You have now completed the DEMO of\n"
	.string "POKéMON LABRADORESCENT LIGHTS.$"

DemoEnd_Text_1:
	.string "Thank you very much for playing!\n"
	.string "Press A to return to the title screen.$"

PrintBadges_Text_0:
	.string "None$"

PrintBadges_Text_1:
	.string "One$"

PrintBadges_Text_2:
	.string "Two$"

PrintBadges_Text_3:
	.string "Three$"

PrintBadges_Text_4:
	.string "Four$"

PrintBadges_Text_5:
	.string "Five$"

PrintBadges_Text_6:
	.string "Six$"

PrintBadges_Text_7:
	.string "Seven$"

PrintBadges_Text_8:
	.string "Eight$"

PrintBadges_Text_9:
	.string "Champion$"

PrintBadges_Text_10:
	.string "Broken$"

LabLights_StartEasyMode_Text_0:
	.string "Moving is a fresh start for all of us,\n"
	.string "but I don't want to be overbearing.\p"
	.string "I can still try and make your life a\n"
	.string "little bit easier if you'd like?$"

LabLights_StartEasyMode_Text_1:
	.string "Alright my love,\n"
	.string "I'll be sure to help you out.\l"
	.string "Start by taking this.$"

LabLights_StartEasyMode_Text_2:
	.string "MOM: Your DAD gave this to me, in order\n"
	.string "to help fit POKéMON training around\l"
	.string "a busy schedule working on SELENIC.\p"
	.string "You may find it more useful now,\n"
	.string "and he also gave me something else.$"

LabLights_StartEasyMode_Text_3:
	.string "MOM: When we were first adventuring,\n"
	.string "I was anxious of wild POKéMON.\p"
	.string "This long lasting REPEL made sure\n"
	.string "that I didn't run into any POKéMON.\l"
	.string "Well, only when I didn't want to!$"

LabLights_StartEasyMode_Text_4:
	.string "MOM: Finally, he gave me this,\n"
	.string "his POKéMON HALL OF FAME MEDAL.\p"
	.string "If they got one look at this medal,\n"
	.string "TRAINERS would be too scared\l"
	.string "to challenge me.\p"
	.string "I could put it on whenever I didn't\n"
	.string "want to be disturbed.\p"
	.string "It also makes catching POKéMON a\n"
	.string "breeze!\p"
	.string "It's almost like the see the medal as\n"
	.string "a mark of respect.\l"
	.string "Anyway…$"

LabLights_StartEasyMode_Text_5:
	.string "Don't worry my love,\n"
	.string "I won't spoil your style.\l"
	.string "Anyway…$"

LabLights_ToggleEasyMode_Text_0:
	.string "MOM: You seem to be doing great honey!\n"
	.string "Would you still like to me to help out?$"

LabLights_ToggleEasyMode_Text_1:
	.string "MOM: You seem to be doing great honey!\n"
	.string "Would you like to me to help out?$"

LabLights_ToggleEasyMode_Text_2:
	.string "Of course, I'll always be here for you.$"

LabLights_ToggleEasyMode_Text_3:
	.string "Don't worry, {PLAYER}.\n"
	.string "I know you'll be amazing on your own.$"

LabLights_ToggleEasyMode_Text_4:
	.string "{PLAYER} returned DAD's\n"
	.string "TRAINING KIT to MOM.$"

LabLights_ToggleEasyMode_Text_5:
	.string "{PLAYER} returned DAD's\n"
	.string "UNLIMITED REPEL to MOM.$"

LabLights_ToggleEasyMode_Text_6:
	.string "{PLAYER} returned DAD's\n"
	.string "HALL OF FAME MEDAL to MOM.$"

LabLights_AbsolCry_Text_0:
	.string "Aurrra!$"

LabLights_AbsolCry_Text_1:
	.string "Oh?\n"
	.string "Was that a POKéMON cry?$"

LabLights_AbsolCry_Text_2:
	.string "There's that cry again,\n"
	.string "I wonder what POKéMON it was.$"

LabLights_LaprasCry_Text_0:
	.string "Burrrurrrr!$"

LabLights_LaprasCry_Text_1:
	.string "Whoa! That cry was definitely made by\n"
	.string "a different POKéMON.\p"
	.string "I wonder what it was.$"

LabLights_EventScript_MineOwner_Text_0:
	.string "On behalf of the DEVON CORPORATION,\n"
	.string "hold it right there!\p"
	.string "We're tunneling and our workers are\n"
	.string "mining LABRADORITE up ahead.\p"
	.string "I can't let anyone by.\n"
	.string "You're going to have to leave.$"

LabLights_EventScript_MineOwner_Text_1:
	.string "Didn't you hear me?\p"
	.string "We're tunneling and our workers are\n"
	.string "mining LABRADORITE up ahead.\p"
	.string "I can't let anyone by, so\n"
	.string "you're going to have to leave.$"

LabLights_ItemScript_Repel_Text_0:
	.string "Would you like to apply\n"
	.string "DAD's UNLIMITED REPEL?$"

LabLights_ItemScript_Repel_Text_1:
	.string "The smell of the REPEL briefly fills\n"
	.string "the air before becoming muted.$"

LabLights_ItemScript_Repel_Text_2:
	.string "You put DAD's UNLIMITED REPEL\n"
	.string "back in your bag.$"

LabLights_ItemScript_Repel_Text_3:
	.string "Would you like to remove\n"
	.string "DAD's UNLIMITED REPEL?$"

LabLights_ItemScript_Repel_Text_4:
	.string "With a quick splash of water,\n"
	.string "you remove DAD's UNLIMITED REPEL.$"

LabLights_ItemScript_Repel_Text_5:
	.string "You leave DAD's UNLIMITED REPEL in use.$"

LabLights_ItemScript_HoFMedal_Text_0:
	.string "Would you like to put on\n"
	.string "DAD's HALL OF FAME MEDAL?$"

LabLights_ItemScript_HoFMedal_Text_1:
	.string "You pin DAD's HALL OF FAME MEDAL\n"
	.string "to your clothes.$"

LabLights_ItemScript_HoFMedal_Text_2:
	.string "You put DAD's HALL OF FAME MEDAL\n"
	.string "back in your bag.$"

LabLights_ItemScript_HoFMedal_Text_3:
	.string "Would you like to remove\n"
	.string "DAD's HALL OF FAME MEDAL?$"

LabLights_ItemScript_HoFMedal_Text_4:
	.string "You leave DAD's HALL OF FAME MEDAL\n"
	.string "pinned to your clothes.$"

LabLights_DadsAdvice::
	.string "MOM & DAD's advice echoed…\n"
	.string "“{PLAYER}, there's a time and place for\l"
	.string "everything!”$"
