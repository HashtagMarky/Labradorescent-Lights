Common_EventScript_PkmnCenterNurse::
	lock
	faceplayer
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, CountPlayerTrainerStars
	goto_if_eq VAR_RESULT, 4, EventScript_PkmnCenterNurse_GoldCard
	msgbox gText_WouldYouLikeToRestYourPkmn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterNurse_HealPkmn
	goto_if_eq VAR_RESULT, NO, EventScript_PkmnCenterNurse_Goodbye
	closemessage
	release
	end

EventScript_PkmnCenterNurse_Goodbye::
	message gText_WeHopeToSeeYouAgain
	return

@ VAR_0x8004 is 1 when player has Gold Card; jumps are identical
EventScript_PkmnCenterNurse_HealPkmn::
	incrementgamestat GAME_STAT_USED_POKECENTER
	call_if_eq VAR_0x8004, 0, EventScript_PkmnCenterNurse_IllTakeYourPkmn
	call_if_eq VAR_0x8004, 1, EventScript_PkmnCenterNurse_IllTakeYourPkmnGold
	waitmessage
	call EventScript_PkmnCenterNurse_TakeAndHealPkmn
	goto_if_unset FLAG_POKERUS_EXPLAINED, EventScript_PkmnCenterNurse_CheckPokerus
	goto EventScript_PkmnCenterNurse_ReturnPkmn
	end

EventScript_PkmnCenterNurse_IllTakeYourPkmn::
	message gText_IllTakeYourPkmn
	return

EventScript_PkmnCenterNurse_IllTakeYourPkmnGold::
	message gText_IllTakeYourPkmnGold
	return

EventScript_PkmnCenterNurse_TakeAndHealPkmn::
	applymovement VAR_0x800B, Common_Movement_WalkInPlaceFasterLeft @ TODO: Make follower disappear here
	waitmovement 0
	dofieldeffect FLDEFF_POKECENTER_HEAL
	waitfieldeffect FLDEFF_POKECENTER_HEAL
	applymovement VAR_0x800B, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	return

@ VAR_0x8004 is 1 when player has Gold Card
EventScript_PkmnCenterNurse_ReturnPkmn::
	goto_if_eq VAR_0x8004, 1, EventScript_PkmnCenterNurse_ReturnPkmnGold
	message gText_RestoredPkmnToFullHealth
	waitmessage
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
	waitmovement 0
	questmenu QUEST_MENU_CHECK_COMPLETE, ADVENTURE_BEGINS
	goto_if_eq VAR_RESULT, FALSE, EventScript_PkmnCenterNurse_EarlyLeave
	goto_if_set FLAG_SYS_REAL_TIME, EventScript_PkmnCenterNurse_EarlyLeave
	msgbox gText_WouldYouStay, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterNurse_PlayerRest
	message gText_WeHopeToSeeYouAgain
	return

EventScript_PkmnCenterNurse_EarlyLeave::
	message gText_WeHopeToSeeYouAgain
	return

EventScript_PkmnCenterNurse_ReturnPkmnGold::
	message gText_ThankYouForWaiting
	waitmessage
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
	waitmovement 0
	questmenu QUEST_MENU_CHECK_COMPLETE, ADVENTURE_BEGINS
	goto_if_eq VAR_RESULT, FALSE, EventScript_PkmnCenterNurse_EarlyLeaveGold
	msgbox gText_WouldYouStay, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterNurse_PlayerRest
	message gText_WeHopeToSeeYouAgainGold
	return

EventScript_PkmnCenterNurse_EarlyLeaveGold::
	message gText_WeHopeToSeeYouAgainGold
	return

EventScript_PkmnCenterNurse_CheckPokerus::
	specialvar VAR_RESULT, IsPokerusInParty
	goto_if_eq VAR_RESULT, TRUE, EventScript_PkmnCenterNurse_ExplainPokerus
	goto_if_eq VAR_RESULT, FALSE, EventScript_PkmnCenterNurse_ReturnPkmn
	end

EventScript_PkmnCenterNurse_ExplainPokerus::
	message gText_PokerusExplanation
	setflag FLAG_POKERUS_EXPLAINED
	return

EventScript_PkmnCenterNurse_GoldCard::
	goto_if_set FLAG_NURSE_MENTIONS_GOLD_CARD, EventScript_PkmnCenterNurse_AskForUsual
	setflag FLAG_NURSE_MENTIONS_GOLD_CARD
	msgbox gText_WelcomeCutShort, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement VAR_0x800B, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x800B, Common_Movement_Delay48
	waitmovement 0
	msgbox gText_NoticesGoldCard, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterNurse_GoldCardHealPkmn
	message gText_WeHopeToSeeYouAgainGold
	return

EventScript_PkmnCenterNurse_AskForUsual::
	msgbox gText_YouWantTheUsual, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterNurse_GoldCardHealPkmn
	message gText_WeHopeToSeeYouAgainGold
	return

EventScript_PkmnCenterNurse_GoldCardHealPkmn::
	setvar VAR_0x8004, 1
	goto EventScript_PkmnCenterNurse_HealPkmn
	end

Movement_PkmnCenterNurse_Bow:
	nurse_joy_bow
	delay_4
	step_end


@ Change Time Scripts
EventScript_PkmnCenterNurse_PlayerRest::
	message gText_HowLongRest
	waitmessage
	multichoice 25, 2, MULTI_TIME_OF_DAY, 0
	switch VAR_RESULT
	case 0, EventScript_PkmnCenterNurse_PlayerRest_4
	case 1, EventScript_PkmnCenterNurse_PlayerRest_5
	case 2, EventScript_PkmnCenterNurse_PlayerRest_6
	case 3, EventScript_PkmnCenterNurse_PlayerRest_7
	case 4, PkmnCenterNurse_PlayerRest_Default
PkmnCenterNurse_PlayerRest_Default:
	goto EventScript_PkmnCenterNurse_PlayerRest_EarlyEnd

EventScript_PkmnCenterNurse_PlayerRest_1:
	fadescreen 1
	closemessage
	PlaySE SE_EXP_MAX
	waitse
	delay 10
	PlaySE SE_EXP_MAX
	waitse
	delay 10
	PlaySE SE_EXP_MAX
	waitse
	delay 20
	fadescreen 0
	switch VAR_RESULT
	case 0, EventScript_PkmnCenterNurse_PlayerRest_11
	case 1, EventScript_PkmnCenterNurse_PlayerRest_12
	case 2, EventScript_PkmnCenterNurse_PlayerRest_13
	case 3, EventScript_PkmnCenterNurse_PlayerRest_14

EventScript_PkmnCenterNurse_PlayerRest_8:
	compare VAR_0x8004, 1
	goto_if_eq EventScript_PkmnCenterNurse_PlayerRest_15
	message gText_WeHopeToSeeYouAgainWithRest
	return

EventScript_PkmnCenterNurse_PlayerRest_4:
	call MorningSleep
	goto EventScript_PkmnCenterNurse_PlayerRest_1

EventScript_PkmnCenterNurse_PlayerRest_5:
	call AfternoonSleep
	goto EventScript_PkmnCenterNurse_PlayerRest_1

EventScript_PkmnCenterNurse_PlayerRest_6:
	call EveningSleep
	goto EventScript_PkmnCenterNurse_PlayerRest_1

EventScript_PkmnCenterNurse_PlayerRest_7:
	call NightSleep
	goto EventScript_PkmnCenterNurse_PlayerRest_1

EventScript_PkmnCenterNurse_PlayerRest_11:
	msgbox EventScript_PkmnCenterNurse_PlayerRest_Text_0, MSGBOX_DEFAULT
	closemessage
	delay 20
	goto EventScript_PkmnCenterNurse_PlayerRest_8

EventScript_PkmnCenterNurse_PlayerRest_12:
	msgbox EventScript_PkmnCenterNurse_PlayerRest_Text_1, MSGBOX_DEFAULT
	closemessage
	delay 20
	goto EventScript_PkmnCenterNurse_PlayerRest_8

EventScript_PkmnCenterNurse_PlayerRest_13:
	msgbox EventScript_PkmnCenterNurse_PlayerRest_Text_2, MSGBOX_DEFAULT
	closemessage
	delay 20
	goto EventScript_PkmnCenterNurse_PlayerRest_8

EventScript_PkmnCenterNurse_PlayerRest_14:
	msgbox EventScript_PkmnCenterNurse_PlayerRest_Text_3, MSGBOX_DEFAULT
	closemessage
	delay 20
	goto EventScript_PkmnCenterNurse_PlayerRest_8

EventScript_PkmnCenterNurse_PlayerRest_15:
	message gText_WeHopeToSeeYouAgainGoldWithRest
	return

EventScript_PkmnCenterNurse_PlayerRest_16::
	message gText_WeHopeToSeeYouAgainGoldNoRest
	return

EventScript_PkmnCenterNurse_PlayerRest_EarlyEnd::
	compare VAR_0x8004, 1
	goto_if_eq EventScript_PkmnCenterNurse_PlayerRest_16
	message gText_WeHopeToSeeYouAgainNoRest
	return

EventScript_PkmnCenterNurse_PlayerRest_Text_0:
	.string "{PLAYER} WAS WOKEN UP AT 9 AM.$"

EventScript_PkmnCenterNurse_PlayerRest_Text_1:
	.string "{PLAYER} WAS WOKEN UP AT 1 PM.$"

EventScript_PkmnCenterNurse_PlayerRest_Text_2:
	.string "{PLAYER} WAS WOKEN UP AT 5 PM.$"

EventScript_PkmnCenterNurse_PlayerRest_Text_3:
	.string "{PLAYER} WAS WOKEN UP AT 9 PM.$"
