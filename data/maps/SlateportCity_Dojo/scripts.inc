SlateportCity_Dojo_OnTransition::
	call_if_unset FLAG_DAILY_DOJO_OFFENSE_CHALLENGED, SlateportCity_Dojo_EventScript_ResetOffense
	call_if_unset FLAG_DAILY_DOJO_DEFENSE_CHALLENGED, SlateportCity_Dojo_EventScript_ResetDefense
	end

SlateportCity_Dojo_EventScript_ResetOffense::
	cleartrainerflag TRAINER_DOJO_ATK
	clearflag FLAG_DAILY_DOJO_ATK
	cleartrainerflag TRAINER_DOJO_SPA
	clearflag FLAG_DAILY_DOJO_SPA
	cleartrainerflag TRAINER_DOJO_SPEED
	clearflag FLAG_DAILY_DOJO_SPEED
	return

SlateportCity_Dojo_EventScript_ResetDefense::
	cleartrainerflag TRAINER_DOJO_HP
	clearflag FLAG_DAILY_DOJO_HP
	cleartrainerflag TRAINER_DOJO_DEF
	clearflag FLAG_DAILY_DOJO_DEF
	cleartrainerflag TRAINER_DOJO_SPD
	clearflag FLAG_DAILY_DOJO_SPD
	return

SlateportCity_Dojo_EventScript_OffenseMaster::
	goto_if_set FLAG_DAILY_DOJO_OFFENSE_CHALLENGED, SlateportCity_Dojo_EventScript_OffenseMasterReset
	lock
	faceplayer
	msgbox SlateportCity_Dojo_Text_OffenseMaster, MSGBOX_DEFAULT
	release
	end

SlateportCity_Dojo_EventScript_DefenseMaster::
	goto_if_set FLAG_DAILY_DOJO_DEFENSE_CHALLENGED, SlateportCity_Dojo_EventScript_DefenseMasterReset
	lock
	faceplayer
	msgbox SlateportCity_Dojo_Text_DefenseMaster, MSGBOX_DEFAULT
	release
	end

SlateportCity_Dojo_Text_OffenseMaster:
	.string "MASTER: I have trained my students\n"
	.string "in the art of OFFENSE.\p"
	.string "Their POKéMON represent the\n"
	.string "embodiment of these concepts.$"

SlateportCity_Dojo_Text_DefenseMaster:
	.string "MASTER: I have trained my students\n"
	.string "in the art of DEFENSE.\p"
	.string "Their POKéMON represent the\n"
	.string "embodiment of these concepts.$"

SlateportCity_Dojo_EventScript_OffenseMasterReset::
	lock
	faceplayer
	showmoneybox 0, 0
	msgbox SlateportCity_Dojo_Text_ResetForAFee, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_Dojo_EventScript_TryResetOffense
	msgbox SlateportCity_Dojo_Text_AnotherTimeThen, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

SlateportCity_Dojo_EventScript_DefenseMasterReset::
	lock
	faceplayer
	showmoneybox 0, 0
	msgbox SlateportCity_Dojo_Text_ResetForAFee, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_Dojo_EventScript_TryResetDefense
	msgbox SlateportCity_Dojo_Text_AnotherTimeThen, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

SlateportCity_Dojo_EventScript_TryResetOffense::
	checkmoney 3500
	goto_if_eq VAR_RESULT, 0, SlateportCity_Dojo_EventScript_Donations
	playse SE_SHOP
	msgbox SlateportCity_Dojo_Text_OffenseStudentsFiredUp, MSGBOX_DEFAULT
	removemoney 3500
	updatemoneybox
	call SlateportCity_Dojo_EventScript_ResetOffense
	closemessage
	hidemoneybox
	release
	end

SlateportCity_Dojo_EventScript_TryResetDefense::
	checkmoney 3500
	goto_if_eq VAR_RESULT, 0, SlateportCity_Dojo_EventScript_Donations
	playse SE_SHOP
	msgbox SlateportCity_Dojo_Text_DefenseStudentsFiredUp, MSGBOX_DEFAULT
	removemoney 3500
	updatemoneybox
	call SlateportCity_Dojo_EventScript_ResetDefense
	closemessage
	hidemoneybox
	release
	end

SlateportCity_Dojo_Text_OffenseStudentsFiredUp:
	.string "The OFFENSE MASTER's pupils\n"
	.string "are ready to go another round!$"

SlateportCity_Dojo_Text_DefenseStudentsFiredUp:
	.string "The DEFENSE MASTER's pupils\n"
	.string "are ready to go another round!$"

SlateportCity_Dojo_EventScript_Donations:
	msgbox SlateportCity_Dojo_Text_Donations, MSGBOX_DEFAULT
	release
	end

SlateportCity_Dojo_Text_Donations:
	.string "I admire your dedication!\p"
	.string "However, we cannot run our\n"
	.string "DOJO on enthusiasm alone.\p"
	.string "Please return when you can\n"
	.string "afford the tuition.$"

SlateportCity_Dojo_Text_ResetForAFee:
	.string "MASTER: Ah! I see you have already\n"
	.string "sought training with my pupils!\p"
	.string "Do you want to continue training?\n"
	.string "Sparring sessions are only ¥3500.$"

SlateportCity_Dojo_Text_AnotherTimeThen:
	.string "Perhaps another time then...$"

SlateportCity_Dojo_EventScript_ATK::
	goto_if_set FLAG_DAILY_DOJO_ATK, SlateportCity_Dojo_EventScript_ATKDefeated
	lock
	faceplayer
	msgbox SlateportCity_Dojo_Text_ATK, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_Dojo_EventScript_BattleATK
	release
	end

SlateportCity_Dojo_Text_ATK:
	.string "1,000 sit ups! 1,000 crunches!\p"
	.string "I'm training my POKéMON's ATTACK!\n"
	.string "Do you want to spar with me?$"

SlateportCity_Dojo_EventScript_BattleATK:
	setflag FLAG_DAILY_DOJO_OFFENSE_CHALLENGED
	setflag FLAG_DAILY_DOJO_ATK
	trainerbattle_single TRAINER_DOJO_ATK, SlateportCity_Dojo_Text_ATKIntro, SlateportCity_Dojo_Text_ATKDefeat
	msgbox SlateportCity_Dojo_Text_ATKDefeated, MSGBOX_AUTOCLOSE
	end

SlateportCity_Dojo_EventScript_ATKDefeated::
	lock
	faceplayer
	msgbox SlateportCity_Dojo_Text_ATKDefeated, MSGBOX_AUTOCLOSE
	release
	end

SlateportCity_Dojo_Text_ATKIntro:
	.string "My POKéMON will take you out\n"
	.string "with one punch!$"

SlateportCity_Dojo_Text_ATKDefeat:
	.string "I've never faced such an\n"
	.string "opponent!$"

SlateportCity_Dojo_Text_ATKDefeated:
	.string "You need to push your body to\n"
	.string "the limit every day!$"


SlateportCity_Dojo_EventScript_SPA::
	goto_if_set FLAG_DAILY_DOJO_SPA, SlateportCity_Dojo_EventScript_SPADefeated
	lock
	faceplayer
	msgbox SlateportCity_Dojo_Text_SPA, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_Dojo_EventScript_BattleSPA
	release
	end

SlateportCity_Dojo_EventScript_SPADefeated::
	lock
	faceplayer
	msgbox SlateportCity_Dojo_Text_SPADefeated, MSGBOX_AUTOCLOSE
	release
	end

SlateportCity_Dojo_Text_SPA:
	.string "My mind is as strong as my fists!\p"
	.string "I'm training my SPECIAL ATTACK!\n"
	.string "Do you want to spar with me?$"

SlateportCity_Dojo_EventScript_BattleSPA:
	setflag FLAG_DAILY_DOJO_OFFENSE_CHALLENGED
	setflag FLAG_DAILY_DOJO_SPA
	trainerbattle_single TRAINER_DOJO_SPA, SlateportCity_Dojo_Text_SPAIntro, SlateportCity_Dojo_Text_SPADefeat
	msgbox SlateportCity_Dojo_Text_SPADefeated, MSGBOX_AUTOCLOSE
	end

SlateportCity_Dojo_Text_SPAIntro:
	.string "BRAINS OVER BRAWN!$"

SlateportCity_Dojo_Text_SPADefeat:
	.string "Brawn probably would have helped.$"

SlateportCity_Dojo_Text_SPADefeated:
	.string "I quit my job at DEVON to train\n"
	.string "at this DOJO!$"


SlateportCity_Dojo_EventScript_Speed::
	goto_if_set FLAG_DAILY_DOJO_SPEED, SlateportCity_Dojo_EventScript_SpeedDefeated
	lock
	faceplayer
	msgbox SlateportCity_Dojo_Text_Speed, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_Dojo_EventScript_BattleSpeed
	release
	end

SlateportCity_Dojo_EventScript_SpeedDefeated::
	lock
	faceplayer
	msgbox SlateportCity_Dojo_Text_SpeedDefeated, MSGBOX_AUTOCLOSE
	release
	end

SlateportCity_Dojo_Text_Speed:
	.string "Strike Fast! Strike First!\p"
	.string "I'm training my POKéMON's SPEED!\n"
	.string "Do you want to spar with me?$"

SlateportCity_Dojo_EventScript_BattleSpeed:
	setflag FLAG_DAILY_DOJO_OFFENSE_CHALLENGED
	setflag FLAG_DAILY_DOJO_SPEED
	trainerbattle_single TRAINER_DOJO_SPEED, SlateportCity_Dojo_Text_SpeedIntro, SlateportCity_Dojo_Text_SpeedDefeat
	msgbox SlateportCity_Dojo_Text_SpeedDefeated, MSGBOX_AUTOCLOSE
	end

SlateportCity_Dojo_Text_SpeedIntro:
	.string "You won't even see me coming!$"

SlateportCity_Dojo_Text_SpeedDefeat:
	.string "TOO SLOW!$"

SlateportCity_Dojo_Text_SpeedDefeated:
	.string "My wife doesn't support my\n"
	.string "POKéMON training, so I come\l"
	.string "here in secret after work.$"


SlateportCity_Dojo_EventScript_HP::
	goto_if_set FLAG_DAILY_DOJO_HP, SlateportCity_Dojo_EventScript_HPDefeated
	lock
	faceplayer
	msgbox SlateportCity_Dojo_Text_HP, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_Dojo_EventScript_BattleHP
	release
	end

SlateportCity_Dojo_EventScript_HPDefeated::
	lock
	faceplayer
	msgbox SlateportCity_Dojo_Text_HPDefeated, MSGBOX_AUTOCLOSE
	release
	end

SlateportCity_Dojo_Text_HP:
	.string "I can take any hit you throw at me!\p"
	.string "I'm training my POKéMON's HP!\n"
	.string "Do you want to spar with me?$"

SlateportCity_Dojo_EventScript_BattleHP:
	setflag FLAG_DAILY_DOJO_DEFENSE_CHALLENGED
	setflag FLAG_DAILY_DOJO_HP
	trainerbattle_single TRAINER_DOJO_HP, SlateportCity_Dojo_Text_HPIntro, SlateportCity_Dojo_Text_HPDefeat
	msgbox SlateportCity_Dojo_Text_HPDefeated, MSGBOX_AUTOCLOSE
	end

SlateportCity_Dojo_Text_HPIntro:
	.string "I've dedicated my life to taking\n"
	.string "hits!$"

SlateportCity_Dojo_Text_HPDefeat:
	.string "But that doesn't mean that I\n"
	.string "enjoy losing...$"

SlateportCity_Dojo_Text_HPDefeated:
	.string "I need to be able to shrug off\n"
	.string "any blow! Even emotional ones!$"


SlateportCity_Dojo_EventScript_DEF::
	goto_if_set FLAG_DAILY_DOJO_DEF, SlateportCity_Dojo_EventScript_DefDefeated
	lock
	faceplayer
	msgbox SlateportCity_Dojo_Text_Def, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_Dojo_EventScript_BattleDef
	release
	end

SlateportCity_Dojo_EventScript_DefDefeated::
	lock
	faceplayer
	msgbox SlateportCity_Dojo_Text_DefDefeated, MSGBOX_AUTOCLOSE
	release
	end

SlateportCity_Dojo_Text_Def:
	.string "Nothing can hurt me!\p"
	.string "My POKéMON focus on DEFENSE!\n"
	.string "Do you want to spar with me?$"

SlateportCity_Dojo_EventScript_BattleDef:
	setflag FLAG_DAILY_DOJO_DEFENSE_CHALLENGED
	setflag FLAG_DAILY_DOJO_DEF
	trainerbattle_single TRAINER_DOJO_DEF, SlateportCity_Dojo_Text_DefIntro, SlateportCity_Dojo_Text_DefDefeat
	msgbox SlateportCity_Dojo_Text_DefDefeated, MSGBOX_AUTOCLOSE
	end

SlateportCity_Dojo_Text_DefIntro:
	.string "You'll never break through my\n"
	.string "perfect DEFENSE!$"

SlateportCity_Dojo_Text_DefDefeat:
	.string "What? My DEFENSE was penetrated?$"

SlateportCity_Dojo_Text_DefDefeated:
	.string "If your opponent can't break your\n"
	.string "DEFENSE, they can't win!\p"
	.string "I need to take my own advice...$"

SlateportCity_Dojo_EventScript_SPD::
	goto_if_set FLAG_DAILY_DOJO_SPD, SlateportCity_Dojo_EventScript_SPDDefeated
	lock
	faceplayer
	msgbox SlateportCity_Dojo_Text_SPD, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_Dojo_EventScript_BattleSPD
	release
	end

SlateportCity_Dojo_EventScript_SPDDefeated::
	lock
	faceplayer
	msgbox SlateportCity_Dojo_Text_SPDDefeated, MSGBOX_AUTOCLOSE
	release
	end

SlateportCity_Dojo_Text_SPD:
	.string "SPECIAL ATTACKS don't scare me!\p"
	.string "I've mastered my SPECIAL DEFENSE!\n"
	.string "Do you want to spar with me?$"

SlateportCity_Dojo_EventScript_BattleSPD:
	setflag FLAG_DAILY_DOJO_DEFENSE_CHALLENGED
	setflag FLAG_DAILY_DOJO_SPD
	trainerbattle_single TRAINER_DOJO_SPD, SlateportCity_Dojo_Text_SPDIntro, SlateportCity_Dojo_Text_SPDDefeat
	msgbox SlateportCity_Dojo_Text_SPDDefeated, MSGBOX_AUTOCLOSE
	end

SlateportCity_Dojo_Text_SPDIntro:
	.string "I'm going to become the master\n"
	.string "of this DOJO!$"

SlateportCity_Dojo_Text_SPDDefeat:
	.string "Maybe I should practice more...$"

SlateportCity_Dojo_Text_SPDDefeated:
	.string "Resisting SPECIAL ATTACKS is my\n"
	.string "speciality.\p"
	.string "But it doesn't pay the bills.$"

SlateportCity_Dojo_EventScript_AquaGrunt::
	setflag FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA
	return


SlateportCity_Dojo_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_Dojo_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_Dojo_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SlateportCity_Dojo_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto SlateportCity_Dojo_OnTransition
	return

SlateportCity_Dojo_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_1, 0, SlateportCity_Dojo_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

SlateportCity_Dojo_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	addvar VAR_TEMP_1, 1
	goto_if_unset FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA, SlateportCity_Dojo_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1
	end

SlateportCity_Dojo_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1:
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Dojo_Entrance
	waitmovement OBJ_EVENT_ID_PLAYER
	message SlateportCity_Dojo_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0
	waitmessage
	waitbuttonpress
	delay 30
	applymovement 9, FaceRight
	msgbox SlateportCity_Dojo_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1, MSGBOX_SIGN
	waitmovement 9
	applymovement 9, Question
	delay 30
	applymovement 9, FaceUp
	delay 30
	applymovement 9, FaceRight
	msgbox SlateportCity_Dojo_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_2, MSGBOX_SIGN
	applymovement OBJ_EVENT_ID_PLAYER, FaceDown
	applymovement 9, SlateportCity_Dojo_Exit
	waitmovement 9
	delay 10
	playse SE_EXIT
	removeobject 9
	delay 30
	call LabLights_Slateport_AquaSubquest
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Dojo_MasterThanks
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox SlateportCity_Dojo_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_3, MSGBOX_SIGN
	startquest EV_TRAINING
	end


SlateportCity_Dojo_Entrance:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	face_left
	step_end

SlateportCity_Dojo_Exit:
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_down
	step_end

SlateportCity_Dojo_MasterThanks:
	walk_left
	face_up
	step_end

SlateportCity_Dojo_Banner::
	questmenu QUEST_MENU_CHECK_COMPLETE, EV_TRAINING
	compare VAR_RESULT, FALSE
	goto_if_eq SlateportCity_Dojo_Banner_1
	specialvar VAR_TEMP_B, IsStarterInParty
	copyvar VAR_TEMP_C, VAR_RESULT
	compare VAR_STARTER_MON, 1
	goto_if_eq SlateportCity_Dojo_Banner_6
SlateportCity_Dojo_Banner_5:
	msgbox SlateportCity_Dojo_Banner_Text_4, MSGBOX_SIGN
	end

SlateportCity_Dojo_Banner_1:
	goto SlateportCity_Dojo_EVs_Tutorial_MasterApproach
	return

SlateportCity_Dojo_Banner_4:
	msgbox SlateportCity_Dojo_Banner_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SlateportCity_Dojo_Banner_9
	msgbox SlateportCity_Dojo_Banner_Text_2, MSGBOX_SIGN
	end

SlateportCity_Dojo_Banner_6:
	compare VAR_TEMP_B, TRUE
	goto_if_eq SlateportCity_Dojo_Banner_4
	goto SlateportCity_Dojo_Banner_5

SlateportCity_Dojo_Banner_9:
	message SlateportCity_Dojo_Banner_Text_1
	waitmessage
	multichoice 21, 8, MULTI_ATTACK_OR_SPECIAL_ATTACK, FALSE
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq SlateportCity_Dojo_Banner_13
	closemessage
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq SlateportCity_Dojo_Banner_16
	specialvar VAR_TEMP_B, ScriptGetPartyMonSpecies
	compare VAR_TEMP_B, SPECIES_CHARCADET
	goto_if_eq SlateportCity_Dojo_Banner_18
	compare VAR_TEMP_B, SPECIES_ARMOROUGE
	goto_if_eq SlateportCity_Dojo_Banner_18
	compare VAR_TEMP_B, SPECIES_CERULEDGE
	goto_if_eq SlateportCity_Dojo_Banner_18
	msgbox SlateportCity_Dojo_Banner_Text_3, MSGBOX_SIGN
	end

SlateportCity_Dojo_Banner_13:
	msgbox SlateportCity_Dojo_Banner_Text_2, MSGBOX_SIGN
	end

SlateportCity_Dojo_Banner_16:
	msgbox SlateportCity_Dojo_Banner_Text_3, MSGBOX_SIGN
	end

SlateportCity_Dojo_Banner_18:
	goto SlateportCity_Dojo_EVs_Tutorial_Charcadet_Nature
	return


SlateportCity_Dojo_EVs_Change_Charcadet::
	compare VAR_TEMP_B, SPECIES_CHARCADET
	goto_if_eq SlateportCity_Dojo_EVs_Change_Charcadet_2
	compare VAR_TEMP_B, SPECIES_ARMOROUGE
	goto_if_eq SlateportCity_Dojo_EVs_Change_Charcadet_3
	compare VAR_TEMP_B, SPECIES_CERULEDGE
	goto_if_eq SlateportCity_Dojo_EVs_Change_Charcadet_4
SlateportCity_Dojo_EVs_Change_Charcadet_1:
	waitmoncry
	fadescreen FADE_TO_BLACK
	playse SE_M_STAT_INCREASE
	waitse
	fadescreen FADE_FROM_BLACK
	special SetHpEvs
	special SetAtkEvs
	special SetDefEvs
	special SetSpdEvs
	special SetSpAtkEvs
	special SetSpDefEvs
	special BufferMonNickname
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_Dojo_EVs_Change_Charcadet_8
	compare VAR_RESULT, 1
	goto_if_eq SlateportCity_Dojo_EVs_Change_Charcadet_9
	return

SlateportCity_Dojo_EVs_Change_Charcadet_2:
	playmoncry SPECIES_CHARCADET, 0
	goto SlateportCity_Dojo_EVs_Change_Charcadet_1

SlateportCity_Dojo_EVs_Change_Charcadet_3:
	playmoncry SPECIES_ARMOROUGE, 0
	goto SlateportCity_Dojo_EVs_Change_Charcadet_1

SlateportCity_Dojo_EVs_Change_Charcadet_4:
	playmoncry SPECIES_CERULEDGE, 0
	goto SlateportCity_Dojo_EVs_Change_Charcadet_1

SlateportCity_Dojo_EVs_Change_Charcadet_8:
	msgbox SlateportCity_Dojo_EVs_Change_Charcadet_Text_0, MSGBOX_SIGN
	return

SlateportCity_Dojo_EVs_Change_Charcadet_9:
	msgbox SlateportCity_Dojo_EVs_Change_Charcadet_Text_1, MSGBOX_SIGN
	return


SlateportCity_Dojo_EVs_Tutorial_MasterApproach::
	getplayerxy VAR_TEMP_A, VAR_TEMP_B
	compare VAR_TEMP_A, 6
	goto_if_eq SlateportCity_Dojo_EVs_Tutorial_MasterApproach_2
	compare VAR_TEMP_A, 9
	goto_if_eq SlateportCity_Dojo_EVs_Tutorial_MasterApproach_3
	end

SlateportCity_Dojo_EVs_Tutorial_MasterApproach_1:
	applymovement OBJ_EVENT_ID_PLAYER, FaceDown
	specialvar VAR_TEMP_B, IsStarterInParty
	compare VAR_TEMP_B, TRUE
	goto_if_eq SlateportCity_Dojo_EVs_Tutorial_MasterApproach_7
	msgbox SlateportCity_Dojo_EVs_Tutorial_MasterApproach_Text_1, MSGBOX_SIGN
	goto SlateportCity_Dojo_EVs_Tutorial_MasterReturn
	return

SlateportCity_Dojo_EVs_Tutorial_MasterApproach_2:
	applymovement 2, SlateportCity_Dojo_EVs_Tutorial_MasterApproachBanner
	waitmovement 2
	goto SlateportCity_Dojo_EVs_Tutorial_MasterApproach_1

SlateportCity_Dojo_EVs_Tutorial_MasterApproach_3:
	applymovement 1, SlateportCity_Dojo_EVs_Tutorial_MasterApproachBanner
	waitmovement 1
	goto SlateportCity_Dojo_EVs_Tutorial_MasterApproach_1

SlateportCity_Dojo_EVs_Tutorial_MasterApproach_7:
	msgbox SlateportCity_Dojo_EVs_Tutorial_MasterApproach_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SlateportCity_Dojo_EVs_Tutorial_MasterApproach_10
	msgbox SlateportCity_Dojo_EVs_Tutorial_MasterApproach_Text_1, MSGBOX_SIGN
	goto SlateportCity_Dojo_EVs_Tutorial_MasterReturn
	return

SlateportCity_Dojo_EVs_Tutorial_MasterApproach_10:
	goto SlateportCity_Dojo_EVs_Tutorial_ChooseStarter
	return


SlateportCity_Dojo_EVs_Tutorial_MasterApproachBanner:
	walk_up
	walk_up
	step_end

SlateportCity_Dojo_EVs_Tutorial_ChooseStarter::
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq SlateportCity_Dojo_EVs_Tutorial_ChooseStarter_2
SlateportCity_Dojo_EVs_Tutorial_ChooseStarter_1:
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_SINISTEA
	goto_if_eq SlateportCity_Dojo_EVs_Tutorial_ChooseStarter_4
	compare VAR_RESULT, SPECIES_CHARCADET
	goto_if_eq SlateportCity_Dojo_EVs_Tutorial_ChooseStarter_5
	compare VAR_RESULT, SPECIES_BASULIN
	goto_if_eq SlateportCity_Dojo_EVs_Tutorial_ChooseStarter_6
	msgbox SlateportCity_Dojo_EVs_Tutorial_ChooseStarter_Text_0, MSGBOX_SIGN
	goto SlateportCity_Dojo_EVs_Tutorial_MasterReturn
	return

SlateportCity_Dojo_EVs_Tutorial_ChooseStarter_2:
	msgbox SlateportCity_Dojo_EVs_Tutorial_MasterApproach_Text_1, MSGBOX_SIGN
	goto SlateportCity_Dojo_EVs_Tutorial_MasterReturn
	goto SlateportCity_Dojo_EVs_Tutorial_ChooseStarter_1

SlateportCity_Dojo_EVs_Tutorial_ChooseStarter_4:
	goto SlateportCity_Dojo_EVs_Tutorial_Sinistea
	return

SlateportCity_Dojo_EVs_Tutorial_ChooseStarter_5:
	copyvar VAR_TEMP_B, VAR_RESULT
	goto SlateportCity_Dojo_EVs_Tutorial_Chacadet
	return

SlateportCity_Dojo_EVs_Tutorial_ChooseStarter_6:
	goto SlateportCity_Dojo_EVs_Tutorial_Basulin
	return


SlateportCity_Dojo_EVs_Tutorial_Sinistea::
	msgbox SlateportCity_Dojo_EVs_Tutorial_Sinistea_Text_0, MSGBOX_SIGN
	goto SlateportCity_Dojo_EVs_Tutorial_Sinistea_Nature
	return


SlateportCity_Dojo_EVs_Tutorial_Chacadet::
	msgbox SlateportCity_Dojo_EVs_Tutorial_Chacadet_Text_0, MSGBOX_DEFAULT
	waitmessage
	multichoice 21, 8, MULTI_ATTACK_OR_SPECIAL_ATTACK, TRUE
	closemessage
	goto SlateportCity_Dojo_EVs_Tutorial_Charcadet_Nature
	return


SlateportCity_Dojo_EVs_Tutorial_Basulin::
	msgbox SlateportCity_Dojo_EVs_Tutorial_Basulin_Text_0, MSGBOX_SIGN
	goto SlateportCity_Dojo_EVs_Tutorial_Basulin_Nature
	return


SlateportCity_Dojo_EVs_Tutorial_Sinistea_Nature::
	setvar VAR_0x8000, NATURE_MODEST
	special SetNature
	goto SlateportCity_Dojo_EVs_Tutorial_Sinistea_EVs
	return


SlateportCity_Dojo_EVs_Tutorial_Charcadet_Nature::
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_Dojo_EVs_Tutorial_Charcadet_Nature_2
	compare VAR_RESULT, 1
	goto_if_eq SlateportCity_Dojo_EVs_Tutorial_Charcadet_Nature_3
SlateportCity_Dojo_EVs_Tutorial_Charcadet_Nature_1:
	special SetNature
	goto SlateportCity_Dojo_EVs_Tutorial_Chacadet_EVs
	return

SlateportCity_Dojo_EVs_Tutorial_Charcadet_Nature_2:
	setvar VAR_0x8000, NATURE_JOLLY
	goto SlateportCity_Dojo_EVs_Tutorial_Charcadet_Nature_1

SlateportCity_Dojo_EVs_Tutorial_Charcadet_Nature_3:
	setvar VAR_0x8000, NATURE_TIMID
	goto SlateportCity_Dojo_EVs_Tutorial_Charcadet_Nature_1


SlateportCity_Dojo_EVs_Tutorial_Basulin_Nature::
	setvar VAR_0x8000, NATURE_ADAMANT
	special SetNature
	goto SlateportCity_Dojo_EVs_Tutorial_Basulin_EVs
	return


SlateportCity_Dojo_EVs_Tutorial_Sinistea_EVs::
	setvar VAR_0x8000, 0
	setvar VAR_0x8001, 0
	setvar VAR_0x8002, 0
	setvar VAR_0x8003, 0
	setvar VAR_0x8005, 255
	setvar VAR_0x8006, 255
	goto SlateportCity_Dojo_EVs_Tutorial_SetEVs
	return


SlateportCity_Dojo_EVs_Tutorial_Chacadet_EVs::
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_Dojo_EVs_Tutorial_Chacadet_EVs_2
	compare VAR_RESULT, 1
	goto_if_eq SlateportCity_Dojo_EVs_Tutorial_Chacadet_EVs_3
SlateportCity_Dojo_EVs_Tutorial_Chacadet_EVs_1:
	setvar VAR_0x8000, 0
	setvar VAR_0x8002, 0
	setvar VAR_0x8003, 255
	setvar VAR_0x8006, 0
	compare VAR_TEMP_C, FALSE
	goto_if_eq SlateportCity_Dojo_EVs_Tutorial_Chacadet_EVs_6
	goto SlateportCity_Dojo_EVs_Change_Charcadet
	return

SlateportCity_Dojo_EVs_Tutorial_Chacadet_EVs_2:
	setvar VAR_0x8001, 255
	setvar VAR_0x8005, 0
	goto SlateportCity_Dojo_EVs_Tutorial_Chacadet_EVs_1

SlateportCity_Dojo_EVs_Tutorial_Chacadet_EVs_3:
	setvar VAR_0x8001, 0
	setvar VAR_0x8005, 255
	goto SlateportCity_Dojo_EVs_Tutorial_Chacadet_EVs_1

SlateportCity_Dojo_EVs_Tutorial_Chacadet_EVs_6:
	goto SlateportCity_Dojo_EVs_Tutorial_SetEVs
	return


SlateportCity_Dojo_EVs_Tutorial_Basulin_EVs::
	setvar VAR_0x8000, 0
	setvar VAR_0x8001, 255
	setvar VAR_0x8002, 255
	setvar VAR_0x8003, 0
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	goto SlateportCity_Dojo_EVs_Tutorial_SetEVs
	return


SlateportCity_Dojo_EVs_Tutorial_SetEVs::
	compare VAR_RESULT, SPECIES_SINISTEA
	goto_if_eq SlateportCity_Dojo_EVs_Tutorial_SetEVs_2
	compare VAR_TEMP_B, SPECIES_CHARCADET
	goto_if_eq SlateportCity_Dojo_EVs_Tutorial_SetEVs_3
	compare VAR_RESULT, SPECIES_BASULIN
	goto_if_eq SlateportCity_Dojo_EVs_Tutorial_SetEVs_4
SlateportCity_Dojo_EVs_Tutorial_SetEVs_1:
	waitmoncry
	fadescreen FADE_TO_BLACK
	playse SE_M_STAT_INCREASE
	waitse
	fadescreen FADE_FROM_BLACK
	special SetHpEvs
	special SetAtkEvs
	special SetDefEvs
	special SetSpdEvs
	special SetSpAtkEvs
	special SetSpDefEvs
	special BufferMonNickname
	goto SlateportCity_Dojo_EVs_Tutorial_Complete
	return

SlateportCity_Dojo_EVs_Tutorial_SetEVs_2:
	playmoncry SPECIES_SINISTEA, 0
	goto SlateportCity_Dojo_EVs_Tutorial_SetEVs_1

SlateportCity_Dojo_EVs_Tutorial_SetEVs_3:
	playmoncry SPECIES_CHARCADET, 0
	goto SlateportCity_Dojo_EVs_Tutorial_SetEVs_1

SlateportCity_Dojo_EVs_Tutorial_SetEVs_4:
	playmoncry SPECIES_BASULIN, 0
	goto SlateportCity_Dojo_EVs_Tutorial_SetEVs_1


SlateportCity_Dojo_EVs_Tutorial_Complete::
	compare VAR_RESULT, SPECIES_SINISTEA
	goto_if_eq SlateportCity_Dojo_EVs_Tutorial_Complete_2
	compare VAR_RESULT, SPECIES_BASULIN
	goto_if_eq SlateportCity_Dojo_EVs_Tutorial_Complete_2
	compare VAR_TEMP_B, SPECIES_CHARCADET
	goto_if_eq SlateportCity_Dojo_EVs_Tutorial_Complete_3
SlateportCity_Dojo_EVs_Tutorial_Complete_1:
	completequest EV_TRAINING
	goto SlateportCity_Dojo_EVs_Tutorial_MasterReturn
	return

SlateportCity_Dojo_EVs_Tutorial_Complete_2:
	msgbox SlateportCity_Dojo_EVs_Tutorial_Complete_Text_0, MSGBOX_SIGN
	goto SlateportCity_Dojo_EVs_Tutorial_Complete_1

SlateportCity_Dojo_EVs_Tutorial_Complete_3:
	msgbox SlateportCity_Dojo_EVs_Tutorial_Complete_Text_1, MSGBOX_SIGN
	goto SlateportCity_Dojo_EVs_Tutorial_Complete_1


SlateportCity_Dojo_EVs_Tutorial_MasterReturn::
	compare VAR_TEMP_A, 6
	goto_if_eq SlateportCity_Dojo_EVs_Tutorial_MasterReturn_2
	compare VAR_TEMP_A, 9
	goto_if_eq SlateportCity_Dojo_EVs_Tutorial_MasterReturn_3
SlateportCity_Dojo_EVs_Tutorial_MasterReturn_1:
	end

SlateportCity_Dojo_EVs_Tutorial_MasterReturn_2:
	applymovement 2, SlateportCity_Dojo_EVs_Tutorial_MasterLeaveBanner
	waitmovement 2
	goto SlateportCity_Dojo_EVs_Tutorial_MasterReturn_1

SlateportCity_Dojo_EVs_Tutorial_MasterReturn_3:
	applymovement 1, SlateportCity_Dojo_EVs_Tutorial_MasterLeaveBanner
	waitmovement 1
	goto SlateportCity_Dojo_EVs_Tutorial_MasterReturn_1


SlateportCity_Dojo_EVs_Tutorial_MasterLeaveBanner:
	walk_down
	walk_down
	step_end

SlateportCity_Dojo_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0:
	.string "Don't lie to me!\n"
	.string "TEAM AQUA will acheive it's goals!$"

SlateportCity_Dojo_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1:
	.string "What do you want?\n"
	.string "TEAM AQUA need to talk to CAPT. STERN!$"

SlateportCity_Dojo_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_2:
	.string "This isn't the CAPTAIN?\n"
	.string "We're in the SLATEPORT DOJO?\p"
	.string "Well it seems that I've made a mistake!\p"
	.string "If the MUSEUM isn't SOUTH of the\n"
	.string "SHIPYARD, it must be NORTH of it.\p"
	.string "I've got to go and join the rest of\n"
	.string "TEAM AQUA in the MUSEUM!$"

SlateportCity_Dojo_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_3:
	.string "MASTER: What an odd person…\n"
	.string "But you have my thanks.\l"
	.string "In fact let me do something for you.\p"
	.string "This is the SLATEPORT DOJO.\n"
	.string "The number one place to train!\l"
	.string "We can improve the EVs of a POKéMON.\p"
	.string "What are EVs?\p"
	.string "EFFORT VALUES, or EVs, dictate how much\n"
	.string "effort a POKéMON has put into battle.\p"
	.string "The type of EV gained depends on the\n"
	.string "opponent or opponents being faced.\l"
	.string "Nevertheless, all EVs improve a stat.\p"
	.string "We also work on mental fortitude here!\p"
	.string "With intense discipline, we can even\n"
	.string "change the NATURE of your POKéMON.\l"
	.string "Do you know what NATURES do?\p"
	.string "The correct NATURE can improve a highly\n"
	.string "used stat, although it comes at the\l"
	.string "cost of the reduction of another.\p"
	.string "The margins aren't small, the NATURE of\n"
	.string "a POKéMON can swing the tide of battle.\p"
	.string "If you bring your PARTNER POKéMON,\n"
	.string "I can give them an intense workout!\p"
	.string "Have a read of the technique behind me,\n"
	.string "it's hung up on the banners on the wall.$"

SlateportCity_Dojo_Banner_Text_0:
	.string "Should I change the offensive style of\n"
	.string "my PARTNER POKéMON?$"

SlateportCity_Dojo_Banner_Text_1:
	.string "Which style should I choose?$"

SlateportCity_Dojo_Banner_Text_2:
	.string "I'll change the offensive style of my\n"
	.string "PARTNER POKéMON another time.$"

SlateportCity_Dojo_Banner_Text_3:
	.string "I should bring my PARTNER POKéMON if I\n"
	.string "want to change their offensive style.$"

SlateportCity_Dojo_Banner_Text_4:
	.string "This banner contains amazing knowledge\n"
	.string "of training regimens.$"

SlateportCity_Dojo_EVs_Change_Charcadet_Text_0:
	.string "{STR_VAR_1} gained the ATTACKING\n"
	.string "offensive style.$"

SlateportCity_Dojo_EVs_Change_Charcadet_Text_1:
	.string "{STR_VAR_1} gained the SPECIAL\n"
	.string "ATTACKING offensive style.$"

SlateportCity_Dojo_EVs_Tutorial_MasterApproach_Text_0:
	.string "MASTER: Did you bring your PARTNER\n"
	.string "POKéMON to train here at the DOJO?$"

SlateportCity_Dojo_EVs_Tutorial_MasterApproach_Text_1:
	.string "MASTER: Come back with your PARTNER.\n"
	.string "I will take them through a workout.$"

SlateportCity_Dojo_EVs_Tutorial_ChooseStarter_Text_0:
	.string "MASTER: No, bring back your PARTNER.\n"
	.string "I will take them through a workout.$"

SlateportCity_Dojo_EVs_Tutorial_Sinistea_Text_0:
	.string "MASTER: Ahh, SINISTEA,\n"
	.string "The GREEN TEA POKéMON!\p"
	.string "SINISTEA and it's evolutions have high\n"
	.string "SPECIAL ATTACK and SPECIAL DEFENSE.\l"
	.string "I have just the training regimen!$"

SlateportCity_Dojo_EVs_Tutorial_Chacadet_Text_0:
	.string "MASTER: Ahh, CHARCADET,\n"
	.string "The FIRE CHILD POKéMON!\p"
	.string "CHARCADET and it's evolutions have\n"
	.string "blistering SPEED, but each evolution\l"
	.string "has a differing offensive style.\p"
	.string "One focusses on ATTACK, whilst the\n"
	.string "other, focusses on SPECIAL ATTACK.\p"
	.string "Now, which will you choose?$"

SlateportCity_Dojo_EVs_Tutorial_Basulin_Text_0:
	.string "MASTER: Ahh, BASULIN,\n"
	.string "The HOSTILE FISH POKéMON!\p"
	.string "BASULIN and it's evolutions have\n"
	.string "high ATTACK and DEFENSE.\l"
	.string "I have just the training regimen!$"

SlateportCity_Dojo_EVs_Tutorial_Complete_Text_0:
	.string "MASTER: That {STR_VAR_1} of yours\n"
	.string "is now bordering on unbeatable!\l"
	.string "You'll be a force to be reckoned with!$"

SlateportCity_Dojo_EVs_Tutorial_Complete_Text_1:
	.string "MASTER: That {STR_VAR_1} of yours\n"
	.string "is now bordering on unbeatable!\p"
	.string "And if you want to change its EVs to\n"
	.string "suit a different offensive style,\l"
	.string "just come right back.$"
