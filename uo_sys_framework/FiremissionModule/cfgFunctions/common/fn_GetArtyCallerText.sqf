#include "..\..\Global\defs.hpp"
private _unit = _this;
    private _caller = _unit call EFUNC(Firemission,GetArtyCaller);
    private _returnName = "Non specified";
    if (!(isNull  _caller)) then {
        _returnName = name _caller;
    };

    _returnName