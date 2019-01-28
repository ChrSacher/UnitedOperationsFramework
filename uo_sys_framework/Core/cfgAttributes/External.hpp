// Base class templates
class Default;

class Title: Default {
    class Controls {
        class Title;
        class Value;
    };
};

class Combo: Title {
    class Controls {
        class Title;
        class Value;
    };
};

class ComboPreview: Combo {
    class Controls {
        class Title;
        class Value;
        class Preview;
    };
};

class Toolbox: Title {
    class Controls {
        class Title;
        class Value;
    };
};

class Edit: Title {
    class Controls {
        class Title;
        class Value;
    };
};

class EditShort: Edit {
    class Controls {
        class Title;
        class Value;
    };
};

class EditArray;

class EditStringArray: EditArray {
    attributeLoad="\
        _valueText = '';\
        _valuetext = _value joinString ',';\
        (_this controlsGroupCtrl 100) ctrlSetText _valueText;\
    ";
    attributeSave="\
        _value = ctrlText (_this controlsGroupCtrl 100);\
        _values = [_value,','] call bis_fnc_splitString;\
        _values\
    ";
};

class EditQuotedStringArray: EditArray {
    attributeLoad="\
        _valueText = '';\
        _valuetext = _value joinString ',';\
        (_this controlsGroupCtrl 100) ctrlSetText _valueText;\
    ";
    attributeSave="\
        _value = ctrlText (_this controlsGroupCtrl 100);\
        _values = [_value,','] call bis_fnc_splitString;\
        _values\
    ";
};

class Slider: Title {
    class Controls {
        class Title;
        class Value;
        class Edit;
    };
};

class Checkbox: Title {
    class Controls {
        class Title;
        class Value;
    };
};

class CheckboxState: Checkbox {
    class Controls {
        class Title;
        class Value;
    };
};

class CategoryTitle: Title {
    class Controls {
        class Title: ctrlStatic {
            style=0;
            sizeEx="6.2 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
            x="2 * (pixelH * pixelGrid * 0.50)";
            //x="2 * (pixelH * pixelGrid * 0.50)";
            w="48 * (pixelW * pixelGrid * 0.50)";
            h="5 * (pixelH * pixelGrid * 0.50)";
            colorBackground[]={0,0,0,0};
        };
    };
};

class CategoryTitleIndent: Title {
    class Controls {
        class Title: ctrlStatic {
            style=0;
            sizeEx="6 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
            //x=0;
            x="4 * (pixelH * pixelGrid * 0.50)";
            w="48 * (pixelW * pixelGrid * 0.50)";
            h="5 * (pixelH * pixelGrid * 0.50)";
            colorBackground[]={0,0,0,0};
        };
    };
};

class SubTitle: CategoryTitle {
    class Controls: Controls {
        class Title: Title {
            x="2 * (pixelH * pixelGrid * 0.50)";
            sizeEx="5.2 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
        };
    };
};

class SubTitleIndent: SubTitle {
    class Controls: Controls {
        class Title: Title {
            x="6 * (pixelH * pixelGrid * 0.50)";
            sizeEx="5.2 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
        };
    };
};

class CheckboxStateReversed: CheckboxState {
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {
            onCheckedChanged="\
                _ctrlCheckbox = _this select 0;\
                _state = [true,false] select (cbChecked _ctrlCheckbox);\
                _fade = [0.75,0] select _state;\
                _ctrlGroup = ctrlParentControlsGroup ctrlParentControlsGroup _ctrlCheckbox;\
                {\
                    if (ctrlParentControlsGroup _x isEqualto _ctrlGroup) then {\
                        _x ctrlenable _state;\
                        _x ctrlsetfade _fade;\
                        _x ctrlcommit 0;\
                    };\
                } foreach (allcontrols (ctrlparent _ctrlCheckbox) - [ctrlParentControlsGroup _ctrlCheckbox]);\
            ";
            onLoad="\
                _ctrlCheckbox = _this select 0;\
                _state = [true,false] select (cbChecked _ctrlCheckbox);\
                _fade = [0.75,0] select _state;\
                _ctrlGroup = ctrlParentControlsGroup ctrlParentControlsGroup _ctrlCheckbox;\
                {\
                    if (ctrlParentControlsGroup _x isEqualto _ctrlGroup) then {\
                        _x ctrlenable _state;\
                        _x ctrlsetfade _fade;\
                        _x ctrlcommit 0;\
                    };\
                } foreach (allcontrols (ctrlparent _ctrlCheckbox) - [ctrlParentControlsGroup _ctrlCheckbox]);\
            ";
        };
    };
};
