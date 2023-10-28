.set LOCALID_BIRCH, 1
.set LOCALID_RIVAL, 2
.set LOCALID_LEAF, 3
.set LOCALID_BLUE, 4
.set LOCALID_AIDE, 5
.set LOCALID_BALL_TREECKO, 6
.set LOCALID_BALL_TORCHIC, 7
.set LOCALID_BALL_MUDKIP, 8


	@ State descriptions for VAR_BIRCH_LAB_STATE
	@ 1: Never occurs
	@ 2: Chose starter
	@ 3: Received starter in lab
	@ 4: Defeated rival on Route 103
	@ 5: Received pokedex

	@ State descriptions for VAR_POSTGAME_BIRCH_GIFT
	@ 1: Beat Elite 4 for the first time
	@ 2: Ignatius presents starters
	@ 3: Chose a new Hoenn starter
	@ 4: Awaiting Scott's call
	@ 5: Re-enabled Starter gift (will loop back to 2)


BoreaGlade_ProfessorBirchsLab_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BoreaGlade_ProfessorBirchsLab_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BoreaGlade_ProfessorBirchsLab_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BoreaGlade_ProfessorBirchsLab_OnFrame
	.byte 0


BoreaGlade_ProfessorBirchsLab_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	call ProfBirch_EventScript_UpdateLocation
	goto_if_ge VAR_POSTGAME_BIRCH_GIFT, 1, BoreaGlade_ProfessorBirchsLab_EventScript_SetPostgameLayout
	end

BoreaGlade_ProfessorBirchsLab_OnFrame:
	map_script_2 VAR_BIRCH_LAB_STATE, 2, BoreaGlade_ProfessorBirchsLab_EventScript_GiveStarterEvent
	map_script_2 VAR_BIRCH_LAB_STATE, 4, BoreaGlade_ProfessorBirchsLab_EventScript_GivePokedexEvent
	map_script_2 VAR_POSTGAME_BIRCH_GIFT, 1, BoreaGlade_ProfessorBirchsLab_EventScript_ChooseHoennStarter
	.2byte 0

BoreaGlade_ProfessorBirchsLab_OnWarp:
	map_script_2 VAR_BIRCH_LAB_STATE, 2, BoreaGlade_ProfessorBirchsLab_EventScript_SetPlayerPosForReceiveStarter
	map_script_2 VAR_POSTGAME_BIRCH_GIFT, 1, BoreaGlade_ProfessorBirchsLab_EventScript_SetPostgamePositions
	map_script_2 VAR_POSTGAME_BIRCH_GIFT, 2, BoreaGlade_ProfessorBirchsLab_EventScript_SetPostgamePositions
	map_script_2 VAR_POSTGAME_BIRCH_GIFT, 5, BoreaGlade_ProfessorBirchsLab_EventScript_SetPostgamePositions
	.2byte 0

@POSTGAME
BoreaGlade_ProfessorBirchsLab_EventScript_SetPostgameLayout::
	setmaplayoutindex LAYOUT_BOREA_GLADE_PROFESSOR_BIRCHS_LAB_WITH_TABLE
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectxyperm LOCALID_RIVAL, 5, 8
	end

BoreaGlade_ProfessorBirchsLab_EventScript_SetPostgamePositions::
	addobject LOCALID_BALL_TREECKO
	turnobject LOCALID_BALL_TREECKO, DIR_SOUTH
	setobjectxy LOCALID_BALL_TREECKO, 8, 4
	addobject LOCALID_BALL_TORCHIC
	turnobject LOCALID_BALL_TORCHIC, DIR_SOUTH
	setobjectxy LOCALID_BALL_TORCHIC, 9, 4
	addobject LOCALID_BALL_MUDKIP
	turnobject LOCALID_BALL_MUDKIP, DIR_SOUTH
	setobjectxy LOCALID_BALL_MUDKIP, 10, 4
	turnobject LOCALID_BIRCH, DIR_SOUTH
	setobjectxy LOCALID_BIRCH, 6, 4
	addobject LOCALID_RIVAL
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectxyperm LOCALID_RIVAL, 5, 8
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

BoreaGlade_ProfessorBirchsLab_EventScript_ChooseHoennStarter::
	lockall
	msgbox BoreaGlade_ProfessorBirchsLab_Text_CompletedDexChoosePokemon, MSGBOX_DEFAULT
	setvar VAR_POSTGAME_BIRCH_GIFT, 2
	releaseall
	end

BoreaGlade_ProfessorBirchsLab_Text_CompletedDexChoosePokemon:
	.string "PROF. IGNATIUS: {PLAYER}{KUN}!\p"
	.string "You've come a long way since that\n"
	.string "day you saved me on ROUTE 101.\p"
	.string "You didn't have a POKéMON of your\n"
	.string "own, and now you are the CHAMPION!\p"
	.string "That's more than just impressive.\p"
	.string "I have a gift for you.\p"
	.string "Consider it my show of appreciation\n"
	.string "for the fantastic work you've done.\p"
	.string "My gift is another rare POKéMON that I\n"
	.string "found during my fieldwork!\p"
	.string "You can have any one of these\n"
	.string "three POKéMON!$"


BoreaGlade_ProfessorBirchsLab_EventScript_Treecko::
	release
	goto_if_ge VAR_POSTGAME_BIRCH_GIFT, 3, BoreaGlade_ProfessorBirchsLab_EventScript_AlreadyChoseGift
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	showmonpic SPECIES_TREECKO, 10, 3
	msgbox BoreaGlade_ProfessorBirchsLab_Text_YoullTakeTreecko, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BoreaGlade_ProfessorBirchsLab_EventScript_TakeYourTime
	goto BoreaGlade_ProfessorBirchsLab_EventScript_GiveTreecko
	end

BoreaGlade_ProfessorBirchsLab_Text_YoullTakeTreecko:
	.string "PROF. IGNATIUS: The GRASS POKéMON\n"
	.string "TREECKO caught your eye!\p"
	.string "You're as sharp as ever!\p"
	.string "So TREECKO is your choice?$"

BoreaGlade_ProfessorBirchsLab_EventScript_GiveTreecko::
	bufferspeciesname STR_VAR_1, SPECIES_TREECKO
	setvar VAR_TEMP_1, SPECIES_TREECKO
	givemon SPECIES_TREECKO, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, BoreaGlade_ProfessorBirchsLab_EventScript_SendTreeckoToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, BoreaGlade_ProfessorBirchsLab_EventScript_SendTreeckoToPC
	hidemonpic
	goto Common_EventScript_NoMoreRoomForPokemon
	end

BoreaGlade_ProfessorBirchsLab_EventScript_SendTreeckoToParty::
	call BoreaGlade_ProfessorBirchsLab_EventScript_ReceivedPostgameGift
	removeobject LOCALID_BALL_TREECKO
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BoreaGlade_ProfessorBirchsLab_EventScript_ReceivedTreecko
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto BoreaGlade_ProfessorBirchsLab_EventScript_ReceivedTreecko
	end

BoreaGlade_ProfessorBirchsLab_EventScript_SendTreeckoToPC::
	call BoreaGlade_ProfessorBirchsLab_EventScript_ReceivedPostgameGift
	removeobject LOCALID_BALL_TREECKO
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BoreaGlade_ProfessorBirchsLab_EventScript_TreeckoTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto BoreaGlade_ProfessorBirchsLab_EventScript_TreeckoTransferredToPC
	end

BoreaGlade_ProfessorBirchsLab_EventScript_TreeckoTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto BoreaGlade_ProfessorBirchsLab_EventScript_ReceivedTreecko
	end

BoreaGlade_ProfessorBirchsLab_EventScript_ReceivedTreecko::
	hidemonpic
	msgbox BoreaGlade_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
	setvar VAR_POSTGAME_BIRCH_GIFT, 3
	setflag FLAG_DAILY_RECEIVED_BIRCH_STARTER
	releaseall
	end


BoreaGlade_ProfessorBirchsLab_EventScript_Torchic::
	release
	goto_if_ge VAR_POSTGAME_BIRCH_GIFT, 3, BoreaGlade_ProfessorBirchsLab_EventScript_AlreadyChoseGift
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	showmonpic SPECIES_TORCHIC, 10, 3
	msgbox BoreaGlade_ProfessorBirchsLab_Text_YoullTakeTorchic, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BoreaGlade_ProfessorBirchsLab_EventScript_TakeYourTime
	goto BoreaGlade_ProfessorBirchsLab_EventScript_GiveTorchic
	end

BoreaGlade_ProfessorBirchsLab_Text_YoullTakeTorchic:
	.string "PROF. IGNATIUS: The FIRE POKéMON\n"
	.string "TORCHIC is your choice!\p"
	.string "You know how to pick a good one.\p"
	.string "So, you'll take the TORCHIC?$"

BoreaGlade_ProfessorBirchsLab_EventScript_GiveTorchic::
	bufferspeciesname STR_VAR_1, SPECIES_TORCHIC
	setvar VAR_TEMP_1, SPECIES_TORCHIC
	givemon SPECIES_TORCHIC, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, BoreaGlade_ProfessorBirchsLab_EventScript_SendTorchicToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, BoreaGlade_ProfessorBirchsLab_EventScript_SendTorchicToPC
	hidemonpic
	goto Common_EventScript_NoMoreRoomForPokemon
	end

BoreaGlade_ProfessorBirchsLab_EventScript_SendTorchicToParty::
	call BoreaGlade_ProfessorBirchsLab_EventScript_ReceivedPostgameGift
	removeobject LOCALID_BALL_TORCHIC
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BoreaGlade_ProfessorBirchsLab_EventScript_ReceivedTorchic
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto BoreaGlade_ProfessorBirchsLab_EventScript_ReceivedTorchic
	end

BoreaGlade_ProfessorBirchsLab_EventScript_SendTorchicToPC::
	call BoreaGlade_ProfessorBirchsLab_EventScript_ReceivedPostgameGift
	removeobject LOCALID_BALL_TORCHIC
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BoreaGlade_ProfessorBirchsLab_EventScript_TorchicTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto BoreaGlade_ProfessorBirchsLab_EventScript_TorchicTransferredToPC
	end

BoreaGlade_ProfessorBirchsLab_EventScript_TorchicTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto BoreaGlade_ProfessorBirchsLab_EventScript_ReceivedTorchic
	end

BoreaGlade_ProfessorBirchsLab_EventScript_ReceivedTorchic::
	hidemonpic
	msgbox BoreaGlade_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
	setvar VAR_POSTGAME_BIRCH_GIFT, 3
	setflag FLAG_DAILY_RECEIVED_BIRCH_STARTER
	releaseall
	end


BoreaGlade_ProfessorBirchsLab_EventScript_Mudkip::
	release
	goto_if_ge VAR_POSTGAME_BIRCH_GIFT, 3, BoreaGlade_ProfessorBirchsLab_EventScript_AlreadyChoseGift
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	showmonpic SPECIES_MUDKIP, 10, 3
	msgbox BoreaGlade_ProfessorBirchsLab_Text_YoullTakeMudkip, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BoreaGlade_ProfessorBirchsLab_EventScript_TakeYourTime
	goto BoreaGlade_ProfessorBirchsLab_EventScript_GiveMudkip
	end

BoreaGlade_ProfessorBirchsLab_Text_YoullTakeMudkip:
	.string "PROF. IGNATIUS: The WATER POKéMON\n"
	.string "MUDKIP is your choice!\p"
	.string "You sure know what you're doing.\p"
	.string "So, you'll take the MUDKIP?$"

BoreaGlade_ProfessorBirchsLab_EventScript_GiveMudkip::
	bufferspeciesname STR_VAR_1, SPECIES_MUDKIP
	setvar VAR_TEMP_1, SPECIES_MUDKIP
	givemon SPECIES_MUDKIP, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, BoreaGlade_ProfessorBirchsLab_EventScript_SendMudkipToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, BoreaGlade_ProfessorBirchsLab_EventScript_SendMudkipToPC
	hidemonpic
	goto Common_EventScript_NoMoreRoomForPokemon
	end

BoreaGlade_ProfessorBirchsLab_EventScript_SendMudkipToParty::
	call BoreaGlade_ProfessorBirchsLab_EventScript_ReceivedPostgameGift
	removeobject LOCALID_BALL_MUDKIP
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BoreaGlade_ProfessorBirchsLab_EventScript_ReceivedMudkip
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto BoreaGlade_ProfessorBirchsLab_EventScript_ReceivedMudkip
	end

BoreaGlade_ProfessorBirchsLab_EventScript_SendMudkipToPC::
	call BoreaGlade_ProfessorBirchsLab_EventScript_ReceivedPostgameGift
	removeobject LOCALID_BALL_MUDKIP
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BoreaGlade_ProfessorBirchsLab_EventScript_MudkipTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto BoreaGlade_ProfessorBirchsLab_EventScript_MudkipTransferredToPC
	end

BoreaGlade_ProfessorBirchsLab_EventScript_MudkipTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto BoreaGlade_ProfessorBirchsLab_EventScript_ReceivedMudkip
	end

BoreaGlade_ProfessorBirchsLab_EventScript_ReceivedMudkip::
	hidemonpic
	msgbox BoreaGlade_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
	setvar VAR_POSTGAME_BIRCH_GIFT, 3
	setflag FLAG_DAILY_RECEIVED_BIRCH_STARTER
	releaseall
	end


BoreaGlade_ProfessorBirchsLab_EventScript_TakeYourTime::
	hidemonpic
	msgbox BoreaGlade_ProfessorBirchsLab_Text_TakeYourTimeAllInvaluable, MSGBOX_DEFAULT
	releaseall
	end

BoreaGlade_ProfessorBirchsLab_Text_TakeYourTimeAllInvaluable:
	.string "PROF. IGNATIUS: Take your time before\n"
	.string "you decide.\p"
	.string "They're all invaluable POKéMON.$"

BoreaGlade_ProfessorBirchsLab_EventScript_ReceivedPostgameGift::
	playfanfare MUS_OBTAIN_ITEM
	message BoreaGlade_ProfessorBirchsLab_Text_ReceivedPostgameGift
	waitmessage
	waitfanfare
	return

BoreaGlade_ProfessorBirchsLab_Text_ReceivedPostgameGift:
	.string "{PLAYER} received the {STR_VAR_1}\n"
	.string "from PROF. IGNATIUS!$"

BoreaGlade_ProfessorBirchsLab_Text_GrassyPatchWaiting:
	.string "PROF. IGNATIUS: Listen, {PLAYER}{KUN}.\n"
	.string "You've become the HOENN CHAMPION,\l"
	.string "but your POKéMON journey isn't over.\p"
	.string "There is no end to the road\n"
	.string "that is POKéMON.\p"
	.string "Somewhere, there is a grassy patch\n"
	.string "that's waiting for you!$"

BoreaGlade_ProfessorBirchsLab_EventScript_AlreadyChoseGift::
	msgbox BoreaGlade_ProfessorBirchsLab_Text_BetterLeaveOthersAlone, MSGBOX_DEFAULT
	releaseall
	end

BoreaGlade_ProfessorBirchsLab_Text_BetterLeaveOthersAlone:
	.string "You received the promised POKéMON.\p"
	.string "You'll have to prove yourself to\n"
	.string "PROF. IGNATIUS before you can receive.\l"
	.string "another gift!$"





@GET STARTER
BoreaGlade_ProfessorBirchsLab_EventScript_SetPlayerPosForReceiveStarter::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

@ The starter is technically given prior to this on Route 101 by special ChooseStarter
@ This is just where the game tells you its yours and lets you nickname it
BoreaGlade_ProfessorBirchsLab_EventScript_GiveStarterEvent::
	lockall
	bufferleadmonspeciesname STR_VAR_1
	message BoreaGlade_ProfessorBirchsLab_Text_LikeYouToHavePokemon
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox BoreaGlade_ProfessorBirchsLab_Text_WhyNotGiveNicknameToMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BoreaGlade_ProfessorBirchsLab_EventScript_NicknameStarter
	goto_if_eq VAR_RESULT, NO, BoreaGlade_ProfessorBirchsLab_EventScript_GoSeeRival
	end

BoreaGlade_ProfessorBirchsLab_Text_LikeYouToHavePokemon:
	.string "PROF. IGNATIUS: So, {PLAYER}{KUN}.\p"
	.string "I've heard so much about you from\n"
	.string "your father.\p"
	.string "We're old friends from the KANTO region,\n"
	.string "he is a true POKéMON MASTER!\p"
	.string "I'm so glad he has taken the role as\n"
	.string "PETALBURG GYM LEADER.\p"
	.string "He will be an exceptional challenge for\n"
	.string "anybody taking him on.\l"
	.string "He's an extraordinary battler!\p"
	.string "It will also afford his lovely LAUREN,\n"
	.string "sorry, your MOM the chance to open up\l"
	.string "her own store, we're all so proud of her!\p"
	.string "I know that you don't have your\n"
	.string "own POKéMON yet.\p"
	.string "But the way you battled earlier,\n"
	.string "you pulled it off with aplomb!\p"
	.string "I guess you have your father's blood\n"
	.string "in your veins after all!\p"
	.string "Oh, yes. As thanks for rescuing me,\n"
	.string "I'd like you to have the POKéMON you\l"
	.string "used earlier.\p"
	.string "{PLAYER} received the {STR_VAR_1}!$"

BoreaGlade_ProfessorBirchsLab_Text_WhyNotGiveNicknameToMon:
	.string "PROF. IGNATIUS: Why not give a nickname\n"
	.string "to {STR_VAR_1}?$"

BoreaGlade_ProfessorBirchsLab_EventScript_NicknameStarter::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	goto BoreaGlade_ProfessorBirchsLab_EventScript_GoSeeRival
	end

BoreaGlade_ProfessorBirchsLab_EventScript_GoSeeRival::
	setvar VAR_GIFT_POKEMON_SCRIPT, 2
	msgbox BoreaGlade_ProfessorBirchsLab_Text_MightBeGoodIdeaToGoSeeRival, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BoreaGlade_ProfessorBirchsLab_EventScript_AgreeToSeeRival
	goto_if_eq VAR_RESULT, NO, BoreaGlade_ProfessorBirchsLab_EventScript_DeclineSeeingRival
	end

BoreaGlade_ProfessorBirchsLab_Text_MightBeGoodIdeaToGoSeeRival:
	.string "PROF. IGNATIUS: If you work at POKéMON\n"
	.string "and gain experience, I think you'll make\l"
	.string "an extremely good TRAINER.\p"
	.string "My kid, {RIVAL}, is also studying\n"
	.string "POKéMON while helping me out.\p"
	.string "{PLAYER}{KUN}, don't you think it might be\n"
	.string "a good idea to go see {RIVAL}?$"

BoreaGlade_ProfessorBirchsLab_EventScript_AgreeToSeeRival::
	msgbox BoreaGlade_ProfessorBirchsLab_Text_GetRivalToTeachYou, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_ROUTE_101_BOY
	subquestmenu QUEST_MENU_COMPLETE_QUEST, ADVENTURE_BEGINS, FIND_RIVAL
	startquest SELENIC_SPIRIT
	setvar VAR_BIRCH_LAB_STATE, 3
	releaseall
	end

BoreaGlade_ProfessorBirchsLab_Text_GetRivalToTeachYou:
	.string "PROF. IGNATIUS: Great!\n"
	.string "{RIVAL} should be happy, too.\p"
	.string "Get {RIVAL} to teach you what it\n"
	.string "means to be a TRAINER.\p"
	.string "Oh!\n"
	.string "Can you do me a favour?\p"
	.string "I delivered a parcel to SELENIC SPIRIT\n"
	.string "earlier. Can you go and see the clerk\l"
	.string "and make sure that everything is fine?\p"
	.string "Your MOM wanted it delivered\n"
	.string "straight to the store as she's\l"
	.string "been busy with the move here.\p"
	.string "I hope it's exactly as she needs.$"

BoreaGlade_ProfessorBirchsLab_EventScript_DeclineSeeingRival::
	msgbox BoreaGlade_ProfessorBirchsLab_Text_DontBeThatWay, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BoreaGlade_ProfessorBirchsLab_EventScript_AgreeToSeeRival
	goto_if_eq VAR_RESULT, NO, BoreaGlade_ProfessorBirchsLab_EventScript_DeclineSeeingRival
	end

BoreaGlade_ProfessorBirchsLab_Text_DontBeThatWay:
	.string "PROF. IGNATIUS: Oh, don't be that way.\n"
	.string "You should go meet my kid.$"


@BLUE now interrupts the POKEDEX event and delivers a National Pokedex to Birch
BoreaGlade_ProfessorBirchsLab_EventScript_GivePokedexEvent::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, BoreaGlade_ProfessorBirchsLab_Movement_PlayerEnterLabForPokedex
	waitmovement 0
	goto BoreaGlade_ProfessorBirchsLab_EventScript_GivePokedex
	end

BoreaGlade_ProfessorBirchsLab_Movement_PlayerEnterLabForPokedex:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BoreaGlade_ProfessorBirchsLab_EventScript_GivePokedex::
	msgbox BoreaGlade_ProfessorBirchsLab_Text_HeardYouBeatRivalTakePokedex, MSGBOX_DEFAULT
	playse SE_DOOR
	playbgm MUS_RG_ENCOUNTER_RIVAL, TRUE
	msgbox BoreaGlade_ProfessorBirchsLab_Text_YoBirch, MSGBOX_AUTOCLOSE
	waitmessage
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	turnobject LOCALID_RIVAL, DIR_SOUTH
	applymovement LOCALID_BIRCH, Common_Movement_ExclamationMark
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	clearflag FLAG_HIDE_BLUE_INSIDE_LAB
	addobject LOCALID_BLUE
	applymovement LOCALID_BLUE, Movement_Blue_Barges_In
	waitmovement 4
	applymovement OBJ_EVENT_ID_PLAYER, Movement_Player_Steps_Aside
	waitmovement 0
	applymovement LOCALID_BLUE, Movement_Blue_Steps_Up
	waitmovement 4
	msgbox BoreaGlade_ProfessorBirchsLab_Text_Beat, MSGBOX_DEFAULT
	waitmessage
	turnobject LOCALID_BLUE, DIR_WEST
	msgbox BoreaGlade_ProfessorBirchsLab_Text_Beat2, MSGBOX_DEFAULT
	waitmessage
	turnobject LOCALID_BLUE, DIR_NORTH
	msgbox BoreaGlade_ProfessorBirchsLab_Text_Beat3, MSGBOX_DEFAULT
	waitmessage
	msgbox BoreaGlade_ProfessorBirchsLab_Text_AmIInterrupting, MSGBOX_DEFAULT
	applymovement LOCALID_BIRCH, Common_Movement_ExclamationMark
	msgbox BoreaGlade_ProfessorBirchsLab_Text_ThisIsAPokedex, MSGBOX_DEFAULT
	applymovement LOCALID_BLUE, Movement_Blue_FacesPlayer
	msgbox BoreaGlade_ProfessorBirchsLab_Text_AnotherTrainer, MSGBOX_DEFAULT
	applymovement LOCALID_BLUE, Movement_Blue_Goodbye
	msgbox BoreaGlade_ProfessorBirchsLab_Text_Goodbye, MSGBOX_DEFAULT
	applymovement LOCALID_BLUE, Movement_Blue_Exit
	msgbox BoreaGlade_ProfessorBirchsLab_Text_SmellYaLater, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_BLUE_INSIDE_LAB
	removeobject LOCALID_BLUE
	savebgm MUS_DUMMY
	fadedefaultbgm
	applymovement OBJ_EVENT_ID_PLAYER, Movement_MoveBackToBirch
	turnobject LOCALID_RIVAL, DIR_WEST
	msgbox BoreaGlade_ProfessorBirchsLab_Text_WhereWereWe, MSGBOX_DEFAULT
	call BoreaGlade_ProfessorBirchsLab_EventScript_ReceivePokedex
	waitmessage
	applymovement LOCALID_RIVAL, BoreaGlade_ProfessorBirchsLab_Movement_RivalApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, BoreaGlade_ProfessorBirchsLab_EventScript_MayGivePokeBalls
	call_if_eq VAR_RESULT, FEMALE, BoreaGlade_ProfessorBirchsLab_EventScript_BrendanGivePokeBalls
	startquest POKEDEX
	setvar VAR_BIRCH_LAB_STATE, 5
	setflag FLAG_ADVENTURE_STARTED
	setvar VAR_OLDALE_TOWN_STATE, 1
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4
	setvar VAR_BOREA_GLADE_STATE, 3
	setvar VAR_GIFT_POKEMON_SCRIPT, 3
	releaseall
	end

BoreaGlade_ProfessorBirchsLab_Text_HeardYouBeatRivalTakePokedex:
	.string "PROF. IGNATIUS: Oh, hi, {PLAYER}{KUN}!\p"
	.string "I heard you beat {RIVAL} on\n"
	.string "your first try. That's excellent!\p"
	.string "{RIVAL}'s been helping with my research\n"
	.string "for a long time.\p"
	.string "{RIVAL} has an extensive history as\n"
	.string "a TRAINER already.$"

BoreaGlade_ProfessorBirchsLab_Text_YoBirch:
	.string "????: Yo! PROF. IGNATIUS!$"

Movement_Blue_Barges_In:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Movement_Player_Steps_Aside:
	walk_left
	face_right
	step_end

Movement_Blue_Steps_Up:
	walk_up
	step_end

BoreaGlade_ProfessorBirchsLab_Text_Beat:
	.string "...$"

BoreaGlade_ProfessorBirchsLab_Text_Beat2:
	.string ".........$"

BoreaGlade_ProfessorBirchsLab_Text_Beat3:
	.string "...............$"

BoreaGlade_ProfessorBirchsLab_Text_AmIInterrupting:
	.string "????: Oh, am I interrupting?\p"
	.string "Sorry about that!\p"
	.string "When GRAMPS heard I was headed to\n"
	.string "HOENN, he asked me to stop by and\l"
	.string "drop these off.\p"
	.string "GRAMPS, I mean, PROFESSOR OAK says\n"
	.string "hello, by the way.$"

BoreaGlade_ProfessorBirchsLab_Text_ThisIsAPokedex:
	.string "PROF. IGNATIUS: Oh!\p"
	.string "This is the NATIONAL POKéDEX!\p"
	.string "This will certainly be useful for\n"
	.string "{PLAYER} and {RIVAL}.$"

Movement_Blue_FacesPlayer:
	face_left
	step_end

BoreaGlade_ProfessorBirchsLab_Text_AnotherTrainer:
	.string "????: Oh, so you're also a POKéMON\n"
	.string "TRAINER?\p"
	.string "My name is BLUE. I just took my\n"
	.string "shot at the POKéMON LEAGUE back\l"
	.string "in KANTO.\p"
	.string "That's right, you're face to face\n"
	.string "with a former CHAMPION.\p"
	.string "I heard a rumor someone in HOENN\n"
	.string "was searching for strong TRAINERS.\p"
	.string "So, I came to see what that's\n"
	.string "all about.\p"
	.string "But I did hear something about a pretty\n"
	.string "BAD OMEN being spotted, so I might not\l"
	.string "stick around for too long.\p"
	.string "Maybe I'll see you around, {PLAYER}!$"

Movement_Blue_Goodbye:
	face_up
	step_end

BoreaGlade_ProfessorBirchsLab_Text_Goodbye:
	.string "BLUE: Anyway, sorry for crashing\n"
	.string "the party, PROF.\p"
	.string "I should let you get back to it.$"

Movement_Blue_Exit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

BoreaGlade_ProfessorBirchsLab_Text_SmellYaLater:
	.string "BLUE: Smell ya later!$"

Movement_MoveBackToBirch:
	walk_right
	face_up
	step_end

BoreaGlade_ProfessorBirchsLab_Text_WhereWereWe:
	.string "{RIVAL}: Who was that, DAD?\p"
	.string "PROF. IGNATIUS: He's my colleague's\n"
	.string "grandson - he's been that way \l"
	.string "since he was young...\p"
	.string "He's a very skilled TRAINER, but\n"
	.string "clearly has a lot to learn about\l"
	.string "what it takes to be a CHAMPION.\p"
	.string "...\p"
	.string "Anyway, where were we?\p"
	.string "Ah! That's right, the POKéDEX!\p"
	.string "The POKéDEX is a high-tech\n"
	.string "tool that automatically makes a record\l"
	.string "of any POKéMON you meet or catch.\p"
	.string "{PLAYER}, your DAD completed a\n"
	.string "REGIONAL POKéDEX in KANTO for me,\l"
	.string "before you were even born!\p"
	.string "He's why a lot of entries have\n"
	.string "already been comlpeted.\p"
	.string "{RIVAL} already goes everywhere\n"
	.string "with their POKéDEX.\p"
	.string "But, as you've probably noticed,\n"
	.string "{RIVAL}, more unknown species have\l"
	.string "begun to appear in HOENN.\p"
	.string "Now…\p"
	.string "{PLAYER}{KUN} and {RIVAL}, I want the\n"
	.string "two of you to help me study these new\l"
	.string "POKéMON that have been seen in HOENN.\p"
	.string "With your help, perhaps we can learn\n"
	.string "even more about POKéMON!\p"
	.string "Be sure to show me when you complete\n"
	.string "what SAMUEL and I started,\l"
	.string "the NATIONAL POKéDEX!$"


BoreaGlade_ProfessorBirchsLab_EventScript_ReceivePokedex::
	giveitem ITEM_POKEDEX
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	return

BoreaGlade_ProfessorBirchsLab_Text_ReceivedPokedex:
	.string "{PLAYER} received the NATIONAL\n"
	.string "POKéDEX from PROF. IGNATIUS!$"

BoreaGlade_ProfessorBirchsLab_EventScript_MayGivePokeBalls::
	msgbox BoreaGlade_ProfessorBirchsLab_Text_MayGotPokedexTooTakeThese, MSGBOX_DEFAULT
	msgbox BoreaGlade_ProfessorBirchsLab_Text_CatchCutePokemonWithPokeBalls, MSGBOX_DEFAULT
	setvar VAR_RESULT, 0
	return

BoreaGlade_ProfessorBirchsLab_Text_MayGotPokedexTooTakeThese:
	.string "{RIVAL}: Oh, wow, {PLAYER}{KUN}!\n"
	.string "You got a POKéDEX, too!\l"
	.string "That's great! Just like me!$"

BoreaGlade_ProfessorBirchsLab_EventScript_MayNoRoomForPokeBalls::
	msgbox BoreaGlade_ProfessorBirchsLab_Text_OhYourBagsFull, MSGBOX_DEFAULT
	return

BoreaGlade_ProfessorBirchsLab_Text_OhYourBagsFull:
	.string "Oh? Your BAG's full.$"

BoreaGlade_ProfessorBirchsLab_Text_CatchCutePokemonWithPokeBalls:
	.string "It's fun if you can get a lot of\n"
	.string "POKéMON!\p"
	.string "I'm going to look all over the place\n"
	.string "because I want different POKéMON.\p"
	.string "If I find any cute POKéMON, I'll catch\n"
	.string "them with POKé BALLS!$"

BoreaGlade_ProfessorBirchsLab_EventScript_BrendanGivePokeBalls::
	msgbox BoreaGlade_ProfessorBirchsLab_Text_BrendanGotPokedexTooTakeThese, MSGBOX_DEFAULT
	msgbox BoreaGlade_ProfessorBirchsLab_Text_CatchCoolPokemonWithPokeBalls, MSGBOX_DEFAULT
	setvar VAR_RESULT, 1
	return

BoreaGlade_ProfessorBirchsLab_Text_BrendanGotPokedexTooTakeThese:
	.string "{RIVAL}: Huh…\n"
	.string "So you got a POKéDEX, too.\l"
	.string "Nice one!$"

BoreaGlade_ProfessorBirchsLab_Text_CatchCoolPokemonWithPokeBalls:
	.string "You know it's more fun to\n"
	.string "have a whole bunch of POKéMON.\p"
	.string "I'm going to explore all over the place\n"
	.string "to find different POKéMON.\p"
	.string "If I find any cool POKéMON, you bet\n"
	.string "I'll try to get them with POKé BALLS.$"

BoreaGlade_ProfessorBirchsLab_EventScript_BrendanNoRoomForPokeBalls::
	msgbox BoreaGlade_ProfessorBirchsLab_Text_HeyYourBagsFull, MSGBOX_DEFAULT
	return

BoreaGlade_ProfessorBirchsLab_Text_HeyYourBagsFull:
	.string "Hey, your BAG's full.$"

BoreaGlade_ProfessorBirchsLab_Movement_RivalApproachPlayer:
	walk_down
	walk_in_place_faster_left
	step_end

@BIRCH
BoreaGlade_ProfessorBirchsLab_EventScript_Birch::
	lock
	faceplayer
	call_if_eq VAR_POSTGAME_BIRCH_GIFT, 5, BoreaGlade_ProfessorBirchsLab_EventScript_CanHaveAnotherPokemon
	goto_if_ge VAR_POSTGAME_BIRCH_GIFT, 3, ProfBirch_EventScript_RatePokedexOrRegister
	goto_if_eq VAR_POSTGAME_BIRCH_GIFT, 2, BoreaGlade_ProfessorBirchsLab_EventScript_CanHaveAnyOneOfRarePokemon
	goto_if_unset FLAG_HAS_MATCH_CALL, BoreaGlade_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister
	goto_if_unset FLAG_ENABLE_PROF_BIRCH_MATCH_CALL, EventScript_RegisterProfBirch
	goto BoreaGlade_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister
	end

BoreaGlade_ProfessorBirchsLab_EventScript_CanHaveAnotherPokemon::
	msgbox BoreaGlade_ProfessorBirchsLab_Text_CanHaveAnotherPokemon, MSGBOX_DEFAULT
	setvar VAR_POSTGAME_BIRCH_GIFT, 2
	return

BoreaGlade_ProfessorBirchsLab_Text_CanHaveAnotherPokemon:
	.string "PROF. IGNATIUS: Hello, {PLAYER}!\p"
	.string "I see you've been working very\n"
	.string "hard to improve your abilities as\l"
	.string "a POKéMON TRAINER!\p"
	.string "This calls for a reward!\p"
	.string "I've brought back more POKéMON\n"
	.string "from my fieldwork.$"


BoreaGlade_ProfessorBirchsLab_EventScript_CanHaveAnyOneOfRarePokemon::
	msgbox BoreaGlade_ProfessorBirchsLab_Text_CanHaveAnyOneOfRarePokemon, MSGBOX_DEFAULT
	release
	end

BoreaGlade_ProfessorBirchsLab_Text_CanHaveAnyOneOfRarePokemon:
	.string "PROF. IGNATIUS: These POKéMON are not\n"
	.string "seen very often, but I seem to have\l"
	.string "a knack for finding them!\p"
	.string "Go ahead and choose one.$"

BoreaGlade_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister::
	goto_if_unset FLAG_HIDE_BOREA_GLADE_BIRCHS_LAB_UNKNOWN_0x380, ProfBirch_EventScript_RatePokedexOrRegister
	goto_if_eq VAR_BIRCH_LAB_STATE, 5, BoreaGlade_ProfessorBirchsLab_EventScript_PokemonAwait
	msgbox BoreaGlade_ProfessorBirchsLab_Text_BirchRivalGoneHome, MSGBOX_DEFAULT
	release
	end

BoreaGlade_ProfessorBirchsLab_Text_BirchRivalGoneHome:
	.string "PROF. IGNATIUS: {RIVAL}?\n"
	.string "Gone home, I think.\p"
	.string "Or maybe that kid's scrabbling around\n"
	.string "in the mountaintops again somewhere…\p"
	.string "If you or your POKéMON get tired,\n"
	.string "you should get some rest at home.$"

EventScript_RegisterProfBirch::
	msgbox MatchCall_Text_BirchRegisterCall, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MatchCall_Text_RegisteredBirch, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	setvar VAR_REGISTER_BIRCH_STATE, 2
	release
	end

BoreaGlade_ProfessorBirchsLab_EventScript_PokemonAwait::
	msgbox BoreaGlade_ProfessorBirchsLab_Text_CountlessPokemonAwait, MSGBOX_DEFAULT
	release
	end

BoreaGlade_ProfessorBirchsLab_Text_CountlessPokemonAwait:
	.string "PROF. IGNATIUS: Countless POKéMON\n"
	.string "await you!\p"
	.string "Argh, I'm getting the itch to get out\n"
	.string "and do fieldwork again!$"

BoreaGlade_ProfessorBirchsLab_EventScript_Rival::
	lock
	faceplayer
	goto_if_eq VAR_POSTGAME_BIRCH_GIFT, 5, BoreaGlade_ProfessorBirchsLab_EventScript_RivalFuturePlans
	goto_if_eq VAR_POSTGAME_BIRCH_GIFT, 4, BoreaGlade_ProfessorBirchsLab_EventScript_RivalHaveYouGoneToBattleFrontier
	goto_if_ge VAR_POSTGAME_BIRCH_GIFT, 3, BoreaGlade_ProfessorBirchsLab_EventScript_RivalFuturePlans
	goto_if_eq VAR_POSTGAME_BIRCH_GIFT, 2, BoreaGlade_ProfessorBirchsLab_EventScript_RivalTakeBreakFromFieldwork
	checkplayergender
	call_if_eq VAR_RESULT, MALE, BoreaGlade_ProfessorBirchsLab_EventScript_MayWhereShouldIGoNext
	call_if_eq VAR_RESULT, FEMALE, BoreaGlade_ProfessorBirchsLab_EventScript_BrendanWhereShouldIGoNext
	release
	end

BoreaGlade_ProfessorBirchsLab_EventScript_MayWhereShouldIGoNext::
	msgbox BoreaGlade_ProfessorBirchsLab_Text_MayWhereShouldIGoNext, MSGBOX_DEFAULT
	return

BoreaGlade_ProfessorBirchsLab_Text_MayWhereShouldIGoNext:
	.string "{RIVAL}: I wonder where I should go look\n"
	.string "for POKéMON next?$"

BoreaGlade_ProfessorBirchsLab_EventScript_BrendanWhereShouldIGoNext::
	msgbox BoreaGlade_ProfessorBirchsLab_Text_BrendanWhereShouldIGoNext, MSGBOX_DEFAULT
	return

BoreaGlade_ProfessorBirchsLab_Text_BrendanWhereShouldIGoNext:
	.string "{RIVAL}: Where should I look for\n"
	.string "POKéMON next…$"

BoreaGlade_ProfessorBirchsLab_EventScript_RivalFuturePlans::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, BoreaGlade_ProfessorBirchsLab_EventScript_MayWhatNextImStayingHere
	call_if_eq VAR_RESULT, FEMALE, BoreaGlade_ProfessorBirchsLab_EventScript_BrendanPreferCollectingSlowly
	release
	end

BoreaGlade_ProfessorBirchsLab_EventScript_MayWhatNextImStayingHere::
	msgbox BoreaGlade_ProfessorBirchsLab_Text_MayWhatNextImStayingHere, MSGBOX_DEFAULT
	return

BoreaGlade_ProfessorBirchsLab_Text_MayWhatNextImStayingHere:
	.string "{RIVAL}: {PLAYER}{KUN}, after this…\n"
	.string "What are you going to do?\p"
	.string "Are you going to keep battling\n"
	.string "and sharpening your skills?\p"
	.string "Or are you going to try filling\n"
	.string "the NATIONAL POKéDEX?\p"
	.string "I'm staying here to help the PROF.$"

BoreaGlade_ProfessorBirchsLab_EventScript_BrendanPreferCollectingSlowly:
	msgbox BoreaGlade_ProfessorBirchsLab_Text_BrendanPreferCollectingSlowly, MSGBOX_DEFAULT
	return

BoreaGlade_ProfessorBirchsLab_Text_BrendanPreferCollectingSlowly:
	.string "{RIVAL}: Rather than collecting\n"
	.string "POKéMON, I prefer slowly and \l"
	.string "steadily raising the one I chose.$"

BoreaGlade_ProfessorBirchsLab_EventScript_RivalHaveYouGoneToBattleFrontier::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, BoreaGlade_ProfessorBirchsLab_EventScript_MayHaveYouGoneToBattleFrontier
	call_if_eq VAR_RESULT, FEMALE, BoreaGlade_ProfessorBirchsLab_EventScript_BrendanHaveYouGoneToBattleFrontier
	release
	end

BoreaGlade_ProfessorBirchsLab_EventScript_MayHaveYouGoneToBattleFrontier::
	msgbox BoreaGlade_ProfessorBirchsLab_Text_MayHaveYouGoneToBattleFrontier, MSGBOX_DEFAULT
	return

BoreaGlade_ProfessorBirchsLab_Text_MayHaveYouGoneToBattleFrontier:
	.string "{RIVAL}: Oh, hi, {PLAYER}{KUN}!\n"
	.string "Have you gone to that place,\l"
	.string "the BATTLE FRONTIER?$"

BoreaGlade_ProfessorBirchsLab_EventScript_BrendanHaveYouGoneToBattleFrontier::
	msgbox BoreaGlade_ProfessorBirchsLab_Text_BrendanHaveYouGoneToBattleFrontier, MSGBOX_DEFAULT
	return

BoreaGlade_ProfessorBirchsLab_Text_BrendanHaveYouGoneToBattleFrontier:
	.string "{RIVAL}: Hey, {PLAYER}!\n"
	.string "Have you gone out to that place,\l"
	.string "the BATTLE FRONTIER?$"

BoreaGlade_ProfessorBirchsLab_EventScript_RivalTakeBreakFromFieldwork::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, BoreaGlade_ProfessorBirchsLab_EventScript_MayTakeBreakFromFieldwork
	call_if_eq VAR_RESULT, FEMALE, BoreaGlade_ProfessorBirchsLab_EventScript_BrendanTakeBreakFromFieldwork
	release
	end

BoreaGlade_ProfessorBirchsLab_EventScript_MayTakeBreakFromFieldwork::
	msgbox BoreaGlade_ProfessorBirchsLab_Text_MayTakeBreakFromFieldwork, MSGBOX_DEFAULT
	return

BoreaGlade_ProfessorBirchsLab_Text_MayTakeBreakFromFieldwork:
	.string "{RIVAL}: I think I'll take a short break\n"
	.string "from fieldwork.\p"
	.string "I think I'll help the PROF. here for\n"
	.string "a while.$"

BoreaGlade_ProfessorBirchsLab_EventScript_BrendanTakeBreakFromFieldwork::
	msgbox BoreaGlade_ProfessorBirchsLab_Text_BrendanTakeBreakFromFieldwork, MSGBOX_DEFAULT
	return

BoreaGlade_ProfessorBirchsLab_Text_BrendanTakeBreakFromFieldwork:
	.string "{RIVAL}: For the time being,\n"
	.string "I'm taking a break from fieldwork.\p"
	.string "I'll be helping out the PROF. here\n"
	.string "for a while.$"


@Other Lab Events

BoreaGlade_ProfessorBirchsLab_EventScript_Machine::
	msgbox BoreaGlade_ProfessorBirchsLab_Text_SeriousLookingMachine, MSGBOX_SIGN
	end

BoreaGlade_ProfessorBirchsLab_Text_SeriousLookingMachine:
	.string "It's a serious-looking machine.\n"
	.string "The PROF. must use this for research.$"

BoreaGlade_ProfessorBirchsLab_EventScript_PC::
	msgbox BoreaGlade_ProfessorBirchsLab_Text_PCUsedForResearch, MSGBOX_SIGN
	end

BoreaGlade_ProfessorBirchsLab_Text_PCUsedForResearch:
	.string "It's a PC used for research.\n"
	.string "Better not mess around with it.$"

BoreaGlade_ProfessorBirchsLab_EventScript_Bookshelf::
	msgbox BoreaGlade_ProfessorBirchsLab_Text_CrammedWithBooksOnPokemon, MSGBOX_SIGN
	end

BoreaGlade_ProfessorBirchsLab_Text_CrammedWithBooksOnPokemon:
	.string "It's crammed with books on POKéMON.$"

BoreaGlade_ProfessorBirchsLab_EventScript_Book::
	msgbox BoreaGlade_ProfessorBirchsLab_Text_BookTooHardToRead, MSGBOX_SIGN
	end

BoreaGlade_ProfessorBirchsLab_Text_BookTooHardToRead:
	.string "It's a book that's too hard to read.$"

BoreaGlade_ProfessorBirchsLab_EventScript_Aide::
	lock
	faceplayer
	goto_if_set FLAG_DELIVERY_TO_LITTLEROOT, BoreaGlade_ProfessorBirchsLab_EventScript_AideParcel
	goto_if_ge VAR_BIRCH_LAB_STATE, 3, BoreaGlade_ProfessorBirchsLab_EventScript_AideReceivedStarter
	goto_if_set FLAG_BIRCH_AIDE_MET, BoreaGlade_ProfessorBirchsLab_EventScript_AideAlreadyMet
	msgbox BoreaGlade_ProfessorBirchsLab_Text_BirchAwayOnFieldwork, MSGBOX_DEFAULT
	setflag FLAG_BIRCH_AIDE_MET
	release
	end

BoreaGlade_ProfessorBirchsLab_EventScript_AideParcel::
	goto_if_unset FLAG_DAILY_DELIVERY_QUEST, BoreaGlade_ProfessorBirchsLab_EventScript_AideParcelLate
	msgbox PetalburgCity_PostOffice_Text_ThanksParcelDelivered, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message PetalburgCity_PostOffice_Text_HappyCustomer
	waitfanfare
	removeitem ITEM_PARCEL
	setflag FLAG_DELIVERY_COMPLETED
	clearflag FLAG_DELIVERY_TO_LITTLEROOT
	release
	end

BoreaGlade_ProfessorBirchsLab_EventScript_AideParcelLate::
	msgbox PetalburgCity_PostOffice_Text_MyParcelIsLate, MSGBOX_DEFAULT
	call PetalburgCity_PostOffice_EventScripts_ResetDeliveries
	message PetalburgCity_PostOffice_Text_UnhappyCustomer
	waitmessage
	removeitem ITEM_PARCEL
	release
	end

BoreaGlade_ProfessorBirchsLab_Text_BirchAwayOnFieldwork:
	.string "Hunh? PROFESSOR IGNATIUS?\p"
	.string "The PROFESSOR is away on fieldwork.\n"
	.string "Ergo, he isn't here.\p"
	.string "Oh, let me explain what fieldwork is.\p"
	.string "It is to study things in the natural\n"
	.string "environment, like fields and mountains,\l"
	.string "instead of a laboratory.\p"
	.string "The PROF. isn't one for doing desk work.\n"
	.string "He's the type of person who would\l"
	.string "rather go outside and experience\l"
	.string "things than read about them here.$"

BoreaGlade_ProfessorBirchsLab_EventScript_AideAlreadyMet::
	msgbox BoreaGlade_ProfessorBirchsLab_Text_BirchIsntOneForDeskWork, MSGBOX_DEFAULT
	release
	end

BoreaGlade_ProfessorBirchsLab_Text_BirchIsntOneForDeskWork:
	.string "The PROF. isn't one for doing desk work.\n"
	.string "He's the type of person who would\l"
	.string "rather go outside and experience\l"
	.string "things than read about them here.$"

BoreaGlade_ProfessorBirchsLab_EventScript_AideReceivedStarter::
	msgbox BoreaGlade_ProfessorBirchsLab_Text_BirchEnjoysRivalsHelpToo, MSGBOX_DEFAULT
	release
	end

BoreaGlade_ProfessorBirchsLab_Text_BirchEnjoysRivalsHelpToo:
	.string "PROF. IGNATIUS is studying the habitats\n"
	.string "and distribution of POKéMON.\p"
	.string "The PROF. enjoys {RIVAL}'s help, too.\n"
	.string "There's a lot of love there.$"

BoreaGlade_ProfessorBirchsLab_EventScript_Leaf::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_LEAF_BATTLE, BoreaGlade_ProfessorBirchsLab_EventScript_LeafFiredUp
	msgbox BoreaGlade_ProfessorBirchsLab_Text_Leaf, MSGBOX_YESNO
	closemessage
	goto_if_eq VAR_RESULT, TRUE, BoreaGlade_ProfessorBirchsLab_EventScript_LeafRematch
	msgbox BoreaGlade_ProfessorBirchsLab_Text_LeafDecline, MSGBOX_DEFAULT
	turnobject LOCALID_LEAF, DIR_WEST
	release
	end

BoreaGlade_ProfessorBirchsLab_Text_Leaf:
	.string "LEAF: PROF. IGNATIUS is letting me use\n"
	.string "some of his equipment to do research\l"
	.string "on rare POKéMON.\p"
	.string "Say, want to have a POKéMON battle?$"

BoreaGlade_ProfessorBirchsLab_Text_LeafDecline:
	.string "That's alright. I should focus on my\n"
	.string "research. I just get so fired up when\l"
	.string "think about finding rare POKéMON!$"

BoreaGlade_ProfessorBirchsLab_EventScript_LeafRematch::
	cleartrainerflag TRAINER_LEAF
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_LEAF, LOCALID_LEAF, BoreaGlade_ProfessorBirchsLab_Text_LeafRematchBattleIntro, BoreaGlade_ProfessorBirchsLab_Text_LeafRematchBattleDefeat, BoreaGlade_ProfessorBirchsLab_EventScript_LeafRematchCompleted
	end


BoreaGlade_ProfessorBirchsLab_Text_LeafRematchBattleIntro:
	.string "LEAF: I won't hold back this time!$"


BoreaGlade_ProfessorBirchsLab_Text_LeafRematchBattleDefeat:
	.string "LEAF: I need to get stronger!$"


BoreaGlade_ProfessorBirchsLab_EventScript_LeafRematchCompleted::
	setflag FLAG_DAILY_LEAF_BATTLE
	msgbox BoreaGlade_ProfessorBirchsLab_Text_LeafFiredUp, MSGBOX_DEFAULT
	release
	end

BoreaGlade_ProfessorBirchsLab_EventScript_LeafFiredUp::
	msgbox BoreaGlade_ProfessorBirchsLab_Text_LeafFiredUp, MSGBOX_DEFAULT
	release
	end

BoreaGlade_ProfessorBirchsLab_Text_LeafFiredUp:
	.string "LEAF: Alright! I'm all fired up!\p"
	.string "I'm going to keep researching\n"
	.string "how to find even more powerful\l"
	.string "POKéMON!$"

BoreaGlade_ProfessorBirchsLab_EventScript_PokedexDownload::
	questmenu QUEST_MENU_CHECK_UNLOCKED, POKEDEX
	compare VAR_RESULT, FALSE
	goto_if_eq BoreaGlade_ProfessorBirchsLab_EventScript_PokedexDownload_1
	lock
	msgbox BoreaGlade_ProfessorBirchsLab_EventScript_PokedexDownload_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BoreaGlade_ProfessorBirchsLab_EventScript_PokedexDownload_4
	closemessage
	goto PokedexDownload_CameraPan
	return

BoreaGlade_ProfessorBirchsLab_EventScript_PokedexDownload_1:
	goto BoreaGlade_ProfessorBirchsLab_EventScript_Book
	return

BoreaGlade_ProfessorBirchsLab_EventScript_PokedexDownload_4:
	goto PokedexDownload_DownloadOption
	return


PokedexDownload_CameraPan::
	fadescreen 1
	playbgm MUS_DP_CANALAVE_NIGHT, TRUE
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, PokedexDownload_CameraPanDown
	waitmovement 0
	fadescreen 0
	goto PokedexDownload_Letter
	return


PokedexDownload_CameraPanDown:
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	step_end

PokedexDownload_CameraPanUp:
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	step_end

PokedexDownload_Letter::
	delay 60
	msgbox PokedexDownload_Letter_Text_0, MSGBOX_DEFAULT
	applymovement 11, MomEntrance
	msgbox PokedexDownload_Letter_Text_1, MSGBOX_DEFAULT
	waitmovement 0
	applymovement 9, WalkDown
	msgbox PokedexDownload_Letter_Text_2, MSGBOX_DEFAULT
	applymovement 9, WalkLeft
	msgbox PokedexDownload_Letter_Text_3, MSGBOX_DEFAULT
	applymovement 9, FaceDown
	msgbox PokedexDownload_Letter_Text_4, MSGBOX_DEFAULT
	applymovement 9, WalkRight
	waitmovement 0
	applymovement 9, FaceDown
	msgbox PokedexDownload_Letter_Text_5, MSGBOX_DEFAULT
	applymovement 9, WalkUp
	waitmovement 0
	applymovement 9, FaceDown
	msgbox PokedexDownload_Letter_Text_6, MSGBOX_DEFAULT
	applymovement 9, FaceUp
	msgbox PokedexDownload_Letter_Text_7, MSGBOX_DEFAULT
	applymovement 9, FaceDown
	msgbox PokedexDownload_Letter_Text_8, MSGBOX_DEFAULT
	applymovement 9, WalkDown
	msgbox PokedexDownload_Letter_Text_9, MSGBOX_DEFAULT
	applymovement 9, WalkLeft
	waitmovement 0
	applymovement 9, FaceDown
	msgbox PokedexDownload_Letter_Text_10, MSGBOX_DEFAULT
	applymovement 9, WalkRight
	waitmovement 0
	applymovement 9, FaceDown
	msgbox PokedexDownload_Letter_Text_11, MSGBOX_DEFAULT
	applymovement 9, WalkUp
	waitmovement 0
	applymovement 9, FaceDown
	msgbox PokedexDownload_Letter_Text_12, MSGBOX_DEFAULT
	waitmovement 0
	closemessage
	delay 20
	goto PokedexDownload_CameraPanRevert
	return


MomEntrance:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

MomReturn:
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	step_end

PokedexDownload_CameraPanRevert::
	savebgm MUS_DUMMY
	fadescreen 1
	fadedefaultbgm
	applymovement 11, MomReturn
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, PokedexDownload_CameraPanUp
	waitmovement 0
	special RemoveCameraObject
	fadescreen 0
	goto PokedexDownload_DownloadOption
	return


ProfReturn:
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

PokedexDownload_DownloadOption::
	questmenu QUEST_MENU_CHECK_COMPLETE, POKEDEX
	compare VAR_RESULT, FALSE
	goto_if_eq PokedexDownload_DownloadOption_1
	closemessage
	release
	end

PokedexDownload_DownloadOption_1:
	msgbox PokedexDownload_DownloadOption_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq PokedexDownload_DownloadOption_4
	goto PokedexDownload_YesThenQuestion
	return

PokedexDownload_DownloadOption_4:
	goto PokedexDownload_NoThenQuestion
	return


PokedexDownload_NoThenQuestion::
	msgbox PokedexDownload_NoThenQuestion_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq PokedexDownload_NoThenQuestion_1
	closemessage
	release
	end

PokedexDownload_NoThenQuestion_1:
	goto PokedexDownload_DownloadOption
	return


PokedexDownload_YesThenQuestion::
	msgbox PokedexDownload_YesThenQuestion_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq PokedexDownload_YesThenQuestion_1
	closemessage
	goto PokedexDownload_Import
	return

PokedexDownload_YesThenQuestion_1:
	goto PokedexDownload_DownloadOption
	return


PokedexDownload_Import::
	delay 60
	msgbox PokedexDownload_Import_Text_0, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox PokedexDownload_Import_Text_1, MSGBOX_DEFAULT
	closemessage
	goto CompleteQuestSpecial
	return


CompleteQuestSpecial::
	delay 30
	questmenu QUEST_MENU_COMPLETE_QUEST, POKEDEX
	playfanfare MUS_DP_EVOLVED
	special DoDomeConfetti
	msgbox CompleteQuestSpecial_Text_0, MSGBOX_SIGN
	waitfanfare
	release
	return


BoreaGlade_ProfessorBirchsLab_EventScript_PokedexDownload_Text_0:
	.string "There's an letter to PROFESSOR\n"
	.string "IGNATIUS from DAD.\l"
	.string "It's dated from before you moved.\p"
	.string "Would you like to read it?$"

PokedexDownload_Letter_Text_0:
	.string "A letter to my best friend,\n"
	.string "POKéMON PROFESSOR IGNATIUS.\p"
	.string "Yet again,\n"
	.string "I would like to apologise.$"

PokedexDownload_Letter_Text_1:
	.string "Before meeting LAUREN, you and I\n"
	.string "completed KANTO's REGIONAL POKéDEX,\l"
	.string "and I know we had even greater plans.$"

PokedexDownload_Letter_Text_2:
	.string "You, a PROFESSOR, analysing data.\n"
	.string "and I, a TRAINER, in the field,\l"
	.string "we were an extraordinary team.$"

PokedexDownload_Letter_Text_3:
	.string "Although, after meeting my future,\n"
	.string "our plans were derailed.$"

PokedexDownload_Letter_Text_4:
	.string "LAUREN and I fell in love.\n"
	.string "And before any of us knew it,\l"
	.string "you were officiating our wedding.$"

PokedexDownload_Letter_Text_5:
	.string "After all of that,\n"
	.string "it was just a matter of time.\p"
	.string "LAUREN and I went adventuring\n"
	.string "and we had the time of our lives.\l"
	.string "We saw the world, a big beautiful world.$"

PokedexDownload_Letter_Text_6:
	.string "I became stronger, a POKéMON MASTER,\n"
	.string "she took SELENIC to new heights,\l"
	.string "all whilst our love grew deeper.$"

PokedexDownload_Letter_Text_7:
	.string "I have no regrets about my decision,\n"
	.string "and I know you don't resent me for it.$"

PokedexDownload_Letter_Text_8:
	.string "You moved to BOREA GLADE, to HOENN.\n"
	.string "And like me, you fell in love.$"

PokedexDownload_Letter_Text_9:
	.string "You even had {RIVAL}, mere months\n"
	.string "after I had {PLAYER}.$"

PokedexDownload_Letter_Text_10:
	.string "Now that {PLAYER}'s older, and LAUREN\n"
	.string "is opening a SELENIC SPIRIT,\l"
	.string "we will be moving to BOREA GLADE.\p"
	.string "I will be taking on the role of\n"
	.string "PETALBURG CITY GYM LEADER.\l"
	.string "I will see you soon my friend.$"

PokedexDownload_Letter_Text_11:
	.string "Until then, a gift.\p"
	.string "I have attached all of the field data\n"
	.string "from my adventures with LAUREN.\l"
	.string "I hope this helps your research into\l"
	.string "the NATIONAL POKéDEX.$"

PokedexDownload_Letter_Text_12:
	.string "I will see you soon,\p"
	.string "SAMUEL$"

PokedexDownload_DownloadOption_Text_0:
	.string "This contains all the remaining data\n"
	.string "needed for you to complete the\l"
	.string "NATIONAL POKéDEX.\p"
	.string "Would you like to import the data?$"

PokedexDownload_NoThenQuestion_Text_0:
	.string "This data will be available for you to\n"
	.string "import at any time.\p"
	.string "Are you sure that you do not wish to\n"
	.string "import the data?$"

PokedexDownload_YesThenQuestion_Text_0:
	.string "Are you sure?\n"
	.string "This change is irreversible.\l"
	.string "Would you like to import the data?$"

PokedexDownload_Import_Text_0:
	.string "…IMPORTING DATA…\n"
	.string "…PLEASE WAIT… …23%…\p"
	.string "…IMPORTING DATA…\n"
	.string "…PLEASE WAIT… …45%…\p"
	.string "…IMPORTING DATA…\n"
	.string "…PLEASE WAIT… …57%…\p"
	.string "…IMPORTING DATA…\n"
	.string "…PLEASE WAIT… …74%…$"

PokedexDownload_Import_Text_1:
	.string "…DATA IMPORT…\n"
	.string "…FINISHED…$"

CompleteQuestSpecial_Text_0:
	.string "With some help from LAUREN & SAMUEL,\n"
	.string "“Gotta Catch 'Em All!” was completed.$"
