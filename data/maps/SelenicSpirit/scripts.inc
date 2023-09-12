SelenicSpirit_MapScripts::
	.byte 0

SelenicSpirit_EventScript_ShopClerk::
	lockall
	faceplayer
	msgbox SelenicSpirit_EventScript_ShopClerk_Text_0, MSGBOX_DEFAULT
	releaseall
	closemessage
	end


SelenicSpirit_EventScript_Gent::
	lockall
	msgbox SelenicSpirit_EventScript_Gent_Text_0, MSGBOX_DEFAULT
	closemessage
	releaseall
	end


SelenicSpirit_EventScript_Lass::
	lockall
	msgbox SelenicSpirit_EventScript_Lass_Text_0, MSGBOX_DEFAULT
	closemessage
	releaseall
	end


SelenicSpirit_EventScript_Girl::
	lockall
	faceplayer
	msgbox SelenicSpirit_EventScript_Girl_Text_0, MSGBOX_DEFAULT
	closemessage
	releaseall
	end


SelenicSpirit_EventScript_Woman::
	lockall
	msgbox SelenicSpirit_EventScript_Woman_Text_0, MSGBOX_DEFAULT
	closemessage
	releaseall
	end


SelenicSpirit_EventScript_ShopClerk_Text_0:
	.string "Welcome to SELENIC SPIRIT.\n"
	.string "We're not currently open-\l"
	.string "Wait, you're {PLAYER}!\p"
	.string "Well if you're MOM is the owner,\n"
	.string "I can hardly send you away.$"

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
