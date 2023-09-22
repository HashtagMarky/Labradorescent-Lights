Global_FlyingTaxi::
	compare VAR_FLYING_TAXI, 0
	goto_if_eq Global_FlyingTaxi_1
	compare VAR_FLYING_TAXI, 1
	goto_if_eq Global_FlyingTaxi_2
	goto FlyingTaxiAv
	return

Global_FlyingTaxi_1:
	goto FlyingTaxiUnav
	return

Global_FlyingTaxi_2:
	goto FlyingTaxiFirst
	return


FlyingTaxiUnav::
	lock
	faceplayer
	msgbox FlyingTaxiUnav_Text_0, MSGBOX_DEFAULT
	goto FlyingTaxiUnavReason
	return


FlyingTaxiUnavReason::
	switch VAR_TEMP_0
	case 0, FlyingTaxiUnavReason_2
	case 1, FlyingTaxiUnavReason_3
	case 3, FlyingTaxiUnavReason_4
	case 5, FlyingTaxiUnavReason_5
	case 7, FlyingTaxiUnavReason_6
	case 9, FlyingTaxiUnavReason_7
	case 10, FlyingTaxiUnavReason_8
	case 11, FlyingTaxiUnavReason_9
	return

FlyingTaxiUnavReason_2:
	random 11
	switch VAR_RESULT
	case 0, FlyingTaxiUnavReason_11
	case 1, FlyingTaxiUnavReason_11
	case 2, FlyingTaxiUnavReason_12
	case 3, FlyingTaxiUnavReason_12
	case 4, FlyingTaxiUnavReason_13
	case 5, FlyingTaxiUnavReason_13
	case 6, FlyingTaxiUnavReason_14
	case 7, FlyingTaxiUnavReason_14
	case 8, FlyingTaxiUnavReason_15
	case 9, FlyingTaxiUnavReason_16
	case 10, FlyingTaxiUnavReason_17
	return

FlyingTaxiUnavReason_3:
	msgbox FlyingTaxiUnavReason_Text_0, MSGBOX_NPC
	return

FlyingTaxiUnavReason_4:
	msgbox FlyingTaxiUnavReason_Text_1, MSGBOX_NPC
	return

FlyingTaxiUnavReason_5:
	msgbox FlyingTaxiUnavReason_Text_2, MSGBOX_NPC
	return

FlyingTaxiUnavReason_6:
	msgbox FlyingTaxiUnavReason_Text_3, MSGBOX_NPC
	return

FlyingTaxiUnavReason_7:
	msgbox FlyingTaxiUnavReason_Text_4, MSGBOX_NPC
	return

FlyingTaxiUnavReason_8:
	msgbox FlyingTaxiUnavReason_Text_5, MSGBOX_NPC
	return

FlyingTaxiUnavReason_9:
	msgbox FlyingTaxiUnavReason_Text_6, MSGBOX_NPC
	return

FlyingTaxiUnavReason_11:
	msgbox FlyingTaxiUnavReason_Text_0, MSGBOX_NPC
	setvar VAR_TEMP_0, 1
	setvar VAR_RESULT, 0
	return

FlyingTaxiUnavReason_12:
	msgbox FlyingTaxiUnavReason_Text_1, MSGBOX_NPC
	setvar VAR_TEMP_0, 3
	setvar VAR_RESULT, 0
	return

FlyingTaxiUnavReason_13:
	msgbox FlyingTaxiUnavReason_Text_2, MSGBOX_NPC
	setvar VAR_TEMP_0, 5
	setvar VAR_RESULT, 0
	return

FlyingTaxiUnavReason_14:
	msgbox FlyingTaxiUnavReason_Text_3, MSGBOX_NPC
	setvar VAR_TEMP_0, 7
	setvar VAR_RESULT, 0
	return

FlyingTaxiUnavReason_15:
	msgbox FlyingTaxiUnavReason_Text_4, MSGBOX_NPC
	setvar VAR_TEMP_0, 9
	setvar VAR_RESULT, 0
	return

FlyingTaxiUnavReason_16:
	msgbox FlyingTaxiUnavReason_Text_5, MSGBOX_NPC
	setvar VAR_TEMP_0, 10
	setvar VAR_RESULT, 0
	return

FlyingTaxiUnavReason_17:
	msgbox FlyingTaxiUnavReason_Text_6, MSGBOX_NPC
	setvar VAR_TEMP_0, 11
	setvar VAR_RESULT, 0
	return


FlyingTaxiFirst::
	msgbox FlyingTaxiFirst_Text_0, MSGBOX_NPC
	addvar VAR_FLYING_TAXI, 1
	return


FlyingTaxiAv::
	lock
	faceplayer
	msgbox FlyingTaxiAv_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq FlyingTaxiAv_1
	msgbox FlyingTaxiAv_Text_2, MSGBOX_NPC
	return

FlyingTaxiAv_1:
	msgbox FlyingTaxiAv_Text_1, MSGBOX_NPC
	special FieldLoadFlyMap
	return


FlyingTaxiUnav_Text_0:
	.string "Hello {PLAYER}.\p"
	.string "I have some bad news. Unfortunately,\n"
	.string "until I get word from the boss,\l"
	.string "the FLYING TAXI service is unavailable.$"

FlyingTaxiUnavReason_Text_0:
	.string "Our PIDGEOT are feeling extremely tired\n"
	.string "and they need a break.$"

FlyingTaxiUnavReason_Text_1:
	.string "There are some powerful winds that our\n"
	.string "PIDGEOT don't want to fly through.$"

FlyingTaxiUnavReason_Text_2:
	.string "Our PIDGEOT have become a bit sick,\n"
	.string "we can't risk their wellbeing.$"

FlyingTaxiUnavReason_Text_3:
	.string "Our PIDGEOT are nesting. We have to let\n"
	.string "them to take care of their young.$"

FlyingTaxiUnavReason_Text_4:
	.string "There's some TEAM MAGMA activity. We\n"
	.string "don't want to put our PIDGEOT at risk.$"

FlyingTaxiUnavReason_Text_5:
	.string "There's some TEAM AQUA activity. We\n"
	.string "don't want to put our PIDGEOT at risk.$"

FlyingTaxiUnavReason_Text_6:
	.string "There are some protests going on and\n"
	.string "they're preventing us from flying.\p"
	.string "I swear we treat our PIDGEOT well, they\n"
	.string "love to stretch their wings and only\l"
	.string "carry passengers if they're happy to.$"

FlyingTaxiFirst_Text_0:
	.string "Hello! You must be {PLAYER}!\n"
	.string "Welcome to the FLYING TAXI service.\p"
	.string "… … …\n"
	.string "How do I know who you are?\p"
	.string "Why your father is the GYM LEADER of my\n"
	.string "hometown, PETALBURG CITY. And your\l"
	.string "MOM's shop is one of my favourites!\p"
	.string "When she asked us FLYING TAXI riders\n"
	.string "to look out for you, we were more than\l"
	.string "happy to oblidge.\p"
	.string "We can help you revisit any town or city\n"
	.string "you've been to before.\l"
	.string "All you have to do is ask!$"

FlyingTaxiAv_Text_0:
	.string "Hello {PLAYER}!\p"
	.string "I can call you a FLYING TAXI if there's\n"
	.string "somewhere you would like to go.\l"
	.string "Is there anywhere that you have in\l"
	.string "mind?$"

FlyingTaxiAv_Text_1:
	.string "Where would you like to go?$"

FlyingTaxiAv_Text_2:
	.string "Not to worry. Let us know if you ever\n"
	.string "need to go somewhere in a hurry!$"
