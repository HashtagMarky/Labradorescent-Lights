#ifndef GUARD_CONSTANTS_QUESTS_H
#define GUARD_CONSTANTS_QUESTS_H

//questmenu scripting command params
#define QUEST_MENU_OPEN                 0   //opens the quest menu (questId = 0)
#define QUEST_MENU_UNLOCK_QUEST         1   //questId = QUEST_X (0-indexed)
#define QUEST_MENU_SET_ACTIVE           2   //questId = QUEST_X (0-indexed)
#define QUEST_MENU_SET_REWARD           3   //questId = QUEST_X (0-indexed)
#define QUEST_MENU_COMPLETE_QUEST       4   //questId = QUEST_X (0-indexed)
#define QUEST_MENU_CHECK_UNLOCKED       5   //checks if questId has been unlocked. Returns result to gSpecialVar_Result
#define QUEST_MENU_CHECK_INACTIVE       6 //check if a questID is inactive. Returns result to gSpecialVar_Result
#define QUEST_MENU_CHECK_ACTIVE         7   //checks if questId has been unlocked. Returns result to gSpecialVar_Result
#define QUEST_MENU_CHECK_REWARD         8  //checks if questId is in Reward state. Returns result to gSpecialVar_Result
#define QUEST_MENU_CHECK_COMPLETE       9   //checks if questId has been completed. Returns result to gSpecialVar_Result
#define QUEST_MENU_BUFFER_QUEST_NAME    10   //buffers a quest name to gStringVar1
#define QUEST_MENU_BUFFER_QUEST_SUBQUEST_NAME 11 //buffers subquest name to gStringVar1 and quest name to gStringVar2

// quest number defines
#define LAB_LIGHTS       0
#define SELENIC_SPIRIT   1
#define ADVENTURE_BEGINS 2
#define POKEDEX          3
#define PKMN_LEAGUE      4
#define CALAMITY_QUEEN   5
#define TEAM_AQUA        6
#define TEAM_MAGMA       7
#define FATHERS_REST     8
#define DEVON_DELIVERY   9
#define EV_TRAINING     10
#define DIGGING         11
#define GABBY_TY        12
#define QUEST_14        13
#define QUEST_15        14
#define QUEST_16        15
#define QUEST_17        16
#define QUEST_18        17
#define QUEST_19        18
#define QUEST_20        19
#define QUEST_21        20
#define QUEST_22        21
#define QUEST_23        22
#define QUEST_24        23
#define QUEST_25        24
#define QUEST_26        25
#define QUEST_27        26
#define QUEST_28        27
#define QUEST_29        28
#define QUEST_30        29
#define QUEST_COUNT     (QUEST_30 + 1)

#define MEET_NEIGHBOURS      0
#define FIND_IGNATIUS        1
#define FIND_RIVAL           2
#define DAD_CATCH_UP         3

#define STONE_BADGE          0
#define KNUCKLE_BADGE        1
#define DYNAMO_BADGE         2
#define HEAT_BADGE           3
#define LABRADORITE_BADGE    4
#define FEATHER_BADGE        5
#define MIND_BADGE           6
#define RAIN_BADGE           7
#define CHAMPION             8

#define DEVON_GOODS         0
#define STEVEN_LETTER       1

#define RUSTBORO_DRIVE_OUT   0
#define SLATEPORT_DRIVE_OUT  1

#define MAGMA_METEOR_FALLS   0
#define MAGMA_MT_CHIMNEY     1

#define SUB_QUEST_20        19
#define SUB_QUEST_21        20
#define SUB_QUEST_22        21
#define SUB_QUEST_23        22
#define SUB_QUEST_24        23
#define SUB_QUEST_25        24
#define SUB_QUEST_26        25
#define SUB_QUEST_27        26
#define SUB_QUEST_28        27
#define SUB_QUEST_29        28
#define SUB_QUEST_30        29

#define LAB_LIGHTS_SUB_COUNT            0
#define SELENIC_SPIRIT_SUB_COUNT        0
#define ADVENTURE_BEGINS_SUB_COUNT      4
#define POKEDEX_SUB_COUNT               0
#define PKMN_LEAGUE_SUB_COUNT           9
#define CALAMITY_QUEEN_SUB_COUNT        0
#define TEAM_AQUA_SUB_COUNT             2
#define TEAM_MAGMA_SUB_COUNT            2
#define FATHERS_REST_SUB_COUNT          0
#define DEVON_DELIVERY_SUB_COUNT        2
#define EV_TRAINING_SUB_COUNT           0
#define DIGGING_SUB_COUNT               0
#define GABBY_TY_SUB_COUNT              0

#define REMAINING_SUB_COUNT             11
#define SUB_QUEST_COUNT                 (LAB_LIGHTS_SUB_COUNT + SELENIC_SPIRIT_SUB_COUNT + ADVENTURE_BEGINS_SUB_COUNT + POKEDEX_SUB_COUNT + PKMN_LEAGUE_SUB_COUNT + CALAMITY_QUEEN_SUB_COUNT + TEAM_AQUA_SUB_COUNT + TEAM_MAGMA_SUB_COUNT + FATHERS_REST_SUB_COUNT + DEVON_DELIVERY_SUB_COUNT + EV_TRAINING_SUB_COUNT + DIGGING_SUB_COUNT + GABBY_TY_SUB_COUNT + REMAINING_SUB_COUNT)

#define QUEST_ARRAY_COUNT (SUB_QUEST_COUNT > QUEST_COUNT ? SUB_QUEST_COUNT : QUEST_COUNT)
#endif // GUARD_CONSTANTS_QUESTS_H
