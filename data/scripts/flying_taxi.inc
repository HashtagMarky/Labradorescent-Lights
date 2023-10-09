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
	switch VAR_TEMP_A
	case 0, FlyingTaxiUnavReason_2
	case 1, FlyingTaxiUnavReason_3
	case 2, FlyingTaxiUnavReason_3
	case 3, FlyingTaxiUnavReason_4
	case 4, FlyingTaxiUnavReason_4
	case 5, FlyingTaxiUnavReason_5
	case 6, FlyingTaxiUnavReason_5
	case 7, FlyingTaxiUnavReason_6
	case 8, FlyingTaxiUnavReason_6
	case 9, FlyingTaxiUnavReason_7
	case 10, FlyingTaxiUnavReason_8
	case 11, FlyingTaxiUnavReason_9
	return

FlyingTaxiUnavReason_2:
	random 11
	copyvar VAR_TEMP_A, VAR_RESULT
	addvar VAR_TEMP_A, 1
	goto FlyingTaxiUnavReason
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
	.string "Our SWELLOW are feeling extremely tired\n"
	.string "and they need a break.$"

FlyingTaxiUnavReason_Text_1:
	.string "There are some powerful winds that our\n"
	.string "SWELLOW don't want to fly through.$"

FlyingTaxiUnavReason_Text_2:
	.string "Our SWELLOW have become a bit sick,\n"
	.string "we can't risk their wellbeing.$"

FlyingTaxiUnavReason_Text_3:
	.string "Our SWELLOW are nesting. We have to let\n"
	.string "them take care of their young.$"

FlyingTaxiUnavReason_Text_4:
	.string "There's some TEAM MAGMA activity. We\n"
	.string "don't want to put our SWELLOW at risk.$"

FlyingTaxiUnavReason_Text_5:
	.string "There's some TEAM AQUA activity. We\n"
	.string "don't want to put our SWELLOW at risk.$"

FlyingTaxiUnavReason_Text_6:
	.string "There are some protests going on and\n"
	.string "they're preventing us from flying.\p"
	.string "I swear we treat our SWELLOW well, they\n"
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
	.string "Any place that you have in mind?$"

FlyingTaxiAv_Text_1:
	.string "Where would you like to go?$"

FlyingTaxiAv_Text_2:
	.string "Not to worry. Let us know if you ever\n"
	.string "need to go somewhere in a hurry!$"
