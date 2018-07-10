/*	Description: Create a group with assigned parameters.
 * 	Arguments:
 * 		ARRAY	- Units and Unit Settings
 * 		ARRAY	- Group Vehicles and Group Vehicle Settings
 * 	Return Value:
 * 		GROUP 	- Created Group
 *	Author
 *		suits & PiZZADOX
 */
#include "\x\UO_FW\addons\main\script_macros.hpp"
UO_FW_EXEC_CHECK(SERVERHC)

params ["_grpid","_grpSet","_grpMem",["_currentVeh",objNull,[objNull]]];
	_grpSet params ["_side","_gpos","_behave","_combat","_speed","_formation","_grpStance","_grpInit","_createRadius","_taskRadius","_wait","_startBld","_task","_taskTimer","_multi","_occupyOption","_vehAssigned","_waypoints","_onWater","_tasks","_hc","_fl"];
	private _ngrp = createGroup _side;	
	for [{_i=0},{(_i < (count _grpMem))},{_i = _i + 1}] do {
		if(((_grpMem select _i) select 0)) then {
			private _u = [false,_ngrp,_gpos,_startBld,_i,(_grpMem select _i),_taskRadius,_currentVeh] call UO_AI_fnc_createUnit;
		} else {
			(_grpMem select _i) params ["_uv","_uc","_vpos"];
			private _v = [_vpos,(_grpMem select _i)] call UO_AI_fnc_createVehicle;				
			_currentVeh = _v;
		};
		sleep 0.25;			
	};	
	[_ngrp,_gpos,_grpSet] call UO_AI_fnc_setGroupVariables;
	_ngrp call UO_AI_fnc_taskReset;
	if(count _tasks > 0) then {		
		[_ngrp,_tasks] call UO_AI_fnc_taskRegister;
		_tasks = _tasks call UO_AI_fnc_taskRemoveZoneActivated;	
	};
	if(count _tasks > 0) then {UO_FW_taskedGroups pushBack [_ngrp];};
	if(count _waypoints > 2) then {			
		[_ngrp,_waypoints] call UO_AI_fnc_createWaypoints;
	} else {
		if(count _tasks > 0 && (_ngrp getVariable ['aeTaskTimer',0]) isEqualTo 0) then {			
			[_ngrp,_tasks] call UO_AI_fnc_taskInit;
		} else {
			_ngrp setVariable["aeCurrentTaskEndTime",(time + _taskTimer)];
			[_task,_ngrp,_gpos,_taskRadius,_wait,_behave,_combat,_speed,_formation,_occupyOption] call UO_AI_fnc_taskAssign;
		};
	};	
	_ngrp