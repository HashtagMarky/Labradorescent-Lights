BoreaGladeTeaser_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BoreaGladeTeaser_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BoreaGladeTeaser_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

BoreaGladeTeaser_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
	map_script_2 VAR_TEMP_1, 0, BoreaGladeTeaser_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

BoreaGladeTeaser_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
	call Teaser_Hide_Objects
	return

BoreaGladeTeaser_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_RESULT, 1, BoreaGladeTeaser_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

BoreaGladeTeaser_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	call TeaserOne_Setup
	call TeaserOne
	return


Teaser_Hide_Objects::
	applymovement OBJ_EVENT_ID_PLAYER, Invisible
	hideobjectat 1, MAP_BOREA_GLADE_TEASER
	hideobjectat 2, MAP_BOREA_GLADE_TEASER
	hideobjectat 3, MAP_BOREA_GLADE_TEASER
	return


TeaserOne_Setup::
	showobjectat 1, MAP_BOREA_GLADE_TEASER
	showobjectat 2, MAP_BOREA_GLADE_TEASER
	special SpawnCameraObject
	return


TeaserOne::
	setvar VAR_RESULT, 0
	call TeaserOne_IgnatiusLabExit
	call TeaserOne_IgnatiusEntrance
	call TeaserOne_IgnatiusConversation
	call TeaserOne_IgnatiusExit
	call TeaserOne_LaurenEntrance
	call TeaserOne_LaurenConversation
	call TeaserOne_CameraPanToWhite
	call TeaserOne_CameraPanToOriginal
	goto TeaserOne_End
	return


TeaserOne_Restart::
	goto BeginTeaser_TeaserOne
	return


TeaserOne_End::
	goto_if_set FLAG_SYS_RELEASE_VERSION, TeaserOne_End_1
	goto TeaserOne_Restart
	return

TeaserOne_End_1:
	initclock VAR_0x8000, VAR_0x8001
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq TeaserOne_End_4
	warpsilent MAP_BOREA_GLADE_MAYS_HOUSE_2F, 5, 2
	waitstate
	releaseall
	return

TeaserOne_End_4:
	warpsilent MAP_BOREA_GLADE_BRENDANS_HOUSE_2F, 3, 2
	waitstate
	releaseall
	return


TeaserOne_IgnatiusLabExit::
	delay 40
	opendoor 7, 16
	waitdooranim
	showobjectat 3, MAP_BOREA_GLADE_TEASER
	applymovement 3, WalkDown
	waitmovement 0
	closedoor 7, 16
	waitdooranim
	return


TeaserOne_IgnatiusEntrance::
	applymovement OBJ_EVENT_ID_CAMERA, TeaserOne_CameraPan
	applymovement 3, TeaserOne_IgnatiusEntranceOne
	waitmovement 0
	applymovement 1, FaceDown
	applymovement 3, TeaserOne_IgnatiusEntranceTwo
	waitmovement 0
	return


TeaserOne_IgnatiusConversation::
	cutscenebox TeaserOne_IgnatiusConversation_Text_0
	cutscenebox TeaserOne_IgnatiusConversation_Text_1
	call TeaserOne_IgnatiusJumpsOne
	applymovement 3, Question
	cutscenebox TeaserOne_IgnatiusConversation_Text_2
	applymovement 1, Exclaim
	cutscenebox TeaserOne_IgnatiusConversation_Text_3
	call TeaserOne_IgnatiusJumpsTwo
	cutscenebox TeaserOne_IgnatiusConversation_Text_4
	cutscenebox TeaserOne_IgnatiusConversation_Text_5
	applymovement 1, Question
	cutscenebox TeaserOne_IgnatiusConversation_Text_6
	cutscenebox TeaserOne_IgnatiusConversation_Text_7
	cutscenebox TeaserOne_IgnatiusConversation_Text_8
	cutscenebox TeaserOne_IgnatiusConversation_Text_9
	delay 30
	return


TeaserOne_IgnatiusExit::
	applymovement OBJ_EVENT_ID_CAMERA, TeaserOne_CameraPanMiddleOne
	applymovement 3, TeaserOne_IgnatiusExitOne
	waitmovement 0
	applymovement 1, FaceLeft
	applymovement 3, TeaserOne_IgnatiusExitTwo
	return


TeaserOne_IgnatiusEnterLab::
	waitmovement 3
	opendoor 7, 16
	waitdooranim
	applymovement 3, WalkUp
	waitmovement 0
	hideobjectat 3, MAP_BOREA_GLADE_TEASER
	waitmovement 0
	closedoor 7, 16
	waitdooranim
	return


TeaserOne_LaurenEntrance::
	applymovement 2, TeaserOne_LaurenEntranceOne
	call TeaserOne_IgnatiusEnterLab
	waitmovement 2
	delay 30
	applymovement OBJ_EVENT_ID_CAMERA, TeaserOne_CameraPanMiddleTwo
	applymovement 2, TeaserOne_LaurenEntranceTwo
	waitmovement 2
	delay 15
	applymovement 2, TeaserOne_LaurenEntranceThree
	return


TeaserOne_LaurenConversation::
	cutscenebox TeaserOne_LaurenConversation_Text_0
	call TeaserOne_LaurenJumpsOne
	applymovement 1, Exclaim
	cutscenebox TeaserOne_LaurenConversation_Text_1
	applymovement 2, Question
	cutscenebox TeaserOne_LaurenConversation_Text_2
	applymovement 1, Exclaim
	cutscenebox TeaserOne_LaurenConversation_Text_3
	applymovement 2, TeaserOne_LaurenRealiseLabOne
	waitmovement 0
	delay 60
	applymovement 2, TeaserOne_LaurenRealiseLabTwo
	cutscenebox TeaserOne_LaurenConversation_Text_4
	cutscenebox TeaserOne_LaurenConversation_Text_5
	return


TeaserOne_CameraPanToWhite::
	applymovement OBJ_EVENT_ID_CAMERA, TeaserOne_CameraPanAway
	fadescreenspeed FADE_TO_WHITE, 8
	waitmovement 0
	return


TeaserOne_CameraPanToOriginal::
	applymovement OBJ_EVENT_ID_CAMERA, TeaserOne_CameraDisable
	waitmovement 0
	special RemoveCameraObject
	return


TeaserOne_CameraDisable:
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
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

TeaserOne_IgnatiusJumpsOne::
	applymovement 3, JumpIPUp
	applymovement 1, JumpIPDown
	waitmovement 0
	delay 10
	applymovement 3, JumpIPUp
	waitmovement 0
	applymovement 1, JumpIPDown
	waitmovement 0
	delay 10
	applymovement 3, JumpIPUp
	waitmovement 0
	delay 20
	return


TeaserOne_IgnatiusJumpsTwo::
	applymovement 3, JumpIPUp
	applymovement 1, JumpIPDown
	waitmovement 0
	applymovement 3, JumpIPUp
	applymovement 1, JumpIPDown
	waitmovement 0
	delay 20
	return


TeaserOne_LaurenJumpsOne::
	applymovement 2, JumpIPRight
	waitmovement 0
	applymovement 2, JumpIPRight
	waitmovement 0
	applymovement 2, JumpIPRight
	waitmovement 0
	delay 10
	applymovement 2, JumpIPRight
	applymovement 1, JumpIPLeft
	waitmovement 0
	delay 20
	return


TeaserOne_CameraPan:
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
	step_end

TeaserOne_CameraPanMiddleOne:
	walk_left
	walk_left
	walk_left
	step_end

TeaserOne_CameraPanMiddleTwo:
	walk_right
	walk_right
	step_end

TeaserOne_CameraPanAway:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

TeaserOne_IgnatiusEntranceOne:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

TeaserOne_IgnatiusEntranceTwo:
	walk_right
	walk_right
	face_up
	step_end

TeaserOne_IgnatiusExitOne:
	walk_left
	walk_left
	step_end

TeaserOne_IgnatiusExitTwo:
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	step_end

TeaserOne_LaurenEntranceOne:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	face_left
	step_end

TeaserOne_LaurenEntranceTwo:
	walk_right
	walk_right
	walk_right
	step_end

TeaserOne_LaurenEntranceThree:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

TeaserOne_LaurenRealiseLabOne:
	emote_question_mark
	face_left
	step_end

TeaserOne_LaurenRealiseLabTwo:
	emote_exclamation_mark
	face_right
	step_end

TeaserOne_IgnatiusConversation_Text_0:
	.string "PROF. IGNATIUS: Hello my old friend.\n"
	.string "Hasn't it been a while?$"

TeaserOne_IgnatiusConversation_Text_1:
	.string "SAMUEL: It's been way too long!\n"
	.string "How have you been?$"

TeaserOne_IgnatiusConversation_Text_2:
	.string "PROF. IGNATIUS: Did you get a chance to\n"
	.string "see the house? Isn't it beautiful?$"

TeaserOne_IgnatiusConversation_Text_3:
	.string "SAMUEL: Yes we did, and yes it was!$"

TeaserOne_IgnatiusConversation_Text_4:
	.string "SAMUEL: LAUREN is viewing the building\n"
	.string "up the road, she'll be here soon.$"

TeaserOne_IgnatiusConversation_Text_5:
	.string "PROF. IGNATIUS: Oh dear…\n"
	.string "I won't get a chance to see her.$"

TeaserOne_IgnatiusConversation_Text_6:
	.string "SAMUEL: Going already?$"

TeaserOne_IgnatiusConversation_Text_7:
	.string "PROF. IGNATIUS: Sadly, I have to.\n"
	.string "I need to analyse the data you sent me.$"

TeaserOne_IgnatiusConversation_Text_8:
	.string "SAMUEL: Don't you worry about it,\n"
	.string "we'll both see you again very soon!$"

TeaserOne_IgnatiusConversation_Text_9:
	.string "PROF. IGNATIUS: Goodbye SAM!$"

TeaserOne_LaurenConversation_Text_0:
	.string "LAUREN: Hello my love.\n"
	.string "I have so much to tell you.$"

TeaserOne_LaurenConversation_Text_1:
	.string "SAMUEL: That's amazing to hear!\n"
	.string "I'm excited for our family to move here.$"

TeaserOne_LaurenConversation_Text_2:
	.string "LAUREN: Wait, I didn't ask…\n"
	.string "The man in the lab-coat?$"

TeaserOne_LaurenConversation_Text_3:
	.string "SAMUEL: That was him, that was IGGY!\n"
	.string "I can't wait to be neighbours again.$"

TeaserOne_LaurenConversation_Text_4:
	.string "LAUREN: So that building must be his\n"
	.string "LAB, what a quaint place this is.$"

TeaserOne_LaurenConversation_Text_5:
	.string "SAMUEL: You're right, I'm really looking\n"
	.string "forward to what our future holds.$"
