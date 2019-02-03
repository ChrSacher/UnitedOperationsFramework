/*    Description: Main UO Framework Init. Declares needed vars, calls core functions
 *    Arguments:
 *         N/A
 *    Return Value:
 *         N/A
 *    Author
 *        Sacher
 */

#define COMPONENT 3DEN
#include "\x\UO_FW\addons\Main\script_macros.hpp"
UO_FW_EXEC_CHECK(ALL);

"Multiplayer" set3DENMissionAttribute ["respawn",3];
"Multiplayer" set3DENMissionAttribute ["respawndelay",5];
"Multiplayer" set3DENMissionAttribute ["disabledAI",true];
"Multiplayer" set3DENMissionAttribute ["respawnDialog",0];
"Multiplayer" set3DENMissionAttribute ["RespawnButton",1];
"Multiplayer" set3DENMissionAttribute ["respawnTemplates",["Base"]];
"Scenario" set3DENMissionAttribute ["EnableDebugConsole",1];
"Scenario" set3DENMissionAttribute ["enableTargetDebug",1];

if ((getMissionConfigValue ['UO_FW_Briefing_MissionNotes_Author',""]) isEqualTo "") then {
    "UO_FW_MissionNotes" set3DENMissionAttribute ["UO_FW_Briefing_MissionNotes_Author",profileNameSteam];
};
