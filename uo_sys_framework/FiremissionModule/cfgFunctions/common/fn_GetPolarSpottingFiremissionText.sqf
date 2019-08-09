#include "..\..\Global\defs.hpp"
    private _unit = _this select 0;
    private _callGrid = _this select 1;
    private _mils = _this select 2;
    private _distance = _this select 3;
    private _rounds = _this select 4;
    private _loc = [_callGrid,true] call CBA_fnc_mapGridToPos;
    private _degrees = MILSPERROUND / _mils * 360.0;
    private _dir = [cos _degrees,sin _degrees,0];
    private _target =  _loc vectorAdd (_dir vectorMultiply _distance);
    private _text =   getText (configfile / "CfgMagazines" / _rounds / "displayName");
    private _unitName = _unit call EFUNC(Firemission,GetArtyDisplayName);
    private _ret =     "Name: " + _unitName +"\n" +
                                                "Firemission type: Spotting-Firemission \n" +
                                                "Shell: " + _text +" \n" +
                                                "Mils: " + (str _mils) +" \n" +
                                                "Distance: " + (str _distance) +" \n" +
                                                "Grid: " + (mapGridPosition _target) +" \n";
    _ret
