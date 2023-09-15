Common_EventScript_FlyingTaxi::
	lock
	faceplayer
	msgbox Common_EventScript_FlyingTaxi_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Common_EventScript_FlyingTaxi_1
	msgbox Common_EventScript_FlyingTaxi_Text_2
    release
	return

Common_EventScript_FlyingTaxi_1:
	msgbox Common_EventScript_FlyingTaxi_Text_1
    goto EventScript_FlyingTaxi_ChooseDestination
    release
	end


Common_EventScript_FlyingTaxi_Text_0:
	.string "I can call you a FLYING TAXI if there's\n"
	.string "somewhere you would like to go.\l"
	.string "Would you me to call you a ride?$"

Common_EventScript_FlyingTaxi_Text_1:
	.string "Where would you like to go?$"

Common_EventScript_FlyingTaxi_Text_2:
	.string "Keep us in mind the next time you need to\n"
	.string "go somewhere in a hurry!$"


EventScript_FlyingTaxi_ChooseDestination::
    special FieldLoadFlyMap
    goto EventScript_FlyingTaxi_Goodbye
    end

EventScript_FlyingTaxi_Goodbye::
    message gText_WeHopeToSeeYouAgain
    setvar VAR_LAST_TALKED, 0
    releaseall
    return

