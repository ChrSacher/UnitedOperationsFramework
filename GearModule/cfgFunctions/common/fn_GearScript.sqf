#include "\x\UO_FW\addons\main\script_macros.hpp"
UO_FW_EXEC_CHECK(CLIENT)
private ["_unit", "_type", "_groupId"];
if(!(missionNamespace getVariable ["UO_FW_Gear_Enabled",false])) exitWith {};
waitUntil{!(isNil "UO_FW_GearLoadouts")};
_unit = _this select 0;
_type = _this select 1;
if (count _this > 2) then {
	
	_groupId = _this select 2;
	
	(group _unit) setGroupId [_groupId];
	
};

{
	_string = _this call (compile (preprocessFileLineNumbers _x));

	 
}forEach UO_FW_GearLoadouts;
