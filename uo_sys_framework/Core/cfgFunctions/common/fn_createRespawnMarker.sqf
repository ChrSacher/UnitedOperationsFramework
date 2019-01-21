/*
 * Author: Olsen
 *
 * Creates respawn marker for set team at [0,0,0]
 *
 * Arguments:
 * 0: team <string>
 *
 * Return Value:
 * nothing
 *
 * Public: No
 */

#define COMPONENT Core
#include "\x\UO_FW\addons\Main\script_macros.hpp"
UO_FW_EXEC_CHECK(ALL);

params ["_team"];

private _markerName = format ["respawn_%1", _team];

private _marker = createMarker [_markerName, [0, 0, 0]];
_marker setMarkerShape "ICON";
_markerName setMarkerType "EMPTY";
