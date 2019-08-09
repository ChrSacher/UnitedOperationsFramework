#include "..\..\Global\defs.hpp"
#include "\x\UO_FW\addons\Main\script_macros.hpp"


if (!isDedicated) then {
    waitUntil{player == player};

    private _guns = _this select 0;
    player setVariable [QEGVAR(Firemission,ObsGuns),_guns];
    private _allowBracket = _this select 1;
    private _allowDonut = _this select 2;
    private _allowGridSpotting = _this select 3;
    private _allowLine = _this select 4;
    private _allowMarker = _this select 5;
    private _allowPoint = _this select 6;
    private _allowPolar = _this select 7;
    private _allowPolarspotting = _this select 8;
    
    
            if (!(player getVariable [QEGVAR(Firemission,PlayerReceived),false])) then {
                
                _action = ["Artillery_Menu", "Artillery Menu", "", {true}, {(count (player getVariable [QEGVAR(Firemission,ObsGuns),[]])) > 0}] call ace_interact_menu_fnc_createAction;
                [player, 1, ["ACE_SelfActions"], _action] call ace_interact_menu_fnc_addActionToObject;

                _action = ["Artillery_Call_Menu", "Call Firemission", "", {true}, {true}] call ace_interact_menu_fnc_createAction;
                [player, 1, ["ACE_SelfActions","Artillery_Menu"], _action] call ace_interact_menu_fnc_addActionToObject;


                if (_allowPoint) then {
                    _action = ["PointFiremission", "Point Firemission", "", {[] call EFUNC(PointFiremission,DIA_PointFiremissionOpenDialog);}, {true}] call ace_interact_menu_fnc_createAction;
                    [player, 1, ["ACE_SelfActions","Artillery_Menu","Artillery_Call_Menu"], _action] call ace_interact_menu_fnc_addActionToObject;
                };
                
                if (_allowLine) then {
                    _action = ["LineFiremission", "Line Firemission", "", {[] call EFUNC(LineFiremission,DIA_LineFiremissionOpenDialog);}, {true}] call ace_interact_menu_fnc_createAction;
                    [player, 1, ["ACE_SelfActions","Artillery_Menu","Artillery_Call_Menu"], _action] call ace_interact_menu_fnc_addActionToObject;
                };

                if (_allowBracket) then {
                    _action = ["BracketFiremission", "Bracket Firemission", "", {[] call EFUNC(BracketFiremission,DIA_BracketFiremissionOpenDialog);}, {true}] call ace_interact_menu_fnc_createAction;
                    [player, 1, ["ACE_SelfActions","Artillery_Menu","Artillery_Call_Menu"], _action] call ace_interact_menu_fnc_addActionToObject;
                };
                if (_allowDonut) then {
                    _action = ["DonutFiremission", "Donut Firemission", "", {[] call EFUNC(DonutFiremission,DIA_DonutFiremissionOpenDialog);}, {true}] call ace_interact_menu_fnc_createAction;
                    [player, 1, ["ACE_SelfActions","Artillery_Menu","Artillery_Call_Menu"], _action] call ace_interact_menu_fnc_addActionToObject;
                };
                if (_allowMarker) then {
                    _action = ["MarkerFiremission", "Marker Firemission", "", {[] call EFUNC(MarkerFiremission,DIA_MarkerFiremissionOpenDialog);}, {true}] call ace_interact_menu_fnc_createAction;
                    [player, 1, ["ACE_SelfActions","Artillery_Menu","Artillery_Call_Menu"], _action] call ace_interact_menu_fnc_addActionToObject;
                };
                if (_allowPolar) then {
                    _action = ["PolarFiremission", "Polar Firemission", "", {[] call EFUNC(PolarFiremission,DIA_PolarFiremissionOpenDialog);}, {true}] call ace_interact_menu_fnc_createAction;
                    [player, 1, ["ACE_SelfActions","Artillery_Menu","Artillery_Call_Menu"], _action] call ace_interact_menu_fnc_addActionToObject;
                };

                _action = ["SpottingFiremission", "Call Spotting Round", "", {true}, {true}] call ace_interact_menu_fnc_createAction;
                [player, 1, ["ACE_SelfActions","Artillery_Menu"], _action] call ace_interact_menu_fnc_addActionToObject;

                if (_allowPolarspotting) then {
                        _action = ["SpottingFiremission", "Polar Spotting Round", "", {[] call EFUNC(PolarSpottingFiremission,DIA_PolarSpottingFiremissionOpenDialog);}, {true}] call ace_interact_menu_fnc_createAction;
                        [player, 1, ["ACE_SelfActions","Artillery_Menu","SpottingFiremission"], _action] call ace_interact_menu_fnc_addActionToObject;
                };
                if (_allowGridSpotting) then {
                        _action = ["SpottingFiremission", "Grid Spotting Round", "", {[] call EFUNC(GridSpottingFiremission,DIA_GridSpottingFiremissionOpenDialog);}, {true}] call ace_interact_menu_fnc_createAction;
                    [player, 1, ["ACE_SelfActions","Artillery_Menu","SpottingFiremission"], _action] call ace_interact_menu_fnc_addActionToObject;
                };

                _action = ["FiremissionInformation", "Firemission Information", "", {true}, {true}] call ace_interact_menu_fnc_createAction;
                [player, 1, ["ACE_SelfActions","Artillery_Menu"], _action] call ace_interact_menu_fnc_addActionToObject;

                _action = ["StopFiremission", "Stop Firemissions", "", {true}, {true}] call ace_interact_menu_fnc_createAction;
                [player, 1, ["ACE_SelfActions","Artillery_Menu"], _action] call ace_interact_menu_fnc_addActionToObject;
                {
                    _artyName =_x call EFUNC(Firemission,GetArtyDisplayName);
                    _text = ("Stop " + _artyName);
                    _action = ["Stop",_text , "", {(_this select 2) call EFUNC(Firemission,StopArtilleryClient); }, {!((_this select 2) call EFUNC(Firemission,isArtyAviable))},{},_x] call ace_interact_menu_fnc_createAction;
                    [player, 1, ["ACE_SelfActions","Artillery_Menu","StopFiremission"], _action] call ace_interact_menu_fnc_addActionToObject;
                } forEach _guns;

                {
                    _artyName =_x call EFUNC(Firemission,GetArtyDisplayName);
                    _text = ("Info " + _artyName);
                    _action = ["Info",_text , "",{hint ((_this select 2) call EFUNC(Firemission,GetCompleteInfoText)); }, { !((_this select 2) call EFUNC(Firemission,isArtyAviable))},{},_x] call ace_interact_menu_fnc_createAction;
                    [player, 1, ["ACE_SelfActions","Artillery_Menu","FiremissionInformation"], _action] call ace_interact_menu_fnc_addActionToObject;
                } forEach _guns;

                ["Event_ArtyIsReady",
                {
                    [PFM_DIA_IDC_GUNSELECT] call EFUNC(Firemission,ArtLoadAviableArtilleries);
                    [LFM_DIA_IDC_GUNSELECT] call EFUNC(Firemission,ArtLoadAviableArtilleries);
                    [BFM_DIA_IDC_GUNSELECT] call EFUNC(Firemission,ArtLoadAviableArtilleries);
                    [DFM_DIA_IDC_GUNSELECT] call EFUNC(Firemission,ArtLoadAviableArtilleries);
                    [MFM_DIA_IDC_GUNSELECT] call EFUNC(Firemission,ArtLoadAviableArtilleries);
                    [PSFM_DIA_IDC_GUNSELECT] call EFUNC(Firemission,ArtLoadAviableArtilleries);
                    [GSFM_DIA_IDC_GUNSELECT] call EFUNC(Firemission,ArtLoadAviableArtilleries);
                }] call CBA_fnc_addEventHandler;
                player setVariable [QEGVAR(Firemission,PlayerReceived),true];
            };
    
    
};
