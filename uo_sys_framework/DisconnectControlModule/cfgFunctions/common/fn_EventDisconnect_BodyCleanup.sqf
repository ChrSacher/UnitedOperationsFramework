#define COMPONENT DisconnectControl
#include "\x\UO_FW\addons\main\script_macros.hpp"
UO_FW_EXEC_CHECK(ALL);

private ["_unit"];

_unit = _this select 0;

if (_unit getVariable ["UO_FW_Tracked", false]) then
{
    if (time < disconnect_control_time * 60 && (side _unit) in disconnect_control_sides) then
    {

        deleteVehicle _unit;

    };

};
