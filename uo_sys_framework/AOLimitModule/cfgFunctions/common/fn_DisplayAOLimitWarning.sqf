#include "\A3\ui_f\hpp\defineResinclDesign.inc"

params ["_display"];

[{!(displayNull isEqualto _this)}, {
    disableserialization;

    _this params ["_display"];
    private _timecheckInit = CBA_missionTime;
    private _endTime = (_timecheckInit + (missionNamespace getVariable ["UO_FW_AOL_TimeLeft", 30]));
    private _nextBeep = _endTime - 10;

    ["AOLimitWarning"] call BIS_fnc_showNotification;

    missionNamespace setVariable ["UO_FW_AOL_DisplayOpen", true];

    private _SoftAOLimitPFHhandle = [{
        params ["_argNested", "_idPFH"];
        _argNested params ["_timecheckInit","_endTime","_nextBeep",["_colorSet",["IGUI","TEXT_RGB"]],"_display"];

        private _ctrlTime = _display displayCtrl 1003;
        private _shouldDisplay = missionNamespace getVariable ["UO_FW_AOL_Display", false];
        private _timeleft = _endTime - CBA_missionTime;

        if !(_shouldDisplay) exitwith {
            missionNamespace setVariable ["UO_FW_AOL_DisplayOpen", false];
            [{
                _this closeDisplay 1;
            }, _display, 1] call CBA_fnc_waitAndExecute;
            [_idPFH] call CBA_fnc_removePerFrameHandler;
        };

        if (_timeLeft <= 0) exitwith {
            missionNamespace setVariable ["UO_FW_AOL_DisplayOpen", false];
            _ctrlTime ctrlSetText "00:00.000";
            [{
                player setDamage 1;
                _this closeDisplay 1;
            }, _display, 1] call CBA_fnc_waitAndExecute;
            [_idPFH] call CBA_fnc_removePerFrameHandler;
        };

        if (CBA_missionTime >= _nextBeep) then {
            playSound "Beep_Target";
            _nextBeep = _nextBeep + 1;
            _argNested set [2,_nextBeep];
        };

        if (_timeLeft <= 10) then {
            if (_timeLeft <= 5) then {
                _colorSet = ["IGUI","ERROR_RGB"];
                _argNested set [3,_colorSet];
            } else {
                _colorSet = ["IGUI","WARNING_RGB"];
                _argNested set [3,_colorSet];
            }
        };

        private _color = _colorSet call bis_fnc_displaycolorget;
        _ctrlTime ctrlSetTextColor _color;
        _ctrlTime ctrlSetText ([_timeLeft,"MM:SS.MS"] call bis_fnc_secondsToString);

    }, 0, [_endTime,_nextBeep,["IGUI","TEXT_RGB"]],_display] call CBA_fnc_addPerFrameHandler;
}, _display] call CBA_fnc_waitUntilAndExecute;
