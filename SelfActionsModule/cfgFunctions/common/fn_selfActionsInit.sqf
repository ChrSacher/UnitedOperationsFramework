/*	Description: Gives players custom self actions 
 *	Arguments:
 * 		N/A
 *	Return Value:
 * 		ARRAY 	
 *	Author
 *		TinfoilHate & PiZZADOX
 */

#include "\x\UO_FW\addons\main\script_macros.hpp"
UO_FW_EXEC_CHECK(CLIENT)
["Self Actions", "Extra self actions", "Sacher"] call UO_FW_FNC_RegisterModule; 
[{!isNull player}, {
	if (!UO_FW_SelfActions_Enable) exitwith {};
	
	player setVariable ["mis_originalSide",side player,true];
	//check own color interaction
	if (UO_FW_SelfActions_CheckColour_Enabled) then {
		private _teamColor = ["colorCheck_class", "Check Team Color", "", {
			private _str = "";
			switch (assignedTeam player) do {
				case "BLUE": {_str = "<t size='1.5'>You are in <br/><t color='#0000FF'>BLUE</t> team.</t> "};
				case "RED": {_str = "<t size='1.5'>You are in <br/><t color='#FF0000'>RED</t> team.</t> "};
				case "GREEN": {_str = "<t size='1.5'>You are in <br/><t color='#00FF00'>GREEN</t> team.</t> "};
				case "YELLOW": {_str = "<t size='1.5'>You are in <br/><t color='#FFFF00'>YELLOW</t> team.</t> "};
				default {_str = "<t size='1.5'>You are in <br/><t color='#FFFFFF'>WHITE</t> team.</t> "};
			};
			hint parseText _str;
		}, {!isNil {assignedTeam player}}] call ace_interact_menu_fnc_createAction;
		[player, 1, ["ACE_SelfActions"], _teamColor] call ace_interact_menu_fnc_addActionToObject;
	};

	//share map interaction
	if (UO_FW_SelfActions_CheckMap_Enabled) then {
		private _shareMap = ["shareMap_class", "View Map", "", {
			params ["_target", "_player"];

			player linkItem "ItemMap";
			openMap true;

			[
				{!visibleMap || (_this select 0) distance (_this select 1) > 3},
				{openMap false; player unlinkItem "ItemMap";},
				[_target,_player]
			] call CBA_fnc_waitUntilAndExecute;
		}, {
			!("ItemMap" in assignedItems _player) &&
			"ItemMap" in assignedItems _target &&
			_target distance _player <= 3 &&
			(_player getVariable "mis_originalSide" == _target getVariable "mis_originalSide")
		}] call ace_interact_menu_fnc_createAction;

		[player, 0, ["ACE_MainActions"], _shareMap, true] call ace_interact_menu_fnc_addActionToObject;
	};

	//cut grass interaction
	if (UO_FW_SelfActions_CutGrass_Enabled) then {
		private _machete = ["machete_class", "Cut Grass", "", {
			mis_macheteDone = false;
			private _macheteEH = player addEventHandler ["AnimDone", {
				if (_this select 1 == "AinvPknlMstpSlayWrflDnon_medic") then {
					mis_macheteDone = true;
				};
			}];

			[player,"AinvPknlMstpSlayWrflDnon_medic"] remoteExec ['playMove'];

			[{mis_macheteDone}, {
				_cutter = createVehicle ["ClutterCutter_small_EP1", [getposATL player, 1, getDir player] call BIS_fnc_relPos, [], 0, "CAN_COLLIDE"];
				player removeEventHandler ["AnimDone", _this];

				mis_macheteDone = false;
			}, _macheteEH] call CBA_fnc_waitUntilAndExecute;
		}, {stance player == "CROUCH"}] call ace_interact_menu_fnc_createAction;
		[player, 1, ["ACE_SelfActions"], _machete] call ace_interact_menu_fnc_addActionToObject;
	};
}, []] call CBA_fnc_waitUntilAndExecute;