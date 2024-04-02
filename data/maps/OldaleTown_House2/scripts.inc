OldaleTown_House2_MapScripts::
	.byte 0

OldaleTown_House2_EventScript_Woman::
	goto_if_set FLAG_HIDE_OLDALE_GABBY_AND_TY, OldaleTown_House2_EventScript_Woman2
	msgbox OldaleTown_House2_Text_PokemonLevelUp, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Woman2::
	msgbox OldaleTown_House2_Text_HeDidInterview, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man::
	goto_if_set FLAG_HIDE_OLDALE_GABBY_AND_TY, OldaleTown_House2_EventScript_Man2
	msgbox OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man2::
	msgbox OldaleTown_House2_Text_DadDidInterview, MSGBOX_NPC
	end

OldaleTown_House2_Text_PokemonLevelUp:
	.string "My husband is doing an interview about\n"
	.string "hunting the CALAMITY BRINGER.\p"
	.string "I don't think I agree with it, but I'm\n"
	.string "glad he's some recognition.$"

OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon:
	.string "My dad is looking for a rare\n"
	.string "POKéMON, he's going to be on TV!$"

OldaleTown_House2_Text_HeDidInterview:
	.string "People didn't enjoy seeing my husband\n"
	.string "on TV. The fallout has been terrible.$"

OldaleTown_House2_Text_DadDidInterview:
	.string "Everyone is saying mean things about\n"
	.string "my dad. I don't know how to feel…$"

OldaleTown_House2_EventScript_Hunter::
	questmenu QUEST_MENU_CHECK_COMPLETE, CALAMITY_QUEEN
	compare VAR_RESULT, FALSE
	goto_if_eq OldaleTown_House2_EventScript_Hunter_1
	applymovement 3, Exclaim
	msgbox OldaleTown_House2_EventScript_Hunter_Text_1
	waitmovement 0
	return

OldaleTown_House2_EventScript_Hunter_1:
	msgbox OldaleTown_House2_EventScript_Hunter_Text_0, MSGBOX_NPC
	return


OldaleTown_House2_EventScript_Hunter_Text_0:
	.string "I don't care if they didn't like the\n"
	.string "interview, I'm a master huntsman and\l"
	.string "it's my destiny to catch the CALAMITY.$"

OldaleTown_House2_EventScript_Hunter_Text_1:
	.string "Wow… You have… Just wow…\p"
	.string "Maybe it wasn't my detiny…$"
